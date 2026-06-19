#include "quoridor.h"

void limpiarTodo(int tablero[MAX_FILAS][MAX_COLUMNAS],
                 int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                 int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                 int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                 int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                 int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                 int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS])
{
    int i;
    int j;

    for(i = 0; i < MAX_FILAS; i++)
    {
        for(j = 0; j < MAX_COLUMNAS; j++)
        {
            tablero[i][j] = LIBRE;
        }
    }

    for(i = 0; i < MAX_FILAS; i++)
    {
        for(j = 0; j < MAX_COLUMNAS + 1; j++)
        {
            muroVertical[i][j] = 0;
            turnoVertical[i][j] = 0;
            duenoVertical[i][j] = SIN_DUENO;
        }
    }

    for(i = 0; i < MAX_FILAS + 1; i++)
    {
        for(j = 0; j < MAX_COLUMNAS; j++)
        {
            muroHorizontal[i][j] = 0;
            turnoHorizontal[i][j] = 0;
            duenoHorizontal[i][j] = SIN_DUENO;
        }
    }
}

void inicializarPacBolas(PacBola pacbolas[])
{
    pacbolas[0].pos.fila = 0;
    pacbolas[0].pos.columna = 0;
    pacbolas[0].activa = 1;

    pacbolas[1].pos.fila = 0;
    pacbolas[1].pos.columna = 8;
    pacbolas[1].activa = 1;

    pacbolas[2].pos.fila = 8;
    pacbolas[2].pos.columna = 0;
    pacbolas[2].activa = 1;

    pacbolas[3].pos.fila = 8;
    pacbolas[3].pos.columna = 8;
    pacbolas[3].activa = 1;
}

void inicializarFantasmas(Fantasma fantasmas[])
{
    fantasmas[0].pos.fila = 0;
    fantasmas[0].pos.columna = 4;
    fantasmas[0].inicio = fantasmas[0].pos;
    fantasmas[0].activo = 1;
    fantasmas[0].habilitado = 1;
    fantasmas[0].dificultad = 2;
    fantasmas[0].color = RED;

    fantasmas[1].pos.fila = 4;
    fantasmas[1].pos.columna = 0;
    fantasmas[1].inicio = fantasmas[1].pos;
    fantasmas[1].activo = 1;
    fantasmas[1].habilitado = 1;
    fantasmas[1].dificultad = 2;
    fantasmas[1].color = SKYBLUE;

    fantasmas[2].pos.fila = 4;
    fantasmas[2].pos.columna = 8;
    fantasmas[2].inicio = fantasmas[2].pos;
    fantasmas[2].activo = 1;
    fantasmas[2].habilitado = 1;
    fantasmas[2].dificultad = 2;
    fantasmas[2].color = PINK;

    fantasmas[3].pos.fila = 8;
    fantasmas[3].pos.columna = 4;
    fantasmas[3].inicio = fantasmas[3].pos;
    fantasmas[3].activo = 1;
    fantasmas[3].habilitado = 1;
    fantasmas[3].dificultad = 2;
    fantasmas[3].color = ORANGE;
}

void cargarMapaPredefinido(int mapa, int *filas, int *columnas, Posicion *pacman,
                           PacBola pacbolas[], Fantasma fantasmas[],
                           int tablero[MAX_FILAS][MAX_COLUMNAS],
                           int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS])
{
    limpiarTodo(tablero, muroVertical, muroHorizontal, turnoVertical,
                turnoHorizontal, duenoVertical, duenoHorizontal);
    inicializarPacBolas(pacbolas);
    inicializarFantasmas(fantasmas);

    *filas = 9;
    *columnas = 9;
    pacman->fila = 4;
    pacman->columna = 4;

    if(mapa == 1)
    {
        tablero[2][2] = MURO_PERMANENTE;
        tablero[2][3] = MURO_PERMANENTE;
        tablero[2][4] = MURO_PERMANENTE;
        tablero[6][4] = MURO_PERMANENTE;
        tablero[6][5] = MURO_PERMANENTE;
        tablero[6][6] = MURO_PERMANENTE;
    }

    if(mapa == 2)
    {
        *filas = 10;
        *columnas = 10;
        pacman->fila = 5;
        pacman->columna = 5;

        tablero[1][5] = MURO_PERMANENTE;
        tablero[2][5] = MURO_PERMANENTE;
        tablero[3][5] = MURO_PERMANENTE;
        tablero[6][5] = MURO_PERMANENTE;
        tablero[7][5] = MURO_PERMANENTE;
        tablero[8][5] = MURO_PERMANENTE;

        pacbolas[0].pos.fila = 1;
        pacbolas[0].pos.columna = 1;
        pacbolas[1].pos.fila = 1;
        pacbolas[1].pos.columna = 8;
        pacbolas[2].pos.fila = 8;
        pacbolas[2].pos.columna = 1;
        pacbolas[3].pos.fila = 8;
        pacbolas[3].pos.columna = 8;
    }

    if(mapa == 3)
    {
        *filas = 8;
        *columnas = 8;
        pacman->fila = 3;
        pacman->columna = 3;

        tablero[2][1] = MURO_PERMANENTE;
        tablero[2][2] = MURO_PERMANENTE;
        tablero[2][5] = MURO_PERMANENTE;
        tablero[2][6] = MURO_PERMANENTE;
        tablero[5][1] = MURO_PERMANENTE;
        tablero[5][2] = MURO_PERMANENTE;
        tablero[5][5] = MURO_PERMANENTE;
        tablero[5][6] = MURO_PERMANENTE;

        pacbolas[0].pos.fila = 0;
        pacbolas[0].pos.columna = 0;
        pacbolas[1].pos.fila = 0;
        pacbolas[1].pos.columna = 7;
        pacbolas[2].pos.fila = 7;
        pacbolas[2].pos.columna = 0;
        pacbolas[3].pos.fila = 7;
        pacbolas[3].pos.columna = 7;
    }
}

