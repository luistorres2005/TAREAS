/*
Ejercicio 5: Reparto de horas en semanas, días y horas
Escribe un algoritmo que reciba un número entero de horas totales (un valor no
negativo). El algoritmo debe convertir esa cantidad de horas a semanas, días y horas
sobrantes, considerando que una semana tiene 168 horas y un día tiene 24 horas. Al
final debe mostrar cuántas semanas, cuántos días y cuántas horas sobran.

E: Numero total de horas, valor entero
P: Validar que las horas no sean negativas, Calcular las semanas, Calcular los dias y el residuo 
S: Cantidad de semanas, dias y horas sobrantes o mensaje de error
*/

#include <iostream>
using namespace std;

int main() {    
    int hT, sem, di, hS, rH;    
    cout << "Ingrese el numero total de horas:" << endl;    
    cin >> hT;    
    if (hT < 0) {        
        cout << "La cantidad de horas no puede ser negativa." << endl;
    } else {         
        sem = hT / 168;      
        rH = hT - (sem * 168);      
        di = rH / 24;       
        hS = rH - (di * 24);  

        cout << "Semanas: " << sem << endl;
        cout << "Dias: " << di << endl;
        cout << "Horas sobrantes: " << hS << endl;
    } 

    return 0;
}