/*-------------------------------------------------------------------------------
|  Autor:Josué Mejía                             Matricula:                     |
|        Christopher Rosario                     Matricula: 1-19-0511           |
|  Fecha: 19/8/2023                               Version: 1.00 	            |
|-------------------------------------------------------------------------------|
| Descripción:                                                                  |
|                                                                               |
|                                                                               |
| ------------------------------------------------------------------------------*/
// Incluir E/S y Librerias Standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/LibF.h"
// Zona de Declaracion de Constantes
// Zona de Declaracion de variables globales

// Zona de Cabeceras de Procedimientos y Funciones

// Programa Principal
void main() 
{
    // Zona de Declaracion de Variables del Programa principal
    int Opcion;
    int cuenta = 0;
    // Implementacion de Procedimientos y Funciones
    do {
    	printf("\n");
        printf("\n");
        printf("\n");
        printf("1. Registrar empleado\n");
        printf("2. Ponchar Entrada\n");
        printf("3. Ponchar Salida\n");
        printf("4. Buscar por fecha\n");
        printf("5. Mostrar registros de empleados\n");
        printf("6. Calculo de prestaciones salariales\n");
        printf("7. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &Opcion);
system ("cls");
        switch (Opcion) {
            case 1:
                registrarColaborador();
                break;
            case 2:
                registrarPoncheEntrada();
                cuenta++;
                break;
            case 3:
                if(cuenta>0)
                    registrarPoncheSalida();
                else
                    printf("No se ha registrado ninguna entrada");
                break;
            case 4:
                buscarPorFecha();
                break;
            case 5:
                mostrarColaboradores();
                break;
            case 6:
                CalculoPrestacionesSalariales();
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida, Debe introducir una opcion valida.\n");
                break;
        }
    } while (Opcion != 7);
}