#include <iostream>
#include "hash.h" 

using namespace std;


int main(){
  Hash clientesHash(10);
   int64_t   imeis[7]   = {
    354809107284743, 354809105904102, 354809102628407,
    354809100135892, 354809100635909, 354809107992659,
    354809100814454};
  string logins[7] = {
    "0x0000244500004484", "0x0000544400008424", "0x0000445400004484",
    "0x0000424400004444", "0x0000445400004445", "0x0000444400008424",
    "0x0000844400004448"}; 

  //Insere na tabela os imeis e logins
  for (int i = 0; i < 7; i++) {
    Cliente cliente = Cliente(imeis[i], logins[i]);
    clientesHash.insertItem(cliente);
  }
  clientesHash.print();  
  cout << "------------------------------" <<  endl;
  
  Cliente cliente(12704,"");  
  bool     found = false;
  clientesHash.retrieveItem(cliente, found);
  cout << cliente.getLogin() << " -> " << found << endl;
  
  cout << "------------------------------" <<  endl;

  clientesHash.deleteItem(cliente);
  clientesHash.print();
  cout << "Fim" << endl;  
}

