#define CATCH_CONFIG_MAIN // defines main() automatically
#include "catch.hpp"
#include "CLL.hpp"
#include "CLLNode.hpp"
// tests for exercise 1

TEST_CASE("Ex1 ", "[Test 1]")
{
	CLL<int> cll;
	cll.addtoTail(4);
	cll.addtoTail(5);
	cll.addtoTail(6);
	CLLNode<int> *ptr = cll.getTail();
	while(1){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
		if (ptr == cll.getTail()) break;
	}
	cout << endl;
	REQUIRE(cll.getTail()->getData() == 6);
	REQUIRE(cll.getTail()->getNext()->getData() == 4);
	REQUIRE(cll.getTail()->getNext()->getNext()->getData() == 5);
}

TEST_CASE("Ex2 ", "[Delete Test 2]"){
	CLL<int> cll;
	cll.addtoTail(4);
	cll.addtoTail(5);
	cll.addtoTail(6);
	CLLNode<int> *ptr = cll.getTail();
	while(1){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
		if (ptr == cll.getTail()) break;
	}
	cout << endl;
	cll.deleteNode(4);
	ptr = cll.getTail();
	while(1){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
		if (ptr == cll.getTail()) break;
	}
	cout << endl;
	REQUIRE(cll.getTail()->getData() == 6);
	REQUIRE(cll.getTail()->getNext()->getData() == 5);

	cll.deleteNode(6);
	INFO("6 should be deleted. Head and Tail should be 5");
	REQUIRE(cll.getTail()->getData() == 5);
	REQUIRE(cll.getTail()->getNext()->getData() == 5);
	ptr = cll.getTail();
	while(1){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
		if (ptr == cll.getTail()) break;
	}
	cout << endl;

	cll.deleteNode(5);
	REQUIRE(cll.getTail() == nullptr);
	REQUIRE(cll.isEmpty() == 1);
}
TEST_CASE("Ex3 ", "[Destructor Test 3]"){
	CLL<int> cll;
	cll.addtoTail(4);
	cll.addtoTail(5);
	cll.addtoTail(6);
	REQUIRE(cll.getTail()->getData() == 6);  
	cll.~CLL();
	INFO("All nodes should be deleted");
	REQUIRE(cll.getTail() == nullptr);
}