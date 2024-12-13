#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu() 
{
    int opc;
    printf("\n MENU \n");
    printf("1. Registro de libros\n");
    printf("2. Ver listado de libros\n");
    printf("3. Buscar libro por ID\n");
    printf("4. Buscar libro por titulo\n");
    printf("5. Actualizar el estado del libro\n");
    printf("6. Eliminar libro\n");
    printf("7. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d", &opc);
    return opc;
}

void registrarLibros(struct Libro libros[], int i) {
    if (i < 20) {
        libros[i].id = i + 1; 
        printf("\nIngrese el titulo del libro: ");
        getchar(); 
        fgets(libros[i].titulo, 100, stdin);
        libros[i].titulo[strcspn(libros[i].titulo, "\n")] = 0; 

        printf("Ingrese el autor del libro: ");
        fgets(libros[i].autor, 50, stdin);
        libros[i].autor[strcspn(libros[i].autor, "\n")] = 0; 

        do {
            printf("Ingrese el anio de publicacion del libro: ");
            scanf("%d", &libros[i].anio);
            if (libros[i].anio < 0 || libros[i].anio > 2024) {
                printf("Anio no valido. Intente de nuevo.\n");
            }
        } while (libros[i].anio < 0 || libros[i].anio > 2024);

        strcpy(libros[i].estado, "Disponible");
        printf("\nLibro registrado con exito. ID: %d\n", libros[i].id);
    } else {
        printf("\nNo se pueden agregar mas libros. Limite alcanzado.\n");
    }
}

void mostrarLibros(struct Libro libros[]) {
    printf("\n%-5s%-30s%-20s%-10s%-15s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < 20; i++) {
        if (libros[i].id != 0) {
            printf("%-5d%-30s%-20s%-10d%-15s\n",
                   libros[i].id,
                   libros[i].titulo,
                   libros[i].autor,
                   libros[i].anio,
                   libros[i].estado);
        }
    }
}

void buscarLibroId(struct Libro libros[], int id) {
    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor,
                   libros[i].anio, libros[i].estado);
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}

void buscarLibroTitulo(struct Libro libros[], char titulo[]) {
    for (int i = 0; i < 20; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor,
                   libros[i].anio, libros[i].estado);
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}

void actualizarEstado(struct Libro libros[], int id) {
    char nuevoEstado[50];

    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            printf("Ingrese el nuevo estado del libro (Disponible / Prestado): ");
            getchar(); 
            fgets(nuevoEstado, 50, stdin);
            nuevoEstado[strcspn(nuevoEstado, "\n")] = 0;  

            if (strcmp(nuevoEstado, "Disponible") == 0 || strcmp(nuevoEstado, "Prestado") == 0) {
                strcpy(libros[i].estado, nuevoEstado);  
                printf("\nEstado actualizado con exito. Nuevo estado: %s\n", libros[i].estado);
            } else {
                printf("\nEstado no valido. El estado debe ser 'Disponible' o 'Prestado'.\n");
            }
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}

void eliminarLibro(struct Libro libros[], int* count) {
    int id;
    printf("\nIngrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            printf("¿Esta seguro de que desea eliminar este libro? (1. Si / 2. No): ");
            int confirmar;
            scanf("%d", &confirmar);
            if (confirmar == 1) {
              
                for (int j = i; j < (*count) - 1; j++) {
                    libros[j] = libros[j + 1];
                }
                (*count)--;
                libros[*count].id = 0;  
                printf("\nLibro eliminado con exito.\n");
            } else if (confirmar == 2) {
                printf("\nOperacion cancelada. El libro no fue eliminado.\n");
            } else {
                printf("\nOpcion no valida. El libro no fue eliminado.\n");
            }
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}
