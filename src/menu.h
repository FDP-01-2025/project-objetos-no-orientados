/*This file contains the functions for all the game menus.
 * Each function represents the menu it corresponds to.*/
// libraries
// Prevents redefinition errors or conflicts due to multiple inclusions.
#ifndef MENU_H
#define MENU_H
#include <limits> // Avoid errors if the user enters more data than expected
#include <iostream>
#include <string> // include string for error formatting
// Include the content of the games, the address of the files is called
#include "busRace/busRace.h"
#include "cardGame21/carGame.h"
// #include "cardGame21/carGame.h"
#include "messyWord/messyWord.h"
// #include "diceBattle/diceBattle.h"

// Libraries std for text message
using namespace std;

// Declaration of global variables
extern string player_1;
extern string player_2;

/// Direct definition of playersName to request name
void PlayersName()
{
    // Option to request the name again
    int option;
    // Bucle do While to request name in case of any error
    do
    {
        // Name of the main player, request
        cout << "Main player name 1: ";
        getline(cin, player_1);

        // Option for name validation
        cout << "confirm name? \n1.Yes \n2.No" << endl;
        cin >> option;

        // Clears the input buffer to avoid errors on the next read.
        cin.ignore(::numeric_limits<streamsize>::max(), '\n');

        if (cin.fail())
        {                // If the user did not enter a number.
            cin.clear(); // Clears the error state.
            option = 2;  // Forces the loop to repeat.
        }
        system("cls"); // Clears the terminal (Windows)

    } while (option != 1);
    // If the option is different from 1 it is repeated
}
/// Direct definition for second player name
void PlayerSecondName()
{
    // Option to request the name again
    int option;
    // Bucle do While to request name in case of any error
    do
    {
        // Name of the main player, request
        cout << "Name player 2: ";
        getline(cin, player_2);

        // Option for validation name
        cout << "confirm name? \n1.Yes \n2.No" << endl;
        cin >> option;

        // Clears the input buffer to avoid errors on the next read.
        cin.ignore(::numeric_limits<streamsize>::max(), '\n');

        if (cin.fail())
        {                // If the user did not enter a number.
            cin.clear(); // Clears the error state.
            option = 2;  // Forces the loop to repeat.
        }
        system("cls"); // Clears the terminal (Windows)
    } while (option != 1);
    // If the option is different from 1 it is repeated
}
/// Game menu, function to select the game mode
void MessyWordMenu()
{
    // Variable for the do-while loop and select game
    int option;
    do
    {
        // Message for menu of the select game
        cout << "\n--- Welcome to Messy Word " << player_1 << "---\n";
        cout << "--- Messy Word Menu ---\n";
        cout << "1. 1 vs CPU\n2. 1 vs 1\n3. Save Game \n4. Load Game\n5. Game Rules\n6. Exit\n";
        // It is stored in the variable option
        cin >> option;
        // Prevents previous entries from affecting new readings
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Switch case for select de Game mode
        switch (option)
        {
        case 1:
            cout << "Play 1 vs CPU\n";
            OnePlayerMode();
            break;
        case 2:
            cout << "Play 1 vs 1\n";
            PlayerSecondName();
            TwoPlayerMode();
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
/// Game menu, function to select the game mode
void BusRaceMenu()
{
    // Variable for the do-while loop and select game
    int option;
    do
    {
        // Message for menu of the select game
        cout << "\n--- Welcome to Bus Race " << player_1 << "---\n";
        cout << "--- Bus Race Menu ---\n";
        cout << "1. 1 vs CPU\n2. 1 vs 1\n3. Save Game \n4. Load Game\n5. Game Rules\n6. Exit\n";
        // It is stored in the variable option
        cin >> option;
        // Prevents previous entries from affecting new readings
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Switch case for select de Game mode
        switch (option)
        {
        case 1:
            cout << "Play 1 vs CPU\n";
            IniciarCarreraCPU();
            break;
        case 2:
            cout << "Play 1 vs 1\n";
            PlayerSecondName();
            IniciarCarrera1vs1();
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
/// Game menu, function to select the game mode
void Poker21Menu()
{
    // Variable for the do-while loop and select game
    int option;
    do
    {
        // Message for menu of the select game
        cout << "\n--- Welcome to 21 Poker " << player_1 << "---\n";
        cout << "--- 21 Poker Menu Menu ---\n";
        cout << "1. 1 vs CPU\n2. 1 vs 1\n3. Save Game \n4. Load Game\n5. Game Rules\n6. Exit\n";
        // It is stored in the variable option
        cin >> option;
        // Prevents previous entries from affecting new readings
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Switch case for select de Game mode
        switch (option)
        {
        case 1:
            Play21Cpu();
            break;
        case 2:
            PlayerSecondName();
            Play21();
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
/// Game menu, function to select the game mode
void DiceBattleMenu()
{
    // Variable for the do-while loop and select game
    int option;
    do
    {
        // Message for menu of the select game
        cout << "\n--- Welcome to Dice Battle " << player_1 << "---\n";
        cout << "--- Dice Battle Menu ---\n";
        cout << "1. 1 vs CPU\n2. 1 vs 1\n3. Save Game \n4. Load Game\n5. Game Rules\n6. Exit\n";
        // It is stored in the variable option
        cin >> option;
        // Prevents previous entries from affecting new readings
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Switch case for select de Game mode
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
/// Main Game menu 
void ChooseGame()
{
    // Definition of the variable for the game to choose
    int option;
    // Do while loop to choose the desired game or exit
    do
    {
        cout << "\n----- Welcome to Royale Casino " << player_1 << " -----\n";
        cout << "----- Select the game you want to run: -----\n";
        // Messages about available games
        cout << "1.Dice Battle \n2.21 POKER\n3.Crazy word\n4.Bus Race\n5.Leave The game" << endl;
        cin >> option;
        // Prevents previous entries from affecting new readings
        cin.ignore(numeric_limits<::streamsize>::max(), '\n');

        if (cin.fail())
        {                // If the user did not enter a number.
            cin.clear(); // Clears the error state.
            option = 0;  // Forces the loop to repeat.
        }
        // Switch that calls the menu function corresponding to the game
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
        // Game menu function
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
