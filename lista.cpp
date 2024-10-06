#include "Lista.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <iomanip>

using namespace std;

// Constructor de NodoLista
NodoLista::NodoLista(Datos valor){
    buque = valor;
    next = nullptr;
}

// Destructor de NodoLista
NodoLista::~NodoLista() {}

// Constructor de Lista
Lista::Lista() {
    first = nullptr; // No hay nodos en la lista al crearla.
}

// Destructor de Lista
// Libera la memoria de todos los nodos en la lista
Lista::~Lista() {
    NodoLista* actual = first;
    while (actual != nullptr) {
        NodoLista* temp = actual;
        actual = actual->next;
        delete temp;
    }
}

// Método obtenerPrimerNodo
// Devuelve un puntero al primer nodo de la lista.
NodoLista* Lista::obtenerPrimerNodo() {
    return first;
}


// Función que compara dos objetos de la estructura 'Datos'.
// Compara primero por el campo 'ubi', y si son iguales, compara por fecha (día, mes, año).
bool Lista::compararDatos(const Datos& a, const Datos& b) {
    // Comparación inicial por UBI. Si no son iguales, retorna el resultado de la comparación.
    if (a.ubi != b.ubi) return a.ubi < b.ubi;

    // Extraer el día, mes y año de la fecha del primer objeto "A".
    int dayA = stoi(a.fecha.substr(0, 2));    // Convertir los primeros 2 caracteres de la fecha a entero (día).
    int monthA = stoi(a.fecha.substr(3, 2));  // Convertir los siguientes 2 caracteres de la fecha a entero (mes).
    int yearA = stoi(a.fecha.substr(6, 4));   // Convertir los últimos 4 caracteres de la fecha a entero (año).

    // Extraer el día, mes y año de la fecha del segundo objeto "B".
    int dayB = stoi(b.fecha.substr(0, 2));    // Convertir los primeros 2 caracteres de la fecha a entero (día).
    int monthB = stoi(b.fecha.substr(3, 2));  // Convertir los siguientes 2 caracteres de la fecha a entero (mes).
    int yearB = stoi(b.fecha.substr(6, 4));   // Convertir los últimos 4 caracteres de la fecha a entero (año).

    if (yearA != yearB) return yearA < yearB;
    if (monthA != monthB) return monthA < monthB;

    // Si los meses también son iguales, se compara por día.
    return dayA < dayB;
}


// Función para insertar un nuevo nodo en la lista, manteniendo el orden por UBI y fecha.
void Lista::insertarEnOrden(Datos buque) {
    // Crear un nuevo nodo con los datos del buque.
    NodoLista* nuevoNodo = new NodoLista(buque);

    // Si la lista está vacía  o el nuevo buque es menor que el primero, insertar el nuevo nodo al inicio de la lista.
    if (first == nullptr || compararDatos(buque, first->buque)) {
        nuevoNodo->next = first;         
        first = nuevoNodo;               
    } else {
        // Si la lista no está vacía y el nuevo buque no es menor que el primero,
        // se recorre la lista para encontrar la posición correcta.
        NodoLista* actual = first;
        
        // Avanzar hasta encontrar un nodo cuyo siguiente sea mayor que el nuevo buque.
        while (actual->next != nullptr && compararDatos(actual->next->buque, buque)) {
            actual = actual->next;
        }

        // Insertar el nuevo nodo en la posición correcta, entre 'actual' y 'actual->next'.
        nuevoNodo->next = actual->next;  
        actual->next = nuevoNodo;        
    }
}

// Función para contar y mostrar el número de buques que han pasado por los mares Mediterráneo y Rojo, organizados por mes y filtrados por UBI (los primeros 3 caracteres).
void Lista::ordenarMeses(NodoLista* serieM, NodoLista* serieR, const string& serie) {
    // Si ambas listas están vacías, no hacemos nada.
    if (serieM == nullptr && serieR == nullptr) return;

    int mesesM[12] = {0};                // Arreglo para contar buques por mes en el Mediterráneo
    int mesesR[12] = {0};                // Arreglo para contar buques por mes en el Rojo
    const string meses[] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"}; 

    int anioM = 0, anioR = 0;  

    // Recorremos la lista del Mediterráneo
    if (serieM != nullptr) {
        NodoLista* actualM = serieM;     
        while (actualM != nullptr) {
            // Comprobamos si los primeros 3 caracteres del UBI coinciden con la serie proporcionada
            if (actualM->buque.ubi.substr(0, 3) == serie) {
                string fecha = actualM->buque.fecha;  // Extraemos la fecha del registro
                int mesIndex = stoi(fecha.substr(3, 2)) - 1;  // Extraemos el mes (en formato numérico, convertido a índice)
                anioM = stoi(fecha.substr(6, 4));  // Extraemos el año
                mesesM[mesIndex]++;      // Aumentamos el conteo de buques para el mes correspondiente en el Mediterráneo
            }
            actualM = actualM->next;     
        }
    }

    // Recorremos la lista del Rojo
    if (serieR != nullptr) {
        NodoLista* actualR = serieR;     
        while (actualR != nullptr) {
            // Comprobamos si los primeros 3 caracteres del UBI coinciden con la serie proporcionada
            if (actualR->buque.ubi.substr(0, 3) == serie) {
                string fecha = actualR->buque.fecha;  // Extraemos la fecha del registro
                int mesIndex = stoi(fecha.substr(3, 2)) - 1;  // Extraemos el mes (en formato numérico, convertido a índice)
                anioR = stoi(fecha.substr(6, 4));  // Extraemos el año
                mesesR[mesIndex]++;      // Aumentamos el conteo de buques para el mes correspondiente en el Rojo
            }
            actualR = actualR->next;     
        }
    }

    // Determinamos el primer mes que tiene datos (ya sea en el Mediterráneo o en el Rojo)
    int primerMes = 0, ultimoMes = 11;   
    for (int i = 0; i < 12; ++i) {
        if (mesesM[i] > 0 || mesesR[i] > 0) {  
            primerMes = i;
            break;
        }
    }

    // Determinamos el último mes que tiene datos (ya sea en el Mediterráneo o en el Rojo)
    for (int i = 11; i >= 0; --i) {
        if (mesesM[i] > 0 || mesesR[i] > 0) {  
            ultimoMes = i;
            break;
        }
    }

    // Mostramos los resultados desde el primer mes con datos hasta el último mes con datos
    for (int i = primerMes; i <= ultimoMes; ++i) {
        // Se muestra el mes, el año (del Mediterráneo o Rojo, dependiendo de cuál tenga datos), y el conteo de buques para ese mes en ambos mares.
        cout << meses[i] << " " << (anioM != 0 ? anioM : anioR) << " " 
             << setw(2) << setfill(' ') << mesesM[i] << " " 
             << setw(2) << setfill(' ') << mesesR[i] << endl;
    }
}
