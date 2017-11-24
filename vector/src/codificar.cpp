#include <iostream>
#include <cstring>
#include "imagen.h"
#include "byte.h"
#include "codificar.h"

using namespace std;

bool ocultar(Imagen &original, const char cadena[])    
{

	int n=strlen(cadena)+1;
	bool resultado=false;
	int pos=0;

    if((n*8) < original.filas()*original.columnas())
    {
     	
	     	for(int i=0;i<n;i++)
	     	{
	     		for(int j =7; j >= 0; j--)
	     		{
	       			byte valor= original.getPos(pos);

	     			if(get(cadena[i],j))
	     				on(valor,0);
	     			else
	     				off(valor,0);

	     			original.setPos(pos, valor);
	     			pos++;
	     		}
	     	}
	  
	     resultado=true;
	}

	return resultado;
 }

 bool revelar(Imagen &original, char mensaje[], int maximo)    
{
	bool fin=false;
	int pos_imagen = 0;
	int pos_mensaje = 0;
	byte letra;
	int n = original.filas() * original.columnas();
	
	
	while(!fin && pos_imagen < n  && pos_mensaje < maximo )
	{
		for(int j = 7 ; j >= 0 ; j--)
		{
			byte valor= original.getPos(pos_imagen);

			if(get(valor, 0))
				on(letra, j);

			else
				off(letra, j);

			pos_imagen++;
		}
		                                 
		mensaje[pos_mensaje] = letra;
		pos_mensaje++;

		if(letra == '\0')
			fin=true;
	} 
	
	return fin;

}
