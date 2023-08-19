/**@file Coleccion.cc
   @brief Codigo de la clase Coleccion.

*/

#include "Coleccion.hh"

//CONSTRUCTORA:


/** @brief <b>Constructora</b> de Coleccion.
    \pre <b>Cierto</b>.
    \post Crea una coleccion vacia, con album ALL vacio y su respectiva entrada en col_album.
    */
Coleccion::Coleccion(){

    todo.mod_id("ALL");
    col_album["ALL"];
}

////////////////////////////////////

//MODIFICADORA:



/** @brief Agrega un album a la coleccion y sincroniza las fotos.
    \pre <b>Sabemos</b> que no se encuentra en la coleccion un album con el identificador del album que queremos agregar.
    \post Si una foto del album no estaba en la coleccón, esta se añade a la coleccion.
    \post Si ya estaba, el album queda sobreescrito por la foto de la coleccion con el mismo identificador.
    */
void Coleccion::agrega_album(Album& agregado){

        Fotos_album id_fotos;                                          //set para guardar las fotos del nuevo album


        map<string, Fotos_album>::iterator it = col_album.find("ALL"); //Los identificadores de las nuevas fotos tambien deben añadirse en al set de identificadores
                                                                       //de foto del album ALL en col_album.




        int size = agregado.nr_fotos();
        for(int i = 0; i < size; ++i){
            Foto f;
            if(i == 0)
                agregado.primera_foto(f);                              //f es ahora la primera foto del album que se agrega a la coleccion.
            else
                agregado.siguiente_foto(f);                            //f es ahora una foto posterior a la primera del album que se agrega a la coleccion.

            if (not todo.existe_foto(f.id_foto())){                    //Si la foto que hemos sacado del album agregado ya existia en la coleccion, no se hace nada, y en un futuro, cuando
                                                                       //queramos extraer dicha foto de la coleccion, extraeremos la que ya estaba en la coleccion antes de agregar el album.
                todo.agrega_foto(f);                                   //En cambio si no estaba, se añade la foto al
                                                                       //album todo (tanto al album todo como a "ALL" en col_album (el map de id_de_album, nombre_fotos_de_album)).

                (it->second).insert(f.id_foto());
            }

            id_fotos.insert(f.id_foto());                             //Vamos rellenando el set que contiene el nombre de las fotos del "album agregado" en cada iteracion.

        }

        col_album.insert(make_pair(agregado.consulta_id(), id_fotos));//Al salir del bucle se inserta el pair de <identificador de album, set con nombre de las fotos del album> en col_album.


        obten_album(agregado.consulta_id(), agregado);                //Se obtiene el album para actualizarlo con las fotos que ya estaban en la coleccion.




}
////////////////////////////////////
/** @brief Elimina un album con la id indicada si este se encuentra en la coleccion.
    \pre El album no puede ser <b>ALL</b>.
    \post El album ha sido eliminado pero la coleccion matiene las fotos del album (en el album "ALL") y, tanto si se lleva a cabo la accion como si no, se informa de ello.
    */
void Coleccion::elimina_album(const string& id){
    cout << "# elimina_album " << id << endl;
    if(contiene_album(id)){
        col_album.erase(id);
        cout << "Album eliminado de la coleccion." << endl;
    }
    else
        cout << "Identificador de album incorrecto. No se puede eliminar." << endl;
}
////////////////////////////////////
/** @brief Indica si la coleccion contiene el album indicado, en caso afirmativo devuelve el album.
    \pre <b>Cierto</b>.
    \post Se ha indicado si la coleccion contiene el album en cuestion, si la
    \post indicacion es positiva, se devuelve el album tambien por referencia.
    */
bool Coleccion::obten_album(const string& id, Album& album_a_obtener) const{
    bool found;

    if(album_a_obtener.consulta_id() != "ALL"){ //Si el album no es ALL

        if(col_album.find(id) != col_album.end()){ //Se busca si existe el album con la id dada en la coleccion.

            set<string>::const_iterator it_final= ((col_album.find(id))->second).end(); //Iterador al set de strings que contiene los identificadores de las fotos del album.

            Album result (id);  // Se crea un album con la id dada.
            for(set<string>::const_iterator it = ((col_album.find(id))->second).begin();
            it != it_final; ++it){
                Foto f;
                todo.obten_foto(*it, f);
                result.inserta_foto(f);//Se agregan las fotos al album result que se sabe vacío y como el album ALL no tiene fotos repetidas la foto inserta sabemos que no se encontraba.

            }

            album_a_obtener = result;
            found = true; //Se ha encontrado el album y se ha copido al album_a_obtener.
        }

        else
            found = false; //No se ha encontrado el album buscado dentro de la coleccion.

    }


    else {
      album_a_obtener = todo;//Si el album buscado era "ALL" se hace una copia del album "todo" de la coleccion.
      found = true; //Se ha encontrado el album y se ha copido al album_a_obtener.
    }


    return found;
}
////////////////////////////////////

