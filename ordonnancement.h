#define DUREEEXEMAX 20
#define ROUGE "\033[1m\033[31m"
#define NEUTRE "\033[0m"

typedef struct Proc {
    char* nom;
    int dureeExe;
    int prio;
} proc;

typedef struct Elem {
    proc processus;
    struct Elem* suiv;
} elem;

typedef struct File {
    elem* tete;
    elem* queue;
} file;

void ajoutActivite(proc, file*);
void step(file*);
void run(file*);
void remplirFile(int, file*);
void affichageProgression(elem*, file*);