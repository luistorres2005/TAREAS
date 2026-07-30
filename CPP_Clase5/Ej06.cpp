/*
Ejercicio 6: Plan de internet (validación + recargo)
Escribe un algoritmo que reciba dos datos: el plan de internet y el consumo. El plan
solo puede ser 1 o 2, y el consumo debe ser un número mayor o igual a cero.
Si el plan es 1, la tarifa base es 12 dólares y el límite incluido es 80. Si el plan es 2, la
tarifa base es 20 dólares y el límite incluido es 150.
Si el consumo supera el límite del plan, se cobra un recargo por excedente: por cada
unidad excedida se suma 0.25 al valor base. Si el consumo no supera el límite, se
paga solo la tarifa base.
Si el plan no es 1 ni 2, o si el consumo es negativo, el algoritmo debe mostrar “DATOS
INVÁLIDOS”. En caso contrario, debe mostrar el total a pagar.

E: Tipo de plan y consumo
P: Validar plan y que el consumo no sea negativo. Determinar tarifa base y limite, verificar consumo,
   excedente, sumar recargos  
S: Total a pagar o el mensaje "DATOS INVALIDOS"
*/

#include <iostream>
using namespace std;

int main() {    
    int plan;    
    double consumo, tarifaBase, limite, excedente, totalPagar;
    
    cout << "Seleccione el plan de internet 1 o 2:" << endl;
    cin >> plan;    
    cout << "Ingrese el consumo:" << endl;    
    cin >> consumo;
    
    if ((plan != 1 && plan != 2) || (consumo < 0)) {        
        cout << "DATOS INVALIDOS" << endl;
    } else { 

        if (plan == 1) {
            tarifaBase = 12.00;
            limite = 80.00;
        } else {
            tarifaBase = 20.00;
            limite = 150.00;
        }        
        if (consumo > limite) {
            excedente = consumo - limite;
        } else {
            excedente = 0;
        }        
        totalPagar = tarifaBase + (excedente * 0.25);       
        
        cout << "El total a pagar es: " << totalPagar << endl;
    } 
    return 0;
}