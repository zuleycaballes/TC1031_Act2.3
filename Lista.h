#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
#include "Datos.h" 

using namespace std;

struct Datos {
    string fecha;
    string hora;
    char entrada;
    string ubi;
};

class NodoLista {
public:
    Datos buque;
    NodoLista *next;
    NodoLista();
    NodoLista(Datos valor);
    ~NodoLista();
};

class Lista {
private:
    NodoLista *first;
public:
    Lista();
    ~Lista();


    void insertarEnOrden(Datos buque) {
        Nodo
    }    // Lista* nuevoNodo = new NodoLista(buque);
        
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
        }Método para insertar al final o en orden por U
};


    // Método para imprimir la lista
    v

    NodoLista* getFirst() const; oid imprimir() const {
        NodoLista* actual = first;
        while (actual != nullptr) {
            cout << actual->buque.fecha << " " << actual->buque.hora << " "
                 << actual->buque.entrada << " " << actual->buque.ubi << endl;
            actual = actual->next;   
        }
    }
}
#endif