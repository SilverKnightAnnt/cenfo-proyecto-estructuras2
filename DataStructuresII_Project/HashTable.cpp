/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: HashTable.cpp
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Diciembre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */

#include "HashTable.h"

using namespace std;

HashTable::HashTable() {
    for (int index = 0; index < 25; index++) {
        countries[index] = "Decoy";
    }
}

HashTable::~HashTable() {
    for (int index = 0; index < 25; index++) {
        if (countries [index] != "Decoy") {
            delete &countries[index];
        }
    }
}

string* HashTable::getCountriesArray() {
    return countries;
}

bool HashTable::addCountryClosedHash(int pIndex, string pCountry) {
    if (searchByCountryName(pIndex, pCountry) != "") {
        return false;
    } else {
        if (getCountriesArray()[pIndex] == "Decoy") {
            getCountriesArray()[pIndex] = pCountry;
        } else {
            pIndex++;
            if (pIndex == 25) {
                pIndex = 0;
            }
            addCountryClosedHash(pIndex, pCountry);
        }
        return true;
    }
}

string HashTable::searchByCountryName(int pIndex, string pCountry) {
    ostringstream stream;
    string obtainedSpace = getCountriesArray()[pIndex];
    while (obtainedSpace != "Decoy") {
        if (obtainedSpace == pCountry) {
            stream << obtainedSpace;
        } else {
            pIndex++;
            if (pIndex == 25) {
                pIndex = 0;
            }
            stream << searchByCountryName(pIndex, pCountry);
        }
        return stream.str();
    }
    return stream.str();
}

