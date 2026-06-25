#ifndef QUORIDOR_H
#define QUORIDOR_H

#include "raylib.h"
#include <stdio.h>

#define MAX_FILAS 12
#define MAX_COLUMNAS 12
#define TAM_CASILLA 45
#define CANT_PACBOLAS 4
#define CANT_FANTASMAS 4

#define PANTALLA_CONFIGURACION 0
#define PANTALLA_JUEGO 1
#define PANTALLA_EDITOR 2

#define MODO_IA 0
#define MODO_PVP 1

#define TURNO_PACMAN 0
#define TURNO_FANTASMAS 1

#define LIBRE 0
#define MURO_PERMANENTE 1

#define SIN_DUENO 0
#define DUENO_PACMAN 1
#define DUENO_FANTASMAS 2

#define ORIENTACION_VERTICAL 0
#define ORIENTACION_HORIZONTAL 1

#define MUROS_INICIALES_PACMAN 3
#define MUROS_INICIALES_FANTASMAS 2
#define VIDA_MURO_TEMPORAL 4

/*
    NOTA IMPORTANTE:
    En esta version los muros temporales NO ocupan una casilla.
    Se guardan como laterales entre casillas:
    - muroVertical[fila][columna] bloquea izquierda/derecha.
    - muroHorizontal[fila][columna] bloquea arriba/abajo.
*/

typedef struct
{
    int fila;
    int columna;
} Posicion;

typedef struct
{
    Posicion pos;
    int activa;
} PacBola;

typedef struct
{
    Posicion pos;
    Posicion inicio;
    int activo;
    int habilitado;
    int dificultad;
    Color color;
} Fantasma;

void limpiarTodo(int tablero[MAX_FILAS][MAX_COLUMNAS],
                 int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                 int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                 int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                 int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                 int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                 int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS]);

void inicializarPacBolas(PacBola pacbolas[]);
void inicializarFantasmas(Fantasma fantasmas[]);

void cargarMapaPredefinido(int mapa, int *filas, int *columnas, Posicion *pacman,
                           PacBola pacbolas[], Fantasma fantasmas[],
                           int tablero[MAX_FILAS][MAX_COLUMNAS],
                           int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS]);

int guardarMapaArchivo(char nombre[], int filas, int columnas, Posicion pacman,
                       PacBola pacbolas[], Fantasma fantasmas[],
                       int tablero[MAX_FILAS][MAX_COLUMNAS]);

int cargarMapaArchivo(char nombre[], int *filas, int *columnas, Posicion *pacman,
                      PacBola pacbolas[], Fantasma fantasmas[],
                      int tablero[MAX_FILAS][MAX_COLUMNAS],
                      int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                      int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                      int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS]);

void actualizarConfiguracion(int *modoJuego, Fantasma fantasmas[],
                             int *murosInicialesPacman, int *murosInicialesFantasmas,
                             int *vidaMuroTemporal, int *mapaSeleccionado,
                             int *pantallaActual);

void dibujarConfiguracion(int modoJuego, Fantasma fantasmas[],
                          int murosInicialesPacman, int murosInicialesFantasmas,
                          int vidaMuroTemporal, int mapaSeleccionado);

void actualizarEditor(int *filasEditor, int *columnasEditor,
                      int *cursorFila, int *cursorColumna,
                      Posicion *pacmanEditor, PacBola pacbolasEditor[],
                      Fantasma fantasmasEditor[],
                      int tableroEditor[MAX_FILAS][MAX_COLUMNAS],
                      int *indicePacbola, int *indiceFantasma,
                      int *mensajeGuardado, int *pantallaActual);

void dibujarEditor(int filasEditor, int columnasEditor, int cursorFila, int cursorColumna,
                   Posicion pacmanEditor, PacBola pacbolasEditor[],
                   Fantasma fantasmasEditor[],
                   int tableroEditor[MAX_FILAS][MAX_COLUMNAS],
                   int indicePacbola, int indiceFantasma, int mensajeGuardado);

