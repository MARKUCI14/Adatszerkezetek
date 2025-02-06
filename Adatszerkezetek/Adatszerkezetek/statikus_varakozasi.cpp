#include "statikus_varakozasi.h"

void createQueue(Queue* queue, int size) {
    queue -> arr = new int[size];
    queue -> size = size;
    queue -> front = queue -> rear = 1;
}

void destroyQueue(Queue* queue) {
    delete queue -> arr;
    queue = nullptr;
}

void push(Queue* queue, int value) {
    if (isFull(queue)) return;
    if (isEmpty(queue)) {
        queue -> front = 0;
    }
    queue -> rear++;
    queue -> arr[queue -> rear] = value;
    
}

void pop(Queue* queue) {
    if (isEmpty(queue)) return;
    
    int value = queue -> arr[queue -> front];
    if (queue -> front == queue -> rear) {
        queue -> front = queue -> rear = -1;
    } else {
        queue -> front++;
    }
}

bool isEmpty(Queue* queue) {
    return queue -> front == -1;
}

bool isFull(Queue* queue) {
    return queue -> rear == queue -> size - 1;
}
