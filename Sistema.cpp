#include <iostream>
#include "lib.h"
#include <ctime>
#include <fstream>
using namespace std;

void sistema::guardartransaccion(double num,int numtransaccion,char divisa){
  ofstream ftransaccion;
  if (ftransaccion.is_open())
  {
    dia=0;
    mes=0;
    ano=0;
    /*ctime setea la fecha*/
    ftransaccion << dia << " / " << mes << " / " << ano << "\t";
    ftransaccion << numtransaccion << "\t";
    ftransaccion << divisa << "\t";
    ftransaccion << num << endl;
  }
  else{
    cout << "no se pudo abrir el archivo" << endl;
  }
}









