#include "funcion.h"
Objetofuncion::Objetofuncion()
{
    this->nombre = "";
}
Objetofuncion::Objetofuncion(string nombre)
{
    this->nombre = nombre;
}
// El objeto parametro que puede recibir valores o un objeto tipo funcion
Parametro::Parametro()
{    
    this->valor=0;
    this->objetofuncion = nullptr;
    this->siguiente =nullptr;
}

Parametro::Parametro(int valor)
{
    this->valor = valor;   
    this->objetofuncion = nullptr;
    this->siguiente =nullptr;
}

Parametro::Parametro(Objetofuncion *objetofuncion)
{
    this->objetofuncion = objetofuncion;
    this->valor = 0;
    this->siguiente = nullptr;
}

//La clase lista Parametros , que posteriormente
//se va a pasar a la clase funcion como atributo
ListaParametros::ListaParametros()
{
    this->longitud = 0;
    this->pPrimer = nullptr;
}

void ListaParametros::AgregarParametro(Parametro *parametro)
{
    if(pPrimer == nullptr)
    {
        pPrimer = parametro;
    }
    else
    {
        Parametro* pPivot = pPrimer;
        while (pPivot->siguiente!=nullptr)
        {
            pPivot = pPivot->siguiente;
        }
        pPivot->siguiente = parametro;           
    }
    longitud++;
}

void ListaParametros::Mostrar()
{
    Parametro* pPivot = pPrimer;
    while(pPivot!=nullptr)
    {
        if(pPivot->valor!=0)
        {
            cout << pPivot->valor << "->";
        }
        if(pPivot->objetofuncion != nullptr)
        {
            cout << pPivot->objetofuncion->nombre << "\"";
        }
        pPivot = pPivot->siguiente;
    }
    cout << endl;
}

Funcion::Funcion(ListaParametros* lista)
{
    this->nombre = "";
    this->lista = lista;
}

string Funcion::FormarLlamadaPython()
{
    Parametro* pPivot = lista->pPrimer;
    string cad = "";
    int cont = 1;
    while(pPivot!=nullptr)
    {   
        if(pPivot->valor != 0)
        {
            cad = cad +  "texto" + to_string(cont) + " = \"" + to_string(pPivot->valor) + "\"\n";               
            
        }    
        if (pPivot->objetofuncion !=nullptr)
        {
            cad = cad + pPivot->objetofuncion->nombre + "()\n"; 
        }
        pPivot = pPivot->siguiente;
        
        cont++;
    }
    return cad;
}

string Funcion::FormarLlamadaRacket()
{
    Parametro* pPivot = lista->pPrimer;
    string cad = "";
    int cont = 1;
    while(pPivot!=nullptr)
    {   
        if(pPivot->valor != 0)
        {
            cad = cad +  "(string " + "'"+ to_string(pPivot->valor) + "')" + "\n";               
            
        }    
        if (pPivot->objetofuncion !=nullptr)
        {
            cad = cad + "(define " + pPivot->objetofuncion->nombre + ")\n"; 
        }
        pPivot = pPivot->siguiente;
        
        cont++;
    }
    return cad;
}
