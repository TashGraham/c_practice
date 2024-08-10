#include <stdio.h>
#include <stdlib.h>

// circular singly linked list
// last node of list contains pointer to first node

// structure for node
struct Node {
    int data;
    struct Node* next;
};

// insert node at the beginning of the circular linked list 
void push(struct Node** head, int data) {
    // create new node and make head as next of it 
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *head;

    // if linked list is not NULL then setting the next of last node
    if (*head != NULL) {
        // finding node before head and update the next of it
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = ptr1;
    } else 
        ptr1->next = ptr1;
    *head = ptr1;
}

// delete a given node
void deleteNode(struct Node** head, int key) {
    // if linked list is empty
    if (*head == NULL) 
        return;
    // if the list only contains one node
    if ((*head)->data == key && (*head)->next == *head) {
        printf("Removing %d from list.\n", key);
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *last = *head, *d;

    // if head is to be deleted
    if ((*head)->data == key) {
        // find the last node of the list
        while (last->next != *head)
            last = last->next;
        // point last node to the new head
        last->next = (*head)->next;
        printf("Removing %d from list.\n", key);
        free(*head);
        *head = last->next;
        return;
    }

    // iterating through circular list
    while (last->next != *head && last->next->data != key) {
        last = last->next;
    }

    // deleting selected node
    if (last->next->data == key) {
        d = last->next;
        last->next = d->next;
        printf("Removing %d from list.\n", key);
        free(d);
    } else 
        printf("Given node is not found in the list.\n");
}

// printing function
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

// driver
int main() {
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);

    printf("List: ");
    printList(head);

    deleteNode(&head, 3);
    deleteNode(&head, 5);

    printf("List: ");
    printList(head);
}