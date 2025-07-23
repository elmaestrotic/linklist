//
// Created by Windows on 21/07/2025.
//

#include "Nodo.h"

Nodo::Nodo(int data, Nodo *link)
        : data(data), link(link) {}

int Nodo::getData() const {
    return data;
}


// Devuelve el puntero al siguiente nodo
Nodo *Nodo::getLink() const  {
    return link;
}

// Cambia el puntero al siguiente nodo
void Nodo::setLink(Nodo *link) {
    this->link = link;
}