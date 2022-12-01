/** lab23functs.h
* ===========================================================
* Name: Benjamin Tat
* Section: T6
* Project: Lab 23
* Purpose: Practice using structs
* ===========================================================
*/

#ifndef LAB23FUNCTS_H
#define LAB23FUNCTS_H

typedef struct Pokemon_Struct{
    char name[69];
    int hp;
    int attack;
    int defense;
    int speed;
    double cp;
} Pokemon;

int readPokemonData(char filename[], Pokemon array[]);

void printPokemon(Pokemon pokemon);

void calculateCombatPower(Pokemon array[], int size);

Pokemon* getPokemon(char* name, Pokemon array[], int size);

Pokemon predictWinner(Pokemon pokemon1, Pokemon pokemon2);

#endif