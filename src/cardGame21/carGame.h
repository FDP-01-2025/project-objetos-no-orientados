/*.h file where de functions to be used for the game will be written*/
/*Archivo .h donde se escribiran las funciones a utilizar para el juego*/
/*.h file where de functions to be used for the game will be written*/
/*Archivo .h donde se escribiran las funciones a utilizar para el juego*/
#ifndef PLAY21_H
#define PLAY21_H

#include <iostream>
#include <cstdlib>
#include <ctime>
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
    char decision;

    //While to alternate shifts
    while (turn_1 || turn_2)
    {
        if (turn_1)
        {
            cout << "\n" << player_1 << "'s turn:" << endl;
            cout << player_1 << ", your total is: " << total_player_1 << endl;
            cout << "Do you want a card? (y/n): ";
            cin >> decision;

            if (decision == 'y' || decision == 'Y')
            {
                int card = RamdomCard();
                cout << "You got a card: " << card << endl;
                total_player_1 += card;
                cout << "New total: " << total_player_1 << endl;
                
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

        if (turn_2)
        {
            cout << "\n" << player_2 << "'s turn:" << endl;
            cout << player_2 << ", your total is: " << total_player_2 << endl;
            cout << "Do you want a card? (y/n): ";
            cin >> decision;

            if (decision == 'y' || decision == 'Y')
            {
                int card = RamdomCard();
                cout << "You got a card: " << card << endl;
                total_player_2 += card;
                cout << "New total: " << total_player_2 << endl;

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
    cout << "Result" << endl;
    cout << player_1 << ": " << total_player_1 << endl;
    cout << player_2 << ": " << total_player_2 << endl;

    //Validation if and else if to comprovate the winner
    if (total_player_1 > 21 && total_player_2 > 21)
        cout << "Both of them lose! maybe next one :( ." << endl;
    else if (total_player_1 == 21)
        cout << player_1 << " You won, you got 21." << endl;
    else if (total_player_2 == 21)
        cout << player_2 << " You won, you got 21." << endl;
    else if (total_player_1 > 21)
        cout << player_2 << " You won, " << player_1 << " got more than 21." << endl;
    else if (total_player_2 > 21)
        cout << player_1 << " You won, " << player_2 << " got more than 21." << endl;
    else if (total_player_1 > total_player_2)
        cout << player_1 << " You got more points." << endl;
    else if (total_player_2 > total_player_1)
        cout << player_2 << " You got more points." << endl;
    else
        cout << "Draw" << endl;
}

#endif
