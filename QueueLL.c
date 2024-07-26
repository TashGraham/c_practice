// QUEUE - Linked List operation

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// linked list node structure
struct QNode {
    int data;
    struct QNode* next;
};

// queue structure to store front and rear node
struct Queue {
    struct QNode *front, *rear;
};

// function to create new linked list node
struct QNode* newNode(int data) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// creating empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}



// queue is empty if rear == NULL
int isEmpty(struct Queue* queue) {
    return (queue->rear == NULL);
}

// enqueue adds element to the back of the queue
void enqueue(struct Queue* queue, int k) {
    // making new node with data = k
    struct QNode* temp = newNode(k);
    // if queue is empty then new node is front and rear
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        printf("%d enqueued to queue\n", k);
        return;
    }
    // otherwise add new node to end of queue and change rear
    queue->rear->next = temp;
    queue->rear = temp;
    printf("%d enqueued to queue\n", k);
}

// dequeue removes and returns element from the front of the queue
int dequeue(struct Queue* queue) {
    // if queue is empty the return NULL
    if (isEmpty(queue))
        return INT_MIN;
    struct QNode* temp = queue->front;
    queue->front = queue->front->next;
    // if front becomes NULL then rear must also 
    if (queue->front == NULL) 
        queue->rear = NULL;
    int tempData = temp->data;
    free(temp);
    return tempData;
}

// peek returns element at front but does not remove it 
int peek(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    struct QNode* temp = queue->front;
    return temp->data;
}

// driver function
int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front item is %d\n", peek(queue));

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front item is %d\n", peek(queue));

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front item is %d\n", peek(queue));

    return 0;
}