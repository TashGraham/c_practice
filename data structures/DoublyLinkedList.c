#include <stdio.h>
#include <stdlib.h>

// node template
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// creating pointer to head and tail of list
struct Node* head = NULL;
struct Node* tail = NULL;

// create node with given data and return pointer to it
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// insert at beginning 
void insertHead(int data) {
    struct Node* newNode = createNode(data);
    // if list is empty then new node is head and tail
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// insert at end
void insertTail(int data) {
    struct Node* newNode = createNode(data);
    // if list is empty then new node is head and tail
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// deleting node at the beginning
void deleteHead() {
    // if nothing in list then nothing to delete
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    // if only one element in list then deleting makes list empty
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    // deallocating memory of the deleted node
    free(temp);
}

// deleting node at end 
void deleteTail() {
    if (tail == NULL) {
        return;
    }
    struct Node* temp = tail;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

// printing list head to tail
void displayForwards() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// printing list tail to head
void displayBackwards() {
    struct Node* current = tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// driver code
int main() {
    insertHead(10);
    insertHead(20);
    insertTail(30);
    insertTail(40);
    displayForwards(); // 20 10 30 40
    displayBackwards(); // 40 30 10 20
    deleteHead();
    deleteTail();
    displayForwards(); // 10 30
    displayBackwards(); // 30 10
}