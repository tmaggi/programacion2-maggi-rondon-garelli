#include <iostream>
#include "lib.h"
#include <ctime>
#include <fstream>
using namespace std;

sistema::sistema(){}

void sistema::setearfecha(){
  time_t t = time(0);
  tm* ahora = localtime(&t);
  anio = ahora->tm_year + 1900;
  mes = ahora->tm_mon + 1;
  dia = ahora->tm_mday;
}
  

void sistema::guardartransaccion(double num,int numtransaccion,char divisa){
  ofstream ftransaccion;
  try
  {
    if (ftransaccion.is_open())
    {
      
      setearfecha();
      ftransaccion << dia << " / " << mes << " / " << anio << "\t";
      ftransaccion << numtransaccion << "\t";
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









