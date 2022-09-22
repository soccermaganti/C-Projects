#include<stdio.h>
#include <stdlib.h>
//#include <items.h>
#include "items.h"
#include "rooms.h"
#include <stdbool.h>
//#include "adventure.c";


//Used for creating individual rooms with their own properties
struct Room *room(char* name, struct Character *characterList, struct Room *North, struct Room *South, struct Room *East, struct Room *West, struct Item *itemList, bool* flag){
    struct Room *randomRoom = (struct Room *)malloc(sizeof(struct Room));
    randomRoom->name = name;
    randomRoom->characterList = characterList;
    randomRoom->North = North;
    randomRoom->South = South;
    randomRoom->East = East;
    randomRoom->West = West;
    randomRoom->itemList = itemList;
    randomRoom->flag = flag;
    return randomRoom;
};

//used for creating the answer struct that has the properties randomly selected in adventure.c
struct Answer *answer(struct Room *room, struct Item *item, struct Character *character){
    struct answer *correct = (struct answer *)malloc(sizeof(struct answer));
    correct->room = room;
    correct->item = item;
    correct->character = character;
    return correct;
}

//used to create the characters with their respective properties
struct Character *character(char *name, struct Room *currentRoom, struct Character *characters){
    struct Character *randomCharacter = (struct Character *)malloc(sizeof(struct Character));
    randomCharacter->name = name;
    randomCharacter->currentRoom = currentRoom;
    randomCharacter->characters = characters;
    return randomCharacter;
};

//All of the bottom methods are used to connect two different room structs into a 3x3 matrix
void connect_North(struct Room *current, struct Room *next){
    current->North = next;
    next->South = current;
}

void connect_South(struct Room *current, struct Room *next){
    current->South = next;
    next->North = current;
}

void connect_East(struct Room *current, struct Room *next){
    current->East = next;
    next->West = current;
}

void connect_West(struct Room *current, struct Room *next){
    current->West = next;
    next->East = current;
}

bool char_in_list(struct Character *head, char *name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return true;
        }

        head = head->characters;
    }

    return false;
} 

//adding to character linked list
struct Character *add_character(struct Character *head, struct Character *newCharacter) {
    if (head == NULL) {
        head = newCharacter;
        return head;
    }

    struct Character *nodeVal = head;
    while (nodeVal != NULL) {
        if (nodeVal->characters != NULL) {
            nodeVal = nodeVal->characters;
        } else {
            nodeVal->characters = newCharacter;
            return head;
        }
    }

    return NULL;
}

//deleting from character inked list
struct Character *remove_character(struct Character *head, struct Character *inputCharacter) {
    if (head == NULL) {
        return head;
    }

    struct Character *nodeVal = head;
    if (strcmp(nodeVal->name, inputCharacter->name) == 0){
        nodeVal = head->characters;
        head->characters = NULL;
        return nodeVal;
    }

    while (nodeVal != NULL) {
        if (nodeVal->characters != NULL && strcmp(nodeVal->characters->name, inputCharacter->name) == 0) {
            struct Character *deletedCharacter = nodeVal->characters;
            nodeVal->characters = nodeVal->characters->characters;
            deletedCharacter->characters = NULL;
            return head;
        } else {
            nodeVal = nodeVal->characters;
        }
    }

    return head;
}
