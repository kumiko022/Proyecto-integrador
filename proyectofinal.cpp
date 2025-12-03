#include <iostream>
#include <string>
using namespace std;


//se crea el struct o el molde para los productos
struct Producto{
    string nombre;
    float precio;
    int cantidad;
};

//se declaran las funciones para que al ejecutar el codigo no se le meta el chamuco al compilador
void registrarProductos();
void mostrarProductos();
void ordenarProductos();
void metodoBurbuja();
void metodoSeleccion();
void metodoInsercion();
void buscarProducto();
void actualizarProducto();
void generarReporteFinal();

//se crea el arreglo para máximo 100 productos
Producto productos[100];
int totalProductos = 0;


// 1. registrar productos
void registrarProductos() {
    int n;
    cout << "¿Cuántos productos desea registrar?" << endl;
    cin >> n;


    if (totalProductos + n > 100){
        cout << "La capacidad máxima de productos es 100" << endl;
        return;
    }


    for (int i = 0; i < n; i++){    //se inicia un bucle para que cada producto quede registrado con nombre, precio y cantidad
        cout << "Producto " << (totalProductos + 1) << " : " << endl;    
        cout << "Nombre del producto: " << endl;                //registrar el nombre de los productos
        cin >> productos[totalProductos].nombre;


    do {    //registrar el precio de los productos
        cout << "Precio del producto: " << endl;
        cin >> productos[totalProductos].precio;
        if (productos[totalProductos].precio <= 0){
            cout << "El precio tiene que ser mayor a 0" << endl;
        }
    } while (productos[totalProductos].precio <= 0);


    do {       //registrar la cantidad (inventario)
        cout << "Cantidad de productos: " << endl;
        cin >> productos[totalProductos].cantidad;
        if (productos[totalProductos].cantidad < 0){
            cout << "Debe de registrar al menos uno o más" << endl;
        }
    } while (productos[totalProductos].cantidad < 0);


       totalProductos ++;
}
 
cout << "Productos registradoas exitosamente!" << endl;


}


//2. mostrar productos con nombre, precio y cantidad ingresados


void mostrarProductos() {
    if (totalProductos == 0 ){
        cout << "No se registró ningún producto" << endl;
        return;      //por si el usuario no registro ningun producto
    }


    cout << "== Lista de productos registrados == " << endl;


    for( int i = 0; i < totalProductos; i++){
        cout << "Producto " << i + 1 << " :" << endl;
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Precio: " << productos[i].precio << endl;
        cout << "Cantidad: " << productos[i].cantidad << endl;
    }
}


//3. ordenar los productos por el método que el usuario elija
void ordenarProductos(){
    int opcion;
    cout << "== Seleccione el metodo para ordenar los productos ==" << endl;
    cout << "1. Por precio (burbuja)" << endl;
    cout << "2. Por nombre (selección)" << endl;
    cout << "3. Por cantidad (inserción)" << endl;
    cin >> opcion;


    switch(opcion){
        case 1:
        metodoBurbuja();
        break;
        case 2:
        metodoSeleccion();
        break;
        case 3:
        metodoInsercion();
        break;
        default:
        cout << "Opción inválida" << endl;
        break;
    }
}


//aqui se hace el metodo burbuja
void metodoBurbuja(){
    if(totalProductos <= 1){
        cout << "Para ordenar debe de haber más de un producto" << endl;
        return;
    }
    for(int i = 0; i < totalProductos - 1; i++){   //el primer bucle controla cuantas pasadas se dará en el arreglo, se necesitan totalProductos - 1 siempre
        for(int j = 0; j < totalProductos - 1 - i; j++){  //se usa para comparar, cada pasada se revisa uno menos
            if (productos[j].precio > productos[j + 1].precio){ //el condicional que si producto [j] es menor que [j + 1] se ejecutara lo siguiente
                Producto temp = productos[j];  //[j] se guarda en temp
                productos[j] = productos[j + 1]; // [j] se convierte en [j+1]
                productos[j + 1] = temp; // el numero que se guardo en temp se pasa a [j + 1]
            }
        }
    }
    cout << "Se ordenó los productos por precio (menor a mayor)" << endl;
}


// metodo por seleccion
void metodoSeleccion(){
    if (totalProductos <= 1) {
        cout << "No hay suficientes productos para ordenar" << endl;
        return;
    }
    for (int i = 0; i < totalProductos - 1; i++) {
        int minIndex = i;  //se supone que el nombre mas pequeño esta en la posicion [i]
         for (int j = i + 1; j < totalProductos; j++) {  //recorre todos los productos despues de [i] para encontrar al minimo
            if (productos[j].nombre < productos[minIndex].nombre) { //compara los strings alfabeticamente, si se encuentra un nombre menor se actualiza minIndex
                minIndex = j;
         }
    }
    if (minIndex != i) { //solo se intercambia si se encuentra un nombre menor, asi se coloca el producto en la posicion [i]
            Producto temp = productos[i];
            productos[i] = productos[minIndex];
            productos[minIndex] = temp;
        }
    }

    cout << "Los productos se ordenaron por nombre" << endl;

}

