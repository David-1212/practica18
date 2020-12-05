#ifndef ALDEANO_H
#define ALDEANO_H
#include <iostream>
#include <iomanip>
using namespace std;

class Aldeano
{
public:
    Aldeano() {}
    Aldeano(const string &nombre, size_t edad, const string &genero, size_t salud)
    : nombre(nombre), edad(edad), genero(genero), salud(salud) {}

    void setNombre(const string &nombre);
    string getNombre()const;

    void setEdad(size_t edad);
    size_t getEdad()const;

    void setGenero(const string &genero);
    string getGenero();

    void setSalud(size_t salud);
    size_t getSalud()const;

    friend ostream& operator<<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(15) << a.nombre;
        out << setw(22) << a.edad;
        out << setw(22) << a.genero;
        out << setw(7) << a.salud;

        return out;
    }
     friend istream& operator >>(istream &in,Aldeano &j)
    {
        cout<<"Nombre: ";
        getline(cin, j.nombre);

        cout <<"Genero: ";
        getline(cin,j.genero);

        cout <<"Edad: ";
        cin>>j.edad; cin.ignore();

        cout <<"Salud: ";
        cin>>j.salud; cin.ignore();

        return in;

    }
    bool operator>(const Aldeano &j)const
    {
        return nombre>j.getNombre();
    }

    bool operator<(const Aldeano &j)const
    {
        return nombre<j.getNombre();
    }
    bool operator==(const Aldeano& j)
    {
        return nombre == j.nombre;
    }
    bool operator==(const Aldeano& j)const
    {
        return nombre == j.nombre;
    }
    
private:
    string nombre;
    size_t edad;
    string genero;
    size_t salud;
};

#endif