#ifndef statikus_verem_h
#define statikus_verem_h

typedef struct Verem{
    int* arr;
    int top;
    int size;
}Verem;

void createVerem(Verem* v, int max_size);
void destroyVerem(Verem* v);
void push(Verem* v, int value);
void pop(Verem* v);
bool isEmpty(Verem* v);
bool isFull(Verem* v);

#endif /* egyszeresen_lista_hpp */

