#include <iostream>
using namespace std;
typedef int QueueEntry;

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
	struct QueueNode;
	typedef QueueNode * QueuePointer;
	struct QueueNode {
		QueueEntry entry;
		QueuePointer nextNode;
	};
	QueuePointer head, tail;
	int count;
public:
	Queue();
	~Queue();
	bool empty();
	bool full();
	void append(QueueEntry x);
	void serve(QueueEntry &x);
	int size();
	void clear();
	void front(QueueEntry &x);
	void rear(QueueEntry &x);
	void toString();
};

#endif
