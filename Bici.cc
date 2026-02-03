/** @file Bici.cc
    @brief Codigo de la clase Bici.
*/
#include "Bici.hh"

    Bici::Bici(){}

    Bici::Bici(const string& id_bici){
        this->id_bici = id_bici;
        viaje_bici = list<pair<string, string>>();
    }

    string Bici::consultar_id_bici() const{
        return id_bici;
    }

    void Bici::anadir_viaje(const string& origen, const string& destino){
        viaje_bici.push_back(make_pair(origen, destino));
    }

    void Bici::escribir_viaje_bici() const{
        for (const auto& viaje : viaje_bici){
            cout << viaje.first << ' ' << viaje.second << endl;
        }
    }
