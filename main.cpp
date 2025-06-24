#include <iostream>
#include "src/menu.h" // Se manda a llamar el archivo .h que contiene todas las funciones

using namespace std;
/*Main structure of the project, in this file only the functions are called
 *In this file only .h files will be called
 */

// Definiicion de variables globales
string player_1;
string player_2;

// funcion principal
int main()
{
    cout << "---Royale Casino---" << endl;
    /// Mandar a llamar a la funcion
    PlayersName();
    // Muestra los nombres guardados en las variables globales
    cout << "\n----- Players ---\n";
    cout << "Player 1: " << player_1 << std::endl;

    // Mandar a llamar la funcion de escoger juego
    ChooseGame();
}