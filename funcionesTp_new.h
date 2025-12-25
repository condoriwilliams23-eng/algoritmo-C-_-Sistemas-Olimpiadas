#ifndef FUNCIONESTP_NEW_H
#define FUNCIONESTP_NEW_H
#include <ctime>

#include <string>
using namespace std;

struct competidores
{
	int paises[16]={0};
	
	int tl=0;
};

struct archivoCompetencia 
{
	competidores competencia[87];

	int deporte_medallas[87][3];
	
	tm *fechaCreacion;
	
	int legajo;
};

void gotoxy(int, int );

void reCuadro( int, int, int , int );

void ingreso_Datos(char [], int);

void solicitud();

void Bienvenida();

bool login(int &);

void Menu_Principal(bool &, char &, bool &, bool &, archivoCompetencia &, string &);

void Generar_Com(char &, bool &, archivoCompetencia &, string &);

void Mensaje_cargarVec();

void Mensaje_cargarVec2(archivoCompetencia , string);

void Mensaje_Cargarealizada();

void Mensaje_deCargaInvalido_1();

void Mensaje_deCargaInvalido_2();

void Menu_Medallas(char &, archivoCompetencia &);

bool encontrarX(char [], const int );

void cargar_matriz(competidores [], int [][3], const int);

void Cargar_individuales(competidores [], int [][3], bool &);

void Cargar_colectivos(competidores [], int [][3], bool &);

void medallero_por_pais(int deporte_medallas[87][3]);

void medallero_por_deporte(int deporte_medallas[87][3]);

void top_medallero(int deporte_medallas[87][3]);

void nombre_dep( char  ,int & );

void Menu_TopM( char & var_menu, int deporte_medallas[][3]);

void Menu_Estadistica(char & var_menu,int deporte_medallas[][3] );

void pais_mayor_medallas(int deporte_medallas[][3]);

void lista_de_paise(int  deporte_medallas[][3] );

void mostrarPagina(int pagina, int paisesPorPagina);

void paisMasMedallasInd(int deporte_medallas[][3]);

void podioPrimerLetra(int deporte_medallas[87][3]);

char primercaracter(int i, char carac);

//void medallero_por_pais(int deporte_medallas[87][3]); //habia otro menu igual en la linea 59 

void medallero_por_deporte(int deporte_medallas[87][3]);

void top_medallero(int deporte_medallas[87][3]);

void Confirmar_Salida(bool &, char &, archivoCompetencia, string);

int password(int);

void fin_programa();

#endif
