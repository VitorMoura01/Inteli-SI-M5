#include "hash.h" 
#include <iostream>
using namespace std;

Hash::Hash(int max) {  
  length = 0;
  max_items = max;
  structure = new Cliente[max_items];   
}

Hash::~Hash(){
  delete [] structure;
}
//retorna True se length é igual ao limite
bool Hash::isFull() const {
  return (length == max_items);
}
//retorna o length
int Hash::getLength() const {
  return length;
}

//Faz uma busca na estrutura e retorna se o elemento ja está inserido
//se estiver, ele retorna o hash do elemento
void Hash::retrieveItem(Cliente& cliente, bool& found) {
  int location = getHash(cliente);
  Cliente aux    = structure[location];
  if (cliente.getImei() != aux.getImei()) {
    found      = false;
  } else {
    found      = true;
    cliente      = aux;
  }
}

//Transforma o Imei do cliente em valor na tabela (vetor)
void Hash::insertItem(Cliente cliente) {
  int location = getHash(cliente);
  structure[location] = cliente;
  length++;
}
//Deleta o Imei do cliente da tabela
void Hash::deleteItem(Cliente cliente) {
  int location = getHash(cliente);
  structure[location] = Cliente();
  length--; 
}

//Printa a tabela hash por inteiro
void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<<
      structure[i].getImei()<<", "<<
      structure[i].getLogin()<<endl;
  }
}

//Aplica a função mod no Imei do cliente
int Hash::getHash(Cliente cliente){
  return cliente.getImei() % max_items;
}