// Zhiyu Yin, 12/7/2023
// main function

#include "GameEngine.h"
#include <iostream>

using std::cout;

int main() {
    GameEngine test;
    test.initializeGame();
    test.intro();

    int numRestVeggies = test.remainingVeggies();
    while (numRestVeggies != 0) {
        cout << numRestVeggies << " veggies remaining. Current score: " << test.getScore() << "\n";
        test.printField();
        test.moveRabbits();
        test.moveCaptain();
        numRestVeggies = test.remainingVeggies();
    }
    test.gameOver();
    return 0;
}