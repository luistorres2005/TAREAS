/*
Nombre del estudiante: TORRES CABEZAS YOBER LUIS
Fecha: 31/07/2026
Tema: Menú repetitivo
*/

/*
Ejercicio 4 — Menú repetitivo
Elaborar un programa en C++ que muestre el siguiente menú:
1. Mostrar el doble de un número
2. Mostrar el triple de un número
3. Salir
El programa debe repetirse hasta que el usuario elija la opción 3.
Si el usuario ingresa una opción inválida, el programa debe mostrar un mensaje de
error y volver a mostrar el menú.
*/

/* 
E: Una opción de menú y un númeroadicional para realizar el cálculo 
P:
S: Un número adicional para realizar el cálculo y el aviso de finalización o error
*/

#include <iostream>
using namespace std;

int main() {
    int  opcion;
    double numero; //  por si el usuario ingresa decimales.

    do {
        cout << "Menu:" << endl;
        cout << "1. Mostrar el doble de un numero" << endl;
        cout << "2. Mostrar el triple de un numero" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion (1-3): ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> numero;
                cout << "El doble de " << numero << " es: " << (numero * 2) << endl;
                break;
            case 2:
                cout << "Ingrese un numero: ";
                cin >> numero;
                cout << "El triple de " << numero << " es: " << (numero * 3) << endl;
                break;
            case 3:
                cout << "Saliste del programa." << endl;
                break;
            default:
                cout << "Error: Opcion invalida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 3);

    return 0; // Termina el programa
}