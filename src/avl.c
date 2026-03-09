#include <stdio.h>
#include <stdlib.h>

typedef struct avl_node {
    int key;
    int height;
    void *data; // inutile dans le TP
     struct avl_node *left;
     struct avl_node *right;
    struct avl_node *parent;
} avl_node;

static int height(avl_node *n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

static void update_height(avl_node *n) {
    int l = height(n->left);
    int r = height(n->right);
    if (l > r) {
        n->height = 1 + l;
    } else {
        n->height = 1 + r;
    }
}

static int balance_factor(avl_node *n) {
    return height(n->left) - height(n->right);
}

static avl_node *rotate_right(avl_node *y) {
    avl_node *x = y->left;
    y->left = x->right;
    x->right = y;
    update_height(y);
    update_height(x);
    return x;
}

static avl_node *rotate_left(avl_node *x) {
    avl_node *y = x->right;
    x->right = y->left;
    y->left = x;
    update_height(x);
    update_height(y);
    return y;
}

avl_node *avl_balance(avl_node *x) {
    update_height(x);
    int bf = balance_factor(x);

    if (bf > 1 && balance_factor(x->left) >= 0) {
        return rotate_right(x);
    }
    if (bf > 1 && balance_factor(x->left) < 0) {
        x->left = rotate_left(x->left);
        return rotate_right(x);
    }
    if (bf < -1 && balance_factor(x->right) <= 0) {
        return rotate_left(x);
    }
    if (bf < -1 && balance_factor(x->right) > 0) {
        x->right = rotate_right(x->right);
        return rotate_left(x);
    }

    return x;
}

avl_node *avl_insert(avl_node *root, avl_node *x) {
    if (root == NULL) {
        return x;
    }
    if (x->key < root->key) {
        root->left = avl_insert(root->left, x);
    } else {
        root->right = avl_insert(root->right, x);
    }
    return avl_balance(root);
}
