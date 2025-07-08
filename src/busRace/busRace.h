/*.h file where de functions to be used for the game will be written*/
// Bookstores
#ifndef BUSRACE_H // Defining ifndef to avoid overwriting errors
#define BUSRACE_H
#include <iomanip>  // Library that allows you to align text with a fixed width
#include <iostream> //Avoid errors if the user enters more data than expected
#include <fstream>
#include <string>  // For name format
#include <conio.h> // use for _getch()
#include <cstdlib> // Use for rand()
using namespace std;

// Definition of goal size
const int GOAL = 50;
// Save score
int SCORE_P1 = 0;
int SCORE_P1_J2 = 0;
int SCORE_P2 = 0;
int SCORE_CPU = 0;

// Declaration of global variables
extern string player_1;
extern string player_2;

// Pause function to see the game result
void Stop()
{
    cout << "\nPress ENTER to continue...";
    cin.ignore();
    cin.get(); // Wait for the user to press enter
}

// Show scores function
void ShowScores()
{
    cout << "\n========= SCORES =========\n";
    // It is validated if there are no scores
    if (SCORE_CPU == 0 && SCORE_P1 == 0 && SCORE_P1_J2 == 0 && SCORE_P2 == 0)
    {
        cout << "\nThere are no scores recorded.\n";
    }
    else
    {
        // Score for CPU vs Player 1
        cout << "\n--------- CPU vs " << player_1 << " ---------n";
        cout << "\nCPU: " << SCORE_CPU << endl;
        cout << player_1 << ": " << SCORE_P1 << endl;
        cout << endl;
        // Score for Player 1 vs Player 2
        cout << "\n--------- " << player_1 << " vs " << player_2 << " ---------\n";
        cout << player_1 << ": " << SCORE_P1_J2 << endl;
        cout << player_2 << ": " << SCORE_P2 << endl;
    }
    Stop(); // Pause for reading
}

// Save player's scores to a file
void SaveScores()
{
    // open a new file to save the scores
    ofstream file("./src/busRace/BusRace.txt", ios::app);

    if (file.is_open())
    {
        file << "========= SCORES =========\n";
        file << "\n========= Game: " << player_1 << " vs " << player_2 << " =========\n";
        file << "Player 1: " << player_1 << " - Score: " << SCORE_P1_J2 << "\n";
        file << "Player 2: " << player_2 << " - Score: " << SCORE_P2 << "\n";
        file << "\n========= Game: CPU" << " vs " << player_1 << " =========\n";
        file << "CPU - Score: " << SCORE_CPU << "\n";
        file << "Player 1: " << player_1 << " - Score: " << SCORE_P1 << "\n";
        file.close();
    }
    else
    {
        cout << "Error saving scores.\n";
    }
}

