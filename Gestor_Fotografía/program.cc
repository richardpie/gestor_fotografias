/**@file program.cc
   @brief Main del programa de gestion de fotos.

*/
//NOTA: ESTOS INCLUDES SON PARA QUE SE VEAN EN EL GRAFICO.
#include "ConsultaBool.hh"
#include "Coleccion.hh"
#include "Album.hh"
#include "Foto.hh"
#include "Fecha.hh"

/**@brief Main del programa que consta de una coleccion (c_en_curso), un album (en_curso) y una string (s) para seleccionar la operacion deseada.
    \pre <b>Cierto</b>
    \post El programa acaba.
*/
int main(){
    Coleccion c_en_curso;
    Album en_curso;
    string s;

    while(cin >> s and s != "acabar") {
    /**@brief Mientras se sigan enviando operaciones diferentes de "acabar", el bucle continua trabajando sobre coleccion c_en_curso y album en_curso.
              \pre La string s <b>NO</b> contiene "acabar".
              \post El bucle acaba y c_en_curso y en_curso han sufrido modificaciones(o no) segun las operaciones seleccionadas durante el bucle.
          */

        if(s == "lee_album"){
        /**@brief Lee el album <b>en_curso</b>.
            \pre s == "lee_album".
            \post Al album <b>en_curso</b> se le ha introducido un identificador y las fotos desadas, además informa de si se está leyendo album o si se ha acabado de leer.
        */
            en_curso.lee_album();

        }



        else if(s == "agrega_foto"){
          /**@brief Agrega una foto al album <b>en_curso</b>.
              \pre s == "agrega_foto".
              \post Al album <b>en_curso</b> contiene ahora la foto si no ese encontraba ya en él e informa de ello, si no se le pudo agregar la foto, se informa de que ya la contenia.
          */
            Foto f;
            f.crea_foto();
            cout << "# agrega_foto " << f.id_foto() << " ..." << endl;
            if(en_curso.agrega_foto(f))
                cout << "Foto " << f.id_foto() << " agregada al album en curso." << endl;

            else
                cout << "El album en curso ya contiene una foto con el identificador " << f.id_foto() << endl;
        }



        else if(s == "elimina_foto"){
          /**@brief Elimina una foto del album <b>en_curso</b>.
              \pre s == "elimina_foto".
              \post Al album <b>en_curso</b> no contiene ahora la foto con el id dado si esta se encontraba ya en el e informa de ello, si no se pudo eliminar la foto, se informa de no la contenia.
          */
            string id;
            cin >> id;

            cout << "# elimina_foto " << id << endl;

            if(en_curso.elimina_foto(id)) //elimina_foto devuelve un bool
                cout << "Foto " << id << " eliminada del album en curso." << endl;
            else
                cout << "El album en curso no contiene una foto con el identificador " << id << endl;
        }



        else if(s == "obten_foto"){
          /**@brief Se saca una foto del album <b>en_curso</b>.
              \pre s == "obten_foto".
              \post Si el album en curso contenia la foto, esta se ha extraido y se imprime, si no, informa de que
              \post el album <b>en_curso</b> no contenia ninguna foto con la id proporcionada.
          */
            string id;
            cin >> id;
            Foto f;
            cout << "# obten_foto " << id << endl;
            if(en_curso.obten_foto(id, f)){ //obten_foto devuelve un bool

                f.imprime_foto();
              }
            else
                cout << "El album en curso no contiene una foto con el identificador " << id << endl;

        }


        else if(s == "nr_fotos"){
          /**@brief Informa de la cantidad de fotos que tiene el album <b>en_curso</b>.
              \pre s == "nr_fotos".
              \post Se ha mostrado por el canal de salida la cantidad de fotos que tiene el album <b>en_curso</b>.

          */
            cout << "# nr_fotos" << endl;
            cout << en_curso.nr_fotos() << endl;
        }



        else if(s == "agrega_album"){

          /**@brief Se añade a la coleccion <b>c_en_curso</b> album <b>en_curso</b>.
              \pre s == "agrega_album".
              \post El album <b>en_curso</b> se ha añadido a la coleccion y se imprime, en caso de que ya existiera
              \post en la coleccion un album con el mismo identificador, informa de que no se ha podido agregar.

          */
            cout << "# agrega_album" << endl;
            if(not c_en_curso.contiene_album(en_curso.consulta_id())){
                c_en_curso.agrega_album(en_curso);
                cout << "Album en curso agregado a la coleccion." << endl
                << "Album en curso, despues de agregar:" << endl;

                en_curso.imprime_album();
            }
            else{

              cout << "Identificador de album incorrecto. No se puede agregar." << endl;
            }
        }



        else if(s == "elimina_album"){
          /**@brief Se elimina un album de la coleccion<b>c_en_curso</b>.
              \pre s == "elimina_album".
              \post El album ha sido eliminado pero la coleccion matiene las fotos del album (en el album "ALL") y, tanto si se lleva a cabo la accion como si no, se informa de ello.

          */
            string id;
            cin >> id;
            c_en_curso.elimina_album(id);

        }


        else if(s == "obten_album"){
          /**@brief Se obtiene un album de la coleccion<b>c_en_curso</b> y pasa a ser el album en curso.
              \pre s == "obten_album".
              \post Se ha convertido el album <b>en_curso</b> en el album que se queria obtener si la
              \post indicacion es positiva y se imprime el album, si no, se informa de ello.

          */
            string id;
            cin >> id;
            cout << "# obten_album " << id << endl;
            bool b = c_en_curso.obten_album(id,en_curso); // si b = false, el album en_curso no ha sido modificado con el album a obtener.


            if (not b)
                cout << "No existe un album con el id dado." << endl;
            else
                en_curso.imprime_album();

        }



        else if(s == "nr_albums"){
          /**@brief Se indica cuantos albumes tiene la coleccion.
              \pre s == "nr_albums".
              \post Se muestra por el canal de salida cuantos albumes contiene la coleccion c_en_curso.


          */
            cout << '#' << ' ' << s << endl;
            cout << c_en_curso.nr_albumes() << endl;
        }



        else if(s == "lista_albumes"){
          /**@brief Se indica el nombre de los albumes que contiene la coleccion.
              \pre s == "lista_albumes".
              \post Se muestra por el canal de salida el nombre de los albumes que tiene la coleccion c_en_curso.
              \post Siempre será almenos 1, el album "ALL".

          */
            cout << "# lista_albumes" << endl;
            c_en_curso.lista_albumes();
        }


        else if(s == "agrega_foto_coleccion"){
        /**@brief Se agrega una foto a la coleccion.
            \pre s == "agrega_foto_coleccion".
            \post Si no existe foto con el identificador de la foto dada en la coleccion , se ha añadido la foto y se informa de ello, en caso contrario solo imprime un informe de la situacion.

        */
            Foto f;
            f.crea_foto();
            cout << "# agrega_foto_coleccion " << f.id_foto() << " ..." << endl;
            c_en_curso.agrega_foto(f);
        }



        else if(s == "elimina_foto_coleccion"){

          /** @brief Elimina una foto de la coleccion (de todos los albumes a los que pertenecia).
            \pre  s == "elimina_foto_coleccion".
            \post La foto ha sido eliminada de todos los albumes de la coleccion si se encuentra una foto con ese identificador en la coleccion y se informa de ello, en caso contrario solo imprime un informe de la situacion.
            */
            string id;
            cin >> id;
            cout <<"# elimina_foto_coleccion " << id << endl;
            c_en_curso.elimina_foto_coleccion(id);
        }



        else if(s == "modifica_foto_coleccion"){
          /** @brief Dado un identificador y una foto con ese identificador, se sustituye la foto de la coleccion con ese identificador por la nueva.
            \pre s == "modifica_foto_coleccion".
            \post La foto ha sido reemplazada por la nueva si se encuentra una foto con el identificador dado en la coleccion y se informa de ello, en caso contrario solo imprime un informe de la situacion.
            */
            Foto f;
            f.crea_foto();
            cout << "# modifica_foto_coleccion " << f.id_foto() << " ..." << endl;
            c_en_curso.modifica_foto(f.id_foto(), f);
        }



        else if(s == "albumes_foto"){
          /** @brief Dado el identificador de una foto muestra todos albumes a los que pertenece la foto en orden lexicografico.
            \pre s == "albumes_foto".
            \post Se ha mostrado los identificadores de los albumes a los que pertenece la foto(incluido el album todo) y se informa de la situacion (si no se ha encontrado la foto dada en toda la coleccion).
            */
            string id;
            cin >> id;
            cout << "# albumes_foto " << id << endl;
            c_en_curso.lista_albumes_foto(id);

        }



        else if(s == "busca_por_fecha"){
          /** @brief Modifica un album pasado por (album en_curso) referencia para que contenga todas las fotos que cumplen la condincion de estar entre las fechas dadas.
            \pre s == "busca_por_fecha".
            \post Se ha modificado el album en_curso pasado por referencia, para que contenga todas las fotos que se encuentran entre las fechas dadas y se encontraban en el album con identificador id, y
            \post además, se modifica la id del album pasado por referencia por el identificador <b>nuevo</b>.
            */

            Fecha a, b;

            a.leer_fecha();
            b.leer_fecha();
            string id_buscado, id_result;
            cin >> id_buscado >> id_result;
            cout << "# busca_por_fecha ";
            a.escribir_fecha();
            cout << '-';
            b.escribir_fecha();
            cout << ' ' << id_buscado << ' ' << id_result << endl;

            if(c_en_curso.contiene_album(id_buscado)) {

                c_en_curso.busca_por_fecha(a, b, id_buscado, id_result, en_curso);


                en_curso.imprime_album();

            }
            else
                cout << "No existe un album con el id dado." << endl;

        }



        else if(s == "busca_por_etiqueta"){
          /** @brief Modifica el album en_curso pasado por referencia para que contenga todas las fotos que cumplen la condincion de tener la etiqueta especificada.
            \pre s == "busca_por_etiqueta".
            \post Se ha modificado el album en_curso pasado por referencia, para que contenga todas las fotos que contienen la etiqueta <b>etiq</b> y se encontraban en el album con identificador id, y
            \post además, se modifica la id del album pasado por referencia por el identificador <b>nuevo</b>.
            */
            string etiq, id_buscado, id_result;

            cin >> etiq >> id_buscado >> id_result;

            cout << "# busca_por_etiqueta " << etiq << ' '
            << id_buscado << ' ' << id_result << endl;
            if(c_en_curso.contiene_album(id_buscado)) {

              c_en_curso.busca_por_etiqueta(etiq, id_buscado, id_result, en_curso);



              en_curso.imprime_album();

            }
            else
                cout << "No existe un album con el id dado." << endl;
      }

        else if(s == "evalua_consulta_booleana"){
          /** @brief Evalua una consulta y modifica el album en curso segun las condiciones de la consulta.
              \pre s == "evalua_consulta_booleana".
              \post El album <b>en_curso</b> se ha modificado de forma que todas las fotos que contiene cumplen con las condiciones de consulta realizada sobre el album buscado (tambien se modifica su id al final)
              \post si el album sobre el que se quiere realizar la consulta no se encuentra, se informa de ello
          */
            string id, result;
            cin >> id >> result;

            cout << "# evalua_consulta_booleana " << id << ' ' << result << endl;
            cout << "# BEGIN_QUERY ... END_QUERY" << endl;
            if(c_en_curso.obten_album(id, en_curso)){ //se obtiene el album buscado a la vez que se comprueba, en caso de no encontrarse en la coleccion, el album en_curso no se modifica

                ConsultaBool c;

                c.read(cin);

                c.evalua_consulta_booleana(en_curso);
                en_curso.mod_id(result);
                en_curso.imprime_album();
            }
            else
                cout << "No existe un album con el id dado." << endl;

        }



        else if(s == "imprime_album_en_curso"){
          /** @brief Muestra el identificador del album en_curso, el identificador de las fotos y toda la informacion relacionada con ellas.
            \pre s == "imprime_album_en_curso".
            \post El canal de salida ha recibido el identificador del album en-curso, el de las fotos(en orden lexicografico ascendente), la fecha y etiquetas de esta.
            */
            cout << "# imprime_album_en_curso" << endl;
            en_curso.imprime_album();
        }



        else if(s == "imprime_coleccion"){
          /** @brief Imprime todos los albumes que componen la coleccion, incluido ALL.
                \pre s == "imprime_coleccion".
                \post Se han mostrado todos los albumes que contiene la coleccion c_en_curso(incluido todas las fotos de estos con su respectiva informacion).
                */
            cout << "# imprime_coleccion" << endl;
            c_en_curso.imprime_coleccion();

        }




    }



}
