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
      crear(filas,columnas);
}

void Imagen::destruir()
{
    if (datos)
    {
      delete [] datos[0];
      delete [] datos;
      nfilas=ncolumnas=0;
      datos=NULL;
    }
}

Imagen::Imagen(const Imagen &otra)
{
   nfilas=otra.nfilas;
   ncolumnas=otra.ncolumnas;

   if(otra.datos==NULL)
    datos=NULL;
    else
    {
      datos=new byte*[nfilas];
      datos[0]=new byte[nfilas*ncolumnas];

      for(int i=1;i<nfilas;i++)
        datos[i]=datos[0]+i*ncolumnas;

      for(int i=0;i<nfilas*ncolumnas;i++)
        datos[0][i]=otra.datos[0][i];
    }
}


 Imagen::~Imagen()
{
   destruir();
}

void Imagen::Copiar(const Imagen &otra)   // creo un metodo copiar, ya que asi me puede valer para el constructor y la sobrecarga de la asignacion
{
  nfilas=otra.nfilas;
   ncolumnas=otra.ncolumnas;

   if(otra.datos==NULL)
    datos=NULL;
    else
    {
      datos=new byte*[nfilas];
      datos[0]=new byte[nfilas*ncolumnas];

      for(int i=1;i<nfilas;i++)
        datos[i]=datos[0]+i*ncolumnas;

      for(int i=0;i<nfilas*ncolumnas;i++)
        datos[0][i]=otra.datos[0][i];
    }
}

 void Imagen::crear(int filas, int columnas)
 {
    nfilas=filas;
    ncolumnas=columnas;
   
    datos= new byte*[nfilas];
    datos[0]= new byte [nfilas*ncolumnas];

    for(int i=1;i<nfilas;i++)
      datos[i]=datos[i-1]+ncolumnas;


    for(int i=0;i<nfilas;i++)
    {
      for(int j=0;j<ncolumnas;j++)
        datos[i][j]=0;
    }

}

 int Imagen::filas()
 {
  return nfilas;
 }

 int Imagen::columnas()
 {
    return ncolumnas;
 }

 void Imagen::set(int i, int j, byte v)
 {
    datos[i][j]=v;

 }

 byte Imagen::get(int i, int j)
 {

  return  datos[i][j];
  
 }

 void Imagen::setPos(int i, byte v)
 {
   datos[0][i]=v;

 }

 byte Imagen::getPos(int i)
 {
  return datos[0][i];
 }

  bool Imagen::leerImagen(const char nombreFichero[])
  {

   bool leido=false;

    
      if(infoPGM(nombreFichero,nfilas,ncolumnas) == IMG_PGM_BINARIO)
      {
          crear(nfilas,ncolumnas);

            leerPGMBinario (nombreFichero, datos[0], nfilas,ncolumnas);
          leido=true;
          
       }
        if(infoPGM(nombreFichero,nfilas,ncolumnas) == IMG_PGM_TEXTO)
       {
          crear(nfilas,ncolumnas);

          leerPGMTexto(nombreFichero, datos[0], nfilas, ncolumnas);
              leido = true;
        }
       
    return leido;

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
         aux=datos[0][i*ncolumnas+j];
        resultado.set(i,j,aux);
    }
   }

  for(int i=0;i<a.nfilas;i++)
   {
    for(int j=0;j<a.ncolumnas;j++)
    {
         aux=a.datos[0][i*a.ncolumnas+j];
        resultado.set(i,j+ncolumnas,aux);
    }
   }

  return resultado;

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

       return escribirPGMTexto(nombreFichero, datos[0], nfilas, ncolumnas);

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



