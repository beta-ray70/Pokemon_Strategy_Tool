/*********************************************************************************************
 * @author Julien Barbier
 * @date 24/09/2016
 * @brief source file to create function allow us to make type, calculate weakness, resistance and immunity
 */

#include <stdio.h>
#include <stdlib.h>
#include <LinkedList.h>
#include <Pokemon.h>
#include <NatureType.h>

const TypePokemon g_AllType[NBTYPE] = {PSYCHIC, WATER, FIRE, GRASS, DRAGON, DARK,
                                       ELECTRIC, ICE, GHOST, FIGHTING, BUG, GROUND,
                                       POISON, ROCK, STEEL, FAIRY, NORMAL, FLYING};

/**
 *
 * @param type the Pokemon type we want to create
 * @return the linkedList of weakness
 */
NatureType* initialisationType (NatureType* type){
    type->weakness = createLinkedList();
    type->resistance = createLinkedList();
    type->immunity = createLinkedList();
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
            type->weakness = addElementInHead((void *) GRASS, type->weakness);
            type->weakness = addElementInHead((void *) ELECTRIC, type->weakness);

            type->resistance = addElementInHead((void *) FIRE, type->resistance);
            type->resistance = addElementInHead((void *) WATER, type->resistance);
            type->resistance = addElementInHead((void *) ICE, type->resistance);
            type->resistance = addElementInHead((void *) STEEL, type->resistance);
            break;
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
        case UNDEFINED :
            type->weakness = NULL;
            type->immunity = NULL;
            type->resistance = NULL;
            break;
        default :
            fprintf(stderr,"Incorrect Type or No Type\n");
            exit(EXIT_FAILURE);
    }
    return type;
}

/**
 * @brief create a nature type
 * @param typePokemon the type of the pokemon
 * @return the naturetype corresponding of the typePokemon
 */
NatureType* createNatureType(TypePokemon typePokemon){
    NatureType* type = malloc(sizeof(typePokemon));
    type->typePokemon = typePokemon;
    type = initialisationType(type);
    type = createdType(type);
    return type;
}

/**
 * @brief print the correct type in the screen in function of the type sending
 * @param typePokemon the type of the pokemon we want to print
 */
void printTypePokemon(TypePokemon typePokemon){
    switch (typePokemon){

        case PSYCHIC: fprintf(stdout, "Psychic");break;
        case WATER:fprintf(stdout, "Water");break;
        case FIRE:fprintf(stdout, "Fire");break;
        case GRASS:fprintf(stdout, "Grass");break;
        case DRAGON:fprintf(stdout, "Dragon");break;
        case DARK:fprintf(stdout, "Dark");break;
        case ELECTRIC:fprintf(stdout, "Electric");break;
        case ICE:fprintf(stdout, "Ice");break;
        case GHOST:fprintf(stdout, "Ghost");break;
        case FIGHTING:fprintf(stdout, "Fighting");break;
        case BUG:fprintf(stdout, "Bug");break;
        case GROUND:fprintf(stdout, "Ground");break;
        case POISON:fprintf(stdout, "Poison");break;
        case ROCK:fprintf(stdout, "Rock");break;
        case STEEL:fprintf(stdout, "Steel");break;
        case FAIRY:fprintf(stdout, "Fairy");break;
        case NORMAL:fprintf(stdout, "Normal");break;
        case FLYING:fprintf(stdout, "Flying");break;
        case UNDEFINED:fprintf(stdout, "Undefined");break;
        default: fprintf(stderr, "Error Type\n");
    }
}

/**
 * @brief print all the characteristic of a natureType
 * @param natureType the natureType we want to print characteristic
 */
void printNatureType(NatureType* natureType){
    Element *tmp;
    if(!isEmpty(natureType->weakness)) {
        tmp = natureType->weakness->head;
        fprintf(stdout, "Weakness of the type ");
        printTypePokemon(natureType->typePokemon);
        fprintf(stdout, " : ");
        while (tmp != NULL) {
            printTypePokemon((TypePokemon) tmp->value);
            fprintf(stdout, " - ");
            tmp = tmp->next;
        }
    } else {
        fprintf(stdout, "No Weakness for the type ");
        printTypePokemon(natureType->typePokemon);
    }
    fprintf(stdout,"\n");
    if(!isEmpty(natureType->resistance)) {
        tmp = natureType->resistance->head;
        fprintf(stdout, "Resistance of the type : ");
        printTypePokemon(natureType->typePokemon);
        fprintf(stdout, " : ");
        while (tmp != NULL) {
            printTypePokemon((TypePokemon) tmp->value);
            fprintf(stdout, " - ");
            tmp = tmp->next;
        }
    } else {
        fprintf(stdout, "No Resistance for the type ");
        printTypePokemon(natureType->typePokemon);
    }
    fprintf(stdout,"\n");
    if(!isEmpty(natureType->immunity)) {
        tmp = natureType->immunity->head;
        fprintf(stdout, "Immunity of the type ");
        printTypePokemon(natureType->typePokemon);
        fprintf(stdout, " : ");
        while (tmp != NULL) {
            printTypePokemon((TypePokemon) tmp->value);
            fprintf(stdout, " - ");
            tmp = tmp->next;
        }
    } else {
        fprintf(stdout, "No Immunity for the type ");
        printTypePokemon(natureType->typePokemon);
    }
    fprintf(stdout, "\n");
}
