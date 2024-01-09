#include <iostream>
#include <new>

using namespace std;

class Conjunto
{
    struct Noh
    {
        double elemento;
        Noh *esq;
        Noh *dir;
    };

    Noh *raiz;

    public:

    Conjunto()
    {
        raiz = nullptr;
    }

    void inserir(double x)
    {
        if(raiz == nullptr)
        {
            raiz = new Noh {x, nullptr, nullptr};
            return;
        }

        Noh *aux = raiz;

        while (true)
        {
            if(x == aux->elemento) return;

            if(x < aux->elemento)
            {
                if(aux->esq == nullptr)
                {
                    aux->esq = new Noh {x, nullptr, nullptr};
                    return;
                }
                else
                {
                    aux = aux->esq;
                }
            }
            else
            {
                if(aux->dir == nullptr)
                {
                    aux->dir = new Noh {x, nullptr, nullptr};
                    return;
                }
                else
                {
                    aux = aux->dir;
                }
            }
        }
    }

    bool pertence(double x)
    {
        Noh *n = raiz;

        while (n != nullptr)
        {
            if(x == n->elemento) return true;
            if(x < n->elemento)  n = n->esq;
            else                 n = n->dir;
        }
        return false;
    }

    void remover(double x)
    {
        Noh *n = raiz, *pai = nullptr;

        while (n != nullptr)
        {
            if(x == n->elemento) break;
            pai = n;
            if(x < n->elemento) n = n->esq;
            else                n = n->dir;
        }

        Noh **cima;

        if(pai == nullptr)
        {
            cima = &raiz;
        }
        else if (pai->elemento < n->elemento)
        {
            cima = &pai->dir;
        }
        else
        {
            cima = &pai->esq;
        }

        if(n->esq == nullptr or n->dir == nullptr)
        {
            Noh *filho;
            if(n->esq == nullptr) filho = n->dir;
            else               filho = n->esq;

            *cima = filho;
        }
        else
        {
            Noh *pai_pred = n;
            Noh *pred = n->esq;

            while (pred->dir != nullptr)
            {
                pai_pred = pred;
                pred = pred->dir;
            }

            if(pred == pai_pred->esq)
            {
                pai_pred->esq = pred->esq;
            }
            else
            {
                pai_pred->dir = pred->esq;
            }

            pred->esq = n->esq;
            pred->dir = n->dir;

            *cima = pred;
        }

        delete n;        
    }



};




int main()
{
    return 0;
}