#ifndef egyszeresen_lista_h
#define egyszeresen_lista_h

#include <stdio.h>

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

typedef struct {
    Node* head;
} List;

void createList(List* list);
void destroyList(List* list);
void push_front(List* list, int value);
void push_back(List* list, int value);
void pop_front(List* list);
void pop_back(List* list);
void print(List* list);


#endif /* egyszeresen_lista_hpp */
