#include <iostream>
#include "lib.h"
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

sistema::sistema(){}

void sistema::setearfecha(){
  time_t t = time(0);
  tm* ahora = localtime(&t);
  anio = ahora->tm_year + 1900;
  mes = ahora->tm_mon + 1;
  dia = ahora->tm_mday;
}
  

void sistema::guardartransaccion(double num,int numcuenta,char divisa){
  ofstream ftransaccion;
  try
  {
    if (ftransaccion.is_open())
    {
      setearfecha();
      ftransaccion << dia << " / " << mes << " / " << anio << "\t";
      ftransaccion << numcuenta << "\t";
      ftransaccion << divisa << "\t";
      ftransaccion << num << endl;
    }
    else{
      throw "no se pudo abrir el archivo";
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void sistema::transaccionPorCliente(int numcuenta){
  ifstream ftransaccion;
  ftransaccion.open("fTransacciones.txt");
  string linea;
  bool encontrado = false;
  try
  {
    if (ftransaccion.is_open())
    {
      while (!ftransaccion.eof())
      {
        getline(ftransaccion, linea);
        if (linea.find(to_string(numcuenta)) != string::npos)
        {
          cout << linea << endl;
          encontrado = true;
        }
      }
      if (!encontrado)
      {
        throw "No se encontro el cliente";
      }
    }
    else
    {
      throw "No se pudo abrir el archivo";
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void sistema::transaccionPorAnio(int A){
  ifstream ftransaccion;
  ftransaccion.open("fTransacciones.txt");
  string linea;
  bool encontrado = false;
  try
  {
    if (ftransaccion.is_open())
    {
      while (!ftransaccion.eof())
      {
        getline(ftransaccion, linea);
        if (linea.find(to_string(A)) != string::npos)
        {
          cout << linea << endl;
          encontrado = true;
        }
      }
      if (!encontrado)
      {
        throw "No hubo transacciones en ese año";
      }
    }
    else
    {
      throw "No se pudo abrir el archivo";
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void sistema::transaccionPorMes(int M){
  ifstream ftransaccion;
  ftransaccion.open("fTransacciones.txt");
  string linea;
  bool encontrado = false;
  setearfecha();
  try
  {
    if (ftransaccion.is_open())
    {
      while (!ftransaccion.eof())
      {
        getline(ftransaccion, linea);
        if ((linea.find(to_string(M)) != string::npos) && (linea.find(to_string(anio)) != string::npos))
        {
          cout << linea << endl;
          encontrado = true;
        }
      }
      if (!encontrado)
      {
        throw "No hubo transacciones en ese año";
      }
    }
    else
    {
      throw "No se pudo abrir el archivo";
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void sistema::mostrarTransacciones(){
  ifstream ftransaccion;
  ftransaccion.open("fTransacciones.txt");
  string linea;
  try
  {
    if (ftransaccion.is_open())
    {
      ftransaccion.ignore(1000, '\n');
      while (!ftransaccion.eof())
      {
        getline(ftransaccion, linea);
        cout << linea << endl;
      }
    }
    else
    {
      throw "No se pudo abrir el archivo";
    }
  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
}

void sistema::guardarClientes(Banco *ucc){
  ofstream fclientes;
  fclientes.open("clientes.txt");
  try
  {
    
    if (fclientes.is_open())
    {
      fclientes << "Cantidad de Clientes: " << ucc->get_cantidadClientes() << endl;
      fclientes << "DNI" << "\t\t" << "Nombre" << "\t\t" << "Ingreso" << "\t\t" << "Nivel" << "\t\t" << "Estado" << "\t\t" << "Numero de Cuenta" << "\t\t" << "Saldo Pesos" << "\t\t" << "Saldo Dolares" << endl;
      for (int i = 0; i < ucc->get_cantidadClientes(); i++)
      {
        fclientes << ucc->get_Clientes()[i].get_DNI() << "\t";
        fclientes << ucc->get_Clientes()[i].get_nombre() << "\t";
        fclientes << ucc->get_Clientes()[i].get_ingreso() << "\t";
        fclientes << ucc->get_Clientes()[i].get_nivel() << "\t" << "\t";
        fclientes << ucc->get_Clientes()[i].get_estado() << "\t" << "\t";
        fclientes << ucc->get_Clientes()[i].get_Cuenta()->get_numero_cuenta() << "\t" << "\t";
        fclientes << ucc->get_Clientes()[i].get_Cuenta()->get_saldoPesos() << "\t" << "\t";
        fclientes << ucc->get_Clientes()[i].get_Cuenta()->get_saldoDolares() << endl;
      }
    }
    else
    {
      throw "No se pudo abrir el archivo";
    }

  }
  catch(const char* exception)
  {
    cerr << "Error: " << exception << endl;
  }
  

}






