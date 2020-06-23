#pragma once
#include "cListaT.h"
#include "cUsuario.h"

class cUsuario;

class cBaseDatos
{
	cListaT <cPersona> listaPersonas;  //creamos una lista de PERSONAS que tiene 
										//a los usuarios y a los administradores
public:
	cBaseDatos(){}
	bool AgregarPersonas(cPersona* Persona) {
		return listaPersonas.AgregarItem(Persona);
	}
	
	// METODOS 
	/*bool QuitarPersonas(int Audio) {
		return listaPersonas.QuitarenPos(Audio);
	}*/
	/*cAudio* QuitarPesonas(cAudio* Audio) {
		return listaPersonas.Quitar(Audio);
	}
	void EliminarPersonas(unsigned int pos) {
		listaPersonas.Eliminar(pos);
	}
	void ListarPersonas() {
		listaPersonas.listarLista();
	}
	void ListarPersonasUsernameOrdenado() {
		listaPersonas.listarNombreOrdenado();
	}*/
	~cBaseDatos() {};
};

