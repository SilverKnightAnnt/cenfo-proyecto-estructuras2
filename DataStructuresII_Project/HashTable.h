/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: HashTable.h
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Diciembre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
#include "Arc.h"


class HashTable {
private:
    string countries[25];
public:
    HashTable();
    virtual ~HashTable();
    bool addCountryClosedHash(int, string);
    string* getCountriesArray();
    string searchByCountryName(int,string);
};

#endif /* HASHTABLE_H */