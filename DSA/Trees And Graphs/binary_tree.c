#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Search for a node
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// Find the minimum node
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete a node
Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder traversal
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Level order traversal
void levelOrder(Node* root) {
    if (root == NULL)
        return;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }
}

// Determine the height of the tree
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Find the smallest node
Node* findSmallest(Node* root) {
    return findMin(root);
}

// Find the largest node
Node* findLargest(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

void mirrorTree(Node* root) {
    if (root == NULL)
        return;

    // Swap the left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

int countNodes(Node* root) {
    if (root == NULL)
        return 0;

    // Count the current node, then recurse for left and right subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Main function to test
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Level order traversal: ");
    levelOrder(root);
    printf("\n");

    printf("Height of the tree: %d\n", height(root));

    Node* smallest = findSmallest(root);
    printf("Smallest node: %d\n", smallest ? smallest->data : -1);

    Node* largest = findLargest(root);
    printf("Largest node: %d\n", largest ? largest->data : -1);

    root = deleteNode(root, 20);
    printf("After deletion of 20, inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
