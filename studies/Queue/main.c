#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 5

typedef struct Queue {
    int *arr;
    int read;
    int write;
    int size;
}Queue;

void enqueue(Queue*,int);
int dequeue(Queue*);
int empty(Queue*);
int full(Queue*);

main() {
    Queue queue;
    queue.read = -1;
    queue.write = -1;
    queue.size = MAX_SIZE;
    queue.arr = malloc(sizeof(int)*MAX_SIZE);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
}

void enqueue(Queue *queue, int x) {
    if ((queue->read == 0 && queue->write == queue->size - 1) ||
        (queue->write == (queue->read - 1) % (queue->size - 1))) {
        printf("(Full) ERROR\n");
    } else if (queue->read == -1) {
        queue->read = queue->write = 0;
        queue->arr[queue->write] = x;
    } else if (queue->write == queue->size -1 && queue->read != 0) {
        queue->write = 0;
        queue->arr[queue->write] = x;
    } else 
        queue->write++;
        queue->arr[queue->write] = x;
}

int empty(Queue *queue) {
    return queue->read == queue->write;
}

int dequeue(Queue* queue) {
    if (queue->read == -1) {
        printf("(EMPTY) ERROR\n");
        return INT_MIN;
    }
    int data = queue->arr[queue->read];
    queue->arr[queue->read] = -1;

    if (queue->read == queue->write) {
        queue->read = -1;
        queue->write = -1;
    } else if (queue->read == queue->size - 1)
        queue->read = 0;
    else
        queue->read++;
    return data;
}