//CONSULTORA:



/** @brief Devuelve el identificador de la coleccion.
    \pre <b>Cierto</b>.
    \post se ha devuelto el identificador de la coleccion.
    */
string Coleccion::consulta_id()const{
    return identificador;
}
////////////////////////////////////
/** @brief Informa de si la coleccion contiene el album.
    \pre <b>Cierto</b>.
    \post Ha devuelto true si el album con el identificador dado estaba en la coleccion, false en caso contrario.
    */
bool Coleccion::contiene_album(const string& id)const{

    bool b = col_album.find(id) != col_album.end();

    return b;

}
////////////////////////////////////
/** @brief Devuelve el numero de albumes que contiene la coleccion (incluido "todo").
    \pre <b>Cierto</b>.
    \post Ha informado de la cantidad de albumes de la coleccion (incluido el album todo).
    */
int Coleccion::nr_albumes()const{
    return col_album.size();

}
////////////////////////////////////
/** @brief Escribe los identificadores de los albumes de la coleccion (Incluido "ALL").
  \pre <b>Cierto</b>.
  \post Los identificadores de los albumes de la coleccion se han mostrado por el canal de salida en orden lexicografico ascendente (incluido "ALL").
  */
void Coleccion::lista_albumes()const{
    bool space = true;
    for(map<string, Fotos_album>::const_iterator it = col_album.begin();
        it != col_album.end(); ++it){
        if (space)
          space = false;
        else
          cout << ' ';
        cout << it->first;

    }



    cout << endl;
}


//////////////////------------FOTOS------------//////////////////


//MODIFICADORA DE FOTO:


/** @brief Agrega una foto a la coleccion si esta no se encuentra ya en el album ALL.
  \pre <b>Cierto</b>.
  \post Si no existe foto con el identificador de la foto dada en el ALL , se ha añadido la foto y se informa de ello, en caso contrario solo imprime un informe de la situacion.
  */
void Coleccion::agrega_foto(const Foto& f){

    if(todo.agrega_foto(f)){ //El agrega foto de la clase album devuelve un bool a la vez que añade la foto (esto ultimo solo pasa si la foto no estaba, es decir, bool = true).
        cout << "Foto " << f.id_foto() << " agregada a la coleccion." << endl;

        (col_album.find("ALL")->second).insert(f.id_foto());

      }
    else
        cout << "Ya existe una foto con el mismo id. No se puede agregar." << endl;


}
////////////////////////////////////
/** @brief Elimina una foto de la coleccion (de todos los albumes a los que pertenecia).
  \pre  <b>Cierto</b>
  \post La foto ha sido eliminada de todos los albumes de la coleccion si se encuentra una foto con ese identificador en la coleccion y se informa de ello, en caso contrario solo imprime un informe de la situacion.
  */
void Coleccion::elimina_foto_coleccion(const string& id){
    if(todo.elimina_foto(id)){

        map<string,Fotos_album>::iterator final_map = col_album.end();

        for(map<string,Fotos_album>::iterator it_map = col_album.begin();
            it_map != final_map; ++it_map){

                (it_map->second).erase(id);


            }
        todo.elimina_foto(id);
        cout << "Foto " << id << " eliminada de la coleccion." << endl;
    }

    else
        cout << "No existe una foto con el id dado. No se puede eliminar." << endl;
}
////////////////////////////////////
/** @brief Dado un identificador y una foto con ese identificador, se sustituye la foto de la coleccion con ese identificador por la nueva.
  \pre <b>Cierto</b>
  \post La foto ha sido reemplazada por la nueva si se encuentra una foto con el identificador dado en la coleccion y se informa de ello, en caso contrario solo imprime un informe de la situacion.
  */
