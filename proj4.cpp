#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class HashTable {
	public:
		HashTable (int size); 
		void insert ( const string & x, const string & y );
		bool contains ( const string & x );
        string search ( const string & x );
        
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

void HashTable::insert ( const string & x, const string & y ) {
	int loc = hash(x);
	table[loc].push_back(y);
}

string HashTable::search ( const string & x ) {
    string location, name;
    int loc = hash(x);
	for (int i=0; i < table[loc].size(); i++) {
	    // Get the latitude and longitude
        location = table[loc][i].substr(0, 15);	    
	    // Get the location name
        name = table[loc][i].substr(15, table[loc][i].size());
        
        if ( location.compare(x) == 0 )
            return "Location found - " + name;
    }
    return "Location not found. Please try again...";        
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
    
    ifstream dataFile;
    string location, latitude, longitude, coordinates;
    int choice = 1;
    
    // Load the location data file
	dataFile.open("proj 4.dat");
	
    if ( dataFile.is_open() ) 
    {
        while (!dataFile.eof()) 
        {
            getline(dataFile, location, '\t');
            getline(dataFile, latitude, '\t');
            getline(dataFile, longitude, '\n');

            coordinates = latitude + longitude;
            coordinates = coordinates.substr(0, coordinates.size()-1);

            myTable.insert(coordinates, coordinates+location);  // Insert location data to hash table
        }
    }
	
    dataFile.close();
    
    // allow the user to decide what one wants to do
    cout << "\nOptions\n";
    cout << "1. Search Location\n";
    cout << "2. Exit\n\n";
    cout << "Enter your choice: ";
    cin >> choice;    
    
    while( choice == 1 ) {   
        cout<< "Latitude: ";
        cin >> latitude;
        cout << "Longitude: ";
        cin >> longitude;

        cout << myTable.search(latitude + longitude) << endl;
        
        // allow the user to decide what one wants to do
        cout << "\nOptions\n";
        cout << "1. Search Location\n";
        cout << "2. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
    } 
    
    return 0;
}
