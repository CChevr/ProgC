#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    struct dirent ** namelist;
    int n;
    int i;

    n = scandir(".so", &namelist, NULL, alphasort);
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