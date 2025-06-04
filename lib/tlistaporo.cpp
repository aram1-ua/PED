#include "tlistaporo.h"

// ==================== IMPLEMENTACIÓN TListaNodo ====================

// Constructor por defecto
TListaNodo::TListaNodo() {
    anterior = NULL;
    siguiente = NULL;
}

// Constructor de copia
TListaNodo::TListaNodo(const TListaNodo &otro) {
    e = otro.e;
    anterior = NULL;
    siguiente = NULL;
}

// Destructor
TListaNodo::~TListaNodo() {
    anterior = NULL;
    siguiente = NULL;
}

// Sobrecarga del operador asignación
TListaNodo & TListaNodo::operator=(const TListaNodo &otro) {
    if (this != &otro) {
        e = otro.e;
        anterior = NULL;
        siguiente = NULL;
    }
    return *this;
}

// ==================== IMPLEMENTACIÓN TListaPosicion ====================

// Constructor por defecto
TListaPosicion::TListaPosicion() {
    pos = NULL;
}

// Constructor de copia
TListaPosicion::TListaPosicion(const TListaPosicion &otra) {
    pos = otra.pos;
}

// Destructor
TListaPosicion::~TListaPosicion() {
    pos = NULL;
}

// Sobrecarga del operador asignación
TListaPosicion& TListaPosicion::operator=(const TListaPosicion &otra) {
    if (this != &otra) {
        pos = otra.pos;
    }
    return *this;
}

// Sobrecarga del operador igualdad
bool TListaPosicion::operator==(const TListaPosicion &otra) const{
    return pos == otra.pos;
}

// Devuelve la posición anterior
TListaPosicion TListaPosicion::Anterior() {
    TListaPosicion anterior;
    if (pos != NULL && pos->anterior != NULL) {
        anterior.pos = pos->anterior;
    }
    return anterior;
}

// Devuelve la posición siguiente
TListaPosicion TListaPosicion::Siguiente() {
    TListaPosicion siguiente;
    if (pos != NULL && pos->siguiente != NULL) {
        siguiente.pos = pos->siguiente;
    }
    return siguiente;
}

// Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
bool TListaPosicion::EsVacia() const{
    return pos == NULL;
}

// ==================== IMPLEMENTACIÓN TListaPoro ====================

// Constructor por defecto
TListaPoro::TListaPoro() {
    primero = NULL;
    ultimo = NULL;
}

// Constructor de copia
TListaPoro::TListaPoro(const TListaPoro &otra) {
    primero = NULL;
    ultimo = NULL;
    
    TListaNodo *actual = otra.primero;
    while (actual != NULL) {
        Insertar(actual->e);
        actual = actual->siguiente;
    }
}

