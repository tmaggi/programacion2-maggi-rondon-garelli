#include <iostream>
using namespace std;




class CajaPesos
{
private:
  double saldoPesos;
public:
  CajaPesos();
  void set_saldoPesos(double num);
  double get_saldoPesos();
};

class CajaDolares
{
private:
  double saldoDolares;
public:
  CajaDolares();
  void set_saldoDolares(double num);
  double get_saldoDolares();
};

class Cuenta 
{
private:
  long int numero_cuenta;
  CajaPesos cuentaPesos;
  CajaDolares cuentaDolares;
public:
  Cuenta();
  void set_numero_cuenta(int num);
  int get_numero_cuenta();
  void transferir_pesos(Cuenta *cuenta2,double monto);
  void transferir_dolares(Cuenta *cuenta2,double monto);
  void set_Pesos(double num);
  void set_Dolares(double num);
  double get_Pesos();
  double get_Dolares();
};

class Persona 
{
private:
  int DNI;
  string nombre;
  int ingreso;
protected:
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
  void depositar_pesos(double monto);
  void depositar_dolares(double monto);
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

class Transaccion
{
private:
  int numeroCliente;
  string tipoTransaccion;
  string divisa;
  double monto;
  int dia;
  int mes;
  int anio;
public:
  Transaccion(int num,string tipo,string moneda,double cantidad,int D,int M,int A);
  void set_numeroCliente(int num);
  void set_tipoTransaccion(string tipo);
  void set_divisa(string moneda);
  void set_monto(double num);
  void set_dia(int num);
  void set_mes(int num);
  void set_anio(int num);
  int get_numeroCliente();
  string get_tipoTransaccion();
  string get_divisa();
  double get_monto();
  int get_dia();
  int get_mes();
  int get_anio();
};


class Banco 
{
private:
  Transaccion *Transacciones;
  int cantidadClientes;
  Cliente *Clientes;
  int cantidadEmpleados;
  Empleado *Empleados;    
public:

};