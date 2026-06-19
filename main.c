#include "quoridor.h"

int main(void)
{
    int pantallaActual = PANTALLA_CONFIGURACION;
    int modoJuego = MODO_IA;
    int mapaSeleccionado = 1;

    int filas = 9;
    int columnas = 9;
    int inicioX = 40;
    int inicioY = 40;

    int vidas = 3;
    int pacbolasComidas = 0;
    int fantasmasComidos = 0;
    int puntaje = 0;
    int poderComerFantasma = 0;

    int gano = 0;
    int perdio = 0;
    int turno = TURNO_PACMAN;
    int accionesPacman = 2;

    int murosInicialesPacman = MUROS_INICIALES_PACMAN;
    int murosInicialesFantasmas = MUROS_INICIALES_FANTASMAS;
    int vidaMuroTemporal = VIDA_MURO_TEMPORAL;
    int murosPacman = murosInicialesPacman;
    int murosFantasmas = murosInicialesFantasmas;

    int terminoTurno = 0;
    int fantasmaSeleccionado = 0;
    int orientacionMuro = ORIENTACION_VERTICAL;
    int ladoMuro = 1;
    int contadorTurnosIA = 0;
    int seMovioPacman = 0;
    int poderAntesMovimiento = 0;

    int tablero[MAX_FILAS][MAX_COLUMNAS];
    int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1];
    int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS];
    int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1];
    int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS];
    int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1];
    int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS];

    Posicion pacman;
    Posicion pacmanInicio;
    PacBola pacbolas[CANT_PACBOLAS];
    Fantasma fantasmas[CANT_FANTASMAS];

    int filasEditor = 9;
    int columnasEditor = 9;
    int cursorFila = 0;
    int cursorColumna = 0;
    int indicePacbola = 0;
    int indiceFantasma = 0;
    int mensajeGuardado = 0;
    int tableroEditor[MAX_FILAS][MAX_COLUMNAS];
    Posicion pacmanEditor;
    PacBola pacbolasEditor[CANT_PACBOLAS];
    Fantasma fantasmasEditor[CANT_FANTASMAS];

    cargarMapaPredefinido(mapaSeleccionado, &filas, &columnas, &pacman,
                          pacbolas, fantasmas, tablero, muroVertical, muroHorizontal,
                          turnoVertical, turnoHorizontal, duenoVertical, duenoHorizontal);
    pacmanInicio = pacman;

    cargarMapaPredefinido(1, &filasEditor, &columnasEditor, &pacmanEditor,
                          pacbolasEditor, fantasmasEditor, tableroEditor,
                          muroVertical, muroHorizontal, turnoVertical, turnoHorizontal,
                          duenoVertical, duenoHorizontal);

    InitWindow(900, 650, "Quoridor Pac-Man Mejorado");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_O))
        {
            if(orientacionMuro == ORIENTACION_VERTICAL)
            {
                orientacionMuro = ORIENTACION_HORIZONTAL;
            }
            else
            {
                orientacionMuro = ORIENTACION_VERTICAL;
            }
        }

        if(IsKeyPressed(KEY_L))
        {
            if(ladoMuro == 0)
            {
                ladoMuro = 1;
            }
            else
            {
                ladoMuro = 0;
            }
        }

        if(pantallaActual == PANTALLA_CONFIGURACION)
        {
            actualizarConfiguracion(&modoJuego, fantasmas,
                                    &murosInicialesPacman, &murosInicialesFantasmas,
                                    &vidaMuroTemporal, &mapaSeleccionado,
                                    &pantallaActual);

            if(pantallaActual == PANTALLA_JUEGO)
            {
                reiniciarPartida(mapaSeleccionado, &filas, &columnas, &pacman,
                                 pacbolas, fantasmas, tablero, muroVertical,
                                 muroHorizontal, turnoVertical, turnoHorizontal,
                                 duenoVertical, duenoHorizontal, &vidas,
                                 &pacbolasComidas, &gano, &perdio, &turno,
                                 &accionesPacman, &murosPacman, &murosFantasmas,
                                 &fantasmasComidos, &puntaje, &poderComerFantasma,
                                 murosInicialesPacman, murosInicialesFantasmas);
            }
        }
        else
        {
            if(pantallaActual == PANTALLA_EDITOR)
            {
                actualizarEditor(&filasEditor, &columnasEditor,
                                 &cursorFila, &cursorColumna, &pacmanEditor,
                                 pacbolasEditor, fantasmasEditor, tableroEditor,
                                 &indicePacbola, &indiceFantasma, &mensajeGuardado,
                                 &pantallaActual);
            }
            else
            {
                if(IsKeyPressed(KEY_R))
                {
                    reiniciarPartida(mapaSeleccionado, &filas, &columnas, &pacman,
                                     pacbolas, fantasmas, tablero, muroVertical,
                                     muroHorizontal, turnoVertical, turnoHorizontal,
                                     duenoVertical, duenoHorizontal, &vidas,
                                     &pacbolasComidas, &gano, &perdio, &turno,
                                     &accionesPacman, &murosPacman, &murosFantasmas,
                                     &fantasmasComidos, &puntaje, &poderComerFantasma,
                                     murosInicialesPacman, murosInicialesFantasmas);
                    pacmanInicio = pacman;
                }

                if(gano == 0 && perdio == 0)
                {
                    if(turno == TURNO_PACMAN)
                    {
                        poderAntesMovimiento = poderComerFantasma;
                        seMovioPacman = moverPacman(&pacman, filas, columnas, tablero,
                                                     muroVertical, muroHorizontal,
                                                     &accionesPacman);

                        verificarPacBolas(pacman, pacbolas, &pacbolasComidas,
                                           &accionesPacman, &puntaje,
                                           &poderComerFantasma);

                        verificarColisionConFantasmas(&pacman, pacmanInicio, fantasmas, &vidas,
                                                      &fantasmasComidos, &puntaje,
                                                      &poderComerFantasma);

                        /*
                           Si Pac-Man tenia poder por haber comido una pac-bola y se movio
                           pero no comio ningun fantasma, el poder se consume.
                        */
                        if(seMovioPacman == 1 && poderAntesMovimiento == 1 && poderComerFantasma == 1)
                        {
                            poderComerFantasma = 0;
                        }

                        colocarMuroPacman(pacman, filas, columnas, muroVertical,
                                           muroHorizontal, turnoVertical, turnoHorizontal,
                                           duenoVertical, duenoHorizontal, &accionesPacman,
                                           &murosPacman, vidaMuroTemporal, orientacionMuro, ladoMuro);

                        if(accionesPacman == 0 || IsKeyPressed(KEY_ENTER))
                        {
                            turno = TURNO_FANTASMAS;
                        }
                    }
                    else
                    {
                        if(modoJuego == MODO_IA)
                        {
                            contadorTurnosIA++;

                            if(colocarMuroFantasmasIA(pacman, fantasmas, filas, columnas,
                                                       muroVertical, muroHorizontal,
                                                       turnoVertical, turnoHorizontal,
                                                       duenoVertical, duenoHorizontal,
                                                       &murosFantasmas, vidaMuroTemporal,
                                                       contadorTurnosIA) == 0)
                            {
                                moverFantasmasIA(fantasmas, pacman, filas, columnas,
                                                 tablero, muroVertical, muroHorizontal);
                            }

                            terminoTurno = 1;
                        }
                        else
                        {
                            terminoTurno = 0;

                            controlarFantasmasPVP(fantasmas, &fantasmaSeleccionado,
                                                  filas, columnas, tablero,
                                                  muroVertical, muroHorizontal,
                                                  turnoVertical, turnoHorizontal,
                                                  duenoVertical, duenoHorizontal,
                                                  &murosFantasmas, vidaMuroTemporal,
                                                  orientacionMuro, ladoMuro, &terminoTurno);
                        }

                        verificarColisionConFantasmas(&pacman, fantasmas, &vidas,
                                                      &fantasmasComidos, &puntaje,
                                                      &poderComerFantasma);

                        if(terminoTurno == 1)
                        {
                            actualizarMurosTemporales(filas, columnas, muroVertical,
                                                       muroHorizontal, turnoVertical,
                                                       turnoHorizontal, duenoVertical,
                                                       duenoHorizontal, &murosPacman,
                                                       &murosFantasmas);

                            turno = TURNO_PACMAN;
                            accionesPacman = 2;
                        }
                    }

                    if(pacbolasComidas == CANT_PACBOLAS)
                    {
                        if(gano == 0)
                        {
                            puntaje = puntaje + 100;
                        }

                        gano = 1;
                    }

                    if(vidas <= 0)
                    {
                        perdio = 1;
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if(pantallaActual == PANTALLA_CONFIGURACION)
        {
            dibujarConfiguracion(modoJuego, fantasmas, murosInicialesPacman,
                                 murosInicialesFantasmas, vidaMuroTemporal,
                                 mapaSeleccionado);
        }
        else
        {
            if(pantallaActual == PANTALLA_EDITOR)
            {
                dibujarEditor(filasEditor, columnasEditor, cursorFila, cursorColumna,
                              pacmanEditor, pacbolasEditor, fantasmasEditor,
                              tableroEditor, indicePacbola, indiceFantasma,
                              mensajeGuardado);
            }
            else
            {
                dibujarTablero(filas, columnas, tablero, muroVertical,
                               muroHorizontal, inicioX, inicioY);
                dibujarPacBolas(pacbolas, inicioX, inicioY);
                dibujarFantasmas(fantasmas, inicioX, inicioY);
                dibujarPacman(pacman, inicioX, inicioY);
                dibujarInformacion(vidas, pacbolasComidas, turno, accionesPacman,
                                    murosPacman, murosFantasmas, fantasmasComidos,
                                    puntaje, modoJuego, fantasmaSeleccionado,
                                    orientacionMuro, ladoMuro, poderComerFantasma);

                if(gano == 1)
                {
                    DrawRectangle(0, 0, 900, 650, Fade(GREEN, 0.3f));
                    DrawText("GANO PAC-MAN", 230, 230, 50, DARKGREEN);
                    DrawText("Presiona R para reiniciar", 250, 300, 20, DARKGREEN);
                    DrawText(TextFormat("Puntaje final: %d", puntaje), 250, 330, 20, DARKGREEN);
                    mostrarNivel(pacbolasComidas, 250, 360, DARKGREEN);
                }

                if(perdio == 1)
                {
                    DrawRectangle(0, 0, 900, 650, Fade(RED, 0.3f));
                    DrawText("GANARON LOS FANTASMAS", 120, 230, 45, MAROON);
                    DrawText("Presiona R para reiniciar", 250, 300, 20, MAROON);
                    DrawText(TextFormat("Puntaje final: %d", puntaje), 250, 330, 20, MAROON);
                    mostrarNivel(pacbolasComidas, 250, 360, MAROON);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