int puedeMover(int filaActual, int columnaActual, int filaNueva, int columnaNueva,
               int filas, int columnas,
               int tablero[MAX_FILAS][MAX_COLUMNAS],
               int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
               int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS]);

int moverPacman(Posicion *pacman, int filas, int columnas,
                int tablero[MAX_FILAS][MAX_COLUMNAS],
                int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                int *accionesPacman);

void colocarMuroPacman(Posicion pacman, int filas, int columnas,
                       int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                       int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                       int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                       int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                       int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                       int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                       int *accionesPacman, int *murosPacman,
                       int vidaMuroTemporal, int orientacionMuro, int ladoMuro);

void controlarFantasmasPVP(Fantasma fantasmas[], int *fantasmaSeleccionado,
                           int filas, int columnas,
                           int tablero[MAX_FILAS][MAX_COLUMNAS],
                           int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int *murosFantasmas, int vidaMuroTemporal,
                           int orientacionMuro, int ladoMuro, int *terminoTurno);

int colocarMuroFantasmasIA(Posicion pacman, Fantasma fantasmas[], int filas, int columnas,
                           int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int *murosFantasmas, int vidaMuroTemporal,
                           int contadorTurnosIA);

void moverFantasmasIA(Fantasma fantasmas[], Posicion pacman, int filas, int columnas,
                      int tablero[MAX_FILAS][MAX_COLUMNAS],
                      int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS]);

int hayLineaVision(Fantasma fantasma, Posicion pacman,
                   int tablero[MAX_FILAS][MAX_COLUMNAS],
                   int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                   int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS]);

void moverUnFantasma(Fantasma *fantasma, Posicion pacman, int filas, int columnas,
                     int tablero[MAX_FILAS][MAX_COLUMNAS],
                     int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                     int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                     int pasos);

void verificarPacBolas(Posicion pacman, PacBola pacbolas[],
                       int *pacbolasComidas, int *accionesPacman,
                       int *puntaje, int *poderComerFantasma);

void verificarColisionConFantasmas(Posicion *pacman, Posicion pacmanInicio,
                                   Fantasma fantasmas[], int *vidas,
                                   int *fantasmasComidos, int *puntaje,
                                   int *poderComerFantasma);

void actualizarMurosTemporales(int filas, int columnas,
                               int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                               int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                               int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                               int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                               int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                               int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                               int *murosPacman, int *murosFantasmas);

void reiniciarPartida(int mapaSeleccionado, int *filas, int *columnas,
                      Posicion *pacman, PacBola pacbolas[], Fantasma fantasmas[],
                      int tablero[MAX_FILAS][MAX_COLUMNAS],
                      int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                      int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                      int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                      int *vidas, int *pacbolasComidas, int *gano, int *perdio,
                      int *turno, int *accionesPacman, int *murosPacman,
                      int *murosFantasmas, int *fantasmasComidos, int *puntaje,
                      int *poderComerFantasma,
                      int murosInicialesPacman, int murosInicialesFantasmas);

void dibujarTablero(int filas, int columnas, int tablero[MAX_FILAS][MAX_COLUMNAS],
                    int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                    int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                    int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                    int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                    int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                    int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                    int inicioX, int inicioY);
void dibujarPacman(Posicion pacman, int inicioX, int inicioY);
void dibujarPacBolas(PacBola pacbolas[], int inicioX, int inicioY);
void dibujarFantasmas(Fantasma fantasmas[], int inicioX, int inicioY);
void dibujarFantasma(int x, int y, Color color);
void dibujarInformacion(int vidas, int pacbolasComidas, int turno, int accionesPacman,
                        int murosPacman, int murosFantasmas, int fantasmasComidos,
                        int puntaje, int modoJuego, int fantasmaSeleccionado,
                        int orientacionMuro, int ladoMuro, int poderComerFantasma);
void mostrarNivel(int pacbolasComidas, int x, int y, Color color);

#endif
