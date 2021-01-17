//Luan Cesar Cardoso - No USP 11340272
/*
 * Deque.cpp
 *
 *  Created on:
 *      Author:
 */
#include "Deque.h"
#include <sstream>

// pre: nenhuma
// pos: Deque criado vazio (sem elementos)
// Pior caso O(1) - nro constante (3) de operacoes
Deque::Deque()
{
    count = 0;
    head = NULL;
    tail = NULL;
}

// pre: Deque criado
// pos: Deque eh destruido, liberando espa�o ocupado pelos seus elementos
// Pior caso O(n) - o metodo clear, invocado pelo finalizador, eh O(n)
Deque::~Deque()
{
    clear();
}

// pre: Deque criado
// pos: retorna true se o deque esta vazio; false caso contrario
// Pior caso O(1) - nro constante de operacoes para todos os casos
bool Deque::empty()
{
    return (count == 0);
}

// pre: Deque criado
// pos: retorna true se o deque esta cheio; false caso contrario
// Pior caso O(1) - nro constante de operacoes para todos os casos
bool Deque::full()
{
    return false;
}

// pre: Deque nao estah cheio
// pos: O item x eh armazenado no inicio do deque
// Pior caso O(1) - no pior caso, os ponteiros tail e head apontarao para o novo elemento
// e um nro constante de operacoes serah feito
void Deque::appendAtFront(DequeEntry x)
{
    DequePointer d;
    d = new DequeNode;
    if (d == NULL) {
        cout << "Memória insuficiente" << endl;
        abort();
    }

    d->entry = x;
    d->nextNode = head;
    head = d;
    if (size() == 0) {
        tail = d;
    }
    count++;
}

// pre: Deque nao estah cheio
// pos: O item x eh armazenado no final do deque
// Pior caso O(1) - no pior caso, um nro constante de operacoes serah feito
void Deque::appendAtRear(DequeEntry x)
{
    DequePointer d;
    d = new DequeNode;
    if (d == NULL) {
        cout << "Memoria insuficiente" << endl;
        abort();
    }
    d->entry = x;

    d->nextNode = NULL;
    if (size() == 0) {
        head = d;
    } else {
        tail->nextNode = d;
    }
    tail = d;
    count++;
}

// pre: Deque nao vazio
// pos: O item do inicio do deque eh removido e seu valor eh retornado na variavel x
// Pior caso O(1) - no pior caso, apenas serah deletado um Node da lista, alem de passar o ponteiro
//head para o proximo elemento. Mas mesmo assim, serah feito um nro constante de operacoes
void Deque::serveAtFront(DequeEntry &x)
{
    if (empty()) {
        cout << "Deque vazio" <<endl;
        abort();
    }
    DequePointer d = head;
    head = head->nextNode;
    x = d->entry;
    delete d;
    count--;
}

// pre: Deque nao vazio
// pos: O item do final do deque eh removido e seu valor eh retornado na variavel x
// Pior caso O(n) - visto que o metodo setPosition eh O(n) no pior caso (p == count), se
// ele for chamado na posicao count, ele percorrera count - 1 elementos da lista, e assim,
// o metodo serveAtRear tambem sera O(n)
void Deque::serveAtRear(DequeEntry &x)
{
    if (empty()) {
        cout << "Deque vazio" <<endl;
        abort();
    }
    x = tail->entry;
    DequePointer d;
    if (count > 1) {
        setPosition(size() - 1, d);
        d->nextNode = NULL;
        delete tail;
        tail = d;
    } else if (count == 1) {
        d = head;
        head = NULL;
        tail = NULL;
        delete d;
    }
    count--;
}

// pre: Deque criado
// pos: Todos os itens do deque sao descartados e ele se torna um deque vazio
// Pior caso O(n) - percorrerah todos os elementos da lista, se existirem
void Deque::clear()
{
    DequePointer d;
    while (head != NULL) {
        d = head;
        head = head->nextNode;
        delete d;
    }
    tail = NULL;
    count = 0;
}

// pre: deque nao estah vazio
// pos:  x recebe uma copia do item que se encontra no inicio do deque; o deque permanece inalterado
// Pior caso O(1) - farah um numero constante de operacoes
void Deque::front(DequeEntry &x)
{
    if (empty()) {
        cout << "Deque vazio" <<endl;
        abort();
    }
    x = head->entry;
}

// pre: deque nao estah vazia
// pos:  x recebe uma copia do item que se encontra no final do deque; o deque permanece inalterado
// Pior caso O(1) - nro constante de operacoes
void Deque::rear(DequeEntry &x)
{
    if (empty()) {
        cout << "Deque vazio" <<endl;
        abort();
    }
    x = tail->entry;
}

// pre: Deque criado
// pos: retorna o numero de itens no deque
// Pior caso O(1) - nro constante de operacoes
int Deque::size()
{
    return count;
}

// pre: Deque criado
// pos: retorna o deque como string, um elemento apos o outro, iniciando pelo comeco do deque
//      Os elementos sao separados por um unico espaco e nao deve haver espacos adicionais no
//      inicio nem no final da string retornada
// Pior caso O(n) - para adicionar todos os elementos da lista na string, o metodo terah que
// percorrer toda ela, sendo assim O(n)
string Deque::toString()
{
    stringstream ss;
    DequePointer d = head;

    while (d != NULL) {
        ss << d->entry;
        if (d->nextNode != NULL) {
            ss << " ";
        }
        d = d->nextNode;
    }

    return ss.str();
}

// pre: o nro p esteja entre 1 e count, e o ponteiro current exista
// pos: o ponteiro current apontarah pro elemento numero p da lista
// Pior caso O(n) - para o pior caso, o nro de operacoes serah proporcional a count, que
// indica o tamanho da lista. Assim, no pior caso, o metodo tera nro de operacoes proporcional
// ao tamanho da lista, sendo assim O(n)
void Deque::setPosition(int p, DequePointer &current) {
    if (p < 1 || p > count) {
        abort();
    }
    current = head;
    for (int i = 1; i < p; i++) {
        current = current->nextNode;
    }
}
