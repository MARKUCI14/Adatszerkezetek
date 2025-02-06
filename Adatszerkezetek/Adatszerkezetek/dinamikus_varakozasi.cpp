#include "dinamikus_varakozasi.h"

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode -> data = value;
    newNode -> next = nullptr;
    return newNode;
}

void createQueue(Queue* queue) {
    queue -> front = queue -> rear = nullptr;
}
void destroyQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        pop(queue);
    }
}
void push(Queue* queue, int value) {
    Node* newNode = createNode(value);
    if (queue -> rear == nullptr) {
        queue -> front = queue -> rear = newNode;
        return;
    }
    queue -> rear -> next = newNode;
    queue -> rear = newNode;
    
}
void pop(Queue* queue) {
    if (isEmpty(queue)) return;
    
    Node* temp = queue -> front;
    queue -> front = queue -> front -> next;
    if (queue -> front == nullptr) {
        queue -> rear = nullptr;
    }
    
    delete temp;
}
bool isEmpty(Queue* queue);
