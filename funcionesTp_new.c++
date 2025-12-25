#include "funcionesTp_new.h"
#include<iostream>
#include <windows.h>
#include <conio.h>
#define numPaises 196
#define totalDeportes 87
#define deportesIndividuales 53
#define deportesColectivos 34
#include <ctime>
#include <cstdlib>
#include "deportes.h"
#include "paises.h"
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

void gotoxy(int x , int y)
{
	HANDLE ventana; // sacado de youtube ya que no supe como utilizar el material dado en el documento...
	ventana = GetStdHandle(STD_OUTPUT_HANDLE);
	
	COORD cordenadas;
	cordenadas.X = x;
	cordenadas.Y = y;
	
	SetConsoleCursorPosition(ventana,cordenadas);
}

void reCuadro(int filasI, int columnasI ,int filasF, int columnasF)
{
	char si=218, ii=192, sd=191, id=217, ancho=196, largo=179;// definimos variables con caracteres especificos para dibujar el recuadro
	
	for(int i=filasI; i<=filasF; i++)
	{
		gotoxy(i,columnasI); // dibuja el techo del recuadro
		cout << ancho;
		gotoxy(i,columnasF); // dibuja el piso del recuadro
		cout << ancho;
	}
	for(int j=columnasI; j<=columnasF; j++)
	{
		gotoxy(filasI, j); // dibuja el costado izquierdo del recuadro
		cout << largo ;
		gotoxy(filasF, j); // dibuja el costado derecho del recuadro
		cout << largo ;
	}
	
	gotoxy(filasI, columnasI); cout<< si; // superior izquierda
	gotoxy(filasI, columnasF); cout<< ii; // inferiror izquierda
	gotoxy(filasF, columnasI); cout<< sd; // superrior derecha
	gotoxy(filasF, columnasF); cout<< id; // inferior dederecha
	
}

int password(int aux)
{
	int aux2, contra=0, cap;// contra almacenara el valor de la contraseña  i y aux ayudaran a calcularla
	
	aux2=((aux/10000)*100)+(((aux/100)%10)*10)+(aux%10); // obtenemos el valor del numero con el 1, 3 y 5 digito de aux y lo almacenamos en aux2. 
	
	cap=aux2+1;
	
	if( cap <= 999) // si es <= a el valor maximo posible(999)...
	{
		while(cap/100 != cap%10)// obtenemos el primer valor capicua mayor a aux2
			++cap;
	}
	
	else // en caso de que sea el valor maximo posible(999) su primer numero capicua mayor es el 1001.
	   cap=1001;
	
	contra = (2024*cap)+(aux%1000);

	return contra; // devolvemos el valor de contra.
}

void ingreso_Datos(char arreglo[], int tamanio)
{
	int i=0; // nos facilita el movernos por el arreglo.
	
	bool cadena=1, tomar_X, asteriscos, archi;
	
	asteriscos = (tamanio == 43) ;
	
	archi = (tamanio == 1);
	
	tomar_X = (tamanio == 33) or (tamanio == 36);
	
	while(cadena)
	{
		char let = _getch();  // Captura un carácter sin mostrarlo en pantalla
		
		if (let == '\r')  // Verifica si el carácter es Enter (carácter de nueva línea)
		{  
			arreglo[i] = 10;  // Añade el carcater de linea nueva.
			
			cadena=0;
		}
		
		else if (let == '\b' && i > 0)  // pertime borrar el caracter ingresado en pantalla.
		{
			i--; 
			
			cout << "\b \b";  // Mueve el cursor hacia atrás y borra el carácter
		}
		
		else if (let != '\b') 
		{
			if(tomar_X)
			{
				if((let >= '0' and let <= '9') or (let == 'X')) // solo permite que se tomen numeros.
				{
					arreglo[i] = let;  // Almacena el carácter en el array
					
					i++;
					
					if (i<=7)
						cout << let;  // imprime el caracter en pantalla.
					
					else
						i--; // disminuye una pocicion para no usar mas espacio del deseado
				}
			}
			
			else if(asteriscos)
			{
				if((let >= '0' and let <= '9') or (let == 'X')) // solo permite que se tomen numeros.
				{
					arreglo[i] = let;  // Almacena el carácter en el array
					
					i++;
					
					if (i<=7)
						cout << "*";  // imprime el caracter en pantalla.
					
					else
						i--; // disminuye una pocicion para no usar mas espacio del deseado
				}
			}
			
			else if(archi == 1)
			{
				if((let >= '0' and let <= '9') or (let == '-') or (let == '.') or (let == 'b') or (let == 'i') or (let == 'n')) // solo permite que se tomen numeros y caracteres validos a usar en el.
				{
					arreglo[i] = let;  // Almacena el carácter en el array
					
					i++;
					
					if (i<24)
						cout << let;  // imprime el caracter en pantalla.
					
					else
						i--; // disminuye una pocicion para no usar mas espacio del deseado
				}
			}
			
			else
			{
				if(let >= '0' and let <= '9') // solo permite que se tomen numeros.
				{
					arreglo[i] = let;  // Almacena el carácter en el array
					
					i++;
					
					if (i<=7)
						cout << let;  // imprime el caracter en pantalla.
					
					else
						i--; // disminuye una pocicion para no usar mas espacio del deseado
				}
			}
		} 
	}
}

void solicitud() // genera un mensaje que solicita poner la pantalla full screen
{
	reCuadro(0, 0, 85,22);
	
	gotoxy(20, 6);
	cout << "Por favor antes de ejecutar el programa,";
	
	gotoxy(20, 8);
	cout << "Ponga la pantalla completa(full screen)";
	
	gotoxy(20, 11);
	
	system("pause");
}

void Bienvenida()
{
	system("cls");
	
	reCuadro(15,0,138,36);
	char cuadro=219; // caracter especifico para dibujar la bandera
	
	// imprime la bandera en la consola
	
	for(int j=1; j<35;j ++)  // columnas
	{
		for(int i=16; i<57; i++) // filas
		{
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),1);
			gotoxy(i,j);
			cout << cuadro;
			
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
			gotoxy(i+41,j);
			cout << cuadro;
			
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),4);
			gotoxy(i+81,j);
			cout << cuadro;
		}
	}
	
	// imprime el mensaje de Bienvenida
	
	// primer renglon
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),3);  
	gotoxy(19,5);
	cout << " #####  # ###### #    # #    # ###### #    # # #####   ####   ####       ##   #         #    # ###### #    # #    # " ;
	gotoxy(19,6);
	cout << " #    # # #      ##   # #    # #      ##   # # #    # #    # #          #  #  #         ##  ## #      ##   # #    # " ;
	gotoxy(19,7);
	cout << " #####  # #####  # #  # #    # #####  # #  # # #    # #    #  ####     #    # #         # ## # #####  # #  # #    # " ;
	gotoxy(19,8);
	cout << " #    # # #      #  # # #    # #      #  # # # #    # #    #      #    ###### #         #    # #      #  # # #    # " ;
	gotoxy(19,9);
	cout << " #    # # #      #   ##  #  #  #      #   ## # #    # #    # #    #    #    # #         #    # #      #   ## #    # " ;
	gotoxy(19,10);
	cout << " #####  # ###### #    #   ##   ###### #    # # #####   ####   ####     #    # ######    #    # ###### #    #  ####  " ;
	
	
	// segundo renglon
	gotoxy(25,16);
	cout << " #####  ######    #        ##    ####      ####  #      # #    # #####  #   ##   #####    ##    ####  ";
	gotoxy(25,17);
	cout << " #    # #         #       #  #  #         #    # #      # ##  ## #    # #  #  #  #    #  #  #  #      ";
	gotoxy(25,18);
	cout << " #    # #####     #      #    #  ####     #    # #      # # ## # #    # # #    # #    # #    #  ####  ";
	gotoxy(25,19);
	cout << " #    # #         #      ######      #    #    # #      # #    # #####  # ###### #    # ######      # ";
	gotoxy(25,20);
	cout << " #    # #         #      #    # #    #    #    # #      # #    # #      # #    # #    # #    # #    # ";
	gotoxy(25,21);
	cout << " #####  ######    ###### #    #  ####      ####  ###### # #    # #      # #    # #####  #    #  ####  ";
	
	
	// tercer renglon.
	gotoxy(44,26);
	cout << "                                   #####    ###    #####  #       ";
	gotoxy(44,27);
	cout << " #####    ##   #####  #  ####     #     #  #   #  #     # #    #  ";
	gotoxy(44,28);
	cout << " #    #  #  #  #    # # #               # #     #       # #    #  ";
	gotoxy(44,29);
	cout << " #    # #    # #    # #  ####      #####  #     #  #####  #    #  ";
	gotoxy(44,30);
	cout << " #####  ###### #####  #      #    #       #     # #       ####### ";
	gotoxy(44,31);
	cout << " #      #    # #   #  # #    #    #        #   #  #            #  ";
	gotoxy(44,32);
	cout << " #      #    # #    # #  ####     #######   ###   #######      #  ";
	
	
	char inicio[50] = {0}; // bandera para cortar el ingreso de datos
	
	gotoxy(65,35);
	cout << "presione 0 para continuar:"; 
	
	while(inicio[0] != '0' or inicio[1] != 10) // cuando inicio sea f se corta el bucle, en caso contrario limpia y solicita una nueva entrada
	{
		gotoxy(91,35);
		cout << "                                               "; // los espacios son para limpiar el ingreso de datos anterior
		
		gotoxy(91,35);
		ingreso_Datos(inicio,48); // obtiene los datos por teclado.
	}
}

