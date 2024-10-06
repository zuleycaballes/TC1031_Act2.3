#include "Lista.h"
#include "Datos.h"

/*
Complejidad: O(log n)
Donde 'n' es el número de elementos en el vector 'buques'
Esta función booleana utiliza un algoritmo de búsqueda de tipo binaria. 
Este tipo de algoritmo es utilizado para encontrar un elemento dentro de un arreglo. 
El arreglo es dividido en 2 partes, para después elegir una de las mitades (verificando si el elemento que se busca es mayor o menor al elemento central) y así hasta encontrar el elemento,
lo que va reduciendo la cantidad de comparaciones que realiza el algoritmo. Recibe el vector buques y los 3 primeros dígitos de la serie que se desea buscar.
*/
bool buscarBuque(const Datos buques, const string& serieElegida) {
    

    int i = 0;
    int f = buques.size() - 1; 
    while (i <= f) { 
        int m = i + (f - i) / 2; 
        if (buques[m].ubi.substr(0, 3) == serieElegida) { 
            return true;
        } else if (buques[m].ubi < serieElegida) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }
    return false;
}

int buscarBuque(const string& serieElegida)
    {
        while (true)
        {
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
}