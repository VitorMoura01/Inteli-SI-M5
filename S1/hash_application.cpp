#include <iostream>
#include "hash.h" 

using namespace std;


int main(){
  Hash clientesHash(10);
  int imeis[7]   = {
    35480918, 35480910, 35410914,
    35480912, 35480914, 35480920,
    35481913};
  string logins[7] = {
    "0x0000244500004484", "0x0000544400008424", "0x0000445400004484",
    "0x0000424400004444", "0x0000445400004445", "0x0000444400008424",
    "0x0000844400004448"}; 

  //Insere na tabela os imeis e logins
  for (int i = 0; i < 7; i++) {
    Cliente cliente = Cliente(imeis[i], logins[i]);
    clientesHash.insertItem(cliente);
  }

  /*
  CASOS DE TESTE
  */
  cout << "------------CASO 1-----------------" <<  endl;

  //Exibe a tabela construida
  clientesHash.print();  

  cout << "------------CASO 2-----------------" <<  endl;

  //Verifica se aquele Login existe na tabela hash, no caso deve
  //ter sido sobreposto por outro Login com Imei de mesmo mod
  Cliente cliente(35480910,"");  
  bool found = false;
  clientesHash.retrieveItem(cliente, found);
  cout << cliente.getLogin() << " -> " << found << endl;
  
  cout << "------------CASO 3-----------------" <<  endl;

  //Verifica o tamanho da tabela Hash, contando colisões
  cout << "tamanho: " << clientesHash.getLength() << endl;
  
  cout << "------------CASO 4-----------------" <<  endl;

  //Remove o Login que está naquela posição de Imei (35480910)
  clientesHash.deleteItem(cliente);
  clientesHash.print();
  cout << "Fim" << endl;  

  cout << "------------CASO 5-----------------" <<  endl;

  //Insere um novo cliente
  Cliente clienteNovo(35480930,"0x0000544400008424");
  clientesHash.insertItem(clienteNovo);
  clientesHash.print();  

}

