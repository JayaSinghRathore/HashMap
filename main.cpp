#include <iostream>
#include "HashMap.h"
using namespace std;

int main() {
    // Initialize hash map with a capacity of 10
    HashMap hashMap(10);

    // Insert some keys into the hash map
    hashMap.insert(5);
    hashMap.insert(15);
    hashMap.insert(25);

    // Search for a key
    cout << "Search for key 15: " << (hashMap.search(25) ? "Found" : "Not found") << endl;

    // Remove a key
     hashMap.remove(25);
     cout << "Search for key 15 after removal: " << (hashMap.search(25) ? "Found" : "Not found") <<endl;

    return 0;
}
