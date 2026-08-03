/*
Nombre del estudiante: TORRES CABEZAS YOBER LUIS
Fecha: 03/08/2026
Tema: GymFit Admin
*/

/*
GymFit Admin es un programa diseñado para administrar de forma 
sencilla y eficiente los datos de un gimnasio. 
Su propósito principal es permitir el registro de 
los socios, buscar su información, realizar cálculos de control 
general y ofrecer recomendaciones personalizadas de salud.
*/

/*
E/P/S

Entrada:
    1.Las decisiones en el menú: El número de la opción que queremos elegir.
    2. Los datos para registrar un socio:
        Su Nombre completo.
        Su Edad en años.
        Su Peso en kilogramos.
    3. El nombre de la persona que queremos consultar.    

Proceso:
    1. Revisa que no ingrese datos invalidos.
    2. controla que no supere su límite de 20 inscritos.
    3. Almacena la información de cada persona para que no se mezcle.    
    4. Revisa la lista de socios para ver si el nombre que escribiste está registrado.
    5. Suma las edades de todos y calcula la edad promedio del gimnasio.
    6. Compara los pesos de todos los socios para descubrir quién es el más liviano.
    7. Toma el peso del socio y calcula cuánta agua debe tomar al día para estar saludable.
    8. Toma su edad y le sugiere el tipo de ejercicio ideal para su etapa de vida.

Salida: 
    1. Un menú de opciones.
    2. Lista de todos los socios que se han registrado hasta el momento.
    3. Un mensaje "Socio encontrado en la posición tal..." o un aviso si  no está registrado. 
    4. Cuál es el promedio de edad y quién es el socio de menor peso.    
    5. Mensaje de cuántos litros de agua necesita al día y qué rutina le conviene hacer.

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    // Almacenamos la información en el mismo índice para cada socio
    string nombres[MAX_SOCIOS];
    int edades[MAX_SOCIOS];
    double pesos[MAX_SOCIOS];

    // Variable para controlar los socios registrados actualmente
    int cantidad_registros = 0;

    // Variable para capturar la opción del menú
    int opcion;

    //MENÚ REPETITIVO
    do {
        cout << "\n=====================================" << endl;
        cout << "       SISTEMA GYMFIT ADMIN          " << endl;
        cout << "=====================================" << endl;
        cout << "1. Registrar un nuevo socio" << endl;
        cout << "2. Mostrar todos los socios" << endl;
        cout << "3. Buscar un socio por nombre" << endl;
        cout << "4. Mostrar reporte general" << endl;
        cout << "5. Componente creativo - Ficha de salud" << endl;
        cout << "6. Salir del programa" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Seleccione una opcion (1-6): ";
        cin >> opcion;

        //  VALIDACIÓN DE ENTRADA INCOHERENTE         
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(10000, '\n'); // Ignora los caracteres incorrectos ingresados
            opcion = -1; // Forzamos una opción inválida para activar el caso 'default'
        }

        //SELECTOR DE ACCIÓN
        switch (opcion) {
            case 1:
                cout << "\n[Proximamente] Aqui se registrara un nuevo socio..." << endl;
                break;
            case 2:
                cout << "\n[Proximamente] Aqui se listaran todos los socios registrados..." << endl;
                break;
            case 3:
                cout << "\n[Proximamente] Aqui buscaremos a un socio por su nombre..." << endl;
                break;
            case 4:
                cout << "\n[Proximamente] Aqui calcularemos el promedio de edad y el socio mas liviano..." << endl;
                break;
            case 5:
                cout << "\n[Proximamente] Aqui se ejecutara el Asistente de Hidratacion y Entrenamiento..." << endl;
                break;
            case 6:
                cout << "\nGracias por usar GymFit Admin. ¡Que tengas un excelente entrenamiento!" << endl;
                break;
            default:
                cout << "\n[ERROR] Opcion no valida. Intente nuevamente con un numero del 1 al 6." << endl;
                break;
        }

    } while (opcion != 6); // Se repite hasta que el usuario elija la opción Salir 

    return 0;
}