/* Cenfotec – Costa Rica
 * Estructura de Datos 2 – 2018-03
 * Nombre del archivo: Main.cpp
 * Autor: Ernesto Desanti, Ángel Marín, Enzo Quartino, Daniel Rodríguez
 * e-mail: edesantis@ucenfotec.ac.cr,amarint@ucenfotec.ac.cr,equartinoz@ucenfotec.ac.cr,drodriguezr@ucenfotec.ac.cr
 * Proyecto Final - Estructura de Datos # 2
 * Fecha de creación: Diciembre del 2018
 * Fecha de último cambio: Diciembre del 2018
 */

#include <cstdlib>
#include "Controller.h"

void showMenu();
int readOption();
void executeAction(int);
void fillCountryNames();
void searchContry();
void showCountry();
void insertTag();
void showTags();
void showAdjacentLocations();
void searchCountryByName();
void showMinimumPath();

using namespace std;

Controller controller;

int main(int argc, char** argv) {
    int opt;
    fillCountryNames();
    insertTag();
    do {
        showMenu();
        opt = readOption();
        executeAction(opt);

    } while (opt != 6);

    return 0;
}

void showMenu() {
    cout << "\n\n";
    cout << "1. ---|           MOSTRAR PAÍS             |--- \n";
    cout << "2. ---|        MOSTRAR ETIQUETAS           |--- \n";
    cout << "3. ---|    MOSTRAR UBICACIONES ADYACENTES  |---\n";
    cout << "4. ---|         BUSCAR PAÍS (HASH)         |---\n";
    cout << "5. ---|           CAMINO MÍNIMO            |---\n";
    cout << "6. ---|              SALIR                 |--- \n";
}

int readOption() {
    int option;
    cout << "\nSeleccione acción a realizar: ";
    cin >> option;

    return option;
}

void executeAction(int pOption) {
    switch (pOption) {
        case 1:
            showCountry();
            break;
        case 2:
            showTags();
            break;
        case 3:
            showAdjacentLocations();
            break;
        case 4:
            searchCountryByName();
            break;
        case 5:
            showMinimumPath();
            break;
        case 6:
            cout << "Cerrando aplicación...";
            break;
        default:
            cout << "OPCIÓN INVÁLIDA";
    }
}

void fillCountryNames() {
    string countries[25] = {"Argentina", "Belice", "Brasil", "Bolivia", "Canada", "Chile",
        "Colombia", "Costa Rica", "Cuba", "Ecuador", "El Salvador",
        "Estados Unidos", "Guatemala", "Haiti", "Honduras", "Jamaica",
        "Mexico", "Nicaragua", "Panama", "Paraguay", "Peru", "Puerto Rico",
        "Republica Dominicana", "Uruguay", "Venezuela"};

    for (int index = 0; index < 25; index++) {
        controller.insertInArray(index, countries[index]);
        controller.addCountryByNameClosedHashC(countries[index]);
    }
}

void searchContry() {
    string countryA, countryB, buffer;
    cout << "Digitar nombre de ciudad A: ";
    getline(cin, buffer);
    getline(cin, countryA);
    cout << "Digitar nombre de ciudad B: ";
    getline(cin, buffer);
    getline(cin, countryB);
    cout << controller.searchArc(controller.searchCountry(countryA), controller.searchCountry(countryB));
}

void showCountry() {
    cout << controller.showCountries();
}

