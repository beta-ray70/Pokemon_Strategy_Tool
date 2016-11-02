//
// Created by Julien Barbier on 24/09/2016.
//

/**
 * @author Julien Barbier
 * @date 24/09/2016
 * @brief this is the main of the programm
 */

#include <stdio.h>
#include <stdlib.h>
#include <NatureType.h>
#include <Pokemon.h>

int main (){
    int i;
    NatureType* natureType[NBTYPE];

    for(i = 0; i < NBTYPE; ++i){
        natureType[i] = createNatureType(g_AllType[i]);
    }

    PokemonTeam* pokemonTeam = createEmptyPokemonTeam();
    Pokemon* pokemon1 = createPokemon("Arakdo", 10,5,6,2,7, natureType[BUG], natureType[FLYING]);
    Pokemon* pokemon2 = createPokemon("Laggron", 15,6,8,9,15, natureType[WATER], natureType[GROUND]);
    Pokemon* pokemon3 = createPokemon("Gallame", 20,10,9,8,15, natureType[PSYCHIC], natureType[FIGHTING]);
    Pokemon* pokemon4 = createPokemon("Gryhena", 20,10,9,8,15, natureType[DARK],NULL);
    Pokemon* pokemon5 = createPokemon("Insecateur", 20,10,9,8,15, natureType[GRASS], natureType[FIGHTING]);
    //Pokemon* pokemon6 = createPokemon("Insecateur", 20,10,9,8,15, natureType[BUG], natureType[FLYING]);
    pokemon1 = calculStatTypePokemon(pokemon1);
    pokemon2 = calculStatTypePokemon(pokemon2);
    pokemon3 = calculStatTypePokemon(pokemon3);
    pokemon4 = calculStatTypePokemon(pokemon4);
    pokemon5 = calculStatTypePokemon(pokemon5);
    pokemonTeam->pokemonTeam[0] = pokemon1;
    pokemonTeam->pokemonTeam[1] = pokemon2;
    pokemonTeam->pokemonTeam[2] = pokemon3;
    pokemonTeam->pokemonTeam[3] = pokemon4;
    pokemonTeam->pokemonTeam[4] = pokemon5;

    pokemonTeam->size = 5;
    pokemonTeam = calculStatTypePokemonTeam(pokemonTeam);
    printCharacteristic(pokemon1);
    printf("\n");
    printCharacteristic(pokemon2);
    printf("\n");
    printCharacteristic(pokemon3);
    printf("\n");
    printf("\n");
    printStatTypePokemonTeam(pokemonTeam);
    deletePokemonTeam(pokemonTeam);
    return EXIT_SUCCESS;
}
