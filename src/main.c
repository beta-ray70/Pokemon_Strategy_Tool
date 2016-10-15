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
#include <LinkedList.h>
#include <NatureType.h>
#include <Pokemon.h>

int main (){
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
    } else {
        printf("La valeur n'est pas presente.\n");
    }

    list = addElementInHead((void *) 5, list);
    list = addElementInTail((void *) 5, list);
    printf("Nb de fois qu'est present 5 : %d\n", occurrence((void *) 5, list));
    list = removeValue((void *) 5, list);
    printf("Nb de fois qu'est present 5 : %d\n", occurrence((void *) 5, list));
    deleteLinkedList(list);

    if(contains(&value, list) || contains(&value1, list) || contains(&value2, list))
        printf("la liste n'a pas ete supprime proprement\n");
    return EXIT_SUCCESS;
}