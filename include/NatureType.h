//
// Created by Julien Barbier on 24/09/2016.
//

#ifndef POKEMON_STRATEGY_TOOLS_NATURETYPE_H
#define POKEMON_STRATEGY_TOOLS_NATURETYPE_H

#include <LinkedList.h>

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
    FLYING
} TypePokemon;

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
NatureType* typeCreator(NatureType* type);

/**
 * @brief f***ing borring function (array -> code line)
 * @param type the type we want to create
 * @return the type created
 */
NatureType* createdType(NatureType* type);

#endif //POKÉMON_STRATEGY_TOOLS_NATURETYPE_H
