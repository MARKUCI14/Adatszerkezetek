//
//  duplan_lista.cpp
//  Adatszerkezetek
//
//  Created by Márk Portik on 06.02.2025.
//

#include "duplan_lista.h"
#include <iostream>

void createList(List* list) {
    list->head = NULL;
    list->tail = NULL;
}

void destroyList(List* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}

void push_front(List* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = list->head;
    newNode->before = NULL;
    
    if (list->head)
        list->head->before = newNode;
    else
        list->tail = newNode;
    
    list->head = newNode;
}

void push_back(List* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = NULL;
    newNode->before = list->tail;
    
    if (list->tail)
        list->tail->next = newNode;
    else
        list->head = newNode;
    
    list->tail = newNode;
}

void pop_front(List* list) {
    if (!list->head) return;
    Node* temp = list->head;
    list->head = list->head->next;
    if (list->head)
        list->head->before = NULL;
    else
        list->tail = NULL;
    free(temp);
}

void pop_back(List* list) {
    if (!list->tail) return;
    Node* temp = list->tail;
    list->tail = list->tail->before;
    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;
    free(temp);
}

void print(List* list) {
    Node* current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

