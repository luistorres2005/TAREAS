public class Telefono {
    private String marca;
    private String modelo;
    private double precio;  

    //Constructor
    public Telefono(String marca, String modelo, double precio) {
        this.marca = marca;
        this.modelo = modelo;

        //validacion 
        if(precio >= 0){
            this.precio = precio;            
        }else{
            this.precio = 0;
        }        
    }


    //Getters
    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }

    public double getPrecio() {
        return precio;
    }

    //Setters
    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public void setPrecio(double precio){
        if (precio >=0){
            this.precio = precio;
        }else{
            System.out.println("El precio no puede ser negativo.");
        }
    }

    //metodo para mostrar informacion
    public void mostrarInfo() {
        System.out.println("Marca: " + marca);
        System.out.println("Modelo: " + modelo);
        System.out.println("Precio: $" + precio);
    }

}
