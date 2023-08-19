/**@file Coleccion.hh
   @brief Cabeceras de la clase Coleccion.

*/

#ifndef COLECCION_HH
#define COLECCION_HH
#include "Foto.hh"
#include "Album.hh"
#include "Fecha.hh"
class Coleccion{

private:
  /** @brief Album que contiene todas las fotos de la coleccion (ESTE ES EL ALBUM ALL y en la documentacion me refiero a el como todo(nombre del objeto) o como ALL (atributo identificador)).
      */
  Album todo;
////////////////////////////////////
  /** @brief Contiene los identificadores de todas las fotos de un album.
      */
  typedef set<string> Fotos_album;

////////////////////////////////////
  /** @brief Contiene todos albumes de la coleccion, el album ALL incluido.
      @brief El pair.first del map es el identificador del album y el pair.second del map es un set que contiene todos los identificadores de las fotos de ese album.
      */
  map<string, Fotos_album> col_album;
////////////////////////////////////

  /** @brief Identificador la coleccion.
      */
  string identificador;
////////////////////////////////////
public:

//CONSTRUCTORA:

  /** @brief <b>Constructora</b> de Coleccion.
      \pre <b>Cierto</b>.
      \post Crea una coleccion vacia, con album ALL vacio y su respectiva entrada en col_album.
      */
  Coleccion();

////////////////////////////////////


//MODIFICADORA:

/** @brief Agrega un album a la coleccion y sincroniza las fotos.
    \pre <b>Sabemos</b> que no se encuentra en la coleccion un album con el identificador del album que queremos agregar.
    \post Si una foto del album no estaba en la coleccón, esta se añade a la coleccion.
    \post Si ya estaba, el album queda sobreescrito por la foto de la coleccion con el mismo identificador.
    */
  void agrega_album(Album& a);
////////////////////////////////////
/** @brief Elimina un album con la id indicada si este se encuentra en la coleccion.
    \pre El album no puede ser <b>ALL</b>.
    \post El album ha sido eliminado pero la coleccion matiene las fotos del album (en el album "ALL") y, tanto si se lleva a cabo la accion como si no, se informa de ello.
    */
  void elimina_album(const string& id);
////////////////////////////////////
/** @brief Indica si la coleccion contiene el album indicado, en caso afirmativo devuelve el album.
    \pre <b>Cierto</b>.
    \post Se ha indicado si la coleccion contiene el album en cuestion, si la
    \post indicacion es positiva, se devuelve el album tambien por referencia.
    */
  bool obten_album(const string& id, Album& album_a_obtener) const;
////////////////////////////////////

//CONSULTORA:


/** @brief Devuelve el identificador de la coleccion.
    \pre <b>Cierto</b>.
    \post se ha devuelto el identificador de la coleccion.
    */
  string consulta_id()const;
////////////////////////////////////

/** @brief Informa de si la coleccion contiene el album.
    \pre <b>Cierto</b>.
    \post Ha devuelto true si el album con el identificador dado estaba en la coleccion, false en caso contrario.
    */
  bool contiene_album(const string& id)const;
////////////////////////////////////
/** @brief Devuelve el numero de albumes que contiene la coleccion (incluido "todo").
    \pre <b>Cierto</b>.
    \post Ha informado de la cantidad de albumes de la coleccion (incluido el album todo).
    */
  int nr_albumes()const;
////////////////////////////////////
/** @brief Escribe los identificadores de los albumes de la coleccion (Incluido "ALL").
  \pre <b>Cierto</b>.
  \post Los identificadores de los albumes de la coleccion se han mostrado por el canal de salida en orden lexicografico ascendente (incluido "ALL").
  */
  void lista_albumes()const;


//////////////////------------FOTOS------------//////////////////

//MODIFICADORA DE FOTO:


/** @brief Agrega una foto a la coleccion si esta no se encuentra ya en el album ALL.
  \pre <b>Cierto</b>.
  \post Si no existe foto con el identificador de la foto dada en el ALL , se ha añadido la foto y se informa de ello, en caso contrario solo imprime un informe de la situacion.
  */
  void agrega_foto(const Foto& f);
////////////////////////////////////
/** @brief Elimina una foto de la coleccion (de todos los albumes a los que pertenecia).
  \pre  <b>Cierto</b>
  \post La foto ha sido eliminada de todos los albumes de la coleccion si se encuentra una foto con ese identificador en la coleccion y se informa de ello, en caso contrario solo imprime un informe de la situacion.
  */
  void elimina_foto_coleccion(const string& id);
////////////////////////////////////
/** @brief Dado un identificador y una foto con ese identificador, se sustituye la foto de la coleccion con ese identificador por la nueva.
  \pre <b>Cierto</b>
  \post La foto ha sido reemplazada por la nueva si se encuentra una foto con el identificador dado en la coleccion y se informa de ello, en caso contrario solo imprime un informe de la situacion.
  */
  void modifica_foto(const string& id, const Foto& x);
////////////////////////////////////

//CONSULTORA DE FOTO:


/** @brief Da el numero de albumes en el que se encuetra el identificador de la foto (excluido el album todo).
  \pre  <b>Cierto</b>
  \post Se ha devuelto el numero de albumes al que pertenece la foto (incluido el album todo).
  */
  int nr_albumes_foto(const string& s) const;
/////////////////////////////////////
/** @brief Dado el identificador de una foto muestra todos albumes a los que pertenece la foto en orden lexicografico.
  \pre <b>Cierto</b>
  \post Se ha mostrado los identificadores de los albumes a los que pertenece la foto(incluido el album todo) y se informa de la situacion (si no se ha encontrado la foto dada en toda la coleccion).
  */
  void lista_albumes_foto(const string& id);



//////////////////------------BUSQUEDA------------//////////////////


//CONSULTORA


/** @brief Modifica un album pasado por referencia para que contenga todas las fotos que cumplen la condincion de estar entre las fechas dadas.
  \pre <b>Cierto</b>
  \post Se ha modificado un album pasado por referencia, para que contenga todas las fotos que se encuentran entre las fechas dadas y se encontraban en el album con identificador id, y
  \post además, se modifica la id del album pasado por referencia por el identificador <b>nuevo</b>.
  */
void busca_por_fecha(const Fecha& inferior, const Fecha& superior,
  const string& id, const string& nuevo, Album& en_c);

/////////////////////////////////////
/** @brief Modifica un album pasado por referencia para que contenga todas las fotos que cumplen la condincion de tener la etiqueta especificada.
  \pre <b>Cierto</b>
  \post Se ha modificado un album pasado por referencia, para que contenga todas las fotos que contienen la etiqueta <b>etiq</b> y se encontraban en el album con identificador id, y
  \post además, se modifica la id del album pasado por referencia por el identificador <b>nuevo</b>.
  */
void busca_por_etiqueta(const string& etiq, const string& id, const string& nuevo, Album& en_c);
/////////////////////////////////////


//ENTRADA/SALIDA:



/** @brief Imprime todos los albumes que componen la coleccion, incluido ALL.
      \pre <b>Cierto</b>
      \post Se han mostrado todos los albumes que contiene la coleccion (incluido todas las fotos de estos con su respectiva informacion).
      */
void imprime_coleccion() const;

};
#endif