int guardarMapaArchivo(char nombre[], int filas, int columnas, Posicion pacman,
                       PacBola pacbolas[], Fantasma fantasmas[],
                       int tablero[MAX_FILAS][MAX_COLUMNAS])
{
    FILE *archivo;
    int i;
    int j;

    archivo = fopen(nombre, "w");

    if(archivo == NULL)
    {
        return 0;
    }

    fprintf(archivo, "%d %d\n", filas, columnas);
    fprintf(archivo, "%d %d\n", pacman.fila, pacman.columna);

    for(i = 0; i < CANT_FANTASMAS; i++)
    {
        fprintf(archivo, "%d %d\n", fantasmas[i].inicio.fila, fantasmas[i].inicio.columna);
    }

    for(i = 0; i < CANT_PACBOLAS; i++)
    {
        fprintf(archivo, "%d %d\n", pacbolas[i].pos.fila, pacbolas[i].pos.columna);
    }

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            fprintf(archivo, "%d ", tablero[i][j]);
        }

        fprintf(archivo, "\n");
    }

    fclose(archivo);

    return 1;
}

int cargarMapaArchivo(char nombre[], int *filas, int *columnas, Posicion *pacman,
                      PacBola pacbolas[], Fantasma fantasmas[],
                      int tablero[MAX_FILAS][MAX_COLUMNAS],
                      int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                      int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                      int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS])
{
    FILE *archivo;
    int i;
    int j;

    archivo = fopen(nombre, "r");

    if(archivo == NULL)
    {
        return 0;
    }

    limpiarTodo(tablero, muroVertical, muroHorizontal, turnoVertical,
                turnoHorizontal, duenoVertical, duenoHorizontal);
    inicializarFantasmas(fantasmas);

    fscanf(archivo, "%d %d", filas, columnas);
    fscanf(archivo, "%d %d", &pacman->fila, &pacman->columna);

    for(i = 0; i < CANT_FANTASMAS; i++)
    {
        fscanf(archivo, "%d %d", &fantasmas[i].inicio.fila, &fantasmas[i].inicio.columna);
        fantasmas[i].pos = fantasmas[i].inicio;
        fantasmas[i].activo = 1;
    }

    for(i = 0; i < CANT_PACBOLAS; i++)
    {
        fscanf(archivo, "%d %d", &pacbolas[i].pos.fila, &pacbolas[i].pos.columna);
        pacbolas[i].activa = 1;
    }

    for(i = 0; i < *filas; i++)
    {
        for(j = 0; j < *columnas; j++)
        {
            fscanf(archivo, "%d", &tablero[i][j]);
        }
    }

    fclose(archivo);

    return 1;
}

void actualizarConfiguracion(int *modoJuego, Fantasma fantasmas[],
                             int *murosInicialesPacman, int *murosInicialesFantasmas,
                             int *vidaMuroTemporal, int *mapaSeleccionado,
                             int *pantallaActual)
{
    if(IsKeyPressed(KEY_ONE))
    {
        *modoJuego = MODO_IA;
    }

    if(IsKeyPressed(KEY_TWO))
    {
        *modoJuego = MODO_PVP;
    }

    if(IsKeyPressed(KEY_F1))
    {
        fantasmas[0].habilitado = 1 - fantasmas[0].habilitado;
        fantasmas[0].activo = fantasmas[0].habilitado;
    }

    if(IsKeyPressed(KEY_F2))
    {
        fantasmas[1].habilitado = 1 - fantasmas[1].habilitado;
        fantasmas[1].activo = fantasmas[1].habilitado;
    }

    if(IsKeyPressed(KEY_F3))
    {
        fantasmas[2].habilitado = 1 - fantasmas[2].habilitado;
        fantasmas[2].activo = fantasmas[2].habilitado;
    }

    if(IsKeyPressed(KEY_F4))
    {
        fantasmas[3].habilitado = 1 - fantasmas[3].habilitado;
        fantasmas[3].activo = fantasmas[3].habilitado;
    }

    if(IsKeyPressed(KEY_Q))
    {
        fantasmas[0].dificultad++;
        if(fantasmas[0].dificultad > 3) fantasmas[0].dificultad = 1;
    }

    if(IsKeyPressed(KEY_W))
    {
        fantasmas[1].dificultad++;
        if(fantasmas[1].dificultad > 3) fantasmas[1].dificultad = 1;
    }

    if(IsKeyPressed(KEY_E))
    {
        fantasmas[2].dificultad++;
        if(fantasmas[2].dificultad > 3) fantasmas[2].dificultad = 1;
    }

    if(IsKeyPressed(KEY_T))
    {
        fantasmas[3].dificultad++;
        if(fantasmas[3].dificultad > 3) fantasmas[3].dificultad = 1;
    }

    if(IsKeyPressed(KEY_A)) (*murosInicialesPacman)++;
    if(IsKeyPressed(KEY_Z) && *murosInicialesPacman > 0) (*murosInicialesPacman)--;
    if(IsKeyPressed(KEY_S)) (*murosInicialesFantasmas)++;
    if(IsKeyPressed(KEY_X) && *murosInicialesFantasmas > 0) (*murosInicialesFantasmas)--;
    if(IsKeyPressed(KEY_D)) (*vidaMuroTemporal)++;
    if(IsKeyPressed(KEY_C) && *vidaMuroTemporal > 1) (*vidaMuroTemporal)--;

    if(IsKeyPressed(KEY_M))
    {
        (*mapaSeleccionado)++;
        if(*mapaSeleccionado > 4) *mapaSeleccionado = 1;
    }

    if(IsKeyPressed(KEY_BACKSPACE))
    {
        *pantallaActual = PANTALLA_EDITOR;
    }

    if(IsKeyPressed(KEY_ENTER))
    {
        *pantallaActual = PANTALLA_JUEGO;
    }
}

