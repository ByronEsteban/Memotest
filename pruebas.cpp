#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void imprimir_tablero(int tablero[], bool tablero_validado[]){
  for (int i = 0; i < 42; i++) {
  	if (i != 0 && i%6 == 0) printf("\n");
    if (tablero_validado[i]) printf("%02d ", tablero[i]);
    else printf("XX ");
  }
}

void desordenar(int tablero[]){
  for (int i = 0; i < 1000; i++) {
    int r = rand()%42;
    int s = rand()%42;
    int temp = tablero[r];
    tablero[r] = tablero[s];
    tablero[s] = temp;
  }
}

void llenar(int tablero[], bool tablero_validado[]){
  for (int i = 2; i <= 43; i++) {
    tablero[i-2] = i/2;
    tablero_validado[i-2] = false;
  }
}

int main(void) {
  srand(time(NULL));
  int tablero[42];
  bool tablero_validado[42];
  llenar(tablero, tablero_validado);
  desordenar(tablero);
  imprimir_tablero(tablero, tablero_validado);
  int cant_jugadores;
  printf("\nIngresa la cantidad de jugadores (entre 2 y 6): ");
  while (1) {
    scanf("%d", &cant_jugadores);
    if (cant_jugadores <= 6 && cant_jugadores >= 2) break;
    else {
      system("cls");
      printf("Ingresa bien la cantidad de jugadores (entre 2 y 6): ");
    }
  }
  int jugadores[cant_jugadores];
  for (int i = 0; i < cant_jugadores; i++) jugadores[i] = 0;
  while (1) {
    for (int i = 1; i <= cant_jugadores; i++) {
      printf("Turno del jugador %d\n", i);
      printf("Ingresa las coordenadas de la ficha (de esta forma: 'a3'): ");
    }
    break;
  }


  return 0;
}
