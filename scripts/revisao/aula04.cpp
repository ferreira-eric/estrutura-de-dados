#include <iostream>

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

    cout << "Digite o tamanho do vetor" << endl;
    cin >> n;
    cout << "Digite o x que voce quer encontrar" << endl;
    cin >> x;
    
    double v[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Digite o valor do v[" << i << "]: ";  
        cin >> v[i];
    }

    cout << procurar(v, n, x);

    return 0;
}