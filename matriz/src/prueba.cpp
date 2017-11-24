#include <iostream>
#include <cstring>
#include "codificar.h"
#include "imagen.h"
#include "byte.h"
#include "pgm.h"

using namespace std;

int main(){

	const int MAXNOMBRE = 100;
	const int MAXTAM = 500;
	char imagen_entrada[MAXNOMBRE], imagen_salida[MAXNOMBRE];
	char mensaje[MAXTAM];
	Imagen img(1000,1000);
	int numero=0;	
	

	int grados;
	bool sentidohorario=false;
	char letra;


	while(numero != 4){

		// Menú.
		cout << "\n1 - Revelar\n";
		cout << "2 - Ocultar\n";
		cout << "3 - Rotar\n";
		cout << "4 - Salir";

		// Filtro de numero.
		///while(numero < 1 || numero > 4)
		//{
			cout << "\nSeleccione una opción: ";
			cin >> numero;
			cin.ignore();

		//}

		switch(numero){

			
			
			// Revelar mensaje.
			case 1: cout << "\nIntroduzca la imagen de entrada: ";
					cin.getline(imagen_entrada, MAXNOMBRE);

					// Cargar el archivo en la imgn.
					if(!img.leerImagen(imagen_entrada)){

						cout << "\nError al leer la imagen de entrada.\n";
						return 1;

					}

					// Revelar el mensaje oculto.
					if (!revelar(img, mensaje, MAXTAM)){
		
						cout << "\n La imagen o no contiene un mensaje o el mensaje es demasiado largo.\n";
						return 1;

					}

					// Imprimir el mensaje por pantalla.
					cout << "\nEl mensaje revelado es: ";

					for (int i = 0 ; i <= strlen(mensaje) ; i++)
						cout << mensaje[i];

					cout << "\n";

					break;

			case 2: cout << "\nIntroduzca la imagen de entrada: ";   // para ocultar
					cin.getline(imagen_entrada, MAXNOMBRE);

					 
					if(!img.leerImagen(imagen_entrada)){               // cargamos la imagen

						cout << "\nError al leer la imagen de entrada.\n";
						return 1;

					}

					cout << "\nIntroduzca la imagen de salida: ";
					cin.getline(imagen_salida, MAXNOMBRE);
					cout << "\nIntroduzca el mensaje para ocultar: ";
					cin.getline(mensaje, MAXTAM);

					
					if (!ocultar(img, mensaje)){                 // ocultamos el mensaje en img
		
						cout << "\nEl mensaje es DEMASIADO largo para ocultarlo en la imagen.\n";
						return 1;

					}

					cout << "\nEstamos ocultando...";

					// Guardar la imgn en el archivo.
					if(!img.escribirImagen(imagen_salida)){

						cout << "\nFallo al escribir la imgn de salida.\n";
						return 1;

					}

					break;

			case 3: //cout << "\nIntroduzca la imagen de entrada: ";   
					//cin.getline(imagen_entrada, MAXNOMBRE);

					 
					if(!img.leerImagen("imagenes/lena.pgm")){               // cargamos la imagen

						cout << "\nError al leer la imagen de entrada.\n";
						return 1;

					}

					//cout<<"\nIntroduzca el numero de grados: ";
					//cin >> grados;

					cout <<"¿\nSentido horario?";
					cin >> letra;

					//cout << "\nIntroduzca la imagen de salida: ";
					//cin.getline(imagen_salida, MAXNOMBRE);

					if(letra=='s' || letra=='S')
						sentidohorario=true;

					//img.rotacion(90, sentidohorario);

					break;

			// Salir.
			case 4: cout << "\nNos vamos del programa...\n";
					break;

		}

	}
}