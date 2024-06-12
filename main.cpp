#include <iostream>
#include "lib.h"
#include <fstream>
#include <string>
#include <limits>
using namespace std;

void detalleCliente(Banco bancoUCC){
  int numcuenta;
  cout << "Ingrese el numero de cuenta del cliente: ";
  cin >> numcuenta;
  bancoUCC.detalleCliente(numcuenta);
}

void listadoClientes(Banco bancoUCC){
  bancoUCC.listadoClientes();
}

void transaccionesCliente(sistema sistemaUCC){
  int numcuenta;
  cout << "Ingrese el numero de cuenta del cliente: ";
  cin >> numcuenta;
  sistemaUCC.transaccionPorCliente(numcuenta);
}

void transaccionesMes(sistema sistemaUCC){
  int mes;
  cout << "Ingrese el mes en formato numerico(mm): ";
  cin >> mes;
  sistemaUCC.transaccionPorMes(mes);
}

void transaccionesAnio(sistema sistemaUCC){
  int A;
  cout << "Ingrese el anio en formato numerico(yyyy): ";
  cin >> A;
  sistemaUCC.transaccionPorAnio(A);
}

void todasTransacciones(sistema sistemaUCC){
  sistemaUCC.mostrarTransacciones();
}


void Menu(int operacion,Banco bancoUCC,sistema sistemaUCC){
  switch (operacion)
  {
  case 1:
    detalleCliente(bancoUCC);
    break;
  case 2:
    listadoClientes(bancoUCC);
    break;
  case 3:
    transaccionesCliente(sistemaUCC);
    break;
  case 4:
    transaccionesMes(sistemaUCC);
    break;
  case 5:
    transaccionesAnio(sistemaUCC);
    break;
  case 6:
    todasTransacciones(sistemaUCC);
    break;
  default:
    break;
  }

};




int main(){
  int operacion;
  Banco bancoUCC;
  sistema sistemaUCC;
  

  cout << "ingrese la operacion que desea realizar: " << endl;
  cout << "(1) Ver detalle de un cliente ingresando su numero de cuenta" << endl;
  cout << "(2) Ver listado de todos los clientes del banco" << endl;
  cout << "(3) Ver Listado de transacciones de un cliente" << endl;
  cout << "(4) Ver listado de transacciones de un mes" << endl;
  cout << "(5) ver listado de transacciones de un anio" << endl;
  cout << "(6) Ver listado de todas las transacciones" << endl;
  cin >> operacion;
  Menu(operacion,bancoUCC,sistemaUCC);


  return 0;
}


