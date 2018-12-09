/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Graph.h
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Dicimebre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */


#ifndef GRAPH_H
#define GRAPH_H
#include "Arc.h"
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Graph {
public:
    Graph();
    Graph(const Graph& orig);
    virtual ~Graph();
    Arc* getMatriz();
    bool addArc(int, int, Arc);
    bool addInArray(int, string);
    int searchCity(string);
    string searchDataArc(int, int);
    string showArray();
    string showArcs();

private:
    Arc matriz[25][25];
    string referencia[25];

};

#endif /* GRAPH_H */

