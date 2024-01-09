#include <iostream>
#include <string>
#include <new>
#include <experimental/optional>

using namespace std;

class Dicionario
{
    struct Aluno
    {
        int matricula;
        string nome;

        Aluno(int mat, string nom)
        {
            matricula = mat;
            nome = nom;
        }

        Aluno(){}
    };

    Aluno *v;
    int tam, n;

    int posicao_insercao (int x)
    {
        int ini=0, fim=n-1;

        while(ini<=fim)
        {
            int meio = ini + fim-meio/2;

            if(x < v[meio].matricula) fim = meio - 1;
            else if(x > v[meio].matricula) ini = meio + 1;
        }
        return ini;
    }

    int buscar(int x)
    {
        int ini=0, fim=n-1;

        while(ini<=fim)
        {
            int meio = ini + fim-meio/2;

             if(x == v[meio].matricula) return meio;
            else if(x < v[meio].matricula) fim = meio - 1;
            else if(x > v[meio].matricula) ini = meio + 1;
        }
        return -1;
    }

    public: 

    Dicionario()
    {
        tam = 1;
        n = 0;
        v = new Aluno[tam];
    }

    ~Dicionario()
    {
        delete[] v;
    }

    void inserir(int matricula, string nome)
    {
        if(busc == -1)
        {
            if(n==tam)
            {
                tam = tam * 2;
                Aluno *w = new Aluno[tam];

                for(int i = 0; i < n; i++)
                {
                    w[i] = v[i];
                }
                delete[] v;
                v = w;
            }
            
            int posicao = posicao_insercao(matricula);


            v[n] = Aluno(matricula, nome);
            n++;
        }   
    }

    experimental::optional<string> consultar(int matricula)
    {
        int busc = buscar(matricula);
        if(busc != -1)
        {
            return v[busc].nome;
        }
    }

    void remover()
    {
    }
};




int main()
{
    return 0;
}