void dibujarConfiguracion(int modoJuego, Fantasma fantasmas[],
                          int murosInicialesPacman, int murosInicialesFantasmas,
                          int vidaMuroTemporal, int mapaSeleccionado)
{
    DrawText("CONFIGURACION DE PARTIDA", 160, 30, 30, BLACK);

    if(modoJuego == MODO_IA)
    {
        DrawText("Modo: IA vs Player", 70, 80, 22, BLUE);
    }
    else
    {
        DrawText("Modo: Player vs Player", 70, 80, 22, BLUE);
    }

    DrawText("1: IA vs Player    2: Player vs Player", 70, 115, 20, DARKGRAY);
    DrawText("Fantasmas habilitados y dificultad:", 70, 165, 22, DARKBLUE);
    DrawText(TextFormat("F1 Blinky: %s   Q dificultad: %d", fantasmas[0].habilitado == 1 ? "ON" : "OFF", fantasmas[0].dificultad), 70, 200, 20, RED);
    DrawText(TextFormat("F2 Inky:   %s   W dificultad: %d", fantasmas[1].habilitado == 1 ? "ON" : "OFF", fantasmas[1].dificultad), 70, 230, 20, SKYBLUE);
    DrawText(TextFormat("F3 Pinky:  %s   E dificultad: %d", fantasmas[2].habilitado == 1 ? "ON" : "OFF", fantasmas[2].dificultad), 70, 260, 20, PINK);
    DrawText(TextFormat("F4 Clyde:  %s   T dificultad: %d", fantasmas[3].habilitado == 1 ? "ON" : "OFF", fantasmas[3].dificultad), 70, 290, 20, ORANGE);

    DrawText(TextFormat("A/Z Muros Pac-Man: %d", murosInicialesPacman), 70, 350, 20, BLACK);
    DrawText(TextFormat("S/X Muros Fantasmas: %d", murosInicialesFantasmas), 70, 380, 20, BLACK);
    DrawText(TextFormat("D/C Vida de muros: %d turnos", vidaMuroTemporal), 70, 410, 20, BLACK);

    if(mapaSeleccionado == 4)
    {
        DrawText("M Mapa: archivo mapa_editor.txt", 70, 440, 20, BLACK);
    }
    else
    {
        DrawText(TextFormat("M Mapa predefinido: %d", mapaSeleccionado), 70, 440, 20, BLACK);
    }

    DrawText("BACKSPACE: editor de mapas", 70, 500, 20, DARKPURPLE);
    DrawText("ENTER: comenzar partida", 70, 535, 24, DARKGREEN);
    DrawText("ESC: salir", 70, 575, 20, DARKGRAY);
}

void actualizarEditor(int *filasEditor, int *columnasEditor,
                      int *cursorFila, int *cursorColumna,
                      Posicion *pacmanEditor, PacBola pacbolasEditor[],
                      Fantasma fantasmasEditor[],
                      int tableroEditor[MAX_FILAS][MAX_COLUMNAS],
                      int *indicePacbola, int *indiceFantasma,
                      int *mensajeGuardado, int *pantallaActual)
{
    if(IsKeyPressed(KEY_UP) && *cursorFila > 0) (*cursorFila)--;
    if(IsKeyPressed(KEY_DOWN) && *cursorFila < *filasEditor - 1) (*cursorFila)++;
    if(IsKeyPressed(KEY_LEFT) && *cursorColumna > 0) (*cursorColumna)--;
    if(IsKeyPressed(KEY_RIGHT) && *cursorColumna < *columnasEditor - 1) (*cursorColumna)++;

    if(IsKeyPressed(KEY_U) && *filasEditor < MAX_FILAS) (*filasEditor)++;
    if(IsKeyPressed(KEY_J) && *filasEditor > 5) (*filasEditor)--;
    if(IsKeyPressed(KEY_I) && *columnasEditor < MAX_COLUMNAS) (*columnasEditor)++;
    if(IsKeyPressed(KEY_K) && *columnasEditor > 5) (*columnasEditor)--;

    if(IsKeyPressed(KEY_M))
    {
        if(tableroEditor[*cursorFila][*cursorColumna] == MURO_PERMANENTE)
        {
            tableroEditor[*cursorFila][*cursorColumna] = LIBRE;
        }
        else
        {
            tableroEditor[*cursorFila][*cursorColumna] = MURO_PERMANENTE;
        }
    }

    if(IsKeyPressed(KEY_P))
    {
        pacmanEditor->fila = *cursorFila;
        pacmanEditor->columna = *cursorColumna;
    }

    if(IsKeyPressed(KEY_B))
    {
        pacbolasEditor[*indicePacbola].pos.fila = *cursorFila;
        pacbolasEditor[*indicePacbola].pos.columna = *cursorColumna;
        pacbolasEditor[*indicePacbola].activa = 1;
        (*indicePacbola)++;
        if(*indicePacbola >= CANT_PACBOLAS) *indicePacbola = 0;
    }

    if(IsKeyPressed(KEY_G))
    {
        fantasmasEditor[*indiceFantasma].pos.fila = *cursorFila;
        fantasmasEditor[*indiceFantasma].pos.columna = *cursorColumna;
        fantasmasEditor[*indiceFantasma].inicio = fantasmasEditor[*indiceFantasma].pos;
        (*indiceFantasma)++;
        if(*indiceFantasma >= CANT_FANTASMAS) *indiceFantasma = 0;
    }

    if(IsKeyPressed(KEY_S))
    {
        if(guardarMapaArchivo("mapa_editor.txt", *filasEditor, *columnasEditor,
                              *pacmanEditor, pacbolasEditor, fantasmasEditor,
                              tableroEditor) == 1)
        {
            *mensajeGuardado = 1;
        }
        else
        {
            *mensajeGuardado = 2;
        }
    }

    if(IsKeyPressed(KEY_ENTER))
    {
        *pantallaActual = PANTALLA_CONFIGURACION;
    }
}

