#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int val;
    struct node_struct* next;
} NODE;


typedef struct queue {
    NODE *front, *rear;
} QUEUE;

void init_stack(QUEUE* s) {
    s->front = NULL;
    s->rear = NULL;
}

NODE* createNode(int val) {
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->val = val;
    node->next = NULL;
    return node;
}

void push(QUEUE* queue, int val) {
    NODE* node = createNode(val);
    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    }
    queue->rear->next = node;
    queue->rear = node;
}

void pop(QUEUE* stack) {
    NODE* current = stack->front;
    if (current != NULL) {
        stack->front = current->next;
        if (stack->front == NULL) {
            stack->rear = NULL;
        }
        free(current);
    }
}

void traverse_print(QUEUE* stack) {
    NODE* current = stack->front;
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
    // pop(&stack);
    pop(&stack);
    push(&stack, 9);
    traverse_print(&stack);
}
