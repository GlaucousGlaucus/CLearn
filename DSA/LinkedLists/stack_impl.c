#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

Node *createNode(int val) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

Stack *createStack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, int val) {
    Node* node = createNode(val);
    node->val = val;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* node = stack->top;
    stack->top = node->next;
    return node->val;
}

void printStack(Stack *stack) {
    Node* node = stack->top;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
}

int main() {
    Stack *stack = createStack();
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    pop(stack);
    printStack(stack);
    return 0;
}
