# push_swap

    “Parce que Swap_push, c’est moins naturel.”

Ce projet consiste à trier une liste d'entiers en utilisant uniquement un ensemble limité d'instructions, avec le moins d'opérations possible, en développant ta compréhension des algorithmes de tri et de leur complexité.<br>

## 📚 Description

push_swap est un programme en C qui :

    Prend en argument une pile a d'entiers uniques à trier.

    Affiche la suite d'instructions Push Swap permettant de trier la pile avec un nombre minimal d'opérations.

    Utilise uniquement les instructions autorisées :

        sa, sb, ss (swap)

        pa, pb (push)

        ra, rb, rr (rotate)

        rra, rrb, rrr (reverse rotate)

Le but est de minimiser le nombre d’instructions pour valider les performances demandées par le projet tout en respectant les contraintes de norme et de gestion mémoire.<br>

## 🚀 Fonctionnalités

✅ Tri d’une pile d’entiers avec le nombre minimal d’opérations<br>
✅ Gestion des erreurs (paramètres invalides, doublons, hors int)<br>
✅ Aucun affichage si aucun argument fourni<br>
✅ Aucune variable globale<br>
✅ Respect des performances :

    Trier 100 nombres aléatoires en < 700 instructions

    Trier 500 nombres aléatoires en < 5500 instructions

## ⚙️ Compilation

Un Makefile est fourni avec les règles :

    $(NAME), all, clean, fclean, re

Compiler avec :

make

## 🖥️ Utilisation

./push_swap [liste d'entiers]

Exemple :

./push_swap 2 1 3 6 5 8

Affichera une suite d'instructions comme :

sa
pb
pb
pb
sa
pa
pa
pa

Pour tester automatiquement le résultat :

ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG

Résultat :

OK

Pour compter le nombre d'opérations :

ARG="4 67 3 87 23"
./push_swap $ARG | wc -l

## 🧪 Tests recommandés

✅ Avec doublons ou non-entier :

./push_swap 0 one 2 3

Affiche :

Error

✅ Sans argument :

./push_swap

Ne doit rien afficher.

✅ Performance avec checker :

ARG="2 1 3"
./push_swap $ARG | ./checker $ARG

Doit afficher :

OK

## 🎯 Objectifs pédagogiques

    Compréhension et implémentation d’algorithmes de tri efficaces.

    Gestion optimisée des piles et de leurs manipulations.

    Respect de la norme 42 sans fuites mémoire.

    Développement d’un esprit d’optimisation d’algorithmes.

    Compréhension des complexités et adaptation selon la taille et la nature des données.

## 📂 Structure du projet

push_swap/
├── Makefile
├── push_swap.c
├── checker.c (bonus)
├── src/
│   ├── parsing.c
│   ├── sorting.c
│   ├── operations.c
│   └── utils.c
└── includes/
    └── push_swap.h

✅ Rendu et évaluation<br>

✅ Code conforme norme<br>
✅ Aucun crash ni comportement indéfini<br>
✅ Pas de fuites mémoire<br>
✅ Respect des performances demandées<br>
✅ Fonctionnalité complète et stable<br>

## 📌 Références utiles<br>

    Wiki Stack (abstract data type)

    Analyse des algorithmes

    Documentation du projet push_swap (42 Intranet)

