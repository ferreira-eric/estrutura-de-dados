#include <iostream> 
#include <string> 
#include <vector>

using namespace std;

int main()
{
    string terminador = "FIM";
    vector<string> texto;

    while(true)
    {
        string palavra;
        cin >> palavra;

        if(palavra == terminador) break;

        texto.push_back(palavra);
    }

    cout << "As palavras digitadas foram:" << endl;

    for(string s: texto) cout << ' ' << s;
    
    return 0;
}