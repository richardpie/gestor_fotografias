/**@file Fecha.hh
   @brief Cabeceras de la clase Fecha.

*/

#ifndef FECHA_HH
#define FECHA_HH

#ifndef NO_DIAGRAM


#include <iostream>
#include <string>
#include <set>
#include <map>
#include "BinTree.hh"
#include <vector>
#include <stack>

#endif

using namespace std;

class Fecha{

private:
  /** @brief Contiene el <b>dia</b> de la fecha de la foto.
      \pre Debe ser menor o igual a 31 (dd<=28 si mm == 2 o dd<= 29 si el año es bisiesto) y mayor a 0.
    */
  int dd;
/////////////////////////////////////
  /** @brief Contiene el <b>mes</b> de la fecha de la foto.
      \pre Debe ser menor o igual a 12 y mayor a 0
    */
  int mm;
/////////////////////////////////////
  /** @brief Contiene el <b>año</b> de la fecha de la foto.
      \pre El input es mayor o igual a 1700 y menor o igual a 2299.
    */
  int aaaa;
/////////////////////////////////////

public:
//CONSTRUCTORA:

/** @brief <b>Constructora</b> de fecha.
    \pre <b>Cierto</b>.
    \post Crea una fecha nueva vacia.
    */
  Fecha();
/////////////////////////////////////

//CONSULTORAS:


/** @brief Consulta el dia de fecha.
    \pre <b>Cierto</b>.
    \post Devuelve el dia de la fecha.
    */
  int consultar_dd() const;
/////////////////////////////////////
/** @brief Consulta el mes de fecha.
    \pre <b>Cierto</b>.
    \post Devuelve el mes de la fecha.
    */
  int consultar_mm() const;
/////////////////////////////////////
/** @brief Consulta el año de fecha.
    \pre <b>Cierto</b>.
    \post Devuelve el año de la fecha.
    */
  int consultar_aaaa() const;
/////////////////////////////////////

//ENTRADA/SALIDA:


/** @brief  Introduce los datos de la fecha.
    \pre <b>Cierto</b>.
    \post La fecha tiene un dia, un mes, un año y un entero para calcular rangos.
    */

  void leer_fecha();
/////////////////////////////////////
/** @brief  Muestra la fecha.
    \pre <b>Cierto</b>.
    \post La fecha (dd mm aa) se muestra por el canal de salida.
    */

  void escribir_fecha() const;

};
/////////////////////////////////////
/** @brief  Define el operador <b><</b> para comparar 2 fechas.
    \pre <b>Cierto</b>.
    \post Devuelve el resultado de comparar 2 fechas pasadas por referencia constante(true si  <b>a</b> es más pequeña respecto a <b>b</b>).
    */
bool operator<(const Fecha& a, const Fecha& b);
/////////////////////////////////////
/** @brief  Define el operador <b>==</b> para comparar 2 fechas.
    \pre <b>Cierto</b>.
    \post Devuelve el resultado de comparar 2 fechas pasadas por referencia constante(cierto si coinciden en dia, mes y año).
    */
bool operator==(const Fecha& a, const Fecha& b);
/////////////////////////////////////
/** @brief  Define el operador <b><=</b> para comparar 2 fechas.
    \pre <b>Cierto</b>.
    \post Devuelve el resultado de comparar 2 fechas pasadas por referencia constante(cierto si coinciden en dia, mes y año o si  <b>a</b> es más pequeña respecto a <b>b</b>).
    */
bool operator<=(const Fecha& a, const Fecha& b);



#endif
