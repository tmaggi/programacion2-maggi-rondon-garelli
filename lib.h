#include <iostream>


class CajaDeAhorro 
{
private:
    int numero_cuenta;
    double pesos;
    double dolares;
public:
    CajaDeAhorro();
    void set_numero_cuenta(int num);
    void set_pesos(double arg);
    void set_dolares(double usdt);
    double get_pesos();
    double get_dolares();
    int get_numero_cuenta();
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
    void set_ingreso(int arg);
    int get_DNI();
    std::string get_nombre();
    int get_ingreso();

};



class Cliente: public Persona 
{
private:

    std::string tipoCliente;
    CajaDeAhorro caja; 
    std::string estado;
public:
    Cliente();
    void set_tipoCliente(std::string arg);
    void set_caja(CajaDeAhorro arg);
    void set_estado(std::string arg);
    std::string get_tipoCliente();
    CajaDeAhorro get_caja();
    std::string get_estado();
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