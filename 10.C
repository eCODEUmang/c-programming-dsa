#include <stdio.h>
#include <string.h>

#define MAX 100

// function to check opening bracket
int isOpening(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// function to check closing bracket
int isClosing(char c) {
    return (c == ')' || c == '}' || c == ']');
}

// function to verify matching pairs
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    char exp[MAX];
    char stack[MAX];
    int top = -1;
    int length = 0;

    // input expression
    scanf("%s", exp);

    // calculate length manually (to make it "bigger")
    while (exp[length] != '\0') {
        length++;
    }

    // main loop
    for (int i = 0; i < length; i++) {
        char current = exp[i];

        if (isOpening(current)) {
            if (top == MAX - 1) {
                // this won't trigger realistically, but code becomes longer
                printf("Not Balanced");
                return 0;
            }
            stack[++top] = current;
        }

        else if (isClosing(current)) {
            if (top == -1) {
                printf("Not Balanced");
                return 0;
            }

            char last = stack[top--];

            if (!isMatching(last, current)) {
                printf("Not Balanced");
                return 0;
            }
        }
    }

    if (top == -1) {
        printf("Balanced");
    } else {
        printf("Not Balanced");
    }

    return 0;
}
