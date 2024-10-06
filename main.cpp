#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Lista.h"
using namespace std;

/*
Descripción: El código realiza el ordenamiento y posterior búsqueda de datos de los buques utilizando estructuras de lista enlazada.
Los datos de los buques son leídos desde un archivo de texto y almacenados en listas según su punto de entrada.
Autores: 
- Elizabeth Jauregui Zarate (A01253381)
- Mariana Carrillo Holguin (A01253358)
- Zuleyca Guadalupe Balles Soto (A01741687)
Fecha: 06/10/2024
*/

int main(){
    // El usuario ingresará el nombre del archivo de entrada (Ej. bitácora.txt).
    string nomArchivo;
    cout << "Ingresa el nombre del archivo de entrada: ";
    cin >> nomArchivo;

    ifstream inFile(nomArchivo); // Abrir archivo

    // Verificar si el archivo de entrada se abrió correctamente
    if (!inFile) {
        cerr << "Error al abrir el archivo de entrada" << endl;
        return 1;   // Salir si hay error
    }

    Lista listaMediterraneo; // Crear lista para el Mediterráneo
    Lista listaRojo; // Crear lista para el Mar Rojo

    string linea;
    while (getline(inFile, linea)) { // Leer cada línea del archivo
        istringstream iss(linea);
        Datos buque;
        iss >> buque.fecha >> buque.hora >> buque.entrada >> buque.ubi; // Extraer datos del buque

        // Insertar buque en la lista correspondiente
        if (buque.entrada == 'M') {
            listaMediterraneo.insertarEnOrden(buque);
        } else if (buque.entrada == 'R') {
            listaRojo.insertarEnOrden(buque);
        }
    }

    inFile.close(); // Cerrar archivo

    string serieElegida;
    cout << "Ingresa los primeros 3 caracteres del UBI a buscar: ";
    cin >> serieElegida; // Obtener serie a buscar
   
    // Ordenar y mostrar la cantidad de entradas de buques por mes
    listaMediterraneo.ordenarMeses(listaMediterraneo.obtenerPrimerNodo(), listaRojo.obtenerPrimerNodo(), serieElegida);

    return 0; // Finalizar el programa.
}