#include <iostream>
#include "List.h"
#include <sstream>
using namespace std;

List::List() {
	count = 0;
	head = NULL;
}

List::~List() {
	clear();
}

bool List::empty() {
	return (count == 0);
}

bool List::full() {
	return false;
}

void List::setPosition(int p, ListPointer &current) {
	current = head;
	int i = 1;
	while (i < p) {
		current = current->nextNode;
		i++;
	}
}

void List::insert(int p, ListEntry x) {
	if (p < 1 || p > count + 1) {
		cout << "Posição inválida" <<endl;
		abort();
	}
	ListPointer q, current;
	q = new ListNode();
	if (q == NULL) {
		cout << "Memória insuficiente" << endl;
		abort();
	}

	q->entry = x;
	if (p == 1) {
		q->nextNode = head;
		head = q;
	} else {
		setPosition(p - 1, current);
		q->nextNode = current->nextNode;
		current->nextNode = q;
	}
	count++;
}

void List::remove(int p, ListEntry &x) {
	if (empty()) {
		cout << "Lista vazia" << endl;
		abort();
	}
	if (p < 1 || p > count) {
		cout << "Posição inválida" <<endl;
		abort();
	}

	ListPointer q, current;
	if (p == 1) {
		q = head;
		head = q->nextNode;
	} else {
		setPosition(p - 1, current);
		q = current->nextNode;
		current->nextNode = q->nextNode;
	}
	x = q->entry;
	delete q;
	count--;
}

void List::replace(int p, ListEntry x) {
	if (empty()) {
		cout << "Lista vazia" << endl;
		abort();
	}
	if (p < 1 || p > count) {
		cout << "Posição inválida" <<endl;
		abort();
	}
	ListPointer current;
	setPosition(p, current);
	current->entry = x;
}

void List::retrieve(int p, ListEntry &x) {
	if (empty()) {
		cout << "Lista vazia" << endl;
		abort();
	}
	if (p < 1 || p > count) {
		cout << "Posição inválida" <<endl;
		abort();
	}
	ListPointer current;
	setPosition(p, current);
	x = current->entry;
}

int List::size() {
	return count;
}

void List::clear() {
	ListPointer p;
	while (head != NULL) {
		p = head;
		head = head->nextNode;
		delete p;
	}
	count = 0;
}

void List::toString() {
	stringstream ss;
	ListPointer p;
	p = head;
	while (p != NULL) {
		ss << p->entry;
		if (p->nextNode != NULL) {
			ss << " ";
		}
		p = p->nextNode;
	}

	cout << ss.str() <<endl;
}

int List::search(ListEntry x) {
	ListPointer p;
	p = head;
	int contador = 1;

	while (p->entry != x && p != NULL) {
		p = p->nextNode;
		contador++;
	}
	return (p == NULL ? 0 : contador);
}
