# 🛒 Sistema de Gestión de Productos — C++

Este proyecto forma parte de la experiencia educativa **Metodología de la Programación** y tiene como objetivo aplicar los conceptos fundamentales de la programación estructurada mediante el desarrollo de un sistema para la gestión de inventario.

El sistema permite **registrar, mostrar, ordenar, buscar, actualizar y generar reportes** de productos utilizando estructuras, arreglos y funciones en C++.

---

## 📌 Funcionalidades principales

### ✔ Registrar productos  
Permite agregar productos indicando nombre, precio y cantidad, con validación de datos.

### ✔ Mostrar productos  
Imprime la lista completa de productos almacenados en el inventario.

### ✔ Ordenar productos  
Tres métodos de ordenamiento implementados:
- **Burbuja** → ordena por precio  
- **Selección** → ordena por nombre  
- **Inserción** → ordena por cantidad  

### ✔ Buscar producto  
Búsqueda exacta por nombre, mostrando los datos del producto encontrado.

### ✔ Actualizar producto  
Permite modificar el precio o la cantidad de un producto existente.

### ✔ Reporte final  
Calcula:
- Total de productos registrados  
- Valor total del inventario  
- Producto con mayor cantidad  

---

## 🧱 Estructura del proyecto

El sistema utiliza un `struct` para representar a cada producto:

```cpp
struct Producto {
    string nombre;
    float precio;
    int cantidad;
};
