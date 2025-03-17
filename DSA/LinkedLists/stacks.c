#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int val;
    struct node_struct* next;
} NODE;


typedef struct queue {
    NODE* top;
} QUEUE;

void init_stack(QUEUE* s) {
    s->top = NULL;
}

NODE* createNode(int val) {
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->val = val;
    node->next = NULL;
    return node;
}

void push(QUEUE* queue, int val) {
    NODE* node = createNode(val);
    node->next = queue->top;
    queue->top = node;
}

void pop(QUEUE* stack) {
    NODE* current = stack->top;
    if (current != NULL) {
        stack->top = current->next;
        free(current);
    }
}

void traverse_print(QUEUE* stack) {
    NODE* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
}

int main() {
    QUEUE stack;
    init_stack(&stack);
    push(&stack, 4);
    push(&stack, 99);
    push(&stack, 2);
    pop(&stack);
    traverse_print(&stack);
}
