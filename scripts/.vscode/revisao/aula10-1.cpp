#include <iostream>
#include <new>

using namespace std;

class Matriz
{
    double *v;
    int l, c;

    public:

    Matriz(int num_linhas, int num_colunas)
    {
        v = new double [num_linhas * num_colunas];
        l = num_linhas;
        c = num_colunas;
    }

    ~Matriz()
    { 
        delete[] v;
    }

    int numLinhas()
    {
        return l;
    }

    int numColunas()
    {
        return c;
    }

    double &operator() (int linha, int coluna)
    {
        return v[linha*c + coluna];
    }

    void imprimir()
    {
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cout << ' ' << v[i*j + j];
            }           
            cout << endl;
        }
    }
};

int main()
{

    try
    {
        Matriz m(3,3);

        for(int i = 0; i < 3; i++)
        {
            for(int j=0; j < 3;  j++)
            {
                m(i,j) = 1;
            }
        }

        m.imprimir();
    }
    catch(bad_alloc &e)
    {
        cout << "Erro alocar memoria" << endl;
        return 1;
    }


    return 0;
}