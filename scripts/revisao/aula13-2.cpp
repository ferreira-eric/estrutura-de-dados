#include <iostream>
#include <new>
#include <string>

using namespace std;

class PilhaStrings
{
    int tam;            //tamnho do vetor
    string *vetor;      //ponteiro para vetor de strings
    int n;              //numero de elementos

    public :

    PilhaStrings()
    {
        tam = 1;
        vetor = new string [tam];
        n = 0;
    }

    void empilhar(string s)
    {
        if (n == tam)
        {
            tam = tam * 2;
            string *w = new string [tam];

            for(int i = 0; i < n; i++)
            {
                w[i] = vetor[i];
            }

            delete[] vetor;
            vetor = w;            
        }

        vetor[n] = s;
        ++n;
    }

    string desempilhar ()
    {
        --n;

        if (n <= tam/4 && tam > 4)
        {
            tam = tam/2;
            string *w = new string [tam];

            for(int i = 0; i < n; i++)
            {
                w[i] = vetor[i];
            }

            delete[] vetor;
            vetor = w;            
        }
        
        return vetor[n];
    }

    
    bool esta_vazia()
    {
        return n==0;
    }

    int tamanho()
    {
        return n;
    }

    string topo()
    {   
        return vetor[n-1];         
    }

    void desempilharSemRetornar ()
    {
        --n;
    }

};

double ler_expressao ()
{
    PilhaStrings pilha;
    
    while(true)
    {
        string palavra;
        cin >> palavra;

        if (palavra == "FIM") break;

        if(palavra != "(" && palavra != ")")
        {
            pilha.empilhar(palavra);
        }
        else
        {
            if(palavra == ")")
            {
                double dir = stod(pilha.desempilhar());
                string op = pilha.desempilhar();
                double esq = stod(pilha.desempilhar());

                double res;

                if      (op == "+") res = esq + dir;
                else if (op == "-") res = esq - dir;
                else if (op == "*") res = esq * dir;
                else                res = esq / dir;

                pilha.empilhar(to_string(res));
            }
        }
    }

    return stod(pilha.desempilhar());
}

int main()
{
    cout << "Digite a expressao: ";

    double resultado = ler_expressao();

    cout << "Resultado: " << resultado;

    return 0;
}
