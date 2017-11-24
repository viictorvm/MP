#ifndef _IMAGEN_H_
#define _IMAGEN_H_


typedef unsigned char byte; ///< byte = 8bits almacenado en un unsigned char

/**
@brief Una imagen en blanco y negro. Cada píxel es un byte
*/
class Imagen{
private:
   // int MAXPIXELS = 1000000;  ///< número máximo de píxeles que podemos almacenar 
   byte **datos;///< datos de la imagen
   int nfilas; 			///< número de filas de la imagen
   int ncolumnas;		///< número de columnsa de la imagen

public:
/// Construye una imagen vacía (0 filas, 0 columnas)
   	Imagen(); 
   
	Imagen(const Imagen &otra);

 	~Imagen();

	void Copiar(const Imagen &nueva);

	Imagen & operator=(const Imagen &original);
 


   Imagen(int filas, int columnas);
   
   
   void crear(int filas, int columnas);
   
   


   int filas(); 

   

   int columnas(); 
   

 void set(int y, int x, byte v); 
   
   

   byte get(int y, int x); 
   
   
   void setPos(int i, byte v); 
   
 

   byte getPos(int i);

   

   bool leerImagen(const char nombreFichero[]);
   


bool escribirImagen(const char nombreFichero[]); 
void rotar();
void rotacion(int grados, bool sentido);
void destruir();

 Imagen operator+(const Imagen &a);



};



#endif
