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
  ofstream ftransaccion("fTransacciones.txt");
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
  ftransaccion.close();
}

void sistema::transaccionPorCliente(int numcuenta){
  ifstream ftransaccion("fTransacciones.txt");
  string linea;
  bool encontrado = false;
  try
  {
    if (ftransaccion.is_open())
    {
      while (ftransaccion)
      {
        if (ftransaccion.eof())
        {
          break;
        }
        
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
  ftransaccion.close();
}

void sistema::transaccionPorAnio(int A){
  ifstream ftransaccion("fTransacciones.txt");
  string linea;
  bool encontrado = false;
  try
  {
    if (ftransaccion.is_open())
    {
      while (ftransaccion)
      {
        if (ftransaccion.eof())
        {
          break;
        }
        
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
  ftransaccion.close();
}

void sistema::transaccionPorMes(int M){
  ifstream ftransaccion("fTransacciones.txt");
  string linea,aux,dia;
  bool encontrado = false;
  setearfecha();
  try
  {
    if (ftransaccion.is_open())
    {
      getline(ftransaccion,linea);
      cout << linea<< endl;
      while (ftransaccion)
      {
        if (ftransaccion.eof())
        {
          break;
        }
        ftransaccion >>dia;
        ftransaccion >> linea;
        aux = "0" + to_string(M);
        if (linea == aux )
        {
          cout << dia << "\t"; 
          cout << linea << "\t";
          for (int i = 0; i < 4; i++)
          {
            ftransaccion >> linea;
            cout << linea << "\t";
          }
          cout << endl;
          encontrado = true;
        }
        
      }
      if (!encontrado)
      {
        throw "No hubo transacciones en ese mes";
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
  ftransaccion.close();
}

void sistema::mostrarTransacciones(){
  ifstream ftransaccion("fTransacciones.txt");
  string linea;
  try
  {
    if (ftransaccion.is_open())
    {
      ftransaccion.ignore(1000, '\n');
      while (ftransaccion)
      {
        if (ftransaccion.eof())
        {
          break;
        }
        
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
  ftransaccion.close();
}

void sistema::guardarClientes(Banco &ucc){
  ofstream fclientes("fclientes.txt");
  cout << "entro a la funcio guardar clientes" << endl;
  try
  {
    if (fclientes.is_open())
    {
      cout << ucc.get_cantidadClientes() << endl;
      fclientes << "DNI\tNombre\tIngreso\tNivel\tEstado\tNumero de cuenta\tSaldo en pesos\tSaldo en dolares" << endl;
      for (int i = 0; i < ucc.get_cantidadClientes(); i++)
      {

        /*fclientes << ucc.get_Cliente(i).get_DNI() << "\t";
        fclientes << ucc.get_Cliente(i).get_nombre() << "\t";
        fclientes << ucc.get_Cliente(i).get_ingreso() << "\t";
        fclientes << ucc.get_Cliente(i).get_nivel() << "\t";
        fclientes << ucc.get_Cliente(i).get_estado() << "\t";
        fclientes << ucc.get_Cliente(i).get_numCuenta() << "\t";
        fclientes << ucc.get_Cliente(i).get_saldoPesos() << "\t";
        fclientes << ucc.get_Cliente(i).get_saldoDolares() << endl;*/
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
  fclientes.close();

}






