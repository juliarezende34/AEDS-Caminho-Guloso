//Inclusões
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
#include <string>

using namespace std;

int lerPrimeiraLinha(ifstream &arquivo){
    int N;
    string primeiraLinha;
    getline(arquivo, primeiraLinha);
    N = atoi(primeiraLinha.c_str());
    return N;
}

int contarLinhasVazias(ifstream& arquivo){
    string linha;
    bool estado;
    int cont = 0;
    while(!arquivo.eof()){
        getline(arquivo, linha);
        estado = true;
        for(char c : linha){
            if(!isspace(c)){
                estado = false;
            }
        }
        if(estado){
            cont++;
        }
    }
    cout << "CONT = " << cont << endl;
    return cont;
}

void lerMatrizArquivo(string ** matrizTexto, ifstream &arquivo, int N){
    int cont = 0;
    string numeroAtual, linha;
    getline(arquivo, linha);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrizTexto[i][j] = "x";
        }
    }

    if (!arquivo)
    {
        cout << "Erro na abertura do arquivo!!\n";
        exit(-1);
    }
    else
    { 
        for (int x = 0; x < N; x++)
        {
            getline(arquivo, linha);

            for (int i = 0; i <= (int) linha.size(); i++)
            {
                if (linha[i] != '\0')
                {
                    if (linha[i] != ' ')
                    {
                        numeroAtual += linha[i];
                    }
                    else
                    {
                        for (int i = 0; i < N; i++)
                        {
                            if (matrizTexto[cont][i] == "x")
                            {
                                matrizTexto[cont][i] = numeroAtual;
                                break;
                            }
                        }
                        numeroAtual.clear();
                    }
                }
                else
                {
                    break;
                }
            }
            cont++;
            linha.clear();
        }
        cont = 0;
    }
}

void converterStrParaInt(string ** matrizTexto, int ** matrizInt, int N){    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {
            matrizInt[i][j] = atoi(matrizTexto[i][j].c_str());
            //cout << matrizInt[i][j] << " ";
        }
        //cout << "\n";
    }
}

