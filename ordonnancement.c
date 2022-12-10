#include "ordonnancement.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void ajoutActivite(proc p, file* f) {
    elem* e = (elem*) malloc(sizeof(elem));
    e->processus = p;
    e->suiv = NULL;

    if (f->queue == NULL) f->tete = e;
    else f->queue->suiv = e;

    f->queue = e;
}

void step(file* f) {
    if (f->queue == NULL) printf("La file est vide.\n");
    else {
        // Ordonnancement non préemptif en Round-Robin avec un quantum égal à (6 - priorité) secondes
        // On retire la tête de la file
        elem* tmp = f->tete;
        if (tmp->suiv != NULL) f->tete = tmp->suiv;

        // On "l'exécute"
        proc p = tmp->processus;
        int duree = tmp->suiv == NULL ? p.dureeExe : 6 - p.prio; // Si le processus est le dernier dans la file, on l'exécute en entier d'un coup
        int dureeRestante = p.dureeExe - duree;
        if (dureeRestante <= 0) duree = p.dureeExe;
        
        // Affichage seconde par seconde dans le tableau
        for (int i = 1; i <= duree; i++) {
            if (tmp->processus.dureeExe > 0) tmp->processus.dureeExe--;
            affichageProgression(tmp, f);
            sleep(1);
        }
        
        if (dureeRestante <= 0) {
            if (tmp->suiv == NULL) {
                f->tete = NULL;
                f->queue = NULL;
            }

            free(tmp);
        } else if (tmp->suiv != NULL) { // On envoie l'élément tmp en queue de file seulement s'il y a encore au moins deux éléments
            f->queue->suiv = tmp;
            f->queue = tmp;
            tmp->suiv = NULL;
        }
    }
}

void run(file* f) {
    while (f->queue != NULL) step(f);
    system("clear");
}

// Permet de remplir la file avec n processus générés aléatoirement et en affiche un résumé
void remplirFile(int n, file* f) {
    srand(time(NULL));
    system("clear");
    printf("Nom\tPriorité\tDurée restante d'exécution (en s)\n");

    for (int i = 0; i < n; i++) {
        proc p;
        char* tmp = (char*) malloc(sizeof(char) * 12);
        p.dureeExe = rand() % DUREEEXEMAX + 1;
        sprintf(tmp, "%d", rand() % 100000); // On veut un nom de processus entre 0 et 99999
        p.nom = tmp;
        p.prio = rand() % 6;

        ajoutActivite(p, f);
        printf("%s\t%d\t\t%d\n", p.nom, p.prio, p.dureeExe);
    }

    printf("\n");
}

// Affiche la progression de l'exécution des processus
void affichageProgression(elem* elemExec, file* f) {
    system("clear");
    proc pExec = elemExec->processus;
    printf(ROUGE "Nom\tPriorité\tDurée restante d'exécution (en s)" NEUTRE "\n%s\t%d\t\t%d\n", pExec.nom, pExec.prio, pExec.dureeExe);

    if (elemExec->suiv != NULL) {
        elem* actuel = f->tete;
        while (actuel != NULL) {
            proc p = actuel->processus;
            printf("%s\t%d\t\t%d\n", p.nom, p.prio, p.dureeExe);

            actuel = actuel->suiv;
        }
    }
}