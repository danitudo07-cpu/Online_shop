#include "Producto.h"

void Producto::leer() {
    cin >> identificador;
    cin.ignore();
    getline(cin, nombre);
    getline(cin, descripcion);
    cin >> precio;
}

void Producto::mostrar() const {
    cout << nombre << " (" << identificador << ")" << endl;
    cout << "  " << descripcion << endl;
    cout << "  " << precio << " euros" << endl;
}
