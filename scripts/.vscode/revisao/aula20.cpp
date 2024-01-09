#include <iostream>
#include <new>
#include <string>

using namespace std;

class Pilha
{
    struct Noh
    {
        string elemento;
        Noh *prox;
    };

    Noh *topo;

    public:

    Pilha()
    {
        topo = nullptr;
    }

    ~Pilha() 
    {
      while (!vazia())
      {
        Noh *aux = topo;
        topo = topo->prox;
        delete aux;
      }        
    }

    bool vazia() 
    {
        return topo == nullptr;
    }

    string consultar_topo()
    {
        return topo->elemento;
    }
    
    string desempilhar()
    {
        string elemento = topo->elemento;
        Noh *aux = topo;
        topo = topo->prox;
        delete aux;
        return elemento;
    }

    void empilhar(string elemento)
    {
        Noh *aux = new Noh;

        aux->prox = topo;
        aux->elemento = elemento;
        topo = aux;
    }
};

int main()
{

    return 0;
}