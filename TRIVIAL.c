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

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE_p 1000
#define LIMITE_o 1000

struct jugador
{
	char nombre[50];
	char pieza;
	int numero;
	int io;
	int jo;
	int i1;
	int j1;
	char posicion;
	int descartado;
	int dado_turno;
	int dado_juego;
	int quesitoT;
	int quesitoD;
	int quesitoC;
	int quesitoG;
};

struct pregunta{
	int numero;
	char pregunta[LIMITE_p];
	int long_p;
	char opcionA[LIMITE_o];
	int long_opA;
	char opcionB[LIMITE_o];
	int long_opB;
	char opcionC[LIMITE_o];
	int long_opC;
	char respuesta;
	char categoria[20];
};


//PROTOTIPOS DE FUNCIONES

//Prototipo de la funcion menu
int menu();

//Prototipo de la funcion dado 
int tirardado();

//Prototipo de la funcion turno 
int turno(int num_jugadores);

//Prototipo de la funcion movimiento
int movimiento(int dado, int io, int jo, char tipo);

//Prototipo de la funcion tablero
char tablero(int i1, int j1, char pieza);
	//Prototipo de la funcion color
	void color(int valor);

//Prototipo de la funcion casilla
char casilla(i1,j1);


int main()
{
	color(15);
	
	//VARIABLES MENU
	int opcion;
	
	struct jugador jugadores[4];
	struct jugador jugadores_orden[4];
	
	//VARIABLES INICIO DE PARTIDA
	int num_jugadores;
	int i;
	int jugador_mayor;
	int pieza;
	char tablero_inicio;
	struct pregunta preguntas[17];
	char caracter;
	int k=0;
	int quesitos;
	int jugador_ganador;
	
	do
	{
		opcion=menu();
	
		switch (opcion)
		{
			case 1:
				printf("REGLAS DEL JUEGO\n\n\n");
				printf("TRIVIAL es un juego de preguntas y respuestas (4 jugadores MAXIMO y 2 jugadores MINIMO) el cual consta de 4\n categorias distintas. Tendras que recolectar los Quesitos de cada categoria y asi convertirte en el COMPEON LISTILLO.\n\n");
				printf("1. Al principio del juego, cada jugador tendra que tirar el dado. El jugador que saque el numero mayor sera\nel que inicie la partida. En caso de haber un empate, los jugadores empatados tendran que volver a tirar el dado\nhasta que haya un unico ganador.\n\n");
				printf("2. El tablero es cuadrado y se recorre en el sentido de las agujas del reloj.\n\n");
				printf("3. Significado de cada casilla en el tablero:\n");
				printf("D = Categoria de Deportes (Amarillo).\n");
				printf("T = Categoria de Television y Cine (Rojo).\n");
				printf("C = Categoria de Ciencias (Verde).\n");
				printf("G = Categoria de Geografia (Azul).\n");
				printf("Q = Quesito (Cian).\n");
				printf("+ = Vuelve a tirar los dados.\n");
				printf("- = Pierde el turno.\n\n");
				printf("4. Cuando un jugador cae en la casilla de otro jugador, este no se mueve y automaticamente pierde el turno.\n\n");
				printf("5. Cuando un jugador responde correctamente a una pregunta, podra lanzar el dado nuevamente (y asi hasta que se equivoque).\n\n");
				printf("6. Si el jugador cae en la casilla del Quesito, tendra que elegir una categoria (que no haya ganado aun) y asi poder optar por el\nQuesito correspondiente. En caso de acertar, ganara el tan deseado Quesito, de lo contrario,\n no le quedara mas remedio que seguir buscando el tan deseado Quesito.\n\n");
				printf("7. El jugador que consiga los 4 Quesitos gana automaticamente el juego y se convierte en el CAMPEON LISTILLO\n(claro, hasta que volvais a jugar).\n\n\n");
				break;
			
			case 2:
				
				//INSCRIPCION DE LOS JUGADORES Y ORDENACION DE LOS MISMOS DE ACUERDO A LA PRIMERA TIRADA DEL DADO
				do
				{
					printf("Cuantos jugadores sois? ");
					scanf("%d", &num_jugadores);
					
					if (num_jugadores<2 || num_jugadores>4)
					{
						printf("NUMERO DE JUGADORES NO PERMITIDO (MIN 2 Y MAX 4)\n");
					}
					
				} while(num_jugadores<2 || num_jugadores>4);
			
				for (i=0; i<num_jugadores; i++)
				{
					printf("Jugador %d, ingresa tu nombre:\n", i+1);
					scanf("%s", jugadores[i].nombre);
					jugadores[i].io=8;
					jugadores[i].jo=1;
					jugadores[i].quesitoT=0;
					jugadores[i].quesitoC=0;
					jugadores[i].quesitoD=0;
					jugadores[i].quesitoG=0;
					jugadores_orden[i]=jugadores[i];
				}
				jugador_mayor=turno(num_jugadores);
				printf("El primer turno es para %s\n", jugadores[jugador_mayor].nombre);
				jugadores_orden[0]=jugadores[jugador_mayor];
				
				if (jugador_mayor==0)
				{
					for (i=1; i<=num_jugadores-1; i++)
					{
						jugadores_orden[i]=jugadores[i];
					}
				}
				else if (jugador_mayor==num_jugadores-1)
				{
					for (i=0; i<=num_jugadores-2; i++)
					{
						jugadores_orden[i+1]=jugadores[i];
					}
				}
				else
				{
					if (jugador_mayor==num_jugadores-2)
					{
						jugadores_orden[1]=jugadores[num_jugadores-1];
						
						for (i=0; i<jugador_mayor; i++)
						{
							jugadores_orden[i+2]=jugadores[i];
						}
					}
					else if (jugador_mayor==num_jugadores-3)
					{
						for (i=jugador_mayor+1; i<num_jugadores-1; i++)
						{
							jugadores_orden[i-1]=jugadores[i];
						}
						
						jugadores_orden[3]=jugadores[0];
					}
				}
				for(i=0;i<num_jugadores;i++)
				{
					jugadores_orden[i].numero=i;
				}
				// ELECCION DE PIEZAS POR TURNOS (NO SE PUEDEN REPETIR)
					
					for(i=0; i<num_jugadores; i++)
					{	
						if(i==0)
						{
						printf("%s, llego el momento de elegir tu pieza:\n", jugadores_orden[i].nombre);
						printf("1. $\n");
						printf("2. @\n");
						printf("3. #\n");
						printf("4. &\n");
						scanf("%d", &pieza);
						
						switch (pieza)
						{
							case 1:
								jugadores_orden[i].pieza='$';
								break;
								
							case 2:
								jugadores_orden[i].pieza='@';
								break;
								
							case 3:
								jugadores_orden[i].pieza='#';
								break;
								
							case 4:
								jugadores_orden[i].pieza='&';
								break;
								
							default:
								printf("NO EXISTE ESTA PIEZA\n");
						}
						}
						
						else
						{
						do
						{
						printf("%s, llego el momento de elegir tu pieza:\n", jugadores_orden[i].nombre);
						printf("1. $\n");
						printf("2. @\n");
						printf("3. #\n");
						printf("4. &\n");
						scanf("%d", &pieza);
						
						switch (pieza)
						{
							case 1:
								jugadores_orden[i].pieza='$';
								break;
								
							case 2:
								jugadores_orden[i].pieza='@';
								break;
								
							case 3:
								jugadores_orden[i].pieza='#';
								break;
								
							case 4:
								jugadores_orden[i].pieza='&';
								break;
								
							default:
								printf("NO EXISTE ESTA PIEZA\n");
						}
						
						if(jugadores_orden[i].pieza==jugadores_orden[i-1].pieza)
						{
							printf("Las piezas no puedes ser iguales\n");
						}
						
					}
					while(jugadores_orden[i].pieza==jugadores_orden[i-1].pieza);
					}
					}
				
				printf("TODO LISTO PARA DAR INICIO A ESTA AVENTURA, A POR LOS QUESITOS!\n\n");
				printf("He aqui el tablero de TRIVIAL, todos los jugadores se encuentran en la casilla de partida\n");
				tablero_inicio=tablero(8, 3, 176);
				
				//INICIO DEL JUEGO
				char categoria;
				int numero_pregunta;
				char respuesta_jugador;
				int i=0;
				int n=0;
				int j;
	
	FILE*fichero;
	
	fichero=fopen("preguntas.txt","r");
	
	if (fichero==NULL)
	{
		printf("Error en la apertura del fichero");
		return -1;
	}
	
	while(fscanf(fichero,"%s %s %s %s %d %c %s", preguntas[n].pregunta,preguntas[n].opcionA,preguntas[n].opcionB,preguntas[n].opcionC,&preguntas[n].numero, &preguntas[n].respuesta,preguntas[n].categoria)!=EOF)
	{
		preguntas[n].long_p=strlen(preguntas[n].pregunta);
		preguntas[n].long_opA=strlen(preguntas[n].opcionA);
		preguntas[n].long_opB=strlen(preguntas[n].opcionB);
		preguntas[n].long_opC=strlen(preguntas[n].opcionC);
		n++;
	}
	
	fclose(fichero);

	//printf("Contador: %d\n",n);

	for (i=0;i<n;i++)
	{
		
		for (j=0;j<preguntas[i].long_p;j++)
		{
			if(preguntas[i].pregunta[j]=='_')
			{
				preguntas[i].pregunta[j]=' ';
			}
		}
		for (j=0;j<preguntas[i].long_opA;j++)
		{
			if(preguntas[i].opcionA[j]=='_')
			{
				preguntas[i].opcionA[j]=' ';
			}
		}
		for (j=0;j<preguntas[i].long_opB;j++)
		{
			if(preguntas[i].opcionB[j]=='_')
			{
				preguntas[i].opcionB[j]=' ';
			}
		}
		for(j=0;j<preguntas[i].long_opC;j++)	
		{
			if(preguntas[i].opcionC[j]=='_')
			{
				preguntas[i].opcionC[j]=' ';
			}
		}
//	printf("%s\n %s\n %s\n %s\n %d\n %c\n %s\n",preguntas[i].pregunta,preguntas[i].opcionA,preguntas[i].opcionB,preguntas[i].opcionC,preguntas[i].numero,preguntas[i].respuesta,preguntas[i].categoria);	
	}
				do
				{
					for (i=0; i<num_jugadores; i++)
					{
						do
						{
						k==0;
						printf("Es el turno de %s:\n", jugadores_orden[i].nombre);
						jugadores_orden[i].dado_juego=tirardado();
						
						jugadores_orden[i].i1=movimiento(jugadores_orden[i].dado_juego, jugadores_orden[i].io, jugadores_orden[i].jo, 'i');
						jugadores_orden[i].j1=movimiento(jugadores_orden[i].dado_juego, jugadores_orden[i].io, jugadores_orden[i].jo, 'j');
						jugadores_orden[i].posicion=tablero(jugadores_orden[i].i1, jugadores_orden[i].j1, jugadores_orden[i].pieza);
						caracter=casilla(jugadores_orden[i].i1,jugadores_orden[i].j1);
						printf("%c\n",caracter);

				srand (time (0));
				numero_pregunta = rand () % 4 + 1;
				
			switch(caracter)
			{
				case 'Q':
					printf("Tienes la oportunidad de comerte un QUESITO\nEscoge la categoria:\n");
					printf(" D. Deportes\n C. Ciencias\n T.Television y Cine\n G. Geografia\n");
					scanf("%c",&categoria);
					for (k=0;k<17;k++)
					{
						if((numero_pregunta==preguntas[k].numero)&&(categoria==preguntas[k].categoria[0]))
						{
							printf("%s\n %s\n %s\n %s\n",preguntas[k].pregunta,preguntas[k].opcionA,preguntas[k].opcionB,preguntas[k].opcionC);
							fflush(stdin);
							scanf("%c",&respuesta_jugador);
							if(respuesta_jugador==preguntas[k].respuesta)
								{
									printf("RESPUESTA CORRECTA!!\nHas ganado el QUESITO de la categoria %s",preguntas[k].categoria[0]);
									switch(categoria)
									{
										case 'T':
											jugadores_orden[i].quesitoT=1;
											k++;
										break;
										case 'C':
											jugadores_orden[i].quesitoC=1;
											k++;
										break;
										case 'G':
											jugadores_orden[i].quesitoG=1;
											k++;
										break;
										case 'D':
											jugadores_orden[i].quesitoD=1;
											k++;
										break;
									}
								}
							else 
								{
									printf("RESPUESTA INCORRECTA\n");
								}
						break;
						}
						else 
						{
						continue;	
						}
					}
				break;
				case 'T':
				for (i=0;i<17;i++)
				{
					if((numero_pregunta==preguntas[i].numero)&&(caracter==preguntas[i].categoria))
					{
						printf("%s\n %s\n %s\n %s\n",preguntas[i].pregunta,preguntas[i].opcionA,preguntas[i].opcionB,preguntas[i].opcionC);
						fflush(stdin);
						scanf("%c",&respuesta_jugador);
						if(respuesta_jugador==preguntas[i].respuesta)
							{
								printf("RESPUESTA CORRECTA!!,continuas jugando\n");
								k++;
							}
						else 
							{
								printf("RESPUESTA INCORRECTA\n");
							}
					break;
					}
					else 
					{
					continue;	
					}
				}
				break;
				case 'C':
				for (i=0;i<17;i++)
				{
					if((numero_pregunta==preguntas[i].numero)&&(caracter==preguntas[i].categoria[0]))
					{
						printf("%s\n %s\n %s\n %s\n",preguntas[i].pregunta,preguntas[i].opcionA,preguntas[i].opcionB,preguntas[i].opcionC);
						fflush(stdin);
						scanf("%c",&respuesta_jugador);
						if(respuesta_jugador==preguntas[i].respuesta)
							{
								printf("RESPUESTA CORRECTA!!,continuas jugando\n");
								k++;
							}
						else 
							{
								printf("RESPUESTA INCORRECTA\n");
							}
					break;
					}
					else 
					{
					continue;	
					}
				}
				break;
				case 'G':
				for (i=0;i<17;i++)
				{
					if((numero_pregunta==preguntas[i].numero)&&(caracter==preguntas[i].categoria))
					{
						printf("%s\n %s\n %s\n %s\n",preguntas[i].pregunta,preguntas[i].opcionA,preguntas[i].opcionB,preguntas[i].opcionC);
						fflush(stdin);
						scanf("%c",&respuesta_jugador);
						if(respuesta_jugador==preguntas[i].respuesta)
							{
								printf("RESPUESTA CORRECTA!!,continuas jugando\n");
								k++;
							}
						else 
							{
								printf("RESPUESTA INCORRECTA\n");
							}
					break;
					}
					else 
					{
					continue;	
					}
				}
				break;
				case 'D':
				for (i=0;i<17;i++)
				{
					if((numero_pregunta==preguntas[i].numero)&&(caracter==preguntas[i].categoria))
					{
						printf("%s\n %s\n %s\n %s\n",preguntas[i].pregunta,preguntas[i].opcionA,preguntas[i].opcionB,preguntas[i].opcionC);
						fflush(stdin);
						scanf("%c",&respuesta_jugador);
						if(respuesta_jugador==preguntas[i].respuesta)
							{
								printf("RESPUESTA CORRECTA!!,continuas jugando\n");
								k++;
							}
						else 
							{
								printf("RESPUESTA INCORRECTA\n");
							}
					break;
					}
					else 
					{
					continue;	
					}
				}
				break;
				case '+':
					k++;
				break;
				case '-':
					printf("PIERDES EL TURNO\n");
				break;
				}
									jugadores_orden[i].io=jugadores_orden[i].i1;
									jugadores_orden[i].jo=jugadores_orden[i].j1;
									quesitos=jugadores_orden[i].quesitoT+jugadores_orden[i].quesitoG+jugadores_orden[i].quesitoC+jugadores_orden[i].quesitoD;
									
									if(quesitos==4)
									{
									jugador_ganador=i;	
									}
								
							}while(k==1&&quesitos!=4);
								}
								printf("%s GANADOR",jugadores_orden[i].nombre);
							} while (quesitos!=4); //Cuando alguien gane, contador de quesitos == 4
							
							break;
						
						case 3:
							printf("HASTA PRONTO!\n");
							break;
							
						default:
							printf("OPCION INCORRECTA, VUELVE A INTENTARLO\n");
					}
				} while (opcion!=3);
			}

