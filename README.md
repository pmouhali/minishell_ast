
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

![repr_pipe_redirection_2](https://github.com/pmouhali/minishell/blob/tuto/exec_part/pipe_three_redirections.png)

## AST : Construire l'AST à partir de la string reçue en input

In progress
