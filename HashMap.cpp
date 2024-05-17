#include "HashMap.h"
#include <iostream>
using namespace std;

HashMap::HashMap(int size)
{
    this->capacity = size;
    table = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        table[i] = -1;
    }
}
HashMap::~HashMap()
{
    delete[] table;
}
//Hash function//
int HashMap::hashFunction(int key)
{
    return key % capacity;
}

int HashMap::linearProbe(int index, int i)
{
    return (index + 1) % capacity;
}

int HashMap::quadraticProbe(int index, int i)
{
    return ((index + i * i) % capacity);
}

int HashMap::doubleHash(int key, int i)
{
    return (hashFunction(key) + i * (1 + (key % (capacity - 1)))) % capacity;
}

void HashMap::insert(int key)
{
    int index = hashFunction(key);
    int i = 0;
    while (i < capacity)
    {
        if (table[index] == -1)
        {
            table[index] = key;
            return;
        }
        else
        {
            index=linearProbe(index, i);
             i++;
        }      
    }
}

bool HashMap::search(int key)
{   bool status;
    int index = hashFunction(key);
    int count = 0;
    while (count < capacity)
    {
        if (table[index] == key)
        {
            cout << "found" << endl;
            status=true;
            break;
                      
        }
        else if(table[index]!=key){
            index= linearProbe(index,count); 
            count++;          
        }
        else
        {
            cout << "Not Found" << endl;
            status=false;
                    
        }
        
    }
    return status;
}

void HashMap::remove(int key)
{    
 int index = hashFunction(key);
    int i = 0;
    while (table[index] != -1 && i < capacity)
    {
        if (table[index] == key)
        {
            table[index] = -1; // Mark the slot as empty
            return;
        }
        index = linearProbe(index, 1); // Update index for next iteration
        i++;
    }

}
