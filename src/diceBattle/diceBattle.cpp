#include <iostream>
#include <diceBattle.h> // Se llama al archivo .h
using namespace std;

//Se llaman las funciones que se crearon

int main(){
    SetConsoleOutputCP(65001);  // Soporte para UTF-8 (acentos, ñ, etc.)
    StartRandom();
    SelectMode();
    PlayRound();

    return 0;
}