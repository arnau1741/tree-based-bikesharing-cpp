/** @file Estacion.hh
    @brief Especificación de la clase Estacion.
*/

#ifndef _ESTACION_HH_
#define _ESTACION_HH_

#include "Bici.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
using namespace std;

/** @class Estacion
    @brief Representa una estacion.
*/

class Estacion{

private: 
    map<string, Bici> mapa_de_bicis;
    int capacidad_estacion;
    string id_estacion;

public:
    //constructoras
    
    /** @brief Dar de alta estacion vacia sin atributos.
        Permite dar de alta una Estacion vacia sin atributos.
        \pre: cierto.
        \post: el resultado es una estacion vacia sin atributos.
    */
    Estacion();

    /** @brief Dar de alta estacion.
        Permite dar de alta una Estacion.
        \pre: cierto.
        \post: el resultado es una estacion inicializada con sus atributos.
    */
    Estacion(const string& id_estacion, const int& capacidad);

    //modificadoras
    
    /** @brief Dar de alta bicicleta en la estacion.
        Permite dar de alta una bicicleta en una estacion.
        \pre: la bici no esta en ninguna estacion porque se acaba de crear o se esta moviendo debido a alguna funcion.
        \post: el resultado es una bicicleta añadida en la estacion.
    */
    void alta_bici(Bici& bici, const string& origen);

    /** @brief Dar de alta bicicleta en la estacion.
        Permite dar de alta una bicicleta en una estacion sin añadir un viaje al historial de la bicicleta.
        \pre: la bici no esta en ninguna estacion porque se acaba de crear o se esta moviendo debido a alguna funcion.
        \post: el resultado es una bicicleta añadida a una estacion sin el viaje.
    */
    void alta_bici_sin_viaje(const Bici& bici);

    /** @brief Dar de baja bici.
        Permite dar de baja una bicicleta.
        \pre: la bici existe.
        \post: la bici desaparece del sistema.
    */
    Bici baja_bici(const string& id_bici);

    //consultoras

    /** @brief Permite consultar si la estacion esta llena.
       \pre: la estacion existe.
       \post: retorna true si esta llena, false si no esta llena.
    */
    bool full_estacion() const;

    /** @brief Espacio libre de una estacion.
        Permite consultar el espacio libre de una estacion.
        \pre: la estacion existe.
        \post: Se devuelve el espacio libre de una estacion.
    */
    int espacio_libre_estacion() const;

    /** @brief Permite consultar el numero de bicis de una estacion.
        \pre: la estacion existe.
        \post: Se devuelve el numero de bicis que hay en una estacion.
    */
    int cuantas_bicis() const;

    /** @brief Permite consultar la primera bici por orden de la estacion.
        \pre: la estacion existe.
        \post: Se devuelve el identificador de la primera bici de la estacion.
    */
    string consultar_bici() const;

    /** @brief Cambiar la capacidad de una estacion.
        \pre: n > 0 y n >= las bicis que hay en la estacion. La estacion existe.
        \post: Se cambia la capacidad de la estacion a la indicada por el parametro de la funcion.
    */
    void cambio_capacidad(const int& n);

    //escritura

    /** @brief Escribir las bicis de una estacion.
        \pre: la estacion existe.
        \post: se escribe en orden de id_bici las bicis que hay en la estacion.
    */
    void write_bicis_estacion() const;

    /** @brief Escribir viajes bici.
        \pre: la bicicleta existe.
        \post: se escriben los viajes de la bicicleta indicada. 
    */
    void write_viajes_bici(const string& id_bici);    

};
#endif