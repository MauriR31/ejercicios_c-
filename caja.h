#include <iostream>
using namespace std;
class Producto
{
public:
    float volumen;
    float peso;
    Producto* siguiente;

    Producto();
    Producto(float volumen, float peso);
};
class Caja
{
public:
    float capacidad;
    float volumenCaja;    
    int longitud;
    Producto* pPrimer;


    Caja();
    Caja(float capacidad, float volumen);
    //metodo para verificar si el volumen del producto supera al de la caja   
    void AgregarObjeto(Producto* producto);
    float CalcularPeso();
    // EL contenido de la caja muestra la lista enlazada de productos 
    // (que es la cantidad de productos)
    void Contenido();  
    void MostrarCaja(); 
};