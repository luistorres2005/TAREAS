/*
Ejercicio 1 — Números pares hasta N
Elaborar un programa en C++ que solicite al usuario un número entero positivo N y
muestre en pantalla todos los números pares desde 1 hasta N.
Si el usuario ingresa un valor menor o igual a 0, el programa debe mostrar un mensaje
de error.
*/

/*
E: Un número entero positivo N
P: Se realiza la validación: ¿Es N <= 0?
      Si es verdadero: Se termina el programa inmediatamente
      Si es falso (N > 0): Se inicializa una variable de control en i = 1
   Si es falso (N > 0): Se inicializa una variable de control en i = 1
      Se verifica si el número actual es par usando el operador de residuo.
      Si el residuo es cero, se prepara ese número para mostrarlo en pantalla.
      Se incrementa la variable de control de uno en uno para avanzar al siguiente número.
      
S: Si el número fue inválido: 
   El mensaje de texto "Error: El numero ingresado debe ser un entero positivo (mayor que 0)."

   Si el número fue válido: 
   Todos los números que cumplieron la condición de ser pares, impresos en pantalla.
*/

#include <iostream>
using namespace std;    

int main() {
    int N;
    cout << "Ingrese un numero entero positivo: ";
    cin >> N;

    // Validacion: si N es menor o igual a 0, mostrar mensaje de error
    if (N <= 0) {
        cout << "Error: El numero ingresado debe ser un entero positivo." << endl;
        return 1; // Termina el programa con error
    }

    cout << "Numeros pares desde 1 hasta " << N << ":" << endl;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) { // Verifica si el número es par
            cout << i << " "; // Muestra el número par en pantalla
        }
    }
    cout << endl; 
    return 0; // Termina el programa 
}   