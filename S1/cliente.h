#include <iostream>
using namespace std;

//Aqui é definida a classe cliente com os atributos imei e login
class Cliente {
private:
  int imei;
  std::string login;

public:
  Cliente();
  Cliente(int imei, std::string login);
  string getLogin() const;
  int getImei() const;
};