#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int val;
    struct node_struct* next;
} NODE;

NODE* createNode(int val) {
    NODE* node = malloc(sizeof(NODE));
    node->val = val;
    node->next = NULL;
    return node;
}

void push(NODE** head, int val) {
    NODE* node = createNode(val);
    node->next = *head;
    *head = node;
}

void insert_at_end(NODE** head, int val) {
    NODE* node = createNode(val);
    if (*head == NULL) {
        *head = node;
        node->next = *head;
        return;
    }
    // Traverse
    NODE* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    node->next = *head;
}

void delete_node(NODE** head, int key) {
    NODE* current = *head;
    NODE* previous = NULL;

    // If it's the only element
    if (current->val == key) {
        if (current->next == *head) {
            free(current);
            *head = NULL;
            return;
        }
        while (current->next != *head) {
            current = current->next;
        }
        current->next = (*head)->next;
        free(*head);
        *head = current->next;
        return;
    }

    do {
        previous = current;
        current = current->next;
    } while (current != *head && current->val != key);

    if (current->val == key) {
        assert(previous != NULL);
        previous->next = current->next;
        free(current);
    }
}

void traverse_print(NODE* head) {
    NODE* current = head;
    do {
        printf("%d ", current->val);
        current = current->next;
    } while (current != head);
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