//CUERPOS DE LAS FUNCIONES

//Cuerpo de la funcion menu

int menu()
{
	int opcion;

		printf("BIENVENIDO AL MENU DE TRIVIAL\n");
		printf("El mejor juego para dartela del listillo y humillar a tus amigos!!!\n\n");
		printf("1. Reglas del juego\n");
		printf("2. Iniciar partida\n");
		printf("3. Salir del juego\n");
		scanf("%d", &opcion);

	return opcion;
}

//Cuerpo de la funcion dado
int tirardado()
{
	char enter;
	printf("PULSE \"ENTER\" para tirar el dado\n");
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
	struct jugador jugadores[4];

	do
	{
		w=0;
		mayor=0;
		jugador_mayor=0;
		
		for(i=0; i<num_jugadores; i++)
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
			jugador_mayor=i;
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
	return jugador_mayor;
}

//Cuerpo de la funcion movimiento
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
	
	j1=jo;
	i1=io;
	
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

//Cuerpo de la funcion tablero
char tablero(int i1, int j1, char pieza)
{
	int i, j;
	char matriz[17][17];
	
	printf("\n");
	
	for (i=1; i<=16; i++)
	{
		for (j=1; j<=16; j++)
		{
			if ((i==1 && j==1 || i==1 && j==16 || i==16 && j==16 || i==16 && j==1) && (i!=i1 || j!=j1)) //PURPURA
			{
				matriz[i][j]='Q'; //PURPURA
			}
			else if ((i==1 && j==2 || i==1 && j==7 || i==1 && j==12 || i==2 && j==16 || i==7 && j==16 || i==12 && j==16 || i==16 && j==15 || i==16 && j==10 || i==16 && j==5 || i==15 && j==1 || i==10 && j==1 || i==4 && j==1) && (i!=i1 || j!=j1)) //AMARILLO
			{
				matriz[i][j]='D'; //AMARILLO
			}
			else if ((i==16 && j==8 || i==1 && j==4 || i==1 && j==9 || i==1 && j==14 || i==4 && j==16 || i==9 && j==16 || i==14 && j==16 || i==16 && j==13 || i==16 && j==3 || i==13 && j==1 || i==7 && j==1 || i==2 && j==1) && (i!=i1 || j!=j1)) //VERDE
			{
				matriz[i][j]='C'; //VERDE
			}
			else if ((i==1 && j==3 || i==1 && j==8 || i==1 && j==13 || i==3 && j==16 || i==8 && j==16 || i==13 && j==16 || i==16 && j==14 || i==16 && j==9 || i==16 && j==4 || i==14 && j==1 || i==9 && j==1 || i==3 && j==1) && (i!=i1 || j!=j1)) //ROJO
			{
				matriz[i][j]='T'; //ROJO
			}
			else if ((i==6 && j==1 || i==1 && j==5 || i==1 && j==10 || i==1 && j==15 || i==5 && j==16 || i==10 && j==16 || i==15 && j==16 || i==16 && j==12 || i==16 && j==7 || i==16 && j==2 || i==12 && j==1) && (i!=i1 || j!=j1)) //AZUL
			{
				matriz[i][j]='G'; //AZUL
			}
			else if ((i==1 && j==11 || i==6 && j==16 || i==16 && j==6 || i==11 && j==1) && (i!=i1 || j!=j1)) //TIRA DE NUEVO
			{
				matriz[i][j]='+'; //TIRA DE NUEVO
			}
			else if ((i==1 && j==6 || i==11 && j==16 || i==16 && j==11 || i==5 && j==1) && (i!=i1 || j!=j1)) //PIERDE TURNO
			{
				matriz[i][j]='-'; //PIERDE TURNO
			}
			else if ((i==8 && j==1) && (i!=i1 || j!=j1)) //GO
			{
				matriz[i][j]=94; //GO
			}
			else if ((i==8 && j==5) && (i!=i1 || j!=j1))
			{
				matriz[i][j]='T';
			}
			else if ((i==8 && j==6) && (i!=i1 || j!=j1))
			{
				matriz[i][j]='R';
			}
			else if ((i==8 && j==7) && (i!=i1 || j!=j1))
			{
				matriz[i][j]='I';
			}
			else if ((i==8 && j==8) && (i!=i1 || j!=j1))
			{
				matriz[i][j]='V';
			}
			else if ((i==8 && j==9) && (i!=i1 || j!=j1))
			{
				matriz[i][j]='I';
			}
			else if ((i==8 && j==10) && (i!=i1 || j!=j1))
			{
				matriz[i][j]='A';
			}
			else if ((i==8 && j==11) && (i!=i1 || j!=j1))
			{
				matriz[i][j]='L';
			}
			else if (i==i1 && j==j1)
			{
				matriz[i][j]=pieza;
			}
			else
			{
				matriz[i][j]=' '; //ESPACIOS
			}
		}
	}
	
	for (i=1; i<=16; i++)
	{
		for (j=1; j<=16; j++)
		{
			if (i==1 && j==1 || i==1 && j==16 || i==16 && j==16 || i==16 && j==1) //PURPURA
			{
				color(11);
				printf(" %c ", matriz[i][j]);
			}
			else if (i==1 && j==2 || i==1 && j==7 || i==1 && j==12 || i==2 && j==16 || i==7 && j==16 || i==12 && j==16 || i==16 && j==15 || i==16 && j==10 || i==16 && j==5 || i==15 && j==1 || i==10 && j==1 || i==4 && j==1) //AMARILLO
			{
				color(14);
				printf(" %c ", matriz[i][j]);
			}
			else if (i==16 && j==8 || i==1 && j==4 || i==1 && j==9 || i==1 && j==14 || i==4 && j==16 || i==9 && j==16 || i==14 && j==16 || i==16 && j==13 || i==16 && j==3 || i==13 && j==1 || i==7 && j==1 || i==2 && j==1) //VERDE
			{
				color(10);
				printf(" %c ", matriz[i][j]);
			}
			else if (i==1 && j==3 || i==1 && j==8 || i==1 && j==13 || i==3 && j==16 || i==8 && j==16 || i==13 && j==16 || i==16 && j==14 || i==16 && j==9 || i==16 && j==4 || i==14 && j==1 || i==9 && j==1 || i==3 && j==1) //ROJO
			{
				color(12);
				printf(" %c ", matriz[i][j]);
			}
			else if (i==6 && j==1 || i==1 && j==5 || i==1 && j==10 || i==1 && j==15 || i==5 && j==16 || i==10 && j==16 || i==15 && j==16 || i==16 && j==12 || i==16 && j==7 || i==16 && j==2 || i==12 && j==1) //AZUL
			{
				color(9);
				printf(" %c ", matriz[i][j]);
			}
			else if (i==1 && j==11 || i==6 && j==16 || i==16 && j==6 || i==11 && j==1) //TIRA DE NUEVO
			{
				color(13);
				printf(" %c ", matriz[i][j]);
			}
			else if (i==1 && j==6 || i==11 && j==16 || i==16 && j==11 || i==5 && j==1) //PIERDE TURNO
			{
				color(13);
				printf(" %c ", matriz[i][j]);
			}
			else if (i==8 && j==1) //GO
			{
				color(15);
				printf(" %c ", matriz[i][j]);
			}
			else if (i==8 && j==5 || i==8 && j==6 || i==8 && j==7 || i==8 && j==8 || i==8 && j==9 || i==8 && j==10 || i==8 && j==11)
			{
				color(15);
				printf(" %c ", matriz[i][j]);
			}
			else
			{
				color(7);
				printf(" %c ", 176);
			}
		}
		printf("\n");
	}
	color(15);
}

//Cuerpo de la funcion color
void color(int valor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), valor);
}

