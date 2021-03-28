#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int* array;
    int size;
    int capacity;
}Vector;


int size(Vector*);
int capacity(Vector*);
int isEmpty(Vector*);
int at(Vector*, int);
void push(Vector*, int);
void insert(Vector*,int,int);
void prepend(Vector*,int);
int pop(Vector*);
void delete(Vector*,int);

main() {
    Vector a;
    a.array = malloc(1 * sizeof(int));
    a.size = 0;
    a.capacity = 1;

    prepend(&a, 1);
    prepend(&a, 2);
    prepend(&a, 3);
    prepend(&a, 4);

    /* printf("%d\n", pop(&a)); */
    /* pop(&a); */
    delete(&a, 1);

    for (int i = 0; i < a.size; i++)
        printf("%d\n", at(&a, i));
}

int size(Vector *v) {
    return v->size;
}

int capacity(Vector *v) {
    return v->capacity;
}

int at(Vector *v, int index) {
    return v->array[index];
}

void push(Vector *v, int x) {
    if (v->size == v->capacity) {
        v->capacity*= 2;
        v->array = realloc(v->array, v->capacity * sizeof(int));
    }
    v->array[v->size++] = x;
}

void insert(Vector* v, int index, int x) {
    if (v->size == v->capacity) {
        v->capacity*= 2;
        v->array = realloc(v->array, v->capacity * sizeof(int));
    }

    for (int i = v->size; i != index; i--) {
        v->array[i] = v->array[i-1]; 
    }

    v->array[index] = x;
    v->size++;
}

void prepend(Vector *v, int x) {
    insert(v, 0, x);
}

int pop(Vector *v) {
    return v->array[v->size--];
}

void delete(Vector *v, int index) {
    for (int i = index; i <= v->size; i++)
        v->array[i] = v->array[i+1];
    v->size--;
}

