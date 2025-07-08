#include <iostream>
#include "src/menu.h" // The .h file that contains all the functions is called

using namespace std;
/*Main structure of the project, in this file only the functions are called
 *In this file only .h files will be called
 */

// Definition of global variables
string player_1;
string player_2;

// Main function
int main()
{
    cout << "\n----------------- Royal Casino ------------------" << endl;
    // Call the function 
    LoadPlayerNames();
    // Displays the names stored in the global variables  
    cout << "\n------------------- Players ---------------------\n";
    cout << "Player 1: " << player_1 << std::endl;
    // Call the function to choose the game  
    ChooseGame();
}