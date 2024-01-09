#include <iostream>

using namespace std;

int main()
{

    double x, y, x1, x2, y1, y2, base, altura;
    int aux = 1;
    
    cout << "Digite a coordenada x do ponto" << aux << ": ";
    cin >> x;
    cout << "Digite a coordenada y do ponto" << aux << ": ";
    cin >> y;

    x1 = x;
    x2 = x;
    y1 = y;
    y2 = y;

    while (aux < 5)
    {
        aux++;

        cout << "Digite a coordenada x do ponto" << aux << ": ";
        cin >> x;
        cout << "Digite a coordenada y ponto" << aux << ": ";
        cin >> y;

        x1 = min(x1, x);
        x2 = max(x2, x);
        y1 = min(y1, y);
        y2 = max(y2, y);
    }

    base = x2 - x1;
    altura = y2 - y1;

    if (base == altura)
    {
        cout << "Classificacao do retangulo: quadrado" << ": ";
    }
    else if (base > altura)
    {
        cout << "Classificacao do retangulo: largo" << ": ";
    }
    else
    {
        cout << "Classificacao do retangulo: alto" << ": ";
    }

    return 0;
}