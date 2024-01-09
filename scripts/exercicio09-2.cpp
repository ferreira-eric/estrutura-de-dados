#include <iostream>

using namespace std;


char *substring (const char *s, int ini, int fim)
{

    char *substring = new char[(fim-ini)+1];

    for(int i = 0, j = ini; i <= (fim-ini); i++, j++)
    {
        substring[i] = s[j];
    }

    substring[(fim-ini)+1] = 0;
    return substring;
}

int main()
{
    const char *texto = "parte de uma string";

    const char *texto2 = substring(texto,3,15);

    cout << texto << endl;
    cout << texto2 << endl;

    delete[] texto2;

    return 0;
}