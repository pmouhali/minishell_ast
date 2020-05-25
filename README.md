
# Minishell

## AST : Intro

Qu'est ce qu'un Abstract Syntax Tree, comment ça fonctionne : https://ruslanspivak.com/lsbasi-part7/

L'intêret qu'on a trouver à utiliser un ast pour un intépreteur de commande genre Bash, c'est de simplifier la logique au niveau de l'évaluation des commandes, simplifier le code, utiliser une méthode récursive.

On stock que le minimum d'informations :
- Un type pour identifier le type de noeud sur l'arbre
- La commande et ses arguments sous forme de tableau de strings
- Maximum 4 file descriptors pour gérer redirections et pipe

La structure de noeud est la suivante :

    typedef struct	s_node
    {
	      enum e_node_type type;
	      char **args;
	      struct s_node *left;
	      struct s_node *right;
    }				        t_node;
    
Les files descriptors si il y en a sont stockés dans une structure à part. (Pas forcément une idée géniale)

## AST : Représenter les commandes

Chaque node représente un processus à lancer, ou un opérateur.

Une fonction dédiée existe pour chaque type de node. Par exemple, si le node est de type commande, on lance le processus qu'il contient. Si le node est de type PIPE, on va créer un pipe, stocker les files descriptors, evaluer les nodes LEFT et RIGHT, etc...

Liste des opérateurs pris en charge : &&, ||, |, <, >, >>.

**Opérateur ET**

Pour chaque opérateur ET, la commande de droite n'est executée que si la commande de gauche retourne 0 (true).

![repr_and_commands](https://github.com/pmouhali/minishell/blob/tuto/exec_part/and_op_schema.png)

**Opérateur OU**

Pour chaque opérateur OU, la commande de droite n'est executée que si la commande de gauche retourne 1 (false).

![repr_or_commands](https://github.com/pmouhali/minishell/blob/tuto/exec_part/or_op_schema.png)

**Opérateur ET et OU dans la même commande**

Ces deux opérateur ont la plus haute priorité de la liste, et ils sont égaux. La règle à suivre pour construire la commande est celle de la "left-associativity" : https://unix.stackexchange.com/questions/88850/precedence-of-the-shell-logical-operators on regroupe les mêmes opérateurs en partant de la gauche.

Sur le schema, on peut voir trois étapes.

Etape 1 : séparer la commande en 2 avec le dernier opérateur de haute priorité trouvé.

Etape 2 : séparer la partie gauche en 3 en fonction des deux derniers opérateur de haute priorité similaires.

Etape 3 : séparer la partie la plus à gauche en 3 en fonction des deux derniers opérateur de haute priorité similaires.


![repr_multi_command](https://github.com/pmouhali/minishell/blob/tuto/exec_part/multi_and_or_schema.png)

**Pipes et Redirections**

L'opérateur ayant la plus haute priorité après ET et OU est le PIPE.

Les REDIRECTIONS viennent après le PIPE. Les trois différentes redirections peuvent ne pas respecter d'ordre de priorité entres elles, on peut décider qu'elles soient égales ou différentes, peu importe. Elles peuvent être executées dans n'importe quel ordre.

![repr_pipe_redirection_1](https://github.com/pmouhali/minishell/blob/tuto/exec_part/two_pipes_one_redirection.png)

Le premier node évalué est le plus haut. Il est de type PIPE.

La fonction associée au type PIPE effectue les actions suivantes :
- créer un pipe
- stocker les file descriptors dans struct s_options
- evaluer le node de gauche
- swapper les file descriptors dans struct s_options
- fermer un éventuel pipe crée précédemment qui n'est plus utile et empêche un pipeline de fonctionner
- evaluer le node de droite
- fermer le pipe crée
- retourner le resultat de l'evaluation du node de droite

Lorsque le node de gauche est évalué, la fonction associé au type REDIR_OUT_2 (redirection output 2) est appelée. Elle ouvre le fichier passé en argument, et stock le file descriptor correspondant dans struct s_options (remplaçant donc le file descriptor du pipe, ce qui est nécéssaire pour que ce soit celui du fichier qui soit dup2, elle restore le file descriptor du pipe a la fin de son execution). Elle évalue ensuite le node de droite, c'est la commande **ls**.

Puis le node de droite est évalué, c'est encore un node de type PIPE. Même actions que pour le premier pipe. A noter qu'à cet instant précis deux pipes cohabitent dans struct s_options. C'est nécéssaire pour que le processus du milieu puisse lire sur le pipe crée lors de l'evaluation du tout premier node, et écrire sur le pipe crée à cet appel-ci.
Les nodes gauche et droit sont évalués successivement.

**ls** est bien lancé en premier, son output est redirigé dans **file1**, rev est ensuite executé, il n'as rien à lire puisque **ls** n'as pas écrit dans le pipe, puis **cut** est lancé, il n'as rien à lire non plus, donc n'écrira rien. Le résultat est bon. Cette commande est super débile mais c'est un bon exemple.

![repr_pipe_redirection_2](https://github.com/pmouhali/minishell/blob/tuto/exec_part/pipe_three_redirections.png)

Une fois que le node de gauche à été évaluer, les trois nodes de redirections vont être evalué successivement puis le processus sera lancé. Il va se passer précisemment ça :
- **file1** est ouvert, son file descriptor est stocké au bon endroit dans s_struct options : le processus lira depuis **file1**
- **file3** est ouvert, son file descriptor est stocké au bon endroit dans s_struct options : le processus écrira dans **file3**
- **file2** est ouvert, son file descriptor est stocké au bon endroit dans s_struct options : le processus lira depuis **file2**

Le processus est lancé, il lis depuis file2 et écris dans file3, c'est le bon résultat.
On voit bien que l'ordre n'importe pas entre redirections différentes. Donc on peut construire l'ast en suivant l'ordre d'apparition des redirections dans l'input.

## AST : Construire l'AST à partir de la string reçue en input

In progress
