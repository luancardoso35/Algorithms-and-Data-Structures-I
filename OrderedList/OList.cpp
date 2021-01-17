#include <iostream>
#include "OList.h"
#include <sstream>
using namespace std;

OList::OList() {
	sentinel = new ListNode;
	head = sentinel;
	count = 0;
}

OList::~OList() {
	clear();
	delete head;
}

bool OList::empty() {
	return (count == 0);
}

bool OList::full() {
	return false;
}

void OList::insert(ListEntry x) {
	sentinel->entry = x;
	ListPointer p, q;
	q = head;

	while (q->entry < x) {
		q = q->nextNode;
	}

	p = new ListNode;
	if (p == NULL) {
		cout << "Memória insuficiente" <<endl;
		abort();
	}

	if (q == sentinel) {
		sentinel->nextNode = p;
		sentinel = p;
	} else {
		*p = *q;
		q->entry = x;
		q->nextNode = p;
	}
	count++;
}

void OList::remove(ListEntry x) {
	if (empty()) {
		cout << "Lista vazia" <<endl;
		abort();
	}
	sentinel->entry = x;
	ListPointer q, p;
	q = NULL;
	p = head;
	while (p->entry != x) {
		q = p;
		p = p->nextNode;
	}

	if (p != sentinel) {
		if (p == head) {
			head = p->nextNode;
		} else {
			q->nextNode = p->nextNode;
		}
		delete p;
		count--;
	}
}

int OList::size() {
	return count;
}

void OList::clear() {
	ListPointer p = head;
	while (head != sentinel) {
		p = head;
		head = head->nextNode;
		delete p;
	}
	count = 0;
}

int OList::search(ListEntry x) {
	if (empty()) {
		cout << "Lista Vazia" << endl;
		abort();
	}
	sentinel->entry = x;
	int contador = 1;
	ListPointer p = head;
	while (p->entry != x) {
		p = p->nextNode;
		contador++;
	}

	return (p == sentinel ? 0 : contador);
}

void OList::toString() {
	stringstream ss;
	ListPointer p = head;
	while (p != sentinel) {
		ss << p->entry;
		if (p->nextNode != sentinel) {
			ss << " ";
		}
		p = p->nextNode;
	}

	cout << ss.str() <<endl;
}
