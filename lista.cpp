#include "Lista.h"
#include <iostream>
#include <algorithm>

using namespace std;

Lista::Lista() {
    first = nullptr;
    size = 0;
}

int Lista::buscarBuque(const string& serieElegida) {
    NodoLista *actual = first; // Reinicia el nodo actual al inicio de la lista
    int posicion = 0;

    // Solicita al usuario que ingrese un valor
    cout << "Ingresar buque a buscar: ";
    string input;
    cin >> input;

    // Recorrer la lista en busca del valor
    while (actual != nullptr)
    {
        if (actual->buque.ubi.substr(0, 3) == serieElegida) {
            cout << "Buque encontrado en la posición: " << posicion << endl;
            return posicion;
        }
        actual = actual->next; // Moverse al siguiente nodo
        posicion++;            // Incrementar la posición
        
    }
    cout << "Buque no encontrado" << endl;
    return -1;
}

// Constructor, complejidad O(1)
    Lista() {
        first = nullptr;
    }

    // Destructor, complejidad O(n)
    ~Lista()
    {
        NodoLista *actual = first;
        while (actual != nullptr) {
            NodoLista *temp = actual;
            actual = actual->next;
            delete temp;
        }
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

    // Método para imprimir la lista
    void imprimir() const {
        NodoLista* actual = first;
        while (actual != nullptr) {
            cout << actual->buque.fecha << " " << actual->buque.hora << " "
                 << actual->buque.entrada << " " << actual->buque.ubi << endl;
            actual = actual->next;   
        }
    }

---------------
NodoLista(Datos valor) {
        buque = valor;
        next = nullptr;
    }

---------------