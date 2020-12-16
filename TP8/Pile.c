/* Auteur : C. Chevreuil
 * Creation : 13/10/2020
 * Modification : 20/10/2020 */

#include "Pile.h"

void freePile(Pile ** pile){
    /*
    Libère de la mémoire une variable de type Pile.
    */
    if(NULL != *pile){
        freePile(&(*pile)->next);
        (*pile)->next = NULL;
        free(*pile);
        *pile = NULL;
    }
}

int allouePile(Pile ** pile, int number){
    /*
    Alloue l'espace mémoire nécessaire à une structure de type Pile.
    Retourne 1 si l'allocation s'est bien passée, 0 sinon.
    */
    *pile = (Pile*) malloc(sizeof(Pile));

    if(NULL == *pile){
        printf("Erreur lors de l'allocation mémoire de Pile.\n");
        return 0;
    }

    (*pile)->number = number;

    return 1;
}

int addNumber(Pile ** pile, int number){
    /*
    Ajoute le nombre number passé en argument en tête de 
    la liste chaînée.
    Retourne 1 si l'ajout s'est bien passé, 0 sinon.
    */
    Pile * elem;

    if(!allouePile(&elem, number)){
        return 0;
    }

    elem->next = *pile;
    *pile = elem;

    return 1;
}

int removeNumber(Pile ** pile, int * number){
    /*
    Retire le premier élément de la pile "pile".
    Retourne 1 si le retrait s'est bien passé, 0 sinon.
    */
    Pile * tempo;

    if(NULL == *pile){
        return 0;
    }

    *number = (*pile)->number;

    tempo = (*pile)->next;
    free(*pile);
    *pile = tempo;

    return 1;
}

void printNumber(Pile * pile){
    /*
    Affiche le nombre en haut de la pile.
    */
   if(NULL != pile){
       printf("%d\n", pile->number);
   }
}

void printPile(Pile * pile){
    /*
    Affiche tous les nombres de la pile.
    */
    while(NULL != pile){
        printf("%d\n", pile->number);
        pile = pile->next;
    }
}

int reverseHead(Pile ** pile){
    /*
    Change l'ordre des deux premières valeurs de la pile.
    Renvoie 1 s'il y a eu inversion, 0 sinon.
    */
    Pile * temp;

    if(NULL == *pile){
        return 0;
    }
    if(NULL == (*pile)->next){
        return 0;
    }

    temp = (*pile)->next;
    (*pile)->next = temp->next;
    temp->next = *pile;
    *pile = temp;

    return 1;
}

int checkPile(Pile * pile, int nb){
    /*
    vérifie qu'il y a au moins nb éléments dans la liste
    chainée pile.
    Retourne 1 s'il y a plus de nb éléments dans pile, 0 sinon.
    */
    int i;

    for(i = 0; i < nb; i++){
        if(NULL == pile){
            return 0;
        }
        pile = pile->next;
    }

    return 1;
}