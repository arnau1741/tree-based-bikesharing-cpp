/** @file Bici.hh
    @brief Especificación de la clase Bici.
*/

#ifndef _BICI_HH_
#define _BICI_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
#endif
using namespace std;

/** @class Bici
    @brief Representa una bicicleta.
*/

class Bici{

private:
    string id_bici;
    list<pair<string, string>> viaje_bici;

public:
    //Creadoras
    
    /** @brief Dar de alta bicicleta vacia.
        \pre: cierto.
        \post: el resultado es una bicicleta sin atributos.
    */
    Bici();

    /** @brief Permite dar de alta una bicicleta con su identificador.
        \pre: la bici no existe.
        \post: el resultado es una bicicleta inicializada con sus atributos.
    */
    Bici(const string& id_bici);

    //modificadoras

    /** @brief Anadir viaje a la bicicleta.
        \pre: la bici existe.
        \post: se ha anadido el viaje al historial de la bicicleta.
    */
    void anadir_viaje(const string& origen, const string& destino);

    //consultoras

    /** @brief Consultora del identificador de la bicicleta.
        \pre: la bici existe.
        \post: el resultado es el identificador de la estacion.
    */
    string consultar_id_bici() const;

    //escritura

    /** @brief Escritura de los viajes de la bicicleta.
        \pre: la bici existe.
        \post: se han escrito los viajes que ha hecho la bicicleta.
    */
    void escribir_viaje_bici() const;

};
#endif