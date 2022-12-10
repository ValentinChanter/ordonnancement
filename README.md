
<div align="center">
  <p>
    <img src="https://i.imgur.com/5YxFp3m.png" width="546" alt="Sujet 2" />
  </p>
</div>

## A propos

Ce TP consiste en la réalisation de deux travaux distincts : 
* Le premier travail est divisé en deux parties :
    * La première permet de prédire le prix d'une habitation destinée à être mise en location sur Airbnb
    * La deuxième, bonus, permet d'évaluer la performance du modèle de prédiction
* Le deuxième travail simule l'ordonnancement d'un processus

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

## Options supplémentaires

Une constante est définie par défaut dans le fichier ordonnancement.h et est modifiable au besoin.

* `DUREEEXEMAX` correspond à la durée d'exécution maximale qu'un processus peut prendre (par défaut 20)