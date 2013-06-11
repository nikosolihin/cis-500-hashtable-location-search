#include "StrBST.h"

StrBST::StrBST () {
	root = NULL;
}

bool StrBST::isEmpty () const {
	return root == NULL;
}

bool StrBST::contains (const string x) const {
	return contains (x, root);
}

string StrBST::findMax () const {
	Node * temp = findMax (root);
	if ( temp != NULL )
		return temp->elem;
	return "";
}

string StrBST::findMin () const {
	Node * temp = findMin (root);
	if ( temp != NULL )
		return temp->elem;
	return "";
}

void StrBST::insert (const string x) {
	insert (x, root);
}

void StrBST::remove (string & x) {
	remove (x, root);
}

void StrBST::printTree (ostream & out) const {
	if ( isEmpty() )
		out << "Empty Tree" << endl;
	else
		printTree (root, out);
}

bool StrBST::contains (const string x, Node * t) const {
	if (t == NULL)
		return false;
	else if (x < t->elem)
		return contains (x, t->left);
	else if (t->elem < x)
		return contains (x, t->right);
	else
		return true;
}

StrBST::Node * StrBST::findMax (Node * t) const {
	if ( t != NULL )
		while ( t->right != NULL )
			t = t->right;
	return t;
}

StrBST::Node * StrBST::findMin (Node * t) const {
	if ( t == NULL )
		return NULL;
	if ( t->left == NULL )
		return t;
	return findMin (t->left);
}

void StrBST::insert (const string x, Node * & t) {
	if ( t == NULL )
		t = new Node(x);
	else if ( x < t->elem )
		insert (x, t->left);
	else if ( x > t->elem )
		insert (x, t->right);
	else
		;	// duplicte; do nothing
}

void StrBST::remove (string & x, Node * & t) {
	// to be defined
}

void StrBST::printTree (Node * t, ostream & out) const {
	if ( t != NULL )
	{
		out << t->elem << endl;
		printTree (t->left, out);
		printTree (t->right, out);
	}
}

int StrBST::count() const {
    return count (root);
}

int StrBST::count(Node *t) const {
    if ( t == NULL ) {
        return 0;                   
    } else {
        int count = 1;              
        count += count(t->left);    
        count += count(t->right);   
        return count;
    }
}