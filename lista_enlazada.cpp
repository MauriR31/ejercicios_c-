#include "lista_enlazada.h"
//Metodos para la clase elemento
Elemento::Elemento()
{
    this->valor=0;
    this->siguiente=nullptr;
}

Elemento::Elemento(int valor)
{
    this->valor=valor;
    this->siguiente=nullptr;
}

// Metodos para la clase ListaEnlazada
ListaEnlazada::ListaEnlazada()
{
    this->longitud=0;
    this->pPrimer=nullptr;
}

void ListaEnlazada::Mostrar()
{
    Elemento* pPivot = pPrimer;
    while (pPivot!=nullptr)
    {
        cout << pPivot->valor << "->";
        pPivot=pPivot->siguiente;
    }
    cout << endl;
    
}

void ListaEnlazada::AgregarElemento(int pos, int valor)
{
    Elemento* nuevoElemento = new Elemento(valor);
    if(pPrimer==nullptr && pos == 0)
    {
        pPrimer = nuevoElemento;
    }
    else if(pPrimer==nullptr && pos != 0)
    {
        cout << "No se puede crear elemento en la pos("<<pos<<"), estando la lista vacia" << endl;
    }
    else
    {
        Elemento* pPivot = pPrimer;
        Elemento* pPAnt = nullptr;
        
        if(pos==0)
        {
            nuevoElemento->siguiente = pPrimer;
            pPrimer = nuevoElemento;
        }
        else if(pos==longitud)
        {            
            while (pPivot->siguiente!=nullptr)
            {
                pPivot=pPivot->siguiente;
            }
            pPivot->siguiente=nuevoElemento;            
        }

        else
        { 
            int cont=0;           
            while(pPivot!=nullptr)
            {
                if(pos == cont)
                {
                    pPAnt->siguiente = nuevoElemento;
                    nuevoElemento->siguiente=pPivot;
                    break;
                }
                cont++;
                pPAnt=pPivot;
                pPivot= pPivot->siguiente;
            }
        }
    }
    longitud++;
}

void ListaEnlazada::EliminarElemento(int pos)
{
    if(pPrimer==nullptr)
    {
        cout << "No se puede eliminar, estando la lista vacia" <<endl;  
    } 
    else
    {
        if(pos == 0)
        {
            Elemento* pTemp = pPrimer;
            pPrimer=pPrimer->siguiente;
            delete pTemp;
        }
        else
        {
            Elemento* pPivot = pPrimer;
            Elemento* pPAnt = nullptr;
            int cont=0;
            while(pPivot!=nullptr)
            {
                if(pos==cont)
                {
                    pPAnt->siguiente=pPivot->siguiente;
                    delete pPivot;
                    break;
                }
                cont++;
                pPAnt=pPivot;
                pPivot= pPivot->siguiente;
            }
        }
        longitud--;
    }    
}

int ListaEnlazada::VerValor(int pos)
{
    if(pPrimer==nullptr) return -1;  

    Elemento* pPivot = pPrimer;
    if(pos==0)
    {
        pPivot->siguiente=nullptr;
        return pPivot->valor;
    }
    else
    {
        int cont=0;
        while(pPivot!=nullptr)
        {
            if(pos==cont)
            {
                pPivot->siguiente=nullptr;
                return pPivot->valor;
            }
            cont++;
            pPivot = pPivot->siguiente;
        }
    }   
    return 0; 
}

// OJO: en este metodo utilizo void porque me piden que muestre la cantidad de elementos de la lista
//man no int porque no me piden que retorne algo
void ListaEnlazada::CantElementos()
{
    int cant = 0;
    Elemento* pPivot = pPrimer;
    while(pPivot!=nullptr)
    {
        cant++;
        pPivot=pPivot->siguiente;
    }
    cout << "La cantidad de elementos es:" << cant << endl;
}
