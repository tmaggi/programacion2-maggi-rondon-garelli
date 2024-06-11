#include <iostream>
#include "lib.h"
#include <ctime>
using namespace std;

Transaccion::Transaccion(int numCliente,string tipo,string moneda,double cantidad,int D,int M,int A){
  numeroCliente = numCliente;
  tipoTransaccion = tipo;
  divisa = moneda;
  monto = cantidad;
  dia = D;
  mes = M;
  anio = A;
}

void Transaccion::set_numeroCliente(int num){
  numeroCliente = num;
}

void Transaccion::set_tipoTransaccion(string tipo){
  tipoTransaccion = tipo;
}

void Transaccion::set_divisa(string moneda){
  divisa = moneda;
}

void Transaccion::set_monto(double num){
  monto = num;
}

void Transaccion::set_dia(int num){

}

/*Falta ver como sacar la fecha de hoy automaticamente*/












