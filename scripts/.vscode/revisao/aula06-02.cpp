#include <iostream>
#include <new>

using namespace std;

int buscar(double *v, int tam, double x)
{
    for(int i = 0; i < tam; i++)
    {
        if( v[i] == x)
        {
            return i;
        }
    }

    return -1;
}

void inserir(double *&v, int &tam, double x)
{
    int tam_aux =  tam - 1;
    if(tam == 1)
    {
        v = new double[1];
        v[0] = x;
        tam++;     
    }
    else if(buscar(v, tam_aux, x) == -1)
    {
        double *w = new double[tam_aux+1];

        for(int i = 0; i < tam_aux; i++)
        {
            w[i] = v[i];
        }

        w[tam_aux] = x;
        delete[] v;
        v = w;
        tam++;
    }
    else
    {
        cout << "O elemento esta no ja esta no vetor" << endl;
    }
}

void remover(double *&v, int &tam, double x)
{
    int posicao = buscar(v, tam, x);
    int tam_aux =  tam - 1;

    if( posicao != -1)
    {
        double *w = new double[tam_aux-1];

        for(int i = 0, j = 0; i < (tam_aux-1); i++, j++){

            if(posicao == j){
                j++;
            }
            w[i] = v[j];
        }

        delete[] v;
        v = w;
        tam--;
    }
    else
    {
        cout << "O elemento nao esta no vetor" << endl;
    }
}


int main()
{
    int escolha, tam = 1;
    double modificar;
    double *v = new double[tam];

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
        inserir(v, tam, modificar);
    }
    else if(escolha == 2)
    {
        cout << "Digite o numero que vc quer remover:";
        cin >> modificar;
        remover(v, tam, modificar);
    }
    else
    {
        cout << "Escolha inválida. Tente novamente." << endl;
    }
    
    cout << "========================================" << endl;

    for(int i = 0; i < tam-1; i++)
    {
        cout << "v[" << i << "]=" << v[i] << endl;
    }
    }

    delete[] v;

    return 0;
}