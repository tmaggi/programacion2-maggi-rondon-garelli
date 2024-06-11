#include <iostream>
#include "lib.h"
#include <fstream>
using namespace std;

void Banco::cargaclientes(){
    ifstream fclientes;
    fclientes.open("clientes.txt");
    if (fclientes.is_open())
    {
        while (!fclientes.eof())
        {
        Clientes = new Cliente[1];
        fclientes >> Clientes.DNI;
        fclientes >> Clientes.nombre;
        fclientes >> Clientes.ingreso;
        fclientes >> Clientes.tipoCliente;
        fclientes >> Clientes.estado;
        fclientes >> Clientes.cuenta.get_numero_cuenta();
        fclientes >> Clientes.cuenta.get_saldoPesos();
        fclientes >> Clientes.cuenta.get_saldoDolares();
        clientes.push_back(cliente);
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
}