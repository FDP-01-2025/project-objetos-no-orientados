#ifndef DICE_BATTLE_H
#define DICE_BATTLE_H

// Libraries
#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <thread>
#include <cstdlib>
#include <vector>

using namespace std;

// Variables
string name1 = player_1; // Name player 1
string name2 = "Player 2"; // Name player 2
bool modeVSCPU;

int savedRound = 1; // Current round of the game
int totalRounds = 0; // Total rounds to play
int savedScore1 = 0; // Player 1 saves score
int savedScore2 = 0; // Player 2 saves score
bool hasSavedGame = false; // Find out if there is a game to load

// Wait for the key to be pressed
void WaitForKey()
{
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void PlayGame(bool resume = false);

// Generates a random roll
void StartRandom()
{
    srand(time(0));
}

// Dice faces
int ThrowDice()
{
    return rand() % 6 + 1;
}

// Dice Design
vector<string> GetDiceArt(int number)
{
    switch (number)
    {
    case 1:
        return {"+-----+", "|     |", "|  *  |", "|     |", "+-----+"};
    case 2:
        return {"+-----+", "| *   |", "|     |", "|   * |", "+-----+"};
    case 3:
        return {"+-----+", "| *   |", "|  *  |", "|   * |", "+-----+"};
    case 4:
        return {"+-----+", "| * * |", "|     |", "| * * |", "+-----+"};
    case 5:
        return {"+-----+", "| * * |", "|  *  |", "| * * |", "+-----+"};
    case 6:
        return {"+-----+", "| * * |", "| * * |", "| * * |", "+-----+"};
    default:
        return {};
    }
}

// Show the dice
void ShowTwoDice(int num1, int num2)
{
    vector<string> d1 = GetDiceArt(num1);
    vector<string> d2 = GetDiceArt(num2);
    for (size_t i = 0; i < d1.size(); ++i)
    {
        cout << d1[i] << "   " << d2[i] << endl;
    }
}

// Dice animation
void AnimationDice()
{
    for (int i = 0; i < 5; ++i)
    {
        int num1 = ThrowDice();
        int num2 = ThrowDice();

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        cout << "Rolling dice..." << endl;
        ShowTwoDice(num1, num2);
    }
}

// Save the result
void SaveResult(string winner, int score1, int score2, bool vsCPU)
{
    ofstream file("items.txt", ios::app);
    if (file.is_open())
    {
        file << "Winner: " << winner << " | ";
        file << player_1 << ": " << score1 << " | ";
        file << (vsCPU ? "CPU" : name2) << ": " << score2 << endl;
        file.close();
    }
}

// Save progress
void SaveGameProgress(int currentRound, int total, int score1, int score2, bool vsCPU)
{
    ofstream file("savegame.txt");
    if (file.is_open())
    {
        file << currentRound << " " << total << " " << score1 << " " << score2 << " " << vsCPU << endl;
        file << player_1 << endl;
        file << name2 << endl;
        file.close();
    }
}

// Load game
void LoadGameProgress()
{
    ifstream file("savegame.txt");
    if (file.is_open())
    {
        if (file >> savedRound >> totalRounds >> savedScore1 >> savedScore2 >> modeVSCPU)
        {
            file.ignore();
            getline(file, player_1);
            getline(file, name2);
            hasSavedGame = true;
        }
        else
        {
            hasSavedGame = false; // invalid or corrupt file
        }
        file.close();
    }
    else
    {
        hasSavedGame = false; // file does not exist
    }
}

// Player turn
int DicePlayerTurn(string name)
{
    int d1 = ThrowDice();
    int d2 = ThrowDice();

    cout << name << " rolls the dice..." << endl;

    // We show fake animation
    AnimationDice();

    // We show real circulation
    cout << name << " got:" << endl;
    ShowTwoDice(d1, d2);
    int total = d1 + d2;
    cout << "Total: " << total << "\n\n";
    return total;
}

// Play 1 vs 1
void PlayGamePVP() {
    modeVSCPU = false;

    cout << "Enter the name of Player 2: ";
    getline(cin, name2); // o cin >> name2 si preferís

    PlayGame();
}

// Play vs CPU
void PlayGameCPU() {
    modeVSCPU = true;
    name2 = "CPU"; // ya fijo

    PlayGame();
}

// Rules of the game
void ShowRules()
{
    cout << "\n========= RULES OF THE GAME =========\n";
    cout << "1. The game is for 2 players (can be Player vs Player or Player vs CPU).\n";
    cout << "2. Each player rolls two 6-sided dice per round.\n";
    cout << "3. Both players must roll their dice for the round to be valid.\n";
    cout << "4. The player who gets the highest sum in the round wins 1 point.\n";
    cout << "5. The player who accumulates the most points at the end of all rounds wins the game..\n";
    cout << "6. Players choose how many rounds they wish to play before starting.\n";
    cout << "====================================\n";
    WaitForKey(); // Pause for reading
}

// Start of game
void PlayGame(bool resume)
{
    if (!resume)
    {
        cout << "How many rounds do you want to play? ";
        cin >> totalRounds;
        cin.ignore();
        savedRound = 1;
        savedScore1 = 0;
        savedScore2 = 0;
    }

    for (int i = savedRound; i <= totalRounds; ++i)
    {
        cout << "\n========== ROUND " << i << " ==========" << endl;
        // Show the turn 1
        cout << "\n--- Turn of " << player_1 << " ---\n";
        int p1 = DicePlayerTurn(player_1);
        // Show the turn 2
        cout << "\n--- Turn of " << (modeVSCPU ? "CPU" : name2) << " ---\n";
        int p2 = DicePlayerTurn(modeVSCPU ? "CPU" : name2);
        // Round result
        cout << "\nRound result:\n";
        cout << player_1 << " Got " << p1 << " Points.\n";
        cout << (modeVSCPU ? "CPU" : name2) << " Got " << p2 << " Points.\n";

        if (p1 > p2)
        {
            // Victory validation
            cout << player_1 << " Win the round!\n";
            savedScore1++;
        }
        else if (p2 > p1)
        {
            // Victory validation
            cout << (modeVSCPU ? "CPU" : name2) << " Win the round!\n";
            savedScore2++;
        }
        else
        {
            // Draw validation
            cout << "¡Tie in the round!\n";
        }

        if (i < totalRounds)
        {
            SaveGameProgress(i + 1, totalRounds, savedScore1, savedScore2, modeVSCPU);
        }
        else
        {
            remove("savegame.txt");
        }

        WaitForKey();
    }

    // Final score
    cout << "\n========== FINAL SCORE ==========\n";
    cout << player_1 << ": " << savedScore1 << " Points\n"; // Show Points
    cout << (modeVSCPU ? "CPU" : name2) << ": " << savedScore2 << " Points\n"; // Show Points

    // In case of a tie
    string winner = "Draw";
    if (savedScore1 > savedScore2)
        winner = player_1;
    else if (savedScore2 > savedScore1)
        winner = (modeVSCPU ? "CPU" : name2);

    //Final winner
    cout << "\nFinal Winner: " << winner << "\n";
    SaveResult(winner, savedScore1, savedScore2, modeVSCPU);
    WaitForKey();
}
#endif
