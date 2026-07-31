/*
Nombre del estudiante: [TORRES CABEZAS YOBER LUIS]
Fecha: 30/07/2026
Tema: Sistema de registro y análisis de notas
Entrada: cantidad, nombres, notas, opción del menú y nombre a buscar
Proceso: validar, almacenar, recorrer, calcular y buscar
Salida: reporte general y resultado de búsqueda
*/

#include <iostream>
#include <string>

using namespace std;

// Declaración de prototipos de funciones
void mostrarMenu();
void registrarEstudiantes(string nombres[], double notas[], int &cantidad);
void mostrarReporte(const string nombres[], const double notas[], int cantidad);
void buscarEstudiante(const string nombres[], const double notas[], int cantidad);

int main() {
    // Declaración de arreglos y variables principales (Máximo 20 estudiantes)
    const int MAX_ESTUDIANTES = 20;
    string nombres[MAX_ESTUDIANTES];
    double notas[MAX_ESTUDIANTES];
    int cantidad = 0; // Registra la cantidad actual de estudiantes (0 indica que no hay datos)
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        // Validación de la opción ingresada (entre 1 y 4)
        if (opcion < 1 || opcion > 4) {
            cout << "\nError: Opcion invalida. Por favor, seleccione una opcion entre 1 y 4.\n" << endl;
            continue; // Regresa al inicio del bucle para volver a mostrar el menú
        }

        // Control obligatorio: No permitir reportes ni búsquedas si no hay estudiantes registrados
        if ((opcion == 2 || opcion == 3) && cantidad == 0) {
            cout << "\nAlerta: Todavia no existen datos registrados. Primero registre los estudiantes (Opcion 1).\n" << endl;
            continue;
        }

        // Estructura de control switch para coordinar las opciones del menú
        switch (opcion) {
            case 1:
                registrarEstudiantes(nombres, notas, cantidad);
                break;
            case 2:
                mostrarReporte(nombres, notas, cantidad);
                break;
            case 3:
                buscarEstudiante(nombres, notas, cantidad);
                break;
            case 4:
                cout << "\nSaliste del programa.\n" << endl;
                break;
        }

    } while (opcion != 4);

    return 0;
}

// Función para mostrar el menú estructurado obligatorio
void mostrarMenu() {
    cout << "=========== MENU ===========" << endl;
    cout << "1. Registrar estudiantes y notas" << endl;
    cout << "2. Mostrar reporte general" << endl;
    cout << "3. Buscar estudiante por nombre" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// Función 1: Registrar estudiantes y notas (Paso por referencia para actualizar 'cantidad')
void registrarEstudiantes(string nombres[], double notas[], int &cantidad) {
    int tempCantidad;
    
    cout << "\n--- REGISTRO DE ESTUDIANTES ---" << endl;
    
    // 1. Pedir la cantidad de estudiantes y validarla entre 1 y 20
    do {
        cout << "Ingrese la cantidad de estudiantes a registrar (1-20): ";
        cin >> tempCantidad;
        if (tempCantidad < 1 || tempCantidad > 20) {
            cout << "Error: La cantidad de estudiantes debe estar estrictamente entre 1 y 20." << endl;
        }
    } while (tempCantidad < 1 || tempCantidad > 20);

    cantidad = tempCantidad; // Actualizamos la cantidad oficial de registros

    // 2. Solicitar el nombre y la nota de cada estudiante
    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante " << (i + 1) << ":" << endl;
        cout << "  Primer nombre (sin espacios): ";
        cin >> nombres[i];

        // 3. Validar cada nota entre 0 y 20; si es inválida, volver a pedirla
        double notaTemp;
        do {
            cout << "  Nota final (0.00 a 20.00): ";
            cin >> notaTemp;
            if (notaTemp < 0.0 || notaTemp > 20.0) {
                cout << "  Error: Nota invalida. Debe ingresar una nota en la escala de 0 a 20." << endl;
            }
        } while (notaTemp < 0.0 || notaTemp > 20.0);

        notas[i] = notaTemp; // Guardamos la nota validada en el arreglo relacionado
    }
    
    cout << "\n Estudiantes registrados exitosamente\n" << endl;
}

