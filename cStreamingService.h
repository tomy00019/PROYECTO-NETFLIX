#pragma once
#include "cListaServicios.h"
#include "cAudio.h"
#include "cPeliculas.h"
#include "cJuegos.h"

class cAudio;
class cPeliculas;
class cJuegos;
template <class T>
class cListaServicios;

class cStreamingService
{
	cListaServicios <cServicio> listaServicios;   //UNA SOLA LISTA DE CLASE PADRE PARA IMPLEMENTAR POLISNIRFISMO
public:
	cStreamingService() {}
	bool AgregarServicio(cServicio* servicio) {
		return listaServicios.AgregarItem(servicio);
	}
	bool QuitarServicio(int pos) {
		return listaServicios.QuitarenPos(pos);
	}
	cServicio* QuitarServicio(cServicio* servicio) {
		return listaServicios.Quitar(servicio);
	}
	void EliminarServicio(unsigned int pos) {
		listaServicios.Eliminar(pos);
	}
	void ListarServicio() {
		listaServicios.listarLista();
	}
	void ListarServicioNombreOrdenado() {
		listaServicios.listarNombreOrdenado();
	}
	/*void ListarCategoriaNombreOrdenado(categoria) {
		listaServicios.listarNombreOrdenado();				//<--REVISAR
	}*/
	void operator+(cServicio* p) { AgregarServicio(p); };
	~cStreamingService() {}
};

