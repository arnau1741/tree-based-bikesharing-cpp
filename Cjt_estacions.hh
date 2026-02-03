/** @file Cjt_estacions.hh
    @brief Especificacion de la clase Cjt_estacions.
*/

#ifndef _Cjt_estacions_HH_
#define _Cjt_estacions_HH_

#include "Estacion.hh"
#include "Cjt_bicis.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#include <map>
#endif
using namespace std;

/** @class Cjt_estacions
    @brief Conjunto de estaciones donde se encuentran las estaciones Bicing.
*/

class Cjt_estacions{

private:
    BinTree<string> identificador_estaciones;
    map<string, Estacion> estaciones;
    Cjt_bicis b;
    int pl_libres;

    /** @brief Lectura del bintree y dar alta estaciones para input.
        Funcion auxiliar para lectura_estaciones.
        \pre cierto.
        \post El resultado es el bintree inicializado con los string de las estaciones y las estaciones han sido dadas de alta.
    */
    BinTree<string> leer_BinTree();

    /** @brief Consultar las plazas libres que hay a partir de un nodo del BinTree y las estaciones que tiene debajo.
        Funcion auxiliar de asignar_estacion.
        \pre Se ha dado las estaciones de alta.
        \post Devuelve el calculo ya especificado.
    */
    int plazas_libres_arbol(const BinTree<string>& b);

    /** @brief Calcular el coeficiente de desocupacion de las estaciones.
        Funcion auxiliar de asignar_estacion.
        \pre Se ha dado las estaciones de alta.
        \post El resultado es la estacion con mayor coeficiente de las estaciones.
    */
    void coeficiente(const BinTree<string>& b, string& id_estacion, double& coef_max, int& el_b, int& hijos_b);
    
    /** @brief Mover bicis en direccion a la primera estacion.
        Funcion auxiliar de subir_bicis.
        \pre Se ha dado de alta las estaciones.
        \post Las bicis han sido reestructuradas en direccion hacia la primera estacion declarada.
    */
    void Reestructurar_ubicacion(const BinTree<string>& b);
    
public:
    //constructoras

    /** @brief Dar de alta Cjt_estacions.
        Permite dar de alta Cjt_estacions, conjunto donde se encuentran las estaciones de bicis.
        \pre: cierto.
        \post: el resultado es Cjt_estacions inicializada con sus atributos.
    */
    Cjt_estacions();

    //modificadoras

    /** @brief Dar de alta bici.
        Permite dar de alta una bicicleta.
        \pre: la bici no existe.
        \post: se da de alta una bicicleta con su identificador en la estacion indicada.
    */
    void alta_bici(const string& id_bici, const string& id_estacion);

    /** @brief Dar de baja bici.
        Permite dar de baja una bicicleta.
        \pre: la bici existe.
        \post: la bici desaparece del sistema.
    */
    void baja_bici(const string& id_bici);

    /** @brief Escribir viajes bici.
        \pre: la bicicleta existe.
        \post: se escriben los viajes de la bicicleta indicada. 
    */
    void viajes_bici(const string& id_bici);
    
    /** @brief Mover bici de estacion.
        Permite mover una bici de una estacion a otra.
        \pre: 
        1.La bici existe.
        2.La estacion de destino existe y no es la misma donde se encuentra.
        3.La estacion de destino tiene capacidad para albergar la bicicleta.
        \post: la bici aparece en la nueva estacion indicada.
    */
    void mover_bici(const string& id_bici, const string& id_estacion);

    /** @brief Mover bici de estacion.
        Permite mover una bici de una estacion a otra.
        \pre: 
        1.La bici existe.
        2.La estacion de destino existe y no es la misma donde se encuentra.
        3.La estacion de destino tiene capacidad para albergar la bicicleta.
        \post: la bici aparece en la nueva estacion indicada sin anadir el viaje al historial.
    */
    void mover_bici_sin_viaje(const string& id_bici, const string& id_estacion);

    /** @brief Modificar capacidad estacion.
       \pre:
       1.La estacion existe.
       2.Un entero n > 0.
       3.El entero n >= que el numero de bicis de la estacion.
       \post: se modifica la estacion con el identificador dado con la nueva capacidad de bicicletas que puede albergar.
    */
    void modificar_capacidad(const string& id_estacion, const int& n);

    /** @brief Mueve bicis hacia la primera estacion declarada.
        \pre se ha dado de alta las estaciones.
        \post Las bicicletas han sido reestructuradas en direccion a la primera estacion.
    */
    void subir_bicis();

    /** @brief Asignar bici donde mas hace falta.
      \pre 
      1.La bici no existe.
      2.Hay almenos un espacio en alguna estacion.
      \post bicicleta queda asignada en la estacion con mayor coeficiente de desocupacion y se escribe el identificador de la estacion seleccionada.
    */
    void asignar_estacion(const string& id_bici);

    //consultoras

    /** @brief Consultora de la estacion donde esta la bicicleta.
        Nos permite saber en que estación se encuentra la bicicleta
        \pre: la bici existe.
        \post: se devuelve el identificador donde esta la bicicleta.
    */
    string estacion_bici_consulta(const string& id_bici);

    /** @brief Consultora existencia bicicleta.
        Nos permite saber si una bicicleta existe.
        \pre: cierto.
        \post: el resultado es true si la bicicleta existe, false si no es el caso.
    */
    bool existe_bici(const string& id_bici) const;

    /** @brief Consultora existencia estacion.
        Nos permite saber si una estacion existe.
        \pre: cierto.
        \post: el resultado es true si la estacion existe, false si no es el caso.
    */
    bool existe_estacion(const string& id_estacion) const;

    /** @brief Consultora de las plazas libres en todo el conjunto de estaciones.
        \pre se ha dado de alta las estaciones.
        \post El resultado es el el numero de plazas libres en todo el sistema.
    */
    int plazas_libres() const;

    /** @brief Consultora de estacion.
        Nos permite consultar una estacion dado su identificador.
        \pre la estacion existe.
        \post Se devuelve la estacion seleccionada por el parametro.
    */
    Estacion consultar_estacion(const string& id_estacion);

    //lectura

    /** @brief Lectura de las estaciones para el sistema.
        \pre cierto.
        \post Se han leido todas las estaciones y se les ha dado de alta en el sistema.
        Tambien se llama a asignar_nodos para calcular un atributo de la clase Estacion
    */
    void lectura_estaciones();
    
    //escritura

    /** @brief Escribir las bicis de una estacion
        \pre: la estacion existe.
        \post: se escribe en orden de identificador las bicis que hay en la estacion.
    */
    void bicis_estacion(const string& id_estacion);
};
#endif