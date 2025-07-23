//
// Created by Alexander Narváez on 21/07/2025.
//

#include "Lista.h"
#include <iostream>
#include "Nodo.h"

using namespace std;

// Constructor: inicializa la lista vacía
Lista::Lista() : head(nullptr) {}

// Crea una lista solicitando valores al usuario hasta que ingrese -1
void Lista::crearLista() {
    int valor;
    cout << "Ingrese valores (-1 para terminar): ";
    while (cin >> valor && valor != -1) {
        insertarCabeza(valor);
    }
}

// Inserta un nodo al inicio de la lista
void Lista::insertarCabeza(int valor) {
    head = new Nodo(valor, head);
}

// Inserta un nodo al final de la lista
void Lista::insertarFinal(int valor) {
    Nodo* nuevo = new Nodo(valor);
    if (!head) {
        head = nuevo;
        return;
    }
    Nodo* ultimo = getUltimo();
    ultimo->setLink(nuevo);
}

// Obtiene el último nodo de la lista
Nodo* Lista::getUltimo() {
    if (!head) {
        throw runtime_error("Lista vacía");
    }
    Nodo* actual = head;
    while (actual->getLink()) {
        actual = actual->getLink();
    }
    return actual;
}

// Inserta un nodo después del nodo especificado
void Lista::insertarDespues(Nodo* anterior, int valor) {
    if (!anterior) {
        throw runtime_error("Nodo anterior no válido");
    }
    Nodo* nuevo = new Nodo(valor, anterior->getLink());
    anterior->setLink(nuevo);
}

// Busca un nodo con el valor especificado
Nodo* Lista::buscar(int valor) {
    for (Nodo* actual = head; actual; actual = actual->getLink()) {
        if (actual->getData() == valor) {
            return actual;
        }
    }
    return nullptr;
}

// Muestra la lista con valores separados por '|'
void Lista::visualizar() {
    if (!primero) {
        std::cout << "Lista vacía\n";
        return;
    }

    int contador = 0;
    for (Nodo* actual = primero; actual; actual = actual->getLink()) {
        // Imprime el dato, no el enlace
        std::cout << actual->getData();

        // Si hay un siguiente, pon separador
        if (actual->getLink()) {
            std::cout << " | ";
        }

        // Salto de línea cada 15 valores (opcional)
        if (++contador % 15 == 0) {
            std::cout << "\n";
        }
    }

    std::cout << "\n";
}

// Elimina un nodo con el valor especificado
void Lista::eliminar(int valor) {
    Nodo* actual = primero;
    Nodo* anterior = nullptr;

    while (actual && actual->getData() != valor) {
        anterior = actual;
        actual = actual->getLink();
    }

    if (!actual) {
        return; // Valor no encontrado
    }

    if (actual == primero) {
        primero = actual->getLink();
    } else {
        anterior->ponerLink(actual->getLink());
    }
    delete actual;
}