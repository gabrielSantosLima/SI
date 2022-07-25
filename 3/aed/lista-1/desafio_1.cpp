#include <iostream>

using namespace std;

void clear(){
    cout << "\x1B[2J\x1B[H";
}

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
      return to_string(this->quantidade) + " x R$" + to_string(this->precoUnitario) + " >>>>> " + this->nome + " (" + this->genero + ")" ;
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
        cout << "|" << this->lista[index].toString() << "|" << endl;
      }
      cout << "|Total a pagar: R$" << to_string(this->totalAPagar()) << "|" << endl;
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
        if(this->lista[index].precoUnitario <= preco){
          quantidadeBaratos++;
        }
      }
      ListaCompras novaLista(quantidadeBaratos);
      for(int index = 0; index < this->tamanho; index++){
        if(this->lista[index].precoUnitario <= preco){
          novaLista.insere(this->lista[index]);
        }
      }
      return novaLista;
    }

    ListaCompras agruparPorGenero(string genero){
      int quantidadeGeneros = 0;
      for(int index = 0; index < this->tamanho; index++){
        if(this->lista[index].genero == genero){
          quantidadeGeneros++;
        }
      }
      ListaCompras novaLista(quantidadeGeneros);
      for(int index = 0; index < this->tamanho; index++){
        if(this->lista[index].genero == genero){
          novaLista.insere(this->lista[index]);
        }
      }
      return novaLista;
    }
};

int main(){
    int tamanhoTotal;

    cout << "> Insira a quantidade de itens que você deseja adicionar na lista de compras: ";
    cin >> tamanhoTotal;

    ListaCompras lista(tamanhoTotal);

    for(int index = 0; index < tamanhoTotal; index++){
        cin.ignore();
        clear();

        string nome, genero;
        float precoUnitario;
        int quantidade;

        cout << "> Insira o nome do novo item " << ": ";
        getline(cin, nome);

        cout << "> Insira o gênero de " << nome << ": ";
        getline(cin, genero);

        cout << "> Insira o preço unitário de " << nome << ": ";
        cin >> precoUnitario;

        cout << "> Insira a quantidade de " << nome << ": ";
        cin >> quantidade;

        ItemLista item(nome, genero, precoUnitario, quantidade);
        lista.insere(item);
    }

    cout << "\n============= Lista Completa ============" << endl;
    lista.imprimeLista();
    cout << "=========================================" << endl;
    
    float preco = 0.0f;
    cout << "\n> Itens mais baratos que: ";
    cin >> preco;

    cout << "\n===== Itens mais baratos que " << to_string(preco) << " reais ====" << endl;
    ListaCompras listaMaisBaratos = lista.maisBaratosQue(preco);
    listaMaisBaratos.imprimeLista();
    cout << "=====================================" << endl;
    cin.ignore();

    string genero;
    cout << "\n> Insira o gênero de: "; 
    getline(cin, genero);

    cout << "\n===== Agrupar Por Gênero '"<< genero <<"' =====" << endl;
    ListaCompras listaMesmoGenero = lista.agruparPorGenero(genero);
    listaMesmoGenero.imprimeLista();
    cout << "=======================================" << endl;

    return 0;
}