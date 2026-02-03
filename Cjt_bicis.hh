/** @file Cjt_bicis.hh
    @brief Especificación de la clase conjunto de bicis.
*/

#ifndef _CJT_BICIS_HH_
#define _CJT_BICIS_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
using namespace std;

/** @class Cjt_bicis
    @brief Representa un conjunto de bicicletas.
*/

class Cjt_bicis{

private:
    map<string, string> map_bicis_estacion;

public:
    //Creadoras
    /** @brief Dar de alta conjunto de bicicletas.
        \pre: cierto.
        \post: el resultado es un conjunto de bicicletas inicializado.
    */
    Cjt_bicis();

    //modificadoras

    /** @brief Dar de alta bicicleta.
        \pre: la bici no existe.
        \post: se ha dado de alta la bicicleta.
    */
    void alta_bici(const string& id_bici, const string& id_estacion);

    /** @brief Dar de baja bicicleta.
        \pre: la bici existe.
        \post: se ha dado de baja la bicicleta.
    */
    void baja_bici(const string& id_bici);

    //consultoras
    /** @brief Estacion donde esta la bicicleta.
        \pre: la bici existe.
        \post: el resultado es la estacion donde se encuentra la bicicleta.
    */
    string devolver_estacion(const string& id_bici);

    /** @brief Consultora existencia bicicleta.
        \pre: cierto.
        \post: el resultado es true si la bicicleta existe, false en caso contrario.
    */
    bool existe_bici(const string& id_bici) const;
};
#endif