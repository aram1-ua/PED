
#include <iostream>
#include "tporo.h"
#include "tvectorporo.h"
#include "tlistaporo.h"

using namespace std;

int main() {
    // Prueba de TPoro
    TPoro p1(1, 2, 3.5, "rojo");
    TPoro p2(4, 5, 6.7, "azul");
    cout << "Poro 1: " << p1 << endl;
    cout << "Poro 2: " << p2 << endl;

    // Prueba de TVectorPoro
    TVectorPoro v(3);
    v[1] = p1;
    v[2] = p2;
    cout << "Vector de poros: " << v << endl;

    // Prueba de TListaPoro
    TListaPoro lista;
    lista.Insertar(p1);
    lista.Insertar(p2);
    cout << "Lista de poros: " << lista << endl;

    // Prueba de operaciones de la lista
    cout << "Borrando Poro 1..." << endl;
    lista.Borrar(p1);
    cout << "Lista después de borrar: " << lista << endl;

    return 0;
}
