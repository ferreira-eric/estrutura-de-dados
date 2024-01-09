#include <iostream>
#include <new>

using namespace std;

int main()
{
    try
    {
        int n = 0, tam = 1;
        double *vetor = new double[tam];

        while(true)
        {
            int num;

            cout << "Digite o valor que voce quer adicionar: (-1 para)";
            cin >> num;
            
            if(num < 0)
            {
                break;
            }
            else if(n == tam)
            {
                int novo_tam = tam * 2;

                double *wetor = new double[novo_tam];

                for(int i = 0; i < tam; i++)
                {
                    wetor[i] = vetor[i];
                }

                delete[] v;
                v = w;
                tam = novo_tam;
            }
            else if(tam/4 == n)
            {
                int novo_tam = tam / 2;

                double *wetor = new double[novo_tam];

                for(int i = 0; i < novo_tam; i++)
                {
                    wetor[i] = vetor[i];
                }

                delete[] v;
                v = w;
                tam = novo_tam;
            }

            v[n] = num;
            n++;
        }


    }
    catch(bad_alloc &e)
    {
        cout << "Erro";
    }
    







    return 0;
}