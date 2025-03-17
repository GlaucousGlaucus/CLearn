#include <stdlib.h>
#include <stdio.h>

typedef struct tree_node {
    int val;
    struct tree_node *left;
    struct tree_node *right;
} TreeNode;

typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, TreeNode* tree_node) {
    QueueNode* queue_node = malloc(sizeof(QueueNode));
    queue_node->treeNode = tree_node;
    queue_node->next = NULL;
    if (queue->rear) {
        queue->rear->next = queue_node;
    } else {
        queue->front = queue_node;
    }
    queue->rear = queue_node;
}

TreeNode* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    TreeNode* tree_node = temp->treeNode;
    free(temp);
    return tree_node;
}

TreeNode* create_node(int val) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insert_val(TreeNode *root, int val) {
    if (root == NULL) return create_node(val);

    if (val < root->val) {
        root->left = insert_val(root->left, val);
    } else if (val > root->val) {
        root->right = insert_val(root->right, val);
    }
    return root;
}

void inOrder(TreeNode* root) {
    if (root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

void breath_first_traversal(TreeNode* root) {
    if (root == NULL) return;
    Queue* queue = createQueue();
    enqueue(queue, root);
    while (queue->front != NULL) {
        TreeNode* node = dequeue(queue);
        printf("%d ", node->val);

        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
    }
    free(queue);
}

TreeNode* bfs_search_val(TreeNode* root, int val) {
    if (root == NULL) return NULL;
    Queue* queue = createQueue();
    enqueue(queue, root);
    while (queue->front != NULL) {
        TreeNode* node = dequeue(queue);
        if (node->val == val) {
            free(queue);
            return node;
        }

        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
    }
    free(queue);
    return NULL;
}

TreeNode* dfs_search_val(TreeNode* root, int val) {

}

int main() {
    TreeNode* root = NULL;
    root = insert_val(root, 10);
    insert_val(root, 20);
    insert_val(root, 30);
    insert_val(root, 25);
    insert_val(root, 22);
    insert_val(root, 2);
    insert_val(root, 19);
    insert_val(root, 9);
    insert_val(root, 12);
    inOrder(root);
    printf("\n");
    breath_first_traversal(root);
    printf("\nChinCo: %d ", bfs_search_val(root, 9)->val);
    return 0;
}
