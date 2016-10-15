//
// Created by Julien Barbier on 24/09/2016.
//

/*************************
 * @author Julien Barbier
 * @date 24/09/2016
 * @brief realisation of the abstract linked list for the project Pokemon_Strategy_Tools
 * @brief implementation of all the function of the linked list for a futur use in other project
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <LinkedList.h>

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
 * @brief function in aim to know if a list is empty or not
 * @param list the list we want to verify if it's empty or not
 * @return true if it's empty, false else
 */

int isEmpty(LinkedList* list){
    return list == NULL || list->size == 0;
}

/**
 * @brief adding an element in head of a list
 * @param value the value we want to add in the head of the linked list
 * @param list  the list in which we want to add the value
 * @return the list with the value added
 */
LinkedList* addElementInHead (void* value, LinkedList* list){

    Element* elem = malloc(sizeof(Element));

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
    return list;
}

/**
 * @brief add an element in the tail of a list
 * @param value the value we want to add in the tail of the linked list
 * @param list the list in which we want to add the value
 * @return the list with the elment added
 */
LinkedList* addElementInTail (void* value, LinkedList* list){
    Element* elem = malloc(sizeof(Element));

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
    return list;
}

/**
 * @brief add an element in a certain index in a list
 * @param value the value we want to add in the list in the index "index"
 * @param list the list in which we want to add the value
 * @param index the index we want to insert the value
 * @return the list in which we add the value if the index is inferior than the size
 */
LinkedList* addElementInIndex (void* value, LinkedList* list, int index){
    Element* elem = malloc(sizeof(Element));

    elem->value = value;
    if (isEmpty(list)){
        elem->next = NULL;
        elem->prev = NULL;
        list->head = elem;
        list->tail = elem;
        list->size ++;
        fprintf(stderr, ">>Warning : the list was empty\n");
    } else {
        if (index > list->size && index < 0)
            fprintf(stderr, ">>Impossible to add this elem\n");
        else {
            Element* tmp = list->head;
            int i = 0;
            for (i = 0; i < index; i++){
                tmp = tmp->next;
            }

            //initialisation of the element
            elem->prev = tmp->prev;
            elem->next = tmp;

            //adding the element in the list
            tmp->prev->next = elem;
            tmp->prev = elem;
            list->size++;
        }
    }
    return list;
}

/**
 * @brief remove the first element of a list
 * @param list the list in which we want to remove the first element
 * @return the list without the first element
 */
LinkedList* removeFirstElement(LinkedList *list){
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
    } else {
        fprintf(stderr, ">>the list is empty\n");
    }
    return list;
}


/**
 * @brief remove the last element of a list
 * @param list the list we want to remove the last element
 * @return the list without the last element
 */
LinkedList* removeLastElement(LinkedList *list){
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
 * @brief remove the n element of a list
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
 * @brief delete an entire list
 * @param list the list to remove
 */
void deleteLinkedList(LinkedList* list){
    while (list->size > 0){
        list = removeFirstElement(list);
    }
    free(list);
}


/**
 * @brief function verifying that a value is in a list
 * @param value the value we saerch
 * @param list the LinkedList in which we search the value
 * @return true if it contains, false else
 */
bool contains (void* value, LinkedList* list){
    if (isEmpty(list)){
        return false;
    } else {
        Element* tmp = list->head;
        while (tmp != NULL && tmp->value != value){
            tmp = tmp->next;
        }

        return tmp != NULL;
    }
}

/**
 * @brief function that search the value in a list
 * @param value the value we want to find the index
 * @param list the list in which we want the index of the value
 * @return the index of the value in the linked list (first occurence)
 */
int indexValue(void* value, LinkedList* list){
    if(contains(value, list)){
        Element* tmp = list->head;
        int i = 0;
        while(tmp->value != value && tmp->next != NULL){
            tmp = tmp ->next;
            ++i;
        }
        return i;
    } else {
        return -1;
    }
}

/**
 * @brief function that count the nomber of time we have a certain value
 * @param value the value we want to know the nomber of occurence present in the list
 * @param list the list in which we want to know the nombre of occurence of the value
 * @return the number of occurence
 */
int occurrence(void *value, LinkedList *list){
    int count = 0, i;
    Element* elem = list->head;
    for (i = 0; i< list->size; i++){
        if (elem->value == value){
            count++;
        }
        elem = elem->next;
    }
    return count;
}

/**
 * @brief concat of a list with another
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

/**
 * @brief remove an element due to the value
 * @param value the value we want to remove (the first)
 * @param list the list in which we want to remove
 * @return the list without the value
 */
LinkedList* removeValue(void *value, LinkedList *list) {
    if (!isEmpty(list)) {
        Element *elem = list->head;
        while (elem != NULL && elem->value != value) {
            elem = elem->next;
        }
        if (elem != NULL) {
            if (elem->next == NULL) {
                elem->prev->next = NULL;
                list->tail = elem->prev;
                free(elem);
            } else if (elem->prev == NULL) {
                elem->next->prev = NULL;
                list->head = elem->next;
                free(elem);
            } else {
                elem->prev->next = elem->next;
                elem->next->prev = elem->prev;
                free(elem);
            }
            --list->size;
        }
    }
    return list;
}