#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    int val;
    int exp;
    struct node_struct* next;
} NODE;

NODE* createNode(int val, int exp) {
    NODE* node = malloc(sizeof(NODE));
    node->val = val;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void insert_at_end(NODE** head, int val, int exp) {
    NODE* node = createNode(val, exp);
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
}

void delete_node(NODE** head, int key) {
    NODE* current = *head;
    NODE* previous = NULL;
    if (current != NULL && current->val == key) {
        *head = current->next;
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
    free(current);
}

void traverse_print(NODE* head) {
    NODE* current = head;
    while (current != NULL) {
        printf("%d^%d ", current->val, current->exp);
        current = current->next;
    }
}

void add_polys(NODE** sum, NODE* p1, NODE* p2) {
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insert_at_end(sum, p1->val, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insert_at_end(sum, p2->val, p2->exp);
            p2 = p2->next;
        } else {
            insert_at_end(sum, p1->val + p2->val, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
}

int main() {
    NODE* poly1 = NULL;
    NODE* poly2 = NULL;

    insert_at_end(&poly1, 50, 3);
    insert_at_end(&poly1, 5, 2);
    insert_at_end(&poly1, 4, 1);
    insert_at_end(&poly1, 2, 0);

    insert_at_end(&poly2, 3, 2);
    insert_at_end(&poly2, 2, 1);
    insert_at_end(&poly2, 7, 0);

    traverse_print(poly1);
    traverse_print(poly2);
    printf("\n");

    NODE* sum = NULL;
    add_polys(&sum, poly1, poly2);
    traverse_print(sum);
}
