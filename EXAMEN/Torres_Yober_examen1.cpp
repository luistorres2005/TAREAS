#include <iostream>
#include <string>

using namespace std;

/*
Nombre del estudiante: [Torres Cabezas Yober Luis]
Fecha: 30/07/2026
Tema: Sistema de registro y análisis de notas
Entrada: cantidad, nombres, notas, opción del menú y nombre a buscar
Proceso: validar, almacenar, recorrer, calcular y buscar
Salida: reporte general y resultado de búsqueda
*/

// Prototipos de funciones
void mostrarMenu();
int registrarEstudiantes(string nombres[], float notas[]);
void mostrarReporte(string nombres[], float notas[], int cantidad);
void buscarEstudiante(string nombres[], float notas[], int cantidad);

int main() {
    // Arreglos y variables principales
    string nombres[20];
    float notas[20];
    int cantidadEstudiantes = 0;
    int opcion;

    do {
        mostrarMenu();
        
        // Validación de la opción del menú
        do {
            cout << "Seleccione una opcion (1-4): ";
            cin >> opcion;
            if (opcion < 1 || opcion > 4) {
                cout << "Error: Opcion invalida. Intente de nuevo.\n";
            }
        } while (opcion < 1 || opcion > 4);

        cout << "-----------------------------------\n";

        // Control de opciones
        if (opcion == 1) {
            cantidadEstudiantes = registrarEstudiantes(nombres, notas);
        } 
        else if (opcion == 2) {
            if (cantidadEstudiantes == 0) {
                cout << "Error: Todavia no existen datos registrados.\n";
            } else {
                mostrarReporte(nombres, notas, cantidadEstudiantes);
            }
        } 
        else if (opcion == 3) {
            if (cantidadEstudiantes == 0) {
                cout << "Error: Todavia no existen datos registrados.\n";
            } else {
                buscarEstudiante(nombres, notas, cantidadEstudiantes);
            }
        } 
        else if (opcion == 4) {
            cout << "Saliendo del programa. ¡Hasta luego!\n";
        }

        cout << "-----------------------------------\n";

    } while (opcion != 4);

    return 0;
}

// Función para imprimir el menú en pantalla
void mostrarMenu() {
    cout << "\n=========== MENU ===========\n";
    cout << "1. Registrar estudiantes y notas\n";
    cout << "2. Mostrar reporte general\n";
    cout << "3. Buscar estudiante por nombre\n";
    cout << "4. Salir\n";
}

// Función para registrar datos. Retorna la cantidad de estudiantes registrados.
int registrarEstudiantes(string nombres[], float notas[]) {
    int n;
    
    // Validar cantidad de estudiantes
    do {
        cout << "Ingrese la cantidad de estudiantes (1 a 20): ";
        cin >> n;
        if (n < 1 || n > 20) {
            cout << "Error: La cantidad debe estar entre 1 y 20.\n";
        }
    } while (n < 1 || n > 20);

    // Bucle para ingresar y validar los datos de cada estudiante
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante " << i + 1 << ":\n";
        cout << "Primer nombre (sin espacios): ";
        cin >> nombres[i];
        
        // Validar nota
        do {
            cout << "Nota final (0 a 20): ";
            cin >> notas[i];
            if (notas[i] < 0 || notas[i] > 20) {
                cout << "Error: La nota debe estar entre 0 y 20.\n";
            }
        } while (notas[i] < 0 || notas[i] > 20);
    }
    
    cout << "\n¡Datos registrados correctamente!\n";
    return n; // Retornamos la cantidad para actualizarla en el main
}

// Función para mostrar el reporte general
void mostrarReporte(string nombres[], float notas[], int cantidad) {
    float sumaNotas = 0;
    int aprobados = 0;
    int reprobados = 0;
    
    // Variables para mayor y menor (asumimos que el primero es el mayor y menor inicialmente)
    float notaMayor = notas[0];
    float notaMenor = notas[0];
    string nombreMayor = nombres[0];
    string nombreMenor = nombres[0];

    cout << "\n--- REPORTE GENERAL ---\n";
    
    // 1. Listado numerado
    for (int i = 0; i < cantidad; i++) {
        string estado = (notas[i] >= 14) ? "APROBADO" : "REPROBADO";
        cout << i + 1 << ". " << nombres[i] << " - Nota: " << notas[i] << " - Estado: " << estado << "\n";
        
        // Acumular para promedio
        sumaNotas += notas[i];
        
        // Contar estados
        if (notas[i] >= 14) {
            aprobados++;
        } else {
            reprobados++;
        }
        
        // Determinar mayor (solo actualiza si es estrictamente mayor, conservando el primero)
        if (notas[i] > notaMayor) {
            notaMayor = notas[i];
            nombreMayor = nombres[i];
        }
        
        // Determinar menor (solo actualiza si es estrictamente menor, conservando el primero)
        if (notas[i] < notaMenor) {
            notaMenor = notas[i];
            nombreMenor = nombres[i];
        }
    }

    // 2. Calcular e imprimir promedio
    float promedio = sumaNotas / cantidad;
    cout << "\nPromedio general de las notas: " << promedio << "\n";
    
    // 3. Estudiante con nota mayor y menor
    cout << "Estudiante con nota MAYOR: " << nombreMayor << " (" << notaMayor << ")\n";
    cout << "Estudiante con nota MENOR: " << nombreMenor << " (" << notaMenor << ")\n";
    
    // 4. Cantidad de aprobados y reprobados
    cout << "Cantidad de aprobados: " << aprobados << "\n";
    cout << "Cantidad de reprobados: " << reprobados << "\n";
}

// Función para buscar un estudiante por coincidencia exacta (Búsqueda secuencial)
void buscarEstudiante(string nombres[], float notas[], int cantidad) {
    string nombreBuscado;
    bool encontrado = false;
    
    cout << "Ingrese el nombre del estudiante a buscar: ";
    cin >> nombreBuscado;

    // Recorrer el arreglo (Búsqueda Secuencial)
    for (int i = 0; i < cantidad; i++) {
        if (nombres[i] == nombreBuscado) {
            string estado = (notas[i] >= 14) ? "APROBADO" : "REPROBADO";
            cout << "\n--- RESULTADO DE BUSQUEDA ---\n";
            cout << "Nombre: " << nombres[i] << "\n";
            cout << "Nota: " << notas[i] << "\n";
            cout << "Estado: " << estado << "\n";
            
            encontrado = true;
            break; // Detenemos la búsqueda en la primera coincidencia
        }
    }

    if (!encontrado) {
        cout << "\nEl estudiante '" << nombreBuscado << "' no se encuentra registrado.\n";
    }
}