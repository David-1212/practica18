#include<iostream>
#include "Videogame.h"
#include <vector>
#include "menuseleccion.h"
using namespace std;


int main(){

    videogame v;
    string op;
    while(true){
        cout<<"1) Nombre de usuario "<<endl;
        cout<<"2) Agregar civilizacion"<<endl;
        cout<<"3) insertar civilizacion"<<endl;
        cout<<"4) crear civilizacion"<<endl;
        cout<<"5) primera civilizacion"<<endl;
        cout<<"6) ultima civilizacion"<<endl;
        cout<<"7) Ordenar civilizaciones"<<endl;
        cout<<"8) Eliminar civilizacion"<<endl;
        cout <<"9) Buscar civilizacion"<<endl;
        cout<<"10) Modificar civilizacion"<<endl;
        cout<<"11) Resumen de civilizaciones"<<endl;
        cout<<"0) salir"<<endl;
        cout<<"ingrese una opcion senior: ";
        getline(cin,op);
        if (op=="2"){
            Civilizacion p;
            cin>>p;
            v.agregarCivilizacion(p);
            cin.ignore();
        }
        else if(op=="11"){
            v.mostrar();
        }
        
      
        else if (op=="0"){
            break;
        }
        else if(op=="3"){
            Civilizacion p;
            cin>>p;
            size_t pos; 
           cout<<"pocision: "<<endl;
            cin>>pos;cin.ignore();
            if(pos>=v.total()){
                cout<<"pocision no valida"<<endl;
            }
            else{
                v.insertar(p,pos);
            }
        }
        else if(op=="4"){
            Civilizacion a;
            cin>>a;
            size_t n; 
            cout<<"n: ";
            cin>>n;cin.ignore();
            v.inicializar(a,n);
        }
        else if(op=="8"){
           string aux;
           cout <<"ingresa el nombre a eliminar: ";
           cin>>aux;cin.ignore();
           Civilizacion a;
           a.setNombre(aux);
           Civilizacion *ptr =v.buscar(a);
           if(ptr ==nullptr){
               cout <<"No hay coincidencias"<<endl;
           }
           else{
               v.eliminar(*ptr);
           }

        }
        else if(op=="7"){
            string opc2;
            cout<< "1.-ordenar por nombre"<<endl;
            cout<< "2.-ordenar por pocicion en x"<<endl;
            cout<< "3.-ordenar por pocicion en y"<<endl;
            cout<< "4.-ordenar por puntuacion"<<endl;
            cout <<"Elige una opcion";
            getline(cin,opc2);
            if(opc2=="1"){
                v.ordenar();
            }
            else if(opc2 =="2"){
                v.ordenarUbicacion_x();
            }
            else if(opc2=="3"){
                v.ordenarUbicacion_y();
            }
            else if(opc2=="4"){
                v.ordenarPuntuacion();
            }

        }
        else if(op=="9"){
           Civilizacion p;
           string nombre;
           cout<<"Nombre: ";
           getline(cin,nombre);
            p.setNombre(nombre);
            Civilizacion *ptr = v.buscar(p);
            if(ptr == nullptr){
                cout<<endl;
                cout<<"no encontrado"<<endl;
            }
            else
            {
                cout <<*ptr <<endl;
                menu(*ptr);
            }
        }


        else if(op=="1"){
            string aux;
            cout<<"Dame un nombre de usuario: ";
            cin>>aux;
            v.setNombre_usuario(aux);
        }
        else if(op =="5")
        {
            if(v.total()>0){
                cout<<v.primero();
            }
            else{
                cout<<"el vector esta vacio"<<endl;
            }
        }


        else if(op=="6"){
            if(v.total()>0){
                cout<<v.ultimo();
            }
            else
            {
                cout <<"el vector esta vacio "<<endl;
            }
            
        }
        else if(op=="10"){
            string opc3,aux;
            int aux1,aux2,aux3;
            string aux4;
            cout <<"inglresa el nombre a modificar: ";
            cin>>aux4; cin.ignore();
            Civilizacion c;
            c.setNombre(aux4);
            Civilizacion *ptr = v.buscar(c);
            if(ptr == nullptr)
                cout <<"No hay coincidencias "<<endl;
            else
            {
                cout<<*ptr<<endl;
                cout<<"1.-modificar nombre"<<endl;
                cout<<"2.-modificar ubicacion en x"<<endl;
                cout<<"3.-modificar ubicacion en y"<<endl;
                cout<<"4.-modificar puntuacion"<<endl;
                cout <<"elige una opcion: ";
                getline(cin,opc3);
                if(opc3 =="1"){
                    cout <<"Dame el nuevo nombre: ";
                    cin>>aux;
                    ptr->setNombre(aux); cin.ignore();
                }
                if(opc3=="2")
                {
                    cout <<"Dame la nueva ubicacion en x: ";
                    cin>>aux1;
                    ptr->setX(aux1); cin.ignore();
                }
                if(opc3=="3")
                {
                    cout <<"Dame la nueva ubicacion en y: ";
                    cin>>aux2;
                    ptr->setY(aux2); cin.ignore();
                }
                if (opc3=="4")
                {
                     cout <<"Dame la nueva puntuacion: ";
                    cin>>aux3;
                    ptr->setPuntuacion(aux3); cin.ignore();
                }
                }
                }
            
            
    }
        
    return 0;
}