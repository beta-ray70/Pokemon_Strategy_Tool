/*********************************************************************************************
 * @author Julien Barbier
 * @date 24/09/2016
 * @brief source file to create function allow us to make type, calculate weakness, resistance and immunity
 */

#include "../include/LinkedList.h"
#include "../include/Pokémon.h"
#include "../include/NatureType.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @param type the Pokemon type we want to create
 * @return the linkedList of weakness
 */
NatureType* typeCreator(NatureType* type){
    LinkedList* weakness = malloc(sizeof(LinkedList));
    LinkedList* resistance = malloc(sizeof(LinkedList));
    LinkedList* immunity = malloc(sizeof(LinkedList));
    type->weakness = weakness;
    type->resistance = resistance;
    type->immunity = immunity;
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
            type->weakness = addElementInHead((void *) BUG, type->weakness);
            type->weakness = addElementInHead((void *) DARK, type->weakness);
            type->weakness = addElementInHead((void *) GHOST, type->weakness);

            type->resistance = addElementInHead((void *) PSYCHIC, type->resistance);
            type->resistance = addElementInHead((void *) FIGHTING, type->resistance);
            break;
        case BUG :
            type->weakness = addElementInHead((void *) FIRE, type->weakness);
            type->weakness = addElementInHead((void *) FLYING, type->weakness);
            type->weakness = addElementInHead((void *) ROCK, type->weakness);

            type->resistance = addElementInHead((void *) GRASS, type->resistance);
            type->resistance = addElementInHead((void *) GROUND, type->resistance);
            type->resistance = addElementInHead((void *) FIGHTING, type->resistance);
            break;
        case NORMAL :
            type->weakness = addElementInHead((void *) FIGHTING, type->weakness);

            type->immunity = addElementInHead((void *) GHOST, type->immunity);
            break;
        case GHOST :
            type->weakness = addElementInHead((void *) GHOST, type->weakness);
            type->weakness = addElementInHead((void *) DARK, type->weakness);

            type->resistance = addElementInHead((void *) BUG, type->resistance);
            type->resistance = addElementInHead((void *) POISON, type->resistance);

            type->immunity = addElementInHead((void *) NORMAL, type->immunity);
            type->immunity = addElementInHead((void *) FIGHTING, type->immunity);
            break;
        case FIRE :
            type->weakness = addElementInHead((void *) WATER, type->weakness);
            type->weakness = addElementInHead((void *) ROCK, type->weakness);
            type->weakness = addElementInHead((void *) GROUND, type->weakness);

            type->resistance = addElementInHead((void *) FIRE, type->resistance);
            type->resistance = addElementInHead((void *) GRASS, type->resistance);
            type->resistance = addElementInHead((void *) ICE, type->resistance);
            type->resistance = addElementInHead((void *) BUG, type->resistance);
            type->resistance = addElementInHead((void *) STEEL, type->resistance);
            type->resistance = addElementInHead((void *) FAIRY, type->resistance);
            break;
        case WATER :
            type->weakness = addElementInHead((void *) GRASS, type->resistance);
            type->weakness = addElementInHead((void *) ELECTRIC, type->weakness);

            type->resistance = addElementInHead((void *) FIRE, type->resistance);
            type->resistance = addElementInHead((void *) WATER, type->resistance);
            type->resistance = addElementInHead((void *) ICE, type->resistance);
            type->resistance = addElementInHead((void *) STEEL, type->resistance);
        case GRASS :
            type->weakness = addElementInHead((void *) FIRE, type->weakness);
            type->weakness = addElementInHead((void *) ICE, type->weakness);
            type->weakness = addElementInHead((void *) FLYING, type->weakness);
            type->weakness = addElementInHead((void *) BUG, type->weakness);
            type->weakness = addElementInHead((void *) POISON, type->weakness);

            type->resistance = addElementInHead((void *) WATER, type->resistance);
            type->resistance = addElementInHead((void *) GRASS, type->resistance);
            type->resistance = addElementInHead((void *) ELECTRIC, type->resistance);
            type->resistance = addElementInHead((void *) GROUND, type->resistance);
            break;
        case ELECTRIC :
            type->weakness = addElementInHead((void *) GROUND, type->weakness);

            type->resistance = addElementInHead((void *) ELECTRIC, type->resistance);
            type->resistance = addElementInHead((void *) FLYING, type->resistance);
            type->resistance = addElementInHead((void *) STEEL, type->resistance);
            break;
        case ICE :
            type->weakness = addElementInHead((void *) FIRE, type->weakness);
            type->weakness = addElementInHead((void *) FIGHTING, type->weakness);
            type->weakness = addElementInHead((void *) ROCK, type->weakness);
            type->weakness = addElementInHead((void *) STEEL, type->weakness);

            type->resistance = addElementInHead((void *) ICE, type->resistance);
            break;
        case FIGHTING :
            type->weakness = addElementInHead((void *) FLYING, type->weakness);
            type->weakness = addElementInHead((void *) PSYCHIC, type->weakness);
            type->weakness = addElementInHead((void *) FAIRY, type->weakness);

            type->resistance = addElementInHead((void *) BUG, type->weakness);
            type->resistance = addElementInHead((void *) ROCK, type->weakness);
            type->resistance = addElementInHead((void *) DARK, type->weakness);
            break;
        case POISON :
            type->weakness = addElementInHead((void *) GROUND, type->weakness);
            type->weakness = addElementInHead((void *) PSYCHIC, type->weakness);

            type->resistance = addElementInHead((void *) GRASS, type->resistance);
            type->resistance = addElementInHead((void *) FIGHTING, type->resistance);
            type->resistance = addElementInHead((void *) POISON, type->resistance);
            type->resistance = addElementInHead((void *) BUG, type->resistance);
            type->resistance = addElementInHead((void *) FAIRY, type->resistance);
            break;
        case GROUND :
            type->weakness = addElementInHead((void *) WATER, type->weakness);
            type->weakness = addElementInHead((void *) GRASS, type->weakness);
            type->weakness = addElementInHead((void *) ICE, type->weakness);

            type->resistance = addElementInHead((void *) POISON, type->resistance);
            type->resistance = addElementInHead((void *) ROCK, type->resistance);

            type->immunity = addElementInHead((void *) ELECTRIC, type->immunity);
            break;
        case FLYING :
            type->weakness = addElementInHead((void *) ELECTRIC, type->weakness);
            type->weakness = addElementInHead((void *) ICE, type->weakness);
            type->weakness = addElementInHead((void *) ROCK, type->weakness);

            type->resistance = addElementInHead((void *) GRASS, type->resistance);
            type->resistance = addElementInHead((void *) BUG, type->resistance);
            type->resistance = addElementInHead((void *) FIGHTING, type->resistance);

            type->immunity = addElementInHead((void *) GROUND, type->immunity);
            break;
        case ROCK :
            type->weakness = addElementInHead((void *) WATER, type->weakness);
            type->weakness = addElementInHead((void *) FIGHTING, type->weakness);
            type->weakness = addElementInHead((void *) GRASS, type->weakness);
            type->weakness = addElementInHead((void *) GROUND, type->weakness);
            type->weakness = addElementInHead((void *) STEEL, type->weakness);

            type->resistance = addElementInHead((void *) NORMAL, type->resistance);
            type->resistance = addElementInHead((void *) FIRE, type->resistance);
            type->resistance = addElementInHead((void *) POISON, type->resistance);
            type->resistance = addElementInHead((void *) FLYING, type->resistance);
            break;
        case DRAGON :
            type->weakness = addElementInHead((void *) ICE, type->weakness);
            type->weakness = addElementInHead((void *) DRAGON, type->weakness);
            type->weakness = addElementInHead((void *) FAIRY, type->weakness);

            type->resistance = addElementInHead((void *) FIRE, type->resistance);
            type->resistance = addElementInHead((void *) WATER, type->resistance);
            type->resistance = addElementInHead((void *) GRASS, type->resistance);
            type->resistance = addElementInHead((void *) ELECTRIC, type->resistance);
            break;
        case DARK :
            type->weakness = addElementInHead((void *) FIGHTING, type->weakness);
            type->weakness = addElementInHead((void *) BUG, type->weakness);
            type->weakness = addElementInHead((void *) FAIRY, type->weakness);

            type->resistance = addElementInHead((void *) GHOST, type->resistance);
            type->resistance = addElementInHead((void *) DARK, type->resistance);

            type->immunity = addElementInHead((void *) PSYCHIC, type->immunity);
            break;
        case STEEL :
            type->weakness = addElementInHead((void *) FIRE, type->weakness);
            type->weakness = addElementInHead((void *) FIGHTING, type->weakness);
            type->weakness = addElementInHead((void *) GROUND, type->weakness);

            type->resistance = addElementInHead((void *) NORMAL, type->resistance);
            type->resistance = addElementInHead((void *) GRASS, type->resistance);
            type->resistance = addElementInHead((void *) ICE, type->resistance);
            type->resistance = addElementInHead((void *) FLYING, type->resistance);
            type->resistance = addElementInHead((void *) PSYCHIC, type->resistance);
            type->resistance = addElementInHead((void *) BUG, type->resistance);
            type->resistance = addElementInHead((void *) ROCK, type->resistance);
            type->resistance = addElementInHead((void *) DRAGON, type->resistance);
            type->resistance = addElementInHead((void *) FAIRY, type->resistance);
            type->resistance = addElementInHead((void *) STEEL, type->resistance);

            type->immunity = addElementInHead((void *) POISON, type->immunity);
            break;
        case FAIRY:
            type->weakness = addElementInHead((void *) POISON, type->weakness);
            type->weakness = addElementInHead((void *) STEEL, type->weakness);

            type->resistance = addElementInHead((void *) FIGHTING, type->resistance);
            type->resistance = addElementInHead((void *) BUG, type->resistance);
            type->resistance = addElementInHead((void *) DARK, type->resistance);

            type->immunity = addElementInHead((void *) DRAGON, type->resistance);
            break;
        default :
            printf("Incorrect Type");
            exit(EXIT_FAILURE);
    }
    return type;
}
