#include <iostream>
using namespace std;






class Cuenta 
{
private:
  long int numero_cuenta;
  double saldoPesos;
  double saldoDolares;
  int limite;
public:
  Cuenta();
  void set_numero_cuenta(int num);
  int get_numero_cuenta();
  void set_saldoPesos(double num);
  double get_saldoPesos();
  void set_saldoDolares(double num);
  double get_saldoDolares(); 
  void set_limite(int num);
  int get_limite();
  void gastarlimite(long double);
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
  string estado;
  string nivel;
  Cuenta cuenta;
public:
  Cliente();
  void set_estado(string est);
  string get_estado();
  void depositar_dolares(double monto);
  void depositar_pesos(double monto);
  void retirar_pesos(double monto);
  void retirar_dolares(double monto);
  int get_numCuenta();
  long double get_saldoPesos();
  long double get_saldoDolares();
  void set_nivel(string niv);
  string get_nivel();
  void set_numcuenta(int numero_cuenta);
  void set_saldo_Pesos(int n);
  void set_saldoDolares(int n);
  void gastarlimite(double num);
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
  int calcularClientes();
public:
  Banco();
  Banco(int cantidadClientes);
  void cargaclientes();
  void listadoClientes();
  void detalleCliente(int numCuenta);
  int get_cantidadClientes();
  Cliente* get_Clientes();
  void deposito(double monto,double numero,char moneda);
  void extraer(double monto,double numero,char moneda);
  void agregarCliente(string nom,int dni,string lvl);
  void credito(int numC,double monto);
};

class sistema{
  private:
    int anio,mes,dia;
    void setearfecha();
  public:
    sistema();
    void guardartransaccion(double num,int numcuenta,char divisa);
    void transaccionPorCliente(int numcuenta);
    void transaccionPorMes(int M);
    void transaccionPorAnio(int A);
    void mostrarTransacciones();
    void guardarClientes(Banco *ucc);
};