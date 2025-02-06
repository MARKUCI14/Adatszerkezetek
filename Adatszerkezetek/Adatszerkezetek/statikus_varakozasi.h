#ifndef statikus_varakozasi_h
#define statikus_varakozasi_h

typedef struct Queue{
    int* arr;
    int front, rear;
    int size;
} Queue;

void createQueue(Queue* queue, int size);
void destroyQueue(Queue* queue);
void push(Queue* queue, int value);
void pop(Queue* queue);
bool isEmpty(Queue* queue);
bool isFull(Queue* queue);

#endif /* egyszeresen_lista_hpp */



