#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string> 

using namespace std;

struct Datos {
    string fecha; // Fecha de entrada del buque
    string hora; // Hora de entrada del buque
    char entrada; // Punto de entrada (M para Mediterráneo, R para Rojo)
    string ubi; // Identificador único del buque
};

class NodoLista {
public:
    Datos buque; // Datos del buque
    NodoLista *next; // Puntero al siguiente nodo
    NodoLista(Datos buque); // Constructor
    ~NodoLista(); // Destructor
};

class Lista {
private:
    NodoLista *first; // Primer nodo de la lista
public:
    Lista(); // Constructor
    bool compararDatos(const Datos& a, const Datos& b); // Compara dos buques por UBI y fecha
    void insertarEnOrden(Datos buque); // Inserta un nuevo buque en la lista, manteniendo el orden
    void ordenarMeses(NodoLista* listaM, NodoLista* listaR, const string& serie); // Ordena y muestra la cantidad de entradas de buques por mes
    NodoLista* obtenerPrimerNodo(); // Método getter para obtener el puntero 'first'
    ~Lista(); // Destructor
};

#endif
