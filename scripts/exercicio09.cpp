#include <iostream> 

using namespace std;

int tamanho(const char *s)
{
    int i=0;

    while(s[i] !=0)
    {
        i++;
    }

    return i;
}

char *concatenar (const char *r, const char *s)
{
    int tamanho_r = tamanho(r);
    int tamanho_s = tamanho(s);
    int tamanho_total = tamanho_r + tamanho_s;

    char *palavrinha = new char[tamanho_total + 1];

    for (int i = 0; i < tamanho_r; i++)
    {
        palavrinha[i] = r[i];
    }

    for (int i = 0; i < tamanho_s; i++)
    {
        palavrinha[i + tamanho_r] = s[i];
    }

    palavrinha[tamanho_total] = 0;

    return palavrinha;
}

int main()
{

    const char *palavra = "o sol";
    const char *texto = " vai brilhar";

    const char *retorno = concatenar(palavra, texto);
    cout << retorno << endl;

    delete[] palavra;
    delete[] texto;
    delete[] retorno;

    return 0;
}