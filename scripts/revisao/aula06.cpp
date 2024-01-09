#include <iostream>
#include <new>

using namespace std;

double *soma(double *v, double *w, int n)
{
    double *s = new double[n];

    for(int i = 0; i < n; i++)
    {
        s[i] = v[i] + w[i];
    }
   
    return s;
}

int main()
{

    int tam;

    cout << "Digite o tamanho dos vetores:";
    cin >> tam;

    try
    {
        double *v = new double[tam];
        double *w = new double[tam];
        double *s = new double[tam];

        for(int i = 0; i < tam; i++)
        {
            cout << "Digite o v[" << i << "]:";
            cin >> v[i];
            cout << "Digite o w[" << i << "]:";
            cin >> w[i];
        }

        s = soma(v,w,tam);

        for(int i = 0; i < tam; i++)
        {
            cout << "soma[" << i << "]:" << s[i] << endl;
        }

        delete[] s;
        delete[] v;
        delete[] w;

    }
    catch (bad_alloc &e)
    {
        cout << "Falha de alocacao" << endl;
    }

    return 0;
}