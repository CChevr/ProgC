/* Auteur : C. Chevreuil
 * Creation : 13/10/2020
 * Modification : 20/10/2020 */

#include "Lecture.h"

int lire_line(char ** ligne){
    /*
    Lit la chaine de caractère écrite dans le terminal
    et la stocke dans ligne.
    Retourne 1 si la lecture s'est bien passé, 0 s'il 
    s'agit de la fin de la saisie.
    */

    *ligne = readline("");    

    if(NULL == *ligne){
        return 0;       /*Fin de traitement*/
    }

    return 1;
}

int lire(char * line, char * chaine, int * indice, int * size){
    /*
    Parcourt la chaine line et stock la première chaine de
    caractère rencontrée à partir de l'indice indice, et stocke
    le nombre de caractères rencontré dans size.
    Si une expression de la ligne a plus de CONST_NB_SIZE caractères
    alors la ligne ne sera pas lue.
    retourne 0 si l'on est a la fin du fichier, 1 sinon.
    */

    for(*size = 0; (line[*indice + *size] != ' ') && (line[*indice + *size] != '\0'); (*size)++){
        if(*size >= (CONST_NB_SIZE - 1)){
            printf("Expression with too many caracteres\n");
            return 0;
        }

        chaine[*size] = line[*indice + (*size)];
    }

    if(('\0' == line[*size + *indice]) && (*size == 0)){
        return 0;
    }

    chaine[*size] = '\0';
    *indice += (*size + 1);

    return 1;
}