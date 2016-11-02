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
#include <malloc.h>


/**
 * @brief construct an empty Pokemon and initialisation of this data structure (allocation and initialisation)
 * @return the empty Pokemon
 */
Pokemon* createEmptyPokemon(){

    Pokemon* pokemon = malloc(sizeof(Pokemon));
    pokemon->attack = 0;
    pokemon->special_attack = 0;
    pokemon->defense = 0;
    pokemon->special_defense = 0;
    for(int i = 0; i < MAX_TYPE; ++i)
        pokemon->type[i]->typePokemon = UNDEFINED;
    pokemon->pv = 0;
    pokemon->speed = 0;
    pokemon->name = "";

    return pokemon;
}

/**
 * @brief construct the data type Pokemon
 * @param name the name of the pokemon
 * @param attack the attack of the pokemon
 * @param sattack the attack special of the pokemon
 * @param defense the defense of the pokemon
 * @param sdefense the special defense
 * @param speed the speedness of the pokemon
 * @param type the types of the pokemon
 * @return the pokemon created
 */
Pokemon* createPokemon(const char* name, int attack, int sattack, int defense, int sdefense,
                       int speed, NatureType* type, NatureType* type2){
    Pokemon* pokemon = malloc(sizeof(Pokemon));
    pokemon->name = name;
    pokemon->attack = attack;
    pokemon->special_attack = sattack;
    pokemon->defense = defense;
    pokemon->special_defense = sdefense;
    pokemon->speed = speed;
    pokemon->weaknessX2 = createLinkedList();
    pokemon->weakness = createLinkedList();
    pokemon->resistance = createLinkedList();
    pokemon->resistanceX2 = createLinkedList();
    pokemon->immunity = createLinkedList();
    pokemon->type[0] = type;
    if(type2 != NULL){
        pokemon->type[1] = type2;
    } else {
        pokemon->type[1] = createNatureType(UNDEFINED);
    }
    return pokemon;
}

/**
 * @brief create an empty Pokemon team
 * @return the empty Pokemon team
 */
PokemonTeam* createEmptyPokemonTeam(){
    PokemonTeam* pokemonTeam = malloc(sizeof(PokemonTeam));
    pokemonTeam->size = 0;
    pokemonTeam->immunity = createLinkedList();
    pokemonTeam->resistance  =createLinkedList();
    pokemonTeam->resistanceX2 = createLinkedList();
    pokemonTeam->weakness = createLinkedList();
    pokemonTeam->weaknessX2 = createLinkedList();
    return pokemonTeam;
}

/**
 * @brief WARNING SIDE EFFECT : creation of the weaknessX2 in the same times as weakness
 * @param pokemon the pokemon we want to calculate his weakness
 * @return the weakness of the pokemon
 */
