/*.h file where de functions to be used for the game will be written*/
/*Archivo .h donde se escribiran las funciones a utilizar para el juego*/
//Bookstores
#ifndef DICE_BATTLE_H
#define DICE_BATTLE_H

#include <iostream>
#include <windows.h> //Windows-exclusive library, we use it to allow the console to display accents
#include <ctime> //Allows you to use time(0) to initialize random numbers with srand.
#include <thread> //It gives us access to this_thread::sleep_for, to pause the program (animation)
#include <chrono> //Defines time durations such as milliseconds, seconds, etc.
#include <cstdlib>

using namespace std;
//Global variables
string name1 = "Player 1";
string name2 = "Player 2";
bool modeVSCPU = false; // Indicates whether you chose to play against the CPU or not

// Random number generator.
int startRandom()
{
    srand(time(0));
}

// The die is generated
int throwDice()
{
    return rand() % 6 + 1;
}

// Dice Options
void showDice(int number)
{
    // A switch is used to choose which drawing to display.
    switch (number)
    {
    case 1:
        cout << "+-----+\n";
        cout << "|     |\n";
        cout << "|  *  |\n";
        cout << "|     |\n";
        cout << "+-----+\n";
        break;
    case 2:
        cout << "+-----+\n";
        cout << "| *   |\n";
        cout << "|     |\n";
        cout << "|   * |\n";
        cout << "+-----+\n";
        break;
    case 3:
        cout << "+-----+\n";
        cout << "| *   |\n";
        cout << "|  *  |\n";
        cout << "|   * |\n";
        cout << "+-----+\n";
        break;
    case 4:
        cout << "+-----+\n";
        cout << "| * * |\n";
        cout << "|     |\n";
        cout << "| * * |\n";
        cout << "+-----+\n";
        break;
    case 5:
        cout << "+-----+\n";
        cout << "| * * |\n";
        cout << "|  *  |\n";
        cout << "| * * |\n";
        cout << "+-----+\n";
        break;
    case 6:
        cout << "+-----+\n";
        cout << "| * * |\n";
        cout << "| * * |\n";
        cout << "| * * |\n";
        cout << "+-----+\n";
        break;
    }
}
// Dice animation
void animationDice()
{
    for (int i = 0; i < 5; ++i)
    {
        int num = throwDice();
// #ifdef is useful when the game is made for different operating systems
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "Rolling dice..." << endl;
        showDice(num);
    }
}
#endif