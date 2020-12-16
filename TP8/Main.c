/* Auteur : C. Chevreuil
 * Creation : 13/10/2020
 * Modification : 20/10/2020 */

#include <stdlib.h>
#include <stdio.h>

#include "Pile.h"
#include "Lecture.h"
#include "Operations.h"


int main(int argc, char * argv[]){
    Pile *  pile;
    char * chaine;
    int err;
    
    pile = NULL;
    chaine = NULL;

    do{ 
        if(NULL != chaine){
            free(chaine);
        }
        
        if(!lire_line(&chaine)){
            return 1;
        }

    }while(1 == (err = calculator(&pile, chaine)));

    if(err == -1)
        return 1;
    else
        return 0;
}