bool login(int &legajo)
{
	int contrasenia=0, cont=3, aux;// cont y contraseña se utilizaran para validar la contraseña y como banderas para cortar el ciclo,
	// aux sirve para convertir el numero de usuario a entero.
	
	char User[50]={0}; // Almacena el Nro de usuario.
	
	bool validar=0, D1=0, D2=0;// validar es lo que devolvera la funcion.
	// D1 y D2 se utilizaran como banderas para cortar el ciclo.
	
	reCuadro(15,0,138,36);
	
	// imprime la pantalla de login.
	gotoxy(65,9);
	cout << "Inicio de Sesion";
	
	gotoxy(61,12);
	cout << "=========================";
	
	gotoxy(50,15);
	cout << "Ingresaar un Nro de usuario entre el 10000 y el 99999";
	
	gotoxy(64,18);
	cout << "Usuario:";
	
	gotoxy(63,20);
	cout << "Contrase" << char(164) << "a:";
	
	while(D1 == 0 or D2 == 0)// el bucle se cortara cuando ingrese correctamente el usuario.
	{
		gotoxy(72,18);
		cout << "                                            "; // los espacios son para limpiar el ingreso de datos anterior
		
		gotoxy(72,18);
		
		ingreso_Datos(User,45);
		
		D1 = ( (User[0] >= '1') and (User[0] <= '9') ) and ( (User[1] >= '0') and (User[1] <= '9') ) and ( (User[2] >= '0') and (User[2] <= '9') );
		D2 = ( (User[3] >= '0') and (User[3] <= '9') ) and ( (User[4] >= '0') and (User[4] <= '9') and (User[5] == 10));
		// D1 y D2 verifican que los datos ingresados sean numeros validos.
	}
	
	aux = ((User[0]-'0')*10000) + ((User[1]-'0')*1000) + ((User[2]-'0')*100) + ((User[3]-'0')*10) + ((User[4]-'0'));// convierto en entero el dato ingresado.
	
	legajo = aux;
	
	contrasenia = password(aux); // llamo a password y lo almaceno en contrasenia.
	
	cont = 3;
	
	while(aux != contrasenia and cont > 0) // verifica la contraseña en caso de equivocarse 3 veces se cierra el bucle
	{
		char contra[50] = {0};
		
		gotoxy(74,20);
		cout << "                                          "; // los espacios son utilizados para borrar /sobrecribir el ingreso anterior
		
		if(cont == 1)
		{
			gotoxy(58,23);
			cout << "Este es su ultimo intento restante ..."; // decrementamos cont y visualizamos la cantidad de intentos restantes.
			
			cont--;
		}
		else
		{
			gotoxy(59, 23);
			cout << "Numero de intentos restantes:" << --cont; // decrementamos cont y visualizamos la cantidad de intentos restantes.
		}
		
		gotoxy(74,20);
		
		ingreso_Datos(contra,43);
		
		aux = atoi(contra); // atoi transforma la cadena de caracteres en un entero.
	}
	
	if(aux == contrasenia) 
		  validar = 1;
	
	// si se ingresa correctamente la contraseña ponemos en 1 a validar para entrar al menu principal,
	// en caso contrario validar permanece en 0 y cierra el programa.
	
	return validar; // devolvemos el valor de Menu_Medallas.
}


void Menu_Principal(bool & bandera, char & var_menu, bool & menu_1, bool & menu_2, archivoCompetencia & competencias, string & Nom_archi)
{	
	system("cls");// refresca la consola
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	// imprime el menu principal en la consola.
	gotoxy(66, 8);
	cout << "Menu Principal" << endl;
	
	gotoxy(59, 11);
	cout << " ==========================" << endl;
	
	gotoxy(59,14);
	cout << " 1.- Generar Competencia" << endl;
	
	gotoxy(59, 17);
	cout << " 2.- Cargar Medallas por Deporte" << endl;
	
	gotoxy(59, 20);
	cout << " 3.- Mostrar Medallero" << endl;
	
	gotoxy(59, 23);
	cout << " 4.- Mostrar Estadisticas" << endl;
	
	gotoxy(59, 26);
	cout << " X.- Salir de la aplicacion" << endl;
	
	gotoxy(59, 29);
	cout << " Ingrese una opcion:";
	
	char auxMenu[50] = {0};
	
	while((var_menu != '1') and (var_menu != '2') and (var_menu != '3') and (var_menu != '4') and (var_menu != 'X') ) // si no es la entrada deseada limpia y pide denuevo los datos...
	{
		gotoxy(79,29);
		cout << "                                ";
		
		
		gotoxy(79,29);
		
		ingreso_Datos(auxMenu,33);
		
		if(auxMenu[1] == 10)  // verifica si se ingreso solo 1 digito antes del salto de linea.
			var_menu = auxMenu[0];
		
	}
	
	// casos validos a ejecutar...
	
	if(var_menu == '1' and menu_1 == 0) // imprime el menu de medallas en la consola.
	{
		Generar_Com(var_menu, menu_1,competencias, Nom_archi); // genera las competencia.
		
		int auxnum=0, i=0, j=0;
		
		while(i<totalDeportes and auxnum == 0)//recorremos los podios para saber si ya esta cargados, en caso de estarlo habilitamos los demas menus.
		{
			j=0;
			while(j<2 and auxnum == 0)
			{
				if(competencias.deporte_medallas[i][j] != -1)
					auxnum++;
				
				j++;
			}
			
			i++;
		}
		
		
		if(auxnum != 0) // habilita el menu 3 y 4
			menu_2 = 1;
		
	}
	
	else if(var_menu == '1' and menu_1 == 1)
	{
		Mensaje_Cargarealizada();  // informa al usuario que ya genero/cargo las competencias
		
		var_menu = 0;// resetea el valor de la variable para habilitar el ingreso de datos.
	}
	
	else if(var_menu == '2' and menu_1 == 0) // es cuando el usuario intenta cargar las competencias sin haberlas generado anteriormente.
	{
		Mensaje_deCargaInvalido_1();
		
		var_menu=0; // resetea el valor de la variable para habilitar el ingreso de datos.
	}
	
	else if(var_menu == '2' and menu_1 == 1) // imprime el menu de juegos en la consola.
	{
		Menu_Medallas(var_menu, competencias);
		
		menu_2 = 1; // habilita el ingreso al menu para mostar los ganadores
	}
	
	else if(var_menu == '3' and menu_2 == 0)// es cuando el usuario intenta mostrar las competencias sin haberlas cargado anteriormente.
	{
		Mensaje_deCargaInvalido_2();
		
		var_menu=0; // resetea el valor de la variable para habilitar el ingreso de datos.
	}
	
	else if(var_menu == '3' and menu_2 == 1) // imprime el menu de juegos en la consola.
	{
		Menu_TopM(var_menu, competencias.deporte_medallas); // ingresa al menu mostar medallero
		
	}
	
	else if(var_menu == '4' and menu_2 == 0) // es cuando el usuario intenta mostrar  sin haberlas cargado anteriormente
	{
		Mensaje_deCargaInvalido_2();
		
		var_menu=0; // resetea el valor de la variable para habilitar el ingreso de datos.
	}
	
	else if(var_menu == '4' and menu_2 == 1)
	{
		Menu_Estadistica(var_menu,competencias.deporte_medallas);
		
		var_menu = 0;
	}
	
	else if(var_menu == 'X') // comfirma la salida o vuelve al menu principal.
		Confirmar_Salida(bandera, var_menu, competencias, Nom_archi);
}

