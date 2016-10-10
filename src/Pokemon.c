//
// Created by Julien Barbier on 08/10/2016.
//

/**
 * @author Julien Barbier
 * @date 8/10/16
 * @brief file allowing to manipulate pokemon and pokemon team like weakness.
 */

#include <stddef.h>
#include <LinkedList.h>
#include <Pokemon.h>

/**
 * @brief WARNING SIDE EFFECT : creation of the weaknessX2 in the same times as weakness
 * @param pokemon the pokemon we want to calculate his weakness
 * @return the weakness of the pokemon
 */
LinkedList* weaknessPokemon(Pokemon* pokemon){
    Element* tmp = pokemon->type[0].weakness->head;
    while(tmp != NULL){
        if (!contains(tmp->value, pokemon->immunity) && !contains(tmp->value, pokemon->resistance) && !contains(tmp->value, pokemon->resistanceX2)){
            pokemon->weakness = addElementInTail(tmp->value, pokemon->weakness);
        }
        tmp = tmp->next;
    }
    if (pokemon->type[1].typePokemon != NULL) {
        tmp = pokemon->type[1].weakness->head;
        while (tmp != NULL) {
            if (!contains(tmp->value, pokemon->immunity) && !contains(tmp->value, pokemon->resistance) && !contains(tmp->value, pokemon->resistanceX2)) {
                if (contains(tmp->value, pokemon->weakness)) {
                    pokemon->weakness = removeByValue(tmp->value, pokemon->weakness);
                    pokemon->weaknessX2 = addElementInTail(tmp->value, pokemon->weaknessX2);
                } else {
                    pokemon->weakness = addElementInTail(tmp->value, pokemon->weakness);
                }
                tmp = tmp->next;
            }
        }
    }
    return pokemon->weakness;
}

/**
 * @brief WARNING SIDE EFFECT : concatenation of weaknessX2 in the same time as weaknessX2
 * @param team the team of pokemon we want to calculate all the weakness
 * @return the weakness of the team (with doubles or more)
 */
LinkedList* weaknessTeamCalculator(PokemonTeam* team){
    for (int i = 0; i < team->size; i++){
        team->weakness = concatenationLinkedList(team->weakness, weaknessPokemon(&team->pokemonTeam[i]));
        team->weaknessX2 = concatenationLinkedList(team->weaknessX2, team->weaknessX2);
    }
    return  team->weakness;
}

/**
 *
 * @param pokemon the pokemon we want to calculate the immunity
 * @return the immunity list of the pokemon
 */
LinkedList* immunityPokemon(Pokemon* pokemon){
    concatenationLinkedList(pokemon->immunity, pokemon->type[0].immunity);
    if (pokemon->type[1].typePokemon != NULL){
        Element* element = pokemon->type[1].immunity->head;
        while (element != NULL ){
            if (!contains(element->value, pokemon->immunity)){
                pokemon->immunity = addElementInTail(element->value, pokemon->immunity);
            }
            element = element->next;
        }
    }
    return pokemon->immunity;
}

/**
 *
 * @param team the team we want to calculate the immunity
 * @return the immunity of the team
 */
LinkedList* immunityTeamCalculator(PokemonTeam* team){
    for (int i = 0; i < team->size; ++i){
        team->immunity = concatenationLinkedList(team->immunity, immunityPokemon(&team->pokemonTeam[i]));
    }
    return team->immunity;
}

/**
 * @brief WARNING SIDE EFFECT : creating resistanceX2 in the same time as resistance
 * @param pokemon the pokemon we want to calculate weakness
 * @return the resistance of the pokemon
 */
LinkedList* resistancePokemon(Pokemon* pokemon){
    Element* element = pokemon->type[0].resistance->head;
    while(element != NULL){
        if (!contains(element->value, pokemon->immunity)){
            pokemon->resistance = addElementInTail(element->value, pokemon->resistance);
        }
        element = element->next;
    }

    if (pokemon->type[1].typePokemon != NULL) {
        element = pokemon->type[1].resistance->head;
        while (element!=NULL){
            if (!contains(element->value, pokemon->immunity)){
                if (contains(element->value, pokemon->resistance)){
                    pokemon->resistance = removeByValue(element->value, pokemon->resistance);
                    pokemon->resistanceX2 = addElementInTail(element->value, pokemon->resistanceX2);
                } else {
                    pokemon->resistance = addElementInTail(element->value, pokemon->resistance);
                }
            }
            element = element->next;
        }
    }
    return pokemon->resistance;
}

/**
 * @brief WARNING SIDE EFFECT : creating resistanceX2 in the same time as resistance
 * @param team the team we want to calculate all the resistance
 * @return the resistance of the team
 */
LinkedList* resistanceTeamCalculator(PokemonTeam* team){
    for (int i =0; i < team->size; i++){
        team->resistance = concatenationLinkedList(team->resistance, resistancePokemon(&team->pokemonTeam[i]));
        team->resistanceX2 = concatenationLinkedList(team->resistanceX2, team->pokemonTeam[i].resistanceX2);
    }
    return team->resistance;
}