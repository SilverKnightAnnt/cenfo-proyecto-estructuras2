/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Graph.cpp
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Diciembre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */

#include <iostream>
#include <stdio.h> 
#include <limits.h> 
#include "Graph.h"

Graph::Graph() {
    for (int row = 0; row < 25; row++) {
        for (int column = 0; column < 25; column++) {
            Arc genericArc;
            adjacentMatrix[row][column] = genericArc;
        }
    }
}

Graph::~Graph() {
}

Arc* Graph::getAdjacentMatrix() {
    return *adjacentMatrix;
}

string* Graph::getCountriesReference() {
    return countriesReference;
}

bool Graph::addArc(int pRow, int pColumn, Arc pArc) {
    adjacentMatrix[pRow][pColumn] = pArc;
    return true;
}

bool Graph::addInArray(int pPosition, string pCountry) {
    if (searchCountry(pCountry) == -1) {
        countriesReference[pPosition] = pCountry;
        return true;
    } else {
        return false;
    }
}

int Graph::searchCountry(string pCountry) {
    for (int row = 0; row < 25; row++) {
        if (getCountriesReference()[row] == pCountry) {
            return row;
        }
    }
    return -1;
}

string Graph::searchDataArc(int pRow, int pColumn) {
    return adjacentMatrix[pRow][pColumn].toString();
}

string Graph::showArray() {
    ostringstream stream;
    for (int row = 0; row < 25; row++) {
        stream << "Ciudad # " << row << " " << getCountriesReference()[row] << "\n";
    }
    return stream.str();
}

string Graph::showArcs() {
    ostringstream stream;
    for (int row = 0; row < 25; row++) {
        for (int column = 0; column < 25; column++) {
            stream << getCountriesReference()[row] << " -> "
                    << getCountriesReference()[column] << ": "
                    << adjacentMatrix[row][column].toString();
        }
    }
    return stream.str();
}

string Graph::showAdjacentLocations(string pDesiredCountry) {
    ostringstream stream;
    for (int row = 0; row < 25; row++) {
        for (int column = 0; column < 25; column++) {
            if ((getCountriesReference()[row] == pDesiredCountry
                    || getCountriesReference()[column] == pDesiredCountry)
                    && adjacentMatrix[row][column].getDistance() != 0) {
                stream << getCountriesReference()[row] << " -> "
                        << getCountriesReference()[column] << ": "
                        << adjacentMatrix[row][column].toString();
            }
        }
    }
    return stream.str();
}

int Graph::minCost(int pCost[], bool pSptSet[]) {
    int min = INT_MAX, minIndex;

    for (int value = 0; value < 25; value++)
        if (pSptSet[value] == false && pCost[value] <= min)
            min = pCost[value], minIndex = value;

    return minIndex;
}

string Graph::printPath(int pParent[], int pIndex) {
    ostringstream stream;
    if (pParent[pIndex] == -1)
        return "";

    stream << printPath(pParent, pParent[pIndex]);
    stream << "->" << getCountriesReference()[pIndex];
    return stream.str();
}

string Graph::printSolution(int pCost[], int pParent[], int pStartPoint,int pEndPoint) {
    ostringstream stream;
    int startPoint = 0;
    stream << "\nVertice\t\t\t Costo en dolares\t\t\tCamino";
    for (int destinationIndex = 1; destinationIndex < 25; destinationIndex++) {
        if (destinationIndex == pEndPoint) {
            stream << "\n" << getCountriesReference()[pStartPoint] << "->"
                    << getCountriesReference()[destinationIndex] << "\t\t" << pCost[destinationIndex]
                    << "\t\t" << getCountriesReference()[pStartPoint];
            stream << printPath(pParent, destinationIndex);
        }

    }
    return stream.str();
}

string Graph::showMinPathUsingDijkstra(string pStart, string pEnd) {
    int start = obtainIndexBasedOnCountryName(pStart);
    int end = obtainIndexBasedOnCountryName(pEnd);
    int cost[25];
    bool sptSet[25];
    int parent[25];

    for (int index = 0; index < 25; index++) {
        parent[index] = -1;
        cost[index] = INT_MAX;
        sptSet[index] = false;
    }

    cost[start] = 0;

    for (int count = 0; count < 25 - 1; count++) {
        int picked = minCost(cost, sptSet);

        sptSet[picked] = true;

        for (int other = 0; other < 25; other++)
            if (!sptSet[other] && adjacentMatrix[picked][other].getCost() &&
                    cost[picked] + adjacentMatrix[picked][other].getCost() < cost[other]) {
                parent[other] = picked;
                cost[other] = cost[picked] + adjacentMatrix[picked][other].getCost();
            }
    }

    return printSolution(cost, parent, start, end);
}

int Graph::obtainIndexBasedOnCountryName(string pCountry) {
    for (int row = 0; row < 25; row++) {
        if (getCountriesReference()[row] == pCountry) {
            return row;
        }
    }
}