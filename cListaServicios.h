#pragma once
#include "cListaT.h"

template <class T>
class cListaServicios : public cListaT<T>
{
public:
	cListaServicios(): cListaT<T>(50){}
	template <class K>
	void listarCategoria(K clave) {};


	~cListaServicios() {};
};
/*
template<class T>
template<class K> 
void cListaServicios<T>::listarCategoria<K >(K clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getTipo() == clave)
		{
			vector[i]->Imprimir();
		}
	}
}
*/
