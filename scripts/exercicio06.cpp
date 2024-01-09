#include <iostream>

using namespace std;

int main()
{

    int n;

    cout << "Digite o tamanho n do vetor" << endl;
    cin >> n;

    double *vetor = new double[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Digite o valor do vetor v[" << i << "]" << endl;
        cin >> vetor[i];
    }
    
    cout << "====================================";

    for (int i = n-1; i >= 0; i--)
    {
        
        cout << vetor[i] << endl;
    }

    delete[] vetor;

    return 0;
}