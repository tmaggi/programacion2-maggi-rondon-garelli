#include <iostream>


class Cuenta 
{
private:
    long int numero_cuenta;
public:
    Cuenta();
    void set_numero_cuenta(int num);
    int get_numero_cuenta();
};

class CajaPesos: public Cuenta  
{
private:
    double saldo;
public:
    CajaPesos();
    void set_saldo(double num);
    double get_saldo();
};

class CajaDolares: public Cuenta  
{
private:
    double saldo;
public:
    CajaDolares();
    void set_saldo(double num);
    double get_saldo();
};


class Persona 
{
private:
    int DNI;
    std::string nombre;
    int ingreso;
public:
    Persona();
    void set_DNI(int num);
    void set_nombre(std::string arg);
    void set_ingreso(int num);
    int get_DNI();
    std::string get_nombre();
    int get_ingreso();

};



class Cliente: public Persona 
{
private:

    std::string tipoCliente;
    std::string estado;
    CajaPesos CuentaPesos;
    CajaDolares CuentaDolares;
public:
    Cliente();
    void set_tipoCliente(std::string arg);
    void set_estado(std::string arg);
    void set_CuentaPesos(CajaPesos arg);
    void set_CuentaDolares(CajaDolares arg);
    std::string get_tipoCliente();
    std::string get_estado();
    CajaPesos get_CuentaPesos();
    CajaDolares get_CuentaDolares();
};
class Empleado: public Persona 
{
private:
    int Clave;
    
public:
    Empleado();
    void set_Clave(int num);
    int get_Clave();
};


class Banco 
{
private:
    int cantidadClientes;
    Cliente *Clientes;
    int cantidadEmpleados;
    Empleado *Empleados;    
public:

};