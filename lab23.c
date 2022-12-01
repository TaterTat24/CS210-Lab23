/** lab23.c
* ===========================================================
* Name: Benjamin Tat
* Section: T6
* Project: Lab 23
* Purpose: Practice using structs
* ===========================================================
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "lab23functs.h"

int main() {
    // WRITE CODE HERE AFTER YOU HAVE FINISHED IMPLEMETNING LAB23FUNCTS.C
    int i;

    // Ask the user for the name of the file to read
    char filename[69];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    // Create an array, and fill it using your readPokemonData function
    Pokemon pokemonArray[100];
    int numberPokemon = readPokemonData(filename, pokemonArray);

    // Calculate the CP of all Pokemon using your calculateCombatPower function
    calculateCombatPower(pokemonArray, numberPokemon);

    // Ask the user to type the names of the two Pokemon he/she wishes to compare
    char pokemon1[100];
    char pokemon2[100];
    printf("Enter the name of Pokemon 1: ");
    scanf("%s", pokemon1);

    printf("Enter the name of Pokemon 2: ");
    scanf("%s", pokemon2);

    int match1 = 0;
    int match2 = 0;
    
    // If the user types the name of a Pokemon that does not exist in the array, print an error message and exit
    for (i = 0; i < numberPokemon; i++)  {
        if (strcmp(pokemon1, pokemonArray[i].name) == 0) {
            match1 = 1;
        } else if (strcmp(pokemon2, pokemonArray[i].name) == 0) {
            match2 = 1;
        }
    }

    if (match1 == 0 || match2 == 0) {
        printf("Invalid Pokemon Name\n");
        exit(1);
    }

    // Otherwise, Print the stats of both Pokemon
    printf("Pokemon Stats:\n");
    printPokemon(*getPokemon(pokemon1, pokemonArray, numberPokemon));
    printPokemon(*getPokemon(pokemon2, pokemonArray, numberPokemon));

    // Print the predicted winner
    Pokemon winner = predictWinner(*getPokemon(pokemon1, pokemonArray, numberPokemon), *getPokemon(pokemon2, pokemonArray, numberPokemon));
    printf("%s is predicted to win\n", winner.name);

    return 0;
}