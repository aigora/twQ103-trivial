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

struct jugador 
{
	//char usuario[50];
	//int record;
	//char contrasena[100];
	int num; //numero de turno 
	char pieza;
	int io;
	int jo;
	int i1;
	int j1;
	struct quesitos
	{
		int C;
		int T;
		int D;
		int G;
	};
};

//Prototipos de funciones

//Prototipo funcion menu
int menu();

//Prototipo funcion dado 
int tirardado();

//Prototipo funcion turno 
int turno(int num_jugadores);

//Prototipo funcion movimiento
int movimiento(int dado, int io, int jo, char tipo);

int main()
{
	//variables menu
	//int primeravez,definicion,menu;
	int opcion;
	
	//variables creacion de usuarios 
	//int numero_usuarios,i=0;
	struct jugador jugadores[100];
	int pieza=0;
	
	//Variables inicio de partida
	int numero_jugadores;
	
	do
	{
		opcion=menu();
	
		switch (opcion)
		{
			case 1:
				printf("REGLAS DEL JUEGO\n\n\n");
				printf("TRIVIAL es un juego de preguntas y respuestas (4 JUGADORES MAXIMO) el cual consta de 4 categorias distintas\ny que se desenvuelve en un tablero un poco peculiar. Para ganar, tendras que recolectar los Quesitos de cada categoria\ne ir escalando hasta la cima del conocimiento.\n\n");
				printf("1. Al principio del juego, cada jugador tendra que lanzar el dado. El jugador que saque el numero mayor sera\nel que comience la partida. En caso de haber un empate, los jugadores empatados tendran que volver a lanzar el dado\nhasta que haya un unico ganador.\n\n");
				printf("2. El tablero es una piramide que consta de 4 pisos y se recorre en el sentido de las agujas del reloj. Para\nganar, tendras que llegar a la cima respondiendo un centenar de preguntas, para hacerte con la victoria.\n\n");
				printf("3. Significado de cada casilla en el tablero:\n");
				printf("D = Categoría de Deportes (Amarillo).\n");
				printf("T = Categoria de TV y Series (Rojo).\n");
				printf("C = Categoria de Ciencias (Verde).\n");
				printf("G = Categoria de Geografia (Azul).\n");
				printf("Q = Quesito (Cian).\n");
				printf("+ = Vuelve a lanzar los dados.\n");
				printf("- = Pierde el turno.\n\n");
				printf("4. Cuando un jugador cae en la casilla de otro jugador, este no se mueve y automaticamente pierde el turno.\n\n");
				printf("5. Cuando un jugador responde correctamente a una pregunta, podra lanzar el dado nuevamente (y asi hasta que se equivoque).\n\n");
				printf("6. Si el jugador cae en la casilla del Quesito, tendra que elegir una categoria y asi poder optar por el\nQuesito correspondiente. En caso de acertar, ganara el tan deseado Quesito y podra pasar al siguiente nivel de la piramide.\nDe lo contrario, no le quedara mas remedio que seguir buscando el tan deseado Quesito.\n\n");
				printf("7. El jugador que consiga los 4 Quesitos gana automaticamente el juego y se convierte en el CAMPEON LISTILLO\n(claro, hasta que volvais a jugar).\n\n\n");
				//printf("Sin nada mas que agregar, solo queda que tu y tus amigos se inscriban en el juego eligiendo su nombre de USUARIO y CONTRASENA para dar inicio a esta aventura!");
				break;
			
			/*case 2:
				printf("Introduce tu nombre de usuario: ");
				gets(jugadores.usuario);
				printf("\nIntroduce tu contrasena: ");
				gets(jugadores.contrasena);
				break;
			
			case 3:
				x
				x
				x
				break;*/
			
			case 2:
				printf("Cuantos jugadores sois? ");
				scanf("%d", &num_jugadores);
			
				for (i=1; i<=num_jugadores; i++)
				{
					printf("Jugador %d, ingresa tu nombre de usuario: ", i);
					scanf()
				}
				break;
			
			case 3:
				printf("HASTA PRONTO!\n");
				break;
		}
	} while (opcion!=3);
}

//Cuerpos funciones 

//Cuerpo funcion menu

int menu()
{
	int opcion;

		printf("BIENVENIDO AL MENU DE TRIVIAL\n");
		printf("El mejor juego para dartela del listillo y humillar a tus amigos\n\n");
		printf("1. Reglas del juego\n");
		//printf("2. Crear usuario\n");
		//printf("3. Ver mi record\n");
		printf("2. Iniciar partida\n");
		printf("3. Salir del juego\n");
		scanf("%d", &opcion);

	return opcion;
}

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
int turno(int num_jugadores)
{
	int i=0, mayor=0, jugador_mayor=0, x=0, w=0;
	int vector_turnos[num_jugadores], vector_turnos_repetidos[4];
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
	
		for (i=0; i<num_jugadores; i++)
		{
			if(vector_turnos[i]>=mayor)
			{
			mayor=vector_turnos[i];
			jugador_mayor=i+1;
			}
		}
	
		for (i=0; i<num_jugadores; i++)
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
	}while (w!=1);
	
	printf("El primer turno es para el jugador %d", jugador_mayor);
}

int movimiento(int dado, int io, int jo, char tipo)
{
		int i1, j1;
	
	do
	{
		if (jo==1 && io>jo)
		{
			i1=io-1;
			dado=dado-1;
			io=i1;
		}
		else if (io==1 && jo>=io)
		{
			j1=jo+1;
			dado=dado-1;
			jo=j1;
		}
		else if (jo==16 && io<=jo)
		{
			i1=io+1;
			dado=dado-1;
			io=i1;
		}
		else if (io==16 && jo<=io)
		{
			j1=jo-1;
			dado=dado-1;
			jo=j1;
		}
		else if (jo==3 && io>jo)
		{
			i1=io-1;
			dado=dado-1;
			io=i1;
		}
		else if (io==3 && jo>=io)
		{
			j1=jo+1;
			dado=dado-1;
			jo=j1;
		}
		else if (jo==14 && io<=jo)
		{
			i1=io+1;
			dado=dado-1;
			io=i1;
		}
		else if (io==14 && jo<=io)
		{
			j1=jo-1;
			dado=dado-1;
			jo=j1;	
		}
		else if (jo==5 && io>jo)
		{
			i1=io-1;
			dado=dado-1;
			io=i1;
		}
		else if (io==5 && jo>=io)
		{
			j1=jo+1;
			dado=dado-1;
			jo=j1;
		}
		else if (jo==12 && io<=jo)
		{
			i1=io+1;
			dado=dado-1;
			io=i1;
		}
		else if (io==12 && jo<=io)
		{
			j1=jo-1;
			dado=dado-1;
			jo=j1;
		}
		else if (jo==7 && io>jo)
		{
			i1=io-1;
			dado=dado-1;
			io=i1;
		}
		else if (io==7 && jo>=io)
		{
			j1=jo+1;
			dado=dado-1;
			jo=j1;
		}
		else if (jo==10 && io<=jo)
		{
			i1=io+1;
			dado=dado-1;
			io=i1;
		}
		else if (io==10 && jo<=io)
		{
			j1=jo-1;
			dado=dado-1;
			jo=j1;
		}
		
	}while (dado!=0);
	
	if (tipo=='i')
	{
		return i1;
	}
	else if (tipo=='j')
	{
		return j1;
	}
	else 
	{
		return 0;
	}
}
