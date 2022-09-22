Clue Game

By Sriram Maganti and Nithin Joshy

README.txt - this is a text file (made in Vim, Emacs, or Nano - not Word, TextEdit, etc.) 
containing an overview/description of your submission highlighting the important parts of 
your implementation. You should also explain where in your implementation your code satisfies
each of the requirements of the project or any requirements that you did not satisfy. 
The goal should make it easy and obvious for the person grading your submission to find the important rubric items. 

Steps to compile project
1) To compile it use 'gcc -o testRun adventure.c rooms.c items.c -g -fsanitize=address'
    - '-fsanitize=address' is used for checking for Segmentation Error

2) type in clear into the command line to get rid of any warning to make it easier to see everything

3) Type in "./testRun" and then enjoy the game, the rest of the instructions are built into the game so make sure to read everything carefully.


Overall Setup of the game
- Basically a 3x3 board/matrix where you always start in the bottom left corner. (adventure.c)
- Can traverse through the rooms by following the pointers and the game will stop you if you try to go into a NULL direction. (adventure.c)
- For game input, just make sure to type in Item names and Character names by their exact casing as shown in 'list' or 'look' (adventure.c)
- For commands, just make sure everything is in lowercase and you should be good. (adventure.c)

Important parts of Implementation:
- All the main methods work, we checked for edge cases and etc. 
    - For example we checked the take and drop methods by trying to take from empty rooms, drop from middle of the lists, and take/drop invalid names.

- When typing invalid inputs, it will tell you to retype another command. 
    - For example if you type drop and then try and drop an item not in your inventory, it will ask you to type in a valid item name.
    - Another example would be to if you type in a wrong command, it will tell you to type in a valid command from the list.

- I also have an answer option where if you believe the game is too hard to play, you can type in 'answer' and it will tell you the answer to the current game.



Rubric Requirements
- Game has 9 rooms all connected by pointers (adventure.c)
- Game randomly initializes the locations of all items, characters and location names before game starts. Only one item per room as well (adventure.c)
- Game has 9 rooms, 9 items and 9 characters, Extreme Difficulty clue game. (adventure.c)
- Game randomly picks room item and character for an answer to end the game (adventure.c)
- Game has linked lists for items and characters for each room and the avatar playing the game (items.c, rooms.c, adventure.c)

a) Game methods (Test by compiling the files and doing ./testRun)
    - Help (adventure.c)
    - List (adventure.c)
    - Look (adventure.c)
    - Go (adventure.c)
    - Take (items.c)
    - Drop (items.c)
    - Inventory (items.c)
    - Clue (adventure.c)

Design and Implementation:
I would say the game is relativly efficient and follows good coding practice.



