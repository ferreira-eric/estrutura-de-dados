#include <iostream>
#include <vector>

using namespace std;

int procurar(double *v, int n, double x)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    double x;    

    cout << "Digite o tamanho n do vetor" << endl;
    cin >> n;
    cout << "Digite um numero x que queira procurar" << endl;
    cin >> x;

    double vetor[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Digite o valor do vetor v[" << i << "]" << endl;
        cin >> vetor[i];
    }

    cout << procurar(vetor, n, x);
    
    return 0;
}

