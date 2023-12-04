#include <iostream>
using namespace std;
class ElementoCola
{
public:
    int valor;
    ElementoCola* siguiente;

    ElementoCola();
    ElementoCola(int valor);
};
class Cola
{
// Para demostrar el funcionamiento de la cola
// en el main.cpp  de la pregunta 3
// la clase la considere publica, pero su visibilidad deberia ser protegida
public:
    int longitud;
    ElementoCola* pPrimer;
    ElementoCola* pUltimo;

    Cola();    
    //Metodos de la pregunta 3
    void Enqueue(int valor);
    int First();
    virtual void Dequeue();
    //Metodo adicional
    virtual void Mostrar();    
};

//pregunta 4
class ColaPrioridad : public Cola
{
public:
    //4 Metodos adicionales para poder ordenar la cola
    //ya que se me dificultaba si solo usaba first, enqueue y dequeue
    int ObtenerElemento(int pos);
    ElementoCola* SacarElementoCola(int pos);
    void InsertarElementoCola(int pos, int valor);    
    void Trade(int pos1, int pos2);
    //Metodo principal
    void Ordenar();
};

//pregunta 5
class LazyColaDePrioridad : public Cola
{
public:
    //4 Metodos adicionales para poder ordenar la cola
    //ya que se me dificultaba si solo usaba first, enqueue y dequeue
    int ObtenerElemento(int pos);
    ElementoCola* SacarElementoCola(int pos);
    void InsertarElementoCola(int pos, int valor);    
    void Trade(int pos1, int pos2);
    //Metodo principal
    void Ordenar();
    //Redefinir metodos mostrar y eliminar (dequeaue)
    void Mostrar() override;
    void Dequeue() override;
};
