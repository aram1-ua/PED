#ifndef TPORO_H
#define TPORO_H

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class TPoro {
private:
    // Coordenada x de la posición
    int x;
    // Coordenada y de la posición
    int y;
    // Volumen
    double volumen;
    // Color
    char* color;

public:
    // FORMA CANÓNICA
    // Constructor por defecto
    TPoro();
    // Constructor a partir de una posición y un volumen
    TPoro(int, int, double);
    // Constructor a partir de una posición, un volumen y un color
    TPoro(int, int, double, const char *);
    // Constructor de copia
    TPoro(const TPoro &);  // CAMBIO: const
    // Destructor
    ~TPoro();
    // Sobrecarga del operador asignación
    TPoro & operator=(const TPoro &);  // CAMBIO: const

    // MÉTODOS
    // Sobrecarga del operador igualdad
    bool operator==(const TPoro &) const;  // CAMBIO: const
    // Sobrecarga del operador desigualdad
    bool operator!=(const TPoro &) const;  // CAMBIO: const
    // Modifica la posición
    void Posicion(int, int);
    // Modifica el volumen
    void Volumen(double);
    // Modifica el color
    void Color(const char *);
    // Devuelve la coordenada x de la posición
    int PosicionX() const;  // CAMBIO: const
    // Devuelve la coordenada y de la posición
    int PosicionY() const;  // CAMBIO: const
    // Devuelve el volumen
    double Volumen() const;  // CAMBIO: const
    // Devuelve el color
    const char * Color() const;
    // Devuelve cierto si el poro está vacío
    bool EsVacio() const;  // CAMBIO: const

    // FUNCIONES AMIGAS
    // Sobrecarga del operador SALIDA
    friend ostream & operator<<(ostream &, const TPoro &);  // CAMBIO: const
};

#endif