void LoadScores()
{
    ifstream file("./src/busRace/BusRace.txt"); // Open the file to read scores
    string line;                                // Variable to read each line

    // Local variables to store the last found
    int lastP1 = 0, lastP1_J2 = 0, lastP2 = 0, lastCPU = 0;
    bool isCPU = false;

    if (file.is_open()) // Check if the file opened successfully
    {
        while (getline(file, line)) // Iterates and reads the file line by line
        {
            // Detects if the game was against the CPU
            if (line.find("Game:") != string::npos && line.find("CPU") != string::npos)
            {
                isCPU = true;
            }
            // Detects if the match was between two human players
            else if (line.find("Game:") != string::npos && line.find("vs") != string::npos)
            {
                if (line.find("CPU") == string::npos)
                    isCPU = false; // Mark that it is NOT against the CPU
            }

            // Processes player scores
            if (line.find("Player 1:") != string::npos)
            {
                size_t pos = line.find("Score: ");
                if (pos != string::npos)
                {
                    if (isCPU)
                        lastP1 = stoi(line.substr(pos + 7)); // recover position
                    else
                        lastP1_J2 = stoi(line.substr(pos + 7)); // recover position
                }
            }
            else if (!isCPU && line.find("Player 2:") != string::npos)
            {
                size_t pos = line.find("Score: ");
                if (pos != string::npos)
                {
                    lastP2 = stoi(line.substr(pos + 7)); // recover position
                }
            }
            else if (line.find("CPU - Score:") != string::npos)
            {
                size_t pos = line.find(": ");
                if (pos != string::npos)
                {
                    lastCPU = stoi(line.substr(pos + 2)); // recover position
                }
            }
        }
        file.close();

        // the last found is assigned
        SCORE_P1 = lastP1;
        SCORE_P1_J2 = lastP1_J2;
        SCORE_P2 = lastP2;
        SCORE_CPU = lastCPU;
    }
    else
    {
        cout << "No previous scores found.\n";
    }
}
// Function to reset scores and delete data
void ResetScores()
{
    // ios::trunc empty the data
    ofstream file("./src/busRace/BusRace.txt", ios::trunc);
    if (file.is_open())
    {
        file << "";
        file.close();
    }
    else
    {
        cout << "error when deleting content\n";
    }

    // También reinicia tus variables globales
    SCORE_P1 = 0;
    SCORE_P1_J2 = 0;
    SCORE_P2 = 0;
    SCORE_CPU = 0;
}

// Function to play for one player vs CPU
// Definition of the function to display the goal
void ShowTrack(int Player_Main, int Player_CPU)
{
    const int name_width = 13; // Fixed width to avoid typing errors

    cout << left; // Align text to the left

    // Player 1
    // setw sets the width of the next output
    cout << setw(name_width) << player_1 << ": |";
    // Use for print player 1's route
    for (int i = 0; i < Player_Main; i++)
    {
        cout << "-"; // Print player 1's progress
    }
    cout << "R44"; // Player 1's car

    // For loop to print player progress
    for (int i = Player_Main; i < GOAL; i++)
    {
        cout << "."; // Print the rest of the track
    }
    cout << "|" << endl; // End of the track

    // Player CPU
    // setw sets the width of the next output
    cout << setw(name_width) << "CPU" << ": |";
    for (int i = 0; i < Player_CPU; i++)
    {
        cout << "-"; // Print CPU progress
    }
    cout << "R-8"; // CPU's car

    for (int i = Player_CPU; i < GOAL; i++)
    {
        cout << "."; // Print the rest of the track
    }
    cout << "|" << endl; // Endf of the track
}

void ShowTrack1vs1(int Player_Main, int Player_2)
{

    const int name_width = 12; // Fixed width to avoid typing errors
    // Definition for players
    cout << left; // Align text to the left
    // Player 1
    // setw sets the width of the next output
    cout << setw(name_width) << player_1 << ": |";
    // Use for print player 1's route
    for (int i = 0; i < Player_Main; i++)
    {
        cout << "-"; // Print player 1's progress
    }
    cout << "R44";
    for (int i = Player_Main; i < GOAL; i++)
    {
        cout << "."; // Print the rest of the track
    }
    cout << "|" << endl; // Endf of the track

    // print player 2's route
    // setw sets the width of the next output
    cout << setw(name_width) << player_2 << ": |";
    for (int i = 0; i < Player_2; i++)
    {
        cout << "-"; // Print player 2's progress
    }
    cout << "R-8";
    for (int i = Player_2; i < GOAL; i++)
    {
        cout << "."; // Print the rest of the track
    }
    cout << "|" << endl; // Endf of the track
}

