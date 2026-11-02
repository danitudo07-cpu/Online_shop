#include "Producto.h"
#include "Interprete.h"
#include "dic.h"
using namespace std;

DiccionarioProductos dic;

void procesar_insertar(){
    Producto nuevo;
    nuevo.leer ();
    dic.insertar(nuevo);
    cout << dic.numElem() << " productos" << endl;
}

void procesar_palabras(){
    string c;
    cin >> c;
    cout << "palabras " << c << endl;
    dic.palabras(c);
}

void Interprete (string comando)
{
 if (comando=="insertar") {procesar_insertar();}
 else if (comando=="palabras"){procesar_palabras();}
 /*
 else if (comando=="precios") {procesar_precios();}
 else if (comando=="eliminar") {procesar_eliminar();}
 else if (comando=="producto") {procesar_producto();}
 */
 }