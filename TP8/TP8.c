#define _DEFAULT_SOURCE
#include <dirent.h>
#include <dlfcn.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define PATH    "./plugins/"
#define EXT     ".so"

typedef struct{
    char * name;
    char sym;
    int nbArgs;
}Function;

static int sel_lib(const struct dirent *file){
    /*
    prends un direct en parametre, retourne 1 si l'extension du fichier
    correspondant est la même que EXT (.so), 0 sinon.
    */
    if(!file)
        return 0;
    
    char * ext = strchr(file->d_name, '.');

    if(!ext)
        return 0;
    
    if(strcmp(ext, EXT) == 0)
        return 1;

    return 0;
}

int allocTabFunc(Function ** funcTab, int nbFunc){
    /*
    Alloue l'espace mémoire nécessaire à un tableau de Function de nbFunc éléments.
    Retourne 1 si l'allocation s'est bien déroulée, 0 sinon.
    */
    *funcTab = (Function*) malloc(nbFunc * sizeof(funcTab));

    if(NULL == *funcTab){
        printf("Erreur lors de l'allocation du tableau de Function.\n");
        return 0;
    }
}

int initTabFunc(Function * funcTab, struct dirent ** namelist, int nbElem){
    /*
    Initialise le tableau de Function funcTab à l'aide de namelist
    */
    void * lib;
    int i;

    assert(NULL != funcTab);
    assert(NULL != namelist);
    assert(nbElem >= 0);
    
    for(i = 0; i < nbElem; i++){
        lib = dlopen(namelist[i]->d_name, RTLD_LAZY);

        if(!lib){
            fprintf(stderr, "Erreur lors du chargement de la lib : %s.\n", namelist[i]);
            return 0;
        }
        
    }
    return 1;
}

int initFunc(Function * func, char * name, char sym, int nbArgs){
    /*
    Initialise la func passé en parametre.
    Retourne 1 si l'initialisation s'est bien passé, 0 sinon.
    */
    if(NULL == func)
        return 0;
    
    strcpy(func->name, name);
    func->sym = sym;
    func->nbArgs = nbArgs;

    return 1;
}



int main(int argc, char * argv[]){
    Function * funcTab;
    struct dirent ** namelist;
    void * lib;
    int n;
    int i;

    n = scandir(PATH, &namelist, sel_lib, alphasort);
    if(-1 == n){
        fprintf(stderr, "Aucun fichier trouvé.\n");
        return 0;
    }


    /*Libération funcTab*/
    free(funcTab);

    /*Libération de namelist*/
    while(n--){
        free(namelist[n]);
    }

    free(namelist);
    return 1;
}