void dibujarEditor(int filasEditor, int columnasEditor, int cursorFila, int cursorColumna,
                   Posicion pacmanEditor, PacBola pacbolasEditor[],
                   Fantasma fantasmasEditor[],
                   int tableroEditor[MAX_FILAS][MAX_COLUMNAS],
                   int indicePacbola, int indiceFantasma, int mensajeGuardado)
{
    int i;
    int j;
    int x;
    int y;
    int inicioX = 40;
    int inicioY = 40;

    DrawText("EDITOR DE MAPAS", 560, 40, 24, BLACK);
    DrawText("Flechas: mover cursor", 560, 90, 18, DARKGRAY);
    DrawText("U/J: filas +/-", 560, 120, 18, DARKGRAY);
    DrawText("I/K: columnas +/-", 560, 150, 18, DARKGRAY);
    DrawText("M: muro permanente", 560, 180, 18, DARKGRAY);
    DrawText("P: ubicar Pac-Man", 560, 210, 18, DARKGRAY);
    DrawText("B: ubicar pac-bola", 560, 240, 18, DARKGRAY);
    DrawText("G: ubicar fantasma", 560, 270, 18, DARKGRAY);
    DrawText("S: guardar archivo", 560, 300, 18, DARKGRAY);
    DrawText("ENTER: volver config", 560, 330, 18, DARKGREEN);
    DrawText(TextFormat("Tamano: %dx%d", filasEditor, columnasEditor), 560, 380, 18, BLACK);
    DrawText(TextFormat("Prox pac-bola: %d", indicePacbola), 560, 410, 18, BLACK);
    DrawText(TextFormat("Prox fantasma: %d", indiceFantasma), 560, 440, 18, BLACK);

    if(mensajeGuardado == 1) DrawText("Mapa guardado", 560, 490, 18, DARKGREEN);
    if(mensajeGuardado == 2) DrawText("Error al guardar", 560, 490, 18, RED);

    for(i = 0; i < filasEditor; i++)
    {
        for(j = 0; j < columnasEditor; j++)
        {
            x = inicioX + j * TAM_CASILLA;
            y = inicioY + i * TAM_CASILLA;

            if(tableroEditor[i][j] == MURO_PERMANENTE)
            {
                DrawRectangle(x, y, TAM_CASILLA, TAM_CASILLA, DARKBLUE);
            }

            DrawRectangleLines(x, y, TAM_CASILLA, TAM_CASILLA, BLACK);
        }
    }

    for(i = 0; i < CANT_PACBOLAS; i++)
    {
        DrawCircle(inicioX + pacbolasEditor[i].pos.columna * TAM_CASILLA + TAM_CASILLA / 2,
                   inicioY + pacbolasEditor[i].pos.fila * TAM_CASILLA + TAM_CASILLA / 2,
                   7, ORANGE);
    }

    for(i = 0; i < CANT_FANTASMAS; i++)
    {
        dibujarFantasma(inicioX + fantasmasEditor[i].pos.columna * TAM_CASILLA + TAM_CASILLA / 2,
                        inicioY + fantasmasEditor[i].pos.fila * TAM_CASILLA + TAM_CASILLA / 2,
                        fantasmasEditor[i].color);
    }

    dibujarPacman(pacmanEditor, inicioX, inicioY);
    DrawRectangleLines(inicioX + cursorColumna * TAM_CASILLA,
                       inicioY + cursorFila * TAM_CASILLA,
                       TAM_CASILLA, TAM_CASILLA, RED);
}

int puedeMover(int filaActual, int columnaActual, int filaNueva, int columnaNueva,
               int filas, int columnas,
               int tablero[MAX_FILAS][MAX_COLUMNAS],
               int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
               int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS])
{
    if(filaNueva < 0 || filaNueva >= filas || columnaNueva < 0 || columnaNueva >= columnas)
    {
        return 0;
    }

    if(tablero[filaNueva][columnaNueva] == MURO_PERMANENTE)
    {
        return 0;
    }

    if(filaNueva == filaActual - 1 && columnaNueva == columnaActual)
    {
        if(muroHorizontal[filaActual][columnaActual] == 1) return 0;
    }

    if(filaNueva == filaActual + 1 && columnaNueva == columnaActual)
    {
        if(muroHorizontal[filaActual + 1][columnaActual] == 1) return 0;
    }

    if(filaNueva == filaActual && columnaNueva == columnaActual - 1)
    {
        if(muroVertical[filaActual][columnaActual] == 1) return 0;
    }

    if(filaNueva == filaActual && columnaNueva == columnaActual + 1)
    {
        if(muroVertical[filaActual][columnaActual + 1] == 1) return 0;
    }

    return 1;
}

int moverPacman(Posicion *pacman, int filas, int columnas,
                int tablero[MAX_FILAS][MAX_COLUMNAS],
                int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                int *accionesPacman)
{
    int nuevaFila = pacman->fila;
    int nuevaColumna = pacman->columna;
    int seMovio = 0;

    if(IsKeyPressed(KEY_UP))
    {
        nuevaFila = pacman->fila - 1;
        seMovio = 1;
    }

    if(IsKeyPressed(KEY_DOWN))
    {
        nuevaFila = pacman->fila + 1;
        seMovio = 1;
    }

    if(IsKeyPressed(KEY_LEFT))
    {
        nuevaColumna = pacman->columna - 1;
        seMovio = 1;
    }

    if(IsKeyPressed(KEY_RIGHT))
    {
        nuevaColumna = pacman->columna + 1;
        seMovio = 1;
    }

    if(seMovio == 1)
    {
        if(puedeMover(pacman->fila, pacman->columna, nuevaFila, nuevaColumna,
                      filas, columnas, tablero, muroVertical, muroHorizontal) == 1)
        {
            pacman->fila = nuevaFila;
            pacman->columna = nuevaColumna;
            (*accionesPacman)--;
            return 1;
        }
    }

    return 0;
}


