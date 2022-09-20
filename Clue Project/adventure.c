#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "rooms.h"
#include "items.h"

int main() {

    //used for randomization
    time_t t;
    srand((unsigned) time(&t));


    //used to randomize the location and item and character name locations
    char *a[9];
    a[0] = "Ballroom";
    a[1] = "Conservatory";
    a[2] = "Billiard Room";
    a[3] = "Library";
    a[4] = "Boltwood Inn";
    a[5] = "Study";
    a[6] = "Hall";
    a[7] = "Lounge";
    a[8] = "Dining Room";

  
    char *itemsRandom[9];
    itemsRandom[0] = "Blicky";
    itemsRandom[1] = "Dagger";
    itemsRandom[2] = "Poison";
    itemsRandom[3] = "LeadPipe";
    itemsRandom[4] = "Rope";
    itemsRandom[5] = "Candles";
    itemsRandom[6] = "Wrench";
    itemsRandom[7] = "Lasers";
    itemsRandom[8] = "Whip";

    char *characterRandom[9];
    characterRandom[0] = "Anish";
    characterRandom[1] = "Neel";
    characterRandom[2] = "Joon";
    characterRandom[3] = "Nithin";
    characterRandom[4] = "Sriram";
    characterRandom[5] = "Jeremy";
    characterRandom[6] = "Nav";
    characterRandom[7] = "Jerry";
    characterRandom[8] = "LilUziVert";

    //basically iterates across the arrays and shuffles it up randomly with different seeds each time
    for (int i = 0; i < 10; i++) {
        int f = rand() % 9;
        int z = rand() % 9;
        char* temp = a[f];
        a[f] = a[z];
        a[z] = temp;
        temp = itemsRandom[f];
        itemsRandom[f] = itemsRandom[z];
        itemsRandom[z] = temp;
        temp = characterRandom[f];
        characterRandom[f] = characterRandom[z];
        characterRandom[z] = temp;
    }
   
   //Used to create all the items, characters and the board
    struct Item *itemList[9];
    struct Item *head = NULL;

    itemList[0] = item(itemsRandom[0],"Bro got smoked by Benson with the Smith and Wesson 🕷", NULL);
    itemList[1] = item(itemsRandom[1], "One Piece best manga fr", NULL);
    itemList[2] = item(itemsRandom[2], "Bro got clapped by a pipe lol 😼", NULL);
    itemList[3] = item(itemsRandom[3], "Monkey business",NULL);
    itemList[4] = item(itemsRandom[4], "H style", NULL);
    itemList[5] = item(itemsRandom[5], "Please just delete the game fr", NULL);
    itemList[6] = item(itemsRandom[6], "Rip Bozo", NULL);
    itemList[7] = item(itemsRandom[7], "Clapped", NULL);
    itemList[8] = item(itemsRandom[8], "Clapped2", NULL);



    struct Character *characterList[9];

    characterList[0] = character(characterRandom[0], a[0],NULL);
    characterList[1] = character(characterRandom[1], a[1],NULL);
    characterList[2] = character(characterRandom[2], a[2],NULL);
    characterList[3] = character(characterRandom[3], a[3],NULL);
    characterList[4] = character(characterRandom[4], a[4],NULL);
    characterList[5] = character(characterRandom[5], a[5],NULL);
    characterList[6] = character(characterRandom[6], a[6],NULL);
    characterList[7] = character(characterRandom[7], a[7],NULL);
    characterList[8] = character(characterRandom[8], a[8],NULL);


    //printf("%s\n", characterList[0]->name);

    //struct Character characters[] = {character1,character2,character3,character4,character5};
     
    struct Room *board[9];

    board[0] = room(a[0], characterList[0], NULL, NULL, NULL, NULL, itemList[0], true);
    board[1] = room(a[1], characterList[1], NULL, NULL, NULL, NULL, itemList[1], false);
    board[2] = room(a[2], characterList[2], NULL, NULL, NULL, NULL, itemList[2], false);
    board[3] = room(a[3], characterList[3], NULL, NULL, NULL, NULL, itemList[3], false);
    board[4] = room(a[4], characterList[4], NULL, NULL, NULL, NULL, itemList[4], false);
    board[5] = room(a[5], characterList[5], NULL, NULL, NULL, NULL, itemList[5], false);
    board[6] = room(a[6], characterList[6], NULL, NULL, NULL, NULL, itemList[6], false);
    board[7] = room(a[7], characterList[7], NULL, NULL, NULL, NULL, itemList[7], false);
    board[8] = room(a[8], characterList[8], NULL, NULL, NULL, NULL, itemList[8], false);

    //used for connecting the board using a pattern I noticed when manually connecting the board
    for (int i = 0; i < 8; i++) {
        //if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 5) {
        if (i >=0 && i < 6){
            connect_North(board[i], board[i+3]);
        }
        if (i == 1 || i == 4 || i == 7){
            connect_East(board[i], board[i+1]);
            connect_West(board[i], board[i-1]);
        }
    }

   

    // Used to show that the pointers are correctly done
    // printf("The North pointer of %s points to %s\n",board[0]->name,board[0]->North->name);
    // printf("The East pointer of %s points to %s\n",board[4]->name,board[4]->East->name);
    // printf("The West pointer of %s points to %s\n",board[8]->name,board[8]->West->name);

    //Randomly selects the correct answer for each distinct game;
    struct answer correct[3];
    correct->room = board[rand()%9];
	correct->item = itemList[rand()%6];
	correct->character = characterList[(rand()%4)+1];

    // printf("%s\n", correct->room->name);
    // printf("%s\n", correct->item->name);
    // printf("%s\n", correct->character->name);

    // printf("%s. The %s\n", room2->itemList->name, room2->itemList->description);
    // printf("%s. The %s\n", room3->itemList->name, room3->itemList->description);
    // printf("%s. The %s\n", room4->itemList->name, room4->itemList->description);
    // printf("%s. The %s\n", room5->itemList->name, room5->itemList->description);
    // printf("%s. The %s\n", room6->itemList->name, room6->itemList->description);
    // printf("%s. The %s\n", room7->itemList->name, room7->itemList->description);
    // printf("%s. The %s\n", room8->itemList->name, room8->itemList->description);


    //lists the board information like character list, item list and room name list
    void list() {
        for (int i = 0; i < 9; i++){
            printf("Item name: %s. Description: %s\n", itemList[i]->name, itemList[i]->description);
        }
        printf("\n");

        for (int i = 0; i < 9; i++){
            printf("Character name: %s\n", characterList[i]->name);
        }
        printf("\n");

        for (int i = 0; i < 9; i++){
            printf("Room name: %s\n", board[i]->name);
        }
        printf("\n");
    }

    //shows the character list for distinct rooms
    void viewCharacterInventory(struct Character *characterHead) {
        int i = 1;
        while (characterHead != NULL){
            printf("%i) %s\n",i,characterHead->name);
            i++;
            characterHead = characterHead->characters;
        }
    }

    //lets you check the room information like character list, which directions are valid and the item list
    void look() {
        for (int i = 0; i < 9; i++){
            if (board[i]->flag == true){
                if (board[i]->characterList != NULL){
                    printf("The characters in the room are: \n");
                    viewCharacterInventory(characterList[i]);
                    printf("\n");
                }
                printf("The current room you are in is the %s.\n", board[i]->name);
                if (board[i]->North != NULL){
                    printf("To the North is the %s\n", board[i]->North->name);
                } 
                if (board[i]->South != NULL){
                    printf("To the South is the %s\n", board[i]->South->name);
                } 
                if (board[i]->East != NULL){
                    printf("To the East is the %s\n", board[i]->East->name);
                } 
                if (board[i]->West != NULL){
                    printf("To the West is the %s\n", board[i]->West->name);
                }
                if (board[i]->itemList != NULL){
                    printf("The items in the room are:\n");
                    viewInventory(board[i]->itemList);
                } else {
                    printf("No items in the room\n");
                }
                printf("\n");
                break;
            }
        }
    }

    //lists all the valid commands
    void help() {
        printf("List. Shows everything available like items, rooms and characters within the game.\n");
        printf("Look. Shows the current room and all the details about that room.\n");
        printf("Go. Lets you move rooms in any main direction. North, South, East, West.\n");
        printf("Take. Lets you pick up the item in the room.\n");
        printf("Drop. Lets you drop an item from your inventory\n");
        printf("Inventory. Lets you see your current inventory.\n");
        printf("Clue. Lets you guess the current answer for this game.\n");
        printf("Answer. Lets you see the answer of the game if you believe it is too hard to actually play lol. \n");
    }

    //takes in input and then compares that to the direction and then changes the active room boolean. Sets previous room boolean to false;
    bool go(char directionInput[]){
        for (int i = 0; i < 9; i++){
            if (board[i]->flag == true){
                if (strcmp(directionInput, "north\n") == 0 && board[i]->North != NULL){
                    board[i]->North->flag = true;
                } else if (board[i]->South != NULL && strcmp(directionInput, "south\n") == 0){
                    board[i]->South->flag = true;
                } else if (board[i]->East != NULL && strcmp(directionInput, "east\n") == 0){
                    board[i]->East->flag = true;
                } else if (board[i]->West != NULL && strcmp(directionInput, "west\n") == 0){
                    board[i]->West->flag = true;
                } else {
                    return false;
                }
                board[i]->flag = false;
                break;
            }
        }
        return true;
    }


    //check winning or losing states;
    int guessCounter = 0;

    //Basically lets you check game winning states by guessing the answer
    bool clue() {
        bool correctClue = true;
        for (int i = 0; i < 9; i++){
            if (board[i]->flag == true) {
                if (strcmp(correct->room->name, board[i]->name) == 0){
                    printf("Room Match\n");
                } else {
                    correctClue = false;
                    printf("Wrong room, try again\n");
                }
                printf("What character would you like to guess.\n");
                char guess[30];
                scanf("%s", &guess);
                int v;
                for (int j = 0; j < 9; j++){
                    if (strcmp(guess,characterList[j]->name) == 0){
                        v = j;
                        break;
                    }
                    if (j == 8){
                        printf("You input a invalid character name, please input a valid one\n");
                        scanf("%s", &guess);
                        j = 0;
                    }
                }
                int r;
                for (int z = 0; z < 9; z++) {
                    if (char_in_list(board[z]->characterList, guess)) {
                        r = z;
                        break;
                    }
                }
                if (i != r) {
                    board[r]->characterList = remove_character(board[r]->characterList, characterList[v]);
                    board[i]->characterList = add_character(board[i]->characterList, characterList[v]);
                }
                if (strcmp(correct->character->name, guess) == 0) {
                    printf("Character Match\n");
                } else {
                    correctClue = false;
                    printf("Wrong Character\n");
                }

                char guess2[30];
                printf("What item would you like to guess.\n");
                scanf("%s", &guess2);
                char *itemName = guess2;
                if (strcmp(correct->item->name, guess2) == 0) {
                    if (item_in_list(head, correct->item->name) || item_in_list(board[i]->itemList, correct->item->name)) {
                        printf("Item Match\n");
                    } else {
                        correctClue = false;
                        printf("Correct Item but not in room!!!\n");
                    }
                }
            } 
        }
        return correctClue;
    }  


   //Intro to the game
    char input[200000];
    printf("Hello Player, you are now playing Clue. Have fun and make sure not to throw your computer because you can't solve this easy ass game 😼\n");
    printf("You have multiple options to start the game. If you would like the table of commands please type in help into the command line\n");

    fgets(input,200000, stdin);
    while (strcmp(input, "help\n") != 0 || strcmp(input, "Help\n") != 0){
        if (strcmp(input, "help\n") == 0 || strcmp(input, "Help\n") == 0){
            printf("\n");
            help();
            break;
        } else {
            printf("Please print 'help' or 'Help'\n");
            fgets(input,200000, stdin);
        }
    }
    

    printf("\n");
    printf("Please make sure to type all Item names like 'Blicky' with a capital in the beginning. Same with Character.\n");
    printf("For everything else like the commands, make sure everything is in lowercase!!!\n");
    printf("Now that you know the game and the requirements to enter commands, it is time to enter the game. Whenever you are ready to solve this murder Mystery game of clue, type in 'start' or 'Start' and press enter 🔪🔫\n");
    
    fgets(input,200000, stdin);

    while (strcmp(input, "start\n") != 0 || strcmp(input, "Start\n") != 0){
        if (strcmp(input, "start\n") == 0 || strcmp(input, "Start\n") == 0){
            printf("\n");
            //help();
            break;
        } else {
            printf("Please print 'start' or 'Start'\n");
            fgets(input,200000, stdin);
        }
    }
   
    
    bool win = false; //win condition
   
    //Basically the game and taking in the input for each fgets
    //Has win conditions of making sure the total amount of guesses is left than 10 and that you haven't guessed right yet
    while (win != true && guessCounter < 10){
        printf("\n");
        printf("Please type in your input that is valid from the list of commands. ");
        //printf("Please try to type in lowercase for the inputs to work for everything except for Item and Character Names.\n");
        //printf("Your input: ");
        fgets(input,200000, stdin);
        if (strcmp(input, "help\n") == 0 || strcmp(input, "Help\n") == 0){
            printf("\n");
            help();
            printf("\n");
        } else if (strcmp(input, "list\n") == 0) {
            printf("\n");
            list();
        } else if (strcmp(input,"look\n") == 0) {
            printf("\n");
            look();
        } else if (strcmp(input,"go\n") == 0){
            printf("What direction would you like to go?\n");
            fgets(input,200000,stdin);
            printf("\n");
            bool happened = go(input);
            if (happened){
                printf("You have moved %s", input);
            } else {
                printf("Invalid direction. Please type in a valid one by checking with look.\n");
            }
        } else if (strcmp(input, "take\n") == 0){
            printf("What item would you like to take? It must be in the room you are currently in!\n");
            scanf("%s", &input);
            printf("\n");
            for (int i = 0; i < 9; i++){
                if (board[i]->itemList == NULL && board[i]->flag == true){
                    printf("There is nothing in the room to take\n");
                    break;
                }
                if (board[i]->flag == true && board[i]->itemList != NULL && strcmp(input,board[i]->itemList->name) == 0 ){
                    for (int j = 0; j < 9; j++){
                        if (strcmp(input, itemList[j]->name) == 0){
                            head = item_add(head, itemList[j]);
                            board[i]->itemList = delete_item(board[i]->itemList, itemList[j]);
                            printf("You were able to add the item to your inventory!!\n");
                            break;
                        }
                    } 
                } 
            }
        } else if (strcmp(input, "drop\n") == 0){
            printf("What item would you like to drop? It must be in your inventory!!\n");
            scanf("%s", &input);
            printf("\n");
            for (int i = 0; i < 9; i++){
                if (head == NULL && board[i]->flag == true){
                    printf("There is nothing in your inventory to drop or you input the wrong item to drop!!!!\n");
                    break;
                }
                if (board[i]->flag == true && item_in_list(head, input)){
                    for (int j = 0; j < 9; j++){
                        if (strcmp(input, itemList[j]->name) == 0){
                            head = delete_item(head, itemList[j]);
                            board[i]->itemList = item_add(board[i]->itemList, itemList[j]);
                            printf("You were able to add to the room and delete from your inventory!!\n");
                            break;
                        } 
                    }
                } 
            }
            printf("\n");
        } else if (strcmp(input, "inventory\n") == 0) {
            printf("\n");
            viewInventory(head);
            printf("\n");
        } else if (strcmp(input, "clue\n") == 0) {
            printf("\n");
            bool valid = clue();
            printf("\n");
            if (valid) {
                printf("You have successfully won. Lets go!!!\n");
                win = true;
            } else {
                guessCounter++;
                printf("L bozo buddy\n");
            }
        } else if (strcmp(input, "answer\n") == 0){
            printf("The murder was commited by %s in %s with a %s.",correct->character->name,correct->room->name,correct->item->name);
        } else {
            printf("please type in a valid command. You can check by typing in help!!!!");
        }
    }
 

    //Frees all the malloced data
    for (int i = 0; i < 9; i++){
        free(itemList[i]);
        free(characterList[i]);
        free(board[i]);
    }
    
    return 1;
}

   

    
