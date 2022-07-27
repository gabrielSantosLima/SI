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

    void imprimeListaPorGenero(){
        string* generosListados = new string[this->tamanhoTotal];
        int quantidadeGenerosListados = 0;
        for(int i = 0; i < this->tamanho; i++){
            if(foiListado(generosListados, quantidadeGenerosListados, this->lista[i].genero)) continue;
            cout << "> Listando por " << this->lista[i].genero << endl;
            for(int j = 0; j < this->tamanho; j++){
                if(this->lista[i].genero.compare(this->lista[j].genero) == 0){
                    generosListados[quantidadeGenerosListados] = this->lista[j].genero;
                    quantidadeGenerosListados++;
                    cout << this->lista[j].toString() << endl;
                }
            }
        }
    }

    bool foiListado(string* generosListados, int quantidadeGenerosListados, string genero){
        for(int index = 0; index < quantidadeGenerosListados; index++){
            if(generosListados[index].compare(genero) == 0) return true;
        }
        return false;    
    }
};

int main(){
  ListaCompras lista(10);
  ItemLista item1("Nestle", "Leite", 19.9f, 2);
  ItemLista item8("Pepsi", "Refrigerante", 20.0f, 1);
  ItemLista item2("Nescau", "Achocolatado", 20.0f, 1);
  ItemLista item3("Toddy", "Achocolatado", 20.0f, 1);
  ItemLista item4("Mococa", "Leite", 20.0f, 1);
  ItemLista item5("Bombril", "Limpeza", 20.0f, 1);
  ItemLista item9("Detergente", "Limpeza", 20.0f, 1);
  ItemLista item6("Baré", "Refrigerante", 20.0f, 1);
  ItemLista item7("Coca-Cola", "Refrigerante", 20.0f, 1);

  cout << "========== Bem vindo ==========" << endl;
  
  lista.insere(item1);
  lista.insere(item4);
  lista.insere(item3);
  lista.insere(item2);
  lista.insere(item5);
  lista.insere(item6);
  lista.insere(item7);
  lista.insere(item8);
  lista.insere(item9);

  cout << "========== Imprimindo lista completa ==========" << endl;
  lista.imprimeLista();

  cout << "========== Imprimindo lista por gênero ==========" << endl;
  lista.imprimeListaPorGenero();

  return 0;
}