#ifndef TABLAHASH_H
#define TABLAHASH_H
#include "Producto.h"
#include <list>
#include <string>

// Tabla de dispersión ABIERTA (encadenamiento) de tamaño variable.
// Asocia cada palabra con la lista de productos que la contienen, ordenada por id.
class TablaHash {
private:
    class Par {
    friend class TablaHash;
    private:
        string palabra;
        list<const Producto*> l;     // ordenada por identificador
    };

    list<Par>* T;   // array de B cubetas
    int B;          // número de cubetas
    int nElem;      // número de palabras distintas almacenadas

    unsigned long dispersion(const string& palabra) const;
    void reestructurar();

public:
    TablaHash();
    ~TablaHash();
    TablaHash(const TablaHash&) = delete;             // la tabla es dueña de su memoria
    TablaHash& operator=(const TablaHash&) = delete;

    void insertar(const string& palabra, const Producto* nuevo);
    // null si la palabra no existe
    const list<const Producto*>* consultar(const string& palabra) const;
    int numElem() const { return nElem; }
};
#endif
