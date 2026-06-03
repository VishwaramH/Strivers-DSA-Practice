#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(!p && !q) {
        return true;
    } 
    if(!p || !q) {
        return false;
    }
    if(p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    // Tree 1:
    //      1
    //     / \
    //    2   3
    struct TreeNode* p = newNode(1);
    p->left = newNode(2);
    p->right = newNode(3);

    // Tree 2:
    //      1
    //     / \
    //    2   3
    struct TreeNode* q = newNode(1);
    q->left = newNode(2);
    q->right = newNode(3);

    if(isSameTree(p, q)) {
        printf("Trees are the same\n");
    } else {
        printf("Trees are different\n");
    }

    // Tree 3:
    //      1
    //     / \
    //    2   3
    struct TreeNode* r = newNode(1);
    r->left = newNode(2);
    r->right = newNode(4);  // different value here

    if(isSameTree(p, r)) {
        printf("Trees are the same\n");
    } else {
        printf("Trees are different\n");
    }

    return 0;
}