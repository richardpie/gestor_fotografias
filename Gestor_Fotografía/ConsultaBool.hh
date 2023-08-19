/**@file ConsultaBool.hh
   @brief Cabeceras de la clase ConsultaBool.

*/


#ifndef CONSULTABOOL_HH
#define CONSULTABOOL_HH
#include "Coleccion.hh"
#include "Album.hh"
#include "Foto.hh"
#include "Fecha.hh"
#ifndef NO_DIAGRAM

struct token {
    string tipo; // tipo de la consulta: TAG, DATE, AND, OR o NOT
    string etq; // si tipo == "TAG", esta es la etiqueta
    Fecha fini, ffin; // si tipo == "DATE", estas son las fechas de inicio y fin
};
#endif

class ConsultaBool{

private:

/** @brief BinTree de token que contiene la consulta booleana.
    */
  BinTree <token> ConsultaTree;


public:

//CONSTRUCTORA:

/** @brief Crea una consulta con su arbol vacio.
    \pre <b>Cierto</b>.
    \post Se ha creado una consulta cuyo arbol atributo es un arbol vacio.
    */

  ConsultaBool();
////////////////////////////////
/** @brief Crea una consulta con la raiz del arbol como nodo tipo TAG y su respectiva etiqueta.
    \pre <b>Cierto</b>.
    \post Se ha creado una consulta cuyo arbol tiene como raiz un nodo con tk.tipo = "TAG"; y tk.etq = s;
    */
  ConsultaBool(const string& s);
////////////////////////////////
/** @brief Crea una consulta con la raiz del arbol atributo como nodo tipo DATE y sus respectivas fechas (fini, ffin).
    \pre <b>Cierto</b>.
    \post Se ha creado una consulta cuyo arbol tiene como raiz un nodo con tk.tipo = "DATE"; y tk.fini = fini y tk.ffin = ffin (fini y fin son las fechas proporcionadas como parametros);
    */


  ConsultaBool(const Fecha& fini, const Fecha& ffin);

////////////////////////////////

//MODIFICADORA:



/** @brief Se devuelve una consulta cuyo arbol representa la interseccion de los arboles de "consulta parametro implicito" y la consulta q2.
    \pre <b>Cierto</b>.
    \post Se ha devuelto una consulta cuya raiz es un nodo tipo "AND" y los hijos izquierdo y derecho son los arboles del objeto implicito y el arbol q2 (respectivamente).
*/

  ConsultaBool AND(const ConsultaBool& q2);
////////////////////////////////
/** @brief Se devuelve una consulta cuyo arbol representa la union de los arboles de "consulta parametro implicito" y la consulta q2.
    \pre <b>Cierto</b>.
    \post Se ha devuelto una consulta cuya raiz es un nodo tipo "OR" y los hijos izquierdo y derecho son los arboles del objeto implicito y el arbol q2 (respectivamente).
*/
  ConsultaBool OR(const ConsultaBool& q2) ;
////////////////////////////////
/** @brief  Se devuelve una consulta cuyo arbol solo tiene hijo izquierdo y este hijo izquierdo es el arbol de la "consulta parametro implicito".
    \pre <b>Cierto</b>.
    \post Se ha devuelto una consulta cuyo arbol tiene como raiz un nodo tipo "NOT" y un hijo izquierdo con la consulta "parametro implicito".
*/
  ConsultaBool NOT();
////////////////////////////////

//CONSULTORA:


/** @brief Recorre el arbol del parametro implicito y devuelve un album por referencia que cumple con las condiciones del arbol.
    \pre <b>Cierto</b>.
    \post El album <b>search</b> se ha modificado de forma que todas las fotos que contiene cumplen con las condiciones del arbol.
*/

  void evalua_consulta_booleana(Album& search);
////////////////////////////////


//ENTRADA/SALIDA:

/** @brief Introduce los datos para poder construir el arbol.
    \pre <b>Cierto</b>.
    \post El arbol se ha construido con todos los datos que se le ha suministrado a la funcion por el canal de entrada.
*/
  void read(istream& is);


};

#endif
