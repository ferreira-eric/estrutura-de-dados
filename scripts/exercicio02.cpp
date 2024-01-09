#include <iostream>

using namespace std;

int main()
{
    int n, aux = 0;
    double i, soma = 0;

    cout << "Digite um numero: ";
    cin >> n;

    while (n <= 0)
    {
        cout << "Digite um numero: ";
        cin >> n;
    }

    while (aux < n)
    {
        cout << "Digite um numero racional: ";
        cin >> i;
        soma += i;
        aux++;
    }

    cout << "A media dos racionais: " << (soma/n);

    return 0;
}