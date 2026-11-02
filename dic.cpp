#include "dic.h"
#include <sstream>

DiccionarioProductos::DiccionarioProductos(){
    contador = 0;
}

void DiccionarioProductos::insertar(Producto nuevo){

    contador++;
    lista.push_back(nuevo);
    Producto* pt = &lista.back();   // puntero al producto guardado, no al parametro

    istringstream iss(pt->getNombre() + " " + pt->getDescripcion());
    string w;
    while (iss >> w) {
        tabla.insertar(minusculas(w), pt);
    }
}

void DiccionarioProductos::palabras(string palabra){

    const list<const Producto*>* l = tabla.consultar(minusculas(palabra));
    int n = 0;
    if (l != NULL) {
        for (list<const Producto*>::const_iterator it = l->begin(); it != l->end(); ++it) {
            n++;
            cout << n << ". ";
            (*it)->mostrar();
        }
    }
    cout << "Total: " << n << " productos" << endl;
}