// Función 2: Mostrar reporte general analítico
void mostrarReporte(const string nombres[], const double notas[], int cantidad) {
    cout << "\n=============================================" << endl;
    cout << "             REPORTE GENERAL" << endl;
    cout << "=============================================" << endl;
    
    double sumaNotas = 0;
    int aprobados = 0;
    int reprobados = 0;

    // Inicializamos el control de mayor y menor con el primer estudiante del arreglo
    double notaMayor = notas[0];
    string nombreMayor = nombres[0];
    
    double notaMenor = notas[0];
    string nombreMenor = nombres[0];

    // 1. Listado numerado con nombre, nota y estado
    cout << "Nro.   Nombre          Nota      Estado" << endl;
    cout << "---------------------------------------------" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        string estado;
        if (notas[i] >= 14.0) {
            estado = "APROBADO";
            aprobados++; // Contador de aprobados
        } else {
            estado = "REPROBADO";
            reprobados++; // Contador de reprobados
        }

        // Impresión en formato de fila
        cout << (i + 1) << ".\t" << nombres[i];
        if (nombres[i].length() < 8) {
            cout << "\t\t"; // Tabulación extra para mantener la alineación de columnas
        } else {
            cout << "\t";
        }
        cout << notas[i] << "\t" << estado << endl;

        // Acumulación para el promedio general
        sumaNotas += notas[i];

        // Identificación de la nota mayor (Primera coincidencia: estricto '>')
        if (notas[i] > notaMayor) {
            notaMayor = notas[i];
            nombreMayor = nombres[i];
        }

        // Identificación de la nota menor (Primera coincidencia: estricto '<')
        if (notas[i] < notaMenor) {
            notaMenor = notas[i];
            nombreMenor = nombres[i];
        }
    }

    // 2. Cálculos finales
    double promedioGeneral = sumaNotas / cantidad;

    // Impresión de estadísticas descriptivas
    cout << "---------------------------------------------" << endl;
    cout << "Promedio General:   " << promedioGeneral << endl;
    cout << "Nota Mayor:         " << notaMayor << " (" << nombreMayor << ")" << endl;
    cout << "Nota Menor:         " << notaMenor << " (" << nombreMenor << ")" << endl;
    cout << "Aprobados:   " << aprobados << " estudiante(s)" << endl;
    cout << "Reprobados:   " << reprobados << " estudiante(s)" << endl;
    cout << "=============================================\n" << endl;
}

// Función 3: Buscar estudiante por nombre (Búsqueda Secuencial)
void buscarEstudiante(const string nombres[], const double notas[], int cantidad) {
    string nombreBuscar;
    cout << "\n--- BUSCAR ESTUDIANTE ---" << endl;
    cout << "Ingrese el nombre exacto del estudiante a buscar: ";
    cin >> nombreBuscar;

    bool encontrado = false;
    int indiceEncontrado = -1;

    // Recorrido secuencial para encontrar la primera coincidencia exacta (Case-sensitive)
    for (int i = 0; i < cantidad; i++) {
        if (nombres[i] == nombreBuscar) {
            encontrado = true;
            indiceEncontrado = i;
            break; // Salimos del bucle en la primera coincidencia encontrada
        }
    }

    // Mostrar resultados según la búsqueda
    if (encontrado) {
        string estado = (notas[indiceEncontrado] >= 14.0) ? "APROBADO" : "REPROBADO";
        cout << "\nEstudiante encontrado" << endl;
        cout << "  Nombre: " << nombres[indiceEncontrado] << endl;
        cout << "  Nota Final: " << notas[indiceEncontrado] << endl;
        cout << "  Estado: " << estado << "\n" << endl;
    } else {
        cout << "\nResultado: El estudiante \"" << nombreBuscar << "\" no se encuentra registrado en el sistema.\n" << endl;
    }
}