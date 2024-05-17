#ifndef HASHMAP_H
#define HASHMAP_H

class HashMap {
private:
    int *table;
    int capacity;

    int hashFunction(int key);
    int linearProbe(int index, int i);
    int quadraticProbe(int index, int i);
    int doubleHash(int key, int i);

public:
    HashMap(int size);
    ~HashMap();
    void insert(int key);
    bool search(int key);
    void remove(int key);
};

#endif // HASHMAP_H
