#include "Producto.h"
#include "Interprete.h"

string minusculas(string c) {
    string s;
    for (size_t i = 0; i < c.length(); i++) {
        unsigned char a = c[i];
        if (a >= 'A' && a <= 'Z') s += (char)(a + 32);
        else if (a == 0xC3 && i + 1 < c.length()) {
            unsigned char n = c[++i];
            s += (char)0xC3;
            if (n==0x81||n==0x89||n==0x8D||n==0x93||n==0x9A||n==0x9C||n==0x91) s += (char)(n + 0x20);
            else s += (char)n;
        } else s += c[i];
    }
    return s;
}

int main() {
    string comando;
    while (cin >> comando) Interprete(comando);
}
