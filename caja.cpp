#include "caja.h"

//Metodos de la clase producto

Producto::Producto()
{
    this->peso=0.0f;
    this->volumen=0.0f;
    this->siguiente = nullptr;
}

Producto::Producto(float volumen, float peso)
{
    this->peso=peso;
    this->volumen=volumen;
    this->siguiente = nullptr;
}

//Metodos de la clase caja

Caja::Caja()
{
    this->capacidad=0;
    this->volumenCaja = 0;    
    this->longitud=0;
    this->pPrimer = nullptr;
}

Caja::Caja(float capacidad, float volumen)
{
    this->capacidad=capacidad;
    this->volumenCaja = volumen;    
    this->longitud=0;
    this->pPrimer = nullptr;
}


void Caja::AgregarObjeto(Producto *producto)
{
    if(capacidad > 0)
    {    
        if(pPrimer == nullptr)
        {
            pPrimer = producto;         
        }
        else
        {
            Producto* pPivot = pPrimer;
            while(pPivot->siguiente!=nullptr)
            {
                pPivot = pPivot->siguiente;
            }        
            pPivot->siguiente = producto;
        }
        capacidad = capacidad - producto->volumen;
        longitud++;
        cout << "Producto agregado" << endl;
    }
    else
    {
        cout << "Sin espacio" << endl;
    }
}

float Caja::CalcularPeso()
{
    float pesoCaja = 0.0f; 
    Producto* pPivot = pPrimer;
    while(pPivot!=nullptr)
    {
        pesoCaja = pesoCaja + pPivot->peso;
        pPivot = pPivot->siguiente;
    }
    return pesoCaja;
}

void Caja::Contenido()
{
    Producto* pPivot = pPrimer;
    cout << "Lista de productos de la caja:" << endl;
    while(pPivot!=nullptr)
    {
        cout << "[ "<<pPivot->volumen << " - "<< pPivot->peso << " ] ->"; 
        pPivot = pPivot->siguiente;
    }
    cout << endl;
}

void Caja::MostrarCaja()
{    
    cout << "Caja:" << endl;
    cout << "----------------------------"<<endl;
    cout << "volumen:"<< this->volumenCaja << endl;
    cout << "capacidad restante:" << this->capacidad << endl;
    Contenido();
    cout << "peso de la caja:" << CalcularPeso() << endl;
}
