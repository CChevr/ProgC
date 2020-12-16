/* Auteur : C. Chevreuil
 * Creation : 13/10/2020
 * Modification : 20/10/2020 */

#ifndef __PILE__
#define __PILE__

#include <stdlib.h>
#include <stdio.h>

typedef struct _pile{
    int number;
    struct _pile * next;
}Pile;

void freePile(Pile ** pile);

int allouePile(Pile ** pile, int number);

int addNumber(Pile ** pile, int number);

int removeNumber(Pile ** pile, int * number);

void printNumber(Pile * pile);

void printPile(Pile * pile);

int reverseHead(Pile ** pile);

int checkPile(Pile * pile, int nb);

#endif