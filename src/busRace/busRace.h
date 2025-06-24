/*.h file where de functions to be used for the game will be written*/
// Bookstores
#ifndef BUSRACE_H // Defining ifndef to avoid overwriting errors
#define BUSRACE_H

#include <iostream> //Avoid errors if the user enters more data than expected
#include <iostream>
#include <string>  // For name format
#include <conio.h> // use for _getch()
#include <cstdlib> // Use for rand()

using namespace std;

// Definition of goal size
const int GOAL = 50;

// Function to play for one player vs CPU
// Definition of the function to display the goal
void ShowTrack(int Player_Main, int Player_CPU)
{
    // Definition for players
    cout << "\nJugador: ";
    for (int i = 0; i < Player_Main; i++)
        cout << "-";
    cout << "🚌";

    cout << "\nCPU:     ";
    for (int i = 0; i < Player_CPU; i++)
        cout << "-";
    cout << "🚌\n";
}

void ShowTrack1vs1(int Player_Main, int Player_2)
{
    // Definition for players
    cout << "\nJugador 1:  ";
    for (int i = 0; i < Player_Main; i++)
        cout << "-";
    cout << "🚌";

    cout << "\nJugador 2:     ";
    for (int i = 0; i < Player_2; i++)
        cout << "-";
    cout << "🚌\n";
}

void iniciarCarreraCPU()
{
    int Player_Main = 0;
    int Player_CPU = 0;
    char tecla;

    cout << "\n¡La carrera ha comenzado!\n";
    cout << "Presiona [X] para avanzar tu bus.\n";

    while (Player_Main < GOAL && Player_CPU < GOAL)
    {
        ShowTrack(Player_Main, Player_CPU);

        // Avance del jugador
        tecla = _getch(); // espera a que se presione una tecla
        if (tecla == 'x' || tecla == 'X')
        {
            Player_Main++;
        }

        // Avance de la CPU (0 o 1 o 2 pasos)
        Player_CPU += rand() % 3;

        system("cls"); // Limpia la pantalla (Windows)
    }

    ShowTrack(Player_Main, Player_CPU);

    // Resultado
    if (Player_Main >= GOAL && Player_CPU >= GOAL)
    {
        cout << "\n¡Empate!\n";
    }
    else if (Player_Main >= GOAL)
    {
        cout << "\n¡Felicidades, GANASTE!\n";
    }
    else
    {
        cout << "\nLa CPU ha ganado...\n";
    }
}

void iniciarCarrera1vs1()
{
    int Player_Main = 0;
    int Player_2 = 0;
    char tecla;

    cout << "\n¡La carrera ha comenzado!\n";
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
    }
    else if (Player_Main >= GOAL)
    {
        cout << "\n¡Felicidades, GANASTE!\n";
    }
    else if (Player_2 >= GOAL)
    {
        cout << "\nGano el segundo...\n";
    }
    else
    {
        cout << "Error" << endl;
    }
}
#endif