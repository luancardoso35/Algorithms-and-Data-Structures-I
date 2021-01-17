#include <iostream>
#include "List.h"
using namespace std;

int main() {
	List l;
	ListEntry x;
	l.insert(1, 4);
	l.insert(1, 3);
	l.insert(1, 2);
	l.insert(1, 1);
	l.toString();

	l.remove(3, x);
	l.replace(1, 0);
	l.retrieve(1, x);
	l.toString();
	cout << l.search(4)<< endl;

	return 0;
}