void encontrarN(char nomFich[], int tam)
{
	if(tam == 0 or nomFich[tam] == 'n') // recorre la cadena recursivamente hasta llegar a 0 o encontrar la n del archivo
		return;
	else
	{
		nomFich[tam--] = 0;
		
		encontrarN(nomFich, tam);
	}
}

void Generar_Com(char & var_menu, bool & menu_1, archivoCompetencia & competencias, string & Nom_archi)
{ 
	system("cls");// refresca la consola
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	// imprime el menu de carga de competencia en la consola.
	gotoxy(60, 8);
	cout << "Menú Generar Competencia " << endl;
	
	gotoxy(54, 11);
	cout << " ==================================" << endl;
	
	gotoxy(59,14);
	cout << " 1.- Generar Competencia " << endl;
	
	gotoxy(61, 17);
	cout << "2.- Cargar Competencia " << endl;
	
	gotoxy(57, 20);
	cout << " X.- Salir de la aplicacion" << endl;
	
	gotoxy(59, 22);
	cout << " Ingrese una opcion:";
	
	char auxGen[50] = {0}, Elec = 0;

	while((Elec != '1') and (Elec != '2') and (Elec != 'X') ) // si no es la entrada deseada limpia y pide denuevo los datos...
	{
		gotoxy(79,22);
		cout << "                                ";
		
		
		gotoxy(79,22);
		
		ingreso_Datos(auxGen,33);
		
		if(auxGen[1] == 10)  // verifica si se ingreso solo 1 digito antes del salto de linea.
			Elec = auxGen[0];
		
	}	
	
	if(Elec == '1')// si el usuario decide generar una competencias
	{
		time_t ahora;
		
		time(&ahora);
		
		competencias.fechaCreacion = localtime(&ahora); //obtengo la informacion de el tiempo actual para generar el nombre del archivo
		
		competencias.fechaCreacion->tm_mon++;
		
		competencias.fechaCreacion->tm_year += 1900;
		
		Nom_archi += std::to_string(competencias.fechaCreacion->tm_year);
		
		Nom_archi += '-';
		
		Nom_archi += std::to_string(competencias.fechaCreacion->tm_mon);
		
		Nom_archi += '-';
		
		Nom_archi += std::to_string(competencias.fechaCreacion->tm_mday);
		
		Nom_archi += '-';
		
		Nom_archi += std::to_string(competencias.fechaCreacion->tm_hour);
		
		Nom_archi += '-';
		
		Nom_archi += std::to_string(competencias.fechaCreacion->tm_min);
		
		Nom_archi += '-';
		
		Nom_archi += std::to_string(competencias.fechaCreacion->tm_sec);
		
		Nom_archi += '.';
		
		Nom_archi += "bin";
		
		ofstream archi(Nom_archi.c_str(), ios::binary); // abrimos el archivo binario
		
		if(!(archi.fail())) // nos ayuda a ver si se abrio correctamente el archivo
		{
			srand(time(NULL)); // planta la semillaa
			
			for(int i=0; i<totalDeportes; i++)
			{
				competencias.competencia[i].tl = 4 + rand()%13;// genera un valor aleatorio desde el 4 al 16 y lo almacena en la variable asignada,
				
				int id_ocupada[numPaises]={0}; // cada ves que se ingresa al bucle for principal se crea y se usa para ver paises repetidos.
				
				for(int j=0; j<competencias.competencia[i].tl; j++)
				{
					do
					{
						competencias.competencia[i].paises[j] = rand()%numPaises; // genera un valor entre el 0 y el numero de paises - 1 uno por cada id de cada pais.
					}
					while(!(id_ocupada[competencias.competencia[i].paises[j]] == 0 )); // verifica si el id ya a sido ingresado anteriormente.
					
					id_ocupada[competencias.competencia[i].paises[j]] = 1; // pone en 1 para no repetir el valor de id.
				}
				
			}
			
			archi.write((char *)(& competencias), sizeof(competencias)); // escribimos los datos en el archivo
			
			archi.close(); //cerramos el archivo para evitar posibles problemas 
			
			Mensaje_cargarVec(); // imprime un mensaje que la carga de competiciones se completo exitosamente.
			
			var_menu = 0;
			
			menu_1 = 1;
		}
		
		else
		{
			gotoxy(57, 24);
			cout << "Error al generar la competencia." << endl;
			
			system("pause");
		}
	}
	
	else if(Elec == '2')
	{ 
		ifstream archi;
		
		char ObtNom[50]={0};
		
		gotoxy(54, 22);
		cout << " Ingrese el nombre del archivo:";
		
		ingreso_Datos(ObtNom, 1); // obtenemos el nombre del archivo a abrir
		
		encontrarN(ObtNom, 25); // sacamos el /n para poder abrirlo correctamente
		
		Nom_archi = ObtNom; //pasamos la cadena tipo c a string para mayor comodidad
		
		archi.open(Nom_archi, std::ios::binary | std::ios::in); // abrimos el archivo para leer la infromacion en la variable competencia 
		
		if(archi.is_open()) // verifica si existe el archivo
		{
			archi.read((char *)(& competencias), sizeof(competencias)); // obtenemos la informacion y la almacenamos en competencias
			
			archi.close(); // cerramos el archivo para evitar problemas
			
			Mensaje_cargarVec2(competencias, Nom_archi); // imprime un mensaje que la carga de competiciones se completo exitosamente.
			
			var_menu = 0;
			
			menu_1 = 1;
		}
		else
		{
			gotoxy(40, 24);
			cout << "El archivo dado no existe o no se ha podido abrir correctamente." << endl;
			
			gotoxy(54, 26);
			
			system("pause");
		}
	}
	else
		var_menu = 0;	//esto solo ocurrira cuando elija la x para volver a menu principal
}

void Mensaje_cargarVec() // informa al usuario que se a cargado el vector correctamente
{
	system("cls");
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	gotoxy(55, 13);
	cout << "Competiciones generadas correctamente."; 
	
	gotoxy(64, 17);
	cout << "Gracias por la espera.";
	
	gotoxy(54,20);
	system("pause");
}

void Mensaje_cargarVec2(archivoCompetencia competencias, string fechas) // informa al usuario que se a cargado el vector correctamente
{
	system("cls");
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	gotoxy(55, 13);
	cout << "Competiciones cargadas correctamente."; 
	
	gotoxy(50, 15);
	cout << "Nro de legajo del creador del archivo: " << competencias.legajo ; // imprime por pantalla el legajo del creador del archivo
	
	gotoxy(48,17);
	cout << "Fecha de creacion del archivo: " << fechas; // imprime la fecha de creacion del archivo
	
	gotoxy(98,17);
	cout << "     ";
	
	gotoxy(63, 19);
	cout << "Gracias por la espera.";
	
	gotoxy(54,21);
	system("pause");
}

void Mensaje_Cargarealizada() // informa al usuario que ya genero la competencia con anterioridad y solicita una opcion diferente
{
	system("cls");
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	gotoxy(55, 13);
	cout << "Ya se han generado/cargado las competencias.";
	
	gotoxy(45, 16);
	cout << "Por favor ingrese los datos de los ganadores o su muestra por pantalla.";
	
	gotoxy(54,19);
	system("pause");
}

void Mensaje_deCargaInvalido_1() // informa al usuario la valides de su ingreso
{
	system("cls");
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	gotoxy(55, 13);
	cout << "No es posible acceder al menu seleccionado,";
	
	gotoxy(40, 16);
	cout << "Por favor genere la competencias para poder acceder al menu selecionado.";
	
	gotoxy(54,19);
	system("pause");
}

void Mensaje_deCargaInvalido_2() // informa al usuario la valides de su ingreso
{
	system("cls");
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	gotoxy(55, 13);
	cout << "No es posible acceder al menu seleccionado,";
	
	gotoxy(47, 16);
	cout << "Por favor cargue la competencais para poder acceder al menu.";
	
	gotoxy(56,19);
	system("pause");
}


