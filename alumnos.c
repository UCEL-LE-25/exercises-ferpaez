#include <stdio.h>

int main() {
    struct alumnos {
        char nombre[20];
        int edad;
        float notaFinal; 
    }
    alumnos[3];
    
    for (int i = 0; i < 3; i++) {
        printf("Ingrese el nombre del alumno %d: ", i + 1);
        scanf("%s", alumnos[i].nombre);
        printf("Ingrese la edad del alumno %d: ", i + 1);
        scanf("%d", &alumnos[i].edad);
        printf("Ingrese la nota final del alumno %d: ", i + 1);
        scanf("%f", &alumnos[i].notaFinal);
    }


}