#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "items.h"
#include <stdbool.h>

struct Room {
      char * name;
      struct Room * North;
      struct Room * South;
      struct Room * East;
      struct Room * West;
      struct Item * itemList;
      struct Character * characterList;
      bool * flag;
};

struct answer {
	struct Room *room;
      struct Item *item;
	struct Character *character;
};

struct Character {
      char * name;
      char * currentRoom;
      struct Character *characters;
};

struct Room *room(char* name, struct Character *characterList, struct Room *North, struct Room *South, struct Room *East, struct Room *West, struct Item *itemList, bool* flag);

struct Character *character(char *name, struct Room *currentRoom, struct Character *characters);

void connect_North(struct Room *current, struct Room *next);
void connect_South(struct Room *current, struct Room *next);
void connect_East(struct Room *current, struct Room *next);
void connect_West(struct Room *current, struct Room *next);

bool char_in_list(struct Character *head, char *name);
struct Character *add_character(struct Character *head, struct Character *newCharacter);
struct Character *remove_character(struct Character *head, struct Character *inputCharacter);
