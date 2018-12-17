/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Arc.h
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Diciembre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */

#ifndef ARC_H
#define ARC_H

#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Arc {
public:
    Arc();
    Arc(int, int, int);
    int getDistance();
    void setDistance(int);
    int getHours();
    void setHours(int);
    int getCost();
    void setCost(int);
    string toString();

private:
    int distance;
    int hours;
    int cost;
};

#endif /* ARC_H */

