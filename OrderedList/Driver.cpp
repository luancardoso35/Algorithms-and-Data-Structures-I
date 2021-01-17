#include <iostream>
#include "OList.h"
using namespace std;

int main() {
	OList l;
	l.insert(1);
	l.insert(2);
	l.insert(4);
	l.insert(5);
	l.insert(3);
	l.toString();

	l.remove(3);
	l.remove(4);
	l.toString();

	cout << l.search(5) <<endl;
	return 0;
}
