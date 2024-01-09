#include <iostream> 

using namespace std;

int tamanho(char *s)
{
    int i = 0;

    while(s[i] != 0) i++;

    return i;
}


void inverter(char *s)
{
    char aux[tamanho(s)];

    for(int i = 0; i < tamanho(s); i++)
    {
        aux[i] = s[i];
    }

    for(int i = 0, j = tamanho(s)-1; i < tamanho(s); i++, j--)
    {
        s[i] = aux[j];
    }
}

int main()
{

    char texto[] = "borboleta";

    cout << "Original: " << texto << endl;

    inverter(texto);

    cout << "Invertida: " << texto << endl;

    return 0;
}