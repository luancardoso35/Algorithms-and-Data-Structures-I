#include <iostream>
using namespace std;
typedef int StackEntry;

#ifndef STACK_H
#define STACK_H

class Stack2 {
private:
	struct StackNode;
	typedef StackNode * StackPointer;
	struct StackNode {
		StackEntry entry;
		StackPointer nextNode;
	};
	int count;
	StackPointer topo;

public:
	Stack2();
	~Stack2();
	bool empty();
	bool full();
	void push(StackEntry x);
	void pop(StackEntry &x);
	int size();
	void clear();
	void top(StackEntry &x);
	void toString();
};

#endif

