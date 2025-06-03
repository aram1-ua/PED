#include "tvectorporo.h"

// Constructor por defecto
TVectorPoro::TVectorPoro() {
    dimension = 0;
    datos = NULL;
}

// Constructor a partir de una dimensión
TVectorPoro::TVectorPoro(int dim) {
    if (dim <= 0) {
        dimension = 0;
        datos = NULL;
    } else {
        dimension = dim;
        datos = new TPoro[dimension];
    }
}

// Constructor de copia
TVectorPoro::TVectorPoro(TVectorPoro &otro) {
    dimension = otro.dimension;
    if (dimension > 0) {
        datos = new TPoro[dimension];
        for (int i = 0; i < dimension; i++) {
            datos[i] = otro.datos[i];
        }
    } else {
        datos = NULL;
    }
}

// Destructor
TVectorPoro::~TVectorPoro() {
    if (datos != NULL) {
        delete[] datos;
        datos = NULL;
    }
    dimension = 0;
}

// Sobrecarga del operador asignación
TVectorPoro & TVectorPoro::operator=(TVectorPoro &otro) {
    if (this != &otro) {
        // Liberar memoria actual
        if (datos != NULL) {
            delete[] datos;
            datos = NULL;
        }
        
        dimension = otro.dimension;
        if (dimension > 0) {
            datos = new TPoro[dimension];
            for (int i = 0; i < dimension; i++) {
                datos[i] = otro.datos[i];
            }
        } else {
            datos = NULL;
        }
    }
    return *this;
}

// Sobrecarga del operador igualdad
bool TVectorPoro::operator==(TVectorPoro &otro) {
    if (dimension != otro.dimension) {
        return false;
    }
    
    for (int i = 0; i < dimension; i++) {
        if (datos[i] != otro.datos[i]) {
            return false;
        }
    }
    
    return true;
}

// Sobrecarga del operador desigualdad
bool TVectorPoro::operator!=(TVectorPoro &otro) {
    return !(*this == otro);
}

// Sobrecarga del operador corchete (parte IZQUIERDA)
TPoro & TVectorPoro::operator[](int pos) {
    if (pos >= 1 && pos <= dimension) {
        return datos[pos - 1];  // Convertir de base 1 a base 0
    }
    return error;  // Devolver referencia al objeto error
}

// Sobrecarga del operador corchete (parte DERECHA)
TPoro TVectorPoro::operator[](int pos) const {
    if (pos >= 1 && pos <= dimension) {
        return datos[pos - 1];  // Convertir de base 1 a base 0
    }
    TPoro vacio;
    return vacio;  // Devolver objeto vacío
}

// Devuelve la longitud (dimensión) del vector
int TVectorPoro::Longitud() {
    return dimension;
}

// Devuelve la cantidad de posiciones ocupadas (no vacías) en el vector
int TVectorPoro::Cantidad() {
    int count = 0;
    for (int i = 0; i < dimension; i++) {
        if (!datos[i].EsVacio()) {
            count++;
        }
    }
    return count;
}

// REDIMENSIONAR el vector de TPoro
bool TVectorPoro::Redimensionar(int nuevaDim) {
    if (nuevaDim <= 0 || nuevaDim == dimension) {
        return false;
    }
    
    TPoro *nuevosDatos = new TPoro[nuevaDim];
    
    // Copiar elementos existentes
    int elementosACopiar = (nuevaDim < dimension) ? nuevaDim : dimension;
    for (int i = 0; i < elementosACopiar; i++) {
        nuevosDatos[i] = datos[i];
    }
    
    // Liberar memoria anterior
    if (datos != NULL) {
        delete[] datos;
    }
    
    datos = nuevosDatos;
    dimension = nuevaDim;
    
    return true;
}

// Sobrecarga del operador salida
ostream & operator<<(ostream &os, TVectorPoro &vector) {
    os << "[";
    for (int i = 0; i < vector.dimension; i++) {
        if (i > 0) os << " ";
        os << (i + 1) << " " << vector.datos[i];
    }
    os << "]";
    return os;
}