void imprimirMatrizInt(int ** matriz, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

void imprimirMatrizTxt(string ** matriz, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

int posicaoMaiorValor(vector<int> vetor){
    int maior = 0, posicaoMaior = vetor[0];
    if(!vetor.empty()){
        for (int i = 0; i < (int)vetor.size(); i++){
            if (vetor[i] > maior){
                maior = vetor[i];
                posicaoMaior = i;
            }
        }
    }
    return posicaoMaior;
}

int ondeAndar(int ** matriz, int linhaAtual, int colunaAtual, int N){
    // Retornos:
    // 1 - Direita, 2 - Esquerda, 3 - Para baixo, 4 - Diagonal direita, 5 - Diagonal esquerda, 10 - Fim
    // Coluna 0: não posso ir pra esquerda nem pra diagonal esquerda
    // Coluna N-1: não posso ir pra direita nem pra diagonal direita
    // Linha N-1: Ando somente para a direita
    vector<int> vetorValores;
    int retorno, posicaoMaior;

    if (colunaAtual == 0){
        if(linhaAtual == (N-1)){
            retorno = 1;
        }
        else{
            if(matriz[linhaAtual][colunaAtual + 1] != -1){
                vetorValores.push_back(matriz[linhaAtual][colunaAtual + 1]);//Direita
            }
            else{
                vetorValores.push_back(-1);
            }
            if(matriz[linhaAtual + 1][colunaAtual + 1] != -1){
                vetorValores.push_back(matriz[linhaAtual + 1][colunaAtual + 1]);//Diagonal direita
            }
            else{
                vetorValores.push_back(-1);
            }
            if(matriz[linhaAtual + 1][colunaAtual] != -1){
                vetorValores.push_back(matriz[linhaAtual + 1][colunaAtual]);//Para baixo
            }
            else{
                vetorValores.push_back(-1);
            }
            posicaoMaior = posicaoMaiorValor(vetorValores);
            switch(posicaoMaior){
                case -1:
                    cout << "Preso!\n";
                break;
                case 0:
                    retorno = 1;
                break;
                case 1:
                    retorno = 4;
                break;
                case 2:
                    retorno = 3;
                break;
            }
        }
    }

    else if(colunaAtual == (N-1)){
        if(linhaAtual == (N-1)){
            cout << "Você chegou ao fim!\n";
            return 10;
        }
        else{
            if(matriz[linhaAtual + 1][colunaAtual] != -1){
                vetorValores.push_back(matriz[linhaAtual + 1][colunaAtual]);//Para baixo
            }
            else{
                vetorValores.push_back(-1);
            }
            if(matriz[linhaAtual][colunaAtual - 1] != -1){
                vetorValores.push_back(matriz[linhaAtual][colunaAtual - 1]);//Esquerda
            }
            else{
                vetorValores.push_back(-1);
            }
            if(matriz[linhaAtual + 1][colunaAtual - 1] != -1){
                vetorValores.push_back(matriz[linhaAtual + 1][colunaAtual - 1]);//Diagonal esquerda
            }
            else{
                vetorValores.push_back(-1);
            }
            posicaoMaior = posicaoMaiorValor(vetorValores);
            switch(posicaoMaior){
                case -1:
                    cout << "Preso!\n";
                break;
                case 0:
                    retorno = 3;
                break;
                case 1:
                    retorno = 2;
                break;
                case 2:
                    retorno = 5;
                break;
            }
        }
    }

    else if(linhaAtual == (N-1)){
        retorno = 1;
    }

    else{
        if(matriz[linhaAtual][colunaAtual + 1] != -1){
            vetorValores.push_back(matriz[linhaAtual][colunaAtual + 1]);//Direita
        }
        else{
            vetorValores.push_back(-1);
        }
        if(matriz[linhaAtual + 1][colunaAtual + 1] != -1){
            vetorValores.push_back(matriz[linhaAtual + 1][colunaAtual + 1]);//Diagonal direita
        }
        else{
            vetorValores.push_back(-1);
        }
        if(matriz[linhaAtual + 1][colunaAtual] != -1){
            vetorValores.push_back(matriz[linhaAtual + 1][colunaAtual]);//Para baixo
        }
        else{
            vetorValores.push_back(-1);
        }
        if(matriz[linhaAtual][colunaAtual - 1] != -1){
            vetorValores.push_back(matriz[linhaAtual][colunaAtual - 1]);//Esquerda
        }
        else{
            vetorValores.push_back(-1);
        }
        if(matriz[linhaAtual + 1][colunaAtual - 1] != -1){
            vetorValores.push_back(matriz[linhaAtual + 1][colunaAtual - 1]);//Diagonal esquerda
        }
        else{
            vetorValores.push_back(-1);
        }
        posicaoMaior = posicaoMaiorValor(vetorValores);
        
        switch(posicaoMaior){
            case -1:
                cout << "Preso!\n";
            break;
            case 0:
                retorno = 1;
            break;
            case 1:
                retorno = 4;
            break;
            case 2:
                retorno = 3;
            break;
            case 3:
                retorno = 2;
            break;
            case 4:
                retorno = 5;
            break;
        }
    }
    
    vetorValores.clear();
    
    return retorno;
}

int determinarLinhaInicio(ifstream& arquivo){
    string l;
    int l2;
    getline(arquivo, l);
    l2 = atoi(l.c_str());
    return l2;
}

int determinarColunaInicio(ifstream& arquivo){
    string c;
    int c2;
    getline(arquivo, c);
    c2 = atoi(c.c_str());
    return c2;
}

int andar(int ** matriz, int N, int linhaAtual, int colunaAtual){
    // Retornos da função "ondeAndar":
    // 1 - Direita, 2 - Esquerda, 3 - Para baixo, 4 - Diagonal direita, 5 - Diagonal esquerda
    int proximoLugar = -1, soma = 0;
    while(true){
        if((linhaAtual == colunaAtual) == (N-1)){
            break;
        }
        proximoLugar = ondeAndar(matriz, linhaAtual, colunaAtual, N);
        if(proximoLugar == 10){
            soma += matriz[linhaAtual][colunaAtual];
            matriz[linhaAtual][colunaAtual] = -1;
            imprimirMatrizInt(matriz, N);
            break;
        }
        //cout << "\n" << endl;
        switch(proximoLugar){
            case 1:
                soma += matriz[linhaAtual][colunaAtual];
                matriz[linhaAtual][colunaAtual] = -1;
                colunaAtual++;//Andei para a direita
            break;

            case 2:
                soma += matriz[linhaAtual][colunaAtual];
                matriz[linhaAtual][colunaAtual] = -1;
                colunaAtual--;//Andei para a esquerda
            break;

            case 3:
                soma += matriz[linhaAtual][colunaAtual];
                matriz[linhaAtual][colunaAtual] = -1;
                linhaAtual++;//Andei para baixo
            break;

            case 4:
                soma += matriz[linhaAtual][colunaAtual];
                matriz[linhaAtual][colunaAtual] = -1;
                colunaAtual++;
                linhaAtual++;//Andei para a diagonal direita
            break;

            case 5:
                soma += matriz[linhaAtual][colunaAtual];
                matriz[linhaAtual][colunaAtual] = -1;
                colunaAtual--;
                linhaAtual++;//Andei para a diagonal esquerda
            break;
        }
        //imprimirMatrizInt(matriz, N);
        //cout << "\n";
    }
    cout << "Soma = " << soma << endl;
    cout << "Fim da caminhada!\n";
    return soma;
}