void Menu_Medallas( char & var_menu, archivoCompetencia & competencias)
{
	system("cls");// refresca la consola
	
	reCuadro(15,0,138,37);// dibuja el recuadro
	
	// imprime el menu principal en la consola.
	gotoxy(57, 8);
	cout << "Menu Carga Medallas por Deporte" << endl;	
	
	gotoxy(58, 11);
	cout << " ==========================" << endl;
	
	gotoxy(55,15);
	cout << " 1.- Cargar por Deporte Individual" << endl;
	
	gotoxy(55, 19);
	cout << " 2.- Cagar por Deporte Colectivo" << endl;
	
	gotoxy(55, 23);
	cout << " X.- Volver al menu principal" << endl;
	
	gotoxy(58, 27);
	cout << " Ingrese una opcion:";
	
	char numeroCorrecto[50] = {0}, var_medallas = 0;
	
	
	while((var_medallas != '1') and var_medallas != '2' and (var_medallas != 'X')) // si no es la entrada deseada limpia y pide denuevo los datos...
	{
		gotoxy(78,27);
		cout << "                                   ";
		
		gotoxy(78,27);
		
		ingreso_Datos(numeroCorrecto, 36);
		
		if(numeroCorrecto[1] == 10)  // verifica si se ingreso solo 1 digito antes del salto de linea.
			var_medallas = numeroCorrecto[0];
	}
	
	if(var_medallas != 'x' and var_medallas != 'X') // si es distinto de x y X varifica el dato ingresado
	{
		bool lup = 0;
		
		while((var_medallas == '1' or var_medallas == '2') and lup == 0 ) 
		{			
			if(var_medallas == '1')
			{
				Cargar_individuales(competencias.competencia, competencias.deporte_medallas, lup);//llamo a la funcion deporte individual
				
				if(lup == 1)
					var_medallas = 0;
			}
			
			else if(var_medallas == '2')
			{
				Cargar_colectivos(competencias.competencia, competencias.deporte_medallas, lup);//llamo a la funcion deporte colectivo 
				
				if(lup == 1)
					var_medallas = 0;
			}
		}
	}
	else
	   var_menu = 0;//vuelve al menu principal
	
}

bool encontrarX(char cadenas[], const int tl) // busca y informa con 1 si encruentra una X
{
	bool esta=0;
	
	for(int i=0; i<tl; i++)
	{
		if(cadenas[i] == 'X')
			esta=1;
	}
	
	return esta;
}

void Cargar_individuales(competidores competencia[], int deporte_medallas[][3], bool & lup)
{
	system("cls");
	
	char ver = 'd';// pasaje por parametro para determinar el id del deporte
	
	char var = 'c'; //para pasaje por parametro pra mostrar el nombre del deportes
	
	int aux[totalDeportes]={0}; // variable usada validar los deporte ingresados
	
	reCuadro(15,0,138,38);//recuadro de deportesIndividuales
	
	reCuadro(62,1,83 ,3);//recuadro para el titulo
	gotoxy(63,2);
	cout << "DEPORTES INDIVIDUALES"<<endl;
	
	gotoxy(17,4);
	cout<<"ID:   Deporte:                                            ID:   Deporte:  ";
	
	
	gotoxy(31,36);
	cout << "Podios cargados:";
	gotoxy(31,37);
	cout << "Podios cargados:";
	
	int pasos1=17+16+15, pasos2=17+16+15; // nos ayudan a contar los espacios donde van los podios cargados/sin cargar.
	
	for(int i=0; i<deportesIndividuales; i++)//mostrar Deportes	individuales.
	{	
		int num = i;
		if(i < deportesIndividuales/2 )
		{
			nombre_dep(ver, num);// pasa el id del deporte por referencia en " num "
			
			if(deporte_medallas[num-1][0] == -1 and deporte_medallas[num-1][1] == -1 and deporte_medallas[num-1][2] == -1)// si el podio no esta cargado lo informa con un --
			{
				gotoxy(pasos1+i,36);
				cout << "--" ;
				
				gotoxy(pasos1+i+2,36);
				cout << ",";
			}
			else // si el podio esta cargado imprime el id del deporte
			{
				gotoxy(pasos1+i,36);// mustra por pantalla los podios cargados
				cout << num ;
				
				gotoxy(pasos1+i+2,36);
				cout << ",";
			}
			
			gotoxy(17,i+6);
			cout << num<<".....";//muestra en pantalla el id del deporte 
			
			
			nombre_dep(var, num );// muestra el deporte en pantalla 
			
			pasos1 += 2; 
		}
		else
		{
			nombre_dep(ver, num);// para el id del deporte por referencia en " num "
			
			if(deporte_medallas[num-1][0] == -1 and deporte_medallas[num-1][1] == -1 and deporte_medallas[num-1][2] == -1)// si el podio no esta cargado lo informa con un --
			{
				gotoxy(pasos2+i- deportesIndividuales/2,37);
				cout << "--" ;
				
				gotoxy(pasos2+i+2- deportesIndividuales/2,37);
				cout << ",";
			}
			else // si el podio esta cargado imprime el id del deporte
			{
				gotoxy(pasos2+i-deportesIndividuales/2,37); // mustra por pantalla los podios cargados
				cout << num ;
				
				gotoxy(pasos2+i+2-deportesIndividuales/2,37);
				cout << ",";
			}
			
			gotoxy(75,i-20);
			cout << num<<".....";//muestro el ID del deporte. 
			nombre_dep(var, num );// muestra el deporte 
			
			pasos2 += 2;
		}
		aux[num-1]++; // carga el vector aux con los indices de los deportes individuales
	}
	
	char id_dep[50]={0}; // variable para el ingreso de datos
	
	int aux_deporte;
	
	do
	{
		gotoxy(54,35);
		cout << "                                                                                "; // limpia la pantalla
		
		for(int i=0; i<50; i++)
			id_dep[i]=0;
		
		gotoxy(55,35);
		cout << "si desea volver al menu anterior ingrese X."; // info para el usuario
		
		gotoxy(76,34);
		cout <<"                                         ";
		
		gotoxy(68,34);
		cout << "Ingrese un ID:";
		
		ingreso_Datos(id_dep, 36);	//ingreso de dato (id del deporte)
		
		if(atoi(id_dep) > totalDeportes or (encontrarX(id_dep, 50) and id_dep[0] != 'X' ))
		{
			
			aux_deporte = 12; // id que no pertenece a deporte individual
			gotoxy(54,35);
			cout  << "ID fuera de rango...." ; 
			system("pause");
		}
		else
		{
			aux_deporte = atoi(id_dep); //almacena el valor ingresado en la variable para comparar despues 
		}
		
	} while(aux[(aux_deporte)-1] == 0 and id_dep[0] != 'X');// verifiva el ingreso de datos 
	
	if(id_dep[0] == 'X' and id_dep[1] == '\n')
		lup=1;// vuelve al menu de medallas;
	
	else // si ingreso un id correcto
	{
		if(deporte_medallas[atoi(id_dep)-1][0] == -1 and deporte_medallas[atoi(id_dep)-1][1] == -1 and deporte_medallas[atoi(id_dep)-1][2] == -1)//verifica si no se repite el digito de entrada 
		{
			gotoxy(45,35);
			cout <<"El ID ingresado es correcto. ";
			system("pause");
			
			cargar_matriz(competencia, deporte_medallas, atoi(id_dep)-1); // carga la matriZ
		}	
		
		else //muestra q se repitio el id o el ingreso de un id invalido
		{
			if(id_dep[0] == 'X' and id_dep[1] != '\n')
			{
				gotoxy(45,35);
				cout <<"El ID ingresado es incorrecto. ";
				system("pause");
			}
			else
			{
				gotoxy(45,35);
				cout << "Este podio ya fue cargado. ";
				system("pause");
			}
		}
	}
}

