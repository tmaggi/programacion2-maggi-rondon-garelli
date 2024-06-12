#include <iostream>
#include "lib.h"
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int main()
{
  int cantC, cantE,numcuenta;
  ifstream fclientes("fclientes.txt");
  string lien;
  getline(fclientes, lien);
  fclientes >> cantC;
  fclientes >> cantE;
  
  Banco banco(cantC, cantE);
  banco.cargaclientes();
  cout << "clientes cargados" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "Bienvenido al sistema de Banco" << endl;
  cout << "si desea abrir una nueva cuenta presione 1" << endl;
  cout << "deseea realizar una accion con una cuenta existente presione 2" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  int opcion;
  while (cout << "Ingrese una opcion" && !(cin >> opcion)) {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "ingreso invalido; porfavor ingrese una opcion valida.\n";
  }
  if (opcion == 1)
  {
    
  }
  else if (opcion == 2)
  {
    
  }
  else 
  {
    cout << "opcion invalida" << endl;
  }
  
  while (cout << "Enter a number" && !(cin >> numcuenta)) {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "ingreso invalido; porfavor ingrese un numero de cuenta.\n";
  return 0;
  }

  return 0;
}
