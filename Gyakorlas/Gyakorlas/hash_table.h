#ifndef hash_table_h
#define hash_table_h
#define ULL unsigned long long int

#include <iostream>

typedef struct Node {
    std::string cnp;
    std::string number;
    std::string email;
    Node* next;
} Node;

typedef struct HashTable {
    int size;
    Node** head;
}HashTable;

Node* createNode(std::string cnp, std::string number, std::string email);

void createHash(HashTable* hashTable, int size);
void destroyHash(HashTable* hashTable);
void insert(HashTable* hashTable, std::string cnp, std::string number, std::string email);
Node* search(HashTable* hashTable, std::string cnp);
void print(HashTable* hashTable);

#endif /* hash_table_h */
