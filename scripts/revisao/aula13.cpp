#include <iostream>
#include <stack>
#include <string>

using namespace std;

double ler_expressao ()
{
    stack<string> pilha;

    while(true)
    {
        string palavra;
        cin >> palavra;

        if (palavra == "FIM") break;

        if(palavra != "(" && palavra != ")")
        {
            pilha.push(palavra);
        }
        else
        {
            if(palavra == ")")
            {
                double dir = stod(pilha.top());
                pilha.pop();

                string op = pilha.top();
                pilha.pop();

                double esq = stod(pilha.top());
                pilha.pop();

                double res;

                if      (op == "+") res = esq + dir;
                else if (op == "-") res = esq - dir;
                else if (op == "*") res = esq * dir;
                else                res = esq / dir;

                pilha.push(to_string(res));
            }
        }
    }

    return stod(pilha.top());
}

int main()
{
    cout << "Digite a expressao: ";

    double resultado = ler_expressao();

    cout << "Resultado: " << resultado;

    return 0;
}