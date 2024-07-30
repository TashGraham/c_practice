// using stack checks if a string has 'balanced' parentheses
// balanced=({([])}) unbalanced=(]{})[]

#include <stdio.h>
#include <stdlib.h>
#define bool int

// character based stack implementation
struct Node {
    char data;
    struct Node* next;
};

// Function to push an item to stack
void push(struct Node** top_ref, char new_data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        return;
    }
    newNode->data = new_data;
    newNode->next = *top_ref;
    *top_ref = newNode;
    return;
}

// Function to pop an item from stack
char pop(struct Node** top_ref) {
    // first checking if empty
    if (*top_ref == NULL) {
        printf("stack overflow\n");
        return '!';
    }
    struct Node* temp = *top_ref;
    *top_ref = (*top_ref)->next;
    char headData = temp->data;
    free(temp);
    return headData;
}

// return 1 if char1 & char2 matching eg.[]
bool isMatching(char char1, char char2) {
    if (char1 == '(' && char2 == ')') 
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else if (char1 == '[' && char2 == ']') 
        return 1;
    else
        // characters do not match
        return 0;
}

// returns 1 if expression has balanced brackets 
bool areBalanced(char exp[]) {
    int i = 0;
    // empty character stack
    struct Node* stack = NULL;
    // traversing given expression to check matching
    while (exp[i]) {
        // if exp[i] is opening then pushing it
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
            push(&stack, exp[i]);
        }
        // if exp[i] is closing bracket then popping from
        // stack to check if last pushed bracket is matching
        if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
            // if stack is empty then closing bracket doesn't have a pair
            if (stack == NULL) {
                return 0;
            } else if (!isMatching(pop(&stack), exp[i])) {
                return 0;
            }
        }
        i++;
    }
    // if there is anything left then not balanced
    if (stack == NULL) {
        return 1; // balanced
    } else {
        return 0; // not balanced
    }
}

// driver code
int main() {
    char exp[100] = "[{}]{}(())";

    if (areBalanced(exp)) {
        printf("Balanced \n");
    } else {
        printf("Unbalanced \n");
    }
    return 0;
}