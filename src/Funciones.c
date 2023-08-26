#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estructura para almacenar la hora
struct Hora {
    int horas;
    int minutos;
};

typedef struct {
    char Nombre[50];
    char Apellido[50];
    char Puesto[50];
    char Cedula[25];
    char Codigo[10];
    char Salario[50];
} Colaborador;

// Funci�n para obtener la hora actual del sistema
struct Hora obtenerHoraActual() {
    struct Hora horaActual;
    time_t rawTime;
    struct tm *timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    horaActual.horas = timeInfo->tm_hour;
    horaActual.minutos = timeInfo->tm_min;

    return horaActual;
}

// Funci�n para calcular la diferencia de tiempo entre dos horas
double calcularDiferenciaTiempo(struct Hora inicio, struct Hora fin) {
    double tiempoInicio = inicio.horas + inicio.minutos / 60.0;
    double tiempoFin = fin.horas + fin.minutos / 60.0;

    return tiempoFin - tiempoInicio;
}

/*int main() {
    FILE *archivoRegistro = fopen("registro.txt", "a+");
    if (archivoRegistro == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    int opcion;
    printf("1. Registrar hora de entrada\n");
    printf("2. Registrar hora de salida\n");
    printf("3. Calcular horas totales\n");
    printf("Selecciona una opci�n: ");
    scanf("%d", &opcion);

    struct Hora horaEntrada, horaSalida;
    double horasTrabajadas;

    switch (opcion) {
        case 1:
            horaEntrada = obtenerHoraActual();
            fprintf(archivoRegistro, "Entrada: %02d:%02d\n", horaEntrada.horas, horaEntrada.minutos);
            break;

        case 2:
            horaSalida = obtenerHoraActual();
            fprintf(archivoRegistro, "Salida: %02d:%02d\n", horaSalida.horas, horaSalida.minutos);
            break;

        case 3:
            // Calcular y mostrar horas totales trabajadas
            rewind(archivoRegistro); // Regresar al inicio del archivo
            fscanf(archivoRegistro, "%*s %d:%d\n", &horaEntrada.horas, &horaEntrada.minutos);
            fscanf(archivoRegistro, "%*s %d:%d\n", &horaSalida.horas, &horaSalida.minutos);
            horasTrabajadas = calcularDiferenciaTiempo(horaEntrada, horaSalida);
            printf("Horas totales trabajadas: %.2lf\n", horasTrabajadas);
            break;

        default:
            printf("Opci�n no v�lida.\n");
    }

    fclose(archivoRegistro);

    return 0;
}
*/
void registrarColaborador() 
{
    Colaborador Emp;
    printf("Ingrese el nombre del colaborador: ");
    scanf("%s", Emp.Nombre);
    printf("Ingrese el apellido del colaborador: ");
    scanf("%s", Emp.Apellido);
    printf("Ingrese su puesto: ");
    scanf("%s", Emp.Puesto);
    printf("Ingrese la cedula de empleado: ");
    scanf("%s", Emp.Cedula);
    printf("Ingrese el codigo de empleado: ");
    scanf("%s", Emp.Codigo);
    printf("Ingrese el salario del empleado: ");
    scanf("%s", Emp.Salario);

    

    FILE *Archivo = fopen(Emp.Nombre, "w");
    if (Archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return;
    }
    fprintf(Archivo, "Nombre: %s\nApellido: %s\nPuesto: %s\nCedula: %s\nCodigo: %s\nSalario: %s\n", Emp.Nombre, Emp.Apellido, Emp.Puesto, Emp.Cedula, Emp.Codigo, Emp.Salario);
    fclose(Archivo);
system ("cls");
    printf("El colaborador ha sido registrado correctamente.\n");
    printf("\n");
    printf("\n");
    printf("\n");
}


