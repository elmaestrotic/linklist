//
// Created by Windows on 21/07/2025.
//

#ifndef LINKLISTAS_NODO_H
#define LINKLISTAS_NODO_H


class Nodo {
private:
    int data;
    Nodo* link;
public:
    Nodo(int data, Nodo* link= nullptr);


    int getData() const;

    Nodo* getLink() const;

    void setLink(Nodo* link);
};


#endif //LINKLISTAS_NODO_H
