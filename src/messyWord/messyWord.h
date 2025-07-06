/*.h file where de functions to be used for the game will be written*/
/*Archivo .h donde se escribiran las funciones a utilizar para el juego*/
#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>  // Inout and output
#include <string>    // Strings management
#include <vector>    // Use of vectors
#include <algorithm> // Shuffle
#include <random>    // Fr random_device and default_random_engine
#include <ctime>     // time(0)
#include <cstdlib>   // rand(), srand()

using namespace std;

extern string player_1;
extern string player_2;

// Start random numbers
inline void StarRandom()
{
    srand(static_cast<unsigned>(time(0)));
}

// Return word list
inline vector<string> GetWords()
{
    return {
        "computer", "screen", "mouse", "keyboard", "code", "program", "technology"};
}

// Pick one random word
inline string PickWord()
{
    vector<string> words = GetWords();
    return words[rand() % words.size()];
}

inline string MixWord(const string &word)
{
    string mixed = word;
    static random_device rd;              
    static default_random_engine rng(rd()); 
    shuffle(mixed.begin(), mixed.end(), rng); 
    return mixed;
}

// Check if guess is right
inline bool IsCorrect(const string & guess, const string & correct)
{
    return guess == correct;
}

// 50% chance CPU is correct
inline bool CpuGuessRight()
{
    return rand() % 2 == 0; // 0 o 1 → 50% probability
}

void StopMessyWord()
{
    cout << "\nPress ENTER to continue...";
    cin.ignore();
    cin.get(); // Waits for the user to pres ENTER
}

// One player mode: player vs CPU
inline void OnePlayerMode()
{
    int rounds = 5, player_points = 0, cpu_points = 0;

    for (int i = 1; i <= rounds; ++i)
    {
        string word = PickWord();
        string mixed = MixWord(word);
        string guess;

        cout << "\n[Round " << i << "] :\nWord: " << mixed << "\n";
        cout << player_1 << " Your guess: ";
        cin >> guess;

        if (IsCorrect(guess, word))
        {
            cout << "--Correct--\n";
            ++player_points;
        }
        else
        {
            cout << "--Incorrect. The word was: " << word << " --\n";
        }

        // CPU turn
        cout << "\nCPU is guessing...\n";
        if (CpuGuessRight())
        {
            cout << "CPU: " << word << " --Correcto--\n";
            ++cpu_points;
        }
        else
        {
            cout << "--CPU: Wrong answer.--\n";
        }
    }

    cout << "\n[(Final Score)]:\n"<< player_1 << " " << player_points << "\nCPU: " << cpu_points << "\n";

    if (player_points > cpu_points)
    {
        cout << "--YOU WIN--\n";
    }
    else if (cpu_points > player_points)
    {
        cout << "--CPU WIN--\n";
    }
    else
    {
        cout << "--TIE--\n";
    }
    StopMessyWord();
}

// Two player Mode: player vs player
inline void TwoPlayerMode()
{
    int rounds = 3, points_1 = 0, points_2 = 0;

    for (int i = 1; i <= rounds; ++i)
    {
        // Player 1
        string word_1 = PickWord();
        string mixed_1 = MixWord(word_1);
        string guess_1;

        cout << "\n[Round " << i << "]\nPlayer " << player_1 << " - word: " << mixed_1 << "\n";
        cout << "Guess: ";
        cin >> guess_1;

        if (IsCorrect(guess_1, word_1))
        {
            cout << "--Correct--\n";
            ++points_1;
        }
        else
        {
            cout << "--Incorrect. The word was: " << word_1 << " --\n";
        }

        // Player 2
        string word_2 = PickWord();
        string mixed_2 = MixWord(word_2);
        string guess_2;

        cout << "\n[Round " << i << "]\nPlayer " << player_2 << " - Word: " << mixed_2 << "\n";
        cout << "Guess: ";
        cin >> guess_2;

        if (IsCorrect(guess_2, word_2))
        {
            cout << "--Correct--\n";
            ++points_2;
        }
        else
        {
            cout << "--Incorrect. The word was: " << word_2 << " --\n";
        }
    }

    cout << "\n[(Final Score)]:\n"
         << player_1 << " : " << points_1 << "\n"
         << player_2 << " : " << points_2 << "\n";

    if (points_1 > points_2)
    {
        cout << "--Player " << player_1 << " wins--";
    }
    else if (points_2 > points_1)
    {
        cout << "--Player " << player_2 << " wins--";
    }
    else
    {
        cout << "--TIE--\n";
    }
    StopMessyWord();
}

#endif