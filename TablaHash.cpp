#include "TablaHash.h"

#ifndef B_INICIAL
#define B_INICIAL 101
#endif

TablaHash::TablaHash() : T(new list<Par>[B_INICIAL]), B(B_INICIAL), nElem(0) {}

TablaHash::~TablaHash() { delete[] T; }

// Multiplicador 131. Se usa unsigned char para que los bytes
// UTF-8 (0xC3, 0xA1...) no den valores negativos, y unsigned long para que el
// desbordamiento no sea nunca negativo.
unsigned long TablaHash::dispersion(const string& palabra) const {
    unsigned long h = 0;
    for (size_t i = 0; i < palabra.length(); i++)
        h = h * 131 + (unsigned char)palabra[i];
    return h % B;
}

// Crea una tabla mayor y mueve los nodos (splice: sin copiar strings ni listas).
void TablaHash::reestructurar() {
    int nuevoB = 2 * B + 1;
    list<Par>* nueva = new list<Par>[nuevoB];
    int viejoB = B;
    list<Par>* vieja = T;

    B = nuevoB;                       // dispersion() ya usa el tamaño nuevo
    for (int i = 0; i < viejoB; i++) {
        while (!vieja[i].empty()) {
            unsigned long pos = dispersion(vieja[i].front().palabra);
            nueva[pos].splice(nueva[pos].begin(), vieja[i], vieja[i].begin());
        }
    }
    T = nueva;
    delete[] vieja;
}

void TablaHash::insertar(const string& palabra, const Producto* nuevo) {
    list<Par>& cubeta = T[dispersion(palabra)];

    list<Par>::iterator par = cubeta.begin();
    while (par != cubeta.end() && par->palabra != palabra) ++par;

    if (par == cubeta.end()) {
        if (nElem + 1 > B) {          // factor de carga > 1 -> crecer
            reestructurar();
            insertar(palabra, nuevo); // recalcula la cubeta con el nuevo B
            return;
        }
        cubeta.push_front(Par());
        par = cubeta.begin();
        par->palabra = palabra;
        nElem++;
    }

    // Inserción ordenada por id (empezando por el final: lo normal es id creciente)
    list<const Producto*>& l = par->l;
    list<const Producto*>::iterator it = l.end();
    while (it != l.begin() && (*prev(it))->id() > nuevo->id()) --it;
    if (it != l.begin() && (*prev(it))->id() == nuevo->id()) return; // palabra repetida en el mismo producto
    l.insert(it, nuevo);
}

const list<const Producto*>* TablaHash::consultar(const string& palabra) const {
    const list<Par>& cubeta = T[dispersion(palabra)];
    for (list<Par>::const_iterator it = cubeta.begin(); it != cubeta.end(); ++it)
        if (it->palabra == palabra) return &it->l;
    return nullptr;
}
