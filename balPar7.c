#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
}
        stack[++top] = c;

    }
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int equal(char char1, char char2) {
    if (char1 == '(' && char2 == ')')
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else if (char1 == '[' && char2 == ']')
        return 1;
    else
        return 0;
}

int checking(char* expr) {
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '('  || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (top == -1) {
                return 0;
            }
            if (!equal(pop(), expr[i])) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (checking(expr)) {
        printf("The expression is valid.\n");
    } else {
        printf("The expression is not valid.\n");
    }

    return 0;
}