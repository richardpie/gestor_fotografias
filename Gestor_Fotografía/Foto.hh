/**@file Foto.hh
   @brief Cabeceras de la clase Foto.

*/

#ifndef FOTO_HH
#define FOTO_HH

#include "Fecha.hh"



class Foto{


private:
/** @brief Contiene el identificador (string) de la foto.
  */
  string identificador;
/////////////////////////////////////
/** @brief Contiene la fecha de la foto.

  */
  Fecha data;
////////////////////////////////////

/** @brief Contiene las etiquetas asignadas a la foto.

  */

  set<string> etiq;
////////////////////////////////////


public:
//CONSTRUCTORA:


/** @brief <b>Constructora</b> de foto.
    \pre <b>Cierto</b>.
    \post Crea una foto nueva vacia.
    */
  Foto();
////////////////////////////////////

//MODIFICADORA


/** @brief  Añade etiqueta.
    \pre <b>Cierto</b>.
    \post La foto ha sido modificada añadiendole la etiqueta <b>s</b> si esta no existía.
    */
  void agrega_etiqueta(const string& s);

////////////////////////////////////

/** @brief  Elimina etiqueta.
    \pre <b>Cierto</b>.
    \post La foto ha sido modificada eliminando la etiqueta <b>s</b> si existía.
*/
  void elimina_etiqueta(const string& s);

////////////////////////////////////

//CONSULTORAS:


/** @brief  Indica si la etiqueta existe.
    \pre <b>Cierto</b>.
    \post Devuelve <b>true</b> si existe la etiqueta <b>s</b>, <b>false</b> en caso contrario.
*/
  bool contiene_etiqueta(const string& s) const;
////////////////////////////////////

/** @brief  Consultora de identificador de la foto.
    \pre <b>Cierto</b>.
    \post Devuelve el identificador de la foto.
*/
  string id_foto() const;
////////////////////////////////////
/** @brief  Consultora de la fecha de la foto.
    \pre <b>Cierto</b>.
    \post Devuelve la fecha en la que fue tomada de la foto.
*/
  Fecha fecha_toma() const;
////////////////////////////////////
/** @brief  Consultora de la cantidad de etiquetas de la foto.
    \pre <b>Cierto</b>.
    \post Devuelve la cantidad de etiquetas que tiene la foto.
*/
  int nr_etiquetas() const;
////////////////////////////////////


//ENTRADA/SALIDA


/** @brief  Introduce identificador, fecha y las etiquetas de la foto.
    \pre <b>Cierto</b>.
    \post La foto ha sido modificada con un identificador, fecha y las etiquetas.
*/
  void crea_foto();

////////////////////////////////////
/** @brief  Muestra la información de la foto por el canal de salida.
    \pre <b>Cierto</b>.
    \post Se muestra identificador, fecha y etiquetas por el canal de salida.
*/
  void imprime_foto() const;
////////////////////////////////////

};

#endif
