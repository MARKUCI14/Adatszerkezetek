#include "egyszeresen_lista.h"
#include <iostream>

void createList(List* list) {
    list -> head = nullptr;
}

void destroyList(List* list) {
    Node* current = list -> head;
    
    while (current != nullptr) {
        Node* next = current -> next;
        delete current;
        current = next;
    }
    
    list -> head = nullptr;
}

void push_front(List* list, int value) {
    Node* newNode = new Node(value);
    newNode -> next = list -> head;
    list -> head = newNode;
}

void push_back(List* list, int value) {
    Node* newNode = new Node(value);
    if (list -> head == nullptr) {
        list -> head = newNode;
        return;
    }
    
    Node* current = list -> head;
    while (current -> next != nullptr) {
        current = current -> next;
    }
    
    current -> next = newNode;
}

void pop_front(List* list) {
    if (list -> head == nullptr) return;
    Node* temp = list -> head;
    list -> head = list -> head -> next;
    delete temp;
}

void pop_back(List* list) {
    if (list->head == nullptr) return;
    if (list->head->next == nullptr) {
        delete list->head;
        list->head = nullptr;
        return;
    }
    Node* temp = list->head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void print(List* list) {
    Node* current = list -> head;
    while (current) {
        std::cout<< current -> data << " " ;
    }
    
    std::cout << '\n';
}
