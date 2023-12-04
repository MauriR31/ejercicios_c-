#include "cola.h"

ElementoCola::ElementoCola()
{
    this->valor=0;
    this->siguiente=nullptr;
}

ElementoCola::ElementoCola(int valor)
{
    this->valor=valor;
    this->siguiente=nullptr;
}

Cola::Cola()
{
    this->longitud=0;
    this->pPrimer=nullptr;
    this->pUltimo=nullptr;
}

void Cola::Enqueue(int valor)
{
    ElementoCola* nuevoElemento = new ElementoCola(valor);
    if(pPrimer==nullptr)
    {
        pPrimer= nuevoElemento;
        pUltimo = nuevoElemento;
    }
    else
    {        
        pUltimo->siguiente = nuevoElemento;
        pUltimo = nuevoElemento;
    }
    longitud++;
}

int Cola::First()
{    
    cout << "Primer valor:" <<pPrimer->valor << endl;
    return pPrimer->valor;
}

void Cola::Dequeue()
{
    ElementoCola* pTemp = pPrimer;
    pPrimer = pPrimer->siguiente;
    delete pTemp;
    longitud--;
}

void Cola::Mostrar()
{
    ElementoCola* pPivot = pPrimer;
    while(pPivot!=nullptr)
    {
        cout << "<-["<<pPivot->valor << "]";
        pPivot = pPivot->siguiente;
    }
    cout << endl;
}

int ColaPrioridad::ObtenerElemento(int pos)
{
    ElementoCola* pPivot = pPrimer;
    int cont = 0;
    while (pPivot!=nullptr)
    {
        if(pos == cont)
        {
            return pPivot->valor;
        }
        cont++;
        pPivot = pPivot->siguiente;
    }     
    return 0; 
}

ElementoCola *ColaPrioridad::SacarElementoCola(int pos)
{
    ElementoCola* pPivot = pPrimer;
    if(pos == 0)
    {
        pPrimer = pPrimer->siguiente;
        longitud--; 
        return pPivot;
    }
    else
    {
        ElementoCola* pAnt = nullptr;
        int cont = 0;
        while (pPivot!=nullptr)
        {
            if(pos == cont)
            {
                pAnt->siguiente = pPivot->siguiente;
                longitud--; 
                return pPivot;
            }
            cont++;
            pAnt = pPivot;
            pPivot = pPivot->siguiente;
        }        
    }    
    return nullptr;       
}

void ColaPrioridad::InsertarElementoCola(int pos, int valor)
{
    ElementoCola* nuevoElemento = new ElementoCola(valor);
    if(pos==0)
    {       
        nuevoElemento->siguiente = pPrimer;
        pPrimer = nuevoElemento;        
    }
    else if(pos == longitud)
    {
        ElementoCola* pPivot = pPrimer;
        while(pPivot->siguiente!=nullptr)
        {
            pPivot = pPivot->siguiente;
        }
        pPivot->siguiente = nuevoElemento;
        
    }
    else
    {
        ElementoCola* pPivot = pPrimer;
        ElementoCola* pAnt = nullptr;
        int cont=0;
        while(pPivot!=nullptr)
        {
            if(pos == cont)
            {
                pAnt->siguiente = nuevoElemento;
                nuevoElemento->siguiente = pPivot;                
                break;
            }
            cont++;
            pAnt = pPivot;
            pPivot = pPivot->siguiente;
        }
    }  
    longitud++;  
}

void ColaPrioridad::Trade(int pos1, int pos2)
{
    if(pos1 < pos2)
    {
        ElementoCola* primerSacado = SacarElementoCola(pos2);
        InsertarElementoCola(pos1,primerSacado->valor);
        ElementoCola* segundoSacado = SacarElementoCola(pos1+1);
        InsertarElementoCola(pos2,segundoSacado->valor);
    }
    if(pos1 > pos2)
    {
        ElementoCola* primerSacado = SacarElementoCola(pos2);
        InsertarElementoCola(pos1,primerSacado->valor);
        ElementoCola* segundoSacado = SacarElementoCola(pos1-1);
        InsertarElementoCola(pos2,segundoSacado->valor);
    }    
}