void registrarPoncheEntrada() 
{
    char Nombre[10];
    printf("Ingrese el Nombre del colaborador: ");
    scanf("%s", Nombre);

    FILE *Archivo = fopen(Nombre, "a");
    if (Archivo == NULL) {
        printf("Colaborador no encontrado.\n");
        return;
    }
    time_t T;
    struct tm *tm_info;
    time(&T);
    tm_info = localtime(&T);
    fprintf(Archivo, "Ponche de entrada: %02d:%02d:%02d %02d/%02d/%d\n", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec, tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
    fclose(Archivo);
system ("cls");
    printf("Ponche registrado correctamente.\n");
    
}
void registrarPoncheSalida() 
{
    char Nombre[10];
    printf("Ingrese el Nombre del colaborador: ");
    scanf("%s", Nombre);

    FILE *Archivo = fopen(Nombre, "a");
    if (Archivo == NULL) {
        printf("Colaborador no encontrado.\n");
        return;
    }
    time_t T1;
    struct tm *tm_info1;
    time(&T1);
    tm_info1 = localtime(&T1);
    fprintf(Archivo, "Ponche de salida: %02d:%02d:%02d %02d/%02d/%d\n", tm_info1->tm_hour, tm_info1->tm_min, tm_info1->tm_sec, tm_info1->tm_mday, tm_info1->tm_mon + 1, tm_info1->tm_year + 1900);
    fclose(Archivo);
system ("cls");
    printf("Ponche registrado correctamente.\n");
    
}

void buscarPorFecha() 
{
    char Fecha[20];
    printf("Ingrese la fecha (dd/mm/yyyy): ");
    scanf("%s", Fecha);
system ("cls");
    char Nombre[10];
    printf("Ingrese Nombre del colaborador: ");
    scanf("%s", Nombre);
system ("cls");
    FILE *Archivo = fopen(Nombre, "r");
    if (Archivo == NULL) {
        printf("Colaborador no encontrado.\n");
        return;
    }

    char Linea[100];
    while (fgets(Linea, sizeof(Linea), Archivo)) {
        if (strstr(Linea, Fecha) != NULL) {
            printf("%s", Linea);
        }
    }
    fclose(Archivo);
}

void buscarPorCodigo() 
{
    char Codigo[10];
    printf("Ingrese el codigo: ");
    scanf("%s", Codigo);
system ("cls");
system ("cls");
    FILE *Archivo = fopen(Codigo, "r");
    if (Archivo == NULL) {
        printf("Colaborador no encontrado.\n");
        return;
    }

    char Linea[100];
    while (fgets(Linea, sizeof(Linea), Archivo)) {
        if (strstr(Linea, Codigo) != NULL) {
            printf("%s", Linea);
        }
    }
    fclose(Archivo);
}

void buscarPorNombre() 
{
    char Nombre[10];
    printf("Ingrese nombre del colaborador: ");
    scanf("%s", Nombre);
    system ("cls");
    FILE *Archivo = fopen(Nombre, "r");
    if (Archivo == NULL) {
        printf("Colaborador no encontrado.\n");
        return;
    }

    char Linea[100];
    while (fgets(Linea, sizeof(Linea), Archivo)) {
        printf("%s", Linea);

    }
    fclose(Archivo);
}

void mostrarColaboradores() 
{
    char Opcion;
    printf("a. Buscar por nombre del colabolador\n");
    printf("b. Buscar por codigo del colabolador\n");
    printf("Elija su opcion de busqueda: ");
    scanf(" %c", &Opcion);
system ("cls");

    if (Opcion == 'a') {
        buscarPorNombre();
    } else if (Opcion == 'b') {
        buscarPorCodigo();
    } else {
        printf("Opcion invalida.\n");
    }
}

void CalculoPrestacionesSalariales() 
{
    char Nombre[10];
    char Fechain[10];
    char Fechaout[10];
    char Opcion;
    printf("a. Calculo de pago x horas trabajadas\n");
    printf("b. Salario Diario\n");
    printf("c. Salario Semanal\n");
    printf("d. Salario Mensual\n");
    printf("Elija su opcion de busqueda: ");
    scanf(" %c", &Opcion);
system ("cls");
    switch (Opcion)
    {
    case 'a':

        break;
    case 'b':
        /* code */
        break;
     case 'c':
        /* code */
        break;
    case 'd':
        /* code */
        break;
    
   
    }
}





