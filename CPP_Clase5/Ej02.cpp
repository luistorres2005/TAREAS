/*
Ejercicio 2: Área y perímetro de un rectángulo
Escribe un algoritmo que reciba la base y la altura de un rectángulo. Con esos datos,
debe calcular y mostrar el área y el perímetro del rectángulo.

E: Base y Altura 
P: Validar que los datos sean mayor a cero, calcular area y perimetro.
S: Valor del area y perimetro o mensaje de error. 
*/

#include <iostream>

using namespace std;

int main() {
    double Ba, Al, Ar, Pe;    
    cout << "Ingrese la base del rectangulo" << endl;    
    cin >> Ba;    
    cout << "Ingrese la altura del rectangulo" << endl;    
    cin >> Al;    
    if (Ba <= 0 || Al <= 0) {        
        cout << "La base y la altura deben ser mayor a cero." << endl;
    } else {         
        Ar = Ba * Al;        
        Pe = 2 * (Ba + Al);        
        cout << "El area del rectangulo es: " << Ar << endl;       
        cout << "El perimetro del rectangulo es: " << Pe << endl;
    } 

    return 0;
}