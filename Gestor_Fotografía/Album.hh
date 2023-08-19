/**@file Album.hh
   @brief Cabeceras de la clase Album.

*/

#ifndef ALBUM_HH
#define ALBUM_HH
#include "Foto.hh"
#include "Fecha.hh"
class Album{

private:
/** @brief Contiene el identificador (string) del album.
    \pre El identificador no puede ser "ALL".
  */
    string identificador;
////////////////////////////////////
/** @brief Contiene las fotos del album.
  */
    map <string, Foto> cjt_fotos;
////////////////////////////////////
/** @brief Iterador que recorre cjt_fotos, util a la hora de recorrer el album desde fuera de la clase.
  */
    map <string, Foto>::const_iterator actual;
////////////////////////////////////
public:

//CONSTRUCTORA:


/** @brief <b>Constructora</b> de album.
    \pre <b>Cierto</b>.
    \post Crea un album vacio con el iterador <b>actual</b> apuntando a <b>cjt_fotos</b>.begin().
    */
  Album();
////////////////////////////////////
/** @brief <b>Constructora</b> de album.
  \pre <b>Cierto</b>.
  \post Crea un album vacio con <b>string id</b> como identificador e iterador <b>actual</b> apuntando a <b>cjt_fotos</b>.begin().
  */
  Album(const string& id);
////////////////////////////////////


//MODIFICADORA:

/** @brief Añade foto al album.
  \pre <b>Cierto</b>.
  \post Añade la foto al album, si no se encuentra ya en el, e informa del resultado de la operacion
  \post con <b>cierto</b> si se ha añadido o <b>falso</b> en caso contrario.
  */
  bool agrega_foto(const Foto& f);

////////////////////////////////////

/** @brief Inserta una foto en el album.
    \pre <b>Se sabe que la foto no existe en el album</b>.
    \post Añade la foto al album.
    */
  void inserta_foto(const Foto& f);
////////////////////////////////////
/** @brief Elimina una foto del album.
  \pre <b>Cierto</b>.
  \post Si la foto con el identificador "id" se encuentraba en el album, la elimina.
  \post Si la ha eliminado devuelve <b>true</b>, en caso contrario devuelve <b>false</b>.
  */
  bool elimina_foto(const string& id);
  ////////////////////////////////////
/** @brief El parametro implicito es la interseccion del album <b>alb1</b> y del album <b>alb2</b>.
    \pre <b>Cierto</b>.
    \post Se ha modificado el parametro implicito de forma que ahora solo contiene las fotos que pertenecen a los 2 albumes (alb1 y alb2).
    */
  void AND(Album& alb1, Album& alb2);
////////////////////////////////////
/** @brief Al parametro implicito se le han quitado las fotos de alb1.
    \pre alb2 es un <b>subconjunto</b> del album parametro implicito.
    \post El album parametro implicito no contiene ahora las fotos que contenia su subconjunto (alb1).
    */
  void NOT(Album& alb1);

///////////////////////////////////
/** @brief Une los dos conjuntos (albumes) en uno solo.
    \pre <b>Cierto</b>.
    \post El objeto implicito es ahora la unión del album implicito y el pasado como argumento.
    */
  void OR(const Album& b);

///////////////////////////////////

/** @brief Deja el album totalmente vacio.
    \pre <b>Cierto</b>.
    \post Todos los atributos del objeto pasan a estar vacios y el iterador pasa a apunntar a cjt_fotos.begin();
    */
  void clear();
/////////////////////////////////////
/** @brief Modifica el identificador del album.
    \pre <b>Cierto</b>.
    \post El identificador del objeto implicito Ha sido sustituido por el identificador <b>id</b>.
    */
  void mod_id(const string& id);



//CONSULTORA:



/** @brief Informa de si una foto se encuentra en el parametro implicito.
    \pre <b>Cierto</b>.
    \post Se ha devuelto <b>true</b> o <b>false</b> dependiendo si la foto se encuentra en el parametro implicito o no respectivamente.
    */
  bool existe_foto(const string& id);
////////////////////////////////////

/** @brief Informa de si se encuentra la foto en el album y en caso afirmativo devuelve la foto tambien.
  \pre <b>Cierto</b>.
  \post Devuelve si se encuentra o no mediante <b>bool& b</b>.
  \post Además modifica por referencia la foto con el identificador "id" si esta se encuentra en el album.
  */
  bool obten_foto(const string& id, Foto& f) const;
/////////////////////////////////////
/** @brief Dadas 2 fechas y un album, modifica el album <b>result</b> para que contenga las fotos que estan entre las fechas dadas del parametro implicito.
    \pre <b>Cierto</b>.
    \post El album <b>result</b> contiene ahora las fotos que estan entre las 2 fechas dadas y que se encontraban en el parametro implicito.
    */
  void busca_fotos_fecha(const Fecha& inferior, const Fecha& superior, Album& result);
/////////////////////////////////////
/** @brief Dada una etiqueta, las fotos que estaban en el album parametro implicito y que contienen esa etiqueta, se añaden al album result.
    \pre <b>Cierto</b>.
    \post El album <b>result</b> contiene ahora las fotos que se encontraban en el album parametro implicito y que contenian la etiqueta dada.
    */
  void busca_fotos_etiqueta(const string& etiq_buscada, Album& result);
////////////////////////////////////

/** @brief Informa del numero de fotos del album.
  \pre <b>Cierto</b>.
  \post Devuelve el numero de fotos que contiene el album.
  */

  int nr_fotos() const;
////////////////////////////////////
/** @brief Devuelve el identificador del album.
  \pre <b>Cierto</b>.
  \post se ha devuelto el identificador del album.
  */
  string consulta_id()const;
////////////////////////////////////

/** @brief Devuelve la primera foto del map, apuntada por el iterador actual.
    \pre <b>Cierto</b>.
    \post La primera foto del album, apuntada por el iterador actual (apunta a cjt_fotos.begin()), se ha devuelto por referencia en la <b>Foto f</b>.
    */

  void primera_foto(Foto& f);
////////////////////////////////////
/** @brief Devuelve las siguientes fotos del map, posteriores a  la primera, apuntada por el iterador actual.
    \pre <b>Cierto</b>.
    \post Una foto posterior a la primera foto del album, apuntada por el iterador actual (este se desplaza con ++actual), se ha devuelto por referencia en la <b>Foto f</b>.
    */
  void siguiente_foto(Foto& f);
////////////////////////////////////



  //ENTRADA/SALIDA




  /** @brief Asigna identificador e introduce las fotos en el album.
    \pre <b>Cierto</b>.
    \post Se ha creado un album con identificador y fotos.
    */

  void lee_album();
////////////////////////////////////

/** @brief Muestra el identificador del album, el identificador de las fotos y toda la informacion relacionada con ellas.
  \pre <b>Cierto</b>.
  \post El canal de salida ha recibido el identificador del album, el de las fotos(en orden lexicografico ascendente), la fecha y etiquetas de esta.
  */
  void imprime_album() const;
////////////////////////////////////
/** @brief Define el operador <b>=</b>.
    \pre <b>Cierto</b>.
    \post Se ha creado una copia del album b (en el parametro implicito) asegurandonos que todos los atributos estan por defecto.
    */
  Album& operator=(const Album& b);
};

#endif
