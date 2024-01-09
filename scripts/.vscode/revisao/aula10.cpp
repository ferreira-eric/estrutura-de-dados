#include <iostream> 

using namespace std;

class minha_string
{

    char *s;
    int tam;

    public:

    minha_string()
    {
        tam = 1;
        s = new char [tam];
        s[0] = 0; // *s=0
    }

    void atribuir(const char *origem)
    {
        int tam_origem = 0;

        while(origem[tam_origem] != 0)
        {
           tam_origem++;
        }

        if(tam < tam_origem + 1)
        {
            delete[] s;
            tam = tam_origem + 1;
            s = new char [tam];
        }

        for(int i = 0; i <= tam_origem; i++)
        {
            s[i] = origem[i];
        }

    }

    void imprimir()
    {
        for(int i = 0; s[i]!=0; i++)
        {
        cout << s[i];
        }
    }

    char operator[] (int i)
    {
        return s[i];
    }

    ~minha_string()
    {
        delete[] s;
    }
};

int main()
{

    try
    {
        minha_string texto;

        texto.imprimir();

        texto.atribuir("Uma string qualquer...");

        texto.imprimir();

        cout << texto.operator[](2);
        
    }
    catch(const bad_alloc &e)
    {
        cout << "Erro de alocacao";
        return 1;
    }

    return 0;
}