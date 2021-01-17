#include "Stack2.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Stack2::Stack2() {
	topo = NULL;
	count = 0;
}

Stack2::~Stack2() {
	clear();
}

bool Stack2::empty() {
	return (topo == NULL);
}

bool Stack2::full() {
	return false;
}

void Stack2::push(StackEntry x) {
	StackPointer p;
	p = new StackNode;
	if (p == NULL) {
		cout << "Memória Insuficiente" << endl;
		abort();
	}

	p->entry = x;
	p->nextNode = topo;
	topo = p;
	count++;
}

void Stack2::pop(StackEntry &x) {
	if (empty()) {
		cout << "Pilha Vazia" << endl;
		abort();
	}
	StackPointer p;
	p = topo;
	topo = topo->nextNode;
	x = p->entry;
	delete p;
	count--;
}

int Stack2::size() {
	return count;
}

void Stack2::clear() {
	StackPointer p;
	while (topo != NULL) {
		p = topo;
		topo = topo->nextNode;
		delete p;
	}
	count = 0;
}

void Stack2::top (StackEntry &x) {
	if (empty()) {
		cout << "Pilha vazia" << endl;
		abort();
	}
	x = topo->entry;
}

void Stack2::toString() {
	stringstream ss;
	StackPointer p;
	p = topo;
	while (p != NULL) {
		ss << (p->entry);
		if (p != NULL)
			ss << ", ";
		p = p->nextNode;
	}
	cout << ss.str() << endl;
}
