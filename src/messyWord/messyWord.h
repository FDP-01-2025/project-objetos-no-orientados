/*.h file where de functions to be used for the game will be written*/
/*Archivo .h donde se escribiran las funciones a utilizar para el juego*/
#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>   // Entrada/salida estándar
#include <string>     // Manejo de strings
#include <vector>     // Uso de vectores
#include <algorithm>  // random_shuffle
#include <ctime>      // time(0)
#include <cstdlib>    // rand(), srand()

using namespace std;

string name1 = "Player 1";
string name2 = "Player 2";

// Inicializa la semilla aleatoria (hace que genere las palabras aleatoriamente)
inline void inicializarAleatorio() {
    srand(static_cast<unsigned>(time(0)));
}

// Devuelve una lista de palabras
inline vector<string> obtenerListaPalabras() {
    return {
        "computadora", "pantalla", "raton", "teclado", "codigo", "programa", "tecnologia"
    };
}

// Selecciona una palabra al azar
inline string seleccionarPalabraAzar() {
    vector<string> palabras = obtenerListaPalabras();
    return palabras[rand() % palabras.size()];
}

// Mezcla una palabra
inline string mezclarPalabra(const string& palabra) {
    string mezclada = palabra;
    //Random_shuffle sirve para la mezcla de palabras de diferente forma
    random_shuffle(mezclada.begin(), mezclada.end());
    return mezclada;
}

// Compara si es correcta
inline bool comparar(const string& intento, const string& correcta) {
    return intento == correcta;
}

// Simula si la CPU acierta (50% de probabilidad)
inline bool cpuRespondeBien() {
    return rand() % 2 == 0; // 0 o 1 → 50% de probabilidad
}

// Modo un jugador contra la CPU
inline void modoUnJugador() {
    int rondas = 3, puntosJugador = 0, puntosCPU = 0;

    for (int i = 1; i <= rondas; ++i) {
        string palabra = seleccionarPalabraAzar();
        string mezclada = mezclarPalabra(palabra);
        string intento;

        cout << "\n[Ronda " << i << "] : Palabra desordenada: " << mezclada << "\n";
        cout << "Tu intento: ";
        cin >> intento;

        if (comparar(intento, palabra)) {
            cout << "---Correcto---\n";
            ++puntosJugador;
        } else {
            cout << "---Incorrecto. Era: " << palabra << " ---\n";
        }

        // Turno de la CPU
        cout << "CPU esta resolviendo...\n";
        if (cpuRespondeBien()) {
            cout << "CPU: " << palabra << " ---Correcto---\n";
            ++puntosCPU;
        } else {
            cout << "---CPU: respuesta incorrecta.---\n";
        }
    }

    cout << "\nPuntaje Final:\nJugador: " << puntosJugador << "\nCPU: " << puntosCPU << "\n";

    if (puntosJugador > puntosCPU)
        cout << "---Ganaste contra la CPU---\n";
    else if (puntosCPU > puntosJugador)
        cout << "---La CPU gana esta vez.---\n";
    else
        cout << "---Empate---\n";
}

// Modo para dos jugadores 
inline void modoMultijugador() {
    int rondas = 3, puntos1 = 0, puntos2 = 0;

    for (int i = 1; i <= rondas; ++i) {
        // Jugador 1
        string palabra1 = seleccionarPalabraAzar();
        string mezclada1 = mezclarPalabra(palabra1);
        string intento1;

        cout << "\n[Ronda " << i << "] Jugador 1 - Palabra: " << mezclada1 << "\n";
        cout << "Intento: ";
        cin >> intento1;

        if (comparar(intento1, palabra1)) {
            cout << "---Correcto---\n";
            ++puntos1;
        } else {
            cout << "---Incorrecto. Era: " << palabra1 << " ---\n";
        }

        // Jugador 2
        string palabra2 = seleccionarPalabraAzar();
        string mezclada2 = mezclarPalabra(palabra2);
        string intento2;

        cout << "\n[Ronda " << i << "] Jugador 2 - Palabra: " << mezclada2 << "\n";
        cout << "Intento: ";
        cin >> intento2;

        if (comparar(intento2, palabra2)) {
            cout << "---Correcto---\n";
            ++puntos2;
        } else {
            cout << "---Incorrecto. Era: " << palabra2 << " ---\n";
        }
    }

    cout << "\nPuntajes Finales:\n"<< name1 << " : " << puntos1 << "\n"<< name2 <<" : "<< puntos2 << "\n";

    if (puntos1 > puntos2)
        cout << "---Jugador "<< name1 <<" gana---";
    else if (puntos2 > puntos1)
        cout << "---Jugador "<< name2 <<" gana---";
    else
        cout << "---Empate---\n";
}

#endif