void Cargar_colectivos(competidores competencia[], int deporte_medallas[][3], bool & lup)
{
	//basicamente lo mismo que Cargar_individuales pero con deportes colectivos
	
	system("cls");
	
	char var = 'c';//para pasaje por parametro pra mostrar el nombre del deporte
	
	char ver = 'a';// pasaje por parametro para determinar el id del deporte
	
	int aux[totalDeportes]={0}; 
	
	reCuadro(15,0,138,37);//recuadro de deportesColectivos
	
	reCuadro(62,1,83 ,3);//recuadro para el titulo
	
	
	gotoxy(64,2);
	cout << "DEPORTES COLECTIVOS";
	
	gotoxy(17,5);
	cout<<"ID:       Deporte:                                        ID:      Deporte:  "  ;
	
	
	gotoxy(16+30,34);
	cout << "Podios cargados:";
	gotoxy(16+30,35);
	cout << "Podios cargados:";
	
	int pasos1=17+16+30, pasos2=17+16+30;// nos ayudan a contar los espacios donde van los podios cargados
	
	for(int i=0; i<deportesColectivos; i++)//mostrar deportes colectivos.
	{
		int num = i;
		if(i < deportesColectivos/2 )
		{
			nombre_dep(ver, num);// para el id del deporte por referencia en " num "
			
			if(deporte_medallas[num-1][0] == -1 and deporte_medallas[num-1][1] == -1 and deporte_medallas[num-1][2] == -1)
			{
				gotoxy(pasos1+i,34);
				cout << "--" ;
				
				gotoxy(pasos1+i+2,34);
				cout << ",";
			}
			else
			{
				gotoxy(pasos1+i,34); // imprime por pantalla los podios cargados.
				cout << num ;
				
				gotoxy(pasos1+i+2,34);
				cout << ",";
			}
			
			gotoxy(17,i+7);
			cout << num<<"........";
			
			nombre_dep(var, num );// muestra el deporte   
			
			pasos1 += 2;
		}
		else
		{
			nombre_dep(ver, num);// para el id del deporte por referencia en " num "
			
			if(deporte_medallas[num-1][0] == -1 and deporte_medallas[num-1][1] == -1 and deporte_medallas[num-1][2] == -1)
			{
				gotoxy(pasos2+i- deportesColectivos/2,35);
				cout << "--" ;
				
				gotoxy(pasos2+i+2- deportesColectivos/2,35);
				cout << ",";
			}
			else
			{
				gotoxy(pasos2+i-deportesColectivos/2,35);
				cout << num ;
				
				gotoxy(pasos2+i+2-deportesColectivos/2,35);
				cout << ",";
			}
			
			gotoxy(75,i-10);
			cout << num<<".......";//muestro el ID del deporte. 
			nombre_dep(var, num );// muestra el nombre deporte 
			
			pasos2 += 2;
		}
		aux[num-1]++; // carga el vector aux con los indices de los deportes individuales
	}
	
	char id_dep[50]={0}; // variable para el ingreso de datos
	
	int aux_deporte;
	
	do
	{
		gotoxy(55,31);
		cout << "si desea volver al menu anterior ingrese X.";
		
		for(int i=0; i<50; i++)
			id_dep[i]=0;
		
		// agregar una funcion que informe al usuario si ingreso mal el id y su debido aparatado visual
		gotoxy(79,28);
		cout <<"                                                        ";
		
		gotoxy(68,28);
		cout << "Ingrese un ID:";
		
		
		ingreso_Datos(id_dep, 36);	//ingreso de datos 
		
		if(atoi(id_dep) > totalDeportes or (encontrarX(id_dep, 50) and id_dep[0] != 'X' ))//verifica q la entrada pertenesca al rango 
		{
			
			aux_deporte = 82; // id que no pertenece a deporte individual
			
			gotoxy(68,29);
			cout << "ID fuera de rango"; 
			
		}
		else
		{
			aux_deporte = atoi(id_dep);
		}
		
	} while(aux[(aux_deporte)-1] == 0 and id_dep[0] != 'X');// verifiva el ingreso de datos 
	
	if(id_dep[0] == 'X')
		lup=1;// vuelve al menu de medallas;
	
	else // si ingreso un id correcto
	{
		if(deporte_medallas[atoi(id_dep)-1][0] == -1 and deporte_medallas[atoi(id_dep)-1][1] == -1 and deporte_medallas[atoi(id_dep)-1][2] == -1)//verifica si no se repite el digito de entrada
		{
			gotoxy(45,29);
			cout << "                                                               ";
			
			gotoxy(65,29);
			cout <<"El ID ingresado es correcto. ";
			
			gotoxy(60,30);
			system("pause");
			
			cargar_matriz(competencia, deporte_medallas, atoi(id_dep)-1); // carga la matriz
			
		}
		
		else//muestra q ya se utilizo el id anteriormente o es invalid0
		{
			if((id_dep[0] == 'X' and id_dep[1] != '\n'))
			{
				gotoxy(45,29);
				cout << "                                                               ";
				
				gotoxy(65,29);
				cout <<"El ID ingresado es incorrecto. ";
				
				gotoxy(60,30);
				system("pause");
			}
			
			else
			{
				gotoxy(45,29);
				cout << "                                                               ";
				
				gotoxy(65,29);
				cout <<"Este podio ya fue cargado.";
				
				gotoxy(65,30);
				cout <<"Ingrese el id de un deporte sin cargar";
				
				gotoxy(60,31);
				system("pause");
			}
		}
	}
}

void cargar_matriz(competidores competencia[], int deporte_medallas[][3], const int deporte)// deporte hace referencia al deporte eleguido a caragar
{
	int  aux[3]={0}, cont=0, pais[numPaises]={0}; 
	
	char var = 'c';//por pasaje por parametro para moetrar el nombre del deporte 
	
	int num = deporte+1;
	
	system("cls");
	
	gotoxy(19,9);
	nombre_dep(var,num);//muestro en pantalla el nombre del deporte..
	
	reCuadro(15,0,138,36);//recuadro de asignar medalla.
	
	gotoxy(19,12);
	
	cout << "ID                     Nombre:  ";
	
	for(int i=0; i<competencia[deporte].tl; i++) //muestro los paises q participan 
	{
		gotoxy(19,i+14);
		cout<< competencia[deporte].paises[i]+1; // mustra el ID del pais
		
		gotoxy(23,i+14);
		cout << "----------------->";
		
		gotoxy(23+19,i+14);
		imprimirPais(competencia[deporte].paises[i] + 1);// muestra el nombre del pais y sumamaos uno para que imprimirPais no se salga del rango
		
		pais[competencia[deporte].paises[i]]++; 	// ingresa el id del pais en la competencia y aumenta en 1 para comparar despues.
	}
	
	char aux_matriz[50];
	gotoxy(75,14);
	cout << " Cargar las Medalla:"<<endl;
	
	do
	{
		gotoxy(80,30);
		cout << "si desea volver al menu anterior ingrese X.";
		
		for(int i=0; i<50; i++)
			aux_matriz[i]=0;
		
		gotoxy(96,14);
		cout <<"                                         ";//limpia lo escrito
		
		// mostra los id de los paises con una funcion, podes sacar los id de competencia[deporte];
		// y borrar el ingreso de datos invalido y informar al ususario
		gotoxy(96,14);
		ingreso_Datos(aux_matriz,36);//ingresos de datos del ID del pais 
		
		if( (atoi(aux_matriz)-1 <= numPaises-1 and atoi(aux_matriz)-1 >= 0) and !(encontrarX(aux_matriz, 50)) )//verifica si pertece al rango
		{
			
			
			if(pais[atoi(aux_matriz)-1] == 1)
			{
				
				aux[cont] = atoi(aux_matriz)-1;
				
				pais[atoi(aux_matriz)-1] = 0; // evita que se ingrese mas de 1 vez el mismo id; 
				
				if(cont == 0)
				{
					gotoxy(76,18);
					cout <<"ORO: ";
					imprimirPais(atoi(aux_matriz));//imprime el pais q gano la medalla
				}
				
				else if( cont == 1)
				{
					gotoxy(76,20);
					cout <<"PLATA: ";
					imprimirPais(atoi(aux_matriz));//imprime el pais q gano la medalla
				}
				   else
				   {
					   gotoxy(76,22);
					   cout <<"BRONCE: ";
					   imprimirPais(atoi(aux_matriz));//imprime el pais q gano la medalla
					   
					   gotoxy(96,15);
					   cout <<"                                      ";//limpia lo escrito
					   
				   }
				   cont++;//para las medallas 
			}
			else
			{
				gotoxy(76,16);
				cout << "                 ";
				
				gotoxy(76,16);
				cout << "ID invalido";
			}
		}
		else
		{
			gotoxy(76,16);
			cout << "                 ";
			
			gotoxy(76,16);
			cout << "ID fuera de rango"; 
		}
	} while(cont < 3 and (aux_matriz[0] != 'X'));//verifica el ingreso del ID del pais
	
	if(cont == 3)
	{
		for(int i=0; i<3; i++)
		{
			deporte_medallas[deporte][i] = aux[i];//carga la matriz deporte_medallas [][]
		}
		gotoxy(19,33);
		system("pause");// esta esta para ver si funca despues sacalo
		
	}
}


