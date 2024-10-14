#include <stdio.h>

#define WORDS_MAX 50

// function that takes an array of string p and a number of 
// words n, and prints the first n strings in reverse order

void reverse_print(char **p, int n) {
    for (int i=n-1; i>=0; i--) {
        printf("%s ", p[i]);
    }
    printf("\n");

}

void main() {
    char *message[WORDS_MAX] = {"I", "think", "we've", "got",
                                "our", "roles", "reversed"};

    reverse_print(message, 3); // we've think I
    reverse_print(message, 5); // our got we've think I
    return 0;
}