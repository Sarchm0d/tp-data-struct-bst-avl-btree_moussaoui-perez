#include <stdio.h>

// Declaration de la fonction postfix
int eval_postfix(const char *expr);

int main() {
    // Expression à tester : (3 + 4) * 2 = 14
    const char *expr = "3 4 + 2 *";

    int resultat = eval_postfix(expr);
   
    printf("L'expression '%s' donne : %d\n", expr, resultat);
    
    return 0;
}