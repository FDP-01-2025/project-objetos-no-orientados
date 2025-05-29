[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - Royal Casino

## Descripción del Proyecto

El proyecto se basa en un banco de juegos compuesto por 3 minijuegos diferentes, dentro de los cuales, cada uno se hará en base a los temas vistos en clases. Al momento de la elección del minijuego deseado por el usuario, éste podrá escoger el que desea realizar, por medio de un menú interactivo.

Listado de minijuegos:

**1. Batalla de dados:**
 **- Temática:** Dos jugadores se enfrentan en un duelo al azar, según las rondas que deseen jugar. La batalla consiste en tirar dos dados, por ciertas rondas, donde cada ronda el puntaje obtenido se guarda, así sucesivamente hasta que se terminen las rondas, el jugador que obtenga el puntaje más alto al sumar los resultados de cada ronda, ganará la partida.

**Conceptos claves:**
- Switch case: Mostrar las opciones en la bienvenida.
- Vectores: Almacenar los datos obtenidos en cada ronda.
- Do-while: Decidir si el jugador desea volver a jugar.
- For: Repetir la cantidad de rondas y la cantidad de turnos de cada jugador.
- If-else: Decidir el ganador de la partida.
- String: Manejar los mensajes.

**2. Conecta 4:**
**Temática:** Dos jugadores se enfrentan en una cuadrícula de 9 columnas por 7 filas, el juego consiste en intentar alinear 4 fichas (horizontal, vertical), cada jugador tendrá su turno y ficha respectiva(O y X).

**Conceptos clave:**
- Switch case: Opciones del jugador antes de iniciar el minijuego
- Char: Iniciar el tablero en una matriz
- If - else: Se utilizará  para determinar qué jugador lanzará.
- Ciclo for: se utilizará para recorrer y colocar la ficha en la celda vacía.
- If-else: Verificar que hayan 4 fichas consecutivas ya sea de manera vertical o horizontal para verificar la victoria o empate en caso de que ningún jugador gane.
- do-while: Se usará para darle la opción al jugador si desea volver a jugar una vez la partida haya terminado.

**3. Palabra invertida:**
**Temática:** Es un juego para 2 personas, Se basa en mostrar una palabra invertida al azar, cada jugador cuenta únicamente con 1 intentos por ronda para adivinar la palabra correcta, el jugador que adivine la mayor cantidad de rondas, gana la partida.


**Conceptos clave:**
- Switch case: Menú de bienvenida con las opciones de jugar o volver al menú principal.
- Vectores: Listado de palabras y almacenamiento de resultados.
- Do while: Repetir el juego según el usuario.
- For: Repetir las rondas del juego.
- If else: Validar las respuestas de cada jugador y determinar si son correctas.
- String: Manipular las palabras(invertir, manipular, mostrar).
- rand(): Elegir palabras aleatoriamente para cada ronda y jugador.

## Equipo

- **Nombre del equipo:** Objetos no orientados
### Integrantes del equipo

1. **Nombre completo:** Josué Abdel Ortiz Deodanes  
   **Carnet:** 00017125

2. **Nombre completo:** Osmar Alejandro Rodas Rodriguez
   **Carnet:** 00068125

3. **Nombre completo:** Dominic Asiel Mejia Mendoza
   **Carnet:** 00042725

4. **Nombre completo:** Willians Anderson Nájera Sánchez
   **Carnet:** 00041625
   
(Agregar más integrantes si es necesario)

## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [URL del repositorio]
