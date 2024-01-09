#include <iostream>

using namespace std;

int main()
{

    int n;
    int soma = 0;

    cout << "Digite o valor de n: ";
    cin >> n;

    while (n > 0)
    {
        if (n%2 == 0)
        {
            soma += n;
        }

        cout << "Digite o proximo valor de n: ";
        cin >> n;
    }

    cout << "\nO valor da soma dos numeros pares:" << soma;

    return 0;
}