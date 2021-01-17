#include <iostream>
#include "Deque.h"
using namespace std;

int main()
{
    Deque a;
    DequeEntry x;
    a.appendAtRear(10);
    cout <<a.toString() <<endl;
    a.serveAtFront(x);
    cout <<a.toString() <<endl;
    return 0;
}
