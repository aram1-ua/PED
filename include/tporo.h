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
    TPoro(int, int, double, const char *);  // ← CAMBIADO: agregado 'const'
    // Constructor de copia
    TPoro(TPoro &);
    // Destructor
    ~TPoro();
    // Sobrecarga del operador asignación
    TPoro & operator=(const TPoro &);

    // MÉTODOS
    // Sobrecarga del operador igualdad
    bool operator==(const TPoro &) const ;
    // Sobrecarga del operador desigualdad
    bool operator!=(TPoro &);
    // Modifica la posición
    void Posicion(int, int);
    // Modifica el volumen
    void Volumen(double);
    // Modifica el color
    void Color(const char *);
    // Devuelve la coordenada x de la posición
    int PosicionX();
    // Devuelve la coordenada y de la posición
    int PosicionY();
    // Devuelve el volumen
    double Volumen() const;
    // Devuelve el color
    const char * Color() const;
    // Devuelve cierto si el poro está vacío
    bool EsVacio();

    // FUNCIONES AMIGAS
    // Sobrecarga del operador SALIDA
    friend ostream & operator<<(ostream &, TPoro &);
};

#endif
