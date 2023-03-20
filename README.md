# AEDS: Caminho Guloso
## Objetivo
Ler e caminhar por um conjunto de matrizes de inteiros. Em cada matriz, o ponto de partida é definido através da leitura de um arquivo e o ponto final é o número localizado na última linha da última coluna da matriz. </br>
Para escolher onde deve-se andar, é necessário analisar os números ao redor da posição atual, não considerando ir para trás ou para caminhos já percorridos, e caminhar em direção ao número maior. Assim, é possível trabalhar o conceito de caminhamento de matrizes de forma gulosa.

## Arquivos
* Dados
  * ```posicaoInicial.data```: indica a posição do caminhamento, na primeira linha do arquivo há o número referente à linha da posição inicial e na segunda linha, a coluna da posição inicial;
  * ```input.data```: contém as matrizes;
* Source
  * ```funcoes.hpp```: implementação das funções necessárias para o funcionamento do código;
  * ```main.cpp```: chamada das funções e criação das variáveis estáticas;
* Compilação
  * ```makefile```: automatiza a compilação dos arquivos.
  
## Variáveis importantes
*Todas estão inicializadas em ```main.cpp```*
* "N" (int): tamanho das matrizes, lido a partir da primeira linha do ```input.data```;
* "linhaInicio" e "colunaInicio" (int): indicam a posição inicial, lidas de ```posicaoInicial.data```;
* "nMatrizesArquivo" (int): através de uma função (```int contarLinhasVazias(ifstream arquivo)```), obtém-se o número de matrizes contidas em ```input.data```;
* "somaFinal" (int): soma dos caminhos percorridos nas matrizes;
* "arquivo" e "arquivoPosicaoInicial" (ifstream): objetos associados ```input.data``` e ```posicaoInicial.data```, respectivamente;
* "matrizTxt" (string **): matriz onde o que foi lido de ```input.data``` é salvo;
* "matrizInt" (int **): "matrizTxt" convertida para inteiro.

## Funções - Manipulação de arquivos e matrizes
* ```int determinarLinhaInicio(ifstream& arquivo)```: Lê a primeira linha de ```posicaoInicial.data``` e retorna a linha da posição inicial;
* ```int determinarColunaInicio(ifstream& arquivo)```: Lê a segunda linha de ```posicaoInicial.data``` e retorna a coluna da posição inicial;
* ```int lerPrimeiraLinha(ifstream &arquivo)```: Lê a primeira linha de ```input.data``` e retorna o tamanho das matrizes;
* ```int contarLinhasVazias(ifstream& arquivo)```: Conta as linhas vazias de ```input.data``` e retorna a quantidade de matrizes;
* ```void lerMatrizArquivo(string ** matrizTexto, ifstream &arquivo, int N)```: Lê uma matriz de ```input.data```, ignorando os caracteres ```' '``` e '\0', e a salva na "matrizTxt";
* ```void converterStrParaInt(string ** matrizTexto, int ** matrizInt, int N)```: converte a "matrizTxt" para a "matrizInt", usando a função ```atoi()```;
* ```void imprimirMatrizInt(int ** matriz, int N)``` e ```void imprimirMatrizTxt(string ** matriz, int N)```: percorrem as matrizes de texto e de inteiro, imprimindo-as no terminal.

## Funções - Decisão de caminhamento
* ```int posicaoMaiorValor(vector<int> vetor)```: percorre um vector e retorna a posição do maior valor;
* ```int ondeAndar(int ** matriz, int linhaAtual, int colunaAtual, int N)```: Adiciona os valores das possíveis posições de destino em um vector, usa a função ```posicaoMaiorValor``` para ver qual posição possui maior valor e retorna um inteiro que indica a direção de caminhamento;
* ```int andar(int ** matriz, int N, int linhaAtual, int colunaAtual)```: A partir do inteiro retornado da função ```ondeAndar```, realiza, de fato, o caminhamento.

## Lógica de caminhamento
