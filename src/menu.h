/*En este archivo estan las funciones de todos los menus de los juegos, cada funcion representa el menu que le corresponde*/
/*Librerias*/
/*Definicion de ifndef para evitar errores de sobreescritura, preveencion de errores*/
#ifndef MENU_H
#define MENU_H
#include <limits> //evita errores si el usuario ingresa más datos de los esperados
#include <iostream>
#include <string> // include string para el formato de los nombres
// Archivo .h del juego Bus Race
#include "busRace/busRace.h"

// Libreria std para mensajes de texto
using namespace std;

/*Declaracion de variables globales*/
extern string player_1;
extern string player_2;

/// Definicion directa de playersName para solicitar los nombres
void PlayersName()
{
    // Opcion para solicitar el nombre de nuevo
    int option;
    // Bucle do While para solitar nombre en caso de algun error
    do
    {
        // Solicitud de nombre princpal de jugador 1
        cout << "Main player name 1: ";
        getline(cin, player_1);

        // Validacion de nombres
        cout << "confirm name? \n1.Yes \n2.No" << endl;
        cin >> option;

        // Limpia el buffer de entrada para evitar errores en la próxima lectura.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail())
        {                     // Si el usuario no ingresó un número.
            std::cin.clear(); // Limpia el estado de error.
            option = 2;       // Fuerza la repetición del bucle.
        }
        system("cls"); // Limpia la pantalla (Windows)

    } while (option != 1);
    // Si la opcion es distinta de 1 se repite
}
// Menu de juego, funcion para elegir la modalidad de juego
void MessyWordMenu()
{
    int option;
    do
    {
        cout << "\n--- Welcome to Messy Word " << player_1 << "---\n";
        cout << "--- Messy Word Menu ---\n";
        cout << "1. 1 vs CPU\n2. 1 vs 1\n3. Save Game \n4. Load Game\n5. Load\n6. Back\n";
        cin >> option;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option)
        {
        case 1:
            cout << "Play 1 vs CPU\n";
            break;
        case 2:
            cout << "Play 1 vs 1\n";
            break;
        case 3:
            cout << "Save Game\n";
            break;
        case 4:
            cout << "Load Game\n";
            break;
        case 5:
            cout << "Game Rules\n";
            break;
        case 6:
            cout << "Exit\n";
            break;
        default:
            cout << "Opción inválida.\n";
            break;
        }
    } while (option != 6);
}
// Menu de juego, funcion para elegir la modalidad de juego
void BusRaceMenu()
{
    int option;
    do
    {
        cout << "\n--- Welcome to Bus Race " << player_1 << "---\n";
        cout << "--- Bus Race Menu ---\n";
        cout << "1. 1 vs CPU\n2. 1 vs 1\n3. Save Game \n4. Load Game\n5. Load\n6. Back\n";
        cin >> option;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option)
        {
        case 1:
            cout << "Play 1 vs CPU\n";
            break;
        case 2:
            cout << "Play 1 vs 1\n";
            break;
        case 3:
            cout << "Save Game\n";
            break;
        case 4:
            cout << "Load Game\n";
            break;
        case 5:
            cout << "Game Rules\n";
            break;
        case 6:
            cout << "Exit\n";
            break;
        default:
            cout << "Opción inválida.\n";
            break;
        }
    } while (option != 6);
}
// Menu de juego, funcion para elegir la modalidad de juego
void Poker21Menu()
{
    int option;
    do
    {
        cout << "\n--- Welcome to 21 Poker " << player_1 << "---\n";
        cout << "--- 21 Poker Menu Menu ---\n";
        cout << "1. 1 vs CPU\n2. 1 vs 1\n3. Save Game \n4. Load Game\n5. Load\n6. Back\n";
        cin >> option;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option)
        {
        case 1:
            cout << "Play 1 vs CPU\n";
            break;
        case 2:
            cout << "Play 1 vs 1\n";
            break;
        case 3:
            cout << "Save Game\n";
            break;
        case 4:
            cout << "Load Game\n";
            break;
        case 5:
            cout << "Game Rules\n";
            break;
        case 6:
            cout << "Exit\n";
            break;
        default:
            cout << "Opción inválida.\n";
            break;
        }
    } while (option != 6);
}
/// Definicion directa de la funcion creada ChooseGame(), solitar juego
// Menu de juego, funcion para elegir la modalidad de juego
void DiceBattleMenu()
{
    int option;
    do
    {
        cout << "\n--- Welcome to Dice Battle " << player_1 << "---\n";
        cout << "--- Dice Battle Menu ---\n";
        cout << "1. 1 vs CPU\n2. 1 vs 1\n3. Save Game \n4. Load Game\n5. Load\n6. Back\n";
        cin >> option;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option)
        {
        case 1:
            cout << "Play 1 vs CPU\n";
            break;
        case 2:
            cout << "Play 1 vs 1\n";
            break;
        case 3:
            cout << "Save Game\n";
            break;
        case 4:
            cout << "Load Game\n";
            break;
        case 5:
            cout << "Game Rules\n";
            break;
        case 6:
            cout << "Exit\n";
            break;
        default:
            cout << "Opción inválida.\n";
            break;
        }
    } while (option != 6);
}
//Menu principal del juego
void ChooseGame()
{
    // Definicion de la variable para el juego a escoger
    int option;
    // Bucle en caso de algun error
    do
    {
        cout << "\n----- Welcome to Royale Casino " << player_1 << " -----\n";
        cout << "----- Select the game you want to run: -----\n";
        // Se muestran los juegos disponibles
        cout << "1.Dice Battle \n2.21 POKER\n3.Crazy word\n4.Bus Race\n5.Leave The game" << endl;
        cin >> option;
        // Limpia el buffer de entrada para evitar errores en la próxima lectura.
        cin.ignore(numeric_limits<::streamsize>::max(), '\n');

        if (cin.fail())
        {                // Si el usuario no ingresó un número.
            cin.clear(); // Limpia el estado de error.
            option = 0;  // Fuerza la repetición del bucle.
        }
        // Switch que manda a llamar la funcion del menu correspondiente al juego
        switch (option)
        {
        case 1:
            DiceBattleMenu();
            break;
        case 2:
            Poker21Menu();
            break;
        case 3:
            MessyWordMenu();
            break;
        case 4:
            BusRaceMenu();
            break;
        case 5:
            cout << "Leaving the game...\n";
            break;
        default:
            cout << "Invalid option.\n";
            break;
        }
    } while (option != 5);
}
#endif
