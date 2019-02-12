#include <iostream>
#include <stdlib.h>
#include <ctime>

// Function prototype.
int generateRandomNumber();
int loseOrWin(int, int);

int main() {
        // Initializing variables.
        int userChoice = 0;
        int pcChoice = 0;
        int result = 0;
        int winCounter = 0;
        int loseCounter = 0;
        int drawCounter = 0;
        char aChar = ' ';
        bool userChoiceLoop = false;
        bool userEndGameLoop = false;
        bool endGame =  false;

        // Game Loop.
        do {
            // Getting the user decision.
            while(!userChoiceLoop) {
               std::cout << "Enter your choice [1-Rock], [2-Paper], [3-Scissor]:";
                    // Assign the value to variable.
                    std::cin >> userChoice;
                    // If the number is 1,2,3 get it, if not continue the loop.
                    if(userChoice == 1 || userChoice == 2 || userChoice == 3) {
                      // Finish the loop.
                      userChoiceLoop = true;
                    }

                      // It must be an invalid input.
                      std::cout << "Invalid input. Please try again." << std::endl << std::endl;
                      std::cin.clear();  // Clear the buffer.

            }

            // Resetting the loop.
            userChoiceLoop = false;

            // Getting a random number from the method.
            pcChoice = generateRandomNumber();

            // Comparing choices sending them to the method.
            result = loseOrWin(userChoice, pcChoice);

            // If there was an error from the method notify it.
            if(result == -2) {
                std::cout << "There is an error from the method.Check your code\n";
                return 0;
            }

            // If it was a DRAW count it, and repeat the loop.
            if(result == -1) {
                drawCounter += 1;
                continue;
            }

            // If it was WIN or LOSE count it,and ask play again?
            if(result == 1 || result == 0) {
                if(result == 1) {
                    winCounter += 1;
                }
                if(result == 0) {
                    loseCounter += 1;
                }

                // Ask for play again and getting a char from user.
                while(!userEndGameLoop) {
                    std::cout << "Do you want to play again? [y]Yes or [n]No:";
                    std::cin >> aChar;
                        // If yes continue the game or loop.
                        if(aChar == 'y') {
                            userEndGameLoop = true;
                        }
                        // If no end the loop or game.
                        else if(aChar == 'n') {
                            userEndGameLoop = true;
                            endGame = true;
                        }
                        else {
                          // It must be an invalid input.
                          std::cin.clear();
                          std::cout << "Invalid input. Please try again." << std::endl << std::endl;
                        }
                }
            }

                // Resetting the loop.
                userEndGameLoop = false;

        } while(!endGame);


        // If user chose not to continue, display results.
        std::cout << "You have win: " << winCounter << " times.\n";
        std::cout << "You have lose: " << loseCounter << " times.\n";
        std::cout << "You have draw: " << drawCounter << " times.\n";

        // Pause.
        std::cin.ignore();
        std::cin.ignore();

    return 0;
}
    // Function that return an integer random number.
    int generateRandomNumber() {
        // Calling object to use the random method.
        srand(time(nullptr));
        // Initializing variables.
        int aNumber = 0;
        // Generating a random number between 1 and 3.
        aNumber = (rand() %3) + 1;
        // Returning the random number.
        return aNumber;
    }

    // Function that return if you win or lose or draw.
    int loseOrWin(int userChoice, int pcChoice) {
       // 1 - Rock, 2 - Paper, 3 - Scissor.

       // If user: rock & PC: rock.
       if(userChoice == 1 && pcChoice == 1) {
           std::cout << "You chose \"Rock\" and PC chose \"Rock\".\n";
           std::cout << "DRAW.\n";
           std::cout << "Choose again.\n\n";
           return -1;
        }

       // If user: rock & PC: paper.
       if(userChoice == 1 && pcChoice == 2) {
           std::cout << "You chose \"Rock\" and PC chose \"Paper\".\n";
           std::cout << "YOU LOSE!!!.\n\n";
           return 0;
        }

       // If user: rock & PC: scissor.
       if(userChoice == 1 && pcChoice == 3) {
           std::cout << "You chose \"Rock\" and PC chose \"Scissor\".\n";
           std::cout << "YOU WIN!!!\n\n";
           return 1;
        }

       // If user: paper & PC: rock.
       if(userChoice == 2 && pcChoice == 1) {
           std::cout << "You chose \"Paper\" and PC chose \"Rock\".\n";
           std::cout << "YOU WIN!!!\n\n";
           return 1;
        }

       // If user: paper & PC: paper.
       if(userChoice == 2 && pcChoice == 2) {
           std::cout << "You chose \"Paper\" and PC chose \"Paper\".\n";
           std::cout << "DRAW\n";
           std::cout << "Choose again.\n\n";
           return -1;
        }

       // If user: paper & PC: scissor.
       if(userChoice == 2 && pcChoice == 3) {
          std::cout << "You chose \"Paper\" and PC chose \"Scissor\".\n";
           std::cout << "YOU LOSE!!!\n\n";
           return 0;
        }

       // If user: scissor & PC: rock.
       if(userChoice == 3 && pcChoice == 1) {
           std::cout << "You chose \"Scissor\" and PC chose \"Rock\".\n";
           std::cout << "YOU LOSE!!!\n\n";
           return 0;
        }

       // If user: scissor & PC: paper.
       if(userChoice == 3 && pcChoice == 2) {
           std::cout << "You chose \"Scissor\" and PC chose \"Paper\".\n";
           std::cout << "YOU WIN!!!\n\n";
           return 1;
        }

       // If user: scissor & PC: scissor.
       if(userChoice == 3 && pcChoice == 3) {
           std::cout << "You chose \"Scissor\" and PC chose \"Scissor\".\n";
           std::cout << "DRAW\n";
           std::cout << "Choose again.\n\n";
           return -1;
        }

       // Return -2 in case of an error.
       return -2;
    }


