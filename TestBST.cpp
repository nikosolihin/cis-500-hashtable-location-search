#include <iostream>
#include <fstream>
#include <string>

#include "StrBST.h"
#include "StrBST.cpp"

using namespace std;

int main () {
	StrBST tree;

	string s1("abc"), s2("xyz"), s3("nop"),
		   s4("ddd"), s5("mno");

	tree.insert(s1);
	tree.insert(s2);

	string s6;
	cout << "enter a string\n";
	getline(cin, s6);

	if (!tree.contains(s6))
		tree.insert(s6);

	tree.insert(s3);
	tree.insert(s4);
	tree.insert(s5);
	
	tree.printTree(cout);

	cout << "\nthe largest is " << tree.findMax() << endl;
	cout << "the smallest is " << tree.findMin() << endl;

	return 0;
}