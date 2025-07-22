//
// Created by Windows on 21/07/2025.
//

#ifndef LINKLISTAS_LISTA_H
#define LINKLISTAS_LISTA_H

#include "Nodo.h"

class Lista {
private:
    Nodo* primero;
public:
    Lista();
    void crearLista();
    void insertarCabeza(int valor);
    void insertarFinal(int valor);
    void insertarDespues(Nodo* anterior, int valor);
    Nodo* buscar(int valor);
    void visualizar();
    void eliminar(int valor);
    Nodo* getUltimo();
};

#endif


