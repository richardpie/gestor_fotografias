/**@file Album.cc
   @brief Codigo de la clase Album.

*/

#include "Album.hh"


//CONSTRUCTORA:


/** @brief <b>Constructora</b> de album.
    \pre <b>Cierto</b>.
    \post Crea un album vacio con el iterador <b>actual</b> apuntando a <b>cjt_fotos</b>.begin().
    */
Album::Album(){
    actual = cjt_fotos.begin();
}
////////////////////////////////////
/** @brief <b>Constructora</b> de album.
  \pre <b>Cierto</b>.
  \post Crea un album vacio con <b>string id</b> como identificador e iterador <b>actual</b> apuntando a <b>cjt_fotos</b>.begin().
  */
Album::Album(const string& id){
    identificador = id;
    actual = cjt_fotos.begin();
}
////////////////////////////////////


//MODIFICADORA:



/** @brief Añade foto al album.
  \pre <b>Cierto</b>.
  \post Añade la foto al album, si no se encuentra ya en el, e informa del resultado de la operacion
  \post con <b>cierto</b> si se ha añadido o <b>falso</b> en caso contrario.
  */
bool Album::agrega_foto(const Foto& f){
    bool b;
    if(cjt_fotos.find(f.id_foto()) == cjt_fotos.end()) {
        cjt_fotos.insert(make_pair(f.id_foto(), f));
        b = true;
    }
    else
        b = false;

    return b;
}

////////////////////////////////////
/** @brief Inserta una foto en el album.
    \pre <b>Se sabe que la foto no existe en el album</b>.
    \post Añade la foto al album.
    */
void Album::inserta_foto(const Foto& f) {
    cjt_fotos.insert(make_pair(f.id_foto(), f));
}
////////////////////////////////////

/** @brief Elimina una foto del album.
  \pre <b>Cierto</b>.
  \post Si la foto con el identificador "id" se encuentraba en el album, la elimina.
  \post Si la ha eliminado devuelve <b>true</b>, en caso contrario devuelve <b>false</b>.
  */
bool Album::elimina_foto(const string& id) {
    bool b = false;
    if(cjt_fotos.find(id) != cjt_fotos.end()) {
        cjt_fotos.erase(id);
        b = true;
    }
    return b;
}

////////////////////////////////////

/** @brief El parametro implicito es la interseccion del album <b>alb1</b> y del album <b>alb2</b>.
  \pre <b>Cierto</b>.
  \post Se ha modificado el parametro implicito de forma que ahora solo contiene las fotos que pertenecen a los 2 albumes (alb1 y alb2).
  */
void Album::AND(Album& alb1, Album& alb2){



    for(alb1.actual = alb1.cjt_fotos.begin(); alb1.actual != alb1.cjt_fotos.end(); ++alb1.actual){

      if(alb2.existe_foto(alb1.actual->first))
          agrega_foto(alb1.actual->second);
    }

}
////////////////////////////////////
/** @brief Al parametro implicito se le han quitado las fotos de alb1.
    \pre alb2 es un <b>subconjunto</b> del album parametro implicito.
    \post El album parametro implicito no contiene ahora las fotos que contenia su subconjunto (alb1).
    */
  void Album::NOT(Album& alb1){

      for(alb1.actual = alb1.cjt_fotos.begin(); alb1.actual != alb1.cjt_fotos.end(); ++alb1.actual){

        if(existe_foto(alb1.actual->first))
            cjt_fotos.erase(alb1.actual->first);
      }


  }
////////////////////////////////////
/** @brief Une los dos conjuntos (albumes) en uno solo.
    \pre <b>Cierto</b>.
    \post El objeto implicito es ahora la unión del album implicito y el pasado como argumento.
    */
void Album::OR(const Album& b){

    for(map<string,Foto>::const_iterator it = b.cjt_fotos.begin();
    it != b.cjt_fotos.end(); ++it){

        (*this).agrega_foto(it->second);
    }



}
////////////////////////////////////
/** @brief Deja el album totalmente vacio.
    \pre <b>Cierto</b>.
    \post Todos los atributos del objeto pasan a estar vacios y el iterador pasa a apunntar a cjt_fotos.begin();
    */
void Album::clear(){
    identificador = "";
    cjt_fotos.clear();
    actual = cjt_fotos.begin();
}
////////////////////////////////////
/** @brief Modifica el identificador del album.
    \pre <b>Cierto</b>.
    \post El identificador del objeto implicito Ha sido sustituido por el identificador <b>id</b>.
    */

void Album::mod_id(const string& id){

    identificador = id;
}



//CONSULTORA:

////////////////////////////////////


/** @brief Informa de si una foto se encuentra en el parametro implicito.
    \pre <b>Cierto</b>.
    \post Se ha devuelto <b>true</b> o <b>false</b> dependiendo si la foto se encuentra en el parametro implicito o no respectivamente.
    */
