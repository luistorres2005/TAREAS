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

const int MAX_SOCIOS = 20;

// === PROTOTIPOS ===
void registrarSocio(string nombres[], int edades[], double pesos[], int &cantidad);
void mostrarSocios(const string nombres[], const int edades[], const double pesos[], int cantidad);
void buscarSocio(const string nombres[], const int edades[], const double pesos[], int cantidad);
void mostrarReporte(const string nombres[], const int edades[], const double pesos[], int cantidad);

int main() {
    string nombres[MAX_SOCIOS];
    int edades[MAX_SOCIOS];
    double pesos[MAX_SOCIOS];
    int cantidad_registros = 0;
    int opcion;

    // MENÚ REPETITIVO
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

        // VALIDACIÓN DE ENTRADA INCOHERENTE
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = -1;
        }

        // SELECTOR DE ACCIÓN
        switch (opcion) {
            case 1:
                registrarSocio(nombres, edades, pesos, cantidad_registros);
                break;
            case 2:
                mostrarSocios(nombres, edades, pesos, cantidad_registros);
                break;
            case 3:
                buscarSocio(nombres, edades, pesos, cantidad_registros);
                break;
            case 4:
                mostrarReporte(nombres, edades, pesos, cantidad_registros);
                break;
            case 5:
                cout << "\n[Proximamente] Aqui se ejecutara el Asistente de Hidratacion..." << endl;
                break;
            case 6:
                cout << "\nGracias por usar GymFit Admin. Que tengas un excelente entrenamiento :)" << endl;
                break;
            default:
                cout << "\nERROR. Opcion no valida, intente nuevamente con un numero del 1 al 6." << endl;
                break;
        }

    } while (opcion != 6);

    return 0;
}

// === REGISTRAR NUEVO SOCIO ===
void registrarSocio(string nombres[], int edades[], double pesos[], int &cantidad) {
    if (cantidad >= MAX_SOCIOS) {
        cout << "\nERROR. El gimnasio esta lleno, no se pueden registrar mas de " << MAX_SOCIOS << " socios." << endl;
        return; 
    }

    cout << "\n--- REGISTRAR NUEVO SOCIO ---" << endl;
    cout << "Ingrese el nombre completo del socio: ";
    cin.ignore(); 
    getline(cin, nombres[cantidad]);

    int edad_ingresada;
    do {
        cout << "Ingrese la edad (debe ser mayor o igual a 0): ";
        cin >> edad_ingresada;
        if (cin.fail() || edad_ingresada < 0) {
            cout << "ERROR. Edad invalida, intente de nuevo." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            break; 
        }
    } while (true);
    edades[cantidad] = edad_ingresada;

    double peso_ingresado;
    do {
        cout << "Ingrese el peso en kg: ";
        cin >> peso_ingresado;
        if (cin.fail() || peso_ingresado <= 0.0) {
            cout << "ERROR. Peso invalido, intente de nuevo." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            break; 
        }
    } while (true);
    pesos[cantidad] = peso_ingresado;

    cantidad++; 
    cout << "\nLISTO. Socio registrado con exito, socios actuales: " << cantidad << endl;
}

// === LISTADO DE SOCIOS ===
void mostrarSocios(const string nombres[], const int edades[], const double pesos[], int cantidad) {
    if (cantidad == 0) {
        cout << "\nERROR. No hay socios registrados todavia." << endl;
        return;
    }

    cout << "\n=================================================================" << endl;
    cout << "                     SOCIOS REGISTRADOS                          " << endl;
    cout << "=================================================================" << endl;
    cout << "ID\tEdad\tPeso (kg)\tNombre Completo" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << "\t" 
             << edades[i] << "\t" 
             << pesos[i] << "\t\t" 
             << nombres[i] << endl;
    }
    cout << "=================================================================" << endl;
    cout << "Capacidad actual: " << cantidad << " de " << MAX_SOCIOS << " cupos ocupados." << endl;
}

// === BÚSQUEDA SECUENCIAL ===
void buscarSocio(const string nombres[], const int edades[], const double pesos[], int cantidad) {
    if (cantidad == 0) {
        cout << "\nERROR. No hay socios registrados para realizar la busqueda." << endl;
        return;
    }

    cout << "\n--- BUSCAR SOCIO POR NOMBRE ---" << endl;
    cout << "Ingrese el nombre del socio que desea buscar: ";
    string nombre_buscado;
    cin.ignore();
    getline(cin, nombre_buscado);

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (nombres[i] == nombre_buscado) {
            cout << "\nLISTO. Socio encontrado!" << endl;
            cout << "ID en lista: " << (i + 1) << endl;
            cout << "Nombre completo: " << nombres[i] << endl;
            cout << "Edad: " << edades[i] << " anos" << endl;
            cout << "Peso actual: " << pesos[i] << " kg" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nERROR. El socio \"" << nombre_buscado << "\" no se encuentra registrado." << endl;
    }
}

// === REPORTE ESTADÍSTICO ===
void mostrarReporte(const string nombres[], const int edades[], const double pesos[], int cantidad) {
    if (cantidad == 0) {
        cout << "\nERROR. No hay datos suficientes para generar el reporte." << endl;
        return;
    }

    double suma_edades = 0;
    for (int i = 0; i < cantidad; i++) {
        suma_edades += edades[i];
    }
    double promedio_edad = suma_edades / cantidad;

    double peso_minimo = pesos [0];
    int indice_minimo = 0;
    for (int i = 1; i < cantidad; i++) {
        if (pesos[i] < peso_minimo) {
            peso_minimo = pesos[i];
            indice_minimo = i;
        }
    }

    cout << "\n=====================================================" << endl;
    cout << "                 REPORTE ESTADISTICO                 " << endl;
    cout << "=====================================================" << endl;
    cout << "1. Promedio de edad del gimnasio: " << promedio_edad << " anos." << endl;
    cout << "2. Socio con menor peso registrado actualmente:" << endl;
    cout << "   - Nombre: " << nombres[indice_minimo] << endl;
    cout << "   - Peso: " << pesos[indice_minimo] << " kg" << endl;
    cout << "   - Edad: " << edades[indice_minimo] << " anos" << endl;
    cout << "=====================================================" << endl;
}