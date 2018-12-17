/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Graph.h
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Diciembre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include "Arc.h"

using namespace std;

class Graph {
public:
    Graph();
    virtual ~Graph();
    Arc* getAdjacentMatrix();
    string* getCountriesReference();
    bool addArc(int, int, Arc);
    bool addInArray(int, string);
    int searchCountry(string);
    string searchDataArc(int, int);
    string showArray();
    string showArcs();
    string showAdjacentLocations(string); 
    string showMinPathUsingDijkstra(string, string);
private:
    Arc adjacentMatrix[25][25];
    string countriesReference[25];
    int minCost(int[], bool[]);
    string printPath(int[], int);
    string printSolution(int[], int[], int, int);
    int obtainIndexBasedOnCountryName(string);
};

#endif /* GRAPH_H */

