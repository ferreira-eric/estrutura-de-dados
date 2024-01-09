#include <iostream>

using namespace std;

int main()
{

    int i;

    cout << "Digite um inteiro: ";
    cin >> i;

    if (cin.fail())
    {
        cout << "Erro durante leitura" << endl;
        return 1;
    }

    return 0;
}