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
 * @brief function in aim to know if a list is empty or not
 * @param list the list we want to verify if it's empty or not
 * @return true if it's empty, false else
 */

int isEmpty(LinkedList* list);

/**
 * @brief adding an element in head of a list
 * @param value the value we want to add in the head of the linked list
 * @param list  the list in which we want to add the value
 * @return the list with the value added
 */
LinkedList* addElementInHead (void* value, LinkedList* list);

/**
 * @brief add an element in the tail of a list
 * @param value the value we want to add in the tail of the linked list
 * @param list the list in which we want to add the value
 * @return the list with the elment added
 */
LinkedList* addElementInTail (void* value, LinkedList* list);

/**
 * @brief add an element in a certain index in a list
 * @param value the value we want to add in the list in the index "index"
 * @param list the list in which we want to add the value
 * @param index the index we want to insert the value
 * @return the list in which we add the value if the index is inferior than the size
 */
LinkedList* addElementInIndex (void* value, LinkedList* list, int index);

/**
 * @brief copy all the element of a list and add them in another list
 * @param listDest the list of destination
 * @param listCopy the list in which we will copy all the elements
 * @return the list with all the elements
 */
LinkedList* addCopyLinkedList(LinkedList* listDest, LinkedList* listCopy);

/**
 * @brief remove the first element of a list
 * @param list the list in which we want to remove the first element
 * @return the list without the first element
 */
LinkedList* removeFirstElement(LinkedList *list);

/**
 * @brief remove the last element of a list
 * @param list the list we want to remove the last element
 * @return the list without the last element
 */
LinkedList* removeLastElement(LinkedList *list);

/**
 * @brief remove the n element of a list
 * @param list the list in which we want to remove the element in index "index"
 * @param index the index of the element to removed
 * @return the list without the element in index "index"
 */
LinkedList* removeElementInIndex(LinkedList* list, int index);

/**
 *
 * @param value the value we want to remove (the first)
 * @param list the list in which we want to remove
 * @return the list without the value
 */
LinkedList* removeValue(void *value, LinkedList *list);

/**
 * @brief delete an entire list
 * @param list the list to remove
 */
void deleteLinkedList(LinkedList* list);

/**
 * @brief function verifying that a value is in a list
 * @param value the value we saerch
 * @param list the LinkedList in which we search the value
 * @return true if it contains, false else
 */
bool contains (void* value, LinkedList* list);

/**
 * @brief function that search the value in a list
 * @param value the value we want to find the index
 * @param list the list in which we want the index of the value
 * @return the index of the value in the linked list (first occurence)
 */
int indexValue(void* value, LinkedList* list);

/**
 * @brief function that count the nomber of time we have a certain value
 * @param value the value we want to know the nomber of occurence present in the list
 * @param list the list in which we want to know the nombre of occurence of the value
 * @return the number of occurence
 */
int occurrence(void *value, LinkedList *list);

/**
 * @brief concat of a list with another
 * @param list1 the list in which we will add the secund list
 * @param list2 the list we will add to the first
 * @return la concatenaton of the two list
 */
LinkedList* concatenationLinkedList(LinkedList* list1, LinkedList* list2);

#endif //POKÉMON_STRATEGY_TOOLS_LINKEDLIST_H
