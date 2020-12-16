/* Auteur : C. Chevreuil
 * Creation : 13/10/2020
 * Modification : 20/10/2020 */

#ifndef __OPERATIONS__
#define __OPERATIONS__

#include <stdlib.h>
#include <stdio.h>
#include "Pile.h"
#include "Outils.h"
#include "Lecture.h"

int addition(Pile ** pile);

int soustraction(Pile ** pile);

int multiplication(Pile ** pile);

int division(Pile ** pile);

int modulo(Pile ** pile);

int factorial(Pile * pile);

int power(Pile ** pile);

int action(Pile ** pile, char c);

int calculator(Pile ** pile, char * line);

#endif