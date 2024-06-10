#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "lib.h"

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
      numero_cuenta = num;
    }
    catch(const char* exception)
    {
      std::cerr << "Error: " << exception << std::endl;
    }
    
}

int Cuenta::get_numero_cuenta()
{
    return numero_cuenta;
}

CajaPesos :: CajaPesos()
{
    saldo = 0;
}

void CajaPesos :: set_saldo(double num)
{
    saldo = num;
}

double CajaPesos :: get_saldo()
{
    return saldo;
}

CajaDolares :: CajaDolares()
{
    saldo = 0;
}

void CajaDolares :: set_saldo(double num)
{
    saldo = num;
}

double CajaDolares :: get_saldo()
{
    return saldo;
}



