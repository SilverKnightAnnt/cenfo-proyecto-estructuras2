/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Controller.cpp
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Dicimebre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */



#include "Controller.h"

#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

Controller::Controller() {
    graph = new Graph();
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

Graph* Controller::getGraph() {
    return graph;
}

bool Controller::insertInArray(int pPosition, string pCity) {
    return getGraph()->addInArray(pPosition, pCity);

}

string Controller::insertInMatriz(int pRow, int pColumn, int pDistance, int pTime, int pCost) {
    Arc arc(pDistance, pTime, pCost);
    getGraph()->addArc(pRow, pColumn, arc);
    return "Datos guardados";
}

int Controller::searchCity(string pCity) {
    return getGraph()->searchCity(pCity);
}

string Controller::searchArc(int pRow, int pColumn) {
    return getGraph()->searchDataArc(pRow, pColumn);
}

string Controller::showCities() {
    return getGraph()->showArray();
}

string Controller::showArcs() {
    return getGraph()->showArcs();
}