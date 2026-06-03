#include <stdio.h>
#include <stdlib.h>

/* ── Node definition ── */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* ── Helper: create a new node ── */
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

/* ! ── Invert tree (your code, bug fixed) ── */ // ! This the main logic code //
struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root) return NULL;

    struct TreeNode *temp = root->left;   // ✅ no malloc
    root->left  = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

/* ── Print tree: inorder (Left → Root → Right) ── */
void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

/* ── Print tree: level-order using a simple queue ── */
void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* node = queue[front++];
        printf("%d ", node->val);
        if (node->left)  queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
}

/* ── Free entire tree ── */
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* ── Driver ── */
int main() {
    /*
     * Build this BST:
     *        10
     *       /  \
     *      5    15
     *     / \   / \
     *    3   7 12  20
     */
    struct TreeNode* root = newNode(10);
    root->left            = newNode(5);
    root->right           = newNode(15);
    root->left->left      = newNode(3);
    root->left->right     = newNode(7);
    root->right->left     = newNode(12);
    root->right->right    = newNode(20);

    printf("Before invert:\n");
    printf("  Inorder     : "); inorder(root);     printf("\n");
    printf("  Level-order : "); levelOrder(root);  printf("\n");

    invertTree(root);

    /*
     * Expected inverted BST:
     *        10
     *       /  \
     *      15    5
     *     / \   / \
     *   20  12  7   3
     */
    printf("\nAfter invert:\n");
    printf("  Inorder     : "); inorder(root);     printf("\n");
    printf("  Level-order : "); levelOrder(root);  printf("\n");

    freeTree(root);
    return 0;
}