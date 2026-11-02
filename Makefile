a.out: main.o Producto.o Interprete.o dic.o TablaHash.o
	g++ main.o Interprete.o dic.o Producto.o TablaHash.o

main.o: main.cpp Producto.h dic.h Interprete.h TablaHash.h
	g++ -c main.cpp

Producto.o: Producto.cpp Producto.h
	g++ -c Producto.cpp

Interprete.o: Interprete.cpp dic.h Producto.h Interprete.h
	g++ -c Interprete.cpp

dic.o: dic.cpp dic.h TablaHash.h Producto.h
	g++ -c dic.cpp

TablaHash.o: TablaHash.cpp TablaHash.h Producto.h
	g++ -c TablaHash.cpp
