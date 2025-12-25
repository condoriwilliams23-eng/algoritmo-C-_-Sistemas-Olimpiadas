#include<iostream>
#include <windows.h>
#include <conio.h>
#include "funcionesTp_new.h"
#include "deportes.h"
#include "paises.h"
#define numPaises 196
#define totalDeportes 87
#define deportesIndividuales 53
#define deportesColectivos 34

using namespace std;

int main (int argc, char *argv[]) {
	
	solicitud(); //manda una solicitud al usuario
	
	Bienvenida(); // imprime el mensaje de bienvenida.
	
	int legajoAct; //legajo de la persona que ingreso al programa.
	
	system("cls"); // refresca la pantalla.
	if(login(legajoAct)) // si login = 1 ingresa al programa ...
	{
		bool bandera=0; // corta el ciclo
		
		char var_menu=0; // variable utilizada para seleccionar el menu.
		
		bool menu_1=0, menu_2=0; // variables que nos ayudan a validar los ingresos a los menus
		
		archivoCompetencia competencia; // lista ordenadad de deportes donde se alamcana cada competicon y los paises que la conforman.
		
		int deporte_medallas[totalDeportes][3]={0}; //variable donde almacenamos los podios de los deportes
		
		for(int i=0; i<totalDeportes; i++)
		{
			for(int j=0; j<3; j++)
				competencia.deporte_medallas[i][j]=-1; // inicializa la matriz con -1 para comparar posteriormente
		}
		
		competencia.legajo = legajoAct;
		
		
		while(bandera == 0) 
			Menu_Principal(bandera, var_menu, menu_1, menu_2, competencia);
		// imprime el menu en la consola y manda por referencia a la bandera y la variable del menu.
	}
	
	else 
			 fin_programa(); // login = 0, finaliza el programa.
	
	return 0;
}