void colocarMuroPacman(Posicion pacman, int filas, int columnas,
                       int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                       int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                       int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                       int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                       int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                       int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                       int *accionesPacman, int *murosPacman,
                       int vidaMuroTemporal, int orientacionMuro, int ladoMuro)
{
    int fila;
    int columna;

    if(IsKeyPressed(KEY_M))
    {
        if(*accionesPacman > 0 && *murosPacman > 0)
        {
            if(orientacionMuro == ORIENTACION_VERTICAL)
            {
                fila = pacman.fila;

                if(ladoMuro == 0)
                {
                    columna = pacman.columna;      /* izquierda */
                }
                else
                {
                    columna = pacman.columna + 1;  /* derecha */
                }

                if(columna > 0 && columna < columnas && muroVertical[fila][columna] == 0)
                {
                    muroVertical[fila][columna] = 1;
                    turnoVertical[fila][columna] = vidaMuroTemporal;
                    duenoVertical[fila][columna] = DUENO_PACMAN;
                    (*accionesPacman)--;
                    (*murosPacman)--;
                }
            }
            else
            {
                columna = pacman.columna;

                if(ladoMuro == 0)
                {
                    fila = pacman.fila;      /* arriba */
                }
                else
                {
                    fila = pacman.fila + 1;  /* abajo */
                }

                if(fila > 0 && fila < filas && muroHorizontal[fila][columna] == 0)
                {
                    muroHorizontal[fila][columna] = 1;
                    turnoHorizontal[fila][columna] = vidaMuroTemporal;
                    duenoHorizontal[fila][columna] = DUENO_PACMAN;
                    (*accionesPacman)--;
                    (*murosPacman)--;
                }
            }
        }
    }
}


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
                           int orientacionMuro, int ladoMuro, int *terminoTurno)
{
    int idx;
    int nuevaFila;
    int nuevaColumna;
    int filaMuro;
    int columnaMuro;
    int movio = 0;

    if(IsKeyPressed(KEY_TAB))
    {
        (*fantasmaSeleccionado)++;
        if(*fantasmaSeleccionado >= CANT_FANTASMAS)
        {
            *fantasmaSeleccionado = 0;
        }
    }

    idx = *fantasmaSeleccionado;

    if(fantasmas[idx].habilitado == 1 && fantasmas[idx].activo == 1)
    {
        nuevaFila = fantasmas[idx].pos.fila;
        nuevaColumna = fantasmas[idx].pos.columna;

        if(IsKeyPressed(KEY_W))
        {
            nuevaFila--;
            movio = 1;
        }

        if(IsKeyPressed(KEY_S))
        {
            nuevaFila++;
            movio = 1;
        }

        if(IsKeyPressed(KEY_A))
        {
            nuevaColumna--;
            movio = 1;
        }

        if(IsKeyPressed(KEY_D))
        {
            nuevaColumna++;
            movio = 1;
        }

        if(movio == 1)
        {
            if(puedeMover(fantasmas[idx].pos.fila, fantasmas[idx].pos.columna,
                          nuevaFila, nuevaColumna, filas, columnas, tablero,
                          muroVertical, muroHorizontal) == 1)
            {
                fantasmas[idx].pos.fila = nuevaFila;
                fantasmas[idx].pos.columna = nuevaColumna;
                *terminoTurno = 1;
            }
        }

        if(IsKeyPressed(KEY_N) && *murosFantasmas > 0)
        {
            if(orientacionMuro == ORIENTACION_VERTICAL)
            {
                filaMuro = fantasmas[idx].pos.fila;

                if(ladoMuro == 0)
                {
                    columnaMuro = fantasmas[idx].pos.columna;      /* izquierda */
                }
                else
                {
                    columnaMuro = fantasmas[idx].pos.columna + 1;  /* derecha */
                }

                if(columnaMuro > 0 && columnaMuro < columnas && muroVertical[filaMuro][columnaMuro] == 0)
                {
                    muroVertical[filaMuro][columnaMuro] = 1;
                    turnoVertical[filaMuro][columnaMuro] = vidaMuroTemporal;
                    duenoVertical[filaMuro][columnaMuro] = DUENO_FANTASMAS;
                    (*murosFantasmas)--;
                    *terminoTurno = 1;
                }
            }
            else
            {
                columnaMuro = fantasmas[idx].pos.columna;

                if(ladoMuro == 0)
                {
                    filaMuro = fantasmas[idx].pos.fila;      /* arriba */
                }
                else
                {
                    filaMuro = fantasmas[idx].pos.fila + 1;  /* abajo */
                }

                if(filaMuro > 0 && filaMuro < filas && muroHorizontal[filaMuro][columnaMuro] == 0)
                {
                    muroHorizontal[filaMuro][columnaMuro] = 1;
                    turnoHorizontal[filaMuro][columnaMuro] = vidaMuroTemporal;
                    duenoHorizontal[filaMuro][columnaMuro] = DUENO_FANTASMAS;
                    (*murosFantasmas)--;
                    *terminoTurno = 1;
                }
            }
        }
    }
}


