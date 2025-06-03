#ifndef TLISTAPORO_H
#define TLISTAPORO_H

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
    TListaNodo(TListaNodo &);
    // Destructor
    ~TListaNodo();
    // Sobrecarga del operador asignación
    TListaNodo & operator=(TListaNodo &);

    // Declarar amistad
    friend class TListaPoro;
    friend class TListaPosicion;

    friend ostream & operator<<(ostream &, TListaPoro &);  // ← ESTA LÍNEA ES CLAVE

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
    TListaPosicion(TListaPosicion &);
    // Destructor
    ~TListaPosicion();
    // Sobrecarga del operador asignación
    TListaPosicion& operator=(TListaPosicion &);

    // MÉTODOS
    // Sobrecarga del operador igualdad
    bool operator==(TListaPosicion &);
    // Devuelve la posición anterior
    TListaPosicion Anterior();
    // Devuelve la posición siguiente
    TListaPosicion Siguiente();
    // Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
    bool EsVacia();

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
    TListaPoro(TListaPoro &);
    // Destructor
    ~TListaPoro();
    // Sobrecarga del operador asignación
    TListaPoro & operator=(TListaPoro &);

    // MÉTODOS
    // Sobrecarga del operador igualdad
    bool operator==(TListaPoro &);
    // Sobrecarga del operador suma
    TListaPoro operator+(TListaPoro &);
    // Sobrecarga del operador resta
    TListaPoro operator-(TListaPoro &);
    // Devuelve true si la lista está vacía, false en caso contrario
    bool EsVacia();
    // Inserta el elemento en la lista
    bool Insertar(TPoro &);
    // Busca y borra el elemento
    bool Borrar(TPoro &);
    // Borra el elemento que ocupa la posición indicada
    bool Borrar(TListaPosicion &);
    // Obtiene el elemento que ocupa la posición indicada
    TPoro Obtener(TListaPosicion &);
    // Devuelve true si el elemento está en la lista, false en caso contrario
    bool Buscar(TPoro &);
    // Devuelve la longitud de la lista
    int Longitud();
    // Devuelve la primera posición en la lista
    TListaPosicion Primera();
    // Devuelve la última posición en la lista
    TListaPosicion Ultima();
    // Extraer un rango de nodos de la lista
    TListaPoro ExtraerRango(int n1, int n2);

    // FUNCIONES AMIGAS
    // Sobrecarga del operador salida
    friend ostream & operator<<(ostream &, TListaPoro &);
};

#endif