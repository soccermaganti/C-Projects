#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "items.h"
#include <stdbool.h>

//creating the item element and adding to the list. Linked List thing
struct Item *item(char *name, char* description, struct Item *nextItem) {
    struct Item *itemListElement = (struct Item *)malloc(sizeof(struct Item));
    itemListElement->name = name;
    itemListElement->description = description;
    itemListElement->nextItem = nextItem;
    return itemListElement;
};

//Iterates across Item linked list and prints it out
void viewInventory(struct Item *head) {
    int i = 1;
    while (head != NULL){
        printf("%i) %s\n",i,head->name);
        i++;
        head = head->nextItem;
    }
}

//checks if the input is in the item linked list
bool item_in_list(struct Item*head, char *name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return true;
        }

        head = head->nextItem;
    }

    return false;
} 

//adding to linked list
struct Item *item_add(struct Item *head, struct Item *inputItem) {
    if (head == NULL) {
        head = inputItem;
        return head;
    }

    struct Item *nodeVal = head;
    while (nodeVal != NULL) {
        if (nodeVal->nextItem != NULL) {
            nodeVal = nodeVal->nextItem;
        } else {
            nodeVal->nextItem = inputItem;
            return head;
        }
    }
    return NULL;
}
//deleting from linked list
struct Item *delete_item(struct Item *head, struct Item *inputItem) {
    if (head == NULL) {
        return head;
    }

    struct Item *nodeVal = head;
    if (strcmp(nodeVal->name, inputItem->name) == 0){
        nodeVal = head->nextItem;
        head->nextItem = NULL;
        return nodeVal;
    }

    while (nodeVal != NULL) {
        if (nodeVal->nextItem != NULL && strcmp(nodeVal->nextItem->name, inputItem->name) == 0) {
            struct Item *deletedItem = nodeVal->nextItem;
            nodeVal->nextItem = nodeVal->nextItem->nextItem;
            deletedItem->nextItem = NULL;
            return head;
        } else {
            nodeVal = nodeVal->nextItem;
        }
    }

    return head;
}