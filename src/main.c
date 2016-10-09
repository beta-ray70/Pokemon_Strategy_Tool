//
// Created by Julien Barbier on 24/09/2016.
//

/**
 * @author Julien Barbier
 * @date 24/09/2016
 * @brief this is the main of the programm
 */

#include "../include/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/NatureType.h"
#include "../include/Pokémon.h"

int main (int argc, char* argv[], int* arge[]){
    int value = 5, i, value1 = 7, value2 = 9;
    Element* tmp;

    LinkedList* list = createLinkedList();
    list = addElementInHead(&value, list);
    list = addElementInTail(&value1, list);
    list = addElementInIndex(&value2, list, 1);

    tmp = list->head;
    for (i = 0; i < list->size; i++){
        int* lol = tmp->value;
        printf("L'element %d est : %d\n", i, *lol);
        tmp = tmp->next;
    }
    if (contains(&value, list)){
        printf("La valeur cherche est bien presente et elle se trouve à l'index : %d\n", indexValue(&value, list));
    }
    deleteLinkedList(list);
    return EXIT_SUCCESS;
}