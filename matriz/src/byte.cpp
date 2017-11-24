#include "byte.h"
#include <iostream>
#include <cmath>

using namespace std;


void on(byte &b, int pos)
{
		byte mask;

	if(pos>=0 && pos<8)
	{
		mask=0x1 << pos;

		b= b | mask;

	}
}

void off(byte &b, int pos)
{
	byte mask;

	if(pos>=0 & pos<8)
	{

		mask = 0x1 << pos;
	    mask = ~mask;

	   b= b&mask;
	}
}


bool get(byte b, int pos)
{
	byte mask;

	mask=0x1 << pos;

	b= b & mask;

	if ( b>0)
			return true;
	else
			return false;

}

void asignar(byte &b, const bool v[])
{

	for(int i=0;i<8;i++)
	{
		if(v[i]== true)
			 on(b,i);
		else if (v[i]== false)
			 off(b,i);

	}
}

void print(byte b)
{

	for(int i=7;i>=0;i--)
			cout<< ((b>>i) & 1);

		cout << "\n";

}

void encender(byte &b)
{
	byte mask;

	mask=0x0;
	mask = ~mask;

	b= b | mask;

}

void apagar(byte &b)
{

	byte mask;

	mask=0x0;
	b= b & mask;

}

void encendidos(byte b, int posic[], int &cuantos)
{
	byte mask, aux;
	int j=0;

	for(int i=0;i<8;i++)
	{
		mask=0x1 << i;
		mask=b & mask;

		if(mask>0)
		{
			posic[j]=i;
			cuantos++;
			j++;
		}

	}
}

void volcar(byte b, bool v[])
{
		bool aux;

	for(int i=0;i<8;i++)
	{
		aux= get(b,i);

		if(aux)
			v[i]=true;
		else
			v[i]=false;
	}
}

