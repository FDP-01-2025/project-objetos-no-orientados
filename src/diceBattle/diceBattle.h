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
int StartRandom()
{
    srand(time(0));
}

// The die is generated
int ThrowDice()
{
    return rand() % 6 + 1;
}

// Dice Options
void ShowDice(int number)
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
void AnimationDice()
{
    for (int i = 0; i < 5; ++i)
    {
        int num = ThrowDice();
// #ifdef is useful when the game is made for different operating systems
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "Rolling dice..." << endl;
        ShowDice(num);
    }
}

//Function for the player's turn
int PlayerTurn(string name){
    cout << nombre << "Roll the dice..." << endl;
    AnimationDice();
    int d1 = ThrowDice();
    int d2 = ThrowDice();
    cout << name << "Got: " << endl;
    ShowDice(d1);
    ShowDice(d2);
    int total = d1 + d2;
    cout << "Total: " << total << "\n\n";
    return 0;
}
//Function to play the round
void PlayRound(){
    int p1 = PlayerTurn(name1);
    int p2 = PlayerTurn(modeVSCPU ? "CPU" : name2);
    if(p1 > p2)
    cout << name1 << "I win the round!" << endl;
    else if (p2 > p1)
    cout << (modeVSCPU ? "CPU" : name2) << "I win the round!" << endl;
    else
    cout << "¡Draw!" << endl;
}
//Choose game mode
void SelectMode(){
    int option;
    cout << "Select the game mode: " << endl;
    cout << "1. Player vs Player" << endl;
    cout << "2. Player vs CPU" << endl;
    cin >> option;
    if(option == 2){
        modeVSCPU = true;
        name2 = "CPU";
    }
    else{
        modeVSCPU = false;
        cout << "Enter the name of the second player: " << endl;
        cin >> name2;
    }
}

#endif