void Menu_TopM( char & var_menu, int deporte_medallas[][3])
{
	system("cls");// refresca la consola
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	gotoxy(65, 8);// dibuja el recuadro
	cout << "Menu Medallero" << endl;//dibuja el menu juegos en la pantalla.
	
	gotoxy(58, 11);
	cout << " ==========================" << endl;
	
	gotoxy(56, 14);
	cout << " 1.- Medallero por Pais" << endl;
	
	gotoxy(56, 17);
	cout << " 2.- Medallero por Deporte" << endl;
	
	gotoxy(56, 20);
	cout << " 3.- Top Medallero" << endl;
	
	gotoxy(56, 23);
	cout << " X.- Volver al menu principal"<<endl;
	
	gotoxy(59, 26);
	cout<< "Ingrese una opcion:";
	
	char dato=0, auxDato[50] = {0};
	
	while((dato != '1') and (dato != '2') and (dato != '3') and (dato != 'X'))
	{
		gotoxy(78,26);
		cout << "                                 ";
		
		gotoxy(78, 26);
		
		ingreso_Datos(auxDato,33);
		
		if(auxDato[1] == 10)
			dato = auxDato[0];
	}
	
	switch(dato)
	{
	case '1':
		medallero_por_pais( deporte_medallas);
		break;
	case '2':
		medallero_por_deporte(deporte_medallas);
		break;
	case '3':
		top_medallero(deporte_medallas);
		break;
	case 'X':
		var_menu=0;
		break;
	}
}
void medallero_por_pais(int deporte_medallas[][3])
{
	system("cls");
	reCuadro(15,0,138,36);
	int i,x,altura=5;
	int medallas_paises[numPaises][3]={0};
	for(i = 0; i < totalDeportes; i++) {//i se establece para el for
		for(int j=0;j<3;j++){
			if(deporte_medallas[i][j]>=0){
				x=deporte_medallas[i][j];//x toma el valor del id del pais que se encuentra en esa posicion de la matriz
				medallas_paises[x][j]++;//en medallas paises en la posicion x(que en este caso representa el id del pais) y en la posicion j, se suma una medalla para ese pais
			}
		}
	}
	reCuadro(69,1,88,3);
	gotoxy(70,2);
	cout<<"Medallero por pais"<<endl;
		int max,g=totalDeportes,aux;
			while(g>0){//g ayuda a que no se muestren los paises repetidos
				max=0;//establezco max en cero para que no tome valor basura y pueda tomar el valor del pais con mas medallas.
				for(i=0;i<numPaises;i++){
					aux=((medallas_paises[i][0]*89*89)+(medallas_paises[i][1]*88)+(medallas_paises[i][2]));//establezco la cantidad de medallas como un sistema de puntos que lleva los casos al extremo asi no me desordena los paises.
					if(aux>max){
						max=aux;//establezco max en la posicion del pais con mas puntos totales y lo comparo con aux para ver si es el mayor puntaje o no.
					}
				}
				for(int h=0;h<numPaises;h++){
					if(altura==27){//este algoritmo me permite refrescar la pantalla cuando el texto a mostrar no sea soportado por el reCuadro.
						gotoxy(35,altura+1);
						cout<<"pagina terminada. ";//pongo el mensaje de pantalla terminada y al lado sale el mensaje de presione una tecla para continuar.
						gotoxy(53,altura+1);
						system("pause");
						system("cls");
						reCuadro(15,0,138,36);
						reCuadro(69,1,88,3);
						gotoxy(70,2);
						cout<<"Medallero por pais"<<endl;
						altura=5;
						
					}
					if(((medallas_paises[h][0]*89*89)+(medallas_paises[h][1]*88)+(medallas_paises[h][2]))==max and (medallas_paises[h][0]>0 or medallas_paises[h][1]>0 or medallas_paises[h][2]>0)){//compara medallas paises con max para imprimirlo por pantalla
						gotoxy(22,altura);
						cout<<". . . . . . . . . . . . . . . . ";
						gotoxy(22,altura);
						imprimirPais(h+1);//imprime el pais en el espacio h, que es el pais que tiene mas medallas en todas las posiciones
						gotoxy(52	,altura);
						cout<<" ganó el oro "<<medallas_paises[h][0]<<" vez(es), ganó la plata "<<medallas_paises[h][1]<<" vez(es), ganó el bronce "<<medallas_paises[h][2]<<". ("<<(medallas_paises[h][0]+medallas_paises[h][1]+medallas_paises[h][2])<<" en total)"<<endl;
						medallas_paises[h][0]=0;//establezco toda la matriz de la posicion h para que no se vuelva a mostrar.
						medallas_paises[h][1]=0;
						medallas_paises[h][2]=0;
						altura++;//aumento la altura en uno para que no se superpongan los textos por el gotoxy.
					}
				}
				g--;
			}
	gotoxy(35,altura+1);
	system("pause");
}
void medallero_por_deporte(int deporte_medallas[87][3])
{
	system("cls");
	int num;
	int aux=4;
	int posicion=4;//pasa la cordenadas de las columnas
	reCuadro(15,0,139,36);
	gotoxy(16,1);
	cout<<"Deportes Individuales: "<<endl;
	
	for(int i=0; i<deportesIndividuales ;i++){//nombra los ganadores por derporte 
		
		num=i;
		
		nombre_dep('d',(num));//asigno a num el ID del deporte individual
		
		if( !(deporte_medallas[num-1][0] == -1 and deporte_medallas[num-1][1] == -1 and deporte_medallas[num-1][2] == -1))
		{	
			gotoxy(16,posicion++);
			cout<<"el ID:"<<num<<".. nombre: ";//imprimo el ID en pantalla
			nombre_dep('c',(num));//imprime en pantalla el nombre del deporte 
			
			for(int j =0 ; j<3 ;j++){
				
				gotoxy(16,posicion++);
				cout<<(j+1)<<"°er lugar:   "; 
				imprimirPais(deporte_medallas[num-1][j]+1);//imprim en pantalla el nombre del pais
				aux++;
			}
			aux++;
		}
		if(aux==28){
			gotoxy(35,35);//cuando se esta por terminar el recuadro, reinicio pagina para que me muestre la siguiente pagina
			cout<<"pagina terminada ";
			gotoxy(53,35);
			system("pause");
			system("cls");
			reCuadro(15,0,139,36);
			gotoxy(16,1);
			cout<<"Deportes Individuales: "<<endl;//llamo en las mismas posiciones a las funciones
			aux=4;//reseteo aux en 4 para que me muestre en los mismos lugares.
			posicion=4;
		}
	}
	if(num>=deportesIndividuales){
		gotoxy(16,35);
		cout<<"Terminaron los deportes individuales, para ver los colectivos, ";
		gotoxy(80,35);
		system("pause");
	}
	system("cls");
	reCuadro(15,0,139,36);
	gotoxy(16,1);
	cout <<"Deportes Colectivos:";
	aux=4;
	posicion=4;//para las poscisiones de los deportes
	for(int d=0 ; d< deportesColectivos; d++){
		num=d;
		
		nombre_dep('a',num);//asigno a num el ID del deporte individual
		
		if( !(deporte_medallas[num-1][0] == -1 and deporte_medallas[num-1][1] == -1 and deporte_medallas[num-1][2] == -1))//verifica si no se repite el digito de entrada
		{	
			gotoxy(16,posicion++);
			cout<<"el ID:"<<num<<".. nombre: ";//imprimo el ID en pantalla
			nombre_dep('c',num);//imprime en pantalla el nombre del deporte 
			
			for(int j =0 ; j<3 ;j++){
				
				gotoxy(16,posicion++);
				cout<<(j+1)<<"°er lugar:   "; //muestro las posiciones.
				imprimirPais(deporte_medallas[num-1][j]+1);//imprim en pantalla el nombre del pais
				aux++;
			}
			aux++;
		}
		if(aux==28){
			gotoxy(35,35);//cuando se esta por terminar el recuadro, reinicio pagina para que me muestre la siguiente pagina
			cout<<"pagina terminada, ";
			gotoxy(53,35);
			system("pause");
			system("cls");
			reCuadro(15,0,139,36);
			gotoxy(16,1);
			cout<<"Deportes colectivos: "<<endl;//llamo en las mismas posiciones a las funciones
			aux=4;//reseteo aux en 4 para que me muestre en los mismos lugares.
			posicion=4;
		}
	}
	gotoxy(16,35);
	system("pause");
}	
void top_medallero(int deporte_medallas[][3])
{
	system("cls");
	char aux_ingres[200]={0};//para los datos de entrada.
	reCuadro(15,0,138,36);
	int max=0,aux,i,x,h=0;//i se establece para el for y x para tomar el valor del id del pais
	int medallas_paises[numPaises][3]={0};
	for(i = 0; i < totalDeportes; i++) {
		for(int j=0;j<3;j++){
			if(deporte_medallas[i][j]>=0){
				x=deporte_medallas[i][j];//x toma el valor del id del pais que se encuentra en esa posicion de la matriz
				medallas_paises[x][j]++;//en medallas paises en la posicion x(que en este caso representa el id del pais) y en la posicion j, se suma una medalla para ese pais
			}
		}
	}
	gotoxy(16,1);
	cout<<"ingrese la cantidad de paises del TOP a visualizar: "<<endl;
	int n;//n se utiliza para ingresar la cantidad del top que se quiere visualizar
	gotoxy(16,2);
	ingreso_Datos(aux_ingres,45);
	n = atoi(aux_ingres);
	
	while(n<0 or n>numPaises or aux_ingres[0] == '\n'){ // verifica que el ingreso sea correcto
			gotoxy(16,2);
			cout<<"ingrese un numero valido:                         "<<endl;
			gotoxy(41,2);
			ingreso_Datos(aux_ingres,45);
			n = atoi(aux_ingres);
	}
	for(int j=0;j<n;j++){
		for(i=0;i<numPaises;i++){
			int suma_medallas=(medallas_paises[i][0]+medallas_paises[i][1]+medallas_paises[i][2]);//suma_medallas sirve para sumar las medallas de un pais
			if(suma_medallas>max and suma_medallas>0 ){//comparamos max con suma_medallas, y si suma_medallases mayor, establece a max su valor
				max=suma_medallas;
				aux=i;//aux toma la posicion del pais con mayor numero de medallas
			}
		}
		if(max>0){
			gotoxy(16,h+3);
			cout<<"TOP N°"<<(j+1)<<": ";
			gotoxy(25,h+3);
			cout<<". . . . . . . . . . . . . . . ";
			gotoxy(25,h+3);
			imprimirPais(aux+1);//imprime el pais tomado en la posicion aux
			gotoxy(50,h+3);
			cout<<" con "<<max<<" medallas("<<medallas_paises[aux][0]<<" de oro, "<<//aca muestra tambien la cantidad de medallas ganadas por el pais y cuantas de cada posicion ganadas
				medallas_paises[aux][1]<<" de plata y "<<medallas_paises[aux][2]<<" de bronce). "<<endl;
				max=0;//establece a max en cero para que no tome otro valor como maximo
				medallas_paises[aux][0]=0;//establezco la matriz del pais en la posicion i para que no se tome encuenta de nuevo
				medallas_paises[aux][1]=0;
				medallas_paises[aux][2]=0;
				if(j+3==32 or j+3==64 or j+3==96 or j+3==128 or j+3==160 or j+3==192){
					gotoxy(35,33);//cuando se esta por terminar el recuadro, reinicio pagina para que me muestre la siguiente pagina
					cout<<"pagina terminada, ";
					gotoxy(53,33);
					system("pause");
					system("cls");
					reCuadro(15,0,138,36);
					h=0;//establezco h para que no se superponga el texto en el recuadro y no alterar el valor de j.
					}
				}
		h++;
		}
	gotoxy(53,33);
	system("pause");
}			
void Confirmar_Salida(bool & bandera, char & var_menu, archivoCompetencia competencias, string Nom_archi)
{
	char varSalida=0, auxSalida[50] = {0};
	
	system("cls");// refresca la consola
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	gotoxy(58, 11);
	cout << "Esta seguro que quiere salir ";

	gotoxy(63,14);
	cout << "de la aplicacion";
	
	gotoxy(69,17);
	cout << "1-Si";
	
	gotoxy(69,20);
	cout << "2-No";
	
	gotoxy(62,23);
	cout << "Ingrese una opcion:" << endl;
	
	while(varSalida != '1' and varSalida != '2') // al ingresar una opcion correcta se corta el bucle.
	{
		gotoxy(81,23);
		cout << "                                  ";
		
		gotoxy(81,23);
		
		ingreso_Datos(auxSalida, 35);
		
		if(auxSalida[1] == 10)
			varSalida = auxSalida[0];
	}

	if(varSalida == '1') // si es 1 modifica a bandera cerrando el bucle para salir del programa,
	{
		bandera = 1;     // si es 2 vuelve al menu principal.
		
		ofstream archi(Nom_archi.c_str(), ios::binary); //actualizo la informacion del archivo utilizado
		
		if(!(archi.fail()))
		{
			archi.write((char *)(& competencias), sizeof(competencias)); // escribimos en el archivo la nueva informacion.
			
			gotoxy(55,25);			
			cout << "Los datos se han guardado correctamente.";
			
			
			gotoxy(55,26);
			system("pause");
		}
		else
		{
			gotoxy(55,25);
			cout << "Hubo un problema inesperado y no se ha podido guardar la informacion\n";
			
			gotoxy(55,26);
			system("pause");
		}
		
		archi.close(); // cerramos el archivo para evitar posibles problemas
		
		fin_programa();
	}

	else
	var_menu=0;
}

