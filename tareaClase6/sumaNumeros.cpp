/*
Nombre del estudiante: TORRES CABEZAS YOBER LUIS
Fecha: 30/07/2026
Tema: Suma de 5 numeros

*/

/*
Ejercicio 2 — Suma de 5 números
Elaborar un programa en C++ que solicite al usuario 5 números enteros y calcule la
suma total de esos valores.
Al final, el programa debe mostrar:
• la suma total
• y cuántos números fueron ingresados
*/

/*
E: 5 números enteros
P: Calcular la suma total de esos valores
S: la suma total y cuántos números fueron ingresados 
*/

#include <iostream>
using namespace std;    

int main() { 
    int numero;
    int cantidad = 0; // Acumulador, inicia en 0
    int suma = 0; // Contador de numeros ingresados, inicia en 0

    cout << "Ingrese 5 numeros enteros:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << " Ingrese el numero " << i << ": ";
        cin >> numero;
        suma += numero; //acumula el valor
        cantidad++; // contar el numero ingresado
    }

    cout << "\nResultados: " << endl;
    cout << "La suma total es:  " << suma << endl;
    cout << "Cantidad de numeros ingresados: " << cantidad << endl;

    return 0; // Termina el programa    
}