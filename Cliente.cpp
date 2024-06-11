#include <iostream>
#include "lib.h"
using namespace std;

Cliente::Cliente()
{
  tipoCliente = "";
  estado = "ACTIVO";
  Cuenta();

}

void Cliente::set_tipoCliente(std::string tipo)
{
  tipoCliente = tipo;
}

void Cliente::set_estado(std::string est)
{
  estado = est;
}

string Cliente::get_tipoCliente()
{
  return tipoCliente;
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
      cuenta.set_Pesos(cuenta.get_Pesos() + monto);
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
      cuenta.set_Dolares(cuenta.get_Dolares() + monto);
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
    if (cuenta.get_Pesos() < monto)
    {
      throw "Saldo insuficiente";
    }
    else
    {
      cuenta.set_Pesos(cuenta.get_Pesos() - monto);
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
    if (cuenta.get_Dolares() < monto)
    {
      throw "Saldo insuficiente";
    }
    else
    {
      cuenta.set_Dolares(cuenta.get_Dolares() - monto);
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

