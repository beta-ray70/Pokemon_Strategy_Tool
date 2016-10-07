//
// Created by Julien Barbier on 24/09/2016.
//

/*************************
 * @author Julien Barbier
 * @date 24/09/2016
 * @brief realisation of the abstract linked list for the project Pokemon_Strategy_Tools
 * @brief implementation of all the function of the linked list for a futur use in other project
 */

#include <windef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

/**
 * @brief construct a linkedList
 * @return a list which are initialized to zero
 */
LinkedList* createLinkedList(){
    LinkedList* list = malloc (sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

/**
 *
 * @param list the list we want to verify if it's empty or not
 * @return true if it's empty, false else
 */

int isEmpty(LinkedList* list){
    if (list->size == 0)
        return TRUE;
    else return FALSE;
}

/**
 *
 * @param value the value we want to add in the head of the linked list
 * @param list  the list in which we want to add the value
 * @return the list with the value added
 */
LinkedList* addElementInHead (void* value, LinkedList* list){

    Element* elem = malloc(sizeof(Element));

    printf ("Entre dans la fonction addElementInHead\n");
    elem->value = value;
    elem->prev = NULL;
    if (isEmpty(list)){
        list->head = elem;
        list->tail = elem;
        elem->next = NULL;
    } else {
        list->head->prev = elem;
        elem ->next = list->head;
        list->head = elem;
    }
    list->size++;
    printf("End\n");

    return list;
}

/**
 *
 * @param value the value we want to add in the tail of the linked list
 * @param list the list in which we want to add the value
 * @return the list with the elment added
 */
LinkedList* addElementInTail (void* value, LinkedList* list){
    Element* elem = malloc(sizeof(Element));

    printf ("Entre dans la fonction addElementInTail\n");
    elem->value = value;
    elem->next = NULL;
    if (isEmpty(list)){
        list->head = elem;
        list->tail = elem;
        elem->prev = NULL;
    } else {
        list->tail->next = elem;
        elem->prev = list->tail;
        list->tail = elem;
    }
    list->size ++;
    printf("End\n");

    return list;
}

/**
 *
 * @param value the value we want to add in the list in the index "index"
 * @param list the list in which we want to add the value
 * @param index the index we want to insert the value
 * @return the list in which we add the value if the index is inferior than the size
 */
LinkedList* addElementInIndex (void* value, LinkedList* list, int index){
    Element* elem = malloc(sizeof(Element));

    printf("Enter in addElementInIndex\n");
    elem->value = value;
    if (isEmpty(list)){
        elem->next = NULL;
        elem->prev = NULL;
        list->head = elem;
        list->tail = elem;
        list->size ++;
        printf("Warning : the list was empty");
    } else {
        if (index > list->size && index < 0)
            printf("Impossible to add this elem");
        else {
            Element* tmp = list->head;
            int i = 0;
            for (i = 0; i < index; i++){
                tmp = tmp->next;
            }
            elem->prev = tmp->prev;
            elem->next = tmp;
            tmp->prev->next = elem;
            tmp->prev = elem;
            list->size++;
        }
    }
    printf("End\n");
    return list;
}

/**
 *
 * @param list the list in which we want to remove the first element
 * @return the list without the first element
 */
LinkedList* removeElementInHead(LinkedList* list){
    if(!isEmpty(list)){
        if (list->size == 1){
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            list->size--;
        } else {
            Element* tmp = list->head;
            list->head->next->prev = NULL;
            list->head = list->head->next;
            free(tmp);
            list->size--;
        }
    }
    return list;
}


/**
 *
 * @param list the list we want to remove the last element
 * @return the list without the last element
 */
LinkedList* removeElementInTail(LinkedList* list){
    if (!isEmpty(list)){
        if (list->size == 1){
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            list->size--;
        } else {
            Element* tmp = list->tail;
            list->tail->prev->next = NULL;
            list->tail = list->tail->prev;
            free(tmp);
            list->size--;
        }
    }
    return list;
}

/**
 *
 * @param list the list in which we want to remove the element in index "index"
 * @param index the index of the element to removed
 * @return the list without the element in index "index"
 */
LinkedList* removeElementInIndex(LinkedList* list, int index){
    int i;

    if (!isEmpty(list)){
        if (index < index){
            Element* tmp = list->head;
            for(i = 0; i < index; i++){
                tmp = tmp->next;
            }
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            list->size--;
        }
    }

    return list;
}


/**
 *
 * @param list the list to remove
 */
void deleteLinkedList(LinkedList* list){
    while (list->size > 0){
        list = removeElementInHead(list);
    }
    free(list);
}


/**
 *
 * @param value the value we saerch
 * @param list the LinkedList in which we search the value
 * @return true if it contains, false else
 */
bool contains (void* value, LinkedList* list){
    if (isEmpty(list)){
        return FALSE;
    } else {
        Element* tmp = list->head;
        while (tmp->value != value && tmp->next != NULL){
            tmp = tmp->next;
        }

        if (tmp->next == NULL){
            return FALSE;
        } else {
            return TRUE;
        }
    }
}

/**
 *
 * @param value the value we want to find the index
 * @param list the list in which we want the index of the value
 * @return the index of the value in the linked list
 */
int indexValue(void* value, LinkedList* list){
    if(contains(value, list)){
        Element* tmp = list->head;
        int i = 0;
        while(tmp->value != value && tmp->next != NULL){
            tmp = tmp ->next;
            i++;
        }
        return i;
    } else {
        return -1;
    }
}

/**
 *
 * @param value the value we want to know the nomber of occurence present in the list
 * @param list the list in which we want to know the nombre of occurence of the value
 * @return the number of occurence
 */
int occurence(void* value, LinkedList* list){
    int count = 0, i;
    Element* elem = list->head;
    for (i = 0; i< list->size; i++){
        if (elem->value = value){
            count++;
        }
        elem = elem->next;
    }
}

/**
 *
 * @param list1 the list in which we will add the secund list
 * @param list2 the list we will add to the first
 * @return la concatenaton of the two list
 */
LinkedList* concatenationLinkedList(LinkedList* list1, LinkedList* list2){
    if (isEmpty(list1)){
        return list2;
    }
    else if (isEmpty(list2)){
        return list1;
    } else {
        list1->tail->next = list2->head;
        list1->tail = list2->tail;
        return list1;
    }
}