all: build
build:
	g++ -c lista_enlazada.cpp
	g++ -c pila.cpp
	g++ -c cola.cpp
	g++ -c caja.cpp
	g++ -c funcion.cpp
	g++ -c hoja_calculo.cpp
	g++ -c partida_ajedrez.cpp
	g++ lista_enlazada.o pila.o cola.o caja.o funcion.o hoja_calculo.o partida_ajedrez.o main.cpp -o main
	main.exe
clean:
	-rm -rf *.exe
	-rm -rf *.o
