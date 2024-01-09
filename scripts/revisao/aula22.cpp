#include <iostream>
#include <string> 
#include <new>

using namespace std;

class DicioTD
{
    struct Noh
    {
        int chave;
        string valor;
        Noh *prox;
    };

    int tam, n; //tamanho da tabela (vetor), quantidade de elementos armazenados
    Noh **T;

    int hash (int chave)
    {
        return chave % tam;
    }
    
    void redimensionar(int novo_tam)
    {
        Noh **U = new Noh* [novo_tam];

        for(int i = 0; i < novo_tam; i++) U[i] = nullptr;

        int tam_anterior = tam; tam = novo_tam;

        for(int i = 0; i < tam_anterior; i++)
        {
            Noh *noh = T[i];

            while( noh != nullptr)
            {
                int j = hash(noh->chave);
                Noh *inicio = U[j];
                U[j] = noh;
                Noh *proximo = noh->prox;
                U[j]->prox = inicio; //noh->prox = inicio;
                noh = proximo;                
            }
        }

        delete T; T = U;
    }

    public: 

    string* consultar(int chave)
    {
        for(Noh *aux = T[hash(chave)]; aux != nullptr; aux = aux->prox)
        {
            if(chave == aux->chave) return &(aux->valor);
        }
        return nullptr;
    }

    DicioTD()
    {
        tam = 1;
        n = 0;
        T = new Noh* [n];
        T[0] = nullptr;
    }

    ~DicioTD()
    {
        for(int i=0; i < tam; ++i)
        {
            while(true)
            {
                Noh *noh = T[i];

                if(noh== nullptr) break;
                T[i] = noh->prox;
                delete noh;
            }
        }
    }

    void inserir(int chave, string valor)
    {
        if(consultar(chave) != nullptr) return; 

        if(n == tam) redimensionar(tam*2);
        
        int i = hash(chave);

        Noh *aux = new Noh;
        aux->chave = chave;
        aux->valor = valor;
        aux->prox = T[i];

        T[i] = aux;
    }

    void remover (int chave)
    {
        int i = hash(chave);

        if (T[i] == nullptr) return;

        if(T[i]->chave == chave)
        {
            Noh *aux = T[i];
            T[i] = T[i]->prox;
            delete aux;
        }
        else
        {
            Noh *anterior = T[i];

            while (true)
            {
                Noh *aux = anterior->prox;

                if(aux == nullptr) return;
                else if(aux->chave == chave)
                {
                    anterior->prox = aux->prox;
                    delete aux; 
                    return;
                }
                anterior = aux;
            }
        }
    }
};

int main()
{

    try
    {
       DicioTD dicionario;
    }
    catch(bad_alloc &e)
    {
        cout << "Erro de alocao de memoria";
    }
    
    return 0;
}