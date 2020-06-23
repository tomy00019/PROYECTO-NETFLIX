#pragma once

#include "cPeliculas.h"
#include "cAdministrador.h"
#include "cUsuario.h"
#include "cServicio.h"
#include "cListaT.h"
#include "cAudio.h"
#include "cJuegos.h"
#include "cStreamingService.h"
#include "cBaseDatos.h"
using namespace std;

//Damian: "Como era para acceder al repositorio de GIT del trabajo que hizo el "Pampa" el viernes?, te paso mi 
//usuario por si las dudas 'tomy00019' tengo algunas dudas con los siguentes ITEMS
//1. problemas con listaCategoria, METODO que lista las categorias que se pasan a una funcion template
//		no me marca problemas el VISUAL, pero a la hora de compilar se me rompe
//2. PROBLEMAS con cListaServicios.ListarNombresOrdenados() El algoritmo esta perfecto, el problema es q se esta llamando al metodo del padre
//		yo lo que haria seria un DYNAMIC CAST, pero se deconoce el tipo de puntero de la derivada
//		OTRA OPCION que pense es hacer servicio VIRTUAL PURE pero No es posible hacer una lista de tipo de una clase 
//		abstracta(creo yo) el compilador me dice que no la puedo instanciar
//3. como sé que tipo de clase es el objeto? ej: en la lista de punteros padres si yo lo recorro, como puedo 
//		saber que clase es la derivda. por ejemplo un metodo que liste solo las peliculas necesita saber el tipo en el if statement
//4. (DETALLE MENOR)algun tip/funcion para imprimir mas prolijo, estuve jugando con setwith y otros formatos, pero siempre hay
//		algun que otro atributo que se sale y no queda 'lindo'



//TASKS FOR NEXT DEADLINE  (PURPOSES)
//1. ver que onda con los admins (franco)
//2. implmentacion de mas sobrecarga
//3. definir paises y desponibilidad de contenidos	(franco)
//5. implementar el logger
//6. realizar las estadisticas
//7. optimizar el ordenamiento empleado con respecto a las listas (probar con lambdas functions)
//8. automatizar el main con rand y formar data en vectores (MULTIPLES FOR)  (franco)
//		agrgue personas con un rand_int/lo mismo con peliculas/audio/juegos
//		tambien se creara un vector que contenga todos los atributos posibles de seleccion
//		ahora se procedio a una realizacion mecanica
//9. definir mas criterios de busqueda para las listas  (franco)
//10. SIMULAR!!!



