#include "civilizacion.h"
#include<algorithm>

Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(const string &nombre, int x, int y, int puntuacion)
{
    this->nombre = nombre;
    this->x = x;
    this->y = y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v)
{
    nombre = v;
}
void Civilizacion::setX(int v)
{
    x = v;
}
void Civilizacion::setY(int v)
{
    y = v;
}
void Civilizacion::setPuntuacion(int v)
{
    puntuacion = v;
}



string Civilizacion::getNombre()
{
    return nombre;
}
int Civilizacion::getX()
{
    return x;
}
int Civilizacion::getY()
{
    return y;
}
int Civilizacion::getPuntuacion()
{
    return puntuacion;
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::print()
{
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(22) << "Edad";
    cout << setw(20) << "Genero";
    cout << setw(10) << "Salud";
    cout << endl;
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++){
         cout << *it <<endl;
    }
       
}
void Civilizacion::eliminarNombre(const string &nombre)
{
     for(auto it = aldeanos.begin(); it != aldeanos.end();it++){
         Aldeano &j= *it;
         if(nombre == j.getNombre()){
             aldeanos.erase(it);
             break;
         }
     }
}
bool comparador(const Aldeano &j)
{
    
    return j.getEdad()==60;
}
void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if(comparador);
}
void Civilizacion::eliminarEdad(size_t edad)
{
    aldeanos.remove_if([edad](const Aldeano &j){return j.getEdad( )>=edad;});
}
void Civilizacion::eliminarSalud(size_t salud)
{
    aldeanos.remove_if([salud](const Aldeano &j){return j.getSalud( )>=salud;});
}
void Civilizacion::ordenarNombre()
{
    aldeanos.sort(); 
}
bool comparadorEdad(const Aldeano &j1,const Aldeano &j2)
{
    return j1.getEdad()>j2.getEdad();
}
void Civilizacion::ordenarEdad()
{
    aldeanos.sort(comparadorEdad);
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &j1,const Aldeano &j2){return j1.getSalud()>=j2.getSalud();});
}
Aldeano* Civilizacion::buscara(const string& a)
{
    for(auto it = aldeanos.begin(); it != aldeanos.end();it++){
         Aldeano &j= *it;
         if(a == j.getNombre()){
            return &(*it);
             break;
         }
         else
         {
            cout<<"No encontrado"<<endl;
            

         }
         
     }
     return 0;
    
}

 