//metodo de insercion

void metodoInsercion(){
    if (totalProductos <= 1){
        cout << "No hay suficientes productos para ordenar" << endl;
        return;
    }
    for (int i = 1; i < totalProductos; i++){ // se inicia en 1
        Producto actual = productos[i]; //se guarda el producto actual
        int j = i - 1;
        
        while (j >= 0 && productos[j].cantidad > actual.cantidad){ //se recorre hacia atras mientras el productos[j] tenga mas cantidad que el actual: lo movemos a la derecha
            productos[j + 1] = productos[j];
            j--;
        }
        productos[j + 1] = actual; //insertamos al final
    }
    cout << "Los productos se ordenaron por cantidad (menor a mayor)" << endl;
}

//buscar producto
void buscarProducto(){
    if (totalProductos == 0) {
        cout << "No hay productos registrados." << endl;
        return;
    }

    string nombreBuscado;
    cout << "Ingrese el nombre del producto que desea buscar: " << endl;
    cin >> nombreBuscado;

    for(int i = 0; i < totalProductos; i++){
        if (productos[i].nombre == nombreBuscado){
            cout << "Producto encontrado!: " << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Precio: " << productos[i].precio << endl;
            cout << "Cantidad: " << productos[i].cantidad << endl;
            return;
        }
    }
    cout << "No existe el producto" << endl;
}

//actualizar producto
void actualizarProducto(){
    if (totalProductos == 0) {
        cout << "No hay productos registrados." << endl;
        return;
    }

    int indice;
    cout << "Ingrese el número del producto a actualizar (" << totalProductos << ")" << endl;
    cin >> indice;

    indice = indice - 1;

    if(indice < 0 || indice >= totalProductos){
        cout << "Indice invalido" << endl;
        return;
    }

    cout << "¿Qué desea actualizar?" << endl;
    cout << "1. Precio" << endl;
    cout << "2. Cantidad" << endl;
    
    int eleccion;
    cin >> eleccion;

    switch (eleccion){
        case 1: {
            float nuevoPrecio;
            do {
                cout << "Ingresa el nuevo precio: " << endl;
                cin >> nuevoPrecio;
                if(nuevoPrecio <= 0){
                    cout << "El precio debe ser mayor a 0!" << endl;              
                }
            } while (nuevoPrecio <= 0);

            productos[indice].precio = nuevoPrecio;
            cout << "Precio actualizado!" << endl;
            break;
        }

        case 2: {
            int nuevaCantidad;
            do {
                cout << "Ingrese la nueva cantidad: " << endl;
                cin >> nuevaCantidad;
                if (nuevaCantidad < 0){
                    cout << "La nueva cantidad no puede ser negativa" << endl;
                } 
             } while (nuevaCantidad <= 0);
                productos[indice].cantidad = nuevaCantidad;
                cout << "Cantidad actualizada!" << endl;
                break;
    }
        default:
        cout << "Opción inválida!" << endl;
        break;
    }
}

//reporte final
void generarReporteFinal(){
     if (totalProductos == 0) {
        cout << "No hay productos registrados para generar el reporte." << endl;
        return;
    }

    float valorTotal = 0;
    int mayorCantidad = productos[0].cantidad;
    string productoMayor = productos[0].nombre;

    for (int i = 0; i < totalProductos; i++) {
        valorTotal += productos[i].precio * productos[i].cantidad;

        if (productos[i].cantidad > mayorCantidad){
            mayorCantidad = productos[i].cantidad;
            productoMayor = productos[i].nombre;
        }
    }

    //imprimir el reporte
    cout << "== Reporte final🥶 ==" << endl;
    cout <<  "Total de prodcutos registrados: " << totalProductos << endl;
    cout << "Valor total en el inventario: " << valorTotal << "$" << endl;
    cout << "Producto con mayor cantidad en el inventario: " << productoMayor << "(" << mayorCantidad << ")" << endl; 

}


int main() {
    int opcion;
    do{
        cout << "=== 🔥SISTEMA DE GESTIÓN DE PRODUCTOS🔥===" << endl;
        cout << "1. Registrar productos" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Ordenar productos" << endl;
        cout << "4. Buscar producto" << endl;
        cout << "5. Actualizar producto" << endl;
        cout << "6. Generar reporte final" << endl;
        cout << "7. Salir" << endl;
        cin >> opcion;


        //se usa un switch para mostrar las opciones¿
        switch(opcion){
            case 1:
            registrarProductos();
            break;
            case 2:
            mostrarProductos();
            break;
            case 3:
            ordenarProductos();
            break;
            case 4:
            buscarProducto();
            break;
            case 5:
            actualizarProducto();
            break;
            case 6:
            generarReporteFinal();
            break;
            case 7:
            cout << "Saliendo del sistema..." << endl;
            break;
            default:
            cout << "Opción inválida😓" << endl;
            break;
        }




    }while (opcion != 7);

    return 0;
}
