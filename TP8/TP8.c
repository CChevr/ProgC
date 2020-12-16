#define _DEFAULT_SOURCE
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define PATH    "./plugins/"
#define EXT     ".so"

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

int main(int argc, char * argv[]){
    struct dirent ** namelist;
    int n;
    int i;

    n = scandir(PATH, &namelist, sel_lib, alphasort);
    if(-1 == n){
        fprintf(stderr, "Aucun fichier trouvé.\n");
        return 0;
    }

    for(i = 0; i < n; i++){
        printf("%s\n", namelist[i]->d_name);
    }

    /*Libération de namelist*/
    while(n--){
        free(namelist[n]);
    }

    free(namelist);
    return 1;
}