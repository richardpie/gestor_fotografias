/**@file Fecha.cc
   @brief Codigo de la clase Fecha.

*/

#include "Fecha.hh"

//CONSTRUCTORA:

/** @brief <b>Constructora</b> de fecha.
    \pre <b>Cierto</b>.
    \post Crea una fecha nueva vacia.
    */
Fecha::Fecha(){

}
/////////////////////////////////////

//CONSULTORAS:


/** @brief Consulta el dia de fecha.
    \pre <b>Cierto</b>.
    \post Devuelve el dia de la fecha.
    */
int Fecha::consultar_dd() const{

    return dd;
}
/////////////////////////////////////
/** @brief Consulta el mes de fecha.
    \pre <b>Cierto</b>.
    \post Devuelve el mes de la fecha.
    */
int Fecha::consultar_mm() const{
    return mm;
}
/////////////////////////////////////
/** @brief Consulta el año de fecha.
    \pre <b>Cierto</b>.
    \post Devuelve el año de la fecha.
    */
int Fecha::consultar_aaaa() const{
    return aaaa;
}

/////////////////////////////////////

//ENTRADA/SALIDA:

/** @brief  Introduce los datos de la fecha.
    \pre <b>Cierto</b>.
    \post La fecha tiene un dia, un mes, un año.
    */

void Fecha::leer_fecha(){
    cin >> dd >> mm >> aaaa;

}
/////////////////////////////////////
/** @brief  Muestra la fecha.
    \pre <b>Cierto</b>.
    \post La fecha (dd/mm/aa) se muestra por el canal de salida.
    */

void Fecha::escribir_fecha() const{

    cout << dd << '/' << mm << '/' << aaaa;


}

/////////////////////////////////////
/** @brief  Define el operador <b><</b> para comparar 2 fechas.
    \pre <b>Cierto</b>.
    \post Devuelve el resultado de comparar 2 fechas pasadas por referencia constante(true si  <b>a</b> es más pequeña respecto a <b>b</b>).
    */
bool operator<(const Fecha& a, const Fecha& b){
    bool comp;
    if(a.consultar_aaaa() != b.consultar_aaaa())
        comp = a.consultar_aaaa() < b.consultar_aaaa();

    else if (a.consultar_mm() != b.consultar_mm())
        comp = a.consultar_mm() < b.consultar_mm();

    else
        comp = a.consultar_dd() < b.consultar_dd();

    return comp;
}
///////////////////////////////////////
/** @brief  Define el operador <b>==</b> para comparar 2 fechas.
    \pre <b>Cierto</b>.
    \post Devuelve el resultado de comparar 2 fechas pasadas por referencia constante(cierto si coinciden en dia, mes y año).
    */
bool operator==(const Fecha& a, const Fecha& b){

    bool comp = false;
    if(a.consultar_aaaa() == b.consultar_aaaa()){
        if(a.consultar_mm() == b.consultar_mm()){
            comp = a.consultar_dd() == b.consultar_dd();
        }
    }
    return comp;
}
/////////////////////////////////////
/** @brief  Define el operador <b><=</b> para comparar 2 fechas.
    \pre <b>Cierto</b>.
    \post Devuelve el resultado de comparar 2 fechas pasadas por referencia constante(cierto si coinciden en dia, mes y año o si  <b>a</b> es más pequeña respecto a <b>b</b>).
    */
bool operator<=(const Fecha& a, const Fecha& b){
    bool comp = false;
    if(a.consultar_aaaa() != b.consultar_aaaa())
        comp = a.consultar_aaaa() < b.consultar_aaaa();

    else if (a.consultar_mm() != b.consultar_mm())
        comp = a.consultar_mm() < b.consultar_mm();

    else if(a.consultar_dd() != b.consultar_dd())
        comp = a.consultar_dd() < b.consultar_dd();

    else if (not comp) {
        if(a.consultar_aaaa() == b.consultar_aaaa()){
          if(a.consultar_mm() == b.consultar_mm()){
              comp = a.consultar_dd() == b.consultar_dd();
          }
      }
    }
    return comp;

}
