#include "civilizacion.h"


Aldeano capturar(){
    Aldeano j;
    string nombre;
    string genero;
    size_t edad;
    size_t salud;
    cout <<"Nombre: ";
    getline(cin,nombre);
    j.setNombre(nombre);

    cout <<"Genero: ";
    getline(cin,genero);
    j.setGenero(genero);

    cout <<"Edad: ";
    cin>>edad;
    j.setEdad(edad);

     cout <<"Salud: ";
    cin>>salud; cin.ignore();
    j.setSalud(salud);

    return j;
}
void menu (Civilizacion &s)
{
    string op;
    while(true)
    {
        cout<<"1) Agregar  "<< endl;
        cout<<"2) Eliminar "<< endl;
        cout<<"3) clasificar "<< endl;
        cout<<"4) Buscar  "<< endl;
        cout<<"5) Modificar  "<< endl;
        cout<<"6) Mostrar "<< endl;
        cout<<"0) Salir "<<endl;
        getline(cin, op);

        if(op=="1")
        {
            string opc;
            while(true){
            cout<<"1.- Agregar al inicio " <<endl;
            cout<<"2.- Agregar al final " <<endl;
            cout<<"0.- Salir"<<endl;
            getline (cin,opc);
            if (opc=="1")
            {
                Aldeano j;
                cin>>j;
                s.agregarInicio(j);
                s.setPuntuacion(s.getPuntuacion()+100);
            }
            else if(opc=="2")
            {
                Aldeano j;
                cin>>j;
                s.agregarFinal(j);
                s.setPuntuacion(s.getPuntuacion()+100);
            }   
            else if(opc=="0")
            {
                break;
            }
            else
            {
                cout<<"opcion invalida"<<endl;
            }
            }
            

        }
        else if(op=="2")
        {
            string opc2;
            while(true){
            cout<<"1.-Eliminar por nombre"<<endl;
            cout<<"2.-Eliminar por salud"<<endl;//se pide la salud
            cout<<"3.-Eliminar por edad"<<endl;//mayor o igual a 60
            cout<<"0.-Salir"<<endl;
            getline(cin,opc2);
            if(opc2=="1")
            {
                string nombre;
                cout<<"Nombre a eliminar: ";
                getline(cin,nombre);
                s.eliminarNombre(nombre);
            }
            else if(opc2=="2")
            {
                size_t sa;
                cout<<"salud a eliminar,se eliminan los menores a esto.";
                cin>>s;
                s.eliminarSalud(sa);
            }
            else if(opc2=="3")
            {
                s.eliminarEdad();
            }
            else if(opc2=="0")
            {
                break;
            }
            else
            {
                cout<<"opcion invalida. vuleve a intentarlo"<<endl;
            }
            
            }
        }
         else if(op=="3")
        {
            string opc3;
            while(true){
            cout<<"1.-Clasificar por nombre"<<endl;
            cout<<"2.-Clasificar por edad"<<endl;
            cout<<"3.-Clasificar por salud"<<endl;
            cout<<"0.-Salir"<<endl;
            getline(cin,opc3);
            if(opc3=="1")
            {
                s.ordenarNombre();
            }
            else if(opc3=="2")
            {
                s.ordenarEdad();
            }
            else if(opc3=="3")
            {
                s.ordenarSalud();
            }
            else if(opc3=="0")
            {
                break;
            }
            else
            {
                cout <<"Opcion invalida, intentalo de nuevo.";
            }

            }
        }
         else if(op=="6")
        {
            s.print();
        }
         else if(op=="5")
        {
            string opc3,aux;
            int aux2,aux3;
            string aux4,aux1;
            cout <<"inglresa el nombre a modificar: ";
            cin>>aux4; cin.ignore();
            s.setNombre(aux4);
            Aldeano a;
            Aldeano *ptr = s.buscara(aux4);
            if(ptr == nullptr){
                cout <<"No hay coincidencias "<<endl;
            }
            else
            {
                cout<<*ptr<<endl;
                cout<<"1.-Modificar nombre"<<endl;
                cout<<"2.-Modificar genero"<<endl;
                cout<<"3.-Modificar edad"<<endl;
                cout<<"4.-Modificar salud"<<endl;
                cout <<"Elige una opcion: ";
                getline(cin,opc3);
                if(opc3 =="1"){
                    cout <<"Dame el nuevo nombre: ";
                    cin>>aux;
                    ptr->setNombre(aux); cin.ignore();
                }
                if(opc3=="2")
                {
                    cout <<"Dame el nuevo genero: ";
                    cin>>aux1;
                    ptr->setGenero(aux1); cin.ignore();

                }
                if(opc3=="3")
                {
                    cout <<"Dame la nueva edad: ";
                    cin>>aux2;
                    ptr->setEdad(aux2); cin.ignore();
                }
                if (opc3=="4")
                {
                    cout <<"Dame la nueva salud: ";
                    cin>>aux3;
                    ptr->setSalud(aux3); cin.ignore();
                }
                } 
        }
         else if(op=="0")
        {
            break;
        }
        else if(op == "4"){
            
           Aldeano a;
           string nombre;
           cout<<"Nombre: ";
           getline(cin,nombre);
            a.setNombre(nombre);
            Aldeano *ptr = s.buscara(nombre);
            if(ptr == nullptr){
                cout<<endl;
                cout<<"no encontrado"<<endl;
            }
            else
            {
                cout <<*ptr <<endl;
             
            }

        }
        else
        {
            cout <<"opcion invalida,intentelo de nuevo."<<endl;
        }
        
    }

} 