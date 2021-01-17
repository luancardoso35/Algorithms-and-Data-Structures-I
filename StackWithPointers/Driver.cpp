#include "Stack2.h"
#include <iostream>
using namespace std;

int main() {
Stack2 pilha;
pilha.push(1);
pilha.push(3);
pilha.toString();

StackEntry x;
pilha.pop(x);
cout << "x = " << x << endl;

pilha.toString();
pilha.push(10);
pilha.top(x);
cout << "x = " << x << endl;
cout << pilha.size() << endl;

return 0;
}
