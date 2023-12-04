#include <iostream>
using namespace std;
//Este elemento de numero se va a agregar a la lista enlazada
class Elemento
{
public:
    int valor;
    Elemento* siguiente;
    
    Elemento();
    Elemento(int valor);
};
//Es lista enlazada simple compuesta por elementos
class ListaEnlazada
{
public:
    int longitud;
    Elemento* pPrimer;

    ListaEnlazada();
    //Este metodo no me piden, pero lo utilizo para ver todos los elementos de la lista
    void Mostrar();
    // Metodos de la pregunta 1
    void AgregarElemento(int pos, int valor);
    void EliminarElemento(int pos);
    int VerValor(int pos);
    void CantElementos();
};