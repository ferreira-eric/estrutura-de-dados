#include <iostream>
#include <new>

using namespace std;

class Fila
{
    struct Noh
    {
        double elemento;
        Noh *prox;
    };

    Noh *ini, *fim;

    public:

    Fila()
    {
        ini = nullptr; fim = nullptr;
    }

    ~Fila()
    {
        while (!vazia())
        {
            Noh *aux = ini;
            ini = ini->prox;
            delete aux;
        }
        
    }

    bool vazia()
    {
        return ini == nullptr;
    }

    double consultar_primeiro()
    {
        return ini->elemento;
    }

    double desenfilar()
    {
        Noh *aux = ini;

        double elemento = ini->elemento;
        ini = ini->prox;

        delete aux;
        return elemento;
    }

    void enfilar(double elemento)
    {
        Noh *aux = new Noh {elemento, nullptr};

        if(vazia())
        {
            ini = aux;
            fim = aux;
        }
        else
        {
            fim->prox = aux;
            fim = aux;
        }
    }
};


int main()
{
    return 0;
}