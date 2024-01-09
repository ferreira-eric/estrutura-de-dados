#include <iostream>
#include <new>

using namespace std;

struct aluno
{
    int matricula;
    double media;

};

int findMatricula (aluno *v, int tam, int matricula)
{
    for(int i = 0; i < tam; i++)
    {
        if(v[i].matricula == matricula)
        {
            return i;
        }
    }
    return -1;    
}

int getMediaByMatricula(aluno *v, int tam, int matricula)
{
    int posicao = findMatricula(v, tam, matricula);
    
    if( posicao != -1)
    {
        return v[posicao].media;
    }
    else
    {
        cout << "Aluno nao encontrado" << endl;
        return -1;
    }
}

void trocarMedia (aluno *v, int tam, int matricula, int media)
{
    int posicao = findMatricula(v, tam, matricula);
    
    if( posicao != -1)
    {
        v[posicao].media = media;
    }
    else
    {
        cout << "Aluno nao encontrado";
    }
}

void inserirAluno (aluno *&v, int &tam, int matricula, int media)
{
    int posicao = findMatricula(v, tam, matricula);
    
    if(tam == 1)
    {
        v[0].matricula = matricula;
        v[0].media = media;
        tam++;
    }
    else if( posicao == -1)
    {   
        int tam_aux = tam-1;

        aluno *w = new aluno[tam_aux+1];

        for(int i = 0; i < tam_aux; i++)
        {
            w[i].matricula = v[i].matricula;
            w[i].media = v[i].media;
        }

        w[tam_aux].matricula = matricula;
        w[tam_aux].media = media;
        delete[] v;
        v = w;
        tam++;
    }
    else
    {
        cout << "Aluno ja existente" << endl;
    }
}

void removerAluno (aluno *&v, int &tam, int matricula)
{
    int posicao = findMatricula(v, tam, matricula);
    
    if( posicao != -1)
    {   
        int tam_aux = tam-1;

        aluno *w = new aluno[tam_aux-1];

        for(int i = 0, j = 0; i < (tam_aux-1); i++, j++)
        {
            if(i == posicao)
            {
                j++;
            }

            w[i].matricula = v[j].matricula;
            w[i].media = v[j].media;
        }

        delete[] v;
        v = w;
        tam--;
    }
    else
    {
        cout << "Aluno NAO existente" << endl;
    }
}

int main()
{   

    try
    {
        int tam = 1, escolha, matricula;
        double media;
        aluno *v = new aluno[tam];

        while(true)
        {
            cout << "Digite [1] para inserir um aluno, [2] para consultar a media, [3] para alterar a media, [4] para remover um estudante (-1 para sair):";
            cin >> escolha;

            if(escolha == -1)
            {
                break;
            }
            else if(escolha == 1)
            {
                cout << "Digite a matricula:";
                cin >> matricula;
                cout << "Digite a media:";
                cin >> media;
                inserirAluno(v, tam, matricula, media);
            }
            else if(escolha == 2)
            {
                cout << "Digite a matricula:";
                cin >> matricula;
                cout << "A media eh:" << getMediaByMatricula(v, tam, matricula) << endl;
            }
            else if(escolha == 3)
            {
                cout << "Digite a matricula:";
                cin >> matricula;
                cout << "Digite a media:";
                cin >> media;
                trocarMedia(v, tam, matricula, media);
            }
            else if(escolha == 4)
            {
                cout << "Digite a matricula:";
                cin >> matricula;
                removerAluno(v, tam, matricula);
            }
            else
            {
                cout << "Valor digitado invalido, tentar novamente" << endl;
            }

            cout << "====================================================" << endl;

            for(int i = 0; i < tam-1; i++)
            {
                cout << "Aluno " << (i + 1) << endl;
                cout << "Matricula:" << v[i].matricula << endl;
                cout << "Media:" << v[i].media << endl;
            }

        }
        delete[] v;  
    }
    catch(bad_alloc &e){
        cout << "Erro" << endl;
    }
    
    return 0;
}