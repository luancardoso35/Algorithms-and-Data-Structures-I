#include <iostream>
#include <sstream>
#include "Queue.h"
using namespace std;

Queue::Queue() {
	count = 0;
	head = NULL;
	tail = NULL;
}

Queue::~Queue() {
	clear();
}

bool Queue::empty() {
	return (count == 0);
}

bool Queue::full() {
	return false;
}

void Queue::append(QueueEntry x) {
	QueuePointer p;
	p = new QueueNode;
	if (p == NULL) {
		cout << "Fila cheia" <<endl;
		abort();
	}
	p->entry = x;
	p->nextNode = NULL;
	if (empty()) {
		head = tail = p;
	} else {
		tail->nextNode = p;
		tail = p;
	}
	count++;
}

void Queue::serve(QueueEntry &x) {
	if (empty()) {
		cout << "Fila vazia" <<endl;
		abort();
	}
	QueuePointer p;
	p = head;
	x = head->entry;
	head = head->nextNode;
	delete p;

	if (head == NULL) {
			tail = NULL;
		}

	count--;
}

int Queue::size() {
	return count;
}

void Queue::clear() {
	QueuePointer p;
	while (head != NULL) {
		p = head;
		head = head->nextNode;
		delete p;
	}
	tail = NULL;
	count = 0;
}

void Queue::front(QueueEntry &x) {
	if (empty()) {
		cout << "Fila vazia" << endl;
		abort();
	}
	x = head->entry;
}

void Queue::rear(QueueEntry &x) {
	if (empty()) {
			cout << "Fila vazia" << endl;
			abort();
	}
	x = tail->entry;
}

void Queue::toString() {
	stringstream ss;

	QueuePointer p;
	p = head;
	while (p != NULL) {
		ss << p->entry;
		if (p->nextNode != NULL)
			ss << " ";
		p = p->nextNode;
	}

	cout << ss.str() << endl;
}