//Cuerpo de la funcion casilla
char casilla(i1,j1)
{
	int i,j;
	
	i=i1;
	j=j1;
	
			if ((i==1 && j==1 || i==1 && j==16 || i==16 && j==16 || i==16 && j==1)) //PURPURA
			{
				return 'Q'; //PURPURA
			}
			else if ((i==1 && j==2 || i==1 && j==7 || i==1 && j==12 || i==2 && j==16 || i==7 && j==16 || i==12 && j==16 || i==16 && j==15 || i==16 && j==10 || i==16 && j==5 || i==15 && j==1 || i==10 && j==1 || i==4 && j==1)) //AMARILLO
			{
				return 'D'; //AMARILLO
			}
			else if ((i==16 && j==8 || i==1 && j==4 || i==1 && j==9 || i==1 && j==14 || i==4 && j==16 || i==9 && j==16 || i==14 && j==16 || i==16 && j==13 || i==16 && j==3 || i==13 && j==1 || i==7 && j==1 || i==2 && j==1)) //VERDE
			{
				return 'C'; //VERDE
			}
			else if ((i==1 && j==3 || i==1 && j==8 || i==1 && j==13 || i==3 && j==16 || i==8 && j==16 || i==13 && j==16 || i==16 && j==14 || i==16 && j==9 || i==16 && j==4 || i==14 && j==1 || i==9 && j==1 || i==3 && j==1)) //ROJO
			{
				return 'T'; //ROJO
			}
			else if ((i==6 && j==1 || i==1 && j==5 || i==1 && j==10 || i==1 && j==15 || i==5 && j==16 || i==10 && j==16 || i==15 && j==16 || i==16 && j==12 || i==16 && j==7 || i==16 && j==2 || i==12 && j==1)) //AZUL
			{
				return 'G'; //AZUL
			}
			else if ((i==1 && j==11 || i==6 && j==16 || i==16 && j==6 || i==11 && j==1)) //TIRA DE NUEVO
			{
				return '+'; //TIRA DE NUEVO
			}
			else if ((i==1 && j==6 || i==11 && j==16 || i==16 && j==11 || i==5 && j==1)) //PIERDE TURNO
			{
				return '-'; //PIERDE TURNO
			}
}


