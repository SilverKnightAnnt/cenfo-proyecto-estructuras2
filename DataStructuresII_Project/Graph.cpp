/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Graph.cpp
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Dicimebre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */




#include "Graph.h"
#include <iostream>

Graph::Graph() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            Arc aux;
            matriz[i][j] = aux;
        }
    }
}

Graph::Graph(const Graph & orig) {
}

Graph::~Graph() {
}

Arc* Graph::getMatriz() {
    return *matriz;
}

bool Graph::addArc(int pRow, int pColumn, Arc pArc) {
    matriz[pRow][pColumn] = pArc;
    return true;
}

bool Graph::addInArray(int pPosition, string pCity) {
    if (searchCity(pCity) == -1) {
        referencia[pPosition] = pCity;
        return true;
    } else {
        return false;
    }
}

int Graph::searchCity(string pCity) {
    for (int i = 0; i < 25; i++) {
        if (referencia[i] == pCity) {
            return i;
        }
    }
    return -1;
}

string Graph::searchDataArc(int pRow, int pColumn) {
    return matriz[pRow][pColumn].toString();
}

string Graph::showArray() {
    ostringstream s;
    for (int i = 0; i < 25; i++) {
        s << "Ciudad # " << i << " " << referencia[i] << "\n";
    }
    return s.str();
}

string Graph::showArcs() {
    ostringstream s;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            s << i << " -> " << j << ": " << matriz[i][j].toString();
        }
    }
    return s.str();
}