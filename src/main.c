#include <stdio.h>
#include <stdlib.h>
#include "bst.c"


int main() {
    TreeNode root = {
        .data = 'F',
        .left = &(TreeNode){
            .data = 'B',
            .left = &(TreeNode){ .data = 'A', .left = NULL, .right = NULL, },
            .right = &(TreeNode){
            .data = 'D',
            .left = &(TreeNode){ .data = 'C', .left = NULL, .right = NULL, },
            .right = &(TreeNode){ .data = 'E', .left = NULL, .right = NULL, },
            },
        },
        .right = &(TreeNode){
            .data = 'G',
            .left = NULL,
            .right = &(TreeNode){
            .data = 'I',
            .left = &(TreeNode){ .data = 'H', .left = NULL, .right = NULL, },
            .right = NULL,
            },
        },
    };

    printf("Racine : %c\n", root.data);

    printf("Parcours prefixe : ");
    preorder(&root, print_node);
    printf("\n");

    printf("Parcours infixe : ");
    inorder(&root, print_node);
    printf("\n");

    printf("Parcours postfixe : ");
    postorder(&root, print_node);
    printf("\n");

    return 0;
}