#include "Lista.h"
#include <iostream>
#include <algorithm>

using namespace std;

NodoLista::NodoLista(): buque(valor), next(nullptr) {}
NodoLista::~NodoLista() {}

Lista::Lista() {
    first = nullptr;
    size = 0;
}

Lista::~Lista() {
    NodoLista* actual = first;
    while (actual != nullptr) {
        NodoLista* temp = actual;
        actual = actual->next;
        delete temp;
    }
}

void cargarDatos() {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo de entrada (Ej. canal.txt): ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    Lista listaMediterraneo;
    Lista listaRojo;

    string linea;
    while (getline(archivo, linea)) {
        Datos buque;
        istringstream iss(linea);
        iss >> buque.fecha >> buque.hora >> buque.entrada >> buque.ubi;

        if (buque.entrada == "M") {
            listaMediterraneo.insertarEnOrden(buque);
        } else if (buque.entrada == "R") {
            listaRojo.insertarEnOrden(buque);
        }
    }

    archivo.close();
}

// Método para comparar dos estructuras de tipo Datos
// Compara dos objetos de clase Datos. Compara los atributos de UBI de los objetos y los ordena en menor y mayor. 
// En el caso de que los atributos de UBI sean iguales en ambos objetos, pasa a comparar los atributos de fecha.
bool compararDatos(const Datos& a, const Datos& b) {
    if (a.ubi != b.ubi) return a.ubi < b.ubi;

    // Extraer día, mes y año de la fecha para 'a'
    int dayA = stoi(a.fecha.substr(0, 2));
    int monthA = stoi(a.fecha.substr(3, 2));
    int yearA = stoi(a.fecha.substr(6, 4));

    // Extraer día, mes y año de la fecha para 'b'
    int dayB = stoi(b.fecha.substr(0, 2));
    int monthB = stoi(b.fecha.substr(3, 2));
    int yearB = stoi(b.fecha.substr(6, 4));

    // Comparar por año, mes y día
    if (yearA != yearB) return yearA < yearB;
    if (monthA != monthB) return monthA < monthB;
    return dayA < dayB;
}

// Método para insertar al final o en orden por UBI
void insertarEnOrden(Datos buque) {
    NodoLista* nuevoNodo = new NodoLista(buque);

    if (first == nullptr || compararDatos(buque, first->buque)) {
        nuevoNodo->next = first;
        first = nuevoNodo;
    } else {
        NodoLista* actual = first;
        while (actual->next != nullptr && compararDatos(actual->next->buque, buque)) {
            actual = actual->next;
        }
        nuevoNodo->next = actual->next;
        actual->next = nuevoNodo;
    }
}

void Lista::ordenarMeses(Lista* serieM, Lista* serieR) {
    int cantM;
    int cantR;

    if (serieM != nullptr) {
        NodoLista* actualM = serieM->first;

        while (actualM != nullptr){
            string fecha = actualM->buque.fecha.substr(3, 7);
            int cantM = 0;

            while (actualM != nullptr && actualM->buque.fecha.substr(3, 7) == fecha) {
                if (actualM->buque.entrada == "M") {
                    cantM++;
                } 
                actualM = actualM->next;
            }
        }
    }

    if (serieR != nullptr) {
        NodoLista* actualR = serieR->first;

        while (actualR != nullptr){
            string fecha = actualR->buque.fecha.substr(3, 7);
            int cantR = 0;

            while (actualR != nullptr && actualR->buque.fecha.substr(3, 7) == fecha) {
                if (actualR->buque.entrada == "M") {
                    cantR++;
                } 
                actualR = actualR->next;
            }
        }
    }

    cout << fecha << " " << cantM << " " << cantR << endl;
}

// Método para imprimir la lista
void Lista::imprimir() const {
    NodoLista* actual = first;
    while (actual != nullptr) {
        cout << actual->buque.fecha << " " << actual->buque.hora << " "
             << actual->buque.entrada << " " << actual->buque.ubi << endl;
        actual = actual->next;   
    }
}
