#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int tam = 5;
    double v[tam];
    double desvioMedio = 0, media = 0;

    for (int i = 0; i < tam; i++)
    {
        cout << "Digite o valor do vetor[" << i << "]:";
        cin >> v[i];

        media += v[i];
    }

    media = media/tam;

    for (int i = 0; i < tam; i++)
    {
        desvioMedio += abs(v[i] - media);
    }

    desvioMedio = desvioMedio/tam;
    
    cout << "O desvio medio eh:" << desvioMedio;

    return 0;
}