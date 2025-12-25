#ifndef FF_H
#define FF_H

class ff {
public:
	ff();
private:
};

bool termino=true;

while(termino)
{
	char let = _getch();  // Captura un carácter sin mostrarlo en pantalla
	
	if (let == '\r')  // Verifica si el carácter es Enter (carácter de nueva línea)
	{  
		arreglo[i] = 10;  // Añade el carcater de linea nueva.
		
		termino = false;
	}
	
	else if (let == '\b' && i > 0)  // pertime borrar el caracter ingresado en pantalla.
	{
		i--; 
		
		cout << "\b \b";  // Mueve el cursor hacia atrás y borra el carácter
	}
	else if (let != '\b') 
	{	
		if((let >= '0' and let <= '9') ) // solo permite que se tomen numeros.
		{
			arreglo[i] = let;  // Almacena el carácter en el array
			
			i++;
			
			if (i<7)
				cout << let;  // imprime el caracter en pantalla.
			
			else
				i--; // disminuye una pocicion para no usar mas espacio del deseado
			
			
			imprimirPais_Inicial(arreglo);
			
		}
	} 
}
system ("pause");

#endif

