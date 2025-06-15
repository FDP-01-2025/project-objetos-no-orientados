[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - Royal Casino

## Descripción del Proyecto

El proyecto se basa en un banco de juegos compuesto por 3 minijuegos diferentes, dentro de los cuales, cada uno se hará en base a los temas vistos en clases. Al momento de la elección del minijuego deseado por el usuario, éste podrá escoger el que desea realizar, por medio de un menú interactivo. Cada partida es guardada en caso de que el jugador quiera seguir jugando o navegando.
Cada minijuego es para dos jugadores, multijugador y contra CPU.

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

**2. Juego de cartas 21:**
**Temática:** Dos jugadores se enfrentan en un juego de cartas llamado 21, consiste en el primer jugador que consiga sumar 21 con la suma de cartas que se le irán brindando ganará el juego.

**Conceptos clave:**
- Switch case: Opciones del jugador antes de iniciar el minijuego
- While, do while: Para que el jugador pueda decidir si quiere otra carta o no
- If,  else - if: Para verificar quién ganó o si hubo empate.
- rand(): se utilizará para generar los números de la carta del 1 al 11.
- Array: Se podrá utilizar para manejar la mano de cartas.

**3. Palabra ordenada:**
**Temática:** Es un juego para 1 y 2 personas. Se basa en mostrar una palabra que está ordenada al azar la cual, cada jugador cuenta únicamente con 1 intentos por ronda para adivinar y ordenar la palabra correcta, el jugador que adivine la mayor cantidad de rondas, gana la partida.

**Conceptos clave:**
- Switch case: Menú de bienvenida con las opciones de jugar o volver al menú principal.
- Vectores: Listado de palabras y almacenamiento de resultados.
- Do while: Repetir el juego según el usuario.
- For: Repetir las rondas del juego.
- If else: Validar las respuestas de cada jugador y determinar si son correctas.
- String: Manipular las palabras(ordenar aleatoriamente, manipular, mostrar).
- rand(): Elegir palabras aleatoriamente para cada ronda y jugador.

**4. Carrera de buses:**
**Temática:** Es un minijuego representado por una carrera de buses para dos personas, en este caso multijugador con una persona externa y contra la computadora(CPU), consiste en una competencia aleatoria donde dos autobuses avanzan por turnos en una pista horizontal, donde cada jugador se le asigna una tecla y tiene que presionarla una cantidad de veces para avanzar.

**Conceptos clave:**
- Rand(): Para determinar los pasos que avanza CPU.
- Librerías.
- If-else: Determinar el bus ganador.
- While: Ejecutar la carrera hasta que un jugador alcance la meta.
- Switch: Menu interactivo.

## Equipo

- **Nombre del equipo:** Objetos no tan orientados
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



Para nombrar archivos y carpetas nuevos, vamos a usar
camelCase

Para nombrar variables
snake_case

Para Funciones
PascalCase