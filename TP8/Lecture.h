/* Auteur : C. Chevreuil
 * Creation : 13/10/2020
 * Modification : 20/10/2020 */

#ifndef __LECTURE__
#define __LECTURE__

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#define CONST_NB_SIZE 12

int lire_line(char ** ligne);

int lire(char * line, char * chaine, int * indice, int * size);

#endif