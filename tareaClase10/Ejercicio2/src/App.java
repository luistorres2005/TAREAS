/*
Ejercicio 2 — Clase telefono
Estudiante: Torres Cabezas Yober Luis
Fecha: 04/08/2026

Enunciado:
Crea una clase llamada Telefono que represente un teléfono.
La clase debe tener los siguientes atributos privados:
marca, modelo, precio.
*/

public class App {
    public static void main(String[] args) throws Exception {
        //objeto telefono.
        Telefono miTelefono = new Telefono("Samsumg", "A15", 250.0);

        System.out.println("===Informacion del Telefono===");
        System.out.println("Marca: " + miTelefono.getMarca());
        System.out.println("Modelo: " + miTelefono.getModelo());
        System.out.println("Precio: $" + miTelefono.getPrecio());

        System.out.println();
        
        //modificar datos del telefono
        miTelefono.setMarca("Apple");
        System.out.println("Marca modificada: " + miTelefono.getMarca());       
        System.out.println();

        miTelefono.setModelo("Iphone 14");
        System.out.println("Modelo modificado: " + miTelefono.getModelo());
        System.out.println();

        miTelefono.setPrecio(1000.0);
        System.out.println("Precio modificado: $" + miTelefono.getPrecio());
        System.out.println();

        System.out.println("--- Prueba de validacion ---");
        miTelefono.setPrecio(-50.0);
        System.out.println();

        System.out.println("=== Datos Finales ===");
        miTelefono.mostrarInfo();
    }
}