void Coleccion::modifica_foto(const string& id, const Foto& x){
    if(todo.existe_foto(id)) {
        todo.elimina_foto(id);
        todo.agrega_foto(x);
        cout << "Foto " << id << " modificada en la coleccion." << endl;
    }
    else
        cout << "No existe una foto con el id dado. No se puede modificar." << endl;
}
////////////////////////////////////

//CONSULTORA DE FOTO:


/** @brief Da el numero de albumes en el que se encuetra el identificador de la foto (excluido el album todo).
  \pre  <b>Cierto</b>
  \post Se ha devuelto el numero de albumes al que pertenece la foto (incluido el album todo).
  */
int Coleccion::nr_albumes_foto(const string& id) const{
      int cantidad = 0;
      for(map<string,Fotos_album>::const_iterator it = col_album.begin();
      it != col_album.end(); ++it) {

          if((it->second).find(id) != (it->second).end())
          ++cantidad;

      }
      return cantidad;
}
/////////////////////////////////////
/** @brief Dado el identificador de una foto muestra todos albumes a los que pertenece la foto en orden lexicografico.
  \pre <b>Cierto</b>
  \post Se ha mostrado los identificadores de los albumes a los que pertenece la foto(incluido el album todo) y se informa de la situacion (si no se ha encontrado la foto dada en toda la coleccion).
  */
void Coleccion::lista_albumes_foto(const string& id) {

    if(todo.existe_foto(id)){
        bool primero = true;
        for(map<string,Fotos_album>::const_iterator it = col_album.begin();
        it != col_album.end(); ++it) {
            if((it->second).find(id) != (it->second).end()) {
                if(primero)
                    primero = false;
                else
                    cout <<' ';
                cout << it->first;

            }

        }

        cout << endl;
    }
    else
        cout << "No existe una foto con el id dado." << endl;
}



//////////////////------------BUSQUEDA------------//////////////////


//CONSULTORA


/** @brief Modifica un album pasado por referencia para que contenga todas las fotos que cumplen la condincion de estar entre las fechas dadas.
  \pre <b>Cierto</b>
  \post Se ha modificado un album pasado por referencia, para que contenga todas las fotos que se encuentran entre las fechas dadas y se encontraban en el album con identificador id, y
  \post además, se modifica la id del album pasado por referencia por el identificador <b>nuevo</b>.
  */

void Coleccion::busca_por_fecha(const Fecha& inferior, const Fecha& superior,
const string& id, const string& nuevo, Album& en_c) {
    Album carry;
    en_c.clear();
    if(id != "ALL"){

          obten_album(id, carry);
          carry.busca_fotos_fecha(inferior, superior, en_c);

    }


    else{

        todo.busca_fotos_fecha(inferior, superior, en_c);

    }


    en_c.mod_id(nuevo);

}

/////////////////////////////////////
/** @brief Modifica un album pasado por referencia para que contenga todas las fotos que cumplen la condincion de tener la etiqueta especificada.
  \pre <b>Cierto</b>
  \post Se ha modificado un album pasado por referencia, para que contenga todas las fotos que contienen la etiqueta <b>etiq</b> y se encontraban en el album con identificador id, y
  \post además, se modifica la id del album pasado por referencia por el identificador <b>nuevo</b>.
  */
void Coleccion::busca_por_etiqueta(const string& etiq, const string& id, const string& nuevo, Album& en_c){
    Album carry;
    en_c.clear();
    if(id != "ALL"){

        obten_album(id, carry);

        carry.busca_fotos_etiqueta(etiq, en_c);

    }


    else{

        todo.busca_fotos_etiqueta(etiq, en_c);


        }

    en_c.mod_id(nuevo);
}
/////////////////////////////////////



//ENTRADA/SALIDA



/** @brief Imprime todos los albumes que componen la coleccion, incluido ALL.
      \pre <b>Cierto</b>
      \post Se han mostrado todos los albumes que contiene la coleccion (incluido todas las fotos de estos con su respectiva informacion).
      */
void Coleccion::imprime_coleccion() const{


  map<string,Fotos_album>::const_iterator final_map = col_album.end();

  for(map<string,Fotos_album>::const_iterator it_map = col_album.begin();
      it_map != final_map; ++it_map){
          Album search;


          obten_album(it_map->first, search);
          search.imprime_album();


      }


}
