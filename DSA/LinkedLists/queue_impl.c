#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct queue {
    Node *front, *rear;
} Queue;

Node *createNode(int val) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void printQueue(Queue *queue) {
    Node* node = queue->front;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
}

void enqueue(Queue *queue, int val) {
    Node* node = createNode(val);
    if (queue->rear == NULL) {
        queue->rear = queue-> front = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

int dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* node = queue->front;
    int val = node->val;
    if (queue->rear == queue->front) {
        queue->rear = queue->front = NULL;
    } else {
        queue->front = node->next;
    }
    free(node);
    return val;
}

int main() {
    Queue *queue = createQueue();
    assert(queue != NULL);
    enqueue(queue, 4);
    // enqueue(queue, 5);
    // enqueue(queue, 6);
    // enqueue(queue, 7);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}
