﻿#pragma once
#define NMAX 100

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
template<class T>
class cListaT
{
protected:
	T** vector;
	unsigned int CA, TAM;

	void Redimensionalizar();
public:
	cListaT(unsigned int TAM = NMAX);
	~cListaT();

	bool AgregarItem(T* item);

	T* Quitar(string clave);
	T* Quitar(T* item);
	T* QuitarenPos(unsigned int pos);

	void Eliminar(string clave);
	void Eliminar(T* item);
	void Eliminar(unsigned int pos);

	void listarLista();
	T* BuscarItem(string clave);
	T* getItem(unsigned int pos);
	
	unsigned int getItemPos(string clave);

	void listarNombreOrdenado();  //no modifica el orden de la lista solo ordena y lista

	unsigned int getCA();
	unsigned int getTAM();

};

template<class T>
unsigned int cListaT<T>::getTAM()
{
	return TAM;
}
template<class T>
unsigned int cListaT<T>::getCA()
{
	return CA;
}

template<class T>
void cListaT<T>::Redimensionalizar()
{
}

template<class T>
cListaT<T>::cListaT(unsigned int TAM)
{
	vector = new T * [TAM];
	for (unsigned int i = 0; i < TAM; i++)
	{
		vector[i] = NULL;
	}

	this->TAM = TAM;
	CA = 0;


}

template<class T>
cListaT<T>::~cListaT()
{
	if (vector != NULL)
	{
		for (unsigned int i = 0; i < CA; i++)
		{
			if (vector[i] != NULL)
				delete vector[i];
		}
		delete[] vector;
	}


}

template<class T>
void cListaT<T>::listarLista()
{
	for (unsigned int i = 0; i < CA; i++)
	{
		vector[i]->Imprimir();
	}
}

template<class T>
bool cListaT<T>::AgregarItem(T* item)
{

	T* i_f = BuscarItem(item->getNombre());
	if (i_f != NULL)throw new exception("Ya se encuentra en la lista");

	if (CA < TAM)
		vector[CA++] = item;
	else throw new exception("No hay tama�o suficiente para agregar el item");;
	return true;
}

template<class T>
T* cListaT<T>::Quitar(string clave) {

	unsigned int pos = getItemPos(clave);
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);

}

template<class T>
T* cListaT<T>::Quitar(T* item) {
	unsigned int pos = getItemPos(item->getNombre());
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);
}

template<class T>
T* cListaT<T>::QuitarenPos(unsigned int pos) {

	if (pos >= CA)throw new exception("Posicion invalida");

	T* aux = vector[pos];

	for (unsigned int i = 0; i < CA - 1; i++)
	{
		vector[i] = vector[i + 1];
	}

	vector[CA - 1] = NULL;
	CA--;
	return aux;
}


template<class T>
void cListaT<T>::Eliminar(string clave) {

	unsigned int pos = getItemPos(clave);

	if (pos < CA)
		Eliminar(pos);
	//sino algo

}

template<class T>
void cListaT<T>::Eliminar(T* item) {

	Eliminar(item->getNombre());

}

template<class T>
void cListaT<T>::Eliminar(unsigned int pos) {
	if (pos >= CA)return;// o Throw no pude eliminar

	T* dato = QuitarenPos(pos);

	if (dato != NULL)
		delete dato;
	else
	{
		throw new exception("no encontrado");
	}
}

template<class T>
T* cListaT<T>::BuscarItem(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (!((vector[i]->getNombre()).compare(clave))) {
			return vector[i];
		}
	}
	return NULL;
}

template<class T>
T* cListaT<T>::getItem(unsigned int pos)
{
	if (pos < CA)
		return vector[pos];
	else return NULL;
}

template<class T>
unsigned int cListaT<T>::getItemPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getNombre() == clave)
			return i;
	}

	return INT_MAX;
}

template<class T>
void cListaT<T>::listarNombreOrdenado() //muy ineficiente pero eficaz
{
	std::vector <T> buffer;
	for (unsigned int i = 0; i < CA; i++)   //creamos un vector auxiliar (no se quiere modificar el vector original)
	{
		buffer.push_back(*(vector[i]));
	}

	for (unsigned int i = 0;i < CA-1;i++) { //Bubble sort O(n^2)
		int cont = 0;
		for (unsigned int l = 0;l < CA - 1;l++) {
			if (((buffer[l].getNombre()).compare(buffer[l+1].getNombre())) > 0) {
				swap(buffer[l], buffer[l + 1]);
				cont++;
			}
		}
		if (cont == 0) break;
	}

	for (unsigned int i = 0; i < CA; i++)
	{
		buffer[i].Imprimir(); 
	}
}




