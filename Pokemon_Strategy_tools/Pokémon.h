//
// Created by Julien Barbier on 24/09/2016.
//

#ifndef POKEMON_STRATEGY_TOOLS_POKÉMON_H
#define POKEMON_STRATEGY_TOOLS_POKÉMON_H
#define NBTYPE 18
#include "NatureType.h"

TypePokemon typePokemon[NBTYPE] = {PSYCHIC, WATER, FIRE, GRASS, DRAGON, DARK, ELECTRIC, ICE, GHOST, FIGHTING, BUG, GROUND, POISON, ROCK, STEEL, FAIRY, NORMAL, FLYING};

typedef struct {

    int pv;
    int attack;
    int defense;
    int special_attack;
    int special_defense;
    int speed;
    NatureType* type;
    LinkedList* weakness;
    LinkedList* weaknessX2;
    LinkedList* immunity;
    LinkedList* resistance;
} Pokemon;

typedef struct{
    TypePokemon typeStatistic;
    int value;
} TypeDataStatistic;

typedef struct{
    LinkedList* weakness;   //prends un type TypeDataStatistic
    LinkedList* resistance; //prends un type TypeDataStatistic
    LinkedList* weaknessX2; //prends un type TypeDataStatistic
    LinkedList* immunity;   //prends un type TypeDataStatistic
    LinkedList* pokemonTeam; //prends un type Pokemon
}PokemonTeam;

/**
 *
 * @param type the Pokemon type we want to create
 * @return the linkedList of weakness
 */
LinkedList* typeCreator(LinkedList* type);

/**
 * @brief f***ing borring function (array -> code line)
 * @param type the type we want to create
 * @return the type created
 */
NatureType* createdType(NatureType* type);
#endif //POKÉMON_STRATEGY_TOOLS_POKÉMON_H
