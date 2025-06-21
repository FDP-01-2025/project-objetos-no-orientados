#include <iostream>
#include "busRace.h" // Se manda a llamar el archivo .h que contiene todas las funciones

using namespace std;
/*Main structure of the project, in this file only the functions are called
 *In this file only .h files will be called
 */

/*Archivo de prueba para juego*/

int main()
{
    int opc;
    cout << "Opcion" << endl;
    cin >> opc;

    switch (opc)
    {
    case 1:
        iniciarCarreraCPU();
        break;
    case 2:
        iniciarCarrera1vs1();
        break;
    default:
        break;
    }
    
}