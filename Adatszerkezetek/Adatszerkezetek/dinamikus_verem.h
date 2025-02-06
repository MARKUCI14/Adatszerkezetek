#ifndef statikus_verem_h
#define statikus_verem_h

typedef struct Node {
    int data;
    Node* next;
} Node;

typedef struct Verem{
    Node* top;
}Verem;

Node* createNode(int data);

void createVerem(Verem* v);
void destroyVerem(Verem* v);
void push(Verem* v, int value);
void pop(Verem* v);
bool isEmpty(Verem* v);
bool isFull(Verem* v);

#endif /* egyszeresen_lista_hpp */


