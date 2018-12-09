/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Controller.h
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Dicimebre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */


#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Graph.h"
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
class Controller {
public:
    Controller();
    Controller(const Controller& orig);
    virtual ~Controller();
    Graph* getGraph();
    bool insertInArray(int, string);
    string insertInMatriz(int, int, int, int, int);
    int searchCity(string);
    string searchArc(int, int);
    string showCities();
    string showArcs();
private:
    Graph* graph;

};

#endif /* CONTROLLER_H */

