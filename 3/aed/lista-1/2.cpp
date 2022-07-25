#include <iostream>

using namespace std;

class ItemLista{
  public:
    string nome;
    string genero;
    float precoUnitario;
    int quantidade;

    ItemLista(){
    }

    ItemLista(string nome, string genero, float precoUnitario, int quantidade){
      this->nome = nome;
      this->genero = genero;
      this->precoUnitario = precoUnitario;
      this->quantidade = quantidade;
    }

    string toString(){
      return to_string(this->quantidade) + " x R$" + to_string(this->precoUnitario) + " -------------------------- " + this->nome ;
    }
};

class ListaCompras{
  public:
    int tamanho;
    int tamanhoTotal;
    ItemLista* lista;

    ListaCompras(int tamanhoTotal){
      this->tamanhoTotal = tamanhoTotal;
      this->criarLista();
    }

    void criarLista(){
      this->lista = new ItemLista[tamanhoTotal];
      this->tamanho = 0;
    }

    bool vazia(){
      return this->tamanho == 0;
    }

    bool cheia(){
      return this->tamanho == this->tamanhoTotal;
    }

    bool insere(ItemLista item){
      if(this->cheia()) return false;
      this->lista[this->tamanho] = item;
      this->tamanho++;
      return true;
    }

    bool retira(){
      if(this->vazia()) return false;
      this->tamanho--;
      return true;
    }

    void imprimeLista(){
      for(int index = 0; index < this->tamanho; index++){
        cout << this->lista[index].toString() << endl;
      }
    }
};

int main(){
  ListaCompras lista(10);
  ItemLista item1("Item1", "Genero1", 19.9f, 2);
  ItemLista item2("Item2", "Genero2", 12.0f, 3);
  ItemLista item3("Item3", "Genero3", 23.0f, 4);
  ItemLista item4("Item4", "Genero4", 7.0f, 5);
  ItemLista item5("Item5", "Genero5", 1.0f, 6);
  ItemLista item6("Item6", "Genero6", 2.0f, 7);

  lista.insere(item1);
  lista.insere(item2);
  lista.insere(item3);
  lista.insere(item4);
  lista.insere(item5);
  lista.insere(item6);
  lista.imprimeLista();
  return 0;
}