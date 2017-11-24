#include <iostream>
#include "imagen.h"
#include "pgm.h"

using namespace std;

Imagen::Imagen()
{
  nfilas=ncolumnas=0;
  datos=0;
}

Imagen::Imagen(int filas,int columnas)
{
  nfilas=filas;
  ncolumnas=columnas;
  int tope= nfilas*ncolumnas;
  datos= new byte[tope];

  for(int i=0;i<tope;i++)
        datos[i]=0;
}

 void Imagen::crear(int filas, int columnas)
 {

  nfilas=filas;
  ncolumnas=columnas;
  int tope= nfilas*ncolumnas;
  datos= new byte[tope];

  for(int i=0;i<tope;i++)
        datos[i]=0;
}

 int Imagen::filas()
 {
  return nfilas;
 }

 int Imagen::columnas()
 {
  return ncolumnas;
 }

 void Imagen::set(int y, int x, byte v)
 {
  datos[(y*ncolumnas)+x]=v;

 }

 byte Imagen::get(int y, int x)
 {

  return datos[(y*ncolumnas)+x];
  
 }

 void Imagen::setPos(int i, byte v)
 {
  datos[i]=v;

 }

 byte Imagen::getPos(int i)
 {
  return datos[i];
 }

  bool Imagen::leerImagen(const char nombreFichero[])
  {

  
      if(infoPGM(nombreFichero,nfilas,ncolumnas) == IMG_PGM_BINARIO)
      {   
        crear(nfilas,ncolumnas);

            leerPGMBinario (nombreFichero, datos, nfilas,ncolumnas);
        
          
       }
       else if(infoPGM(nombreFichero,nfilas,ncolumnas)   == IMG_PGM_TEXTO)
       {
         crear(nfilas,ncolumnas);

          leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas);
              
        }
       else
         return false;

  }

void Imagen::Copiar(const Imagen &nueva)   // creo un metodo copiar, ya que asi me puede valer para el constructor y la sobrecarga de la asignacion
{
   nfilas=nueva.nfilas;
   ncolumnas=nueva.ncolumnas;
   

   if(nueva.datos==0)
   		datos=NULL;
   	else
   	{
   		int tope=nfilas*ncolumnas;
   		datos=new byte [tope];

   		for(int i=0;i<tope;i++)
    	  datos[i]=nueva.datos[i];
   	}
   
}


 Imagen::Imagen(const Imagen &otra)
{
   Copiar(otra);
}


 Imagen::~Imagen()
{
   destruir();
}

Imagen& Imagen::operator=(const Imagen &original)
{
   if(this!=&original)
   {
      destruir();
      Copiar(original);

   }
   return *this;
}


  bool Imagen::escribirImagen(const char nombreFichero[])
  {

    return escribirPGMTexto (nombreFichero, datos, nfilas, ncolumnas);
  }

  void Imagen::destruir()
  {
    if (datos)
    {
      delete [] datos;
      nfilas=0;
      ncolumnas=0;
      datos=NULL;
    }
  }


void Imagen::rotar()
{


  Imagen a(ncolumnas,nfilas);

  for(int i=0;i<nfilas;i++)
  {
    for(int j=0;j<ncolumnas;j++)
    {
       a.set(j,nfilas-i-1,get(i,j));

    
    }
  }

  destruir();

  Copiar(a);
}


void Imagen::rotacion(int grados, bool sentido)
{

  if((sentido && grados == 90) || (!sentido && grados == 270))
   {

    rotar();
   }

  else if((!sentido && grados == 90) || (sentido && grados == 270))
  {

    rotar();
    rotar();
    rotar();

  }

    else if(grados == 180)
    {

      rotar();
      rotar();

    }
 
  
}

Imagen Imagen::operator+(const Imagen &a)
{
  int filasmax=nfilas;
  int columax=a.ncolumnas+ncolumnas;
  byte aux;

  if(a.nfilas>nfilas)
    filasmax=a.nfilas;


  Imagen resultado(filasmax,columax);

  for(int i=0;i<nfilas;i++)
   {
    for(int j=0;j<ncolumnas;j++)
    {
         aux=datos[i*ncolumnas+j];
        resultado.set(i,j,aux);
    }
   }

  for(int i=0;i<a.nfilas;i++)
   {
    for(int j=0;j<a.ncolumnas;j++)
    {
         aux=a.datos[i*a.ncolumnas+j];
        resultado.set(i,j+ncolumnas,aux);
    }
   }

  return resultado;

}



