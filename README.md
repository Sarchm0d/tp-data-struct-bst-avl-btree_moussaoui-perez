# tp-data-struct-bst-avl-btree_moussaoui-perez

# FIFO et LIFO (7 pts)

## Insertion de 1, 2, 3, 4, 5 (3 pts)


### Donnez la séquence de valeurs affichées si S se comporte comme une pile (LIFO).
Comportement Pile
5, 4, 3, 2, 1.


### Donnez la séquence de valeurs affichées si S se comporte comme une file (FIFO).
Comportement FIFO 
1, 2, 3, 4, 5

### Que ce passe t’il si on inverse les opérations de push ? 5, 4, 3, 2, 1 ?
La pile affichera : 1, 2, 3, 4, 5 et la file 5, 4, 3, 2, 1






## Évaluation d’expression


### Donner la séquence d’opérations sur une pile (push/pop) permettant d’évaluer une expression postfixe composée des opérateurs +, -, *, / et d’opérandes entiers positifs. On suppose que l’expression est correcte implicitement. (1 pt)

En gros, pour évaluer une expression postfixe, il nous faut parcourir la chaîne de gauche à droite
Si c’est un nombre, on le met sur la pile avec un push.
Si c’est un opérateur, on fait deux pop pour récupérer les deux derniers nombres, on fait le calcul, et on fait un push du résultat sur la pile

### Appliquer cette méthode d’évaluation à l’expression postfixe suivante (1 pt) : 3 4 + 2 * (qui correspond en infixe à (3 + 4) * 2) En détaillant : le contenu de la pile après chaque lecture de symbole, En détaillant : les opérations effectuées lors de la rencontre d’un opérateur.

Pour évaluer 3 4 + 2 *, il faut lire le 3 et on le met direct sur la pile. Après on lit le 4 et on le pose par-dessus le 3. Quand on arrive sur le +, on récupère le 4 et le 3 pour faire l'addition, ce qui nous donne 7 et on remet sur la pile. Ensuite on lit le 2 et on le rajoute au-dessus du 7. Pour finir, on tombe sur le *, du coup on ressort le 2 et le 7 pour faire la multiplication. Ça nous donne 14

### Vous pouvez vous aidez de l’exo-3 en C token, mais surtout expliquez la différence en complexité spatial vs une solution IA utilisant malloc pour le split des tokens (bonus 4 pts)

L'IA fait un malloc pour chaque token pour les mettre dans un tableau, donc ça bouffe de la place en complexité O(n)






### Proposer trois arbres (1.5 pts)

### un arbre dit équilibré
        10
      5   15

### un arbre dit non équilibré
        10
      5   15
            18

### un arbre dit dégénéré
        10
          15
            18


## Main de base avec arbre statique (2.5 pt)

### Expliquer en quoi cette construction « sur la pile » est limitée dès qu’on souhaite insérer ou supprimer des nœuds à l’exécution. Et si cette construction est compatible avec malloc et free (1 pt)

Cette construction sur la pile est limié car on ne peut pas inséré ou supprimer des noeuds pendant que le programme s'execute. De plus, l'arbre disparaitra quand la fonction sera terminé. Ce n'est pas compatible avec malloc et free

### Ecrire un main de base qui déclare cette variable root pour la suite (0.5 pt)

Fait (voir main)

### Est-ce un BST en suposant l’ordre alphabétique ? (1 pt)

Oui, il s'agit d'un BST avec des lettres. Les premières lettres vont à gauche et celles plus avancés dans l'alphabet à droite. 






## Fonctions de traversée d’arbre récursives (2.5 pts)

### Adapter ces fonctions pour utiliser correctement process_fn (signatures, appels). (1 pt)

Fait (voir bst.c)

### Écrire un callback void print_node(struct tree_node *n) qui affiche n->data. (1 pt)

Fait (voir bst.c)

### Que donne le parcours infixe sur l’arbre précédent ? (0.5 pt)

A B C D E F G H I






## Transformer en allocation dynamique (5 pts)

### Construire à la main le BST résultant de cette séquence d’insertions et dessiner l’arbre (pointeurs left et right). (1 pt)

              10
           2      25               
               15    30   
             12  20     
               16   24   
                17 22


### Quel aurait été le résultat si la séquence initial avait été trié ? (1 pt)

On aurait obtenu un arbre dégénéré

### Écrire node_new 

Fait (voir bst.c)

### Écrire bst_insert(3 pts)

Fait (voir bst.c)






## Fonctions de traversée d'arbre itératives (5 pts)

### Proposer une version itérative de preorder et inorder (4 pts)

Fait (voir preorder_iter et inorder_iter dans bst.c)

### Expliquer la stratégie générale (1 pt)

On utilise le pointeur parent déjà dans la structure pour remonter l'arbre sans pile ni champ supplémentaire. Quand on ne peut plus descendre, on remonte via le neoudparent pour trouver le prochain noeud à visiter dans l'ordre que l'on veut

### Comparaison de complexité récursif vs itératif (bonus 4 pts)

