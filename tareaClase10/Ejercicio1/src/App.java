/*
Ejercicio 1 — Clase Mascota
Estudiante: Torres Cabezas Yober Luis
Enunciado
Crea una clase llamada Mascota que represente una mascota sencilla.
*/

public class App {
    public static void main(String[] args) throws Exception {

        Mascota Mascota1 = new Mascota("Firulais", "Perro", 3);
        Mascota Mascota2 = new Mascota("Michi", "Gato", 2);

        System.out.println("===Mascota 1===");
        Mascota1.mostrarInformacion();
        System.out.println("La mascota 1 se llama " + Mascota1.nombre + " es un " + Mascota1.especie + " y tiene " + Mascota1.edad + " anios");
        
        System.out.println();

        System.out.println("===Mascota 2===");
        Mascota2.mostrarInformacion();  
        System.out.println("La mascota 2 se llama " + Mascota2.nombre + " es un " + Mascota2.especie + " y tiene " + Mascota2.edad + " anios");
    }
}
