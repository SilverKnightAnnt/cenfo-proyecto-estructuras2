/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Controller.cpp
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Diciembre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */

#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include "Controller.h"
#include "HashTable.h"

using namespace std;

Controller::Controller() {
    graph = new Graph();
    hashTable = new HashTable();
}

Controller::~Controller() {
}

Graph* Controller::getGraph() {
    return graph;
}

HashTable* Controller::getHashTable() {
    return hashTable;
}

bool Controller::insertInArray(int pPosition, string pCountry) {
    return getGraph()->addInArray(pPosition, pCountry);

}

string Controller::insertInMatrix(int pRow, int pColumn, int pDistance, int pTime, int pCost) {
    Arc arc(pDistance, pTime, pCost);
    getGraph()->addArc(pRow, pColumn, arc);
    return "Datos guardados";
}

int Controller::searchCountry(string pCountry) {
    return getGraph()->searchCountry(pCountry);
}

string Controller::searchArc(int pRow, int pColumn) {
    return getGraph()->searchDataArc(pRow, pColumn);
}

string Controller::showCountries() {
    return getGraph()->showArray();
}

string Controller::showArcs() {
    return getGraph()->showArcs();
}

string Controller::showAdjacentLocations(string pCountry) {
    return getGraph()->showAdjacentLocations(pCountry);
}

string Controller::addCountryByNameClosedHashC(string pCountry) {
    if (getHashTable()->addCountryClosedHash(hashingString(pCountry), pCountry) == true) {
        return "\n¡Se registró exitosamente!";
    } else {
        return "\nNo se pudo ingresar el país.";
    }
}

string Controller::searchCountryByName(string pCountry) {
    string found = getHashTable()->searchByCountryName(hashingString(pCountry), pCountry);
    if (found != "") {
        return found;
    } else {
        return "\nNo existe ningun registro que corresponda\n";
    }
    return "\nNo existe ningun registro que corresponda\n";
}

int Controller::hashingString(string word) {
    int seed = 1;
    unsigned long hash = 0;
    for (int i = 0; i < word.length(); i++) {
        hash = (hash * seed) + word[i];
    }
    return hash % 23;
}

string Controller::showMinimumPath(string pStartingPoint, string pEndingPoint) {
    return getGraph()->showMinPathUsingDijkstra(pStartingPoint, pEndingPoint);
}

