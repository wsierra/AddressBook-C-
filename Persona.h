#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
#include "FechaDM.h"
using namespace std;

enum OrdenPer {NOMBRE, APELLIDO};


class Persona{

private:
    string apellido;
    string nombre;
    string numero;
    string direccion;
    FechaDM cumple;

    static OrdenPer orden;

    string minu(string cadena);

public:
    Persona();
    Persona(string, string, string, string, FechaDM);

    void ape(string);
    void nom(string);
    void num(string);
    void dir(string);
    void cum(FechaDM);
    string ape(void);
    string nom(void);
    string num(void);
    string dir(void);
    FechaDM cum(void);

    bool operator<(const Persona &);
    bool operator>(const Persona &);
    friend void ordenPer(OrdenPer);
    friend OrdenPer ordenPer(void);
    friend ostream & operator<<(ostream &, const Persona &);
};

OrdenPer Persona::orden = APELLIDO;

Persona::Persona()
{
    apellido = "";
    nombre = "";
    numero = "";
    direccion = "";
    cumple.mes = 0;
    cumple.dia = 0;
}

Persona::Persona(string apellido, string nombre, string numero, string direccion, FechaDM cumple)
{
    this->apellido = apellido;
    this->nombre = nombre;
    this->numero = numero;
    this->direccion = direccion;
    this->cumple = cumple;
}

void Persona::ape(string apellido)
{
    this->apellido = apellido;
    return;
}

void Persona::nom(string nombre)
{
    this->nombre = nombre;
    return;
}

void Persona::num(string numero)
{
    this->numero = numero;
    return;
}

void Persona::dir(string direccion)
{
    this->direccion = direccion;
}

void Persona::cum(FechaDM cumple)
{
    this->cumple = cumple;
    return;
}

string Persona::ape(void)
{
    return apellido;
}

string Persona::nom(void)
{
    return nombre;
}

string Persona::num(void)
{
    return numero;
}

string Persona::dir(void)
{
    return direccion;
}

FechaDM Persona::cum(void)
{
    return cumple;
}

bool Persona::operator<(const Persona & p)
{
    bool resul;

    if (orden)
        resul = minu(apellido) < minu(p.apellido) ||
                minu(apellido) == minu(p.apellido) && minu(nombre) < minu(p.nombre);
    else
        resul = minu(nombre) < minu(p.nombre) ||
                minu(nombre) == minu(p.nombre) && minu(apellido) < minu(p.apellido);

    return resul;
}

bool Persona::operator>(const Persona & p)
{
    bool resul;

    if (orden)
        resul = minu(apellido) > minu(p.apellido) ||
                minu(apellido) == minu(p.apellido) && minu(nombre) > minu(p.nombre);
    else
        resul = minu(nombre) > minu(p.nombre) ||
                minu(nombre) == minu(p.nombre) && minu(apellido) > minu(p.apellido);

    return resul;
}

void ordenPer(OrdenPer orden)
{
    Persona::orden = orden;
    return;
}

OrdenPer ordenPer(void)
{
    return Persona::orden;
}

ostream & operator<<(ostream &os, const Persona &per)
{
    if (per.apellido == "" && per.nombre == "")
        os << "[Desconocido]";
    else
        if (Persona::orden)
            os << per.apellido << " " << per.nombre;
        else
            os << per.nombre << " " << per.apellido;

    os << " - " << per.numero << " - " << per.direccion << " - ";

    if (per.cumple.mes)
        os << per.cumple.dia << "/" << per.cumple.mes;

    return os;
}

string Persona::minu(string cadena)
{
    for (int i = 0; i < cadena.length(); i++)
        if ('A' <= cadena[i] && cadena[i] <= 'Z')
            cadena[i] += 32;
    return cadena;
}

#endif // PERSONA_H
