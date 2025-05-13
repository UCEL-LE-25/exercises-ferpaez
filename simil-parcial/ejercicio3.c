#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int lluviaDeFlechas[10];
    int lenght = sizeof(lluviaDeFlechas) / sizeof(lluviaDeFlechas[0]);
    int flechasAcertadas = 0;
    int flechasFalladas = 0;
   
    srand(time(NULL));
   
    for (int i = 0; i < lenght;i++){
        int random = rand() % 100 + 1;
       
        if (random >= 60) {
            lluviaDeFlechas[i] = 1;
            flechasAcertadas++;
            printf("La flecha %d acerto , ", i);
        } else {
            lluviaDeFlechas[i] = 0;
            flechasFalladas++;
            printf("La flecha %d fallo , ", i);
        }
    }
   
    printf("\nFlechas acertadas: %d\n", flechasAcertadas);
    printf("Flechas falladas: %d\n", flechasFalladas);
   
    return 0;
}