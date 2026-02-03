/** @file Cjt_bicis.cc
    @brief Codigo de la clase Cjt_bicis.
*/
#include "Cjt_bicis.hh"

    Cjt_bicis::Cjt_bicis(){
        map_bicis_estacion = map<string, string>();
    }

    void Cjt_bicis::alta_bici(const string& id_bici, const string& id_estacion){
        map_bicis_estacion[id_bici] = id_estacion;
    }

    void Cjt_bicis::baja_bici(const string& id_bici){
        map_bicis_estacion.erase(id_bici);
    }

    string Cjt_bicis::devolver_estacion(const string& id_bici){
        return map_bicis_estacion[id_bici];
    }   

    bool Cjt_bicis::existe_bici(const string& id_bici) const{
        return map_bicis_estacion.count(id_bici) != 0;
    }