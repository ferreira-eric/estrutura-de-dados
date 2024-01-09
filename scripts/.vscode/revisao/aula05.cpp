#include <iostream>
#include <new>

using namespace std;

int main()
{

    try
    {
        int n = 0;
        int tam = 1;
        double *v = new double[tam];

        while (true)
        {
            int num;

            cout << "Digite um natural (< 0 para encerrar): ";
            cin >> num;

            if (num < 0)
            {
                break;
            }

            if (n == tam)
            {
                int novo_tam = tam + 1;
                double *w = new double[novo_tam];

                for (int i = 0; i < tam; i++)
                {
                    w[i] = v[i];
                }

                delete[] v;
                v = w;
                tam = novo_tam;
            }

            v[n] = num;
            n++;
        }

        for (int i = 0; i < tam; i++)
        {
            cout << "v[" << i << "]:" << v[i] << endl;
        }

        delete[] v;
    }
    catch (bad_alloc &e)
    {
        cout << "erro";
    }

    return 0;
}