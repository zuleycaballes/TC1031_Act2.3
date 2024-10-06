// Datos.h
#ifndef DATOS_H
#define DATOS_H

#include <vector>
#include <string>

using namespace std;

struct Datos {
    string fecha;
    string hora;
    char entrada;
    string ubi;
};

// Funciones para ordenar y buscar
void ordenarBuque(Datos& arr, int left, int right);
bool buscarBuque(const Datos& buques, const string& serieElegida);

// Comparador para ordenar Datos
bool compararDatos(const Datos& a, const Datos& b);

#endif