#include "dinamikus_verem.h"

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = nullptr;
    return newNode;
}

void createVerem(Verem* v) {
    v -> top = nullptr;
}

void destroyVerem(Verem* v) {
    Node* current = v -> top;
    while (current != nullptr) {
        Node* tmp = current;
        current = current -> next;
        delete tmp;
    }
    v = nullptr;
}

void push(Verem* v, int value) {
    Node* newNode = createNode(value);
    newNode -> next = v -> top;
    v -> top = newNode;
}

void pop(Verem* v) {
    Node* node = v -> top;
    v -> top = v -> top -> next;
    delete node;
}

bool isEmpty(Verem* v) {
    return v -> top == nullptr;
}
