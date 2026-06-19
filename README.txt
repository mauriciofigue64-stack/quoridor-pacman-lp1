README - Quoridor Pac-Man
Trabajo Practico LP1 - Universidad Catolica
Integrantes:
Mauricio Figueredo 
Maria Jose Romero 

Archivos del proyecto:
- main.c: contiene el flujo principal del juego y el game loop.
- quoridor.h: contiene constantes, estructuras y prototipos de funciones.
- quoridor.c: contiene la implementacion de las funciones del juego.
- mapa_editor.txt: archivo de mapa que se puede cargar desde el juego.

Como compilar en Linux:
gcc main.c quoridor.c -o quoridor_pacman -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

Como ejecutar:
./quoridor_pacman

Como compilar en Eclipse:
1. Crear un proyecto C.
2. Agregar main.c, quoridor.c y quoridor.h al proyecto.
3. Configurar raylib en el linker.
4. Agregar las librerias necesarias: raylib, GL, m, pthread, dl, rt y X11.
5. Compilar y ejecutar.

Controles de configuracion:
1: IA vs Player
2: Player vs Player
F1-F4: habilitar/deshabilitar fantasmas
Q/W/E/T: cambiar dificultad de cada fantasma
A/Z: aumentar/disminuir muros de Pac-Man
S/X: aumentar/disminuir muros de fantasmas
D/C: aumentar/disminuir vida de muros
M: cambiar mapa
BACKSPACE: abrir editor
ENTER: empezar partida
ESC: salir

Controles durante la partida:
Pac-Man:
Flechas: mover
M: colocar muro
O: cambiar orientacion del muro
L: cambiar lado del muro
ENTER: terminar turno
R: reiniciar
ESC: salir

Fantasmas en Player vs Player:
TAB: cambiar fantasma seleccionado
W/A/S/D: mover fantasma
N: colocar muro
O: cambiar orientacion del muro
L: cambiar lado del muro

Editor de mapas:
Flechas: mover cursor
U/J: aumentar/disminuir filas
I/K: aumentar/disminuir columnas
M: colocar/quitar muro permanente
P: ubicar Pac-Man
B: ubicar pac-bola
G: ubicar fantasma
S: guardar mapa en mapa_editor.txt
ENTER: volver a configuracion

Dificultad de fantasmas:
Dificultad 1: movimiento basico.
Dificultad 2: puede usar modo frenetico si ve a Pac-Man en linea recta.
Dificultad 3: comportamiento mas agresivo y posibilidad de usar muros en IA.

Reglas principales:
Pac-Man gana si come las 4 pac-bolas.
Los fantasmas ganan si Pac-Man pierde sus 3 vidas.
Pac-Man solo puede comer un fantasma despues de comer una pac-bola.
Los muros se colocan entre casillas, no ocupan una casilla completa.
