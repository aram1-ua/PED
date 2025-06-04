#ifndef TLISTAPORO_H
#define TLISTAPORO_H
#include <iostream>
#include "tporo.h"

// Declaraciones adelantadas
class TListaNodo;
class TListaPosicion;
class TListaPoro;

// Clase TListaNodo
class TListaNodo {
private:
    // El elemento del nodo
    TPoro e;
    // El nodo anterior
    TListaNodo *anterior;
    // El nodo siguiente
    TListaNodo *siguiente;

public:
    // FORMA CANÓNICA
    // Constructor por defecto
    TListaNodo();
    // Constructor de copia
    TListaNodo(const TListaNodo &);  // CAMBIO: const
    // Destructor
    ~TListaNodo();
    // Sobrecarga del operador asignación
    TListaNodo & operator=(const TListaNodo &);  // CAMBIO: const

    // Declarar amistad
    friend class TListaPoro;
    friend class TListaPosicion;

    friend ostream & operator<<(ostream &, const TListaPoro &);  // CAMBIO: const
};

// Clase TListaPosicion
class TListaPosicion {
private:
    // Para implementar la POSICIÓN a NODO de la LISTA de TPoro
    TListaNodo *pos;

public:
    // FORMA CANÓNICA
    // Constructor por defecto
    TListaPosicion();
    // Constructor de copia
    TListaPosicion(const TListaPosicion &);  // CAMBIO: const
    // Destructor
    ~TListaPosicion();
    // Sobrecarga del operador asignación
    TListaPosicion& operator=(const TListaPosicion &);  // CAMBIO: const

    // MÉTODOS
    // Sobrecarga del operador igualdad
    bool operator==(const TListaPosicion &) const;  // CAMBIO: const
    // Devuelve la posición anterior
    TListaPosicion Anterior();
    // Devuelve la posición siguiente
    TListaPosicion Siguiente();
    // Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
    bool EsVacia() const;  // CAMBIO: const

    // Declarar amistad
    friend class TListaPoro;
};

// Clase TListaPoro
class TListaPoro {
private:
    // Primer elemento de la lista
    TListaNodo *primero;
    // Ultimo elemento de la lista
    TListaNodo *ultimo;

public:
    // FORMA CANÓNICA
    // Constructor por defecto
    TListaPoro();
    // Constructor de copia
    TListaPoro(const TListaPoro &);  // CAMBIO: const
    // Destructor
    ~TListaPoro();
    // Sobrecarga del operador asignación
    TListaPoro & operator=(const TListaPoro &);  // CAMBIO: const

    // MÉTODOS
    // Sobrecarga del operador igualdad
    bool operator==(const TListaPoro &) const;  // CAMBIO: const
    // Sobrecarga del operador suma
    TListaPoro operator+(const TListaPoro &) const;  // CAMBIO: const
    // Sobrecarga del operador resta
    TListaPoro operator-(const TListaPoro &) const;  // CAMBIO: const
    // Devuelve true si la lista está vacía, false en caso contrario
    bool EsVacia() const;  // CAMBIO: const
    // Inserta el elemento en la lista
    bool Insertar(const TPoro &);  // CAMBIO: const
    // Busca y borra el elemento
    bool Borrar(const TPoro &);  // CAMBIO: const
    // Borra el elemento que ocupa la posición indicada
    bool Borrar(TListaPosicion &);
    // Obtiene el elemento que ocupa la posición indicada
    TPoro Obtener(const TListaPosicion &) const;  // CAMBIO: const
    // Devuelve true si el elemento está en la lista, false en caso contrario
    bool Buscar(const TPoro &) const;  // CAMBIO: const
    // Devuelve la longitud de la lista
    int Longitud() const;  // CAMBIO: const
    // Devuelve la primera posición en la lista
    TListaPosicion Primera() const;  // CAMBIO: const
    // Devuelve la última posición en la lista
    TListaPosicion Ultima() const;  // CAMBIO: const
    // Extraer un rango de nodos de la lista
    TListaPoro ExtraerRango(int n1, int n2);

    // FUNCIONES AMIGAS
    // Sobrecarga del operador salida
    friend ostream & operator<<(ostream &, const TListaPoro &);  // CAMBIO: const
};

#endif
