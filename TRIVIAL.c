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
#include<string.h>

struct usuario 
{
	char usuario[50];
	int record;
	char contrasena[100];
	char pieza;
	int x0;
	int y0;
};

//Prototipos funciones

//Prototipo funcion dado 
int tirardado();

//Prototipo turno 
int turno(int numero_jugadores);

int main()
{
	//variables menu
	int primeravez,definicion,menu;
	//variables creacion de usuarios 
	int numero_usuarios,i=0;
	struct usuario usuarios[100];
	int pieza=0;
	
	//Variables inicio de partida
	int numero_jugadores;
	

	do
	{
	system("cls");
	printf("BIENVENIDO A TRIVIA:\n");
	printf("Es tu primera vez en trivia?:\n");
	printf("Teclea 1 si es tu primera vez, en caso contrario teclea 2\n"); // cambio "si no" por "en caso contrario"
	scanf("%d", &primeravez); 
	
	switch(primeravez)
	{
	case 1: //Si es la primera vez jugando, el programa le contara en que consiste el juego
		printf("A que no sabes que es TRIVIA?\n");
		printf("Teclea 1 si lo sabes, si no teclea 2\n");
		scanf("%d", &definicion);
		
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
			printf("Cuantos jugadores sois?\n");
			scanf("%d",&numero_usuarios);
			for(i=0; i<=numero_usuarios-1; i++)
				{
				printf("**Usuario %d**\n",i+1);
				fflush(stdin);
				gets(usuarios[i].usuario);
				printf("**Contraseña usuario %d**\n",i+1);
				fflush(stdin);
				gets(usuarios[i].contrasena);
				printf("Que pieza desea el usuario %d\n", i+1);
				printf("1. ($)\n");
				printf("2. (&)\n");
				printf("3. (#)\n");
				printf("4. (@)\n");
				scanf("%d", &pieza);
				do 
				{
				switch(pieza)
				{
					case 1: 
					usuarios[i].pieza= '($)';
					case 2: 
					usuarios[i].pieza= '(&)';
					case 3: 
					usuarios[i].pieza= '(#)';
					case 4: 
					usuarios[i].pieza= '(@)';
				}
				if(usuarios[i].pieza==usuarios[i-1].pieza)
				{
					printf("Las piezas no deben ser iguales");
				}
				}
				while(usuarios[i].pieza!=usuarios[i-1].pieza);
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
			printf("")
		break;
		case 5:
		break;
		default: 
		printf("Opcion invalida");
		}
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
			printf("Cuantos jugadores sois?\n");
			scanf("%d",&numero_usuarios);
			for(i=1;i<numero_usuarios;i++)
				{
				printf("**Usuario %d**\n",i);
				fflush(stdin);
				gets(usuarios[i-1].usuario);
				printf("**Contraseña usuario %d**\n",i);
				fflush(stdin);
				gets(usuarios[i-1].contrasena);
				printf("Que pieza desea el usuario %d\n", i);
				printf("1. ($)\n");
				printf("2. (&)\n");
				printf("3. (#)\n");
				printf("4. (@)\n");
				scanf("%d", &pieza);
				
				do 
				{
				switch(pieza)
				{
					case 1: 
					usuarios[i].pieza= '($)';
					case 2: 
					usuarios[i].pieza= '(&)';
					case 3: 
					usuarios[i].pieza= '(#)';
					case 4: 
					usuarios[i].pieza= '(@)';
				}
				if(usuarios[i].pieza==usuarios[i-1].pieza)
				{
					printf("Las piezas no deben ser iguales\n");
				}
				}
				while(usuarios[i].pieza!=usuarios[i-1].pieza);
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
			printf("Adelante! A por los quesitos\n");
			printf("Cuantos jugadores sois?\n");
			scanf("%d", &numero_jugadores);
			turno(numero_jugadores);
		break;
		case 5:
		break;
		default: 
		printf("Opcion invalida");
		}
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

//Cuerpos funciones 

//Cuerpo funcion dado
int tirardado()
{
	char enter;
	printf("Presione \"ENTER\" para lanzar el dado\n");
	enter = getch();
	
	int dado=0;
  	srand (time (0));
  	dado = rand () % 6 + 1;
  	switch(dado)
    {
    case 1: 
    	printf(" ------\n");
        printf("|      |\n");
        printf("|  *   |\n");
        printf("|      |\n");
        printf(" ------\n");
    break;
    case 2: 
        printf(" ------\n");
        printf("| *    |\n");
        printf("|      |\n");
        printf("|    * |\n");
        printf(" ------\n");
	break;
	case 3:
        printf(" ------\n");
        printf("|*     |\n");
        printf("|  *   |\n");
        printf("|    * |\n");
        printf(" ------\n");
    break;
	case 4:
        printf(" ------\n");
        printf("|*   * |\n");
        printf("|      |\n");
        printf("|*   * |\n");
        printf(" ------\n");
	break;
	case 5:
        printf(" ------\n");
        printf("|*   * |\n");
        printf("|  *   |\n");
        printf("|*   * |\n");
        printf(" ------\n");
	break;
	case 6:
        printf(" ------\n");
        printf("|*   * |\n");
        printf("|*   * |\n");
        printf("|*   * |\n");
        printf(" ------\n");
    break;
    }  
  	return dado;
}

// Cuerpo de la funcion turno 
int turno(int numero_jugadores)
{
	int i=0, mayor=0, jugador_mayor=0, x=0, w=0;
	int vector_turnos[numero_jugadores], vector_turnos_repetidos[4];
	struct jugador jugadores[100];

	do
	{
		w=0;
		mayor=0;
		jugador_mayor=0;
		
		for(i=0; i<numero_jugadores; i++)
		{
		if(jugadores[i].descartado==1)
		{
			vector_turnos[i]=0;
			continue;
		}
		printf("Jugador %d\n",i+1);
		jugadores[i].dado_turno=tirardado();
		vector_turnos[i]=jugadores[i].dado_turno;
	}
	
	for (i=0; i<numero_jugadores; i++)
	{
		if(vector_turnos[i]>=mayor)
		{
		mayor=vector_turnos[i];
		jugador_mayor=i+1;
		}
	}
	
	for (i=0; i<numero_jugadores; i++)
	{
		if(vector_turnos[i]>=mayor)
		{
			w++;
		}
		else
		{
			jugadores[i].descartado=1;
		}
	}
}
while (w!=1);

	printf("El primer turno es para el jugador %d",jugador_mayor);
}
