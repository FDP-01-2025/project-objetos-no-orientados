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

extern string player_1;
extern string player_2;

// Inicializa la semilla aleatoria (hace que genere las palabras aleatoriamente)
inline void InicializarAleatorio() {
    srand(static_cast<unsigned>(time(0)));
}

// Devuelve una lista de palabras
inline vector<string> ObtenerListaPalabras() {
    return {
        "computadora", "pantalla", "raton", "teclado", "codigo", "programa", "tecnologia"
    };
}

// Selecciona una palabra al azar
inline string SeleccionarPalabraAzar() {
    vector<string> palabras = ObtenerListaPalabras();
    return palabras[rand() % palabras.size()];
}

// Mezcla una palabra
inline string MezclarPalabra(const string& palabra) {
    string mezclada = palabra;
    //Random_shuffle sirve para la mezcla de palabras de diferente forma
    random_shuffle(mezclada.begin(), mezclada.end());
    return mezclada;
}

// Compara si es correcta
inline bool Comparar(const string& intento, const string& correcta) {
    return intento == correcta;
}

// Simula si la CPU acierta (50% de probabilidad)
inline bool CpuRespondeBien() {
    return rand() % 2 == 0; // 0 o 1 → 50% de probabilidad
}

// Modo un jugador contra la CPU
inline void ModoUnJugador() {
    int rondas = 5, puntosJugador = 0, puntosCPU = 0;

    for (int i = 1; i <= rondas; ++i) {
        string palabra = SeleccionarPalabraAzar();
        string mezclada = MezclarPalabra(palabra);
        string intento;

        cout << "\n[Ronda " << i << "] :\nPalabra desordenada: " << mezclada << "\n";
        cout << player_1<< " Tu intento: ";
        cin >> intento;

        if (Comparar(intento, palabra)) {
            cout << "--Correcto--\n";
            ++puntosJugador;
        } else {
            cout << "--Incorrecto. Era: " << palabra << " --\n";
        }

        // Turno de la CPU
        cout << "\nCPU esta resolviendo...\n";
        if (CpuRespondeBien()) {
            cout << "CPU: " << palabra << " --Correcto--\n";
            ++puntosCPU;
        } else {
            cout << "--CPU: respuesta incorrecta.--\n";
        }
    }

    cout << "\n[(Puntaje Final)]:\n"<<player_1<<" "<< puntosJugador << "\nCPU: " << puntosCPU << "\n";

    if (puntosJugador > puntosCPU)
        cout << "--Ganaste contra la CPU--\n";
    else if (puntosCPU > puntosJugador)
        cout << "--La CPU gana esta vez.--\n";
    else
        cout << "--Empate--\n";
}

// Modo para dos jugadores 
inline void ModoMultijugador() {
    int rondas = 3, puntos1 = 0, puntos2 = 0;

    for (int i = 1; i <= rondas; ++i) {
        // Jugador 1
        string palabra1 = SeleccionarPalabraAzar();
        string mezclada1 = MezclarPalabra(palabra1);
        string intento1;

        cout << "\n[Ronda " << i << "]\nJugador "<<player_1<<" - Palabra: " << mezclada1 << "\n";
        cout << "Intento: ";
        cin >> intento1;

        if (Comparar(intento1, palabra1)) {
            cout << "--Correcto--\n";
            ++puntos1;
        } else {
            cout << "--Incorrecto. Era: " << palabra1 << " --\n";
        }

        // Jugador 2
        string palabra2 = SeleccionarPalabraAzar();
        string mezclada2 = MezclarPalabra(palabra2);
        string intento2;

        cout << "\n[Ronda " << i << "]\nJugador "<<player_2<<" - Palabra: " << mezclada2 << "\n";
        cout << "Intento: ";
        cin >> intento2;

        if (Comparar(intento2, palabra2)) {
            cout << "--Correcto--\n";
            ++puntos2;
        } else {
            cout << "--Incorrecto. Era: " << palabra2 << " --\n";
        }
    }

    cout << "\n[(Puntajes Finales)]:\n"<< player_1<< " : " << puntos1 << "\n"<< player_2 <<" : "<< puntos2 << "\n";

    if (puntos1 > puntos2)
        cout << "--Jugador "<< player_1 <<" gana--";
    else if (puntos2 > puntos1)
        cout << "--Jugador "<< player_2 <<" gana--";
    else
        cout << "--Empate--\n";
}

#endif