LinkedList* weaknessPokemon(Pokemon* pokemon){

    if(!isEmpty(pokemon->weakness))
        return pokemon->weakness;

    Element* tmp = pokemon->type[0]->weakness->head;
    while(tmp != NULL){
        if (!contains(tmp->value, pokemon->immunity) && !contains(tmp->value, pokemon->resistance)
            && !contains(tmp->value, pokemon->resistanceX2)){
            pokemon->weakness = addElementInTail(tmp->value, pokemon->weakness);
        }
        if(contains(tmp->value, pokemon->resistance)){
            pokemon->resistance = removeValue(tmp->value, pokemon->resistance);
        }
        tmp = tmp->next;
    }
    if (pokemon->type[1]->typePokemon != UNDEFINED) {
        tmp = pokemon->type[1]->weakness->head;
        while (tmp != NULL) {
            if (!contains(tmp->value, pokemon->immunity) && !contains(tmp->value, pokemon->resistance)
                && !contains(tmp->value, pokemon->resistanceX2)) {
                if (contains(tmp->value, pokemon->weakness)) {
                    pokemon->weakness = removeValue(tmp->value, pokemon->weakness);
                    pokemon->weaknessX2 = addElementInTail(tmp->value, pokemon->weaknessX2);
                } else {
                    pokemon->weakness = addElementInTail(tmp->value, pokemon->weakness);
                }
            } else {
                if(contains(tmp->value, pokemon->resistance)){
                    pokemon->resistance = removeValue(tmp->value, pokemon->resistance);
                }
            }
            tmp = tmp->next;
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
    for (int i = 0; i < team->size; ++i){
        team->weakness = addCopyLinkedList(team->weakness, weaknessPokemon(team->pokemonTeam[i]));
        team->weaknessX2 = addCopyLinkedList(team->weaknessX2, team->pokemonTeam[i]->weaknessX2);
    }
    return  team->weakness;
}

/**
 *
 * @param pokemon the pokemon we want to calculate the immunity
 * @return the immunity list of the pokemon
 */
LinkedList* immunityPokemon(Pokemon* pokemon){

    if(!isEmpty(pokemon->immunity) && (!isEmpty(pokemon->type[0]->immunity) || !isEmpty(pokemon->type[1]->immunity)))
        return pokemon->immunity;

    pokemon->immunity = concatenationLinkedList(pokemon->immunity, pokemon->type[0]->immunity);
    if (pokemon->type[1]->typePokemon != UNDEFINED){
        Element* element = pokemon->type[1]->immunity->head;
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
        team->immunity = addCopyLinkedList(team->immunity, team->pokemonTeam[i]->immunity);
    }
    return team->immunity;
}

/**
 * @brief WARNING SIDE EFFECT : creating resistanceX2 in the same time as resistance
 * @param pokemon the pokemon we want to calculate weakness
 * @return the resistance of the pokemon
 */
LinkedList* resistancePokemon(Pokemon* pokemon){

    if(!isEmpty(pokemon->resistance))
        return pokemon->resistance;

    Element* element = pokemon->type[0]->resistance->head;
    while(element != NULL){
        if (!contains(element->value, pokemon->immunity)){
            pokemon->resistance = addElementInTail(element->value, pokemon->resistance);
        }
        element = element->next;
    }

    if (pokemon->type[1]->typePokemon != UNDEFINED) {
        element = pokemon->type[1]->resistance->head;
        while (element!=NULL){
            if (!contains(element->value, pokemon->immunity)){
                if (contains(element->value, pokemon->resistance)){
                    pokemon->resistance = removeValue(element->value, pokemon->resistance);
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
    for (int i =0; i < team->size; ++i){
        team->resistance = addCopyLinkedList(team->resistance, resistancePokemon(team->pokemonTeam[i]));
        team->resistanceX2 = addCopyLinkedList(team->resistanceX2, team->pokemonTeam[i]->resistanceX2);
    }
    return team->resistance;
}

/**
 * @brief calcul weakness, immunity and resistance of a pokemon
 * @param pokemon the pokemon we want to calculate weakness, immunity and resistance
 * @return the pokemon
 */
Pokemon* calculStatTypePokemon(Pokemon* pokemon){
    pokemon->immunity = immunityPokemon(pokemon);
    pokemon->resistance = resistancePokemon(pokemon);
    pokemon->weakness = weaknessPokemon(pokemon);
    return pokemon;
}

/**
 * @brief calcul the weaknesses, immunities and resistances of the pokemon team
 * @param pokemonTeam the pokemon team we want to print characteristic
 * @return the pokemonTeam with weaknesses, immunities and resistances
 */
PokemonTeam* calculStatTypePokemonTeam(PokemonTeam* pokemonTeam){
    immunityTeamCalculator(pokemonTeam);
    resistanceTeamCalculator(pokemonTeam);
    weaknessTeamCalculator(pokemonTeam);
    return pokemonTeam;
}

/**
 * @brief delete a Pokemon
 * @param pokemon the pokemon we want to delete
 */
void deletePokemon(Pokemon* pokemon){
    //free(pokemon->name);
    deleteLinkedList(pokemon->immunity);
    deleteLinkedList(pokemon->resistance);
    deleteLinkedList(pokemon->resistanceX2);
    deleteLinkedList(pokemon->weakness);
    deleteLinkedList(pokemon->weaknessX2);
}

/**
 * @brief delete all the pokemon team
 * @param pokemonTeam the pokemon team we want to delete
 */
void deletePokemonTeam(PokemonTeam* pokemonTeam){
    for(int i =0; i < pokemonTeam->size; ++i){
        deletePokemon(pokemonTeam->pokemonTeam[i]);
    }
}

/**
 * @brief print all the element of the linkedlist (for NatureType only)
 * @param list the list in which we want to print all the value
 */
void printLinkedListPokemon(LinkedList* list){
    if (!isEmpty(list)) {
        Element *tmp = list->head;
        while (tmp != NULL) {
            printTypePokemon((TypePokemon) tmp->value);
            if(tmp->next != NULL)
                fprintf(stdout, " - ");
            tmp = tmp->next;
        }
    } else {
        fprintf(stdout,"Nothing");
    }
    fprintf(stdout, "\n");
}

/**
 * @brief print all the characteristic of a pokemon
 * @param pokemon the pokemon we want to print characteristic
 */
void printCharacteristic(Pokemon* pokemon){
    fprintf(stdout, "name : %s\n", pokemon->name);
    fprintf(stdout, "attack : %d\n", pokemon->attack);
    fprintf(stdout, "special attack : %d\n", pokemon->special_attack);
    fprintf(stdout, "defense : %d\n", pokemon->defense);
    fprintf(stdout, "special defense : %d\n", pokemon->special_defense);
    fprintf(stdout, "speedness : %d\n", pokemon->speed);
    fprintf(stdout, "WeaknessX2 : ");
    printLinkedListPokemon(pokemon->weaknessX2);
    fprintf(stdout, "Weakness : ");
    printLinkedListPokemon(pokemon->weakness);
    fprintf(stdout, "Resistance : ");
    printLinkedListPokemon(pokemon->resistance);
    fprintf(stdout, "ResistanceX2 : ");
    printLinkedListPokemon(pokemon->resistanceX2);
    fprintf(stdout, "Immunity : ");
    printLinkedListPokemon(pokemon->immunity);
}

/**
 * @brief print all the weaknesses, the immunities and the resistances of the team
 * @param pokemonTeam the team we want to print characteristic
 */
void printStatTypePokemonTeam(PokemonTeam* pokemonTeam){
    fprintf(stdout, "WeaknessX2 of the team : ");
    printLinkedListPokemon(pokemonTeam->weaknessX2);

    fprintf(stdout, "Weakness of the team : ");
    printLinkedListPokemon(pokemonTeam->weakness);

    fprintf(stdout, "Resistance of the team : ");
    printLinkedListPokemon(pokemonTeam->resistance);

    fprintf(stdout, "resistanceX2 of the team : ");
    printLinkedListPokemon(pokemonTeam->resistanceX2);

    fprintf(stdout, "immunity of the team : ");
    printLinkedListPokemon(pokemonTeam->immunity);
}