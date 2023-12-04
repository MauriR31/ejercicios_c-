#include <iostream>
#include <string>
using namespace std;
class Objetofuncion
{
public:
    string nombre;    
    Objetofuncion();
    Objetofuncion(string nombre);
};

class Parametro
{
public:
    int valor;
    Objetofuncion* objetofuncion;
    Parametro* siguiente;

    Parametro();
    Parametro(int valor);
    Parametro(Objetofuncion* objetofuncion);
};

class ListaParametros
{
public:
    int longitud;
    Parametro* pPrimer;

    ListaParametros();
    void AgregarParametro(Parametro *parametro);
    void Mostrar();
};

class Funcion
{
public:
    string nombre;
    ListaParametros* lista;

    //Constructor de la pregunta 10
    Funcion(ListaParametros* lista);
    //Metodos de la pregunta 9
    string FormarLlamadaPython();
    string FormarLlamadaRacket();
};

