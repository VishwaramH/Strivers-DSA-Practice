#include <stdio.h>
#include <stdlib.h>

// Definition
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

// Max depth function
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left  = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + ((left > right) ? left : right);
}

int main() {
    /*
     * Building this tree:
     *        1
     *       / \
     *      2   3
     *     / \
     *    4   5
     *
     * Expected max depth = 3
     */

    struct TreeNode* root = newNode(1);
    root->left            = newNode(2);
    root->right           = newNode(3);
    root->left->left      = newNode(4);
    root->left->right     = newNode(5);

    printf("Max Depth: %d\n", maxDepth(root));  // Output: 3

    // Test 2: Single node
    struct TreeNode* single = newNode(1);
    printf("Single node depth: %d\n", maxDepth(single));  // Output: 1

    // Test 3: Empty tree
    printf("Empty tree depth: %d\n", maxDepth(NULL));  // Output: 0

    // Test 4: Left skewed tree
    /*
     *   1
     *  /
     * 2
     *  \
     *   3
     * Expected = 3
     */
    struct TreeNode* skewed = newNode(1);
    skewed->left            = newNode(2);
    skewed->left->right     = newNode(3);
    printf("Skewed tree depth: %d\n", maxDepth(skewed));  // Output: 3

    return 0;
}