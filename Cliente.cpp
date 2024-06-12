#include <iostream>
#include "lib.h"
using namespace std;

Cliente::Cliente()
{
  estado = "ACTIVO";
  Cuenta();
  nivel = "PLATA";
}



void Cliente::set_estado(std::string est)
{
  estado = est;
}


string Cliente::get_estado()
{
  return estado;
}

void Cliente::depositar_pesos(double monto)
{
  try
  {
    if (monto < 0)
    {
      throw "Monto invalido";
    }
    else
    {
      cuenta.set_saldoPesos(cuenta.get_saldoPesos() + monto);
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void Cliente::depositar_dolares(double monto)
{
  try
  {
    if (monto < 0)
    {
      throw "Monto invalido";
    }
    else
    {
      cuenta.set_saldoDolares(cuenta.get_saldoDolares() + monto);
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void Cliente::retirar_pesos(double monto)
{
  try
  {
    if (cuenta.get_saldoPesos() < monto)
    {
      throw "Saldo insuficiente";
    }
    else
    {
      cuenta.set_saldoPesos(cuenta.get_saldoPesos() - monto);
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void Cliente::retirar_dolares(double monto)
{
  try
  {
    if (cuenta.get_saldoDolares() < monto)
    {
      throw "Saldo insuficiente";
    }
    else
    {
      cuenta.set_saldoDolares(cuenta.get_saldoDolares() - monto);
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

Cuenta* Cliente::get_Cuenta()
{
  return &cuenta;
}

void Cliente::set_nivel(string niv)
{
  try
  {
    if (niv == "PLATA")
    {
      cuenta.set_limite(0);
      nivel = niv;
    }
    else if (niv == "ORO")
    {
      cuenta.set_limite(250000);
      nivel = niv;
    }
    else if (niv == "PLATINO")
    {
      cuenta.set_limite(500000);
      nivel = niv;
    }
    else
    {
      throw "Nivel invalido";
    }
  } 
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

string Cliente::get_nivel()
{
  return nivel;
}


