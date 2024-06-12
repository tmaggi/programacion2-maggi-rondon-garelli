#include <iostream>
#include "lib.h"
#include <fstream>
#include <string>
using namespace std;

Banco::Banco(int cantC, int cantE)
{
    cantidadClientes = cantC;
    Clientes = new Cliente[cantC];
    cantidadEmpleados = cantE;
    Empleados = new Empleado[cantE];
};


void Banco::cargaclientes(){
    ifstream fclientes;
    fclientes.open("clientes.txt");
    string dni, nombre, tipoCliente, estado;
    double ingreso, numero_cuenta, saldoPesos, saldoDolares;
    int i = 0;
    try
    {
        if (fclientes.is_open())
        {
            while (!fclientes.eof())
            {
                fclientes >> dni;
                fclientes >> nombre;
                fclientes >> ingreso;
                fclientes >> tipoCliente;
                fclientes >> estado;
                fclientes >> numero_cuenta;
                fclientes >> saldoPesos;
                fclientes >> saldoDolares;
                
                Clientes[i].set_DNI(stoi(dni));
                Clientes[i].set_nombre(nombre);
                Clientes[i].set_ingreso(ingreso);
                Clientes[i].set_tipoCliente(tipoCliente);
                Clientes[i].set_estado(estado);
                Clientes[i].get_Cuenta()->set_numero_cuenta(numero_cuenta);
                Clientes[i].get_Cuenta()->set_saldoPesos(saldoPesos);
                Clientes[i].get_Cuenta()->set_saldoDolares(saldoDolares);
                i++;
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