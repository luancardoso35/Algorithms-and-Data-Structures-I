#include <iostream>
using namespace std;

typedef int ListEntry;

class OList {
private:
	struct ListNode;
	typedef ListNode * ListPointer;
	struct ListNode {
		ListEntry entry;
		ListPointer nextNode;
	};
	ListPointer head;
	ListPointer sentinel;
	int count;
public:
	OList();
	~OList();
	bool empty();
	bool full();
	void insert(ListEntry x);
	void remove(ListEntry x);
	int search(ListEntry x);
	void clear();
	int size();
	void toString();
};
