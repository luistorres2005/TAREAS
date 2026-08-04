# Sistema GymFit Admin

Este proyecto es una aplicación de consola desarrollada en C++ diseñada para facilitar la administración básica de un gimnasio pequeño o centro deportivo. El sistema permite gestionar la información de los socios de forma segura, garantizando el control de cupos y la validación de los datos ingresados.

## Datos que administra

El sistema almacena y gestiona tres datos esenciales de cada socio mediante el uso de arreglos paralelos:
*   **Nombre completo:** Texto que identifica al socio (admite espacios para nombres y apellidos).
*   **Edad:** Número entero mayor o igual a cero.
*   **Peso:** Número decimal (en kilogramos) mayor que cero.

## Funcionalidades del menú

La aplicación cuenta con una interfaz de menú interactivo y repetitivo con las siguientes opciones:
1.  **Registrar un nuevo socio:** Permite ingresar los datos de un socio validando que no se superen los 20 cupos disponibles y que los valores de edad y peso sean coherentes.
2.  **Mostrar todos los socios:** Presenta de forma ordenada una tabla con el listado de todos los socios registrados actualmente, indicando el número de cupos ocupados.
3.  **Buscar un socio por nombre:** Realiza un recorrido por la lista para localizar a un socio específico por su nombre exacto y mostrar su ficha de datos personales.
4.  **Mostrar reporte general:** Calcula y muestra de manera automática la edad promedio de los socios activos y localiza al socio con el menor peso registrado.
5.  **Componente creativo - Ficha de salud:** Genera un análisis de bienestar físico personalizado para un socio seleccionado.
6.  **Salir del programa:** Cierra la aplicación con un saludo de despedida.

## Funcionalidad creativa: Ficha de salud y bienestar

Para aportar un valor agregado al sistema, se diseñó el **Asistente de Ficha de Salud**, que realiza dos operaciones automáticas al consultar a un socio:
1.  **Cálculo de hidratación personalizada:** Utiliza el peso del socio para calcular cuántos litros de agua necesita consumir al día mediante la fórmula biológica estándar (35 ml de agua por cada kg de peso corporal: `peso * 0.035`).
2.  **Sugerencia de rutina por rango de edad:** Analiza la edad del socio mediante lógica condicional para asignarle una categoría de entrenamiento segura:
    *   *Menores de 18 años:* Ejercicios coordinativos y de acondicionamiento general.
    *   *Entre 18 y 50 años:* Rutinas de fuerza, hipertrofia o resistencia física de alta intensidad.
    *   *Mayores de 50 años:* Ejercicios funcionales, movilidad articular y cardio de bajo impacto.

## Instrucciones de compilación y ejecución

Para compilar y correr el programa en cualquier computadora con un compilador de C++ (`g++`), sigue estos sencillos pasos desde la terminal de tu sistema:

1.  **Compilar el código fuente:**
    ```bash
    g++ main.cpp -o gymfit
    ```
2.  **Ejecutar el programa resultante:**
    *   En Windows:
        ```cmd
        gymfit.exe
        ```
    *   En Linux / macOS:
        ```bash
        ./gymfit
        ```

## Autor

*   **Estudiante:** Torres Cabezas Yober Luis
*   **Curso:** Programación Cero a POO