bool Album::existe_foto(const string& id){
    return cjt_fotos.find(id) != cjt_fotos.end();
}
////////////////////////////////////
/** @brief Informa de si se encuentra la foto en el album y en caso afirmativo devuelve la foto tambien.
  \pre <b>Cierto</b>.
  \post Devuelve si se encuentra o no mediante <b>bool& b</b>.
  \post Además modifica por referencia la foto con el identificador "id" si esta se encuentra en el album.
  */
bool Album::obten_foto(const string& id, Foto& f) const {


    map<string, Foto>::const_iterator it = cjt_fotos.find(id);
    bool b = (it != cjt_fotos.end());



    if(b)
        f = it->second;

    return b;

}
///////////////////////////////////////

/** @brief Dadas 2 fechas y un album, modifica el album <b>result</b> para que contenga las fotos que estan entre las fechas dadas del parametro implicito.
    \pre <b>Cierto</b>.
    \post El album <b>result</b> contiene ahora las fotos que estan entre las 2 fechas dadas y que se encontraban en el parametro implicito.
    */
void Album::busca_fotos_fecha(const Fecha& inferior, const Fecha& superior, Album& result){

    for(map<string,Foto>::const_iterator it = cjt_fotos.begin()
      ; it != cjt_fotos.end(); ++it){

          if((it->second).fecha_toma() <= superior and
          inferior <= (it->second).fecha_toma()){

            result.agrega_foto(it->second);

          }
    }

}
/////////////////////////////////////
/** @brief Dada una etiqueta, las fotos que estaban en el album parametro implicito y que contienen esa etiqueta, se añaden al album result.
    \pre <b>Cierto</b>.
    \post El album <b>result</b> contiene ahora las fotos que se encontraban en el album parametro implicito y que contenian la etiqueta dada.
    */
void Album::busca_fotos_etiqueta(const string& etiq_buscada, Album& result){

    for(map<string,Foto>::const_iterator it = cjt_fotos.begin()
      ; it != cjt_fotos.end(); ++it){

          if((it->second).contiene_etiqueta(etiq_buscada)){

            result.agrega_foto(it->second);

          }
    }

}

////////////////////////////////////
/** @brief Informa del numero de fotos del album.
  \pre <b>Cierto</b>.
  \post Devuelve el numero de fotos que contiene el album.
  */
int Album::nr_fotos() const {
    return cjt_fotos.size();


}
////////////////////////////////////
/** @brief Devuelve el identificador del album.
  \pre <b>Cierto</b>.
  \post se ha devuelto el identificador del album.
  */
string Album::consulta_id()const{
    return identificador;
}

////////////////////////////////////
/** @brief Devuelve la primera foto del map, apuntada por el iterador actual.
    \pre <b>Cierto</b>.
    \post La primera foto del album, apuntada por el iterador actual (apunta a cjt_fotos.begin()), se ha devuelto por referencia en la <b>Foto f</b>.
    */

void Album::primera_foto(Foto& f){

    actual = cjt_fotos.begin();

    if(actual != cjt_fotos.end()) {

        f = actual->second;
    }

}
////////////////////////////////////
/** @brief Devuelve las siguientes fotos del map, posteriores a  la primera, apuntada por el iterador actual.
    \pre <b>Cierto</b>.
    \post Una foto posterior a la primera foto del album, apuntada por el iterador actual (este se desplaza con ++actual), se ha devuelto por referencia en la <b>Foto f</b>.
    */

void Album::siguiente_foto(Foto& f){

    ++actual;
    if(actual != cjt_fotos.end()) {

        f = actual->second;
    }

}

////////////////////////////////////





//ENTRADA/SALIDA:




/** @brief Asigna identificador e introduce las fotos en el album.
  \pre <b>Cierto</b>.
  \post Se ha creado un album con identificador y fotos, y se informa de ello.
  */

void Album::lee_album(){
    cjt_fotos.clear();
    cin >> identificador;
    cout << "# lee_album " << identificador << " ..." << endl;
    int size;
    cin >>size;

    for(int i = 0; i < size; ++i){
        Foto f;
        f.crea_foto();
        cjt_fotos.insert(make_pair(f.id_foto(),f));


    }
    cout << "Album " << identificador << " leido." << endl;
}
////////////////////////////////////
/** @brief Muestra el identificador del album, el identificador de las fotos y toda la informacion relacionada con ellas.
  \pre <b>Cierto</b>.
  \post El canal de salida ha recibido el identificador del album, el de las fotos(en orden lexicografico ascendente), la fecha y etiquetas de esta.
  */
void Album::imprime_album() const{

    cout << identificador << endl;
    for(map<string, Foto>::const_iterator it = cjt_fotos.begin(); it != cjt_fotos.end(); ++it){

        cout << "  ";
        it->second.imprime_foto();
    }
}
////////////////////////////////////
/** @brief Define el operador <b>=</b>.
    \pre <b>Cierto</b>.
    \post Se ha creado una copia del album b (en el parametro implicito) asegurandonos que todos los atributos estan por defecto.
    */
Album& Album::operator=(const Album& b){

    identificador = b.identificador;
    cjt_fotos = b.cjt_fotos;
    actual = cjt_fotos.begin();
    return *this;

}
