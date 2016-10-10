//
// Created by Julien Barbier on 24/09/2016.
//

#ifndef POKEMON_STRATEGY_TOOLS_POKÉMON_H
#define POKEMON_STRATEGY_TOOLS_POKÉMON_H

#include <NatureType.h>

#define NBTYPE 18
#define NB_POKEMON 6
#define MAX_TYPE 2

TypePokemon typePokemon[NBTYPE] = {PSYCHIC, WATER, FIRE, GRASS, DRAGON, DARK, ELECTRIC, ICE, GHOST, FIGHTING, BUG, GROUND, POISON, ROCK, STEEL, FAIRY, NORMAL, FLYING};

typedef struct {

    int pv;
    int attack;
    int defense;
    int special_attack;
    int special_defense;
    int speed;
    NatureType type[MAX_TYPE];
    LinkedList* weakness;
    LinkedList* weaknessX2;
    LinkedList* immunity;
    LinkedList* resistance;
    LinkedList* resistanceX2;
} Pokemon;

typedef struct{
    LinkedList* weakness;
    LinkedList* resistance;
    LinkedList* weaknessX2;
    LinkedList* resistanceX2;
    LinkedList* immunity;
    Pokemon pokemonTeam[NB_POKEMON];
    int size;
}PokemonTeam;

/**
 * @brief WARNING SIDE EFFECT : concatenation of weaknessX2 in the same time as weaknessX2
 * @param team the team of pokemon we want to calculate all the weakness
 * @return the weakness of the team (with doubles or more)
 */
LinkedList* weaknessTeamCalculator(PokemonTeam* team);

/**
 *
 * @param team the team we want to calculate the immunity
 * @return the immunity of the team
 */
LinkedList* immunityTeamCalculator(PokemonTeam* team);

/**
 * @brief WARNING SIDE EFFECT : creating resistanceX2 in the same time as resistance
 * @param team the team we want to calculate all the resistance
 * @return the resistance of the team
 */
LinkedList* resistanceTeamCalculator(PokemonTeam* team);

#endif //POKÉMON_STRATEGY_TOOLS_POKÉMON_H
