#include <iostream>
#include "lib.h"
#include <fstream>
#include <string>
using namespace std;

Banco::Banco(){
    cantidadClientes = calcularClientes();
    Clientes = new Cliente[cantidadClientes];
};

Banco::Banco(int cantidadClientes)
{
    cantidadClientes = 0;
    Clientes = new Cliente[cantidadClientes];
};


void Banco::cargaclientes(){
    ifstream fclientes;
    fclientes.open("clientes.txt");
    string dni, nombre,estado,nivel;
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
                fclientes >> nivel;
                fclientes >> estado;
                fclientes >> numero_cuenta;
                fclientes >> saldoPesos;
                fclientes >> saldoDolares;
                
                Clientes[i].set_DNI(stoi(dni));
                Clientes[i].set_nombre(nombre);
                Clientes[i].set_ingreso(ingreso);
                Clientes[i].set_nivel(nivel);
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

void Banco::detalleCliente(int numCuenta){
    try
    {
        for (int i = 0; i < cantidadClientes; i++)
        {       
            if (numCuenta == Clientes[i].get_Cuenta()->get_numero_cuenta())
            {
                for (int j = 0; j < i; j++)
                {
                    cout << "DNI: " << Clientes[j].get_DNI() << endl;
                    cout << "Nombre: " << Clientes[j].get_nombre() << endl;
                    cout << "Ingreso: " << Clientes[j].get_ingreso() << endl;
                    cout << "Nivel: " << Clientes[j].get_nivel() << endl;
                    cout << "Estado: " << Clientes[j].get_estado() << endl;
                    cout << "Numero de cuenta: " << Clientes[j].get_Cuenta()->get_numero_cuenta() << endl;
                    cout << "Saldo en pesos: " << Clientes[j].get_Cuenta()->get_saldoPesos() << endl;
                    cout << "Saldo en dolares: " << Clientes[j].get_Cuenta()->get_saldoDolares() << endl;
                }
            }
            else
            {
                throw "No se encontro el cliente";
            }
        }
    }
    catch(const char* exception)
    {
        cerr << "Error: " << exception << endl;
    }
}

void Banco::listadoClientes(){
    for (int i = 0; i < cantidadClientes; i++)
    {
        cout << "DNI: " << Clientes[i].get_DNI() << endl;
        cout << "Nombre: " << Clientes[i].get_nombre() << endl;
        cout << "Ingreso: " << Clientes[i].get_ingreso() << endl;
        cout << "Nivel: " << Clientes[i].get_nivel() << endl;
        cout << "Estado: " << Clientes[i].get_estado() << endl;
        cout << "Numero de cuenta: " << Clientes[i].get_Cuenta()->get_numero_cuenta() << endl;
        cout << "Saldo en pesos: " << Clientes[i].get_Cuenta()->get_saldoPesos() << endl;
        cout << "Saldo en dolares: " << Clientes[i].get_Cuenta()->get_saldoDolares() << endl;
    }
}

int Banco::get_cantidadClientes(){
    return cantidadClientes;
}

Cliente* Banco::get_Clientes(){
    return Clientes;
}

int Banco::calcularClientes(){
    ifstream fclientes;
    fclientes.open("clientes.txt");
    int cantidad;
    try
    {
        if (fclientes.is_open())
        {
            fclientes >> cantidad;
            fclientes >> cantidad;
            fclientes >> cantidad;
            fclientes >> cantidad;
            return cantidad;
        }
        else
        {
            throw "No se pudo abrir el archivo";
        }
    }
    catch(const char* exception)
    {
        cerr << "Error: " << exception << endl;
        return 0;
    }
}