void fin_programa()
{
	system("cls");
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	gotoxy(58, 13);
	cout << " el programa finalizara, saludos. " << endl;

	gotoxy(65,17);
	cout << "en 5, "; 
	
	Sleep(1000); // pausa por 1 segundos el programa
	cout << "4, "; 
	
	Sleep(1000);
	cout << "3, "; 
	
	Sleep(1000); 
	cout << "2, "; 
	
	Sleep(1000);
	cout << "1....";
	
	Sleep(1000);
	system("cls");
}

void Menu_Estadistica(char & var_menu,int deporte_medallas[][3])
{
	system("cls");// refresca la consola
	
	bool lupo = true;
	do{
		
		system("cls");// refresca la consola
		
		reCuadro(15,0,138,36);// dibuja el recuadro
		
		gotoxy(65, 8);// dibuja el recuadro
		cout << "Menu Estadisticas" << endl;//dibuja el menu juegos en la pantalla.
		
		gotoxy(58, 11);
		cout << " ==========================" << endl;
		
		gotoxy(56, 14);
		cout << " 1.- Pais con mas medallas." << endl;
		
		gotoxy(56, 17);
		cout << " 2.- Medallas del Pais." << endl;
		
		gotoxy(56, 20);
		cout << " 3.- Pais con mas deporte individuales." << endl;
		
		gotoxy(56, 23);
		cout <<" 4.- Pais premiado del deporte."<<endl;
		
		gotoxy(56,26);
		cout << " X.- Volver al menu principal"<<endl;
		
		gotoxy(58, 29);
		cout<< "Ingrese una opcion:";
		
		char numeroCorrecto[50] = {0}, var_medallas = 0;
		
		while((var_medallas != '1') and (var_medallas != '2') and (var_medallas != '3') and (var_medallas != '4') and  (var_medallas != 'X')) // si no es la entrada deseada limpia y pide denuevo los datos...
		{
			gotoxy(78,29);
			cout << "                                   ";
			
			gotoxy(78,29);
			
			ingreso_Datos(numeroCorrecto, 36);
			
			if(numeroCorrecto[1] == 10)  // verifica si se ingreso solo 1 digito antes del salto de linea.
				var_medallas = numeroCorrecto[0];
		}
		
		if(var_medallas != 'x' and var_medallas != 'X') // si es distinto de x y X varifica el dato ingresado
		{
			
			if(var_medallas == '1')//pais con mas medallas
			{
				pais_mayor_medallas( deporte_medallas );
				
				gotoxy(52,35);
				system("pause");
			}
			else if(var_medallas == '2')//medalla del pais
			{
				lista_de_paise( deporte_medallas );
				
			}
			else if(var_medallas == '3')//pais con mas deporte individuales
			{
				paisMasMedallasInd(deporte_medallas);
				gotoxy(16,35);
				system("pause");
			}
			else if( var_medallas == '4')//paises previados del deporte
			{
				
				podioPrimerLetra(deporte_medallas);
				gotoxy(16,35);
				system("pause");
			}
		}
		else
		{
			var_menu = 0;//vuelve al menu principal
			lupo = false;
		}
		
	} while(lupo);
}
void paisMasMedallasInd(int deporte_medallas[][3])
{
		system("cls");// refresca la consola
		
		reCuadro(15,0,138,36);// dibuja el recuadro
		
		
		int num=0,max=0,aux=-1;
		int vecfrec[numPaises]={0};
		for(int i=0;i<deportesIndividuales;i++){
			num=i;
			nombre_dep('d',(num));//asignamos a num el ID del deporte individual.
			for(int j=0;j<3;j++){
				if(deporte_medallas[num-1][j]>=0){
					int x=deporte_medallas[num-1][j];//igualo x al ID del pais en esa posicion.
					vecfrec[x]++;//utilizamos un vector frecuencia para determinar cuantas medallas tiene cada pais.
				}
			}
		}
		for(int i=0;i<numPaises;i++){
			if(vecfrec[i]>max){
				max=vecfrec[i];
				aux=i;//guarda el ID del pais.
			}
		}
		if(aux!=-1){
			gotoxy(17,3);
			cout<<"Pais con mas medallas individuales: ";
			gotoxy(56,3);
			cout<<". . . . . . . . . . . . . . . . . . . ";
			gotoxy(54,3);
			imprimirPais(aux+1);
			gotoxy(80,3);
			cout<<" (con "<<vecfrec[aux]<<" medalla(s).)"<<endl;
		}
		else{
			gotoxy(17,3);
			cout<<"no se han cargado deportes individuales"<<endl;
		}
	}
	
