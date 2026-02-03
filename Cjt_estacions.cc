/** @file Cjt_estacions.cc
    @brief Codigo de la clase Cjt_estacions.
*/
#include "Cjt_estacions.hh"
    Cjt_estacions::Cjt_estacions(){
        identificador_estaciones = BinTree<string>();
        estaciones = map<string, Estacion>();
        b = Cjt_bicis();
        pl_libres = 0;
    }

    void Cjt_estacions::alta_bici(const string& id_bici, const string& id_estacion){
        Bici p(id_bici);
        estaciones[id_estacion].alta_bici_sin_viaje(p);
        b.alta_bici(id_bici, id_estacion);
        --pl_libres;
    }

    void Cjt_estacions::baja_bici(const string& id_bici){
        estaciones[b.devolver_estacion(id_bici)].baja_bici(id_bici);
        b.baja_bici(id_bici);
        ++pl_libres;
    }

    string Cjt_estacions::estacion_bici_consulta(const string& id_bici){
        return b.devolver_estacion(id_bici);
    }

    void Cjt_estacions::viajes_bici(const string& id_bici){
        estaciones[b.devolver_estacion(id_bici)].write_viajes_bici(id_bici);
    }

    void Cjt_estacions::mover_bici(const string& id_bici, const string& id_estacion){
        Bici c = estaciones[b.devolver_estacion(id_bici)].baja_bici(id_bici);
        estaciones[id_estacion].alta_bici(c, b.devolver_estacion(id_bici));
        b.alta_bici(id_bici, id_estacion);
    }

    void Cjt_estacions::mover_bici_sin_viaje(const string& id_bici, const string& id_estacion){
        Bici c = estaciones[b.devolver_estacion(id_bici)].baja_bici(id_bici);
        estaciones[id_estacion].alta_bici_sin_viaje(c);
        b.alta_bici(id_bici, id_estacion);
    }

    void Cjt_estacions::bicis_estacion(const string& id_estacion){
        estaciones[id_estacion].write_bicis_estacion();
    }

    void Cjt_estacions::modificar_capacidad(const string& id_estacion, const int& n){
        int a = estaciones[id_estacion].espacio_libre_estacion();
        estaciones[id_estacion].cambio_capacidad(n);
        pl_libres += estaciones[id_estacion].espacio_libre_estacion() - a;
    }

    int Cjt_estacions::plazas_libres() const{
        return pl_libres;
    }

    BinTree<string> Cjt_estacions::leer_BinTree(){
        string value_node;
        int capacidad;
        cin >> value_node;

        if(value_node == "#") return BinTree<string>();
        cin >> capacidad;
        Estacion est = Estacion(value_node, capacidad);
        estaciones[value_node] = est;
        pl_libres += capacidad;
        BinTree<string> izq = leer_BinTree();
        BinTree<string> drc = leer_BinTree();
        return BinTree<string>(value_node, izq, drc);
    }

    void Cjt_estacions::lectura_estaciones(){
        identificador_estaciones = leer_BinTree();
    }

    void Cjt_estacions::subir_bicis(){
       Reestructurar_ubicacion(identificador_estaciones);

    }

    void Cjt_estacions::Reestructurar_ubicacion(const BinTree<string>& b) 
    {
        if(b.empty()) return;
        if(b.left().empty()) return;
        string estacion_actual = b.value();
        string estacion_izq = b.left().value();
        string estacion_drc = b.right().value();

        int esp_actual = estaciones[estacion_actual].espacio_libre_estacion();
        int bicis_izq = estaciones[estacion_izq].cuantas_bicis();
        int bicis_drc = estaciones[estacion_drc].cuantas_bicis();
        
        bool stop = (bicis_izq == 0 and bicis_drc == 0);

        while((not(stop)) and (esp_actual != 0)){
            if(bicis_izq > bicis_drc){
                mover_bici_sin_viaje(estaciones[estacion_izq].consultar_bici(), estacion_actual);
                --bicis_izq;
            }
            else if(bicis_drc > bicis_izq){
                mover_bici_sin_viaje(estaciones[estacion_drc].consultar_bici(), estacion_actual);
                --bicis_drc;    
            }
            else{
                string id_bici_izq = estaciones[estacion_izq].consultar_bici();
                string id_bici_drc = estaciones[estacion_drc].consultar_bici();
                if(id_bici_izq < id_bici_drc){
                    mover_bici_sin_viaje(id_bici_izq, estacion_actual);
                    --bicis_izq;
                }
                else{
                    mover_bici_sin_viaje(id_bici_drc, estacion_actual);
                    --bicis_drc;    
                }
            }
            if(bicis_izq == 0 and bicis_drc == 0){
                stop = true;
            }
            --esp_actual;
        }     
        Reestructurar_ubicacion(b.left());
        Reestructurar_ubicacion(b.right());   
    }

    void Cjt_estacions::asignar_estacion(const string& id_bici){
        string id_estacion = "";
        int el_b, hijos_b;
        el_b = hijos_b = 0;
        double max = 0;

        coeficiente(identificador_estaciones, id_estacion, max, el_b, hijos_b);
        alta_bici(id_bici, id_estacion);
        cout << id_estacion << endl;
    }

    void Cjt_estacions::coeficiente(const BinTree<string>& b, string& id_estacion, double& max, int& el_b, int& hijos_b) {
        if(b.empty()) return;
        int el_izq, el_drc, hijos_izq, hijos_drc;
        el_izq = el_drc = hijos_izq = hijos_drc = 0;

        coeficiente(b.left(), id_estacion, max, el_izq, hijos_izq);
        coeficiente(b.right(), id_estacion, max, el_drc, hijos_drc);
        el_b = estaciones[b.value()].espacio_libre_estacion() + el_izq + el_drc;
        hijos_b = 1 + hijos_izq + hijos_drc;

        if(hijos_izq == 0 or hijos_drc == 0) return;

        double coef_b = el_b / double(hijos_b);
        double coef_izq = el_izq / double(hijos_izq);
        double coef_drc = el_drc / double(hijos_drc);

        if(coef_izq > max) {
            max = coef_izq;
            id_estacion = b.left().value();
        } 
        else if(coef_izq == max) {
            if(b.left().value() < id_estacion) {
                max = coef_izq;
                id_estacion = b.left().value();
            }
        }

        if(coef_drc > max) {
            max = coef_drc;
            id_estacion = b.right().value();
        } 
        else if(coef_drc == max) {
            if(b.right().value() < id_estacion) {
                max = coef_drc;
                id_estacion = b.right().value();
            }
        }

        if(coef_b > max) {
            max = coef_b;
            id_estacion = b.value();
        } 
        else if(coef_b == max) {
            if(b.value() < id_estacion) {
                max = coef_b;
                id_estacion = b.value();
            }
        }
    }

    Estacion Cjt_estacions::consultar_estacion(const string& id_estacion){
        return estaciones[id_estacion];
    }

    bool Cjt_estacions::existe_bici(const string& id_bici) const{
        return b.existe_bici(id_bici);
    }

    bool Cjt_estacions::existe_estacion(const string& id_estacion) const{
        return estaciones.count(id_estacion) != 0;
    }