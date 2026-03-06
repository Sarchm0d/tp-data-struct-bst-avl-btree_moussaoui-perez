# tp-data-struct-bst-avl-btree_moussaoui-perez

FIFO et LIFO (7 pts)

Insertion de 1, 2, 3, 4, 5 (3 pts)


Donnez la séquence de valeurs affichées si S se comporte comme une pile (LIFO).
Comportement Pile
5, 4, 3, 2, 1.


Donnez la séquence de valeurs affichées si S se comporte comme une file (FIFO).
Comportement FIFO 
1, 2, 3, 4, 5

Que ce passe t’il si on inverse les opérations de push ? 5, 4, 3, 2, 1 ?
La pile affichera : 1, 2, 3, 4, 5 et la file 5, 4, 3, 2, 1






Évaluation d’expression


Donner la séquence d’opérations sur une pile (push/pop) permettant d’évaluer une expression postfixe composée des opérateurs +, -, *, / et d’opérandes entiers positifs. On suppose que l’expression est correcte implicitement. (1 pt)

En gros, pour évaluer une expression postfixe, il nous faut parcourir la chaîne de gauche à droite
Si c’est un nombre, on le met sur la pile avec un push.
Si c’est un opérateur, on fait deux pop pour récupérer les deux derniers nombres, on fait le calcul, et on fait un push du résultat sur la pile

Appliquer cette méthode d’évaluation à l’expression postfixe suivante (1 pt) :
    3 4 + 2 * (qui correspond en infixe à (3 + 4) * 2)
    En détaillant : le contenu de la pile après chaque lecture de symbole,
    En détaillant : les opérations effectuées lors de la rencontre d’un opérateur.

Pour évaluer 3 4 + 2 *, il faut lire le 3 et on le met direct sur la pile. Après on lit le 4 et on le pose par-dessus le 3. Quand on arrive sur le +, on récupère le 4 et le 3 pour faire l'addition, ce qui nous donne 7 et on remet sur la pile. Ensuite on lit le 2 et on le rajoute au-dessus du 7. Pour finir, on tombe sur le *, du coup on ressort le 2 et le 7 pour faire la multiplication. Ça nous donne 14

