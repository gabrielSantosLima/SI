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
  ItemLista item1("Nestle", "Leite", 19.9f, 2);
  ItemLista item2("Nescau", "Achocolatado", 20.0f, 1);

  cout << "========== Bem vindo ==========" << endl;
  
  lista.insere(item1);
  lista.insere(item2);
  lista.imprimeLista();
  cout << "Removendo..." << endl;
  lista.retira();
  lista.imprimeLista();

  return 0;
}