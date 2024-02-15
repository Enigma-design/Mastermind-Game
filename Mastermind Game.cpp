#include <iostream>
#include <cstdlib>
#include <set>
#include <Windows.h>
#include <random>
using namespace std;

const int MAX = 6; //Maximum digits allowed 
char colors[MAX] = { 'R', 'G', 'B', 'Y', 'P', 'O' }; //Color codes 
char Pos1, Pos2, Pos3, Pos4; //solution digits by position
char guess[5]; // Players guess 
char gPos1, gPos2, gPos3, gPos4; // Digits guessed by player 
bool guessValid; //Determine if guess is correct
int correctPos = 0; // Number of digits in the correct position 
int correctNum = 0; // Number of correct digits, but not in the correct postion 

// Function to set text color
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Allows for color output 
    SetConsoleTextAttribute(hConsole, color);
}

int main() {

    srand(time(NULL));

    // Set Solution 

    do {
        Pos1 = colors[rand() % MAX];
        Pos2 = colors[rand() % MAX];
        Pos3 = colors[rand() % MAX];
        Pos4 = colors[rand() % MAX];
        //cout << Pos1 << Pos2 << Pos3 << Pos4 << endl; //THIS IS THE ANSWER TO THE CODE. DELETE "//" TO REVEAL THE COMPUTER'S PROCESS 
    } while (Pos1 == Pos2 || Pos1 == Pos3 || Pos1 == Pos4 || Pos2 == Pos3 || Pos2 == Pos4 || Pos3 == Pos4);

    do {

        do {
            guessValid = true;

            do {
                // verifying 4 digit code 
                cout << "'R', 'G', 'B', 'Y', 'P', 'O' \nEnter 4 digit color code :  ";
                cin >> guess;
            } while (guess[0] == '\0' || guess[1] == '\0' || guess[2] == '\0' || guess[3] == '\0');

            gPos1 = guess[0];
            gPos2 = guess[1];
            gPos3 = guess[2];
            gPos4 = guess[3];

            if (gPos1 == '0' || gPos2 == '0' || gPos3 == '0' || gPos4 == '0') guessValid = false;
            else if (gPos1 == gPos2 || gPos1 == gPos3 || gPos1 == gPos4 || gPos2 == gPos3 || gPos2 == gPos4 || gPos3 == gPos4) {
                guessValid = false;
            }

        } while (guessValid == false);

        //Check Player's Guess 
        correctPos = 0;
        correctNum = 0;
        if (gPos1 == Pos1) {
            correctPos++;
            setTextColor(12); // Red
            cout << gPos1;
        }
        else if (gPos1 == Pos2 || gPos1 == Pos3 || gPos1 == Pos4) {
            correctNum++;
            setTextColor(14); // Yellow
            cout << gPos1;
        }
        if (gPos2 == Pos2) {
            correctPos++;
            setTextColor(12); // Red
            cout << gPos2;
        }
        else if (gPos2 == Pos1 || gPos2 == Pos3 || gPos2 == Pos4) {
            correctNum++;
            setTextColor(14); // Yellow
            cout << gPos2;
        }
        if (gPos3 == Pos3) {
            correctPos++;
            setTextColor(12); // Red
            cout << gPos3;
        }
        else if (gPos3 == Pos1 || gPos3 == Pos2 || gPos3 == Pos4) {
            correctNum++;
            setTextColor(14); // Yellow
            cout << gPos3;
        }
        if (gPos4 == Pos4) {
            correctPos++;
            setTextColor(12); // Red
            cout << gPos4;
        }
        else if (gPos4 == Pos1 || gPos4 == Pos2 || gPos4 == Pos3) {
            correctNum++;
            setTextColor(14); // Yellow
            cout << gPos4;
        }

        if (correctPos == 4) {
            cout << "\nCongratulations! You have won!" << endl;
            break;
        }
        else {
            cout << endl << "Number of Correct Digits in Correct Position: " << correctPos << endl;
            cout << "Number of Correct Digits in Wrong Position: " << correctNum << endl;
        }
    } while (true);

    return 0;
}