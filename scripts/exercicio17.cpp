#include <iostream>
#include <new>

using namespace std;

class Conjunto
{
    int tam, n;
    double *v;

    int posicao(double x)
    {
        for(int i = 0; i < n; i++)
        {
            if(v[i]==x) return i;
        }

        return -1;
    }

    public:

    Conjunto()
    {
        tam = 1;
        n = 0;
        v = new double[tam];
    }

    ~Conjunto()
    {
        delete[] v;
    }

    bool pertence(double x)
    {
        for(int i = 0; i < n; i++)
        {
            if(v[i]==x) return true;
        }

        return false;
    }

    
    void inserir(double x)
    {
        if(n == tam)
        {
            tam = tam * 2;
            double *w = new double[tam];
            
            for(int i = 0; i < n; i++)
            {
                w[i] = v[i];
            }

            delete[] v;
            v = w;
        }
    
        v[n] = x;
        ++n;
    }

    void inserirVerificando(double x)
    {
        if(!pertence(x))
        {
            inserir(x);
        }
    }

    void remover(double x)
    {
        int indice = posicao(x);

        if(indice == -1) return;

        v[indice] = v[n-1];

        --n;
    }  


    void imprimir()
    {
        for(int i = 0; i < n; i++)
        {
            cout << v[i] << "\n";
        }
    }

};

int main()
{
    try
    {
        Conjunto conjunto;

        conjunto.inserir(1);
        conjunto.inserir(2);
        conjunto.inserir(3);
        conjunto.inserir(4);

        conjunto.imprimir();

        conjunto.remover(1);

        conjunto.imprimir();
    }
    catch(bad_alloc &e)
    {
        cout << "erro de alocacao";
    }
    
    return 0;
}