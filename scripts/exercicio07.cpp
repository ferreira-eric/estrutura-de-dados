#include <iostream>

using namespace std;

double *soma(double *v, double *w, int n)
{
    double *z = new double[n];

    for (int i = 0; i < n; i++)
    {
        z[i] = v[i] + w[i];
    }

    return z;
}

int main()
{
    int n;
    cout << "Digite o tamanho dos vetores: ";
    cin >> n;

    double *v = new double[n];
    double *w = new double[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Digite o valor do vetor v[" << i << "]" << endl;
        cin >> v[i];
    }

    cout << "====================================" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Digite o valor do vetor w[" << i << "]" << endl;
        cin >> w[i];
    }

    double *vetorRetornado = soma(v, w, n);

    cout << "====================================" << endl;
    cout << "A soma dos vetores:" << endl;

    for (int i = 0; i < n; i++)
    {
        
        cout << vetorRetornado[i] << endl;
    }

    delete[] v;
    delete[] w;
    delete[] vetorRetornado;

    return 0;
}