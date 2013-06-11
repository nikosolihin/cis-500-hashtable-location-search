#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTable {
	public:
		HashTable (int size); 
		
		void insert ( const string & x );
		void remove ( const string & x );
		bool contains ( const string & x );

	private:
		int tableSize;
		vector<string> * table;

		int hash (const string & key);
};

HashTable::HashTable (int size) {
	tableSize = size;
	table = new vector<string>[tableSize];
}

int HashTable::hash (const string & key) {
	int hashval = 0;
	for (int i = 0; i < key.length(); i++)
		hashval += key[i];

	return hashval % tableSize;
}

void HashTable::insert ( const string & x ) {
	int loc = hash(x);
	table[loc].push_back(x);
}

void HashTable::remove ( const string & x ) {


}

bool HashTable::contains ( const string & x ) {
	int loc = hash(x);
	for (int i=0; i < table[loc].size(); i++) {
		if (table[loc][i].compare(x) == 0)
			return true;
	}
	return false;
}

int main () {

	HashTable myTable(101);
	string t1("123"), t2("42.9651-85.6695"), t3("class");
	
	myTable.insert(t1);
	myTable.insert(t2);
	myTable.insert(t3);

	if (myTable.contains(t1))
		cout << t1 << " found\n";
	else
		cout << t1 << " not found\n";

	if (myTable.contains("42.9651-85.6695"))
		cout << t2 << " found\n";
	else
		cout << t2 << " not found\n";

	return 0;
}