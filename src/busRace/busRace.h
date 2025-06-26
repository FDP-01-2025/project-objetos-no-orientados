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

// Declaration of global variables
extern string player_1;
extern string player_2;

//  Funcion Pausa para ver el resultado del juego
void Stop()
{
    cout << "\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get(); // Espera a que el usuario presione Enter
}

// Function to play for one player vs CPU
// Definition of the function to display the goal
void ShowTrack(int Player_Main, int Player_CPU)
{
    // Definition for players
    cout << "\n"
         << player_1 << ": ";
    for (int i = 0; i < Player_Main; i++)
        cout << "-";
    cout << "🚌";

    cout << "\nCPU: ";
    for (int i = 0; i < Player_CPU; i++)
        cout << "-";
    cout << "🚌\n";
}

void ShowTrack1vs1(int Player_Main, int Player_2)
{
    const int name_width = 10; // Ancho fijo para los errores
    // Definition for players
    cout << "\n"
         << setw(name_width) << player_1 << ": ";
    for (int i = 0; i < Player_Main; i++)
        cout << "-";
    cout << "🚌";

    cout << "\n"
         << setw(name_width) << player_2 << ": ";
    for (int i = 0; i < Player_2; i++)
        cout << "-";
    cout << "🚌\n";
}

void IniciarCarreraCPU()
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
        Player_CPU += rand() % 2;

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
#endif