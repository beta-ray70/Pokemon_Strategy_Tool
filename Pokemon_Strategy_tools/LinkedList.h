//
// Created by Julien Barbier on 24/09/2016.
//

#ifndef POKEMON_STRATEGY_TOOLS_LINKEDLIST_H
#define POKEMON_STRATEGY_TOOLS_LINKEDLIST_H

#include <stdbool.h>

typedef struct elem{
    void* value;
    struct elem* next;
    struct elem* prev;
} Element;

typedef struct {
    Element* head;
    Element* tail;
    int size;
} LinkedList;

/**
 * @brief construct a linkedList
 * @return a list which are initialized to zero
 */
LinkedList* createLinkedList();

/**
 *
 * @param value the value we want to add in the head of the linked list
 * @param list  the list in which we want to add the value
 * @return the list with the value added
 */
LinkedList* addElementInHead (void* value, LinkedList* list);

/**
 *
 * @param value the value we want to add in the tail of the linked list
 * @param list the list in which we want to add the value
 * @return the list with the elment added
 */
LinkedList* addElementInTail (void* value, LinkedList* list);

/**
 *
 * @param value the value we want to add in the list in the index "index"
 * @param list the list in which we want to add the value
 * @param index the index we want to insert the value
 * @return the list in which we add the value if the index is inferior than the size
 */
LinkedList* addElementInIndex (void* value, LinkedList* list, int index);

/**
 *
 * @param list the list we want to remove the last element
 * @return the list without the last element
 */
LinkedList* removeElementInTail(LinkedList* list);

/**
 *
 * @param list the list in which we want to remove the element in index "index"
 * @param index the index of the element to removed
 * @return the list without the element in index "index"
 */
LinkedList* removeElementInIndex(LinkedList* list, int index);

/**
 *
 * @param list the list to remove
 */
void deleteLinkedList(LinkedList* list);

/**
 *
 * @param value the value we saerch
 * @param list the LinkedList in which we search the value
 * @return true if it contains, false else
 */
bool contains (void* value, LinkedList* list);

/**
 *
 * @param value the value we want to find the index
 * @param list the list in which we want the index of the value
 * @return the index of the value in the linked list
 */
int indexValue(void* value, LinkedList* list);

/**
 *
 * @param value the value we want to know the nomber of occurence present in the list
 * @param list the list in which we want to know the nombre of occurence of the value
 * @return the number of occurence
 */
int occurence(void* value, LinkedList* list);

#endif //POKÉMON_STRATEGY_TOOLS_LINKEDLIST_H
