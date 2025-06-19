/*En este archivo estan las funciones de todos los menus de los juegos, cada funcion representa el menu que le corresponde*/

/*Librerias*/
/*Definicion de ifndef para evitar errores de sobreescritura, preveencion de errores*/
#ifndef MENU_H
#define MENU_H
#include <limits> //evita errores si el usuario ingresa más datos de los esperados
#include <iostream>
#include <string> // include string para el formato de los nombres
// Libreria std para mensajes de texto
using namespace std;

/*Declaracion de variables globales*/
extern string player_1;
extern string player_2;

/// Definicion directa de playersName para solicitar los nombres
void PlayersName()
{
    // Opcion para solicitar el nombre de nuevo
    int option;
    // Bucle do While para solitar nombre en caso de algun error
    do
    {
        // Solicitud de nombre princpal de jugador 1
        cout << "Main player name 1: ";
        getline(cin, player_1);

        // Solicitud para el segundo jugador
        cout << "\nPlayer name 2: ";
        getline(cin, player_2);

        // Validacion de nombres
        cout << "confirm names? \n1.Yes \n2.No" << endl;
        cin >> option;

        // Limpia el buffer de entrada para evitar errores en la próxima lectura.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail())
        {                     // Si el usuario no ingresó un número.
            std::cin.clear(); // Limpia el estado de error.
            option = 2;       // Fuerza la repetición del bucle.
        }

    } while (option != 1);
    // Si la opcion es distinta de 1 se repite
}

/// Definicion directa de la funcion creada ChooseGame(), solitar juego
void ChooseGame()
{
    // Definicion de la variable para el juego a escoger
    int option;
    // Bucle en caso de algun error
    do
    {
        cout << "\n----- Choose one of our games that we present -----\n" << endl;
        // Se muestran los juegos disponibles
        cout << "1.Dice Battle \n2. 21 POKER\n3.Crazy word\n4.Carrera de busus\n5.Leave The game" << endl;
        cin >> option;
        // Limpia el buffer de entrada para evitar errores en la próxima lectura.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail())
        {                     // Si el usuario no ingresó un número.
            std::cin.clear(); // Limpia el estado de error.
            option = 0;       // Fuerza la repetición del bucle.
        }
        switch (opcion)
        {
        case 1:
            break;
        case 2:
            break;
        case 3: 
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (option != 5);

}
#endif