void insertTag() {
    controller.insertInMatrix(12, 16, 1243, 2, 200); //Guatemala - Mexico* 1243km 2h 200 dolares
    controller.insertInMatrix(12, 14, 658, 1.5, 300); //Guatemala - Honduras* 658km  1.5h 300 dolares
    controller.insertInMatrix(12, 4, 6089, 10, 300); //Guatemala - Canadá* 6089km  10h 300 dolares
    controller.insertInMatrix(1, 10, 688, 1.5, 250); //Belice - El Salvador* 688km  1.5h 300 dolares
    controller.insertInMatrix(1, 12, 600, 0.5, 250); // Belice - Guatemala* 600km 0.5h 250 dolares
    controller.insertInMatrix(24, 1, 2662, 15, 1500); // Venezuela - Belice* 2662km   15h 1500 dolares
    controller.insertInMatrix(4, 11, 2262, 11, 336); // Canadá - Estados Unidos* 2262km 11h 336d
    controller.insertInMatrix(10, 14, 301, 0.5, 230); // El Salvador - Honduras* 301km  0.5h 230d
    controller.insertInMatrix(14, 18, 1534, 2, 360); // Honduras - Panamá* 1534km 2h 360d
    controller.insertInMatrix(16, 6, 3178, 5, 430); //México - Colombia*  3178km 5h 430d
    controller.insertInMatrix(16, 18, 3298, 5, 600); // México - Panamá* 3298km 5h 600d
    controller.insertInMatrix(18, 9, 1209, 5, 377); //Panamá - Ecuador* 1209km 5h 377d
    controller.insertInMatrix(6, 11, 2437, 4, 300); //Colombia - Estados Unidos* 2437km 4h  300 dolares
    controller.insertInMatrix(0, 10, 6370, 10, 968); //  Argentina - El Salvador* 6370km 10h 968d
    controller.insertInMatrix(0, 7, 5745, 10, 858); // Argentina - Costa Rica* 5745km 10h 858d
    controller.insertInMatrix(6, 3, 2601, 4, 688); // Colombia - Bolivia* 2601km 4h 688d
    controller.insertInMatrix(20, 17, 2697, 16, 721); //Perú - Nicaragua* 2697km 16h 721d
    controller.insertInMatrix(20, 0, 4777, 4, 804); // Perú - Argentina* 4777km 4h 804d
    controller.insertInMatrix(3, 9, 2265, 18, 607); // Bolivia - Ecuador* 2265km 18h 607d
    controller.insertInMatrix(9, 23, 4137, 11, 500); // Ecuador - Uruguay* 4137km 11h 500d
    controller.insertInMatrix(23, 5, 1917, 2.5, 671); //Uruguay - Chile* 1917km 2.5h 671d
    controller.insertInMatrix(19, 23, 1043, 7, 423); //Paraguay - Uruguay* 1043km 7h 423d
    controller.insertInMatrix(19, 5, 1854, 3, 298); //Paraguay - Chile* 1854km 3h 298d
    controller.insertInMatrix(7, 9, 1427, 5, 492); //Costa Rica - Ecuador* 1427km 5h 492d
    controller.insertInMatrix(7, 17, 574, 1, 376); //Costa Rica - Nicaragua* 574km 1h 376d
    controller.insertInMatrix(7, 8, 1455, 9, 591); //Costa Rica - Cuba* 1455km 9h 591d 
    controller.insertInMatrix(21, 22, 381, 1, 215); //Puerto Rico - Republica Dominicana* 381km 1h 215d
    controller.insertInMatrix(22, 13, 225, 10, 900); //Republica Dominicana - Haití* 225km 10h 900d
    controller.insertInMatrix(13, 8, 640, 6.5, 1214); //Haití - Cuba* 640km 6.5h 1214d
    controller.insertInMatrix(13, 15, 537, 6.5, 1262); //Haití - Jamaica* 537km 6.5h 1262d 
    controller.insertInMatrix(2, 7, 4408, 32, 1016); //Brasil - Costa Rica* 4408km 32h 1016d
    controller.insertInMatrix(2, 8, 4872, 10, 1307); //Brasil - Cuba* 4872km 10h 1307d 
}

void showTags() {
    cout << controller.showArcs();
}

void showAdjacentLocations() {
    string country, buffer;
    cout << "Digite el nombre del país: ";
    getline(cin, buffer);
    getline(cin, country);
    cout << "\n---Recorridos disponibles---\n";
    cout << controller.showAdjacentLocations(country);
}

void searchCountryByName() {
    string country, buffer;
    cout << "Nombre del país a buscar: ";
    getline(cin, buffer);
    getline(cin, country);
    cout << "\n" << controller.searchCountryByName(country) << "\n";
}

void showMinimumPath() {
    string startingCountry, endingCountry, buffer;
    cout << "Ingrese el nombre de la ubicación inicio: ";
    getline(cin, buffer);
    getline(cin, startingCountry);
    cout << "Ingrese el nombre de la ubicación destino: ";
    getline(cin, endingCountry);
    cout << controller.showMinimumPath(startingCountry, endingCountry);
}