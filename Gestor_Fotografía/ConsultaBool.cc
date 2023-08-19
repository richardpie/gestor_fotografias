/**@file ConsultaBool.cc
   @brief Codigo de la clase ConsultaBool.

*/

#include "ConsultaBool.hh"
string toupper(const string& s);

void read_input(istream& is, vector<token>& l);

int precedence(string oper);

void convert_infix_to_postfix(const vector<token>& infix, vector<token>& postfix);

ConsultaBool construct_bool_query(const vector<token>& postfix);


//CONSTRUCTORA:

/** @brief Crea una consulta con su arbol vacio.
    \pre <b>Cierto</b>.
    \post Se ha creado una consulta cuyo arbol atributo es un arbol vacio.
    */
ConsultaBool::ConsultaBool(){
    ConsultaTree = BinTree<token>();
}

////////////////////////////////
/** @brief Crea una consulta con la raiz del arbol como nodo tipo TAG y su respectiva etiqueta.
    \pre <b>Cierto</b>.
    \post Se ha creado una consulta cuyo arbol tiene como raiz un nodo con tk.tipo = "TAG"; y tk.etq = s;
    */

ConsultaBool::ConsultaBool(const string& s){
    token tk;
    tk.tipo = "TAG";
    tk.etq = s;
    ConsultaTree = BinTree<token>(tk);

}
////////////////////////////////
/** @brief Crea una consulta con la raiz del arbol atributo como nodo tipo DATE y sus respectivas fechas (fini, ffin).
    \pre <b>Cierto</b>.
    \post Se ha creado una consulta cuyo arbol tiene como raiz un nodo con tk.tipo = "DATE"; y tk.fini = fini y tk.ffin = ffin (fini y fin son las fechas proporcionadas como parametros);
    */

ConsultaBool::ConsultaBool(const Fecha& fini, const Fecha& ffin){
    token tk;
    tk.tipo = "DATE";
    tk.fini = fini;
    tk.ffin = ffin;
    ConsultaTree = BinTree<token>(tk);

}
////////////////////////////////

//MODIFICADORA:



/** @brief Se devuelve una consulta cuyo arbol representa la interseccion de los arboles de "consulta parametro implicito" y la consulta q2.
    \pre <b>Cierto</b>.
    \post Se ha devuelto una consulta cuya raiz es un nodo tipo "AND" y los hijos izquierdo y derecho son los arboles del objeto implicito y el arbol q2 (respectivamente).
*/


ConsultaBool ConsultaBool::AND(const ConsultaBool& q2){
    token tk;
    tk.tipo = "AND";
    ConsultaBool result;
    result.ConsultaTree = BinTree <token>(tk, ConsultaTree, q2.ConsultaTree);
    return result;

}
////////////////////////////////
/** @brief Se devuelve una consulta cuyo arbol representa la union de los arboles de "consulta parametro implicito" y la consulta q2.
    \pre <b>Cierto</b>.
    \post Se ha devuelto una consulta cuya raiz es un nodo tipo "OR" y los hijos izquierdo y derecho son los arboles del objeto implicito y el arbol q2 (respectivamente).
*/


ConsultaBool ConsultaBool::OR(const ConsultaBool& q2){

    token tk;
    tk.tipo = "OR";
    ConsultaBool result;
    result.ConsultaTree = BinTree <token>(tk, ConsultaTree, q2.ConsultaTree);

    return result;


}
////////////////////////////////
/** @brief  Se devuelve una consulta cuyo arbol solo tiene hijo izquierdo y este hijo izquierdo es el arbol de la "consulta parametro implicito".
    \pre <b>Cierto</b>.
    \post Se ha devuelto una consulta cuyo arbol tiene como raiz un nodo tipo "NOT" y un hijo izquierdo con la consulta "parametro implicito".
*/

ConsultaBool ConsultaBool::NOT(){

    token tk;
    tk.tipo = "NOT";

    ConsultaBool result, c_void;

    result.ConsultaTree = BinTree <token>(tk, ConsultaTree, c_void.ConsultaTree);

    return result;
}


////////////////////////////////

//CONSULTORA:


/** @brief Recorre el arbol del parametro implicito y devuelve un album por referencia que cumple con las condiciones del arbol.
    \pre <b>Cierto</b>.
    \post El album <b>search</b> se ha modificado de forma que todas las fotos que contiene cumplen con las condiciones del arbol.
*/

