/**@file Foto.cc
   @brief Codigo de la clase Foto.

*/

#include "Foto.hh"

//CONSTRUCTORA:


/** @brief <b>Constructora</b> de foto.
    \pre <b>Cierto</b>.
    \post Crea una foto nueva vacia.
    */
Foto::Foto(){

}
////////////////////////////////////

//MODIFICADORA


/** @brief  Añade etiqueta.
    \pre <b>Cierto</b>.
    \post La foto ha sido modificada añadiendole la etiqueta <b>s</b> si esta no existía.
    */
void Foto::agrega_etiqueta(const string& s){
    etiq.insert(s);
}

////////////////////////////////////

/** @brief  Elimina etiqueta.
    \pre <b>Cierto</b>.
    \post La foto ha sido modificada eliminando la etiqueta <b>s</b> si existía.
*/
void Foto::elimina_etiqueta(const string& s){

    etiq.erase(s);
}

////////////////////////////////////

//CONSULTORAS:


/** @brief  Indica si la etiqueta existe.
    \pre <b>Cierto</b>.
    \post Devuelve <b>true</b> si existe la etiqueta <b>s</b>, <b>false</b> en caso contrario.
*/
bool Foto::contiene_etiqueta(const string& s) const{

      return etiq.find(s) != etiq.end();
}
////////////////////////////////////

/** @brief  Consultora de identificador de la foto.
  \pre <b>Cierto</b>.
  \post Devuelve el identificador de la foto.
  */
string Foto::id_foto() const{
    return identificador;
}
////////////////////////////////////
/** @brief  Consultora de la fecha de la foto.
  \pre <b>Cierto</b>.
  \post Devuelve la fecha en la que fue tomada de la foto.
  */
Fecha Foto::fecha_toma() const{
    return data;
}
////////////////////////////////////
/** @brief  Consultora de la cantidad de etiquetas de la foto.
  \pre <b>Cierto</b>.
  \post Devuelve la cantidad de etiquetas que tiene la foto.
  */
int Foto::nr_etiquetas() const{

    return etiq.size();
}
////////////////////////////////////


//ENTRADA/SALIDA



/** @brief  Introduce identificador, fecha y las etiquetas de la foto.
    \pre <b>Cierto</b>.
    \post La foto ha sido modificada con un identificador, fecha y las etiquetas.
*/
void Foto::crea_foto(){
    cin >> identificador;
    data.leer_fecha();
    int size;
    cin >> size;

    for (int i = 0; i < size; ++i){
          string e;
          cin >> e;
          etiq.insert(e);
    }

}

////////////////////////////////////
/** @brief  Muestra la información de la foto por el canal de salida.
  \pre <b>Cierto</b>.
  \post Se muestra identificador, fecha y etiquetas por el canal de salida.
  */
void Foto::imprime_foto() const{
    cout << identificador << ' ';
    data.escribir_fecha();
    cout << ' ' << etiq.size();
    for(set<string>::iterator it = etiq.begin(); it != etiq.end(); ++it){
        cout << ' ' << *it;
    }
    cout << endl;
}
