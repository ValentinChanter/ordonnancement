
<div align="center">
  <p>
    <img src="https://i.imgur.com/5YxFp3m.png" width="546" alt="Sujet 2" />
  </p>
</div>

## A propos

Ce sujet consiste en la simulation de l'ordonnancement d'un processus en Round-Robin avec un quantum de 6 - priorité. La priorité d'un processus est comprise entre 0 et 5.

## Pour commencer


### Prérequis

* gcc (ou un autre compilateur en C)
* Un ordinateur sous Linux (l'application a été testée sur Ubuntu 20.04.5)

### Mise en place lors de la première utilisation

1. Ouvrez un terminal et placez-vous dans le répertoire dans lequel se trouvent le Makefile et les fichiers .c et .h
2. Compilez à l'aide du Makefile
   ```sh
   make
   ```
3. (Optionnel) Supprimez les fichiers .o
   ```sh
   make clean
   ```

## Usage

1. Suivez les instructions affichées par le terminal : renseignez le nombre de processus que vous voulez générer aléatoirement
2. Le terminal affichera l'exécution des processus

## Option supplémentaire

Une constante est définie par défaut dans le fichier ordonnancement.h et est modifiable au besoin.

* `DUREEEXEMAX` correspond à la durée d'exécution maximale qu'un processus peut prendre (par défaut 20)
