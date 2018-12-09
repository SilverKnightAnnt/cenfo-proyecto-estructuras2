/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Arc.cpp
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Dicimebre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */


#include "Arc.h"

#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

Arc::Arc() {
    setDistance(0);
    setHours(0);
    setCost(0);
}

Arc::Arc(int pDistance, int pHours, int pCost) {
    setDistance(pDistance);
    setHours(pHours);
    setCost(pCost);
}

int Arc::getDistance() {
    return distance;
}

void Arc::setDistance(int pDistance) {
    distance = pDistance;
}

int Arc::getHours() {
    return hours;
}

void Arc::setHours(int pHours) {
    hours = pHours;
}

int Arc::getCost() {
    return cost;
}

void Arc::setCost(int pCost) {
    cost = pCost;
}

string Arc::toString() {
    ostringstream s;
    s << distance << " metros || " << hours << " horas || " << cost << " dolares\n";
    return s.str();
}