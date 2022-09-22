#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// void Item *item(char *name, struct Item *nextItem);
struct Item {
      char * name;
      char * description;
      struct Item * nextItem;
};

struct Item *item(char *name, char *description, struct Item *nextItem);

bool item_in_list(struct Item*head, char *name);
struct Item *item_add(struct Item *head, struct Item *inputItem);
struct Item *delete_item(struct Item *head, struct Item *inputItem);
void viewInventory(struct Item *head);
