#include <stdlib.h>

int eval_postfix(const char *expr) {
    // Pile pour stocker max 100 nombres (100*4=400 octets)
    int *stack = malloc(100 * sizeof(int));
    
    // top = -1 alors pile vide. Quand top >= 0, y'a des trucs dedans
    int top = -1;
    int i = 0;

    // On lit toute la string jusqu'à le '\0', donc la la fin 
    while (expr[i] != '\0') {
        
        // On ignore les espaces
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        // Si c'est un chiffre (0-9)
        if (expr[i] >= '0' && expr[i] <= '9') {
            int num = 0;
            
            // On lit tous les chiffres d'affilée
            while (expr[i] >= '0' && expr[i] <= '9') {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            
            // On met le nombre sur la pile
            top++;
            stack[top] = num;
        } 
        // Sinon c'est un opérateur 
        else {
            // On dépile les 2 derniers nombres
            int val2 = stack[top];
            top--;
            
            int val1 = stack[top];
            top--;
            
            int res = 0;

            // On calcule selon l'opérateur
            if (expr[i] == '+') {
                res = val1 + val2;
            }
            else if (expr[i] == '-') {
                res = val1 - val2;
            }
            else if (expr[i] == '*') {
                res = val1 * val2;
            }
            else if (expr[i] == '/') {
                if (val2 != 0) {  // Évite division par 0
                    res = val1 / val2;
                } else {
                    res = 0;  // Par sécurité
                }
            }

            // On remet le résultat sur la pile
            top++;
            stack[top] = res;
            
            i++;  // On passe à l'opérateur suivant
        }
    }

    // Le résultat final est au sommet
    int resultat = stack[top];
    
    free(stack);  // On libère la mémoire
    
    return resultat;
}
