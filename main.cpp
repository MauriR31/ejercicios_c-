#include "lista_enlazada.h"
#include "pila.h"
#include "cola.h"
#include "caja.h"
#include "funcion.h"
#include "hoja_calculo.h"
#include "partida_ajedrez.h"
int main()
{
    int pregunta = 0;
    cout << "Elija la pregunta que quiera ver: ";
    cin >> pregunta;     

    //Pregunta1
    ListaEnlazada* lista1 = new ListaEnlazada();
    //Pregunta2
    Pila* pila1 = new Pila();
    //Pregunta3
    Cola* cola1 = new Cola();
    //Pregunta4
    ColaPrioridad* c1 = new ColaPrioridad();
    //Pregunta5
    LazyColaDePrioridad* lc1 = new LazyColaDePrioridad();
    //Pregunta6 y 8
    HojaCalculo* hoja = new HojaCalculo();
    HojaCalculo* nuevaHoja = hoja->GenerarHoja();
    //Pregunta 7
    Producto* p1 = new Producto(10,5);
    Producto* p2 = new Producto(20,15);
    Producto* p3 = new Producto(20,15);
    Producto* p4 = new Producto(1,10);
    Caja* caja1 = new Caja(50,100);
    //Pregunta 9 y 10
    Objetofuncion* f1 = new Objetofuncion("FormarLlamadaPython");    
    Objetofuncion* f2 = new Objetofuncion("FormarLlamadaRacket"); 
    Parametro* para1 = new Parametro(4);
    Parametro* para2 = new Parametro(2);
    Parametro* para3 = new Parametro(5);
    Parametro* para4 = new Parametro(f1);

    Parametro* para5 = new Parametro(4);
    Parametro* para6 = new Parametro(2);
    Parametro* para7 = new Parametro(5);
    Parametro* para8 = new Parametro(f2);
    ListaParametros* listaP1 = new ListaParametros();
    ListaParametros* listaR1 = new ListaParametros();
    listaP1->AgregarParametro(para1);
    listaP1->AgregarParametro(para2);
    listaP1->AgregarParametro(para3);
    listaP1->AgregarParametro(para4);

    listaR1->AgregarParametro(para5);
    listaR1->AgregarParametro(para6);
    listaR1->AgregarParametro(para7);
    listaR1->AgregarParametro(para8);       
    Funcion* funcion = new Funcion(listaP1);
    Funcion* funcion2 = new Funcion(listaR1);
    //Pregunta 11 y 12
    PartidaAjedrez* tab1 = new PartidaAjedrez();

    switch (pregunta)
    {
    case 1:
        //Pregunta 1 demostracion            
        lista1->AgregarElemento(0,2);
        lista1->AgregarElemento(1,4);
        lista1->AgregarElemento(0,9);
        lista1->Mostrar();
        lista1->CantElementos();

        lista1->EliminarElemento(1);
        lista1->Mostrar();
        lista1->CantElementos();
        cout << "valor:" << lista1->VerValor(1) << endl;
        break;
        
    case 2:
        //Pregunta 2 demostracion 
        pila1->Push(4);  
        pila1->Push(9);  
        pila1->Push(11);  
        pila1->Push(15);  
        pila1->Mostrar();
        pila1->Peek();
        pila1->Pop();
        pila1->Pop();
        pila1->Mostrar();
        pila1->Peek();
        break;
    case 3:    
        //Pregunta 3 demostracion     
        cola1->Enqueue(5);
        cola1->Enqueue(10);
        cola1->Enqueue(15);    
        cola1->Mostrar();

        cola1->Dequeue();
        cola1->Mostrar();
        cola1->First(); 
        break;
    case 4:
        //Pregunta 4 demostracion 
        c1->Enqueue(3);
        c1->Enqueue(5);
        c1->Enqueue(20);
        c1->Enqueue(5);
        c1->Enqueue(4);
        c1->Enqueue(8);
        c1->Enqueue(13);
        c1->Mostrar();  
        c1->Ordenar();
        c1->Mostrar(); 
        break;    
    case 5:   
        //Pregunta 5 demostracion      
        lc1->Enqueue(1);
        lc1->Enqueue(0);
        lc1->Enqueue(9);
        lc1->Enqueue(7);
        lc1->Enqueue(2);        

        lc1->Mostrar();
        lc1->First();
        cout << "------------"<<endl;
        lc1->Dequeue();
        lc1->First();        
        lc1->Mostrar();
        break;
    case 6:    
        //Pregunta 6 demostracion    
        nuevaHoja->MostrarHoja();
        nuevaHoja->AgregarFila();
        nuevaHoja->MostrarHoja();
        nuevaHoja->AgregarColumna();
        nuevaHoja->MostrarHoja();
        cout << "ver valor:" << nuevaHoja->VerValor(1,2) << endl;
        nuevaHoja->MostrarHoja();
        nuevaHoja->AsignarValor(2,3,8);
        nuevaHoja->AsignarValor(0,4,1);
        nuevaHoja->MostrarHoja();
        break;
    case 7:   
        //Pregunta 7 demostracion     
        caja1->AgregarObjeto(p1);
        caja1->AgregarObjeto(p2);
        caja1->AgregarObjeto(p3);
        caja1->AgregarObjeto(p4);

        cout << "---------------------"<<endl;
        caja1->MostrarCaja();        
        break;

    case 8:
        //Pregunta 8 demostracion
        nuevaHoja->MostrarHoja();
        nuevaHoja->AsignarValorSuma();
        nuevaHoja->AsignarValorResta();
        nuevaHoja->MostrarHoja();
        break;

    case 9:  
        //Pregunta 9 demostracion     
        cout << funcion->FormarLlamadaPython() << endl;        
        break;
    case 10: 
        //Pregunta 10 demostracion  
        cout << funcion2->FormarLlamadaRacket() << endl;       
        break;
    case 11:
        //Pregunta 11 demostracion 
        tab1->CrearTablero(); 
        tab1->MostrarPartida();
        break;
    case 12:
        //Pregunta 12 demostracion 
        tab1->CrearTablero(); 
        tab1->MostrarPartida();
        tab1->MostrarPosiblesMovimientos();
        tab1->MoverPieza();
        tab1->MostrarPartida();
        tab1->ReiniciarPartida();
        tab1->MostrarPartida();
        break;
    }
    return 0;
}