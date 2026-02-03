/**
 * @mainpage Bicing bifurcado.
 
En esta practica se gestiona un conjunto de bicis en un conjunto de estaciones llamado Bicing. Se introducen las clases <em>Cjt_estacions</em>, <em>Cjt_bicis</em>, <em>Estacion</em> y <em>Bici<em>.
El programa principal se encuentra en el archivo program.cc. Todos los elementos y funciones privadas estan incluidas, las publicas tambien.
*/

/** @file program.cc
    @brief Programa principal para el ejercicio <em>Bicing bifurcado</em>.
*/

#include "Bici.hh"
#include "Estacion.hh"
#include "Cjt_estacions.hh"
#include "Cjt_bicis.hh"
#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @brief Programa principal para el ejercicio <em>Bicing bifurcado</em>.
*/
int main(){
    Cjt_estacions b;
    b.lectura_estaciones();
    string operacion;
    cin >> operacion;

    while(operacion != "fin"){
        if(operacion == "alta_bici" or operacion == "ab"){
            string id_bici, id_estacion;
            cin >> id_bici >> id_estacion;
            cout << "#ab " << id_bici << ' ' << id_estacion << endl;
            if(b.existe_bici(id_bici)){
                cout << "error: la bici ya existe" << endl;
            }
            else if(not b.existe_estacion(id_estacion)){
                cout << "error: la estacion no existe" << endl;
            }
            else if(b.consultar_estacion(id_estacion).full_estacion()){
                cout << "error: la bici no cabe" << endl;
            }
            else{
                b.alta_bici(id_bici, id_estacion);
            }
        }
        else if(operacion == "baja_bici" or operacion == "bb"){
            string id_bici;
            cin >> id_bici;
            cout << "#bb " << id_bici << endl;
            if(not b.existe_bici(id_bici)){
                cout << "error: la bici no existe" << endl;
            }
            else{
                b.baja_bici(id_bici);
            }
        }
        else if(operacion == "estacion_bici" or operacion == "eb"){
            string id_bici;
            cin >> id_bici;
            cout << "#eb " << id_bici << endl;
            if(not b.existe_bici(id_bici)){
                cout << "error: la bici no existe" << endl;
            }
            else{
                cout << b.estacion_bici_consulta(id_bici) << endl;
            }
        }
        else if(operacion == "viajes_bici" or operacion == "vb"){
            string id_bici;
            cin >> id_bici;
            cout << "#vb " << id_bici << endl;
            if(not b.existe_bici(id_bici)){
                cout << "error: la bici no existe" << endl;
            }
            else{
                b.viajes_bici(id_bici);
            }
        }
        else if(operacion == "mover_bici" or operacion == "mb"){
            string id_bici, id_estacion;
            cin >> id_bici >> id_estacion;
            cout << "#mb " << id_bici << ' ' << id_estacion << endl;
            if(not b.existe_bici(id_bici)){
                cout << "error: la bici no existe" << endl;
            }
            else if(not b.existe_estacion(id_estacion)){
                cout << "error: la estacion no existe" << endl;
            }
            else if(b.estacion_bici_consulta(id_bici) == id_estacion){
                cout << "error: la bici ya esta en el sitio" << endl;
            }
            else if(b.consultar_estacion(id_estacion).full_estacion()){
                cout << "error: la bici no cabe" << endl;
            }
            else{
                b.mover_bici(id_bici, id_estacion);
            }
        }
        else if(operacion == "bicis_estacion" or operacion == "be"){
            string id_estacion;
            cin >> id_estacion;
            cout << "#be " << id_estacion << endl;
            if(not b.existe_estacion(id_estacion)){
                cout << "error: la estacion no existe" << endl;
            }
            else{
                b.bicis_estacion(id_estacion);
            }
        }
        else if(operacion == "modificar_capacidad" or operacion == "mc"){
            string id_estacion;
            int n;
            cin >> id_estacion >> n;
            cout << "#mc " << id_estacion << ' ' << n << endl;
            if(not b.existe_estacion(id_estacion)){
                cout << "error: la estacion no existe" << endl;
            }
            else if(n < b.consultar_estacion(id_estacion).cuantas_bicis()){
                cout << "error: capacidad insuficiente" << endl;
            }
            else{
                b.modificar_capacidad(id_estacion, n);
            }
        }
        else if(operacion == "plazas_libres" or operacion == "pl"){
            cout << "#pl" << endl;
            cout << b.plazas_libres() << endl;
        }
        else if(operacion == "subir_bicis" or operacion == "sb"){
            cout << "#sb" << endl;
            b.subir_bicis();    
        }
        else if(operacion == "asignar_estacion" or operacion == "ae"){
            string id_bici;
            cin >> id_bici;
            cout << "#ae " << id_bici << endl;
            if(b.existe_bici(id_bici)){
                cout << "error: la bici ya existe" << endl;
            }
            else if(b.plazas_libres() == 0){
                cout << "error: no hay plazas libres" << endl;
            }
            else{
                b.asignar_estacion(id_bici);
            }
        }
        cin >> operacion;
    }
}