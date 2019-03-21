/*
Autores: Sophia Villanova, Aitana Carretero y Carlos Cruz
Grupo: Q103
Curso: 2018-2019
Descripción del programa: El programa ejecuta un juego de preguntas y respuestas, permite crear un usuario, 
guardar su record, iniciar nuevas partidas o continuar antiguas. 
El juego consiste en moverse a traves de un tablero conformado por casillas, cada casilla se corresponde 
con un tipo de pregunta de acuedo a la tematica correspondida. 
Los jugadores deberan contestar preguntas de cada tema hasta acumular una cantidad de puntos necesarios 
para ganar la estrella de esa area. 
Una vez acumuladas las estrellas de todas las tematicas el jugador se declara ganador. 
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int primeravez,definicion,menu;
	

	do
	{
	system("cls");
	printf("BIENVENIDO A TRIVIA:\n");
	printf("Es tu primera vez en trivia?:\n");
	printf("Teclea 1 si es tu primera vez, si no teclea 2\n");
	scanf("%d",&primeravez); 
	
	switch(primeravez)
	{
	case 1: //Si es la primera vez jugando, el programa le contara en que consiste el juego
		printf("A que no sabes que es TRIVIA?\n");
		printf("Teclea 1 si lo sabes, si no teclea 2\n");
		scanf("%d",&definicion);
		
		if (definicion==2)
		{
			printf("TRIVIA es un juego de preguntas y respuestas, deberas contestar preguntas de diversas areas\n");
			printf("para avanzar a traves de un tablero magico, una vez acumulados los 1000 puntos en cada area\n");
			printf("podras obtener la estrella correspondiente, cuando tengas las 4 estrellas seras declarado CAMPEON LISTILLO:\n");
			printf("Pero un novatillo como tu no podra declararse CAMPEON sin antes crearse un usuario, vamos a ello!\n");		
		}
		do
		{
		printf("Menu:\n");
		printf("1. Crear usuario\n");
		printf("2. Ver mi record\n");
		printf("3. Guardar partida\n");
		printf("4. Iniciar partida\n");
		printf("5. Salir del juego\n");
		scanf("%d", &menu);
		
		switch(menu)
		{
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
		case 5:
		break;
		default: 
		printf("Opcion invalida");
		}
		}
		while (menu!=5);		
	break;
	
	case 2: //Si no es la primera vez jugando el programa va directo al menu 
		do
		{
		printf("Menu:\n");
		printf("1. Crear usuario\n");
		printf("2. Ver mi record\n");
		printf("3. Guardar partida\n");
		printf("4. Iniciar partida\n");
		printf("5. Salir del juego\n");
		scanf("%d",&menu);
		
		switch(menu)
		{
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
		case 5:
		break;
		default: 
		printf("Opcion invalida");
		}
		}
		while (menu!=5);	
	break;
	default: 
	printf("Opcion invalida");
	}
	}
	while(primeravez<=0&primeravez>2);
}
