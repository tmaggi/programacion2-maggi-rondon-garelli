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
  system("pause");
}

void listadoClientes(Banco bancoUCC){
  bancoUCC.listadoClientes();
  system("pause");
}

void transaccionesCliente(sistema sistemaUCC){
  int numcuenta;
  cout << "Ingrese el numero de cuenta del cliente: ";
  cin >> numcuenta;
  sistemaUCC.transaccionPorCliente(numcuenta);
  system("pause");
}

void transaccionesMes(sistema sistemaUCC){
  int mes;
  cout << "Ingrese el mes en formato numerico(mm): ";
  cin >> mes;
  sistemaUCC.transaccionPorMes(mes);
  system("pause");
}

void transaccionesAnio(sistema sistemaUCC){
  int A;
  cout << "Ingrese el anio en formato numerico(yyyy): ";
  cin >> A;
  sistemaUCC.transaccionPorAnio(A);
  system("pause");
}

void todasTransacciones(sistema sistemaUCC){
  sistemaUCC.mostrarTransacciones();
  system("pause");
}
void depositar(Banco bancoUCC){
  double monto,numero;
  string moneda;
  cout<<"ingrese la moneda (p)pesos (d)dolares"<<endl;
  cin>>moneda;
  cout<<"ingrese el nro de cuenta en el que desea depositar"<<endl;
  cin>>numero;
  cout<<"ingrese el monto a depositar"<<endl;
  cin>>monto;
  bancoUCC.deposito(monto,numero,moneda);
}
void extraccion(Banco bancoUCC){
  double monto,numero;
  string moneda;
  cout<<"ingrese la moneda (p)pesos (d)dolares"<<endl;
  cin>>moneda;
  cout<<"ingrese el nro de cuenta en el que desea extraer"<<endl;
  cin>>numero;
  cout<<"ingrese el monto a extraer"<<endl;
  cin>>monto;
  bancoUCC.extraer(monto,numero,moneda);
}
void credito(Banco BancoUCC){

  
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
  case 7:
    depositar(bancoUCC);
    break;
  case 8:
    extraccion(bancoUCC);
    break;
  case 9:
    credito(bancoUCC);
  default:
    break;
  }

};




int main(){
  int operacion;
  int b;
  string variable = "si";
  
  Banco bancoUCC(3);
  sistema sistemaUCC;
  bancoUCC.cargaclientes();

  while (variable == "si")
  {
    cout << "ingrese la operacion que desea realizar: " << endl;
    cout << "(1) Ver detalle de un cliente ingresando su numero de cuenta" << endl;
    cout << "(2) Ver listado de todos los clientes del banco" << endl;
    cout << "(3) Ver Listado de transacciones de un cliente" << endl;
    cout << "(4) Ver listado de transacciones de un mes" << endl;
    cout << "(5) ver listado de transacciones de un anio" << endl;
    cout << "(6) Ver listado de todas las transacciones" << endl;
    cout << "(7) Depositar dinero" << endl;
    cout<<  "(8) Extraer dinero" << endl;
    cout<<  "(9) Pagar en credito" << endl;
    cin >> operacion;

    Menu(operacion,bancoUCC,sistemaUCC);
    cout<<"si desea seguir operando, ingrese si"<<endl;
    cin >> variable;
  }
  
  return 0;
}


