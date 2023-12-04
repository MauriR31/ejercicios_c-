#include "hoja_calculo.h"

Celda::Celda()
{
    this->valor= 0;
    this->siguiente = nullptr;
}

Celda::Celda(int valor)
{
    this->valor= valor;
    this->siguiente = nullptr;
}

ListaCelda::ListaCelda()
{
    this->longitud = 0;
    this->pCelda = nullptr;
}

void ListaCelda::AgregarCelda(int valor)
{
    Celda* nuevaCelda = new Celda(valor);
    if(pCelda==nullptr)
    {
        pCelda = nuevaCelda;
    }
    else
    {
        Celda* pPivot = pCelda;
        while (pPivot->siguiente!=nullptr)
        {
            pPivot=pPivot->siguiente;
        }
        pPivot->siguiente = nuevaCelda;        
    }
    longitud++;
}

void ListaCelda::MostrarCeldas()
{
    Celda* pPivot = pCelda;    
    while (pPivot!=nullptr)
    {
        cout << "|     " << pPivot->valor << "     ";
        if(pPivot->siguiente == nullptr)
        {
            cout<< "|";
        }        
        pPivot=pPivot->siguiente;
    }    
    cout << endl;
}

Fila::Fila()
{
    this->listaC = nullptr;
    this->siguiente = nullptr;
}

Fila::Fila(ListaCelda *listaC)
{
    this->listaC = listaC;
    this->siguiente = nullptr;
}

ListaFila::ListaFila()
{
    this->longitudFila = 0;
    this->pFila = nullptr;
}


void ListaFila::AgregarFila(Fila* fila)
{
    if(pFila == nullptr)
    {
        pFila = fila;
        longitudFila++;
    }
    else
    {
        Fila* pPivot = pFila;
        while(pPivot->siguiente!=nullptr)
        {
            pPivot = pPivot->siguiente;
        }
        if(pPivot->listaC->longitud == fila->listaC->longitud)
        {
            pPivot->siguiente = fila;
            longitudFila++;
        }
        else
        {
            cout << "No se agrega fila,";
            cout <<  "porque no tiene la misma cantidad de celdas" << endl;
        }
    }    
}

void ListaFila::MostrarFilas()
{
    Fila* pPivot = pFila;
    int cont = 1;
    while(pPivot!=nullptr)
    {
        cout << "Fila" <<cont<<":";
        pPivot->listaC->MostrarCeldas();               
        cont++;
        pPivot = pPivot->siguiente;
    }
}

HojaCalculo::HojaCalculo()
{
    listafila=nullptr;
}


HojaCalculo::HojaCalculo(ListaFila* listafila)
{
    this->listafila = listafila;
}

HojaCalculo* HojaCalculo::GenerarHoja()
{
    ListaCelda* listac1 = new ListaCelda();
    listac1->AgregarCelda(5);
    listac1->AgregarCelda(3);
    listac1->AgregarCelda(2);
    listac1->AgregarCelda(0);

    ListaCelda* listac2 = new ListaCelda();
    listac2->AgregarCelda(5);
    listac2->AgregarCelda(7);
    listac2->AgregarCelda(9);
    listac2->AgregarCelda(0);

    ListaCelda* listac3 = new ListaCelda();
    listac3->AgregarCelda(5);
    listac3->AgregarCelda(5);
    listac3->AgregarCelda(5);
    listac3->AgregarCelda(5);
    listac3->AgregarCelda(0);    

    Fila* f1 = new Fila(listac1);
    Fila* f2 = new Fila(listac2);
    Fila* f3 = new Fila(listac3);

    ListaFila* listaf1 = new ListaFila();
    listaf1->AgregarFila(f1);
    listaf1->AgregarFila(f2);
    listaf1->AgregarFila(f3);

    HojaCalculo* h1 = new HojaCalculo(listaf1);
    return h1;
}

void HojaCalculo::AgregarFila()
{
    ListaCelda* CeldasAdicionales = new ListaCelda();
    for (int i = 0; i < listafila->pFila->listaC->longitud; i++)
    {
        CeldasAdicionales->AgregarCelda(0);
    }    
    Fila* filaAdicional = new Fila(CeldasAdicionales);
    listafila->AgregarFila(filaAdicional);   
}

