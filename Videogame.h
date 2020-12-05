#ifndef LABORATORIO_H
#define LABORATORIO_H
#include<vector>
#include "civilizacion.h"

class videogame
{
    string nombre_usuario;
    int vector_civilizaciones;

     vector<Civilizacion> civilizaciones;
public:
    void setNombre_usuario(const string &v);
    string getNombre_usuario();
    
    videogame();
    void agregarCivilizacion(const Civilizacion &P);
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();
    Civilizacion primero();
    Civilizacion ultimo();
    Civilizacion*buscar(const Civilizacion &p);
    Civilizacion*eliminar(const Civilizacion &p);

    void insertar(const Civilizacion&p, size_t pos);
    size_t total();
    void inicializar(const Civilizacion &p, size_t n);
   
    void ordenar();
    void ordenarUbicacion_x();
    void ordenarUbicacion_y();
    void ordenarPuntuacion();

    friend videogame& operator<<(videogame &v,const Civilizacion &p)
    {

        v.agregarCivilizacion(p);
        return v;
    }
};
#endif