/*
Ejercicio 4: Nota final con ponderaciones
Escribe un algoritmo que reciba tres calificaciones: Parcial 1, Parcial 2 y Proyecto.
Con esos valores, debe calcular la nota final usando ponderaciones: el Parcial 1 vale
el 30%, el Parcial 2 vale el 30% y el Proyecto vale el 40%. El algoritmo debe mostrar la
nota final.

E: Calificaciones de los parciales y proyecto
P: Validar notas. Calcular la nota final
S: Nota fial o mensaje de error si la nota es invalida 
*/

#include <iostream>
using namespace std;

int main() {    
    double p1, p2, pro, nF;    
    cout << "Ingrese la nota del Parcial 1:" << endl;    
    cin >> p1;    
    cout << "Ingrese la nota del Parcial 2:" << endl;    
    cin >> p2;    
    cout << "Ingrese la nota del Proyecto:" << endl;    
    cin >> pro;
    
    if (p1 < 0 || p2 < 0 || pro < 0) {        
        cout << "Las calificaciones no pueden ser negativas." << endl;
    } else {         
        nF = (p1 * 0.30) + (p2 * 0.30) + (pro * 0.40);     
        
        cout << "La nota final es: " << nF << endl;
    } 
    return 0;
}