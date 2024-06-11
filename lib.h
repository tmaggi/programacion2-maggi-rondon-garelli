#include <iostream>
using namespace std;






class Cuenta 
{
private:
  long int numero_cuenta;
  double saldoPesos;
  double saldoDolares;
public:
  Cuenta();
  void set_numero_cuenta(int num);
  int get_numero_cuenta();
  void set_saldoPesos(double num);
  double get_saldoPesos();
  void set_saldoDolares(double num);
  double get_saldoDolares(); 
};

class Persona 
{
protected:
  int DNI;
  string nombre;
  int ingreso;
public:
  Persona();
  void set_DNI(int num);
  void set_nombre(std::string arg);
  void set_ingreso(int num);
  int get_DNI();
  string get_nombre();
  int get_ingreso();

};


class Cliente: public Persona 
{
private:

  string tipoCliente;
  string estado;
  Cuenta cuenta;
public:
  Cliente();
  void set_tipoCliente(string tipo);
  void set_estado(string est);
  string get_tipoCliente();
  string get_estado();
  void depositar_dolares(double monto);
  void depositar_pesos(double monto);
  void retirar_pesos(double monto);
  void retirar_dolares(double monto);
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
  Banco(int cantC,int cantE);
  void cargaclientes();
};

class sistema{
  private:
    int ano,mes,dia;
  public:
    sistema();
    void guardartransaccion(double num,int numcuenta,char divisa);
};