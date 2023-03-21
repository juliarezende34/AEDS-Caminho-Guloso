#include "funcoes.hpp"

int main(){
    int N, linhaInicio, colunaInicio, nMatrizesArquivo, somaFinal = 0;
    ifstream arquivo, arquivoPosicaoInicial;
    string ** matrizTxt;
    int ** matrizInt;

    arquivoPosicaoInicial.open("dataset/posicaoInicial.data", ios::in);
    arquivo.open("dataset/input.data", ios::in);

    linhaInicio = determinarLinhaInicio(arquivoPosicaoInicial);
    colunaInicio = determinarColunaInicio(arquivoPosicaoInicial);
    
    N = lerPrimeiraLinha(arquivo);
    cout << N << "\n";
    nMatrizesArquivo = contarLinhasVazias(arquivo);

    arquivo.close();//Fechei aqui pois na função de contar linhas vazias, percorro todo o arquivo.

    arquivo.open("dataset/input.data", ios::in);

    matrizInt = (int**)malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++){
        matrizInt[i] = (int*)malloc(N * sizeof(int));
    }
    
    matrizTxt = (string**)malloc(N * sizeof(string*));
    for(int i = 0; i < N; i++){
        matrizTxt[i] = (string*)malloc(N * sizeof(string));
    }

    for (int i = 0; i < nMatrizesArquivo; i++){ 
        cout << "Matriz " << i + 1 << endl;       
        lerMatrizArquivo(matrizTxt, arquivo, N);        
        converterStrParaInt(matrizTxt, matrizInt, N);
        imprimirMatrizInt(matrizInt, N);
        cout << endl;
        somaFinal += andar(matrizInt, N, linhaInicio, colunaInicio);
        
        cout << "\n";
    }

    for(int i = 0; i < N; i++){
        free(matrizInt[i]);
    }
    free(matrizInt);

    for(int i = 0; i < N; i++){
        free(matrizTxt[i]);
    }
    free(matrizTxt);

    cout << "\nSoma final = " << somaFinal << endl;

    arquivo.close();
    arquivoPosicaoInicial.close();

    return 0;
}