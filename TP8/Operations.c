/* Auteur : C. Chevreuil
 * Creation : 13/10/2020
 * Modification : 20/10/2020 */

#include "Operations.h"

int addition(Pile ** pile){
    /*
    Fait la somme des deux premiers nombres de la pile, et met le résultat en haut
    de la pile.
    Renvoie 0 en cas d'erreur, 1 sinon.
    */
    int nb1, nb2;

    if(!checkPile(*pile, 2)){
        printf("Stack empty\n");
        return 1;
    }

    if(!removeNumber(pile, &nb1)){
        return 0;
    }

    nb2 = (*pile)->number;

    (*pile)->number = (nb1 + nb2);

    return 1;
}

int soustraction(Pile ** pile){
    /*
    Fait la différence des deux premiers nombres de la pile, et met le résultat en haut
    de la pile.
    Renvoie 0 en cas d'erreur, 1 sinon.
    */
    int nb1, nb2;

    if(!checkPile(*pile, 2)){
        printf("Stack empty\n");
        return 1;
    }

    if(!removeNumber(pile, &nb1)){
        return 0;
    }

    nb2 = (*pile)->number;

    (*pile)->number = nb2 - nb1;

    return 1;
}

int multiplication(Pile ** pile){
    /*
    Fait le produit des deux premiers nombres de la pile, et met le résultat en haut
    de la pile.
    Renvoie 0 en cas d'erreur, 1 sinon.
    */
    int nb1, nb2;

    if(!checkPile(*pile, 2)){
        printf("Stack empty\n");
        return 1;
    }

    if(!removeNumber(pile, &nb1)){
        return 0;
    }

    nb2 = (*pile)->number;

    (*pile)->number = nb2*nb1;

    return 1;
}

int division(Pile ** pile){
    /*
    Fait le quotient des deux premiers nombres de la pile, et met le résultat en haut
    de la pile.
    Renvoie 0 en cas d'erreur, 1 sinon.
    */
    int nb1, nb2;

    if(!checkPile(*pile, 2)){
        printf("Stack empty\n");
        return 1;
    }

    if(0 == (*pile)->number){
        printf("divide by zero\n");
        return 0;
    }

    if(!removeNumber(pile, &nb1)){
        return 0;
    }

    nb2 = (*pile)->number;

    (*pile)->number = nb2/nb1;

    return 1;
}

int modulo(Pile ** pile){
    /*
    Fait le module des deux premiers nombres de la pile, et met le résultat en haut
    de la pile.
    Renvoie 0 en cas d'erreur, 1 sinon.
    */
    int nb1, nb2;

    if(!checkPile(*pile, 2)){
        printf("Stack empty\n");
        return 1;
    }

    if(0 == (*pile)->number){
        printf("divide by zero\n");
        return 0;
    }

    if(!removeNumber(pile, &nb1)){
        return 0;
    }

    nb2 = (*pile)->number;

    (*pile)->number = nb2%nb1;

    return 1;
}

int factorial(Pile * pile){
    /*
    Fait le facteur du premier nombre de la pile, et met le résultat en haut
    de la pile.
    Renvoie 0 en cas d'erreur, 1 sinon.
    */
    int nb1;

    if(!checkPile(pile, 1)){
        printf("Stack empty\n");
        return 1;
    }

    if((pile->number) < 0){
        printf("divide by zero\n");
        return 0;
    }

    nb1 = pile->number;

    pile->number = factCompute(nb1);

    return 1;
}



int power(Pile ** pile){
    /*
    Fait le quotient des deux premiers nombres de la pile, et met le résultat en haut
    de la pile.
    Renvoie 0 en cas d'erreur, 1 sinon.
    */
    int nb1, nb2;

    if(!checkPile(*pile, 2)){
        printf("Stack empty\n");
        return 1;
    }

    if(!removeNumber(pile, &nb1)){
        return 0;
    }

    nb2 = (*pile)->number;

    (*pile)->number = powCompute(nb2, nb1);

    return 1;
}

int action(Pile ** pile, char c){
    /*
    Traite toutes les options possibles par l'utilisateur sur
    la pile pile en fonction du caractère "c".
    */
    switch(c){
        case '+' :
            return addition(pile);
        case '-' :
            return soustraction(pile);
        case '*' :
            return multiplication(pile);
        case '/' :
            return division(pile);
        case '%' :
            return modulo(pile);
        case '!' :
            return factorial(*pile);
        case '^' :
            return power(pile);
        case 'q' :
            return 0;
        case 'p' :
            printNumber(*pile);
            break;
        case 'c' :
            freePile(pile);
            break;
        case 'a' :
            printPile(*pile);
            break;
        case 'r' :
            return reverseHead(pile);
        default:
            return 0;
    }

    return 1;
}

int calculator(Pile ** pile, char * line){
    /*
    Parcourt la ligne de commande saisie et remplie
    les actions correspondantes.
    Retourne 1 si tout si l'on est arrivé au bout de la ligne,
    0 si l'utilisateur a demandé à arreter le programme, et -1
    s'il y a eu un soucis.
    */
    char chaine[CONST_NB_SIZE];
    int indice;
    int size;
    int err;

    indice = 0;
    size = 0;
    while(lire(line, chaine, &indice, &size)){

        if(0 == size){    /*Eviter que les espaces soient pris pour des 0*/
            continue;
        }

        if(queChiffres(chaine)){
            if(!addNumber(pile, atoi(chaine))){
                return 0;
            }
        }

        else if(size == 1){
            if(0 >= (err = action(pile, chaine[0]))){
                return err;
            }
        }
    }

    return 1;
}