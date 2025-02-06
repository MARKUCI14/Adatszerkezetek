
#ifndef dinamikus_varakozasi_h
#define dinamikus_varakozasi_h

typedef struct Node {
    int data;
    Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int value);

void createQueue(Queue* queue);
void destroyQueue(Queue* queue);
void push(Queue* queue, int value);
void pop(Queue* queue);
bool isEmpty(Queue* queue);

#endif /* egyszeresen_lista_hpp */



