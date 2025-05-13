#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
    char nombre [20];
    int precio;
}Material;

const int PRICE_TABLA = 50;
const int PRICE_CLAVO = 10;
const int PRICE_SOGA = 75;
const int PRECIO_TRAMPA_DEFENSA = PRICE_TABLA * 2 + PRICE_CLAVO*4+ PRICE_SOGA;

int main()
{

    Material tabla = {"Tabla", PRICE_TABLA};
    Material clavo = {"Clavo", PRICE_CLAVO};
    Material soga = {"Soga", PRICE_SOGA};

    srand(time(NULL));

    int monedas = 100 + rand() % 200  + 1; 

    if (monedas<PRECIO_TRAMPA_DEFENSA)
    {
        printf("No puede comprar la trampa completa\n");
        monedas -=PRICE_SOGA;
    }else{
        printf("Puede comprar la trampa completa\n");
        monedas -= PRECIO_TRAMPA_DEFENSA;
        printf("Monedas restantes: %d\n", monedas);
        printf("Compra exitosa!\n");
        
    }



    

    
    return 0;
}