void ConsultaBool::evalua_consulta_booleana(Album& search){

    if(not ConsultaTree.empty()){


        if(ConsultaTree.value().tipo == "AND") {

            ConsultaBool carry;

            carry.ConsultaTree = ConsultaTree.left();//hijo izquierdo del arbol del objeto en el que estamos, lo paso a que sea el arbol de una nueva consulta
            Album result1;
            result1 = search;
            carry.evalua_consulta_booleana(result1);//album que se envía al left

            carry.ConsultaTree = ConsultaTree.right();//hijo derecho del arbol del objeto en el que estamos,  lo paso a que sea el arbol de una nueva consulta
            Album result2;
            result2 = search;
            carry.evalua_consulta_booleana(result2);//album que se envía al right

            Album nuevo;
            nuevo.AND(result1, result2); //interseccion de los albumes result1(izquierdo) y result2 (derecho)


            search = nuevo;

        }

        else if(ConsultaTree.value().tipo == "OR") {
            ConsultaBool carry;

            carry.ConsultaTree = ConsultaTree.left();
            Album result1;
            result1 = search;
            carry.evalua_consulta_booleana(result1);//album que se envía al left

            carry.ConsultaTree = ConsultaTree.right();
            Album result2;
            result2 = search;
            carry.evalua_consulta_booleana(result2);//album que se envía al right

            result1.OR(result2); //union de los dos albumes

            search = result1;

        }

        else if(ConsultaTree.value().tipo == "NOT") {
            ConsultaBool carry;

            carry.ConsultaTree = ConsultaTree.left();
            Album result1;
            result1 = search;


            carry.evalua_consulta_booleana(result1); //album que se envía al left


            search.NOT(result1); //las fotos del album enviado al nivel inferior, se borran del original (el que esta en el nivel "NOT" al que hemos vuelto)


        }

        else if(ConsultaTree.value().tipo == "TAG"){
            Album result1;
            search.busca_fotos_etiqueta(ConsultaTree.value().etq, result1);

            search = result1;
        }

        else if(ConsultaTree.value().tipo == "DATE"){
            Album result1;

            search.busca_fotos_fecha(ConsultaTree.value().fini,
            ConsultaTree.value().ffin, result1);

            search = result1;


        }
    }


}

////////////////////////////////


//ENTRADA/SALIDA:

/** @brief Introduce los datos para poder construir el arbol.
    \pre <b>Cierto</b>.
    \post El arbol se ha construido con todos los datos que se le ha suministrado a la funcion por el canal de entrada.
*/
void ConsultaBool::read(istream& is) {
    vector<token> infix, postfix;

    read_input(is, infix);

    if (infix.empty()) {
        *this = ConsultaBool();
        return;
    }

    convert_infix_to_postfix(infix, postfix);
    *this = construct_bool_query(postfix);

}





ConsultaBool construct_bool_query(const vector<token>& postfix) {
    stack<ConsultaBool> S;
    for (int i = 0; i < postfix.size(); ++i) {
        token tk = postfix[i];
        if (tk.tipo == "TAG") S.push(ConsultaBool(tk.etq)); // apila una consulta TAG
        if (tk.tipo == "DATE") S.push(ConsultaBool(tk.fini, tk.ffin)); // apila una consulta DATE
        if (tk.tipo == "AND" or tk.tipo == "OR") {
            ConsultaBool q2 = S.top(); S.pop();
            ConsultaBool q1 = S.top(); S.pop();
            if (tk.tipo == "AND") S.push(q1.AND(q2)); // apila una consulta 'q1 and q2'
            if (tk.tipo == "OR") S.push(q1.OR(q2)); // apila una consulta 'q1 or q2'
        }
        if (tk.tipo == "NOT") {
            ConsultaBool q = S.top(); S.pop();
            S.push(q.NOT()); // apila una consulta 'not q'
        }
    }
    return S.top();
}


void read_input(istream& is, vector<token>& l) {
    string s;
    is >> s;
    while (s != "END_QUERY") {
        token tk;
        s = toupper(s);
        tk.tipo = s;
        if (s == "(" or s == ")" or s == "AND" or s == "OR" or s == "NOT") {
            l.push_back(tk);
        }
        if (s == "DATE") { /** usad el metodo Fecha::llegir() o similar si no teneis
                            sobrecargado el operador >> para leer fechas **/
            tk.fini.leer_fecha();
            tk.ffin.leer_fecha();
            l.push_back(tk);
        }
        if (s == "TAG") {
            is >> tk.etq;
            l.push_back(tk);
        }

        is >> s;
    }
}



string toupper(const string& s) {
    string res = "";
    for (int i = 0; i < s.length(); ++i)
        res += toupper(s[i]);
    return res;
}

int precedence(string oper) {
    if (oper == "OR") return 1;
    if (oper == "AND") return 2;
    if (oper == "NOT") return 3;
    return 0;
}

void convert_infix_to_postfix(const vector<token>& infix, vector<token>& postfix) {
    stack<token> S;
    token spc; spc.tipo = "#"; S.push(spc);
    for (int i = 0; i < infix.size(); ++i) {
        token tk = infix[i];
        if (tk.tipo == "DATE" or tk.tipo == "TAG")
            postfix.push_back(tk);
        else if (tk.tipo == "(" or tk.tipo == "NOT")
            S.push(tk);
        else if (tk.tipo == ")") {
            while (S.top().tipo != "#" and S.top().tipo != "(") {
                postfix.push_back(S.top()); S.pop();
            }
            S.pop();
        } else {
            while (S.top().tipo != "#" and
                precedence(tk.tipo) <= precedence(S.top().tipo)) {
                    postfix.push_back(S.top()); S.pop();
            }
            S.push(tk);
        }
    }
    while (S.top().tipo != "#") {
        postfix.push_back(S.top()); S.pop();
    }
}