void podioPrimerLetra(int deporte_medallas[87][3]){
	system("cls");// refresca la consola
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	char carac,prim;
	int num,posicion=4,aux=4,band=0;
	do{
		gotoxy(17,3);
		cout<<"ingrese primera letra del deporte: ";
		gotoxy(52,3);
		cout<<"                                       ";
		gotoxy(52,3);
		cin>>carac;//ingresamos la primer letra del deporte
		carac=toupper(carac);//lo igualamos a su mayuscula para no generar problemas
	} while('A'>=carac or carac>='Z');
	for(int i=0;i<totalDeportes;i++){
		num=i+1;
		prim=primercaracter(i,carac);//igualo prim al primer caracter del deporte en la posicion i.
		if(carac==prim and !(deporte_medallas[num-1][0] == -1 and deporte_medallas[num-1][1] == -1 and deporte_medallas[num-1][2] == -1)){//solo mostrara informacion si la primer letra coincide y el podio esta cargado
			band++;//muestra cuantos podios se mostraron
			gotoxy(16,posicion++);
			cout<<"el ID:"<<num<<".. nombre: ";//imprimo el ID en pantalla
			nombre_dep('c',num);//imprime en pantalla el nombre del deporte 
			
			for(int j =0 ; j<3 ;j++){
				
				gotoxy(16,posicion++);
				cout<<(j+1)<<"°er lugar:   "; //muestro las posiciones.
				imprimirPais(deporte_medallas[num-1][j]+1);//imprim en pantalla el nombre del pais
				aux++;
			}
			aux++;
		}
		if(aux==28){
			gotoxy(35,35);//cuando se esta por terminar el recuadro, reinicio pagina para que me muestre la siguiente pagina
			cout<<"pagina terminada, ";
			gotoxy(53,35);
			system("pause");
			system("cls");
			reCuadro(15,0,139,36);
			aux=4;//reseteo aux en 4 para que me muestre en los mismos lugares.
			posicion=4;
		}
	}
	if(band==0){//esto es por las dudas que no se ingrese un dato valido.
		gotoxy(17,4);
		cout<<"no existe informacion con esta letra, por favor, ingrese al menu nuevamente."<<endl;
	}
}

void pais_mayor_medallas(int deporte_medallas[][3])
{
	
	system("cls");
	
	reCuadro(15,0,138,36);// dibuja el recuadro
	
	
	gotoxy (55,6);
	cout <<" El Pais con mayor cantidad de medallas\n";
	
	gotoxy(58,9);
	cout <<" =============================== ";
	int v[500]= {0};
	
	
	//un vector  frecuencia para contar la cantidad de medallas ganadas por cada pais	
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < totalDeportes-1 ; j++)
		{
			if( deporte_medallas[j][i] > 0)
			{
				//almaceno las medallas en cada pais
				v[deporte_medallas[j][i]]++;
			}
		}
	}
	
	int ID=0,total=0;
	
	//funcion para optener el pais con mas medallas 
	for(int i = 0 ; i < numPaises ; i++)
	{
		if(total < v[i] and v[i] > 0  )
		{
			ID = i;//guardo el ID del pais con mas medallas 
			total = v[i];
		}
	}
	
	gotoxy(52,12);
	cout << " El nombre del pais con mas medallas es: ";
	imprimirPais(ID+1);//imprime el pais por pantalla
	
	gotoxy(52, 15);
	cout << " Con cantidad de medallas "<<v[ID]<<endl; 
	
}
void lista_de_paise(int  deporte_medallas[][3] ){

	bool termino=true;//para el bucle
	
	const int paisesPorPagina = 30; // Cantidad de países por página
	
	int paginaActual = 0,ID = 0;

	char v[10]={0};//lamacena el ID

	int medallas[200]={0};//para las medallas
	
	//una matriz frecuencia para contar la cantidad de medallas ganadas por cada pais
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < totalDeportes-1 ; j++){
			
			if( deporte_medallas[j][i] > 0)
			{
				// vector frecuencia (Almaceno las medallas ganadas de cada pais)
				medallas[deporte_medallas[j][i]]++;
			}
		}
	}
	
	while (termino)
	{
		system("cls");
		
		gotoxy( 80,5);
		cout << "Teclear (P):ID o (X):salir ";
		
		// Mostrar la página actual 
		mostrarPagina(paginaActual, paisesPorPagina);
		
		// Leer entrada del usuario
		gotoxy(111,5);
		char tecla = _getch();
		
		if (tecla == 75)// Flecha izquierda 
		{ 
			if (paginaActual > 0)
			{
				paginaActual--;
			}
		} 
		else if (tecla == 77) // Flecha derecha
		{  
			if ((paginaActual + 1) * paisesPorPagina < numPaises) 
			{
				paginaActual++;
			}
		}
		else if (tecla == 'P' or tecla == 'P')  // pertime borrar el caracter ingresado en pantalla.
		{	
			gotoxy(80,5);
			cout<<" ingrese el ID:               "; 
			
			gotoxy(96,5);
			ingreso_Datos(v,33);
			
			ID = atoi(v);//paso la cadena de caracteres a un tipo int
			
			if(ID < 0 or ID > numPaises  or  v[0] < '0' or v[0] > '9' )
			{
				gotoxy(80,7);
				cout<<"El ID ingreso no es correcto";
			}
			else
			{
				gotoxy(80,7);
				cout <<" El pais es:  ";
				imprimirPais(ID); // imprime en pantalla el nombre del pais
				
				gotoxy(80,8);
				cout <<" La cantidad de medalla: " << medallas[ID-1];//imprime las medallas totales 
			}
			gotoxy(80,35 );
			system("pause");	
		}
		else if ( tecla == 'X' or tecla == 'x')
		{
			termino = false;
			
			gotoxy(80,34);
			cout <<" Adios ";
			
			Sleep(1000); // pausa por 1 segundos el programa
		}
		
	}
}
	
void mostrarPagina(int pagina, int paisesPorPagina)
{	// Función para mostrar una página de países
	
	int inicio = pagina * paisesPorPagina;
	int fin = inicio + paisesPorPagina;
	int pos=0;
	
	gotoxy(36,1);
	cout << "=== Página " << pagina + 1 << " ===\n";
	
	//muestra en pantalla los paises en forma de pagina 
	for (int i = inicio; i < fin && i < numPaises; i++) 
	{
		gotoxy(34,pos+3);
		pos++;
		cout << i + 1 << ". ";
		imprimirPais(i+1);//imprimo el pais en pantalla
		
	}
	if(inicio == 0) // Muestro en pantalla las direcciones
	{  
		gotoxy(42,34);
		cout <<" siguiente pagina";
		
		gotoxy(42,35);
		cout <<"       -> ";
	}
	else
	{
		gotoxy(30,34);
		cout<<" anterior pagina    siguiente pagina";
		gotoxy(30,35);
		cout<<"       <-                     -> ";
		
	}
	// Muestro el marco en pantalla
	reCuadro(15,0,138,36);
}
	
