#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
	Queue q;
	QueueEntry x;

	q.append(1);
	q.append(2);
	q.append(3);
	q.append(4);
	q.toString();

	q.serve(x);
	cout << "x = " << x <<endl;

	q.front(x);
	cout << "x = " << x <<endl;
	q.rear(x);
	cout << "x = " << x <<endl;

	q.toString();

	q.clear();
	q.toString();

	return 0;
}
