#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int val;
    struct node_struct* next;
    struct node_struct* prev;
} NODE;

NODE* createNode(int val) {
    NODE* node = malloc(sizeof(NODE));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void push(NODE** head, int val) {
    NODE* node = createNode(val);
    node->next = *head;
    if (*head != NULL) {
        (*head)->prev = node;
    }
    *head = node;
}

void insert_at_end(NODE** head, int val) {
    NODE* node = createNode(val);
    if (*head == NULL) {
        *head = node;
        return;
    }
    // Traverse
    NODE* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    node->prev = current;
}

void delete_node(NODE** head, int key) {
    NODE* current = *head;
    NODE* previous = NULL;
    if (current != NULL && current->val == key) {
        *head = current->next;
        (*head)->prev = NULL;
        free(current);
        return;
    }
    while (current != NULL && current->val != key) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    assert(previous != NULL);
    previous->next = current->next;
    if (previous->next != NULL) {
        (previous->next)->prev = previous;
    }
    free(current);
}

void traverse_print(NODE* head) {
    NODE* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
}

int main() {
    NODE* head = createNode(1);
    NODE* second = createNode(2);
    head->next = second;
    NODE* third = createNode(3);
    second->next = third;
    push(&head, 4);
    insert_at_end(&head, 5);
    delete_node(&head, 2);
    traverse_print(head);
}
