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

void Cuenta::set_saldoPesos(double num)
{
  saldoPesos = num;
}

double Cuenta::get_saldoPesos()
{
  return saldoPesos;
}


/*Declaracion Metodos de Caja en Dolares*/


void Cuenta::set_saldoDolares(double num)
{
  saldoDolares = num;
}

double Cuenta::get_saldoDolares()
{
  return saldoDolares;
}




