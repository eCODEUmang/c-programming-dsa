#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char exp[MAX], stack[MAX];
    int top = -1;
    scanf("%s", exp);
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stack[++top] = exp[i];
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                printf("Not Balanced");
                return 0;
            }
            char c = stack[top--];
            if ((exp[i] == ')' && c != '(') ||
                (exp[i] == '}' && c != '{') ||
                (exp[i] == ']' && c != '[')) {
                printf("Not Balanced");
                return 0;
            }
        }
    }
    if (top == -1) printf("Balanced");
    else printf("Not Balanced");
    return 0;
}
