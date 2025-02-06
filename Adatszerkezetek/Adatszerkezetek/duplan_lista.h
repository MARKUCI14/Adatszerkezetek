#ifndef duplan_lista_h
#define duplan_lista_h

struct Node{
    int data;
    Node* next;
    Node* before;
    Node(int value) : data(value), next(nullptr), before(nullptr) {}
};

typedef struct {
    Node* head;
    Node* tail;
} List;

void createList(List* list);
void destroyList(List* list);
void push_front(List* list, int value);
void push_back(List* list, int value);
void pop_front(List* list);
void pop_back(List* list);
void print(List* list);


#endif /* duplan_lista_hpp */

