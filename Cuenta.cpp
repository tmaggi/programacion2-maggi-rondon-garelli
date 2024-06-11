#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lib.h"
using namespace std;

/*Declaracion metodos de Cuenta*/

Cuenta::Cuenta()
{
  numero_cuenta = rand() %  999999 + 100000;
}

void Cuenta::set_numero_cuenta(int num)
{
    try
    {
      if(num < 100000 || num > 999999)
      {
        throw "Numero de cuenta invalido"; /* evita que el numero de cuenta tenga menos de 6 cifras y mas de 7*/
      }
      else
      {
        numero_cuenta = num;
      }
    }
    catch(const char* exception)
    {
      cerr << "Error: " << exception << endl;
    }
    
}

int Cuenta::get_numero_cuenta()
{
  return numero_cuenta;
}

void Cuenta::transferir_pesos(Cuenta *cuenta2,double monto)
{
  try
  {
    if(cuentaPesos.get_saldoPesos() < monto)
    {
      throw "Saldo insuficiente"; /* evita que se transfiera un monto mayor al saldo disponible*/
    }
    else
    {
      cuentaPesos.set_saldoPesos(cuentaPesos.get_saldoPesos() - monto);
      cuenta2->cuentaPesos.set_saldoPesos(cuenta2->cuentaPesos.get_saldoPesos() + monto);
    }
    
    
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void Cuenta::transferir_dolares(Cuenta *cuenta2,double monto)
{
  try
  {
    if(cuentaDolares.get_saldoDolares() < monto)
    {
      throw "Saldo insuficiente"; /* evita que se transfiera un monto mayor al saldo disponible*/
    }
    else
    {
      cuentaDolares.set_saldoDolares(cuentaDolares.get_saldoDolares() - monto);
      cuenta2->cuentaDolares.set_saldoDolares(cuenta2->cuentaDolares.get_saldoDolares() + monto);
    }
    
  
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void Cuenta::set_Pesos(double num)
{
  cuentaPesos.set_saldoPesos(num);
}

void Cuenta::set_Dolares(double num)
{
  cuentaDolares.set_saldoDolares(num);
}

double Cuenta::get_Pesos()
{
  return cuentaPesos.get_saldoPesos();
}

double Cuenta::get_Dolares()
{
  return cuentaDolares.get_saldoDolares();
}

/*Declaracion Metodos de Caja en Pesos*/
CajaPesos::CajaPesos()
{
  saldoPesos = 0;
}

void CajaPesos::set_saldoPesos(double num)
{
  saldoPesos = num;
}

double CajaPesos::get_saldoPesos()
{
  return saldoPesos;
}


/*Declaracion Metodos de Caja en Dolares*/

CajaDolares::CajaDolares()
{
  saldoDolares = 0;
}

void CajaDolares::set_saldoDolares(double num)
{
  saldoDolares = num;
}

double CajaDolares::get_saldoDolares()
{
  return saldoDolares;
}




