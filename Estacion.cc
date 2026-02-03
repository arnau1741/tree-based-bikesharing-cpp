/** @file Estacion.cc
    @brief Codigo de la clase Estacion.
*/
#include "Estacion.hh"

    Estacion::Estacion(){}

    Estacion::Estacion(const string& id_estacion, const int& capacidad){
        this->id_estacion = id_estacion;
        capacidad_estacion = capacidad;
        mapa_de_bicis = map<string, Bici>();
    }

    void Estacion::alta_bici(Bici& bici, const string& origen){
        bici.anadir_viaje(origen, id_estacion);
        mapa_de_bicis[bici.consultar_id_bici()] = bici;
    }

    void Estacion::alta_bici_sin_viaje(const Bici& bici){
        mapa_de_bicis[bici.consultar_id_bici()] = bici;
    }

    Bici Estacion::baja_bici(const string& id_bici){
        Bici b = mapa_de_bicis[id_bici];
        mapa_de_bicis.erase(id_bici);
        return b;
    }

    bool Estacion::full_estacion() const{
        return mapa_de_bicis.size() == capacidad_estacion;
    }

    int Estacion::espacio_libre_estacion() const{
        return capacidad_estacion - mapa_de_bicis.size();
    }

    int Estacion::cuantas_bicis() const{
        return mapa_de_bicis.size();
    }

    string Estacion::consultar_bici() const{
        map<string, Bici>::const_iterator it = mapa_de_bicis.begin();
        return it->first;
    }

    void Estacion::cambio_capacidad(const int& n){
        capacidad_estacion = n;
    }

    void Estacion::write_bicis_estacion() const {
        for(const auto& pair : mapa_de_bicis){
            cout << pair.first << endl;
        }
    }

    void Estacion::write_viajes_bici(const string& id_bici){
        mapa_de_bicis[id_bici].escribir_viaje_bici();
    } 