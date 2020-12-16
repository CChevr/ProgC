/* Auteur : C. Chevreuil
 * Creation : 13/10/2020
 * Modification : 20/10/2020 */
 
#include "Outils.h"

int queChiffres(char * chaine){
    /*
    Verifie que la chaine de caractère passée en parametre
    n'est composée que de chiffres.
    Retourne 1 si c'est bien le cas, 0 sinon.
    */
    int i;

    for(i = 0; chaine[i] != '\0'; i++){
        if((chaine[i] < '0') || (chaine[i] > '9')){
            return 0;
        }
    }

    return 1;
}

int factCompute(int nb){
    /*
    Retourne le factoriel d'un entier passé en parametre
    */
    if(nb <= 1){
        return 1;
    }
    return nb * factCompute(nb - 1);
}

int powCompute(int nb1, int nb2){
    /*
    Retourne nb1 a la puissance nb2.
    */
    if(0 >= nb2){
        return 1;
    }
    return (nb1 * powCompute(nb1, (nb2 - 1)));
}