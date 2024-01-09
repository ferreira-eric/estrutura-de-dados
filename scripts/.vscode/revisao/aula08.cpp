#include <iostream>

using namespace std;

struct Vetor
{
    double *v;
    int tam;
    int n;

    Vetor()
    {
        tam = 1;
        n = 0;
        v = new double[tam];
    }

    ~Vetor()
    {
        delete[] v;
    }

    void inserir (double num)
    {
        if(n == tam)
        {
            tam = tam * 2;
            double *wetor = new double[tam];

            for(int i = 0; i < n; i++)
            {
                wetor[i]=v[i];
            }

            delete[] v;
            v = wetor;
        }
        v[n]=num;
        n++;        
    }

    void imprimir ()
    {
        for(int i = 0; i < n; i++)
        {
            cout << "v[" << i << "]:" << v[i] << endl;
        }
    }

    int buscar (double num)
    {
        for(int i = 0; i < n; i++)
        {
            if(v[i] == num)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{

    try
    {
       
        Vetor vet;
        double num;

        while(true)
        {
            cout << "Digite o valor que vc quer armazenar (-1 para):";
            cin >> num;

            if(num < 0)
            {
                break;
            }

            vet.inserir(num);
        }

        vet.imprimir();
        cout << vet.buscar(3);
    }
    catch(bad_alloc &e)
    {
       cout << "Erro de alocacao" << endl;
    }

    return 0;
}