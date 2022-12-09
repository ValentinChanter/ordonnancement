#include "ordonnancement.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    file* f = (file*) malloc(sizeof(file));
    f->tete = NULL;
    f->queue = NULL;

    int nbProc;
    printf("Combien de processus voulez-vous générer ?\n");
    int retCode = scanf("%d", &nbProc);
    if (!retCode) exit(1);

    remplirFile(nbProc, f);

    run(f);

    free(f);
}