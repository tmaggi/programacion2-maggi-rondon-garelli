#include <iostream>
#include "lib.h"
#include <fstream>
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
    if (fclientes.is_open())
    {
        while (!fclientes.eof())
        {
       
        fclientes >> Clientes[0].get_DNI();
        fclientes >> Clientes[0].get_nombre();
        fclientes >> Clientes[0].get_ingreso();
        fclientes >> Clientes[0].get_tipoCliente();
        fclientes >> Clientes[0].get_estado();
        fclientes >> Clientes[0].cuenta.get_numero_cuenta();
        fclientes >> Clientes[0].cuenta.get_saldoPesos();
        fclientes >> Clientes[0].cuenta.get_saldoDolares();
        clientes.push_back(cliente);
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
}