//
// Created by Julien Barbier on 24/09/2016.
//

#ifndef POKEMON_STRATEGY_TOOLS_NATURETYPE_H
#define POKEMON_STRATEGY_TOOLS_NATURETYPE_H

#include "LinkedList.h"
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

#endif //POKÉMON_STRATEGY_TOOLS_NATURETYPE_H
