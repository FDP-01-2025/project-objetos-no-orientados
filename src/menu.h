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
#include "messyWord/messyWord.h"
#include "diceBattle/diceBattle.h"

// Libraries std for text message
using namespace std;

// Declaration of global variables
extern string player_1;
extern string player_2;

// Function to store the players' names in a txt file
void SavePlayers()
{
    ofstream file("item.txt");

    if (file.is_open())
    {
        file << "---------------- Players Names ------------\n"
             << endl; // Header
        file << "Player 1: " << player_1 << endl;
        file << "\nPlayer 2: " << player_2 << endl; // Write the name to the file
        file.close();                               // Close the file
    }
    else
    {
        // Error validation
        cout << "Error save names." << endl;
    }
}

/// Direct definition of playersName to request name
void PlayersName()
{
    // Option to request the name again
    int option;
    // Bucle do While to request name in case of any error
    do
    {
        // Name of the main player, request
        cout << "\nMain player name 1: ";
        getline(cin, player_1);

        // Option for name validation
        cout << "\nconfirm name? \n1.Yes \n2.No" << endl;
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

    // Function to store the names
    SavePlayers();
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
        cout << "\nName player 2: ";
        getline(cin, player_2);

        // Option for validation name
        cout << "\nconfirm name? \n1.Yes \n2.No" << endl;
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

    // function to store names
    SavePlayers();
}

/// Function to load names if they exist
void LoadPlayerNames()
{
    ifstream file("item.txt");

    if (file.is_open())
    {
        string line; // Read empty lines

        getline(file, line); // header line
        getline(file, line); // empty line

        // read player 1 name
        getline(file, line);
        // It is validated that the line is not empty and contains ":"
        // After validating, extract the name of player 1
        if (!line.empty() && line.find(":") != string::npos)
        {
            player_1 = line.substr(line.find(":") + 2);
        }

        // read player 2 name
        getline(file, line);
        if (!line.empty() && line.find(":") != string::npos)
        {
            player_2 = line.substr(line.find(":") + 2);
        }

        file.close();
    }
    else
    { // Errror validation
        cout << "Error loading names." << endl;
    }

    // Verify after to read the names
    if (player_1.empty())
    {
        PlayersName(); // If the name does not exist, it is requested
    }
}

/// Game menu, function to select the game mode
void MessyWordMenu()
{
    // Variable for the do-while loop and select game
    int option;
    do
    {
        // Message for menu of the select game
        cout << "\n=================================================\n";
        cout << "             WELCOME TO MESSY WORD " << player_1 << "\n";
        cout << "=================================================\n";
        cout << "---------------- Messy Word Menu ----------------\n";
        cout << "\n1. 1 vs CPU\n2. 1 vs 1\n3. Reset Scores \n4. Show Scores\n5. Game Rules\n6. Exit\n";
        // It is stored in the variable option
        cin >> option;
        // Prevents previous entries from affecting new readings
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Switch case for select de Game mode
        switch (option)
        {
        case 1:
            cout << "\n----------------- Play 1 vs CPU -----------------\n";
            OnePlayerMode();
            break;
        case 2:
            cout << "\n------------------ Play 1 vs 1 ------------------\n";
            // if dont exist player_2 name, request it
            if (player_2.empty())
            {
                PlayerSecondName(); // If player 2 name is empty, request it
            }
            TwoPlayerMode();
            break;
        case 3:
            cout << "\n------------------ Reset Scores -----------------\n";
            ResetMessyWordScores();
            break;
        case 4:
            cout << "\n------------------ Show Scores ------------------\n";
            ShowSavedScores();
            break;
        case 5:
            cout << "\n------------------ Game Rules ------------------\n";
            GameRules();
            break;
        case 6:
            cout << "\n-------------------- Exit ----------------------\n";
            break;
        default:
            cout << "Invalid option.\n";
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
        cout << "\n=================================================\n";
        cout << "             WELCOME TO BUS RACE " << player_1 << "\n";
        cout << "=================================================\n";
        cout << "----------------- Bus Race Menu -----------------\n";
        cout << "\n1. 1 vs CPU\n2. 1 vs 1\n3. New Game \n4. Scores\n5. Game Rules\n6. Exit\n";
        // It is stored in the variable option
        cin >> option;
        // Prevents previous entries from affecting new readings
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        LoadScores(); // Load scores from file
        // Switch case for select de Game mode
        switch (option)
        {
        case 1:
            cout << "\n----------------- Play 1 vs CPU -----------------\n";
            StartRaceCPU();
            break;
        case 2:
            cout << "\n------------------ Play 1 vs 1 ------------------\n";
            // if dont exist player_2 name, request it
            if (player_2.empty())
            {
                PlayerSecondName(); // If player 2 name is empty, request it
            }
            StartRace1vs1();
            break;
        case 3:
            cout << "\n------------------- New Game --------------------\n";
            ResetScores(); // Reset scores to start a new game
            break;
        case 4:
            cout << "\n------------------ Show Scores ------------------\n";
            ShowScores(); // Show the scores of the game
            break;
        case 5:
            cout << "\n------------------ Game Rules ------------------\n";
            ShowRulesBus(); // Show the rules of the game
            break;
        case 6:
            cout << "\n---------------------- Exit --------------------\n";
            break;
        default:
            cout << "Invalid option.\n";
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
        cout << "\n=================================================\n";
        cout << "             WELCOME TO 21 POKER " << player_1 << "\n";
        cout << "=================================================\n";
        cout << "----------------- 21 Poker Menu -----------------\n";
        cout << "\n1. 1 vs CPU\n2. 1 vs 1\n3. Game Rules\n4. Exit\n";
        // It is stored in the variable option
        cin >> option;
        // Prevents previous entries from affecting new readings
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Switch case for select de Game mode
        switch (option)
        {
        case 1:
            cout << "\n----------------- Play 1 vs CPU -----------------\n";
            Play21Cpu();
            break;
        case 2:
            cout << "\n------------------ Play 1 vs 1 ------------------\n";
            // if dont exist player_2 name, request it
            if (player_2.empty())
            {
                PlayerSecondName(); // If player 2 name is empty, request it
            }
            Play21();
            break;
        case 3:
            cout << "\n------------------ Game Rules ------------------\n";
            GameRules21();
            break;
        case 4:
            cout << "\n---------------------- Exit --------------------\n";
            break;
        default:
            cout << "Invalid option.\n";
            break;
        }
    } while (option != 4);
}
/// Game menu, function to select the game mode
void DiceBattleMenu()
{
    // Variable for the do-while loop and select game
    int option;
    do
    {
        // Message for menu of the select game
        cout << "\n=================================================\n";
        cout << "            WELCOME TO DICE BATTLE " << player_1 << "\n";
        cout << "=================================================\n";
        cout << "--------------- Dice Battle Menu ----------------\n";
        cout << "\n1. 1 vs CPU\n2. 1 vs 1\n3. Load Game\n4. Game Rules\n5. Exit\n";
        // It is stored in the variable option
        cin >> option;
        // Prevents previous entries from affecting new readings
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Switch case for select de Game mode
        switch (option)
        {
        case 1:
            cout << "\n----------------- Play 1 vs CPU -----------------\n";
            PlayGameCPU();
            break;
        case 2:
            cout << "\n------------------ Play 1 vs 1 ------------------\n";
            if (player_2.empty())
            {
                PlayerSecondName(); // If player 2 name is empty, request it
            }
            PlayGamePVP();
            break;
        case 3:
            cout << "\n------------------ Load Game ------------------\n";
            LoadGameProgress();
            if (hasSavedGame)
            {
                PlayGame(true);
            }
            else
            {
                cout << "No saved game found.\n";
            }
            break;
        case 4:
            cout << "\n------------------ Game Rules ------------------\n";
            ShowRules();
            break;
        case 5:
            cout << "\n---------------------- Exit --------------------\n";
            cout << "Exit the game...\n";
            break;
        default:
            cout << "Invalid option.\n";
            break;
        }
    } while (option != 5);
}
/// Main Game menu
void ChooseGame()
{
    // Definition of the variable for the game to choose
    int option;
    // Do while loop to choose the desired game or exit
    do
    {
        cout << "\n=================================================\n";
        cout << "           WELCOME TO ROYAL CASINO " << player_1 << "\n";
        cout << "=================================================\n";
        cout << "         Select the game you want to run:\n";
        cout << "_________________________________________________\n";
        // Messages about available games
        cout << "\n1.Dice Battle \n2.21 POKER\n3.Crazy word\n4.Bus Race\n5.Leave The game" << endl;
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