int colocarMuroFantasmasIA(Posicion pacman, Fantasma fantasmas[], int filas, int columnas,
                           int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                           int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                           int *murosFantasmas, int vidaMuroTemporal,
                           int contadorTurnosIA)
{
    int i;
    int algunDificil = 0;
    int ve = 0;
    int filaMuro;
    int columnaMuro;

    if(*murosFantasmas <= 0)
    {
        return 0;
    }

    for(i = 0; i < CANT_FANTASMAS; i++)
    {
        if(fantasmas[i].habilitado == 1 &&
           fantasmas[i].activo == 1 &&
           fantasmas[i].dificultad == 3)
        {
            algunDificil = 1;

            if(fantasmas[i].pos.fila == pacman.fila ||
               fantasmas[i].pos.columna == pacman.columna)
            {
                ve = 1;
            }
        }
    }

    /*
     * La IA coloca muros solo en dificultad 3.
     * Ademas no usa siempre el mismo lado:
     * 0 derecha, 1 izquierda, 2 abajo, 3 arriba.
     */
    if(algunDificil == 1 && ve == 1 && contadorTurnosIA % 3 == 0)
    {
        if(contadorTurnosIA % 4 == 0)
        {
            filaMuro = pacman.fila;
            columnaMuro = pacman.columna + 1;

            if(columnaMuro > 0 && columnaMuro < columnas && muroVertical[filaMuro][columnaMuro] == 0)
            {
                muroVertical[filaMuro][columnaMuro] = 1;
                turnoVertical[filaMuro][columnaMuro] = vidaMuroTemporal;
                duenoVertical[filaMuro][columnaMuro] = DUENO_FANTASMAS;
                (*murosFantasmas)--;
                return 1;
            }
        }

        if(contadorTurnosIA % 4 == 1)
        {
            filaMuro = pacman.fila;
            columnaMuro = pacman.columna;

            if(columnaMuro > 0 && columnaMuro < columnas && muroVertical[filaMuro][columnaMuro] == 0)
            {
                muroVertical[filaMuro][columnaMuro] = 1;
                turnoVertical[filaMuro][columnaMuro] = vidaMuroTemporal;
                duenoVertical[filaMuro][columnaMuro] = DUENO_FANTASMAS;
                (*murosFantasmas)--;
                return 1;
            }
        }

        if(contadorTurnosIA % 4 == 2)
        {
            filaMuro = pacman.fila + 1;
            columnaMuro = pacman.columna;

            if(filaMuro > 0 && filaMuro < filas && muroHorizontal[filaMuro][columnaMuro] == 0)
            {
                muroHorizontal[filaMuro][columnaMuro] = 1;
                turnoHorizontal[filaMuro][columnaMuro] = vidaMuroTemporal;
                duenoHorizontal[filaMuro][columnaMuro] = DUENO_FANTASMAS;
                (*murosFantasmas)--;
                return 1;
            }
        }

        if(contadorTurnosIA % 4 == 3)
        {
            filaMuro = pacman.fila;
            columnaMuro = pacman.columna;

            if(filaMuro > 0 && filaMuro < filas && muroHorizontal[filaMuro][columnaMuro] == 0)
            {
                muroHorizontal[filaMuro][columnaMuro] = 1;
                turnoHorizontal[filaMuro][columnaMuro] = vidaMuroTemporal;
                duenoHorizontal[filaMuro][columnaMuro] = DUENO_FANTASMAS;
                (*murosFantasmas)--;
                return 1;
            }
        }
    }

    return 0;
}

void moverFantasmasIA(Fantasma fantasmas[], Posicion pacman, int filas, int columnas,
                      int tablero[MAX_FILAS][MAX_COLUMNAS],
                      int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                      int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS])
{
    int i;
    int pasos;

    for(i = 0; i < CANT_FANTASMAS; i++)
    {
        if(fantasmas[i].habilitado == 1 && fantasmas[i].activo == 1)
        {
            pasos = 1;

            if(fantasmas[i].dificultad >= 2)
            {
                if(hayLineaVision(fantasmas[i], pacman, tablero, muroVertical, muroHorizontal) == 1)
                {
                    pasos = 2;
                }
            }

            moverUnFantasma(&fantasmas[i], pacman, filas, columnas, tablero,
                            muroVertical, muroHorizontal, pasos);
        }
    }
}

int hayLineaVision(Fantasma fantasma, Posicion pacman,
                   int tablero[MAX_FILAS][MAX_COLUMNAS],
                   int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                   int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS])
{
    int f;
    int c;
    int paso;
    int filaActual;
    int columnaActual;
    int filaNueva;
    int columnaNueva;

    if(fantasma.pos.fila == pacman.fila)
    {
        filaActual = fantasma.pos.fila;
        columnaActual = fantasma.pos.columna;

        if(pacman.columna > fantasma.pos.columna) paso = 1;
        else paso = -1;

        c = columnaActual + paso;

        while(c != pacman.columna + paso)
        {
            filaNueva = filaActual;
            columnaNueva = c;

            if(puedeMover(filaActual, columnaActual, filaNueva, columnaNueva,
                          MAX_FILAS, MAX_COLUMNAS, tablero, muroVertical, muroHorizontal) == 0)
            {
                return 0;
            }

            columnaActual = columnaNueva;
            c = c + paso;
        }

        return 1;
    }

    if(fantasma.pos.columna == pacman.columna)
    {
        filaActual = fantasma.pos.fila;
        columnaActual = fantasma.pos.columna;

        if(pacman.fila > fantasma.pos.fila) paso = 1;
        else paso = -1;

        f = filaActual + paso;

        while(f != pacman.fila + paso)
        {
            filaNueva = f;
            columnaNueva = columnaActual;

            if(puedeMover(filaActual, columnaActual, filaNueva, columnaNueva,
                          MAX_FILAS, MAX_COLUMNAS, tablero, muroVertical, muroHorizontal) == 0)
            {
                return 0;
            }

            filaActual = filaNueva;
            f = f + paso;
        }

        return 1;
    }

    return 0;
}

void moverUnFantasma(Fantasma *fantasma, Posicion pacman, int filas, int columnas,
                     int tablero[MAX_FILAS][MAX_COLUMNAS],
                     int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                     int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                     int pasos)
{
    int paso;
    int nuevaFila;
    int nuevaColumna;

    for(paso = 0; paso < pasos; paso++)
    {
        nuevaFila = fantasma->pos.fila;
        nuevaColumna = fantasma->pos.columna;

        if(fantasma->pos.fila < pacman.fila)
        {
            nuevaFila++;
        }
        else
        {
            if(fantasma->pos.fila > pacman.fila)
            {
                nuevaFila--;
            }
            else
            {
                if(fantasma->pos.columna < pacman.columna)
                {
                    nuevaColumna++;
                }
                else
                {
                    if(fantasma->pos.columna > pacman.columna)
                    {
                        nuevaColumna--;
                    }
                }
            }
        }

        if(puedeMover(fantasma->pos.fila, fantasma->pos.columna, nuevaFila,
                      nuevaColumna, filas, columnas, tablero, muroVertical,
                      muroHorizontal) == 1)
        {
            fantasma->pos.fila = nuevaFila;
            fantasma->pos.columna = nuevaColumna;
        }
    }
}

void verificarPacBolas(Posicion pacman, PacBola pacbolas[],
                       int *pacbolasComidas, int *accionesPacman,
                       int *puntaje, int *poderComerFantasma)
{
    int i;

    for(i = 0; i < CANT_PACBOLAS; i++)
    {
        if(pacbolas[i].activa == 1)
        {
            if(pacman.fila == pacbolas[i].pos.fila && pacman.columna == pacbolas[i].pos.columna)
            {
                pacbolas[i].activa = 0;
                (*pacbolasComidas)++;
                (*accionesPacman)++;
                (*puntaje) = (*puntaje) + 10;
                *poderComerFantasma = 1;
            }
        }
    }
}