void StartRaceCPU()
{

    // Players are initialized to zero
    int Player_Main = 0;
    int Player_CPU = 0;
    char key;

    // cout << "\n¡The race has begun!\n";
    /// cout << "Press [X] to advance your bus.\n";

    while (Player_Main < GOAL && Player_CPU < GOAL)
    {
        cout << "\n¡The race has begun!\n";
        cout << "Press [X] to advance your bus.\n";

        cout << endl;
        ShowTrack(Player_Main, Player_CPU);

        // Player Preview
        key = _getch(); // Wait for me to press the key
        if (key == 'x' || key == 'X')
        {
            Player_Main += (rand() % 2) + 1; // 1 o 2
            // The CPU player position is added randomly
        }

        // CPU advance(1 or 2)
        Player_CPU += (rand() % 2) + 1; // 1 o 2

        system("cls"); // Clean the terminal (Windows)
    }

    // The track is presented
    ShowTrack(Player_Main, Player_CPU);

    // Result
    if (Player_Main >= GOAL && Player_CPU >= GOAL)
    {
        cout << "\n¡Draw!\n";
        SCORE_P1++;
        SCORE_CPU++;
    }
    else if (Player_Main >= GOAL)
    {
        cout << "\n¡Congratulations, player " << player_1 << " won!\n";
        SCORE_P1++;
    }
    else
    {
        cout << "\nCPU WON...\n";
        SCORE_CPU++;
    }

    cout << endl;
    cout << "========= SCORES =========\n";
    cout << player_1 << ": " << SCORE_P1 << endl;
    cout << "CPU: " << SCORE_CPU << endl;
    cout << endl;
    SaveScores(); // Save scores to file
    Stop();
}

void StartRace1vs1()
{
    // Players are initialized to zero
    int Player_Main = 0;
    int Player_2 = 0;
    char key;

    while (Player_Main < GOAL && Player_2 < GOAL)
    {
        cout << "\n¡The race has begun!\n";
        cout << "Press [X] to advance your bus 1.\n";
        cout << "Press [B] to advance your bus 2.\n";
        cout << endl;

        ShowTrack1vs1(Player_Main, Player_2);

        // Player Preview
        key = _getch(); // Wait for me to press the key
        if (key == 'x' || key == 'X')
        {
            Player_Main++;
            // The position of the player when pressing the key is added
        }
        else if (key == 'b' || key == 'B')
        {
            Player_2++; // The position of the player when pressing the key is added
        }

        system("cls"); // Clean the terminal (Windows)
    }
    // The track is presented
    ShowTrack1vs1(Player_Main, Player_2);

    // Result
    if (Player_Main >= GOAL && Player_2 >= GOAL)
    {
        cout << "\n¡Draw!\n";
        SCORE_P1_J2++;
        SCORE_P2++;
        // Stop();
    }
    else if (Player_Main >= GOAL)
    {
        cout << "\n¡Congratulations, player " << player_1 << " won!\n";
        SCORE_P1_J2++;

        // Stop();
    }
    else if (Player_2 >= GOAL)
    {
        cout << "\n¡Congratulations, player " << player_2 << " won!\n";
        SCORE_P2++;

        // Stop();
    }
    else
    {
        cout << "Error, lost game" << endl;
    }
    cout << endl;
    cout << "========= SCORES =========\n";
    cout << player_1 << ": " << SCORE_P1_J2 << endl;
    cout << player_2 << ": " << SCORE_P2 << endl;
    cout << endl;
    SaveScores(); // Save scores to file
    Stop();
}
// show the rules of the game
void ShowRulesBus()
{
    cout << "\n========= RULES OF THE GAME =========\n";
    cout << "The rules of the Bus Race game are as follows:\n";
    cout << "- The game is for two players: the player and the computer (or two players).\n";
    cout << "- Each bus advances by pressing an assigned key.\n";
    cout << "- Player vs. CPU, the player key is 'X'\n";
    cout << "- Player vs. Player 2, Player 1's key is 'X' and Player 2's key is 'K'\n";
    cout << "- A goal is set for all players to reach, and each player must arrive before their opponent.\n";
    cout << "- The bus that reaches the finish line wins..\n";
    cout << "====================================\n";
    Stop(); // Pause for reading
}
#endif