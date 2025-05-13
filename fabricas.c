#include <stdio.h>
#include <string.h>

typedef struct {
    int unidades;
    int costo;
    int precio;
    char nombre[20];
} Productos;

typedef struct {
    char nombre[20];
    Productos productos[4];
} Fabricas;

int main() {
    Fabricas fabricas[3];
    float rentabilidad[3][4];
    float margen[3][4];
    char productoMenorMargen[20];
    char fabricaMayorRent[20];
    float rentabilidadMax = -1;
    float menorMargen = -1;

    // Cargar datos
    for (int i = 0; i < 3; i++) {
        printf("Ingrese el nombre de la fabrica %d: ", i + 1);
        scanf("%s", fabricas[i].nombre);

        for (int j = 0; j < 4; j++) {
            printf("Ingrese el nombre del producto %d de la fabrica %d: ", j + 1, i + 1);
            scanf("%s", fabricas[i].productos[j].nombre);

            printf("Ingrese el costo del producto %d de la fabrica %d: ", j + 1, i + 1);
            scanf("%d", &fabricas[i].productos[j].costo);

            printf("Ingrese el precio del producto %d de la fabrica %d: ", j + 1, i + 1);
            scanf("%d", &fabricas[i].productos[j].precio);

            printf("Ingrese la cantidad de unidades del producto %d de la fabrica %d: ", j + 1, i + 1);
            scanf("%d", &fabricas[i].productos[j].unidades);

            // Calcular rentabilidad y margen
            rentabilidad[i][j] = (fabricas[i].productos[j].precio - fabricas[i].productos[j].costo) * fabricas[i].productos[j].unidades;
            margen[i][j] = fabricas[i].productos[j].precio - fabricas[i].productos[j].costo;
        }
    }

    // Buscar mayor rentabilidad
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (rentabilidad[i][j] > rentabilidadMax) {
                rentabilidadMax = rentabilidad[i][j];
                strcpy(fabricaMayorRent, fabricas[i].nombre);
            }
        }
    }

    // Buscar menor margen
    menorMargen = margen[0][0];
    strcpy(productoMenorMargen, fabricas[0].productos[0].nombre);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (margen[i][j] < menorMargen) {
                menorMargen = margen[i][j];
                strcpy(productoMenorMargen, fabricas[i].productos[j].nombre);
            }
        }
    }

    // Promedio de unidades por fábrica
    for (int i = 0; i < 3; i++) {
        int sumaUnidades = 0;
        for (int j = 0; j < 4; j++) {
            sumaUnidades += fabricas[i].productos[j].unidades;
        }
        float promedioUnidades = (float)sumaUnidades / 4;
        printf("El promedio de unidades producidas por la fabrica %s es: %.2f\n", fabricas[i].nombre, promedioUnidades);
    }

    printf("El producto con menor margen economico es: %s\n", productoMenorMargen);
    printf("La fabrica con mayor rentabilidad es: %s\n", fabricaMayorRent);

    return 0;
}
