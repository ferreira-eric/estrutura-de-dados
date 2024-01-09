#include <iostream> 

using namespace std;

int buscar(double *v, int tam, double x)
{
    int ini = 0, fim = tam-1;
    int meio;

    while(ini <= fim)
    {
        meio = ini + ((fim-ini)/2);

        if(x==v[meio]) return meio;
        else if(x < v[meio]) fim = meio-1;
        else ini = meio+1;
    }
    return -1;
}

int posicaoInserir(double *v, int tam, double x)
{
    int ini = 0, fim = tam-1;
    int meio;

    while(ini <= fim)
    {
        meio = ini + ((fim-ini)/2);

        if(x < v[meio]) fim = meio-1;
        else ini = meio+1;
    }
    return ini;
}

int main()
{
    double *v = new double [5] {1,2,4,6,7};

    cout << posicaoInserir(v,5,5);

    delete[] v;
    return 0;
}