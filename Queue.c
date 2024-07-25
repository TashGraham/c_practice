// QUEUE

// basic operations of a queue:
// - Enqueue (insert): adds element to back to queue
// - Dequeue (delete): removes and returns element at front
// - Peek: returns element at front without removing
// - Empty: checks if queue is empty
// - Full: checks if queue is full

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// structure to represent queue
struct Queue {
    int front, rear, size; // front and rear are indexes of array
    unsigned capacity;
    int* array;
};

// creates queue of given capacity, initialises size as 0
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity-1;
    queue->array = (int*)malloc(queue->capacity*sizeof(int));

    return queue;
}

// if size == capacity then queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// empty if size == 0
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// add item to rear and adjust size
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) 
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

// remove item from front and adjust size
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// get front of queue
int front(struct Queue* queue) {
    if (isEmpty(queue)) 
        return INT_MIN;
    return queue->array[queue->front];
}

// get rear of queue
int rear(struct Queue* queue) {
    if (isEmpty(queue)) 
        return INT_MIN;
    return queue->array[queue->rear];
}

// driver function
int main() {
    struct Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}