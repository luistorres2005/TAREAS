/*
Nombre del estudiante: TORRES CABEZAS YOBER LUIS
Fecha: 30/07/2026
Tema: Tabla de multiplicar repetitiva
*/

/*
Ejercicio 3: Elaborar un programa en C++ que solicite al usuario un número entero y muestre su
tabla de multiplicar del 1 al 10.
Al final, el programa debe mostrar un mensaje indicando que la tabla fue generada
correctamente.
*/

/*
E: Solicite al usuario un número entero
P: Calcular la tabla de multiplicar del 1 al 10 para el número ingresado
S: Muestra la tabla de multiplicar del 1 al 10, 
   mostrar un mensaje indicando que la tabla fue generada correctamente.
*/

#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Ingrese un numero entero para generar su tabla de multiplicar: ";
    cin >> numero;

    cout << "Tabla de multiplicar del " << numero << ":" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << numero << " x " << i << " = " << (numero * i) << endl;
    }
    cout << "La tabla de multiplicar fue generada correctamente." << endl;
    
    return 0; // Termina el programa
} 