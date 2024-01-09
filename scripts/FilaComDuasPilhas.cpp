#include <iostream>
#include <new>

using namespace std;


class Pilha
{
    int tam, n;
    double *v;

    public:

    Pilha()
    {
        tam = 1;
        n = 0;
        v = new double[tam];
    }
    
    ~Pilha()
    {
        delete[] v;
    }

    bool vazia()
    {
        return n==0;
    }

    void empilhar(double x)
    {
        if(n==tam)
        {
            tam = tam * 2;
            double *w = new double [tam];

            for(int i=0; i < n; i++)
            {
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
        v[n] = x;
        ++n;
    }

    double desempilhar()
    {   
        --n;

        if (n <= tam/4 && tam > 4)
        {
            tam = tam/2;
            double *w = new double [tam];

            for(int i = 0; i < n; i++)
            {
                w[i] = v[i];
            }

            delete[] v;
            v = w;            
        }

        return v[n];
    }   

    int tamanho()
    {
        return n;
    }

    double topo()
    {
        return v[n-1];
    }
};

class Fila
{
    Pilha normal;
    Pilha invertida;
    int n;

    public:

    Fila()
    {
        n = 0;
    }

    bool vazia()
    {
        return n == 0;
    }

    void enfilar(double x)
    {
        if(!invertida.vazia())
        {
            for(int i = 0; !invertida.vazia(); i++)
            {
                normal.empilhar(invertida.desempilhar());
            }
        } 
        normal.empilhar(x);
    }

    double desenfilar()
    {
        if(invertida.vazia())
        {
            invertida.empilhar(normal.desempilhar());
        }
        return invertida.desempilhar();
    }

    double primeiro()
    {
        if(invertida.vazia())
        {
            invertida.empilhar(normal.desempilhar());
        }
        return invertida.topo();
    }
};

int main()
{
    return 0;
}