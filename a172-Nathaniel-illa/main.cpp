#include "CLL.hpp"
#include "CLLNode.hpp"
#include <iostream>
using namespace std;

template <class T>
void printCLL(CLL<T> &cll);

int main()
{
	CLL<int> cll;
	cll.addtoTail(4);		// test: add to tail
	cll.addtoTail(5);		// test: add to tail
	cll.addtoTail(6);		// test: add to tail
	printCLL(cll);			//  1 2 3 4 5 6
	cll.deleteNode(4);		// test: delete middle
	printCLL(cll);			//  1 2 4 5 6
	cll.deleteNode(6);		// test: delete tail
	printCLL(cll);			//  1 2 4 5
	cll.deleteNode(5);		// test: delete tail
	printCLL(cll);			//  1 2 4
}

template <class T>
void printCLL(CLL<T> &cll){
	CLLNode<T> *ptr;
	if (cll.isEmpty()) return;
	ptr = cll.getTail();
	while (1){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
		if (ptr == cll.getTail()) break;
	}
	cout << endl;
}