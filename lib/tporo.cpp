#include "tporo.h"

// Constructor por defecto
TPoro::TPoro() {
    x = 0;
    y = 0;
    volumen = 0.0;
    color = NULL;
}

// Constructor a partir de una posición y un volumen
TPoro::TPoro(int px, int py, double vol) {
    x = px;
    y = py;
    volumen = vol;
    color = NULL;
}

// Constructor a partir de una posición, un volumen y un color
TPoro::TPoro(int px, int py, double vol, char *col) {
    x = px;
    y = py;
    volumen = vol;
    
    if (col != NULL) {
        color = new char[strlen(col) + 1];
        strcpy(color, col);
        // Convertir a minúsculas
        for (int i = 0; color[i]; i++) {
            color[i] = tolower(color[i]);
        }
    } else {
        color = NULL;
    }
}

// Constructor de copia
TPoro::TPoro(TPoro &otro) {
    x = otro.x;
    y = otro.y;
    volumen = otro.volumen;
    
    if (otro.color != NULL) {
        color = new char[strlen(otro.color) + 1];
        strcpy(color, otro.color);
    } else {
        color = NULL;
    }
}

// Destructor
TPoro::~TPoro() {
    if (color != NULL) {
        delete[] color;
        color = NULL;
    }
    x = 0;
    y = 0;
    volumen = 0.0;
}

// Sobrecarga del operador asignación
TPoro & TPoro::operator=(TPoro &otro) {
    if (this != &otro) {
        // Liberar memoria previa
        if (color != NULL) {
            delete[] color;
            color = NULL;
        }
        
        x = otro.x;
        y = otro.y;
        volumen = otro.volumen;
        
        if (otro.color != NULL) {
            color = new char[strlen(otro.color) + 1];
            strcpy(color, otro.color);
        } else {
            color = NULL;
        }
    }
    return *this;
}

// Sobrecarga del operador igualdad
bool TPoro::operator==(TPoro &otro) {
    if (x != otro.x || y != otro.y || volumen != otro.volumen) {
        return false;
    }
    
    if (color == NULL && otro.color == NULL) {
        return true;
    }
    
    if (color == NULL || otro.color == NULL) {
        return false;
    }
    
    return strcmp(color, otro.color) == 0;
}

// Sobrecarga del operador desigualdad
bool TPoro::operator!=(TPoro &otro) {
    return !(*this == otro);
}

// Modifica la posición
void TPoro::Posicion(int px, int py) {
    x = px;
    y = py;
}

// Modifica el volumen
void TPoro::Volumen(double vol) {
    volumen = vol;
}

// Modifica el color
void TPoro::Color(const char *col) {
    if (color != NULL) {
        delete[] color;
        color = NULL;
    }
    
    if (col != NULL) {
        color = new char[strlen(col) + 1];
        strcpy(color, col);  // ← AGREGADO: faltaba copiar la cadena
        // Convertir a minúsculas
        for (int i = 0; color[i]; i++) {
            color[i] = tolower(color[i]);
        }
    }
}

// Devuelve la coordenada x de la posición
int TPoro::PosicionX() {
    return x;
}

// Devuelve la coordenada y de la posición
int TPoro::PosicionY() {
    return y;
}

// Devuelve el volumen
double TPoro::Volumen() {
    return volumen;
}

// Devuelve el color
char * TPoro::Color() {
    return color;
}

// Devuelve cierto si el poro está vacío
bool TPoro::EsVacio() {
    return (x == 0 && y == 0 && volumen == 0.0 && color == NULL);
}

// Sobrecarga del operador SALIDA
ostream & operator<<(ostream &os, TPoro &poro) {
    if (!poro.EsVacio()) {
        os.setf(ios::fixed);
        os.precision(2);
        os << "(" << poro.x << ", " << poro.y << ") " << poro.volumen << " ";
        if (poro.color != NULL)
            os << poro.color;
        else
            os << "-";
    } else {
        os << "()";
    }
    return os;
}