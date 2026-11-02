#ifndef _DICCIONARIO
#define _DICCIONARIO
#include "Producto.h"
#include "TablaHash.h"
#include <list>


class DiccionarioProductos {
 private:
    list<Producto> lista;
    TablaHash tabla;
    int contador;
 public:
    DiccionarioProductos ();
    void insertar (Producto nuevo);
    void palabras (string palabra);
    // void eliminar (long long id);
    // void producto (long long id);
    // void precios (double min,double max);
 int numElem ()
 {return contador;}
};

#endif
