#include "cliente.h"

//Aqui é definida a classe hash
class Hash {
 public:
  Hash(int max_items = 100);//limite default do hash
  ~Hash();
  bool isFull() const;//retorna True se length é igual ao limite
  int getLength() const;//retorna o length
  
  void retrieveItem(Cliente& cliente, bool& found);   
  void insertItem(Cliente cliente); 
  void deleteItem(Cliente cliente);  
  void print();
 private:
  int getHash(Cliente cliente);
  int   max_items;
  int   length;
  Cliente* structure;
};