Complexité de O(n) dans les deux cas, chaque noeud est visité une seule fois






## Mettre en œuvre tree_delete (4 pts)

### Implémenter tree_delete en gérant les trois cas : (2 pts)

Fait (voir tree_delete dans bst.c)

### Sur le BST de référence, dessiner l’arbre après : (1 pt)
Arbre de base :
              10
           2      25               
               15    30   
             12  20     
               16   24   
                17 22

### tree_delete(&root, 24),
Après tree_delete(&root, 24) — 24. Le 22 a disparu :
              10
           2      25
               15    30
             12  20  
               16   22
                17

### puis tree_delete(&root, 15) (en partant du résultat précédent).
Après tree_delete(&root, 15) — 15 :
              10
           2      25
               16    30
             12  20
               17   22


### Discuter si l’opération est commutative du point de vue de la structure résultante de l’arbre.

La suppression n'est pas commutative en général.

## Variante de tree_delete avec prédécesseur (3 pts)

### Modifier tree_delete pour qu’elle utilise le prédécesseur comme nœud de remplacement dans le cas « deux enfants ». (1 pt) 

Fait (voir tree_delete_pred dans bst.c)

### Appliquer successivement les opérations : suppression de 25, puis de 20, puis de 10, avec la version successeur et la version prédécesseur. Comparer les structures obtenues (par exemple en termes de hauteur ou d’« équilibrage » visuel). (1 pt)

Avec le successeur, ca reduit les sous-arbres droits (on remonte depuis la droite). Avec le prédécesseur, ca réduit les sous arbres gauches. 

### Proposer une version de tree_delete qui choisit aléatoirement, pour chaque suppression de nœud à deux enfants, entre successeur et prédécesseur. Discuter l’intérêt de cette randomisation du point de vue de la forme moyenne de l’arbre. (1 pt)

C'est long

## Variante de tree_delete avec prédécesseur (3 pts)

Je passe à la suite sinon j'aurais pas le temps de finir






## Arbres AVL (15 pts)

### Les deux arbres construits dans la partie BST (entiers et lettres) satisfont‑ils la condition AVL ? Justifier votre réponse.

L'arbre F, B, G, A, D, C, E, I, H n'est pas un AVL car le nœud G a un sous arbre droit de hauteur 2  et un sous arbre gauche de hauteur 0

L'arbre 10, 2, 25, 15, 30, 12, 20, 16, 24, 17, 22 n'est pas non plus un AVL car plusieurs nœuds ont un déséquilibre > 1

### Si ce n’est pas le cas, proposer une nouvelle version équilibrée contenant les mêmes clés.
              16
          12        22
        10  15    20   25
      2   12    17   24   30

### Montrer qu’un AVL contenant n nœuds a une hauteur en Olog.
Pass

### Préciser si l’on parle de Log2(n) ou Log10(n)

On parle en log₂(n) car les arbres binaires se divisent en 2 à chaque fois

### Pourquoi cette distinction n’affecte pas la classe de complexité et que l’on parle simplement de O(log n)

Changer de base revient à multiplier par une constante, or O ignore les constante. Donc log2(n) et log10(n) sont compris dans  O(log n)

### Justifier que avl_insert a une complexité en O(log n) et effectue un nombre O(1) de rotations par insertion.

L'arbre AVL a une hauteur en O(log n), l'insertion descend au max de O(log n) n. Une fois inséré, on remonte pour rééquilibrer, mais on fait au maximum 2 rotations, donc O(1) rotations par insertion.





## Rotations (7 pts)

### Décrire les quatre cas classiques de rotation (LL, RR, LR, RL), en explicitant les préconditions sur les facteurs d'équilibre des nœuds impliqués. (2 pt)

LL : trop lourd à gauche, enfant gauche penche à gauche = rotation droite
RR : trop lourd à droite, enfant droit penche à droite = rotation gauche
LR : trop lourd à gauche, enfant gauche penche à droite = rotation gauche sur l'enfant puis rotation droite
RL : trop lourd à droite, enfant droit penche à gauche = rotation droite sur l'enfant puis rotation gauche

### Discuter pourquoi, pour une insertion donnée, le nombre total de rotations nécessaires est borné par une constante indépendante de la taille de l'arbre. (1 pt)

On fait au max 2 rotations par insertion. Donc une fois rééquilibré, le déséquilibre ne va pas plus haut.

### Écrire la fonction : avl_node *avl_balance(avl_node *x); (4 pts)

Fait (voir avl_balance dans avl.c)

## Fonction avl_insert(x) (2 pts)

### L’insertion dans un AVL suit la logique d’insertion dans un BST, puis opère un rééquilibrage le long du chemin de remontée. Écrire la fonction :avl_node *avl_insert(avl_node *root, avl_node *x); en supposant left(x) = right(x) = parent(x) = NULL au départ. Avec une stratégie pour avl_insert, qui insère le nœud comme dans un BST (facile) puis remonte et appelle avl_balance sur les nœuds concernés. (2 pts)

Fait (voir avl_insert dans avl.c)




