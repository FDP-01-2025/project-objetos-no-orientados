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
bool modeVSCPU; // Indicates whether you chose to play against the CPU or not

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
void PlayGame()
{
    int totalRounds;
    cout << "¿Cuántas rondas deseas jugar? ";
    cin >> totalRounds;

    int score1 = 0;
    int score2 = 0;

    for (int i = 1; i <= totalRounds; ++i)
    {
        cout << "\n--- Ronda " << i << " ---" << endl;
        int p1 = PlayerTurn(name1);
        int p2 = PlayerTurn(modeVSCPU ? "CPU" : name2);

        if (p1 > p2)
        {
            cout << name1 << " ¡win the round!" << endl;
            score1++;
        }
        else if (p2 > p1)
        {
            cout << (modeVSCPU ? "CPU" : name2) << " ¡win the round!" << endl;
            score2++;
        }
        else
        {
            cout << "¡Draw!" << endl;
        }
    }

    cout << "\n--- Resultado final ---" << endl;
    cout << name1 << ": " << score1 << " puntos" << endl;
    cout << (modeVSCPU ? "CPU" : name2) << ": " << score2 << " puntos" << endl;

    if (score1 > score2)
        cout << name1 << " ¡gana el juego!" << endl;
    else if (score2 > score1)
        cout << (modeVSCPU ? "CPU" : name2) << " ¡gana el juego!" << endl;
    else
        cout << "¡El juego terminó en empate!" << endl;
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