/*.h file where de functions to be used for the game will be written*/
// Bookstores
#ifndef BUSRACE_H // Defining ifndef to avoid overwriting errors
#define BUSRACE_H
#include <iomanip>  // Libreria que permite alinear el texto con un ancho fijo
#include <iostream> //Avoid errors if the user enters more data than expected
#include <iostream>
#include <string>  // For name format
#include <conio.h> // use for _getch()
#include <cstdlib> // Use for rand()

using namespace std;

// Definition of goal size
const int GOAL = 50;
// Save score 
const int SCORE_P1 = 0;
const int SCORE_P2 = 0;
// Declaration of global variables
extern string player_1;
extern string player_2;

// Pause function to see the game result
void Stop()
{
    cout << "\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get(); // Wait for the user to press enter
}

// Function to play for one player vs CPU
// Definition of the function to display the goal
void ShowTrack(int Player_Main, int Player_CPU)
{
    const int name_width = 13; // Fixed width to avoid typing errors

    cout << left; // Align text to the left

    // Player 1
    // setw sets the width of the next output
    cout << setw(name_width) << player_1 << ": |";
    // Use for print player 1's route
    for (int i = 0; i < Player_Main; i++)
    {
        cout << "-"; // Print player 1's progress
    }
    cout << "🚌"; // Player 1's car

    // For loop to print player progress
    for (int i = Player_Main; i < GOAL; i++)
    {
        cout << "."; // Print the rest of the track
    }
    cout << "|" << endl; // End of the track

    // Player CPU
    // setw sets the width of the next output
    cout << setw(name_width) << "CPU" << ": |";
    for (int i = 0; i < Player_CPU; i++)
    {
        cout << "-"; // Print CPU progress
    }
    cout << "🚌"; // CPU's car

    for (int i = Player_CPU; i < GOAL; i++)
    {
        cout << "."; // Print the rest of the track
    }
    cout << "|" << endl; // Endf of the track
}

void ShowTrack1vs1(int Player_Main, int Player_2)
{
    const int name_width = 12; // Fixed width to avoid typing errors
    // Definition for players
    cout << left; // Align text to the left
    // Player 1
    // setw sets the width of the next output
    cout << setw(name_width) << player_1 << ": |";
    // Use for print player 1's route
    for (int i = 0; i < Player_Main; i++)
    {
        cout << "-"; // Print player 1's progress
    }
    cout << "🚌";
    for (int i = Player_Main; i < GOAL; i++)
    {
        cout << "."; // Print the rest of the track
    }
    cout << "|" << endl; // Endf of the track

    // print player 2's route
    // setw sets the width of the next output
    cout << setw(name_width) << player_2 << ": |";
    for (int i = 0; i < Player_2; i++)
    {
        cout << "-"; // Print player 2's progress
    }
    cout << "🚌";
    for (int i = Player_2; i < GOAL; i++)
    {
        cout << "."; // Print the rest of the track
    }
    cout << "|" << endl; // Endf of the track
}

void IniciarCarreraCPU()
{
    int Player_Main = 0;
    int Player_CPU = 0;
    char tecla;

    cout << "\n¡The race has begun!\n";
    cout << "Presiona [X] para avanzar tu bus.\n";

    while (Player_Main < GOAL && Player_CPU < GOAL)
    {
        ShowTrack(Player_Main, Player_CPU);

        // Avance del jugador
        tecla = _getch(); // espera a que se presione una tecla
        if (tecla == 'x' || tecla == 'X')
        {
            Player_Main += (rand() % 2) + 1; // 1 o 2
        }

        // Avance de la CPU (0 o 1 o 2 pasos)
       Player_CPU += (rand() % 2) + 1;  // 1 o 2

        system("cls"); // Limpia la pantalla (Windows)
    }

    ShowTrack(Player_Main, Player_CPU);

    // Resultado
    if (Player_Main >= GOAL && Player_CPU >= GOAL)
    {
        cout << "\n¡Empate!\n";
        Stop();
    }
    else if (Player_Main >= GOAL)
    {
        cout << "\n¡Felicidades, GANASTE!\n";
        Stop();
    }
    else
    {
        cout << "\nLa CPU ha ganado...\n";
        Stop();
    }
}

void IniciarCarrera1vs1()
{
    int Player_Main = 0;
    int Player_2 = 0;
    char tecla;

    cout << "\n¡The race has begun!\n";
    cout << "Presiona [X] para avanzar tu bus 1.\n";
    cout << "Presiona [B] para avanzar tu bus 2.\n";

    while (Player_Main < GOAL && Player_2 < GOAL)
    {
        ShowTrack1vs1(Player_Main, Player_2);

        // Avance del jugador
        tecla = _getch(); // espera a que se presione una tecla
        if (tecla == 'x' || tecla == 'X')
        {
            Player_Main++;
        }
        else if (tecla == 'b' || tecla == 'B')
        {
            Player_2++;
        }

        system("cls"); // Limpia la terminal (Windows)
    }

    ShowTrack1vs1(Player_Main, Player_2);

    // Resultado
    if (Player_Main >= GOAL && Player_2 >= GOAL)
    {
        cout << "\n¡Empate!\n";
        //SCORE_P1++;
//SCORE_P2++;
        Stop();
    }
    else if (Player_Main >= GOAL)
    {
        cout << "\n¡Felicidades, GANASTE!\n";
        Stop();
    }
    else if (Player_2 >= GOAL)
    {
        cout << "\nGano el segundo...\n";
        Stop();
    }
    else
    {
        cout << "Error" << endl;
    }
}

// show the rules of the game
void ShowRulesBus()
{
    cout << "\n========= RULES OF THE GAME =========\n";
    cout << "The rules of the Bus Race game are as follows:\n";
    cout << "- The game is for two players: the player and the computer (or two players).\n";
    cout << "- Each bus advances by pressing an assigned key.\n";
    cout << "- Player vs. CPU, the player key is 'X'\n";
    cout << "- Player vs. Player 2, Player 1's key is 'X' and Player 2's key is 'K'\n";
    cout << "- A goal is set for all players to reach, and each player must arrive before their opponent.\n";
    cout << "- The bus that reaches the finish line wins..\n";
    cout << "====================================\n";
    Stop(); // Pause for reading
}

#endif