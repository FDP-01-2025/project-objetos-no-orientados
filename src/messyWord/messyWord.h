/*.h file where de functions to be used for the game will be written*/
/*Archivo .h donde se escribiran las funciones a utilizar para el juego*/
#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>  // Inout and output
#include <string>    // Strings management
#include <vector>    // Use of vectors
#include <algorithm> // Shuffle
#include <random>    // For random_device and default_random_engine
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
        "computer", "screen", "mouse", "keyboard", "code", "program", "technology", 
        "monitor", "printer", "internet", "software", "hardware", "algorithm", "netwok",
        "database", "security", "browser", "website", "password", "memory", "backup",
        "download", "upload", "scanner", "desktop", "laptop", "server", "cloud", "router", "email"
    };
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

// function to save the match
void SaveMessyWord(const string& player_1, int score1, const string& player_2, int score2)
{
    ofstream archivo("score_MessyWord.txt", ios::app);

    if (archivo.is_open())
    {
        archivo << "Resultado de la partida:" << endl;
        archivo << player_1 << ": " << score1 << endl;
        archivo << player_2 << ": " << score2 << endl;
        archivo << "-------------------------" << endl;
        archivo.close();
        cout << "Scores save in score_MessyWord.txt\n";
    }
    else
    {
        cout << " Error in save progress." << endl;
    }
}

void StopMessyWord()
{
    cout << "\nPress ENTER to continue...";
    cin.ignore();
    cin.get(); // Waits for the user to pres ENTER
}

void StopMessyWord();

inline void ShowSavedScores()
{
    ifstream file("score_MessyWord.txt");

    cout << "\n================= MATCH HISTORY =================\n";

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "Could not open the score file or it doesn't exist yet.\n";
    }

    cout << "=================================================\n";
    StopMessyWord(); // Pause until the user presses ENTER
}

inline void ResetMessyWordScores()
{
    ofstream file("score_MessyWord.txt",ios::trunc); // Truncate borra todo

    if (file.is_open())
    {
        file.close();
        cout << "\nAll match records have been deleted successfully.\n";
    }
    else
    {
        cout << "\nError: could not open score file to delete contents.\n";
    }

    StopMessyWord(); // Espera ENTER
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

        cout <<"\n------------------- [Round " << i << "] -------------------\n";
        cout << "\nWord: " << mixed << "\n";
        cout <<"[ "<< player_1 <<" ]" <<" Your guess: ";
        cin >> guess;

        if (IsCorrect(guess, word))
        {
            cout << "\n--Correct--\n";
            ++player_points;
        }
        else
        {
            cout << "--Incorrect The word was: " << word << " --\n";
        }

        // CPU turn
        string word_CPU = PickWord();
        string mixed_CPU = MixWord(word_CPU);

        cout << "\nWord: " << mixed_CPU << "\n";
        cout << "[ CPU ] CPU is guessing... ";
        if (CpuGuessRight())
        {
            cout << ": " << word_CPU << "\n--Correcto--\n";
            ++cpu_points;
        }
        else
        {
            cout << "\n--CPU Wrong answer--\n";
        }
    }
    cout <<"\n---------------- [(Final Score)] ----------------\n";
    cout << player_1 << ": " << player_points << "\nCPU: " << cpu_points << "\n";

    if (player_points > cpu_points)
    {
        cout <<"\n------------------ [YOU WIN] ------------------\n";
    }
    else if (cpu_points > player_points)
    {
        cout <<"\n------------------- [CPU WIN] -------------------\n";
    }
    else
    {
        cout <<"\n--------------------- [TIE] ---------------------\n";
    }
    SaveMessyWord(player_1, player_points, "CPU", cpu_points);
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

        cout <<"\n------------------- [Round " << i << "] -------------------\n";
        cout << "\nWord: " << mixed_1 << "\n";
        cout <<"[ "<< player_1 <<" ]" <<" Your guess: ";
        cin >> guess_1;

        if (IsCorrect(guess_1, word_1))
        {
            cout << "--Correct--\n";
            ++points_1;
        }
        else
        {
            cout << "--Incorrect The word was: " << word_1 << " --\n";
        }

        // Player 2
        string word_2 = PickWord();
        string mixed_2 = MixWord(word_2);
        string guess_2;

        cout << "\nWord: " << mixed_2 << "\n";
        cout <<"[ "<< player_2 <<" ]" <<" Your guess: ";
        cin >> guess_2;

        if (IsCorrect(guess_2, word_2))
        {
            cout << "--Correct--\n";
            ++points_2;
        }
        else
        {
            cout << "--Incorrect The word was: " << word_2 << " --\n";
        }
    }
        cout <<"\n---------------- [(Final Score)] ----------------\n"
         << player_1 << " : " << points_1 << "\n"
         << player_2 << " : " << points_2 << "\n";

    if (points_1 > points_2)
    {
        cout <<"\n---------------- [YOU WIN "<<player_1<<"] ----------------\n";
    }
    else if (points_2 > points_1)
    {
        cout <<"\n---------------- [YOU WIN "<<player_2<<"] ----------------\n";
    }
    else
    {
        cout <<"\n--------------------- [TIE] ---------------------\n";
    }
    SaveMessyWord(player_1, points_1, player_2, points_2);
    StopMessyWord();
}

inline void GameRules(){
    {
    cout << "========= RULES OF THE GAME =========\n";
    cout << "The rules of the Messy Word game are as follows:\n";
    cout << "- The objective is to guess scrambled words over several rounds.\n";
    cout << "- The player with the most correct guesses wins the game.\n";
    cout << "- Game Modes:\n";
    cout << "  * One Player: 5 rounds against the CPU. CPU has a 50% chance to guess correctly.\n";
    cout << "  * Two Players: 3 rounds. Each player guesses their own scrambled word.\n";
    cout << "- Each correct guess earns 1 point.\n";
    cout << "- If scores are tied, the game ends in a tie.\n";
    cout << "====================================\n";
    Stop();
}
}

#endif