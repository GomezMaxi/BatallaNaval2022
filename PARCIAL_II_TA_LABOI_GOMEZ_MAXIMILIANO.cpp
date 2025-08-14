#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Tablero inicial
void Tablero(int matriz[7][6]) {
    for (int f = 0; f < 7; f++) {
        for (int c = 0; c < 6; c++) {
            matriz[f][c] = 0;
        }
    }
    // Barco Nro1 (fila C, columnas 2-5)
    matriz[2][1] = 2; matriz[2][2] = 3; matriz[2][3] = 4; matriz[2][4] = 5;
    // Barco Nro2 (columna 5, filas E y F)
    matriz[4][4] = 6; matriz[5][4] = 7;
}

int main() {
    int opcion;
    char opcion2;
    int tiros = 0;
    int tiroagua = 0;
    int matriz[7][6];
    char opf;
    int opc;
    int b11 = 0, b12 = 0, b13 = 0, b14 = 0, b21 = 0, b22 = 0, ver = 0, ver2 = 0;
    const char nombre[100] = "Maximiliano Gomez";
    setlocale(LC_ALL, "");

    do {
        system("cls");
        printf("\n\t\t\tMenu de Opciones\n");
        printf("\t\t\t----------------\n");
        printf("\t1. Jugar\n");
        printf("\t2. Creditos\n");
        printf("\t3. SALIR\n");

        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1: {
            Tablero(matriz); // Se crea tablero una sola vez
            do {
                printf("\n\nIngrese Letra Para Fila (A-G): ");
                scanf(" %c", &opf);

                // convertir letra en número (1-7)
                switch (opf) {
                case 'a': case 'A': opf = 1; break;
                case 'b': case 'B': opf = 2; break;
                case 'c': case 'C': opf = 3; break;
                case 'd': case 'D': opf = 4; break;
                case 'e': case 'E': opf = 5; break;
                case 'f': case 'F': opf = 6; break;
                case 'g': case 'G': opf = 7; break;
                default:
                    printf("Fila inválida\n");
                    continue;
                }

                printf("\n\nIngrese Numero Para Columna (1-6): ");
                scanf("%d", &opc);
                if (opc < 1 || opc > 6) {
                    printf("Columna inválida\n");
                    continue;
                }

                if (matriz[opf - 1][opc - 1] == 0) {
                    printf("\n\nAgua\n\nInfo:\n");
                    tiroagua++;
                    tiros++;
                } else {
                    printf("\n\nHa Sido Tocada Una Nave\n\nInfo:\n");
                    tiros++;

                    if (matriz[opf - 1][opc - 1] == 2) b11 = 1;
                    if (matriz[opf - 1][opc - 1] == 3) b12 = 1;
                    if (matriz[opf - 1][opc - 1] == 4) b13 = 1;
                    if (matriz[opf - 1][opc - 1] == 5) b14 = 1;

                    if (b11 && b12 && b13 && b14) {
                        printf("\nBarco 1 Hundido!!\n\n"); ver = 1;
                    } else if (b11 || b12 || b13 || b14) {
                        printf("\nParte De Barco 1 Hundida\n\n");
                    }

                    if (matriz[opf - 1][opc - 1] == 6) b21 = 1;
                    if (matriz[opf - 1][opc - 1] == 7) b22 = 1;

                    if (b21 && b22) {
                        printf("\nBarco 2 Hundido!!\n\n"); ver2 = 1;
                    } else if (b21 || b22) {
                        printf("\nParte Del Barco 2 Hundida\n\n");
                    }

                    matriz[opf - 1][opc - 1] = 0; // marcar como ya disparado
                }

                printf("Cantidad de tiros: %d\n", tiros);
                printf("Cantidad de tiros al agua: %d\n", tiroagua);

                if (ver && ver2) {
                    printf("\nJuego Terminado!! Ha Hundido Todos Los Barcos\n\n");
                    break;
                }

                printf("¿Ingresar otro movimiento? S/N: ");
                scanf(" %c", &opcion2);
                system("cls");

            } while (opcion2 == 's' || opcion2 == 'S');

            printf("\n\n");
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            printf("\nEl Creador Del Juego Es: %s\n", nombre);
            printf("\n\n");
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            printf("\nSe Cerrara El Juego\n");
            return 0;
        }
        default:
            printf("Por Favor Ingrese Una Opcion Correcta\n");
            system("pause");
            system("cls");
        }
    } while (opcion != 3);
    return 0;
}

