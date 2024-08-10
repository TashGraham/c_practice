// removing pairs from a given, sorted linked list
// eg 2, 2, 2, 3, 3, 4, 4, 4 -> 2, 3, 4

#include <stdio.h>
#include <stdlib.h>

// node
struct Node {
    int data;
    struct Node* next;
};

// insert at head
void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// remove duplicates function
void removeDuplicates(struct Node* head) {
    // do nothing if the list is empty
    if (head == NULL) {
        return;
    }
    struct Node* current = head;
    // comparing current node with next
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            // if they are the same then removing next
            struct Node* nextNode = current->next->next;
            free(current->next);
            current->next = nextNode;
        } else {
            // only moving on if there was no deletion
            current = current->next;
        }
    }
}


// print function
void printList(struct Node* head) {
    struct Node* ptr = head;
    while(ptr->next) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }

    printf("%d\n", ptr->data);
}

int main(void) {
    // input keys
    int keys[] = {1, 1, 2, 2, 2, 3, 4, 4};
    int n = sizeof(keys)/sizeof(keys[0]);

    // points to the head node of linked list 
    struct Node* head = NULL;

    // costruct a linked list 
    for (int i = n-1; i >= 0; i--) {
        push(&head, keys[i]);
    }

    printList(head);
    removeDuplicates(head);
    printList(head);
    return 0;
}