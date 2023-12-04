#include <iostream>
using namespace std;
class Casillero
{
public:
    string pieza;
    Casillero* siguiente;

    Casillero();
    Casillero(string pieza);
};

class ListaCasilleros
{
public:
    int longitudCasillero;
    Casillero* pCasillero;

    ListaCasilleros();
    void AgregarCasillero(string pieza);
    void MostrarCasilleros();
};

class FilaCasillero
{
public:
    ListaCasilleros* lista;
    FilaCasillero* siguienteFila;    

    FilaCasillero();
    FilaCasillero(ListaCasilleros* lista);
};

class ListaFilaCasillero
{
public:
    FilaCasillero* pFila;
    int longitudFila;

    ListaFilaCasillero();
    void AgregarFila(FilaCasillero* filaCasillero);
    void MostrarFilas();
};

class PartidaAjedrez
{
public:
    int turno;
    ListaFilaCasillero* lista;
    PartidaAjedrez();
    
    void CrearTablero();
    string ObtenerPieza();
    //Metodos pregunta 11 y 12
    void verTurno();
    void MostrarPartida();
    void MoverPieza();
    void MostrarPosiblesMovimientos();
    void ReiniciarPartida();
};