void verificarColisionConFantasmas(Posicion *pacman, Posicion pacmanInicio,
                                   Fantasma fantasmas[], int *vidas,
                                   int *fantasmasComidos, int *puntaje,
                                   int *poderComerFantasma)
{
    int i;
    int j;

    for(i = 0; i < CANT_FANTASMAS; i++)
    {
        if(fantasmas[i].habilitado == 1 && fantasmas[i].activo == 1)
        {
            if(pacman->fila == fantasmas[i].pos.fila && pacman->columna == fantasmas[i].pos.columna)
            {
                if(*poderComerFantasma == 1)
                {
                    fantasmas[i].activo = 0;
                    (*fantasmasComidos)++;
                    (*puntaje) = (*puntaje) + 50;
                    *poderComerFantasma = 0;
                }
                else
                {
                    (*vidas)--;
                    *poderComerFantasma = 0;

                    pacman->fila = pacmanInicio.fila;
                    pacman->columna = pacmanInicio.columna;

                    for(j = 0; j < CANT_FANTASMAS; j++)
                    {
                        if(fantasmas[j].habilitado == 1)
                        {
                            fantasmas[j].pos = fantasmas[j].inicio;
                            fantasmas[j].activo = 1;
                        }
                    }
                }
            }
        }
    }
}

void actualizarMurosTemporales(int filas, int columnas,
                               int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                               int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                               int turnoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                               int turnoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                               int duenoVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                               int duenoHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                               int *murosPacman, int *murosFantasmas)
{
    int i;
    int j;

    for(i = 0; i < filas; i++)
    {
        for(j = 1; j < columnas; j++)
        {
            if(muroVertical[i][j] == 1)
            {
                turnoVertical[i][j]--;

                if(turnoVertical[i][j] <= 0)
                {
                    muroVertical[i][j] = 0;

                    if(duenoVertical[i][j] == DUENO_PACMAN) (*murosPacman)++;
                    if(duenoVertical[i][j] == DUENO_FANTASMAS) (*murosFantasmas)++;

                    duenoVertical[i][j] = SIN_DUENO;
                }
            }
        }
    }

    for(i = 1; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            if(muroHorizontal[i][j] == 1)
            {
                turnoHorizontal[i][j]--;

                if(turnoHorizontal[i][j] <= 0)
                {
                    muroHorizontal[i][j] = 0;

                    if(duenoHorizontal[i][j] == DUENO_PACMAN) (*murosPacman)++;
                    if(duenoHorizontal[i][j] == DUENO_FANTASMAS) (*murosFantasmas)++;

                    duenoHorizontal[i][j] = SIN_DUENO;
                }
            }
        }
    }
}

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
                      int murosInicialesPacman, int murosInicialesFantasmas)
{
    if(mapaSeleccionado == 4)
    {
        if(cargarMapaArchivo("mapa_editor.txt", filas, columnas, pacman,
                             pacbolas, fantasmas, tablero, muroVertical,
                             muroHorizontal, turnoVertical, turnoHorizontal,
                             duenoVertical, duenoHorizontal) == 0)
        {
            cargarMapaPredefinido(1, filas, columnas, pacman, pacbolas,
                                  fantasmas, tablero, muroVertical, muroHorizontal,
                                  turnoVertical, turnoHorizontal, duenoVertical,
                                  duenoHorizontal);
        }
    }
    else
    {
        cargarMapaPredefinido(mapaSeleccionado, filas, columnas, pacman,
                              pacbolas, fantasmas, tablero, muroVertical,
                              muroHorizontal, turnoVertical, turnoHorizontal,
                              duenoVertical, duenoHorizontal);
    }

    *vidas = 3;
    *pacbolasComidas = 0;
    *gano = 0;
    *perdio = 0;
    *turno = TURNO_PACMAN;
    *accionesPacman = 2;
    *murosPacman = murosInicialesPacman;
    *murosFantasmas = murosInicialesFantasmas;
    *fantasmasComidos = 0;
    *puntaje = 0;
    *poderComerFantasma = 0;
}

void dibujarTablero(int filas, int columnas, int tablero[MAX_FILAS][MAX_COLUMNAS],
                    int muroVertical[MAX_FILAS][MAX_COLUMNAS + 1],
                    int muroHorizontal[MAX_FILAS + 1][MAX_COLUMNAS],
                    int inicioX, int inicioY)
{
    int i;
    int j;
    int x;
    int y;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            x = inicioX + j * TAM_CASILLA;
            y = inicioY + i * TAM_CASILLA;

            if(tablero[i][j] == MURO_PERMANENTE)
            {
                DrawRectangle(x, y, TAM_CASILLA, TAM_CASILLA, DARKBLUE);
            }

            DrawRectangleLines(x, y, TAM_CASILLA, TAM_CASILLA, BLACK);
        }
    }

    for(i = 0; i < filas; i++)
    {
        for(j = 1; j < columnas; j++)
        {
            if(muroVertical[i][j] == 1)
            {
                x = inicioX + j * TAM_CASILLA - 3;
                y = inicioY + i * TAM_CASILLA;
                DrawRectangle(x, y, 6, TAM_CASILLA, SKYBLUE);
            }
        }
    }

    for(i = 1; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            if(muroHorizontal[i][j] == 1)
            {
                x = inicioX + j * TAM_CASILLA;
                y = inicioY + i * TAM_CASILLA - 3;
                DrawRectangle(x, y, TAM_CASILLA, 6, SKYBLUE);
            }
        }
    }
}

