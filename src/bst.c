#include <stdio.h>

// On définit la structure 
typedef struct tree_node {
    int data;
    struct tree_node *parent;
    struct tree_node *left;
    struct tree_node *right;
} TreeNode;

typedef void (*process_fn)(struct tree_node *);

// Préfixe (preorder) : Nœud → Gauche → Droite
void preorder(struct tree_node *n, process_fn process) {
    if (!n) return; // Attention : il fallait rajouter ce cas d'arrêt que le prof n'avait pas mis !
    process(n);
    preorder(n->left, process);
    preorder(n->right, process);
}

// Infixe (inorder) : Gauche → Nœud → Droite
void inorder(struct tree_node *n, process_fn process) {
    if (!n) return;
    inorder(n->left, process);
    process(n);
    inorder(n->right, process);
}

// Postfixe (postorder) : Gauche → Droite → Nœud
void postorder(struct tree_node *n, process_fn process) {
    if (!n) return;
    postorder(n->left, process);
    postorder(n->right, process);
    process(n);
}

void print_node(struct tree_node *n) {
    if (n != NULL) {
        printf("%c ", n->data);
    }
}