// Destructor
TListaPoro::~TListaPoro() {
    TListaNodo *actual = primero;
    while (actual != NULL) {
        TListaNodo *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    primero = NULL;
    ultimo = NULL;
}

// Sobrecarga del operador asignación
TListaPoro & TListaPoro::operator=(const TListaPoro &otra) {
    if (this != &otra) {
        // Destruir lista actual
        TListaNodo *actual = primero;
        while (actual != NULL) {
            TListaNodo *siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
        primero = NULL;
        ultimo = NULL;
        
        // Copiar elementos de la otra lista
        actual = otra.primero;
        while (actual != NULL) {
            Insertar(actual->e);
            actual = actual->siguiente;
        }
    }
    return *this;
}

// Sobrecarga del operador igualdad
bool TListaPoro::operator==(const TListaPoro &otra) const {
    if (Longitud() != otra.Longitud()) {
        return false;
    }
    
    TListaNodo *actual1 = primero;
    TListaNodo *actual2 = otra.primero;
    
    while (actual1 != NULL && actual2 != NULL) {
        if (actual1->e != actual2->e) {
            return false;
        }
        actual1 = actual1->siguiente;
        actual2 = actual2->siguiente;
    }
    
    return true;
}

// Sobrecarga del operador suma
TListaPoro TListaPoro::operator+(const TListaPoro &otra) const{
    TListaPoro resultado;
    
    // Insertar elementos de la primera lista
    TListaNodo *actual = primero;
    while (actual != NULL) {
        resultado.Insertar(actual->e);
        actual = actual->siguiente;
    }
    
    // Insertar elementos de la segunda lista
    actual = otra.primero;
    while (actual != NULL) {
        resultado.Insertar(actual->e);
        actual = actual->siguiente;
    }
    
    return resultado;
}

// Sobrecarga del operador resta
TListaPoro TListaPoro::operator-(const TListaPoro &otra) const{
    TListaPoro resultado;
    
    TListaNodo *actual = primero;
    while (actual != NULL) {
        if (!otra.Buscar(actual->e)) {
            resultado.Insertar(actual->e);
        }
        actual = actual->siguiente;
    }
    
    return resultado;
}

// Devuelve true si la lista está vacía, false en caso contrario
bool TListaPoro::EsVacia() const {
    return primero == NULL;
}

// Inserta el elemento en la lista
bool TListaPoro::Insertar(const TPoro &elemento) {
    // Verificar si el elemento ya existe
    if (Buscar(elemento)) {
        return false;
    }
    
    TListaNodo *nuevo = new TListaNodo();
    nuevo->e = elemento;
    
    // Si la lista está vacía
    if (primero == NULL) {
        primero = ultimo = nuevo;
        return true;
    }
    
    // Buscar posición de inserción (ordenado por volumen)
    TListaNodo *actual = primero;
    while (actual != NULL && actual->e.Volumen() <= elemento.Volumen()) {
        actual = actual->siguiente;
    }
    
    // Insertar al principio
    if (actual == primero) {
        nuevo->siguiente = primero;
        primero->anterior = nuevo;
        primero = nuevo;
    }
    // Insertar al final
    else if (actual == NULL) {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
    }
    // Insertar en el medio
    else {
        nuevo->siguiente = actual;
        nuevo->anterior = actual->anterior;
        actual->anterior->siguiente = nuevo;
        actual->anterior = nuevo;
    }
    
    return true;
}

// Busca y borra el elemento
bool TListaPoro::Borrar(const TPoro &elemento) {
    TListaNodo *actual = primero;
    
    while (actual != NULL) {
        if (actual->e == elemento) {
            // Caso: único elemento
            if (actual == primero && actual == ultimo) {
                primero = ultimo = NULL;
            }
            // Caso: primer elemento
            else if (actual == primero) {
                primero = actual->siguiente;
                primero->anterior = NULL;
            }
            // Caso: último elemento
            else if (actual == ultimo) {
                ultimo = actual->anterior;
                ultimo->siguiente = NULL;
            }
            // Caso: elemento intermedio
            else {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }
            
            delete actual;
            return true;
        }
        actual = actual->siguiente;
    }
    
    return false;
}

// Borra el elemento que ocupa la posición indicada
bool TListaPoro::Borrar(TListaPosicion &posicion) {
    if (posicion.EsVacia()) {
        return false;
    }
    
    TListaNodo *nodo = posicion.pos;
    
    // Caso: único elemento
    if (nodo == primero && nodo == ultimo) {
        primero = ultimo = NULL;
    }
    // Caso: primer elemento
    else if (nodo == primero) {
        primero = nodo->siguiente;
        primero->anterior = NULL;
    }
    // Caso: último elemento
    else if (nodo == ultimo) {
        ultimo = nodo->anterior;
        ultimo->siguiente = NULL;
    }
    // Caso: elemento intermedio
    else {
        nodo->anterior->siguiente = nodo->siguiente;
        nodo->siguiente->anterior = nodo->anterior;
    }
    
    posicion.pos = NULL; // Vaciar la posición
    delete nodo;
    return true;
}

// Obtiene el elemento que ocupa la posición indicada
TPoro TListaPoro::Obtener(const TListaPosicion &posicion) const {
    if (posicion.EsVacia()) {
        TPoro vacio;
        return vacio;
    }
    return posicion.pos->e;
}

// Devuelve true si el elemento está en la lista, false en caso contrario
bool TListaPoro::Buscar(const TPoro &elemento) const{
    TListaNodo *actual = primero;
    while (actual != NULL) {
        if (actual->e == elemento) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// Devuelve la longitud de la lista
int TListaPoro::Longitud() const{
    int count = 0;
    TListaNodo *actual = primero;
    while (actual != NULL) {
        count++;
        actual = actual->siguiente;
    }
    return count;
}

// Devuelve la primera posición en la lista
TListaPosicion TListaPoro::Primera() const {
    TListaPosicion pos;
    pos.pos = primero;
    return pos;
}

// Devuelve la última posición en la lista
TListaPosicion TListaPoro::Ultima() const{
    TListaPosicion pos;
    pos.pos = ultimo;
    return pos;
}

// Extraer un rango de nodos de la lista
TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {
    TListaPoro resultado;
    
    // Validar parámetros
    if (n1 > n2) {
        return resultado; // Lista vacía
    }
    
    // Ajustar límites
    if (n1 <= 0) n1 = 1;
    int longitud = Longitud();
    if (n2 > longitud) n2 = longitud;
    
    // Si la lista está vacía o no hay elementos en el rango
    if (longitud == 0 || n1 > longitud) {
        return resultado;
    }
    
    // Encontrar el nodo inicial (posición n1)
    TListaNodo *nodoInicio = primero;
    for (int i = 1; i < n1 && nodoInicio != NULL; i++) {
        nodoInicio = nodoInicio->siguiente;
    }
    
    // Encontrar el nodo final (posición n2)
    TListaNodo *nodoFin = nodoInicio;
    for (int i = n1; i < n2 && nodoFin != NULL; i++) {
        nodoFin = nodoFin->siguiente;
    }
    
    // Si no encontramos los nodos, retornar lista vacía
    if (nodoInicio == NULL) {
        return resultado;
    }
    
    // Extraer los elementos y agregarlos al resultado
    TListaNodo *actual = nodoInicio;
    while (actual != NULL && actual != nodoFin->siguiente) {
        resultado.Insertar(actual->e);
        TListaNodo *siguiente = actual->siguiente;
        
        // Eliminar el nodo de la lista original
        if (actual == primero && actual == ultimo) {
            // Único elemento
            primero = ultimo = NULL;
        } else if (actual == primero) {
            // Primer elemento
            primero = actual->siguiente;
            primero->anterior = NULL;
        } else if (actual == ultimo) {
            // Último elemento
            ultimo = actual->anterior;
            ultimo->siguiente = NULL;
        } else {
            // Elemento intermedio
            actual->anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = actual->anterior;
        }
        
        delete actual;
        actual = siguiente;
    }
    
    return resultado;
}

// Sobrecarga del operador salida
ostream & operator<<(ostream &os, const TListaPoro &lista) {
    os << "(";
    
    TListaNodo *actual = lista.primero;
    bool primero = true;
    
    while (actual != NULL) {
        if (!primero) {
            os << " ";
        }
        os << actual->e;
        primero = false;
        actual = actual->siguiente;
    }
    
    os << ")";
    return os;
}