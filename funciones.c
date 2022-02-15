/*
 * funciones.c
 *
 *  Created on: 5/11/2014
 *      Author: daniricoesteban
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 1000

/*FUNCION ENCARGADA DE REALIZAR LAS TIRADAS*/
int realizarTirada(int tiradas[MAX])
{
	int valor;    /*Valor de cada tirada*/
	int i;        /*Indice que recorre el array de tiradas*/
	time_t t;
	srand((unsigned) time(&t));
	for(i=0;i<MAX;i++)
	{
		valor=1+(rand()%6);
		tiradas[i]=valor;
		for(i=10;i<20;i++)
		{
			tiradas[i]=0;
		}
	}
return tiradas[MAX];
}

/*FUNCION ENCARGADA DE IMPRIMIR POR PANTALLA LOS VALORES DE LA ULTIMA RONDA DE TIRADAS*/
int escribirRonda(int valoresRonda[MAX])
{
	int j;   /*Indice que recorre el array de los valores de la ronda*/

	for(j=0;j<MAX;j++)
		{
			printf("%d ",valoresRonda[j]);
			fflush(stdout);
	    }

	return valoresRonda[MAX];
}

/*FUNCION ENCARGADA DE CALCULAR LA MEDIA ARITMETICA*/
double mediaAritmetica(int ronda[MAX])
{
	double media; /*ALmacenarï¿½ la media aritï¿½tica de los valores*/
	int x;        /*Indice que recorre el array de la ronda de tiradas*/
	int suma;     /*Harï¿½ la suma total de los valores de la ronda*/
	suma=0;
	for(x=0;x<MAX;x++)
	{
		suma=suma+ronda[x];
	}
	media=(1.0*suma/MAX);
return media;
}

/*FUNCION ENCARGADA DE CALCULAR LA VARIANZA*/
double varianza(int _ronda[MAX],double _media)
{
	double varianza;       /*Valor de la varianza*/
	int y;                 /*Indice que recorre el array de tiradas*/
	double cuadrado[MAX];  /*Cuadrado de la resta de cada valor de la tirada con la media aritmetica*/
	double suma;              /*Suma total del cuadrado de cada numero habiendole restado la media aritmetica*/
	suma=0;
	for(y=0;y<MAX;y++)
	{
		cuadrado[y]=(_ronda[y]-_media)*(_ronda[y]-_media);
		suma=suma+cuadrado[y];
	}
	varianza=(1.0*suma)/MAX-1;
return varianza;
}

/*FUNCION ENCARGADA DE CALCULAR LA DESVIACION TIPICA*/
double desviacionT(double _varianza)
{
	double desviacion;         /*Desviacion tï¿½pica*/
	desviacion=sqrt(_varianza);
return desviacion;
}

/*FUNCION ENCARGADA DE REALIZAR LAS TIRADAS CON UN DADO TRUCADO*/
int tiradaTrucada(int tiradasT[MAX])
{
	int valorT;           /*Valor de cada tirada trucada*/
	int q;                /*Indice que recorre el array de tiradas*/
	time_t t;
	srand((unsigned) time(&t));
	for(q=0;q<MAX;q++)
		{
			valorT=1+(rand()%21);
			if(valorT==1)
			{
				tiradasT[q]=1;
			}
			else
				if(valorT>=2 && valorT<=3)
				{
					tiradasT[q]=2;
				}
				else
					if(valorT>=4 && valorT<=6)
					{
						tiradasT[q]=3;
					}
					else
						if(valorT>=7 && valorT<=10)
						{
							tiradasT[q]=4;
						}
						else
							if(valorT>=11 && valorT<=15)
							{
								tiradasT[q]=5;
							}
							else
								if(valorT>=16 && valorT<=21)
								{
									tiradasT[q]=6;
								}
		}
return tiradasT[MAX];
}

/*FUNCION PRINCIPAL*/
int main(void)
{
int eleccion;      /*Eleccion de una opcion del menu*/
int tirada[MAX];   /*Array que almacena el numero de tiradas realizadas*/
do
{
	printf("\n**********\nMENU\n");
	fflush(stdout);
	printf("1. Hacer N tiradas de un dado de 6 caras y almacenar la ronda de tiradas.\n");
	fflush(stdout);
	printf("2. Obtener y escribir la media aritmÃ©tica de la Ãºltima ronda de tiradas obtenida.\n");
	fflush(stdout);
	printf("3. Obtener y escribir la varianza de la Ãºltima ronda de tiradas obtenida.\n");
	fflush(stdout);
	printf("4. Obtener la desviaciÃ³n tÃ­pica de la Ãºltima ronda de tiradas obtenida.\n");
	fflush(stdout);
	printf("5. Hacer N tiradas de un dado trucado de 6 caras y almacenar la ronda de tiradas.\n");
	fflush(stdout);
	printf("6. Salir del programa.\n**********\n");
	fflush(stdout);
	scanf("%d",&eleccion);
	fflush(stdin);

	switch(eleccion)
	{
	case 1:
			realizarTirada(tirada);
			printf("Valor de la Ãºltima ronda de tiradas: ");
			fflush(stdout);


			escribirRonda(tirada);
		break;

	case 2:
			printf("La media aritmÃ©tica de la Ãºltima ronda de tiradas es: %lf",mediaAritmetica(tirada));
			fflush(stdout);
		break;

	case 3:
			printf("La varianza de la Ãºltima ronda de tiradas es: %lf",varianza(tirada,mediaAritmetica(tirada)));
			fflush(stdout);

		break;

	case 4:
			printf("La desviaciÃ³n tÃ­pica de la Ãºltima ronda de tiradas es: %lf",desviacionT(varianza(tirada,mediaAritmetica(tirada))));
			fflush(stdout);
		break;

	case 5:
			tiradaTrucada(tirada);
			printf("Valor de la Ãºltima ronda de tiradas (dado trucado): ");
			fflush(stdout);
			escribirRonda(tirada);
		break;

	case 6: printf("PROGRAMA FINALIZADO\n");
			fflush(stdout);
			return 0;
		break;

	default: printf("SELECCION INCORRECTA\n");
			 fflush(stdout);
		 break;
	}

}while(eleccion!=6);

printf("PROGRAMA FINALIZADO.");
fflush(stdout);

return 0;
}
