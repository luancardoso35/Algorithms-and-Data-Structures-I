#include <iostream>
using namespace std;

typedef int ListEntry;

#ifndef LIST_H
#define LIST_H

class List {
private:
	struct ListNode;
	typedef ListNode * ListPointer;
	struct ListNode {
		ListEntry entry;
		ListPointer nextNode;
	};
	ListPointer head;
	int count;
public:
	List();
	~List();
	bool empty();
	bool full();
	void insert(int p, ListEntry x);
	void remove(int p, ListEntry &x);
	void replace(int p, ListEntry x);
	void retrieve(int p, ListEntry &x);
	void clear();
	int size();
	void setPosition(int p, ListPointer &current);
	void toString();
	int search(ListEntry x);
};

#endif
