#include "hash_table.h"
#include <iostream>

// hash fuggveny
int hash(std::string cnp, int size) {
    ULL number_cnp = stoull(cnp);
    return number_cnp % size;
}


Node* createNode(std::string cnp, std::string number, std::string email) {
    Node* newNode = new Node;
    newNode -> cnp = cnp;
    newNode -> number = number;
    newNode -> email = email;
    newNode -> next = nullptr;
    return newNode;
}

void createHash(HashTable* hashTable, int size) {
    hashTable -> head = new Node*[size];
    hashTable -> size = size;
}
void destroyHash(HashTable* hashTable) {
    for (int i = 0; i < hashTable -> size; i++) {
        Node* current = hashTable -> head[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current -> next;
            delete temp;
        }
        current = nullptr;
    }
    hashTable -> head = nullptr;
}
void insert(HashTable* hashTable, std::string cnp, std::string number, std::string email) {
    int index = hash(cnp, hashTable -> size);
    Node* newNode = createNode(cnp, number, email);
    newNode -> next = hashTable -> head[index];
    hashTable -> head[index] = newNode;
}

Node* search_list(Node* head, std::string cnp) {
    while (head != nullptr) {
        if (head -> cnp == cnp) return head;
        head = head -> next;
    }
    std::cout << "Not Found!" << '\n';
    return new Node;
}

Node* search(HashTable* hashTable, std::string cnp) {
    int index = hash(cnp, hashTable -> size);
    return search_list(hashTable -> head[index], cnp);
}

void print(HashTable* hashTable) {
    for (int i = 0; i < hashTable -> size; i++) {
        Node* current = hashTable -> head[i];
        std::cout << i <<":\n";
        while (current != nullptr) {
            std::cout << '\t' << current -> cnp << " " << current -> number << " " << current -> email << '\n';
            current = current -> next;
        }
    }
}