void dibujarPacman(Posicion pacman, int inicioX, int inicioY)
{
    int centroX = inicioX + pacman.columna * TAM_CASILLA + TAM_CASILLA / 2;
    int centroY = inicioY + pacman.fila * TAM_CASILLA + TAM_CASILLA / 2;

    DrawCircle(centroX, centroY, 17, YELLOW);
    DrawTriangle((Vector2){centroX, centroY},
                 (Vector2){centroX + 19, centroY - 11},
                 (Vector2){centroX + 19, centroY + 11}, WHITE);
    DrawCircle(centroX + 2, centroY - 7, 2, BLACK);
}

void dibujarPacBolas(PacBola pacbolas[], int inicioX, int inicioY)
{
    int i;
    int centroX;
    int centroY;

    for(i = 0; i < CANT_PACBOLAS; i++)
    {
        if(pacbolas[i].activa == 1)
        {
            centroX = inicioX + pacbolas[i].pos.columna * TAM_CASILLA + TAM_CASILLA / 2;
            centroY = inicioY + pacbolas[i].pos.fila * TAM_CASILLA + TAM_CASILLA / 2;
            DrawCircle(centroX, centroY, 7, ORANGE);
        }
    }
}

void dibujarFantasmas(Fantasma fantasmas[], int inicioX, int inicioY)
{
    int i;
    int centroX;
    int centroY;

    for(i = 0; i < CANT_FANTASMAS; i++)
    {
        if(fantasmas[i].habilitado == 1 && fantasmas[i].activo == 1)
        {
            centroX = inicioX + fantasmas[i].pos.columna * TAM_CASILLA + TAM_CASILLA / 2;
            centroY = inicioY + fantasmas[i].pos.fila * TAM_CASILLA + TAM_CASILLA / 2;
            dibujarFantasma(centroX, centroY, fantasmas[i].color);
        }
    }
}

void dibujarFantasma(int x, int y, Color color)
{
    DrawCircle(x, y - 5, 14, color);
    DrawRectangle(x - 14, y - 5, 28, 19, color);
    DrawCircle(x - 5, y - 5, 4, WHITE);
    DrawCircle(x + 5, y - 5, 4, WHITE);
    DrawCircle(x - 5, y - 5, 2, BLACK);
    DrawCircle(x + 5, y - 5, 2, BLACK);
}


void dibujarInformacion(int vidas, int pacbolasComidas, int turno, int accionesPacman,
                        int murosPacman, int murosFantasmas, int fantasmasComidos,
                        int puntaje, int modoJuego, int fantasmaSeleccionado,
                        int orientacionMuro, int ladoMuro, int poderComerFantasma)
{
    DrawText("Informacion", 610, 40, 24, BLACK);
    DrawText(TextFormat("Vidas: %d", vidas), 610, 90, 18, BLACK);
    DrawText(TextFormat("Pac-bolas: %d/%d", pacbolasComidas, CANT_PACBOLAS), 610, 120, 18, BLACK);
    DrawText(TextFormat("Muros P-M: %d", murosPacman), 610, 150, 18, BLACK);
    DrawText(TextFormat("Muros Fant.: %d", murosFantasmas), 610, 180, 18, BLACK);
    DrawText(TextFormat("Fant. comidos: %d", fantasmasComidos), 610, 210, 18, BLACK);
    DrawText(TextFormat("Puntaje: %d", puntaje), 610, 240, 18, BLACK);

    if(poderComerFantasma == 1)
    {
        DrawText("Poder: puede comer fantasma", 610, 270, 18, DARKGREEN);
    }
    else
    {
        DrawText("Poder: no", 610, 270, 18, DARKGRAY);
    }

    if(orientacionMuro == ORIENTACION_VERTICAL)
    {
        DrawText("Muro: vertical", 610, 300, 18, DARKBLUE);

        if(ladoMuro == 0)
        {
            DrawText("Lado: izquierda", 610, 330, 18, DARKBLUE);
        }
        else
        {
            DrawText("Lado: derecha", 610, 330, 18, DARKBLUE);
        }
    }
    else
    {
        DrawText("Muro: horizontal", 610, 300, 18, DARKBLUE);

        if(ladoMuro == 0)
        {
            DrawText("Lado: arriba", 610, 330, 18, DARKBLUE);
        }
        else
        {
            DrawText("Lado: abajo", 610, 330, 18, DARKBLUE);
        }
    }

    DrawText("O: orientacion  L: lado", 610, 360, 18, DARKGRAY);

    if(turno == TURNO_PACMAN)
    {
        DrawText("Turno: Pac-Man", 610, 400, 18, BLUE);
        DrawText(TextFormat("Acciones: %d", accionesPacman), 610, 430, 18, BLUE);
        DrawText("Flechas: mover", 610, 460, 18, DARKGRAY);
        DrawText("M: colocar muro", 610, 490, 18, DARKGRAY);
        DrawText("ENTER: fin turno", 610, 520, 18, DARKGRAY);
    }
    else
    {
        DrawText("Turno: Fantasmas", 610, 400, 18, RED);

        if(modoJuego == MODO_PVP)
        {
            DrawText(TextFormat("Fantasma sel.: %d", fantasmaSeleccionado), 610, 430, 18, RED);
            DrawText("TAB: cambiar fantasma", 610, 460, 18, DARKGRAY);
            DrawText("WASD: mover", 610, 490, 18, DARKGRAY);
            DrawText("N: colocar muro", 610, 520, 18, DARKGRAY);
        }
    }

    DrawText("R: reiniciar", 610, 565, 18, DARKGRAY);
    DrawText("ESC: salir", 610, 590, 18, DARKGRAY);
}

void mostrarNivel(int pacbolasComidas, int x, int y, Color color)
{
    if(pacbolasComidas == 0) DrawText("Nivel: Sin pac-bolas comidas", x, y, 20, color);
    if(pacbolasComidas == 1) DrawText("Nivel: Pac-Man novato", x, y, 20, color);
    if(pacbolasComidas == 2) DrawText("Nivel: Pac-Man prometedor", x, y, 20, color);
    if(pacbolasComidas == 3) DrawText("Nivel: Pac-Man de categoria", x, y, 20, color);
    if(pacbolasComidas == 4) DrawText("Nivel: Pac-Man de elite", x, y, 20, color);
}
