#include <stdio.h>
#include <iostream>

#include "Key.hpp"
#include "SkipList.hpp"

using namespace std;

int main()
{

	//Key myKey ("mystring");
	
	//cout << myKey << endl;


	/*SkipList mySkipListTest (30);
	for (int i = 0; i < 30; i++) {
		cout << mySkipListTest.randHeight() << " ";
	}
	cout << endl;
	
    SkipListNode* a1 = new SkipListNode("A1", 3);
	SkipListNode* a2 = new SkipListNode("A2", 1);
	SkipListNode* c = new SkipListNode("C", 1);
	SkipListNode* e1 = new SkipListNode("E1", 1);
	SkipListNode* e2 = new SkipListNode("E2", 3);
	/*SkipListNode* g = new SkipListNode("G", 1);
	SkipListNode* h = new SkipListNode("H", 2);
	SkipListNode* i = new SkipListNode("I", 1);
	SkipListNode* l = new SkipListNode("L", 4);
	SkipListNode* m = new SkipListNode("M", 1);
	SkipListNode* n = new SkipListNode("N", 3);
	SkipListNode* o = new SkipListNode("O", 1);
	SkipListNode* p = new SkipListNode("P", 1);
	SkipListNode* s = new SkipListNode("S", 5);
	SkipListNode* x = new SkipListNode("X", 1);
	SkipListNode* y = new SkipListNode("Y", 2);

	//cout << "alsnfla  " << a1->Key() << endl;



	SkipList mySkipList (4);
	mySkipList.addToHeadTest(0, a1);
	mySkipList.addToHeadTest(1, a1);
	mySkipList.addToHeadTest(2, a1);

	a1->setNextAtLevel(0, a2);
	a1->setNextAtLevel(1, e2);
	a1->setNextAtLevel(2, e2);

	a2->setNextAtLevel(0, c);

	c->setNextAtLevel(0, e1);

	e1->setNextAtLevel(0, e2);

	mySkipList.add("Testing, B will be added");



	mySkipList.dump();

	SkipListNode* testFind = mySkipList.find(a1, "B", 0);

	cout << "FOUND  " << *testFind << endl;



	SkipListNode* testingNodeA = new SkipListNode("0", 3);
	SkipListNode* testingNodeA1 = new SkipListNode("A1", 1);

	if (*testingNodeA > *testingNodeA1) {
		cout << "0 is greater than A1" << endl;
	} else {
		cout << "0 is not greater than A1" << endl;
	}

	mySkipList.del("B");

	mySkipList.dump();
	SkipListNode* testFind2 = mySkipList.find(a1, "B", 0);

	if (testFind2 == NULL) {
		cout << "its null" << endl;
	}*/

	SkipList mySkipList(10);
	mySkipList.add("B", true);
	mySkipList.add("B", true); // no duplicates
	mySkipList.add("G", true);
	mySkipList.add("T", true);
	mySkipList.add("C", true);
	mySkipList.add("A", true);
	mySkipList.dump();





	




	cout << "\nEND\n" << endl ;
}
