/*
Ejercicio 1: Conversión de temperatura
Escribe un algoritmo que reciba una temperatura en grados Celsius y la convierta a
grados Fahrenheit. El algoritmo debe mostrar el valor final en Fahrenheit. Usa la
conversión estándar entre Celsius y Fahrenheit. Usa la conversión F = (C × 9/5) + 32.

E: Una temperatura en grados Celsius.
P: Aplicar F = (C × 9/5) + 32
S: Valor final en Fahrenheit.
*/

#include <iostream>
#include <string>
using namespace std;

int main (){
    double cels, fah;
    cout<< "ingrese celsius ";
    cin>> cels;
    fah = cels * 9/5 + 32;
    cout << "La temperatura en Fahrenheit es: " << fah << endl;

    return 0;
}