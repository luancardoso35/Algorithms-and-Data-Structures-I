//Luan Cesar Cardoso - No USP 11340272
/*
 * Deque.h
 *
 *  Created on:
 *      Author:
 */

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef int DequeEntry; // tipo de dado colocado no Deque

class Deque
{ public:
    Deque();
    ~Deque();
    bool empty();
    bool full();
    void clear();
    void front(DequeEntry &x);
    void rear(DequeEntry &x);
    int  size();

    void appendAtRear(DequeEntry x);
    void serveAtFront(DequeEntry &x);

    void appendAtFront(DequeEntry x);
    void serveAtRear(DequeEntry &x);
    string toString();

  private:
    // Defina aqui os campos do objeto
    struct DequeNode;
    typedef DequeNode * DequePointer;
    struct DequeNode {
        DequeEntry entry;
        DequePointer nextNode;
    };
    void setPosition(int p, DequePointer &current);

    DequePointer head, tail;
    int count;
};

#endif /* DEQUE_H */

