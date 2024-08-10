#include <stdio.h>
#include <stdlib.h>

// node has its data and a pointer to the next node
struct Node {
    int data;
    struct Node* next;
};

// method to insert at beginning
void insertFront(struct Node** head, int data) {
    // creating new node using dynamic memory allocation
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // storing data in new node
    newNode->data = data;
    // new node will point to current head
    newNode->next = *head;
    // update head to be new node
    *head = newNode;
}

// method to insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // storing data
    newNode->data = data;
    // newNode->next will be null as it is last
    newNode->next = NULL;
    // if list is empty then this node will be the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    // otherwise iterate through till the last node
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    // make the tail->next = the new node
    current->next = newNode;
}

// printing function
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // creating linked list
    struct Node* head = NULL;
    // passing head by reference so it can be modified
    insertFront(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    // print list
    printf("Linked List: ");
    printList(head);

    return 0;
}