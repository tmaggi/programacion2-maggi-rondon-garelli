#include <iostream>
#include "lib.h"
#include <fstream>
#include <string>
using namespace std;

Banco::Banco(){
    cantidadClientes = 0;
    Clientes = new Cliente[cantidadClientes]; //
};

Banco::Banco(int cantidadClientes2)
{
    cantidadClientes = cantidadClientes2;
    Clientes = new Cliente[cantidadClientes];
};


void Banco::cargaclientes(){
    ifstream fclientes("fclientes.txt");
    string dni, nombre,estado,nivel,auxPesos,auxDolares,aux,apellido;
    long double saldoPesos = 0,saldoDolares =0;
    int ingreso,numero_cuenta;
    int i = 0;
    try
    {
        if (fclientes.is_open())
        {   
            getline(fclientes,aux);
            getline(fclientes,aux);
            while (fclientes)
            {   
                if (fclientes.eof())
                {
                    break;
                }
                
                fclientes >> dni;
                fclientes >> nombre;
                fclientes >>apellido;
                nombre = nombre + " ";
                nombre = nombre + apellido;
                fclientes >> ingreso;
                fclientes >> nivel;
                fclientes >> estado;
                fclientes >> numero_cuenta;
                fclientes >> auxPesos;
                fclientes >> auxDolares;
                saldoPesos = stod(auxPesos);
                saldoDolares = stod(auxDolares);

                Clientes[i].set_DNI(stoi(dni));
                Clientes[i].set_nombre(nombre);
                Clientes[i].set_ingreso(ingreso);
                Clientes[i].set_nivel(nivel);
                Clientes[i].set_estado(estado);
                Clientes[i].set_numcuenta(numero_cuenta);
                Clientes[i].set_saldo_Pesos(stold(auxPesos));
                Clientes[i].set_saldoDolares(stold(auxDolares));
                i++;
            }
        }
        else
        {
           throw "No se pudo abrir el archivo";
        }
        fclientes.close();

    }
    catch(const char* exception)
    {
        cerr << "Error: " << exception << endl;
    }
    catch(...)
    {
        cerr << "Error" << endl;

    }
}

void Banco::detalleCliente(int numCuenta){
    bool encontrado = false;
    try
    {
        for (int i = 0; i < cantidadClientes; i++)
        {       
            if (numCuenta == Clientes[i].get_numCuenta())
            {            
                cout << "DNI: " << Clientes[i].get_DNI() << endl;
                cout << "Nombre: " << Clientes[i].get_nombre() << endl;
                cout << "Ingreso: " << Clientes[i].get_ingreso() << endl;
                cout << "Nivel: " << Clientes[i].get_nivel() << endl;
                cout << "Estado: " << Clientes[i].get_estado() << endl;
                cout << "Numero de cuenta: " << Clientes[i].get_numCuenta() << endl;
                cout << "Saldo en pesos: " << Clientes[i].get_saldoPesos() << endl;
                cout << "Saldo en dolares: " << Clientes[i].get_saldoDolares() << endl;
                encontrado = true;
                
            }
            
        }
        if (!encontrado)
        {
            throw "No se encontro el cliente";
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
        cout << "Numero de cuenta: " << Clientes[i].get_numCuenta() << endl;
        cout << "Saldo en pesos: " << Clientes[i].get_saldoPesos() << endl;
        cout << "Saldo en dolares: " << Clientes[i].get_saldoDolares() << endl;
        cout<<"------------------------------------------------------------------"<<endl;
    }
}

int Banco::get_cantidadClientes(){
    return cantidadClientes;
}

Cliente* Banco::get_Clientes(){
    return Clientes;
}

int Banco::calcularClientes(){
    ifstream fclientes("fclientes.txt");
    fclientes.open("fclientes.txt");
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
    fclientes.close();

}
void Banco::deposito(double monto,double numero,string moneda){
   string variable=moneda;
    for (int i = 0; i <cantidadClientes; i++)
    {
        if (Clientes[i].get_numCuenta()==numero)
        {
            if (variable=="p")
            {
                Clientes[i].depositar_pesos(monto);
            }
            else if (variable=="d")
            {
                Clientes[i].depositar_dolares(monto);
            }
            
            
        }
        cout<<Clientes[i].get_saldoPesos();
    }
    
}
void Banco::extraer(double monto,double numero,string moneda){
   string variable=moneda;
    for (int i = 0; i <cantidadClientes; i++)
    {
        if (Clientes[i].get_numCuenta()==numero)
        {
            if (variable=="p")
            {
                Clientes[i].retirar_pesos(monto);
            }
            else if (variable=="d")
            {
                Clientes[i].retirar_dolares(monto);
            }
            
            
        }
        
    }
 }
