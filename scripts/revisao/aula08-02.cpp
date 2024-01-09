#include <iostream>
#include <new>

using namespace std;

struct Vetor
{
    double *v;
    int tam;
    int n;

    Vetor()
    {
        tam = 1;
        n = 0;
        v = new double[tam];
    }

    ~Vetor()
    {
        delete[] v;
    }

    int buscar(int num)
    {
        for(int i = 0; i < n; i++)
        {
            if(v[i] == num)
            {
                return i;
            }
        }
        return -1;
    }

    void inserir(double num)
    {
        if(buscar(num == -1))
        {
            if(n == tam)
            {
                tam = tam * 2;
                double *vetor = new double [tam];

                for( int i = 0; i < n; i ++)
                {
                    vetor[i] = v[i];
                }
                delete[] v;
                v = vetor;
            }
            v[n] = num;
            n++;
        }
        else
        {
            cout << "Vetor Existente" << endl;
        }
    }

    void remover(double num)
    {
        if(buscar(num) != -1)
        {
            
            double *vetor = new double [tam];

            for( int i = 0, j = 0; i < n-1; i ++, j++)
            {
                if(v[i] == num)
                {
                    j++;
                }
                vetor[i] = v[j];
            }

            delete[] v;
            v = vetor;            
            n--;
        }
        else
        {
            cout << "Vetor NAO Existente" << endl;
        }
    }

    void imprimir()
    {
        for(int i = 0; i < n; i++)
        {
            cout << "v [" << i << "]:" << v[i] << endl;
        }
    }
};


int main()
{
    try
    {
        int escolha;
        double modificar;
        Vetor vet;

        while (true)
        {   
            cout << "Digite [1] para insercao e [2] para remocao (-1 para sair)" << endl;
            cin >> escolha;

            if(escolha == -1)
            {
                break;
            }
            else if(escolha == 1)
            {
                cout << "Digite o numero que vc quer inserir:";
                cin >> modificar;
                vet.inserir(modificar);
            }
            else if(escolha == 2)
            {
                cout << "Digite o numero que vc quer remover:";
                cin >> modificar;
                vet.remover(modificar);
            }
            else
            {
                cout << "Escolha inválida. Tente novamente." << endl;
            }

            vet.imprimir();
        }
    }
    catch(bad_alloc &e)
    {
       cout << "Erro de alocacao" << endl;
    }  

    return 0;
}