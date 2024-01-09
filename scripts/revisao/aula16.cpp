#include <iostream>
#include <new>

using namespace std;

class erroFila
{
    const char *msg;

    public :

    erroFila(const char *mensagem)
    {
        msg = mensagem;
    }

    const char *mensagem() const 
    {
        return msg;
    }
};

class Fila
{
    int tam, prim, ult;
    double *v;

    void avancar(int &indice)
    {
        if(indice == tam-1)
        {
            indice = 0;
        }
        else
        {
            ++indice;
        }
    }
      
    public:

    Fila()
    {
        tam = 1;
        prim = -1;
        v = new double[tam];
    }

    bool vazia()
    {
        return (prim == -1);
    }

    // [ 0 ult 0 0 prim 0]


    int tamanho()
    {
        if(vazia())
        {
            return 0;
        }
        else if(ult >= prim)
        {
            return (ult - prim + 1);
        }
        else
        {
            return (ult+1)+(prim-tam+1);
        }
    }

    double desenfilar()
    {
        if(vazia())
        {
            throw erroFila { "Fila vazia"};
        }

        double primeiro = v[prim];

        if(prim == ult){ 
            prim = -1;
        }
        else
        {
            avancar(prim);
        }
                 
        return primeiro;
    }

    void enfilar(double elemento)
    {
        if(vazia())
        {
            prim = 0;
            ult = 0;
        }
        else  
        {
            if((prim == 0 && ult == tam-1) || (ult+1 == prim))
            {
                int novo_tam = tam * 2;

                double *w = new double[novo_tam];

                for(int i = 0, j = prim; i < tamanho(); ++i, avancar(j))
                {
                    w[i] = v[j];
                }

                delete[] v;
                v = w;
                prim = 0;
                ult = tam - 1;
                tam = novo_tam;
            }
            avancar(ult);
        }

        v[ult] = elemento;
    }

    double primeiro()
    {
        if(vazia())
        {
            throw erroFila { "Fila vazia"};
        }

        return v[prim];
    }

    ~Fila()
    {
        delete[] v;
    }
};

int main()
{
    try
    {
        cout << "inic" << endl;

        Fila fila;

        cout << "inicializei" << endl;

        fila.enfilar(10);
        fila.enfilar(11);
        fila.enfilar(12);
        fila.enfilar(13);
        fila.enfilar(10);
        fila.enfilar(11);
        fila.enfilar(12);
        fila.enfilar(13);
        fila.enfilar(10);
        fila.enfilar(11);
        fila.enfilar(12);
        fila.enfilar(13);

        cout << "enfilei" << endl;

        cout << "Desenfilar : " << fila.desenfilar() << "\n";
        cout << "Desenfilar : " << fila.desenfilar() << "\n";
        cout << "Desenfilar : " << fila.desenfilar() << "\n";
        cout << "Desenfilar : " << fila.desenfilar() << "\n";
    }
    catch(const bad_alloc &e)
    {
        cout << "Erro ao alocar";
    }
    catch(const erroFila &e)
    {
       cout << e.mensagem();
    }

    return 0;
}