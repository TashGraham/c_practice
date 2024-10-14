#include <stdlib.h>
#include <stdio.h>

struct node {
    char value;
    struct node * next;
};

struct node* create_node(char value) {
    // TODO: allocate memory space and initialise struct members
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    // if malloc fails then returning null
    if (!newNode)
        return NULL;

    newNode->value = value;
    newNode->next = NULL; 

    return newNode;
}

void free_list(struct node* list) {
  // TODO: free all allocated memory space starting from the head of the list
  struct node* current = list;
  struct node* next_node;

  // traversing list and freeing each node
  while (current != NULL) {
    next_node = current->next;
    free(current);
    current = next_node;
  }
}

void print_list(struct node* list) {
    while (list) {
      printf("%c-", list->value);
      list = list->next;
    }
    printf("\n");
}

int main () {
    char course[] = "Systems Programming";
    struct node* last_node = NULL;
    struct node* head = NULL;
    for (int i=0; course[i]!='\0'; i++) {
        struct node* new_node = create_node(course[i]);
        if(!new_node) {
            printf("Could not create new node\nExiting...\n");
            return -1;
        }
        if (last_node) {
            last_node->next = new_node;
        } else {
            head = new_node;
        }
        last_node = new_node;
    }
    print_list(head);
    free_list(head);
    head=NULL;
    print_list(head);
}