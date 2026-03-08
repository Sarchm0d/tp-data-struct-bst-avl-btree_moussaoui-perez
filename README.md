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

Vous pouvez vous aidez de l’exo-3 en C token, mais surtout expliquez la différence en complexité spatial vs une solution IA utilisant malloc pour le split des tokens (bonus 4 pts)

L'IA fait un malloc pour chaque token pour les mettre dans un tableau, donc ça bouffe de la place en complexité O(n)






Proposer trois arbres (1.5 pts)

    un arbre dit équilibré
        10
      5   15

    un arbre dit non équilibré
        10
      5   15
            18

    un arbre dit dégénéré
        10
          15
            18


Main de base avec arbre statique (2.5 pt)

Expliquer en quoi cette construction « sur la pile » est limitée dès qu’on souhaite insérer ou supprimer des nœuds à l’exécution. Et si cette construction est compatible avec malloc et free (1 pt)

Cette construction sur la pile est limié car on ne peut pas inséré ou supprimer des noeuds pendant que le programme s'execute. De plus, l'arbre disparaitra quand la fonction sera terminé. Ce n'est pas compatible avec malloc et free

Ecrire un main de base qui déclare cette variable root pour la suite (0.5 pt)

Fait (voir main)

Est-ce un BST en suposant l’ordre alphabétique ? (1 pt)

Oui, il s'agit d'un BST avec des lettres. Les premières lettres vont à gauche et celles plus avancés dans l'alphabet à droite. 






Fonctions de traversée d’arbre récursives (2.5 pts)

Adapter ces fonctions pour utiliser correctement process_fn (signatures, appels). (1 pt)

Fait (voir bst.c)

Écrire un callback void print_node(struct tree_node *n) qui affiche n->data. (1 pt)

Fait (voir bst.c)

Que donne le parcours infixe sur l’arbre précédent ? (0.5 pt)

A B C D E F G H I




Transformer en allocation dynamique (5 pts)

Construire à la main le BST résultant de cette séquence d’insertions et dessiner l’arbre (pointeurs left et right). (1 pt)
```
              10
            /    \
           2      25
                /    \
               15    30
              /  \
             12  20
                /  \
               16   24
                \   /
                17 22
```

Quel aurait été le résultat si la séquence initial avait été trié ? (1 pt)

On aurait obtenu un arbre dégénéré

Écrire node_new 

Fait (voir bst.c)

Écrire bst_insert(3 pts)

Fait (voir bst.c)