//
// Created by Julien Barbier on 24/09/2016.
//

#ifndef POKEMON_STRATEGY_TOOLS_POKEMON_H
#define POKEMON_STRATEGY_TOOLS_POKEMON_H

#include <NatureType.h>

#define NB_POKEMON 6
#define MAX_TYPE 2

typedef struct {

    char* name;
    int pv;
    int attack;
    int defense;
    int special_attack;
    int special_defense;
    int speed;
    NatureType* type[MAX_TYPE];
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
    Pokemon* pokemonTeam[NB_POKEMON];
    int size;
}PokemonTeam;

/**
<<<<<<< HEAD
 * @brief construct an empty Pokemon and initialisation of this data structure (allocation and initialisation)
 * @return the empty Pokemon
 */
Pokemon* createEmptyPokemon();

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
                       int speed, NatureType* type, NatureType* type2);

/**
 * @brief create an empty Pokemon team
 * @return the empty Pokemon team
 */
PokemonTeam* createEmptyPokemonTeam();
/**
 * @brief calcul the weakness of a pokemon
 * @brief WARNING SIDE EFFECT : creation of the weaknessX2 in the same times as weakness
 * @param pokemon the pokemon we want to calculate his weakness
 * @return the weakness of the pokemon
 */
LinkedList* weaknessPokemon(Pokemon* pokemon);

/**
 * @brief WARNING SIDE EFFECT : concatenation of weaknessX2 in the same time as weaknessX2
 * @param team the team of pokemon we want to calculate all the weakness
 * @return the weakness of the team (with doubles or more)
 */
LinkedList* weaknessTeamCalculator(PokemonTeam* team);

/**
 * @brief calcul the immunities of a pokemon
 * @param pokemon the pokemon we want to calculate the immunity
 * @return the immunity list of the pokemon
 */
LinkedList* immunityPokemon(Pokemon* pokemon);

/**
 *
 * @param team the team we want to calculate the immunity
 * @return the immunity of the team
 */
LinkedList* immunityTeamCalculator(PokemonTeam* team);

/**
 * @brief calcul the resistance of a Pokemon
 * @brief WARNING SIDE EFFECT : creating resistanceX2 in the same time as resistance
 * @param pokemon the pokemon we want to calculate weakness
 * @return the resistance of the pokemon
 */
LinkedList* resistancePokemon(Pokemon* pokemon);

/**
 * @brief WARNING SIDE EFFECT : creating resistanceX2 in the same time as resistance
 * @param team the team we want to calculate all the resistance
 * @return the resistance of the team
 */
LinkedList* resistanceTeamCalculator(PokemonTeam* team);

/**
 * @brief calcul the weaknesses, immunities and resistances of the pokemon team
 * @param pokemonTeam the pokemon team we want to print characteristic
 * @return the pokemonTeam with weaknesses, immunities and resistances
 */
PokemonTeam* calculStatTypePokemonTeam(PokemonTeam* pokemonTeam);

/**
 * @brief delete a Pokemon
 * @param pokemon the pokemon we want to delete
 */
void deletePokemon(Pokemon* pokemon);

/**
 * @brief delete all the pokemon team
 * @param pokemonTeam the pokemon team we want to delete
 */
void deletePokemonTeam(PokemonTeam* pokemonTeam);

/**
 * @brief print all the characteristic of a pokemon
 * @param pokemon the pokemon we want to print characteristic
 */
void printCharacteristic(Pokemon* pokemon);

/**
 * @brief calcul weakness, immunity and resistance of a pokemon
 * @param pokemon the pokemon we want to calculate weakness, immunity and resistance
 * @return the pokemon
 */
Pokemon* calculStatTypePokemon(Pokemon* pokemon);

/**
 * @brief print all the weaknesses, the immunities and the resistances of the team
 * @param pokemonTeam the team we want to print characteristic
 */
void printStatTypePokemonTeam(PokemonTeam* pokemonTeam);

#endif //POKÉMON_STRATEGY_TOOLS_POKÉMON_H
