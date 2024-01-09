#include <iostream>
#include <vector>

using namespace std;

void ordenar(double *v, int n) // ordenar vetor
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;
        double aux;
        for (int j = i + 1; j < n; ++j)
        {
            if (v[j] < v[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            aux = v[i];
            v[i] = v[min_idx];
            v[min_idx] = aux;
        }
    }
}

int main()
{
    int n;
    //double x;

    cout << "Digite o tamanho n do vetor" << endl;
    cin >> n;

    double vetor[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Digite o valor do vetor v[" << i << "]" << endl;
        cin >> vetor[i];
    }

    ordenar(vetor, n);

    for (int i = 0; i < n; i++)
    {
        cout << vetor[i];
    }

    return 0;
}
