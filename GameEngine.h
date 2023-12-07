// Zhiyu Yin, 12/6/2023
// declarations of GameEngine class

#pragma once

#include "Captain.h"
#include "FieldInhabitant.h"
#include "Rabbit.h"
#include "Veggie.h"

class GameEngine {
private:
    // fundamental game settings
    FieldInhabitant ***gameField;
    int height;
    int width;
    int score;
    static const int NUMBEROFVEGGIES = 30;
    static const int NUMBEROFRABBITS = 5;

    // objects in the game
    Captain *gameCaptain;
    vector<Veggie *> gameVeggies;
    vector<Rabbit *> gameRabbits;

    // helper functions for initialization
    void initVeggies();

    void initCaptain();

    void initRabbits();

    // functions to control the objects
    void moveCptVertical(int);

    void moveCptHorizontal(int);

    // helper functions
    static int sample(int, int); // for sample random integers in [a,b]

public:
    // functions for setting up the game
    void initializeGame();

    void intro();

    void gameOver();

    // function for moving creatures
    void moveRabbits();

    void moveCaptain();

    // helper functions for get the current states
    void printField();

    int getScore() const;

    int remainingVeggies();
};