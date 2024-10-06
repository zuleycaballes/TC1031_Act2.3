#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Lista.h"
using namespace std;

/*
El código presentado realiza el ordenamiento y posterior búsqueda de datos utilizando los algoritmos de ordenamiento MergeSort y busqueda binaria a partir de un archivo .txt.
El archivo de entrada contiene información de distintos buques en el siguiente formato:
    <fecha> <hora> <punto-entrada> <UBI-Identificador único del buque>

Los datos de los buques son ordenados por UBI y fecha y almacenados en un vector. De esta manera el usuario podrá buscar la información de buques, ingresando los primeros 3 dígitos de la UBI de estos.

Autoras:
Elizabeth Jauregui Zarate (A01253381)
Mariana Carrillo Holguin (A01253358)
Zuleyca Guadalupe Balles Soto (A01741687)

Fecha: 06/10/2024
*/

int main(){
    // El usuario ingresará el nombre del archivo de entrada (Ej. bitácora.txt).
    string nomArchivo;
    cout << "Ingresa el nombre del archivo de entrada. ";
    cin >> nomArchivo;

    ifstream inFile(nomArchivo);

    // Verificar si el archivo de entrada se abrió correctamente
    if (!inFile) {
        cerr << "Error al abrir el archivo de entrada" << endl;
        return 1;
    }

    Lista listaMediterraneo;
    Lista listaRojo;

    string linea;
    while (getline(inFile, linea)) {
        Datos buque;
        istringstream iss(linea);
        iss >> buque.fecha >> buque.hora >> buque.entrada >> buque.ubi;

        if (buque.entrada == "M") {
            listaMediterraneo.insertarEnOrden(buque);
        } else if (buque.entrada == "R") {
            listaRojo.insertarEnOrden(buque);
        }
    }

    inFile.close();
}

    // Leer los datos del archivo y almacenar los objetos buque en el vector buques
    // Complejidad: O(n), donde n es el número de registros en el archivo
    while (inFile >> buque.fecha >> buque.hora >> buque.entrada >> buque.ubi) {
        buques.push_back(buque);
    }

    // Ordenar el vector buques por fecha y hora
    // Complejidad: O(n log n), donde n es el tamaño del vector buques
    ordenarBuque(buques, 0, buques.size() - 1);

    string serieElegida;
    cout << "Ingresa los primeros 3 caracteres de el UBI a buscar. ";
    cin >> serieElegida;

    // Buscar y mostrar los buques con la serie especificada (primeros 3 dígitos)
    // Complejidad de búsqueda: O(n), donde n es el tamaño del vector buques
    if (buscarBuque(buques, serieElegida)){
        cout << "La información de los buques de la serie " << serieElegida << ": " << endl;
        for (const Datos& buque : buques){
            if (buque.ubi.substr(0, 3) == serieElegida){
                cout << buque.fecha << " " << buque.hora << " " << buque.entrada << " " << buque.ubi << endl;
            }
        }
    } else {
        cout << "No se encontraron buques con la serie " << serieElegida << endl;
    }

    inFile.close();
    return 0;
}   