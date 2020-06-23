#include "cServicio.h"
int cServicio::cantContenido = 0;

cServicio::cServicio(int tiempoDeUso, string nombre)
{ 
	this->tiempoDeUso = tiempoDeUso; 
	this->nombre = nombre; 
	cantContenido++;
}

void cServicio::descargar()
{
	cout << "Se ha descargado con exito" << endl;
}
 
void cServicio::iniciar()
{
	cout << "Se ha iniciado con exito" << endl;
}

void cServicio::pausar()
{
	int i = 0;
	cout << "presione el numero '9' para reanudar" << endl;
	while (i != 9)
	{     //Hago un while infinito para realizar una simulacion mejor de que esta pausado
		cin >> i;
	}
	cout << "Se ha reanudado" << endl;
}

void cServicio::apagar()
{
	cout << "Apagado" << endl;             //Apago 
}

