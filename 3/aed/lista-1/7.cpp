#include <iostream>

using namespace std;

class ItemLista
{
public:
  string nome;
  string genero;
  float precoUnitario;
  int quantidade;

  ItemLista()
  {
  }

  ItemLista(string nome, string genero, float precoUnitario, int quantidade)
  {
    this->nome = nome;
    this->genero = genero;
    this->precoUnitario = precoUnitario;
    this->quantidade = quantidade;
  }

  string toString()
  {
    return to_string(this->quantidade) + " x R$" + to_string(this->precoUnitario) + " -------------------------- " + this->nome;
  }
};

class ListaCompras
{
public:
  int tamanho;
  int tamanhoTotal;
  string genero;
  ItemLista *lista;

  ListaCompras()
  {
    this->tamanho = 0;
  }

  ListaCompras(int tamanhoTotal, string genero)
  {
    this->tamanhoTotal = tamanhoTotal;
    this->genero = genero;
    this->criarLista();
  }

  void criarLista()
  {
    this->lista = new ItemLista[tamanhoTotal];
    this->tamanho = 0;
  }

  bool vazia()
  {
    return this->tamanho == 0;
  }

  bool cheia()
  {
    return this->tamanho == this->tamanhoTotal;
  }

  bool insere(ItemLista item)
  {
    if (this->cheia())
      return false;
    this->lista[this->tamanho] = item;
    this->tamanho++;
    return true;
  }

  bool retira()
  {
    if (this->vazia())
      return false;
    this->tamanho--;
    return true;
  }

  void imprimeLista()
  {
    cout << "===== " << this->genero << " =====" << endl;
    for (int index = 0; index < this->tamanho; index++)
    {
      cout << this->lista[index].toString() << endl;
    }
  }
};

int main()
{
  int tamanhoTotal;

  cout << "Insira a quantidade de itens que você deseja adicionar na lista de compras: ";
  cin >> tamanhoTotal;

  ListaCompras lista(tamanhoTotal, "Geral");

  for (int index = 0; index < tamanhoTotal; index++)
  {
    cin.ignore();
    string nome, genero;
    float precoUnitario;
    int quantidade;

    cout << "Insira o nome do novo item "
         << ": ";
    getline(cin, nome);

    cout << "Insira o gênero de " << nome << ": ";
    getline(cin, genero);

    cout << "Insira o preço unitário de " << nome << ": ";
    cin >> precoUnitario;

    cout << "Insira a quantidade de " << nome << ": ";
    cin >> quantidade;

    ItemLista item(nome, genero, precoUnitario, quantidade);
    lista.insere(item);
  }

  ListaCompras *listasPorGenero = new ListaCompras[tamanhoTotal];

  for (int index = 0; index < lista.tamanho; index++)
  {
    ItemLista item = lista.lista[index];
    bool temGenero = false;
    for (int genderIndex = 0; genderIndex < tamanhoTotal; genderIndex++)
    {
      ListaCompras listaPorGenero = listasPorGenero[genderIndex];
      if (item.genero.compare(listaPorGenero.genero) == 0)
      {
        listaPorGenero.insere(item);
        temGenero = true;
      }
    }

    if (!temGenero)
    {
      for (int genderIndex = 0; genderIndex < tamanhoTotal; genderIndex++)
      {
        ListaCompras *listaPorGenero = &listasPorGenero[genderIndex];
        if (listaPorGenero->genero.size() == 0)
        {
          listaPorGenero = new ListaCompras(tamanhoTotal, item.genero);
          listaPorGenero->insere(item);
          break;
        }
      }
    }
  }

  for (int genderIndex = 0; genderIndex < tamanhoTotal; genderIndex++)
  {
    ListaCompras *listaPorGenero = &listasPorGenero[genderIndex];
    if (listaPorGenero->genero.size() != 0)
    {
      listaPorGenero->imprimeLista();
    }
  }
  return 0;
}