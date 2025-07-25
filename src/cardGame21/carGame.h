/*.h file where de functions to be used for the game will be written*/
/*Archivo .h donde se escribiran las funciones a utilizar para el juego*/
/*.h file where de functions to be used for the game will be written*/
/*Archivo .h donde se escribiran las funciones a utilizar para el juego*/
#ifndef PLAY21_H
#define PLAY21_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// Declaration of global variables
extern string player_1;
extern string player_2;

// function to generate a ranmdon from 1 to 11
int RamdomCard()
{
    return rand() % 11 + 1;
}

int PlayerTurn(string name)
{
    int total = 0;
    char desition;

    // do while for if player decide take another card 
    do
    {
        int card = RamdomCard();
        cout << name << ", you got a card: " << card << endl;
        total += card;
        cout << "You got: " << total << endl;

        if (total >= 21)
            break;
            
        cout << "Do you want another card? (y/n): ";
        cin >> desition;
    } while (desition == 'y' || desition == 'Y');

    return total;
}

// function to save the match
void SaveMatch21(const string& player1, int score1, const string& player2, int score2)
{
    ofstream archivo("score_21.txt", ios::app);

    if (archivo.is_open())
    {
        archivo << "Resultado de la partida:" << endl;
        archivo << player1 << ": " << score1 << endl;
        archivo << player2 << ": " << score2 << endl;
        archivo << "-------------------------" << endl;
        archivo.close();
        cout << "Scores save in score_21.txt\n";
    }
    else
    {
        cout << " Error in save progress." << endl;
    }
}

//Principal function for Poker 21 game 
void Play21()
{
    srand(time(0));

    //Calling variables for player 1 and player 2
    cout << player_1 << ": ";
    cout << player_2 << ": ";

    //Variable to save the accumulation of points
    int total_player_1 = 0, total_player_2 = 0;

    //Variable to alternate shifts
    bool turn_1 = true, turn_2 = true;
    char decition;

    //While to alternate shifts
    while (turn_1 || turn_2)
    {
        if (turn_1) // Turn for player 1 
        {
            cout << "\n================= " << player_1 << "'s TURN =================\n";
            cout << player_1 << ", your total is: " << total_player_1 << endl;
            cout << "Do you want a card? (y/n): "; 
            cin >> decition;

            if (decition == 'y' || decition == 'Y')
            {
                int card = RamdomCard(); // The player get another card
                cout << "You got a card: " << card << endl;
                total_player_1 += card;
                cout << "New total: " << total_player_1 << endl; // New total cards for the player
                
                if (total_player_1 >= 21)
                {
                    turn_1 = false;
                    //Validation if player got more than 21 he lose
                    if (total_player_1 > 21)
                        cout << player_1 << " busted!" << endl;
                    //Validation if player got more than 21 he won
                    else
                        cout << player_1 << " got 21!" << endl;
                }
            }
            //Validation if player didn't want more cards
            else
            {
                turn_1 = false;
                cout << player_1 << " has decided to stop." << endl;
            }
        }

        if (turn_2) // Turn for player 2
        {
            cout << "\n================= " << player_2 << "'s TURN =================\n";
            cout << player_2 << ", your total is: " << total_player_2 << endl;
            cout << "Do you want a card? (y/n): ";
            cin >> decition;

            if (decition == 'y' || decition == 'Y')
            {
                int card = RamdomCard(); // The player get another card
                cout << "You got a card: " << card << endl;
                total_player_2 += card;
                cout << "New total: " << total_player_2 << endl; // New total cards for the player

                if (total_player_2 >= 21)
                {
                    turn_2 = false;
                    //Validation if player got more than 21 he lose
                    if (total_player_2 > 21)
                        cout << player_2 << " busted!" << endl;
                    //Validation if player got more than 21 he won
                    else
                        cout << player_2 << " got 21!" << endl;
                }
            }
            //Validation if player didn't want more cards
            else
            {
                turn_2 = false;
                cout << player_2 << " has decided to stop." << endl;
            }
        }
    }

    //Final results
    cout << "\n================= " << "Result" << " ================= " << endl;
    cout << "         " << player_1 << ": " << total_player_1  << " === " << player_2 << ": " << total_player_2  << "        " << endl ;
    

    //Validation if and else if to comprovate the winner
    if (total_player_1 > 21 && total_player_2 > 21)
        cout << "=== " << "Both of them lose! maybe next one " << "=== \n" << endl;
    else if (total_player_1 == 21)
        cout << "===== " << player_1 << " You won, you got 21." << "===== \n" << endl;
    else if (total_player_2 == 21)
        cout << "===== " << player_2 << " You won, you got 21." << "===== \n" << endl;
    else if (total_player_1 > 21)
        cout << "=== " << player_2 << " You won, " << player_1 << " got more than 21." << "=== \n" << endl;
    else if (total_player_2 > 21)
        cout << "=== " << player_1 << " You won, " << player_2 << " got more than 21." << "=== \n" << endl;
    else if (total_player_1 > total_player_2)
        cout << "===== " << player_1 << " You got more points." << "===== \n" << endl;
    else if (total_player_2 > total_player_1)
        cout << "===== " << player_2 << " You got more points." << "===== \n" << endl;
    else
        cout << "Draw" << endl;

    SaveMatch21(player_1, total_player_1, player_2, total_player_2);
}

void Play21Cpu()
{
    srand(time(0));

    //Calling variables for player 1 and player 2
    cout << player_1 << ": ";

    int playerTotal = PlayerTurn(player_1);

    // 
    int cpuTotal = 0;
    cout << "\nCPU's turn:" << endl;

    while (cpuTotal < 17) // 
    {
        int card = RamdomCard();
        cout << "CPU got a card: " << card << endl;
        cpuTotal += card;
        cout << "CPU total: " << cpuTotal << endl;
    }

    cout << "\n--- Final Results ---" << endl;
    cout << player_1 << ": " << playerTotal << endl;
    cout << "CPU: " << cpuTotal << endl;

    //
    if (playerTotal > 21 && cpuTotal > 21)
    {
        cout << "Both busted. No one wins!" << endl;
    }
    else if (playerTotal > 21)
    {
        cout << "You busted. CPU wins!" << endl;
    }
    else if (cpuTotal > 21)
    {
        cout << "CPU busted. " << player_1 << " wins!" << endl;
    }
    else if (playerTotal == cpuTotal)
    {
        cout << "It's a draw!" << endl;
    }
    else if (playerTotal > cpuTotal)
    {
        cout << player_1 << " wins!" << endl;
    }
    else
    {
        cout << "CPU wins!" << endl;
    }

    SaveMatch21(player_1, playerTotal, "CPU", cpuTotal);
}

void GameRules21()
{
    cout << "\n========= RULES OF THE GAME =========\n";
    cout << "1. The game is for 2 players (can be Player vs Player or Player vs CPU).\n";
    cout << "2. The goal is to reach 21 points or come close without going over. If you go over 21, you automatically lose.\n";
    cout << "3. Each player takes turns receiving a card.\n";
    cout << "4. Each players decide if want more cards or no.\n";
    cout << "5. If both reach 21 it's a tie.\n";
    cout << "====================================\n";
}


#endif
