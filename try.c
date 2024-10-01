#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack operations using arrays
char stack[MAX];
int top = -1;

// Function prototypes
void push(char c);
char pop();
char peek();
int isEmpty();
int precedence(char op);
void infixToPostfix(const char* infix, char* postfix);

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character if present

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Push function
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = c;
}

// Pop function
char pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return '\0';
    }
    return stack[top--];
}

// Peek function
char peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return '\0';
    }
    return stack[top];
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// Return operator precedence
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Convert infix to postfix
void infixToPostfix(const char* infix, char* postfix) {
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isspace(ch)) {
            continue; // Skip whitespace
        }

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from the stack
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}
