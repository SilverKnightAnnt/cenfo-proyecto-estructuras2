/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Controller.h
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Diciembre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include "Graph.h"
#include "HashTable.h"

using namespace std;

class Controller {
public:
    Controller();
    virtual ~Controller();
    Graph* getGraph();
    HashTable* getHashTable();
    bool insertInArray(int, string);
    string insertInMatrix(int, int, int, int, int);
    int searchCountry(string);
    string searchArc(int, int);
    string showCountries();
    string showArcs();
    string showAdjacentLocations(string);
    string addCountryByNameClosedHashC(string);
    int hashingString(string);
    string searchCountryByName(string);
    string showMinimumPath(string, string);
private:
    Graph* graph;
    HashTable* hashTable;

};

#endif /* CONTROLLER_H */

