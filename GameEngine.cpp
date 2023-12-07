// Zhiyu Yin, 12/6/2023
// implementation of GameEngine class

#include "GameEngine.h"
#include "Captain.h"
#include "FieldInhabitant.h"
#include "Rabbit.h"
#include "Veggie.h"

#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

using namespace std;

int GameEngine::sample(int lower, int upper) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(lower, upper);
    return dist(gen);
}

void GameEngine::initializeGame() {
    initVeggies();
    initCaptain();
    initRabbits();
    score = 0;
}

void GameEngine::initVeggies() {
    while (true) {
        // reading the file
        string filename;
        cout << "Please enter the name of the vegetable point file: ";
        cin >> filename;
        ifstream file(filename); // Automatically freed when coming out of scope
        if (!file) {
            cout << "\n" << filename << "does not exist! ";
        } else {
            // successfully find the file

            string line;

            // Read the first line for field size
            if (getline(file, line)) {
                istringstream iss(line);
                string token;
                getline(iss, token, ','); // Skip "Field Size" label
                getline(iss, token, ','); // Read width
                width = stoi(token);
                getline(iss, token, ','); // Read height
                height = stoi(token);
            } else {
                cerr << "failed to get field size...";
            }

            // init filed
            gameField = new FieldInhabitant **[height]; // Note: need to be free
            for (int i = 0; i < height; ++i) {
                gameField[i] = new FieldInhabitant *[width];
                for (int j = 0; j < width; ++j) {
                    gameField[i][j] = nullptr;
                }
            }

            // read vegetables and fill up vector of possible veggies
            while (getline(file, line)) {
                istringstream iss(line);
                string name;
                getline(iss, name, ',');
                string symbol;
                getline(iss, symbol, ',');
                string point;
                getline(iss, point, ',');

                // Note: need to be free
                auto *currVeggie = new Veggie(symbol, name, stoi(point));
                gameVeggies.push_back(currVeggie);
            }

            const int numOfKinds = gameVeggies.size();
            int restOfVeggies = NUMBEROFVEGGIES;
            while (restOfVeggies != 0) {
                int veggieIdx = sample(0, numOfKinds - 1);
                int i = sample(0, height - 1);
                int j = sample(0, width - 1);
                // cout << i << '\t' << j << '\t';
                if (gameField[i][j] == nullptr) {
                    // if it's empty, call copy ctor and dynamically allocate a new veggie
                    // object the type of this object is determined by the sampled random
                    // variable
                    gameField[i][j] = new Veggie(*gameVeggies[veggieIdx]);
                    restOfVeggies--;
                    // cout << restOfVeggies << '\n';
                } else {
                    // cout << restOfVeggies << '\n';
                    continue;
                }
            }
            // no need to close because we use RAII(ifstream file(filename)).
            break;
        }
    }
}

void GameEngine::initCaptain() {
    while (true) {
        int i = sample(0, height - 1);
        int j = sample(0, width - 1);
        if (gameField[i][j] == nullptr) {
            gameCaptain = new Captain(i, j);
            gameField[i][j] = gameCaptain;
            return;
        }
    }
}

void GameEngine::initRabbits() {
    int restOfRabbits = NUMBEROFRABBITS;
    while (restOfRabbits != 0) {
        int i = sample(0, height - 1);
        int j = sample(0, width - 1);
        if (gameField[i][j] == nullptr) {
            auto *thisRabbit = new Rabbit(i, j);
            gameRabbits.push_back(thisRabbit);
            gameField[i][j] = thisRabbit;
            restOfRabbits--;
        }
    }
}

int GameEngine::remainingVeggies() {
    int num = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            auto *test = dynamic_cast<Veggie *>(gameField[i][j]);
            if (test != nullptr) {
                num++;
            }
        }
    }
    return num;
}

void GameEngine::intro() {
    cout << "Welcome to Captain Veggie!\n"
         << "The rabbits have invaded your garden and you must harvest as \n"
            "many vegetables as possible before the rabbits eat them all! \n"
            "Each vegetable is worth a different number of points so go for \n"
            "the high score!\n\n"
         << "The vegetables are:\n";

    for (Veggie *thisVeggie: gameVeggies) {
        // overloaded << before, here we can print the info conveniently
        cout << *thisVeggie;
    }
}

void GameEngine::printField() {
    cout << "\n";
    for (int i = 0; i < height; ++i) {
        cout << "\n";
        for (int j = 0; j < width; ++j) {
            if (gameField[i][j] == nullptr) {
                cout << "   ";
            } else {
                cout << " " << gameField[i][j]->GetSymbol() << " ";
            }
        }
    }
    cout << "\n";
}

int GameEngine::getScore() const { return score; }