void HojaCalculo::AgregarColumna()
{
    Fila* pPivot = listafila->pFila;
    while(pPivot!=nullptr){
        //Voy a crear una columna de puros ceros osea vacia
        pPivot->listaC->AgregarCelda(0);
        pPivot = pPivot->siguiente;
    }    
}

int HojaCalculo::VerValor(int pos1 , int pos2)
{    
    int contFila=0;
    int contColumna=0;
    Fila* pPivotFila = listafila->pFila;    
    while (pPivotFila!=nullptr)
    {
        if(pos1 == contFila)
        {
            Celda* pPivotCelda = pPivotFila->listaC->pCelda;
            while(pPivotCelda!=nullptr)
            {
                if(pos2 == contColumna)
                {
                    return pPivotCelda->valor;
                }
                contColumna++;
                pPivotCelda = pPivotCelda->siguiente;
            }
        } 
        contFila++;
        pPivotFila = pPivotFila->siguiente;
    }    
    return -1;
}


void HojaCalculo::AsignarValor(int pos1, int pos2, int valor)
{
    int contFila=0;
    int contColumna=0;
    Fila* pPivotFila = listafila->pFila;    
    while (pPivotFila!=nullptr)
    {
        if(pos1 == contFila)
        {
            Celda* pPivotCelda = pPivotFila->listaC->pCelda;
            while(pPivotCelda!=nullptr)
            {
                if(pos2 == contColumna)
                {
                    pPivotCelda->valor = valor;
                    return;
                }
                contColumna++;
                pPivotCelda = pPivotCelda->siguiente;
            }
        } 
        contFila++;
        pPivotFila = pPivotFila->siguiente;
    }
    cout << "No se encontro la celda indicada" << endl;
}

void HojaCalculo::MostrarHoja()
{
    cout << "Hoja:" << endl;
    listafila->MostrarFilas();
}

void HojaCalculo::AsignarValorSuma()
{
    int pos1Celda1=0;
    int pos2Celda1=0;
    cout << "Para la primera celda:" << endl;
    cout << "pos1:"<<endl;
    cin >> pos1Celda1;
    cout << "pos2:"<<endl;    
    cin >> pos2Celda1;
    int valor1 = VerValor(pos1Celda1, pos2Celda1);


    int pos1Celda2=0;
    int pos2Celda2=0;
    cout << "Para la segunda celda:" << endl;
    cout << "pos1:"<<endl;
    cin >> pos1Celda2;
    cout << "pos2:"<<endl;
    cin >> pos2Celda2;
    int valor2 = VerValor(pos1Celda2, pos2Celda2);

    if(valor1 == -1 || valor2 == -1)
    {
        cout << "La celda o celdas indicadas no existen en hoja" << endl;
    }
    else
    {
        int suma = valor1+valor2;
        int pos1Suma =0;
        int pos2Suma =0;
        cout << "Indique la celda para la suma:"<<endl;
        cout << "pos1"<<endl;
        cin >> pos1Suma;
        cout << "pos2"<<endl;
        cin >> pos2Suma;              
        AsignarValor(pos1Suma,pos2Suma,suma);
    }
}

void HojaCalculo::AsignarValorResta()
{
    int pos1Celda1=0;
    int pos2Celda1=0;
    cout << "Para la primera celda:" << endl;
    cout << "pos1:"<<endl;
    cin >> pos1Celda1;
    cout << "pos2:"<<endl;    
    cin >> pos2Celda1;
    int valor1 = VerValor(pos1Celda1, pos2Celda1);


    int pos1Celda2=0;
    int pos2Celda2=0;
    cout << "Para la segunda celda:" << endl;
    cout << "pos1:"<<endl;
    cin >> pos1Celda2;
    cout << "pos2:"<<endl;
    cin >> pos2Celda2;
    int valor2 = VerValor(pos1Celda2, pos2Celda2);

    if(valor1 == -1 || valor2 == -1)
    {
        cout << "La celda o celdas indicadas no existen en hoja" << endl;
    }
    else
    {
        int resta = valor1-valor2;
        int pos1Resta =0;
        int pos2Resta =0;
        cout << "Indique la celda para la resta:"<<endl;
        cout << "pos1"<<endl;
        cin >> pos1Resta;
        cout << "pos2"<<endl;
        cin >> pos2Resta;              
        AsignarValor(pos1Resta,pos2Resta,resta);
    }
}

