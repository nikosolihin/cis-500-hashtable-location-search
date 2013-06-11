#ifndef STRBST_H
#define STRBST_H

#include <iostream>
#include <string>

using namespace std;

class StrBST
{
    public:
		StrBST ();
		bool isEmpty () const;
		bool contains (const string x) const;
		string findMax () const;
		string findMin () const;
		void insert (const string x);
		void remove (string & x);
		void printTree (ostream & out) const;
        int count() const;

	private:
		struct Node {
			string elem;
			Node * left, * right;

			Node (const string x) {
				elem = x;
				left = right = NULL;
			}
		};

		Node * root;

		bool contains (const string x, Node * t) const;
		Node * findMax (Node * t) const;
		Node * findMin (Node * t) const;
		void insert (const string x, Node * & t);
		void remove (string & x, Node * & t);
		void printTree (Node * t, ostream & out) const;
        int count (Node * t) const;
};

#endif