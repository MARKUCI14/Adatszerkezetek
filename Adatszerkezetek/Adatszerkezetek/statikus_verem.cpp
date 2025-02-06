#include "statikus_verem.h"

void createVerem(Verem* v, int max_size) {
    v -> arr = new int[max_size];
    v -> top = -1;
    v -> size = max_size;
}

void destroyVerem(Verem* v) {
    delete v -> arr;
    v = nullptr;
}

void push(Verem* v, int value) {
    if (isFull(v)) return;
    v -> top++;
    v -> arr[v -> top] = value;
}

void pop(Verem* v) {
    if (isEmpty(v)) return;
    v -> top--;
}

bool isEmpty(Verem* v) {
    return v -> top == -1;
}

bool isFull(Verem* v) {
    return v -> size - 1 == v -> top;
}
