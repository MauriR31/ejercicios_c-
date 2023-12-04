#include "pila.h"

ElementoPila::ElementoPila()
{
    this->valor=0;
    this->siguiente=nullptr;
}

ElementoPila::ElementoPila(int valor)
{
    this->valor = valor;
    this->siguiente=nullptr;
}

void Pila::Push(int valor)
{
    ElementoPila* nuevoElemento = new ElementoPila(valor);
    if(pPrimer==nullptr)
    {
        pPrimer=nuevoElemento;
    }
    else
    {
        nuevoElemento->siguiente = pPrimer;
        pPrimer = nuevoElemento;
    }
    longitud++;
}

void Pila::Peek()
{
    ElementoPila* pPivot = pPrimer;
    cout << "peek:" << pPivot->valor << endl;
}
void Pila::Pop()
{    
    ElementoPila* pTemp = pPrimer;
    pPrimer = pPrimer->siguiente;
    delete pTemp;
    longitud--;
}

void Pila::Mostrar()
{
    if(pPrimer !=nullptr)
    {
        ElementoPila* pPivot = pPrimer;
        while(pPivot!=nullptr)
        {
            cout << "[" <<pPivot->valor <<"]"<< endl;
            pPivot = pPivot->siguiente;
        }
        
    }    
    else
    {
        cout << "Pila vacia" << endl;
    }
    
}
