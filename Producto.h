#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string>
using namespace std;

string minusculas(string c);   

class Producto {
private:
    long long identificador;
    string nombre, descripcion;
    float precio;
public:
    Producto() : identificador(0), precio(0) {}
    void leer();
    void mostrar() const;
    long long id() const { return identificador; }
    const string& getNombre() const { return nombre; }
    const string& getDescripcion() const { return descripcion; }
};
#endif
