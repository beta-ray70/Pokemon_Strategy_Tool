/*********************************************************************************************
 * @author Julien Barbier
 * @date 24/09/2016
 * @brief source file to create function allow us to make type
 */

#include "LinkedList.h"
#include "Pokémon.h"
#include "NatureType.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @param type the Pokemon type we want to create
 * @return the linkedList of weakness
 */
LinkedList* typeCreator(LinkedList* type){
    LinkedList* weakness = malloc(sizeof(LinkedList));
    LinkedList* resistance = malloc(sizeof(LinkedList));
    LinkedList* immunity = malloc(sizeof(LinkedList));
    return type;
}

/**
 * @brief f***ing borring function (array -> code line)
 * @param type the type we want to create
 * @return the type created
 */
NatureType* createdType(NatureType* type){
    switch (type->typePokemon) {
        case PSYCHIC:
            type->weakness = addElementInHead(BUG, type->weakness);
            type->weakness = addElementInHead(DARK, type->weakness);
            type->weakness = addElementInHead(GHOST, type->weakness);

            type->resistance = addElementInHead(PSYCHIC, type->resistance);
            type->resistance = addElementInHead(FIGHTING, type->resistance);
            break;
        case BUG :
            type->weakness = addElementInHead(FIRE, type->weakness);
            type->weakness = addElementInHead(FLYING, type->weakness);
            type->weakness = addElementInHead(ROCK, type->weakness);

            type->resistance = addElementInHead(GRASS, type->resistance);
            type->resistance = addElementInHead(GROUND, type->resistance);
            type->resistance = addElementInHead(FIGHTING, type->resistance);
            break;
        case NORMAL :
            type->weakness = addElementInHead(FIGHTING, type->weakness);

            type->immunity = addElementInHead(GHOST, type->immunity);
            break;
        case GHOST :
            type->weakness = addElementInHead(GHOST, type->weakness);
            type->weakness = addElementInHead(DARK, type->weakness);

            type->resistance = addElementInHead(BUG, type->resistance);
            type->resistance = addElementInHead(POISON, type->resistance);

            type->immunity = addElementInHead(NORMAL, type->immunity);
            type->immunity = addElementInHead(FIGHTING, type->immunity);
            break;
        case FIRE :
            type->weakness = addElementInHead(WATER, type->weakness);
            type->weakness = addElementInHead(ROCK, type->weakness);
            type->weakness = addElementInHead(GROUND, type->weakness);

            type->resistance = addElementInHead(FIRE, type->resistance);
            type->resistance = addElementInHead(GRASS, type->resistance);
            type->resistance = addElementInHead(ICE, type->resistance);
            type->resistance = addElementInHead(BUG, type->resistance);
            type->resistance = addElementInHead(STEEL, type->resistance);
            type->resistance = addElementInHead(FAIRY, type->resistance);
            break;
        case WATER :
            type->weakness = addElementInHead(GRASS, type->resistance);
            type->weakness = addElementInHead(ELECTRIC, type->weakness);

            type->resistance = addElementInHead(FIRE, type->resistance);
            type->resistance = addElementInHead(WATER, type->resistance);
            type->resistance = addElementInHead(ICE, type->resistance);
            type->resistance = addElementInHead(STEEL, type->resistance);
        case GRASS :
            type->weakness = addElementInHead(FIRE, type->weakness);
            type->weakness = addElementInHead(ICE, type->weakness);
            type->weakness = addElementInHead(FLYING, type->weakness);
            type->weakness = addElementInHead(BUG, type->weakness);
            type->weakness = addElementInHead(POISON, type->weakness);

            type->resistance = addElementInHead(WATER, type->resistance);
            type->resistance = addElementInHead(GRASS, type->resistance);
            type->resistance = addElementInHead(ELECTRIC, type->resistance);
            type->resistance = addElementInHead(GROUND, type->resistance);
            break;
        case ELECTRIC :
            type->weakness = addElementInHead(GROUND, type->weakness);

            type->resistance = addElementInHead(ELECTRIC, type->resistance);
            type->resistance = addElementInHead(FLYING, type->resistance);
            type->resistance = addElementInHead(STEEL, type->resistance);
            break;
        case ICE :
            type->weakness = addElementInHead(FIRE, type->weakness);
            type->weakness = addElementInHead(FIGHTING, type->weakness);
            type->weakness = addElementInHead(ROCK, type->weakness);
            type->weakness = addElementInHead(STEEL, type->weakness);

            type->resistance = addElementInHead(ICE, type->resistance);
            break;
        case FIGHTING :
            type->weakness = addElementInHead(FLYING, type->weakness);
            type->weakness = addElementInHead(PSYCHIC, type->weakness);
            type->weakness = addElementInHead(FAIRY, type->weakness);

            type->resistance = addElementInHead(BUG, type->weakness);
            type->resistance = addElementInHead(ROCK, type->weakness);
            type->resistance = addElementInHead(DARK, type->weakness);
            break;
        case POISON :
            type->weakness = addElementInHead(GROUND, type->weakness);
            type->weakness = addElementInHead(PSYCHIC, type->weakness);

            type->resistance = addElementInHead(GRASS, type->resistance);
            type->resistance = addElementInHead(FIGHTING, type->resistance);
            type->resistance = addElementInHead(POISON, type->resistance);
            type->resistance = addElementInHead(BUG, type->resistance);
            type->resistance = addElementInHead(FAIRY, type->resistance);
            break;
        case GROUND :
            type->weakness = addElementInHead(WATER, type->weakness);
            type->weakness = addElementInHead(GRASS, type->weakness);
            type->weakness = addElementInHead(ICE, type->weakness);

            type->resistance = addElementInHead(POISON, type->resistance);
            type->resistance = addElementInHead(ROCK, type->resistance);

            type->immunity = addElementInHead(ELECTRIC, type->immunity);
            break;
        case FLYING :
            type->weakness = addElementInHead(ELECTRIC, type->weakness);
            type->weakness = addElementInHead(ICE, type->weakness);
            type->weakness = addElementInHead(ROCK, type->weakness);

            type->resistance = addElementInHead(GRASS, type->resistance);
            type->resistance = addElementInHead(BUG, type->resistance);
            type->resistance = addElementInHead(FIGHTING, type->resistance);

            type->immunity = addElementInHead(GROUND, type->immunity);
            break;
        case ROCK :
            type->weakness = addElementInHead(WATER, type->weakness);
            type->weakness = addElementInHead(FIGHTING, type->weakness);
            type->weakness = addElementInHead(GRASS, type->weakness);
            type->weakness = addElementInHead(GROUND, type.weakness);
            type->weakness = addElementInHead(STEEL, type->weakness);

            type->resistance = addElementInHead(NORMAL, type->resistance);
            type->resistance = addElementInHead(FIRE, type->resistance);
            type->resistance = addElementInHead(POISON, type->resistance);
            type->resistance = addElementInHead(FLYING, type->resistance);
            break;
        case DRAGON :
            type->weakness = addElementInHead(ICE, type->weakness);
            type->weakness = addElementInHead(DRAGON, type->weakness);
            type->weakness = addElementInHead(FAIRY, type->weakness);

            type->resistance = addElementInHead(FIRE, type->resistance);
            type->resistance = addElementInHead(WATER, type->resistance);
            type->resistance = addElementInHead(GRASS, type->resistance);
            type->resistance = addElementInHead(ELECTRIC, type->resistance);
            break;
        case DARK :
            type->weakness = addElementInHead(FIGHTING, type->weakness);
            type->weakness = addElementInHead(BUG, type->weakness);
            type->weakness = addElementInHead(FAIRY, type->weakness);

            type->resistance = addElementInHead(GHOST, type->resistance);
            type->resistance = addElementInHead(DARK, type->resistance);

            type->immunity = addElementInHead(PSYCHIC, type->immunity);
            break;
        case STEEL :
            type->weakness = addElementInHead(FIRE, type->weakness);
            type->weakness = addElementInHead(FIGHTING, type->weakness);
            type->weakness = addElementInHead(GROUND, type->weakness);

            type->resistance = addElementInHead(NORMAL, type->resistance);
            type->resistance = addElementInHead(GRASS, type->resistance);
            type->resistance = addElementInHead(ICE, type->resistance);
            type->resistance = addElementInHead(FLYING, type->resistance);
            type->resistance = addElementInHead(PSYCHIC, type->resistance);
            type->resistance = addElementInHead(BUG, type->resistance);
            type->resistance = addElementInHead(ROCK, type->resistance);
            type->resistance = addElementInHead(DRAGON, type->resistance);
            type->resistance = addElementInHead(FAIRY, type->resistance);
            type->resistance = addElementInHead(STEEL, type.resistance);

            type->immunity = addElementInHead(POISON, type->immunity);
            break;
        case FAIRY:
            type->weakness = addElementInHead(POISON, type->weakness);
            type->weakness = addElementInHead(STEEL, type->weakness);

            type->resistance = addElementInHead(FIGHTING, type->resistance);
            type->resistance = addElementInHead(BUG, type->resistance);
            type->resistance = addElementInHead(DARK, type->resistance);

            type->immunity = addElementInHead(DRAGON, type->resistance);
            break;
        default :
            printf("Incorrect Type");
            exit(EXIT_FAILURE);
    }
    return type;
}

LinkedList* weaknessTeamCreator(PokemonTeam* team){
    Pokemon* element = team->pokemonTeam->head;
    TypePokemon typePokemon[NBTYPE] = {PSYCHIC, WATER, FIRE, GRASS, DRAGON, DARK, ELECTRIC, ICE, GHOST, FIGHTING, BUG, GROUND, POISON, ROCK, STEEL, FAIRY, NORMAL, FLYING};

    
}

LinkedList* weaknessPokemon(Pokemon* pokemon){
    int i = 0;

}