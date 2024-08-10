// implementing a stack using linked list
#include <stdio.h>
#include <stdlib.h>

// stack functions: isEmpty, Push, Pop, Peek

////// linked list implementation //////

// node has its data and a pointer to the next node
struct Node {
    int data;
    struct Node* next;
};

// method to insert at beginning
int insertFront(struct Node** head, int data) {
    // creating new node using dynamic memory allocation
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // if malloc failed then return error
    if (!newNode) {
        return -1;
    }
    // storing data in new node
    newNode->data = data;
    // new node will point to current head
    newNode->next = *head;
    // update head to be new node
    *head = newNode;
    return 0; // returning 0 if nothing failed
}

// removing from beginning
int deleteHead(struct Node** head) {
    // don't need to check if empty here as it is done in caller function
    struct Node* temp = *head;
    *head = (*head)->next;
    int headData = temp->data;
    free(temp); // freeing memory allocation
    return(headData); // returning value of popped node
}


////// stack implementation //////

int isEmpty(struct Node** stack) {
    return *stack == NULL;
}

void push(struct Node** stack, int data) {
    // if insertFront does not return 0 then stack overflow occurred
    if (insertFront(stack, data)) {
        printf("Stack overflow!\n");
    }
}

int pop(struct Node** stack) {
    // first checking if empty
    if (isEmpty(stack)) {
        printf("stack Underflow\n");
        return -1;
    }
    deleteHead(stack);
}

int peek(struct Node** stack) {
    if (!isEmpty(stack)) {
        return (*stack)->data;
    }
    return -1;
}

// printing function
void printStack(struct Node** stack) {
    struct Node* temp = *stack;
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // initialising stack top pointer
    struct Node* stack = NULL;
    // pushing elements onto stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);

    // printing stack
    printf("Stack: ");
    printStack(&stack);
    // popping top two 
    pop(&stack);
    pop(&stack);
    // printing after pops
    printf("Stack: ");
    printStack(&stack);
    return 0;
}