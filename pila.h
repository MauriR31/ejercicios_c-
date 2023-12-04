#include <iostream>
using namespace std;
class ElementoPila
{
public:
    int valor;
    ElementoPila* siguiente;

    ElementoPila();
    ElementoPila(int valor);
};

class Pila
{
// Para demostrar el funcionamiento de la pila
// en el main.cpp  de la pregunta 2
// la clase la considere publica, pero su visibilidad deberia ser protegida
public:
    int longitud;
    ElementoPila* pPrimer;

    void Push(int valor);
    void Peek();
    void Pop();
    void Mostrar();
};
