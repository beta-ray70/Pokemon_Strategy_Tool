//
// Created by Julien Barbier on 24/09/2016.
//

#ifndef POKEMON_STRATEGY_TOOLS_NATURETYPE_H
#define POKEMON_STRATEGY_TOOLS_NATURETYPE_H

#include <LinkedList.h>

#define NBTYPE 18

typedef enum {
    PSYCHIC,
    WATER,
    FIRE,
    GRASS,
    DRAGON,
    DARK,
    ELECTRIC,
    ICE,
    GHOST,
    FIGHTING,
    BUG,
    GROUND,
    POISON,
    ROCK,
    STEEL,
    FAIRY,
    NORMAL,
    FLYING,
    UNDEFINED
} TypePokemon;

const extern TypePokemon g_AllType[NBTYPE];

typedef struct {
    TypePokemon typePokemon;
    LinkedList* weakness;
    LinkedList* resistance;
    LinkedList* immunity;
} NatureType;

/**
 *
 * @param type the Pokemon type we want to create
 * @return the linkedList of weakness
 */
NatureType* initialisationType(NatureType* type);

/**
 * @brief f***ing borring function (array -> code line)
 * @param type the type we want to create
 * @return the type created
 */
NatureType* createdType(NatureType* type);

/**
 * @brief create a nature type
 * @param typePokemon the type of the pokemon
 * @return the naturetype corresponding of the typePokemon
 */
NatureType* createNatureType(TypePokemon typePokemon);

/**
 * @brief print the correct type in the screen in function of the type sending
 * @param typePokemon the type of the pokemon we want to print
 */
void printTypePokemon(TypePokemon typePokemon);

/**
 * @brief print all the characteristic of a natureType
 * @param natureType the natureType we want to print characteristic
 */
void printNatureType(NatureType* natureType);

#endif //POKÉMON_STRATEGY_TOOLS_NATURETYPE_H
