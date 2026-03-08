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

// On alloue un noeudsur le tas et on initialise ses champs
struct tree_node *node_new(int data) {
    struct tree_node *n = malloc(sizeof(struct tree_node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    return n;
}

// // On insere data dans le bst, on met à jour le panrent et on return le nouveau noeud
struct tree_node *bst_insert(struct tree_node **root, int data) {
    struct tree_node *new_node = node_new(data);

    if (*root == NULL) {
        *root = new_node;
        return new_node;
    }

    struct tree_node *current = *root;
    struct tree_node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data){
            current = current->left;
        }
            
        else {
            current = current->right;
        }
            
    }

    new_node->parent = parent;
    if (data < parent->data){
        parent->left = new_node;
    }
        
    else{
        parent->right = new_node;
    }
        

    return new_node;
}