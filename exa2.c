#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
typedef struct exa2
{
    int numero;
    char Nombre[30];
    char fecha[30];
    char problema[50];
    char costo[15];
} Tdato;

void R(FILE *fa, Tdato registros[], int num_reg);
void pedir(Tdato Registros[], int *num_reg);
void buscar(Tdato registros[], int num_reg, int numero);
void copiarArchivo(FILE *fa);
void buscar_modificar(Tdato registros[], int *num_reg);

int main()
{
    Tdato registros[1000];
    FILE *archivo;
    archivo = fopen("Regsitros.txt", "a");
    int num_reg = 0;
    int opc, numero, menu = 1;
    do
    {
        printf("menu\n1.-Agregar registro de mascota\n2.-actualizar/agregar a arcgivo\n3.-Buscar registro\n4.-SALIR\n5.-cargar\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            pedir(registros, &num_reg);
            break;
        case 2:
            R(archivo, registros, num_reg);
            break;

        case 3:
            printf("ingrese el numero que quieres busacr\n");
            scanf("%d", &numero);

            buscar(registros, num_reg, numero);
            break;
        case 4:

            return 0;
        case 5:
            copiarArchivo(archivo);
            break;
        case 6:

            buscar_modificar(registros, &num_reg);

            break;
        }
    } while (menu == 1);

    fclose(archivo);
}
void R(FILE *fa, Tdato registros[], int num_reg)
{
    int i;
    fa = fopen("Regsitros.txt", "w");
    for (int i = 0; i < num_reg; i++)
    {
        if (!feof(fa))
        {
            fprintf(fa, " ");
        }
    }
    if (num_reg == 0)
    {
        fprintf(fa, "No hay registros para imprimir.\n");
        fclose(fa);
        return;
    }
    fprintf(fa, "\nnumero    | Nombres                      | fecha                        |  Problema                                        |  Costo   |\n");
    for (i = 0; i < num_reg; i++)
    {
        fprintf(fa, "%-10d|%-30s|%-30s|%-50s|%-10s|\n", registros[i].numero, registros[i].Nombre, registros[i].fecha, registros[i].problema, registros[i].costo);
    }
    fclose(fa);
}
void pedir(Tdato Registros[], int *num_reg)
{
    char Nombre[30], fecha[30], problema[50], costo[15];
    Tdato *Registro = &Registros[*num_reg];
    Registro->numero = (rand() % 1000);
    printf("Ingrese Nombre de mascota\n");
    gets(Nombre);
    gets(Nombre);
    strcpy(Registro->Nombre, Nombre);
    printf("Ingrese fecha\n");
    gets(fecha);
    strcpy(Registro->fecha, fecha);
    printf("Ingrese problema de mascota\n");
    gets(problema);
    strcpy(Registro->problema, problema);
    printf("Ingrese costo de mascota\n");
    gets(costo);
    strcpy(Registro->costo, costo);
    (*num_reg)++;
}

void buscar(Tdato registros[], int num_reg, int numero)
{
    int encontrado = 0;

    for (int i = 0; i < num_reg; i++)
    {
        if (registros[i].numero == numero)
        {
            printf("============================================================================\n");
            printf("| Numero: %d                                                       |\n", registros[i]);
            printf("|--------------------------------------------------------------------------|\n");
            printf("| Nombre: %-25s                                        |\n", registros[i].Nombre);
            printf("| fecha    : %-28s                                  |\n", registros[i].fecha);
            printf("| Problema: %-20s                                           |\n", registros[i].problema);
            printf("| Numero Social: %-11s                                               |\n", registros[i].costo);
            printf("============================================================================\n");
        }
        encontrado = 1;
    }
    if (encontrado == 0)
    {
        printf("NO SE ENCONTRO El NUMERO\n\n");
    }
}
void copiarArchivo(FILE *fa)
{
    FILE *archivo_origen;
    char caracter, nombre_externo[30], nombre_destino[30];
    printf("INGRESE EL NOMBRE DEL ARCHIVO EXTERNO\n");
    gets(nombre_externo);
    gets(nombre_externo);
    strcat(nombre_externo, ".txt");
    archivo_origen = fopen(nombre_externo, "r");
    if (archivo_origen == NULL)
    {
        printf("No se pudo abrir el archivo externo.\n");
        return;
    }

    printf("INGRESE EL NOMBRE DEL ARCHIVO DESTINO\n");
    gets(nombre_destino);

    strcat(nombre_destino, ".txt");
    fa = fopen(nombre_destino, "w");
    if (fa == NULL)
    {
        printf("No se pudo crear o abrir el archivo.\n");
        fclose(archivo_origen);
        return;
    }

    while ((caracter = fgetc(archivo_origen)) != EOF)
    {
        fputc(caracter, fa);
    }

    fclose(archivo_origen);
    fclose(fa);
}
void buscar_modificar(Tdato Registros[], int *num_reg)
{
    Tdato *Registro = &Registros[*num_reg];
    int numero_a_encontrar, encontrado = 0, opc, i;
    char Nombre[30], fecha[30], problema[50], costo[15];
    char numero[10];
    printf("Ingrese el Numero\n");
    gets(numero);
    for (i = 0; i < *num_reg; i++)
    {

        if (registros[i].numero == numero)
        {
            {
                printf("============================================================================\n");
                printf("| Numero: %d                                                       |\n", registros[i]);
                printf("|--------------------------------------------------------------------------|\n");
                printf("| Nombre: %-25s                                        |\n", registros[i].Nombre);
                printf("| fecha    : %-28s                                  |\n", registros[i].fecha);
                printf("| Problema: %-20s                                           |\n", registros[i].problema);
                printf("| costo        : %-11s                                               |\n", registros[i].costo);
                printf("============================================================================\n");
            }
            encontrado = 1;
            printf("\n--MENU--\nCual area quieres modificar?\n1.-Numero\n2.-Nombre\n3.-fecha\n4.-problema\n5.-costo\n0.-NINGUNO\n");
            scanf("%d", &opc);

            switch (opc)
            {
            case 0:

                break;
            case 1:
                printf("Ingrese Nombre de mascota\n");
                gets(Nombre);
                gets(Nombre);
                strcpy(Registro->Nombre, Nombre);
                break;
            case 2:
                printf("Ingrese fecha\n");
                gets(fecha);
                strcpy(Registro->fecha, fecha);
                break;
            case 3:

                break;
            case 4:

                break;
            }
        }

        if (encontrado == 0)
        {
            printf("NO SE ENCONTRO LA MATRICULA\n\n");
            return;
        }
    }
}