void ColaPrioridad::Ordenar()
{ 
    for (int i = 0; i < longitud-1; i++)
    {
        for (int j = 0; j < longitud- 1 -i ; j++)
        {            
            if(ObtenerElemento(j+1) < ObtenerElemento(j))
            {
                Trade(j+1,j);
            }
        }        
    }
}

int LazyColaDePrioridad::ObtenerElemento(int pos)
{
    ElementoCola* pPivot = pPrimer;
    int cont = 0;
    while (pPivot!=nullptr)
    {
        if(pos == cont)
        {
            return pPivot->valor;
        }
        cont++;
        pPivot = pPivot->siguiente;
    }     
    return 0; 
}

ElementoCola *LazyColaDePrioridad::SacarElementoCola(int pos)
{
    ElementoCola* pPivot = pPrimer;
    if(pos == 0)
    {
        pPrimer = pPrimer->siguiente;
        longitud--; 
        return pPivot;
    }
    else
    {
        ElementoCola* pAnt = nullptr;
        int cont = 0;
        while (pPivot!=nullptr)
        {
            if(pos == cont)
            {
                pAnt->siguiente = pPivot->siguiente;
                longitud--; 
                return pPivot;
            }
            cont++;
            pAnt = pPivot;
            pPivot = pPivot->siguiente;
        }        
    }    
    return nullptr; 
}

void LazyColaDePrioridad::InsertarElementoCola(int pos, int valor)
{
    ElementoCola* nuevoElemento = new ElementoCola(valor);
    if(pos==0)
    {       
        nuevoElemento->siguiente = pPrimer;
        pPrimer = nuevoElemento;        
    }
    else if(pos == longitud)
    {
        ElementoCola* pPivot = pPrimer;
        while(pPivot->siguiente!=nullptr)
        {
            pPivot = pPivot->siguiente;
        }
        pPivot->siguiente = nuevoElemento;
        
    }
    else
    {
        ElementoCola* pPivot = pPrimer;
        ElementoCola* pAnt = nullptr;
        int cont=0;
        while(pPivot!=nullptr)
        {
            if(pos == cont)
            {
                pAnt->siguiente = nuevoElemento;
                nuevoElemento->siguiente = pPivot;                
                break;
            }
            cont++;
            pAnt = pPivot;
            pPivot = pPivot->siguiente;
        }
    }  
    longitud++;
}

void LazyColaDePrioridad::Trade(int pos1, int pos2)
{
    if(pos1 < pos2)
    {
        ElementoCola* primerSacado = SacarElementoCola(pos2);
        InsertarElementoCola(pos1,primerSacado->valor);
        ElementoCola* segundoSacado = SacarElementoCola(pos1+1);
        InsertarElementoCola(pos2,segundoSacado->valor);
    }
    if(pos1 > pos2)
    {
        ElementoCola* primerSacado = SacarElementoCola(pos2);
        InsertarElementoCola(pos1,primerSacado->valor);
        ElementoCola* segundoSacado = SacarElementoCola(pos1-1);
        InsertarElementoCola(pos2,segundoSacado->valor);
    }    
}

void LazyColaDePrioridad::Ordenar()
{
    for (int i = 0; i < longitud-1; i++)
    {
        for (int j = 0; j < longitud- 1 -i ; j++)
        {            
            if(ObtenerElemento(j+1) < ObtenerElemento(j))
            {
                Trade(j+1,j);
            }
        }        
    }
}

void LazyColaDePrioridad::Mostrar()
{
    Ordenar();
    ElementoCola* pPivot = pPrimer;
    cout << "Cola ordenada:" << endl;
    while (pPivot!=nullptr)
    {
        cout << "<-["<< pPivot->valor << "]";
        pPivot = pPivot->siguiente;
    }    
    cout << endl;
}

void LazyColaDePrioridad::Dequeue()
{   
    Ordenar(); 
    ElementoCola* pTemp = pPrimer;
    pPrimer = pPrimer->siguiente;
    delete pTemp;
    longitud--;    
}
