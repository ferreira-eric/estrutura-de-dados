#include <iostream>

using namespace std;

void inverterVetor(double *v, int n)
{
    double vetor[n];

    for (int i = 0; i < n; i++)
    {
        vetor[i] = v[i];
    }

    for (int i = 0, j = (n-1); i < n; i++, j--)
    {
        v[i] = vetor[j];
    }
}

int main()
{
    int tam = 7;
    double vetor[tam];

    
    for (int i = 0; i < tam; i++)
    {
        cout << "Digite o valor de vetor[" << i << "]:";
        cin >> vetor[i];
    }

    inverterVetor(vetor, tam);

    for (int i = 0; i < tam; i++)
    {
        cout << "valor de vetor[" << i << "]:" <<vetor[i] << endl;
    }

    return 0;
}