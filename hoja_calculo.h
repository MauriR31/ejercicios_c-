#include <iostream>
using namespace std;
class Celda
{
public:
    int valor;
    Celda* siguiente;

    Celda();
    Celda(int valor);
};
class ListaCelda
{
public:
    int longitud;
    Celda* pCelda;
    ListaCelda();
    void AgregarCelda(int valor);
    void MostrarCeldas();
};
class Fila
{
public:
    ListaCelda* listaC;
    Fila* siguiente;
    Fila();
    Fila(ListaCelda* listaC);
};
class ListaFila
{
public:
    int longitudFila;
    Fila* pFila;

    ListaFila();
    void AgregarFila(Fila* fila);
    void MostrarFilas();
};
class HojaCalculo
{
public:
    ListaFila* listafila;

    HojaCalculo();
    HojaCalculo(ListaFila* listafila);
    HojaCalculo* GenerarHoja();

    //Metodos de la pregunta 6
    void AgregarFila();
    void AgregarColumna();
    int VerValor(int pos1 , int pos2);
    void AsignarValor(int pos1 , int pos2, int valor);
    void MostrarHoja();
    //Metodos de la pregunta 8
    void AsignarValorSuma();
    void AsignarValorResta();
};