#include "partida_ajedrez.h"
//Creacion de un casillero
//en el casillero puede o no haber piezas
Casillero::Casillero()
{
    this->pieza = "[     ]";
    this->siguiente = nullptr;
}

Casillero::Casillero(string pieza)
{
    this->pieza = pieza;
    this->siguiente = nullptr;
}

ListaCasilleros::ListaCasilleros()
{
    this->longitudCasillero= 0;
    this->pCasillero = nullptr;
}

void ListaCasilleros::AgregarCasillero(string pieza)
{
    Casillero* nuevaPieza = new Casillero(pieza);
    if(pCasillero == nullptr)
    {
        pCasillero = nuevaPieza;
    }
    else
    {
        Casillero* pPivot = pCasillero;
        while (pPivot->siguiente!=nullptr)
        {
            pPivot=pPivot->siguiente;
        }
        pPivot->siguiente = nuevaPieza;
    }
    longitudCasillero++;
}

void ListaCasilleros::MostrarCasilleros()
{
    Casillero* pPivot = pCasillero;    
    while(pPivot!=nullptr)
    {
        cout << pPivot->pieza;     
        pPivot = pPivot->siguiente;
    }
    cout << endl;        
}

FilaCasillero::FilaCasillero()
{
    this->lista = new ListaCasilleros();
    this->siguienteFila = nullptr;
}

FilaCasillero::FilaCasillero(ListaCasilleros *lista)
{
    this->lista = lista;
    this->siguienteFila = nullptr;
}

ListaFilaCasillero::ListaFilaCasillero()
{
    this->pFila = nullptr;
    this->longitudFila = 0;
}

void ListaFilaCasillero::AgregarFila(FilaCasillero *filaCasillero)
{
    if(pFila==nullptr)
    {
        pFila = filaCasillero;
    }
    else
    {
        FilaCasillero* pPivot = pFila;
        while(pPivot->siguienteFila!=nullptr)
        {
            pPivot = pPivot->siguienteFila;
        }
        pPivot->siguienteFila = filaCasillero;
    }
    longitudFila++;
}

void ListaFilaCasillero::MostrarFilas()
{
    FilaCasillero* pPivot = pFila;
    int incremento=1;
    while(pPivot!=nullptr)
    {
        cout << incremento << " : ";
        pPivot->lista->MostrarCasilleros();
        pPivot =pPivot->siguienteFila;
        incremento++;
    }
}

PartidaAjedrez::PartidaAjedrez()
{
    turno = 0;
    lista = new ListaFilaCasillero();
}

void PartidaAjedrez::CrearTablero()
{
    FilaCasillero* fila = new FilaCasillero();
    fila->lista->AgregarCasillero("[ TORRE ]");
    fila->lista->AgregarCasillero("[CABALLO]");
    fila->lista->AgregarCasillero("[ ALFIL ]");
    fila->lista->AgregarCasillero("[ REINA ]");
    fila->lista->AgregarCasillero("[  REY  ]");
    fila->lista->AgregarCasillero("[ ALFIL ]");
    fila->lista->AgregarCasillero("[CABALLO]");
    fila->lista->AgregarCasillero("[ TORRE ]");    
    lista->AgregarFila(fila);

    fila = new FilaCasillero();   
    for (int i = 0; i < 8; i++)
    {
        fila->lista->AgregarCasillero("[ PEON  ]");
    }
    lista->AgregarFila(fila);
    
    for (int i = 0; i < 4; i++)
    {
        fila = new FilaCasillero();
        for (int i = 0; i < 8; i++)
        {
            fila->lista->AgregarCasillero("[       ]");
        }
        lista->AgregarFila(fila);    
    }  

    fila = new FilaCasillero();   
    for (int i = 0; i < 8; i++)
    {
        fila->lista->AgregarCasillero("[ PEON  ]");
    }
    lista->AgregarFila(fila);

    fila = new FilaCasillero();
    fila->lista->AgregarCasillero("[ TORRE ]");
    fila->lista->AgregarCasillero("[CABALLO]");
    fila->lista->AgregarCasillero("[ ALFIL ]");
    fila->lista->AgregarCasillero("[ REINA ]");
    fila->lista->AgregarCasillero("[  REY  ]");
    fila->lista->AgregarCasillero("[ ALFIL ]");
    fila->lista->AgregarCasillero("[CABALLO]");
    fila->lista->AgregarCasillero("[ TORRE ]");
    lista->AgregarFila(fila);    
}

string PartidaAjedrez::ObtenerPieza()
{
    int posX;
    int posY;
    cout << "Coordenadas de ficha a mover:" << endl;
    cout << "X:" << endl;
    cin >> posX;
    cout << "Y:" << endl;
    cin >> posY;

    int contX = 0;
    int contY = 0;
    string valorPieza = "";
    FilaCasillero* pPivotFila =lista->pFila;
    while(pPivotFila!=nullptr)
    {
        if(posY == contY)
        {
            Casillero* pPivotCasillero = pPivotFila->lista->pCasillero;
            while(pPivotCasillero!=nullptr)
            {
                if(posX == contX)
                {
                    valorPieza = pPivotCasillero->pieza;
                    pPivotCasillero->pieza = "[       ]";                    
                }
                contX++;                
                pPivotCasillero = pPivotCasillero->siguiente;
            }
        }
        contY++;
        pPivotFila = pPivotFila->siguienteFila;
    }
    return valorPieza;
}

void PartidaAjedrez::verTurno()
{    
    if(turno % 2 == 0)
    {
        cout << "Inician Piezas Blancas" << endl;
    }
    else
    {
        cout << "Inician Piezas Negras" << endl;
    }
    turno++;
}

void PartidaAjedrez::MostrarPartida()
{ 
    lista->MostrarFilas();
    cout << "\tA" << "\t B" <<"\t  C" << "\t   D" <<  
    "\t    E"  <<  "\t     F"  <<   "\t      G"<<"\t       H" <<endl;    
}

void PartidaAjedrez::MoverPieza()
{
    string nuevoValor = ObtenerPieza();
    int posX;
    int posY;
    cout << "Coordenadas de destino:" << endl;
    cout << "X:" << endl;
    cin >> posX;
    cout << "Y:" << endl;
    cin >> posY;

    int contX = 0;
    int contY = 0;
    FilaCasillero* pPivotFila = lista->pFila;
    while(pPivotFila!=nullptr)
    {
        if(posY == contY)
        {
            Casillero* pPivotCasillero = pPivotFila->lista->pCasillero;
            while(pPivotCasillero!=nullptr)
            {
                if(posX == contX)
                {
                    pPivotCasillero->pieza = nuevoValor;
                }
                contX++;                
                pPivotCasillero = pPivotCasillero->siguiente;
            }
        }
        contY++;
        pPivotFila = pPivotFila->siguienteFila;
    }
}

void PartidaAjedrez::MostrarPosiblesMovimientos()
{
    string valorPieza = ObtenerPieza();
    if(valorPieza != "[       ]")
    {
        cout << "La pieza tiene x movimientos a realizar" << endl;
    }
    else
    {
        cout << "No hay pieza" << endl;
    }
}

void PartidaAjedrez::ReiniciarPartida()
{
    lista = new ListaFilaCasillero();
    CrearTablero();
}

