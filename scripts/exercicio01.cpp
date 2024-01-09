#include <iostream>

using namespace std;

int main()
{
    int i;
    int soma = 0;

    cout << "Digite um numero: ";
    cin >> i;

    while (i >= 0)
    {
        if (i % 2 == 0)
        {
            soma += i;
        }
        cout << "Digite outro numero: ";
        cin >> i;
    }

    cout << "A soma dos numeros pares eh: " << soma << endl;

    return 0;
}