int main() {
	cStreamingService PLATAFORMA;  //SE CREA LA PLATAFORMA
	cPeliculas* pel = new cPeliculas(31, "V de Vendetta", documental, 23);
	PLATAFORMA.AgregarServicio(pel);
	PLATAFORMA.QuitarServicio(pel);
	PLATAFORMA.ListarServicio();
	//Se cargan algunos que otros servicios:
	//AUDIOS
	PLATAFORMA + new cAudio(2, "zaragoza historia", cancion, 14);
	PLATAFORMA + new cAudio(1, "can can", cancion, 12);
	PLATAFORMA + new cAudio(2, "hey jude", cancion, 11);
	PLATAFORMA + new cAudio(1, "boogie woogie", cancion, 62);
	PLATAFORMA + new cAudio(2, "nobody", audioLibro, 3);
	PLATAFORMA + new cAudio(1, "let it be", podcast, 23);

	//PELICULAS (int tiempoDeUso, string nombre, ePeliculas categoria, int duracion)
	PLATAFORMA+ new cPeliculas(20, "El Padrino", accion, 14);
	PLATAFORMA + new cPeliculas(12, "Pulp fiction", comedia, 12);
	PLATAFORMA + new cPeliculas(21, "Lobo de Wall Stret", comedia, 11);
	PLATAFORMA + new cPeliculas(41, "Codigo da Vinci", misterio, 62);
	PLATAFORMA + new cPeliculas(2, "Los Vengadores", accion, 3);
	PLATAFORMA + new cPeliculas(31, "V de Vendetta", documental, 23);
	
	//JUEGOS (int tiempoDeUso, string nombre, eJuegos categoria)
	PLATAFORMA + new cJuegos(20, "CS-GO", armas);
	PLATAFORMA + new cJuegos(12, "Family", ropa);
	PLATAFORMA + new cJuegos(21, "GTA", multijugador);
	PLATAFORMA + new cJuegos(41, "Sims", ropa);
	PLATAFORMA + new cJuegos(2, "Call of duty", armas);
	PLATAFORMA + new cJuegos(31, "FIFA 20", deportes);
	


	//Dado el exito del departamento de marketing a la hora de anunciar nuestra platforma
	//se SUBSCRIBEN LOS PRIMEROS Clientes y se emplean administradores que pueden 
	//administrar el cotenido(agregar pelis, audios, eliminar, etc) y subscriptores(dar de baja, etc)

	//Se decide la creacion de una base de datos que alacene los datos de todos los usuarios/administradores
	
	
	//USUARIO (eCliente tipo, string nombre, string apellido, string username, string pais, string contrasenia)

	cBaseDatos BaseDeDatos; //SE podria hacer una sobrecarga tambien
	cUsuario* Usuario = new cUsuario(gratis, "carlos", "alfonso", "carlitosalf", "argentina", "alfonsito19");
	BaseDeDatos.AgregarPersonas(Usuario);
	Usuario = new cUsuario(gratis, "javier", "alonso", "carlitosalf", "argentina", "alfonsito19");
	BaseDeDatos.AgregarPersonas(Usuario);
	//BaseDeDatos + (Usuario);
	Usuario = new cUsuario(premium, "ramon", "schumann", "carlitosalf", "argentina", "alfonsito19");
	BaseDeDatos.AgregarPersonas(Usuario);
	Usuario = new cUsuario(gratis, "franco", "shumacher", "carlitosalf", "argentina", "alfonsito19");
	BaseDeDatos.AgregarPersonas(Usuario);
	Usuario = new cUsuario(gratis, "sol", "lizst", "carlitosalf", "argentina", "alfonsito19");
	BaseDeDatos.AgregarPersonas(Usuario);
	Usuario = new cUsuario(premium, "francisco", "perez", "carlitosalf", "argentina", "alfonsito19");
	BaseDeDatos.AgregarPersonas(Usuario);

	cout << "LISTA DE JUEGOS POR NOMBRE ORDENADO" << endl;
	PLATAFORMA.ListarServicioNombreOrdenado();
	for (int i = 0;i < 3;i++) { cout<<endl; }
	cout << "*************************"<<endl;
	/*cout << "LISTA DE PELICULAS POR NOMBRE ORDENADO" << endl;
	PLATAFORMA.ListarPeliculaNombreOrdenado();
	for (int i = 0;i < 3;i++) { cout << endl; }
	cout << "*************************" << endl;
	cout << "LISTA DE AUDIOS POR NOMBRE ORDENADO" << endl;
	PLATAFORMA.ListarAudiosNombreOrdenado();
	for (int i = 0;i < 3;i++) { cout << endl; }
	cout << "*************************" << endl;*/


	//Usuarios comianzan a interactuar con nuestra plataforma

	//usuario debe acceder a cServicio para poder reproducir-iniciar-pausar...etc
	//cServicio es una padre --> todos estos objetos estan en una lista de cStraming
	//Usuarios debenn llamar a cStreamingService y de ahi seleccionar de la lista del servicio que gustan
	//seleccionan el elemento y ponen reproducir
	//que quierre hacer? ver peliculas /escuchar audios/ jugar?
	//opcion = 1
	//se muestra en pantalla todas las peliculas
	//cAudio AudioSeleccionado = PLATAFORMA.GetAudio();
	//desea reproducir el servicio seleccionado?
	//reproducir...
	//bool salir=false
	//for co-n un maximo de duracion del elemento
	//		if (imput=="parar")
	//			desea reanudar el elemento?
	//				si->continue 
	//			no->salir=true
	//			break
	//if salir == true:
	//		int parar()  //necesito saber el tiempo
	//return tiempo que paso en el proceso


	return 0;
}