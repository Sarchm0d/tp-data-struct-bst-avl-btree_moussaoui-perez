#include <stdio.h>
#include <stdlib.h>
#include "../src/eval_postfix.c"

int test_eval_postfix() {
    // Expression à tester : (3 + 4) * 2 = 14
    const char *expr = "3 4 + 2 *";

    int resultat = eval_postfix(expr);
   
    printf("L'expression '%s' donne : %d\n", expr, resultat);
    
    return 0;
}
