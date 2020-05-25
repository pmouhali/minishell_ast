
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

SCHEMA

**Opérateur ET et OU dans la même commande**

Ces deux opérateur ont la plus haute priorité de la liste, et ils sont égaux. La règle à suivre pour construire la commande est celle de la "left-associativity" : https://unix.stackexchange.com/questions/88850/precedence-of-the-shell-logical-operators on regroupe les mêmes opérateurs en partant de la gauche.

SCHEMAS

## AST : Construire l'AST à partir de la string reçue en input

In progress
