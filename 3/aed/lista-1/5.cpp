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
      cout << "Total a pagar: R$" << to_string(this->totalAPagar()) << endl;
    }

    float totalAPagar(){
      float total = 0.0f;
      for(int index = 0; index < this->tamanho; index++){
        total += this->lista[index].precoUnitario * this->lista[index].quantidade;
      }
      return total;
    }

    ListaCompras maisBaratosQue(float preco){
      int quantidadeBaratos = 0;
      for(int index = 0; index < this->tamanho; index++){
        if(this->lista[index].precoUnitario < preco){
          quantidadeBaratos++;
        }
      }
      ListaCompras novaLista(quantidadeBaratos);
      for(int index = 0; index < this->tamanho; index++){
        if(this->lista[index].precoUnitario < preco){
          novaLista.insere(this->lista[index]);
        }
      }
      return novaLista;
    }
};

int main(){
  ListaCompras lista(10);
  ItemLista item1("Nestle", "Leite", 19.9f, 2);
  ItemLista item2("Nescau", "Achocolatado", 20.0f, 1);
  ItemLista item3("Bombril", "Plalha de Aço", 3.0f, 3);
  ItemLista item4("Vela de aniversário", "Vela", 2.0f, 3);
  ItemLista item5("Maçã", "Frutas/Verduras", 1.0f, 3);

  lista.insere(item1);
  lista.insere(item2);
  lista.insere(item3);
  lista.insere(item4);
  lista.insere(item5);
  lista.imprimeLista();

  cout << "Mais baratos que 3 reais" << endl;
  ListaCompras listaMaisBaratos = lista.maisBaratosQue(3);
  listaMaisBaratos.imprimeLista();
  return 0;
}