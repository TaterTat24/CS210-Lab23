/** lab23functs.c
* ===========================================================
* Name: Benjamin Tat
* Section: T6
* Project: Lab 23
* Purpose: Practice using structs
* ===========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab23functs.h"

int readPokemonData(char filename[], Pokemon array[]) {
    int numberPokemon = 0;
    
    FILE* myFile  = NULL;
    myFile = fopen(filename, "r");
    
    while (!feof(myFile)) {
        fscanf(myFile, "%s %d %d %d %d", array[numberPokemon].name, &array[numberPokemon].hp, &array[numberPokemon].attack, &array[numberPokemon].defense, &array[numberPokemon].speed);
        numberPokemon = numberPokemon + 1;
    }

    fclose(myFile);
    return numberPokemon;
}

void printPokemon(Pokemon pokemon) {
    printf("%s (HP:%d, Attack:%d, Defense:%d, Speed:%d, CP:%.1f)\n", pokemon.name, pokemon.hp, pokemon.attack, pokemon.defense, pokemon.speed, pokemon.cp);

}

void calculateCombatPower(Pokemon array[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        array[i].cp = (0.3 * array[i].attack) + (0.2 * array[i].defense) + (0.4 * array[i].hp) + (0.1 * array[i].speed);
    }
}

Pokemon* getPokemon(char* name, Pokemon array[], int size) {
    int i;
    Pokemon* pointer = NULL;

    for (i = 0; i < size; i++) {
        if (strcmp(name, array[i].name) == 0) {
            pointer = &array[i];
        }
    }
    return pointer;
}

Pokemon predictWinner(Pokemon pokemon1, Pokemon pokemon2) {
    if (pokemon1.cp >= pokemon2.cp) {
        return pokemon1;
    }
    else {
        return pokemon2;
    }
}