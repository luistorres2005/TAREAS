/*
Ejercicio 3: Descuento por edad

Escribe un algoritmo que reciba la edad de una persona y determine el precio a pagar
según estas reglas: si la edad es 18 o más, el precio es 5 dólares; si la edad es menor
a 18, el precio es 2.50 dólares. El algoritmo debe mostrar el precio final.

E: Edad de la persona
P: Validar que la edad sea mayor o ifual a cero. Si la edad es mayor o igual a 18, 
   asignar el precio de 5 dolares  
S: Precio final o mensaje de error
*/

#include <iostream>
using namespace std;

int main() {
    
    int Edad;    
    double Precio;    
    cout << "ingrese la edad" << endl;   
    cin >> Edad;

    if (Edad < 0) {
        cout << "La edad debe ser mayor a cero." << endl;
    } else {         
        if (Edad >= 18) {
            Precio = 5;
        } else { 
            Precio = 2.50;
        }     
        
        cout << "El precio final a pagar es: " << Precio << endl;
    } 

    return 0;
}