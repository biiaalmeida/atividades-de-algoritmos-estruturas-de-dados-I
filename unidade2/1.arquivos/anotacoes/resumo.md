# Arquivos
- Cada arquivo é identificado por seu nome e pelo diretório que ele está armazenado em uma determinada unidade de disco
- Os nomes dos arquivos são compostos pelo nome + uma extensão (tipo do arquivo)
- Um arquivo pode ser visto de duas maneiras: modo texto e modo binário
- Uma vantagem do arquivo texto é que pode ser lido por uma pessoa e editado com os editores de texto
- A vantagem do binário é poder salvar (e recuperar) grandes quantidades de informação de forma mais eficiente
---
Para minimizar a dificuldade na manipulação de arquivos, os sistemas operacionais oferecem um conjunto de serviços para ler e escrever informações em 
disco. A linguagem C disponibiliza esses serviços para o programador por meio de um conjunto de funções. Os principais serviços que interessam são:
- Abertura de arquivos: o SO encontra o arquivo com o nome dado e prepara o buffer na memória
- Leitura do arquivo: o SO recupera o trecho solicitado do arquivo. Como o buffer contém parte da informação do arquivo, parte ou toda a informação 
solicitada pode vim dele.
- Escrita no arquivo: o SO acrescenta ou altera o conteúdo do arquivo. A alteração no conteúdo do arquivo é feita inicialmente no buffer e depois é 
transferida para o disco.
- Fechamento de arquivo: toda a informação contida no buffer é atualizada no disco e a área do buffer utilizada na memória é liberada.
---
- Uma das informações mantidas pelo SO é um cursor que indica a posição de trabalho no arquivo
- Para leitura, esse cursor percorre a sequência de informação existente no arquivo, do início ao fim, conforme os dados vão sendo recuperados(lidos) para a memória.
- Para escrita, normalmente os dados são acrescentados quando o cursor está no fim do arquivo

## Funções para manipular arquivos
- Todas as funções da biblioteca padrão de C que manipulam arquivos encontram-se na biblioteca de entrada e saída (stdio.h)

### Funções para abrir arquivos
- a função básica para abrir um arquivo é a fopen
```
FILE* fopen (char* nome_arquivo, char* modo);
```
- FILE é um tipo definido pela biblioteca padrão que representa uma abstração do arquivo
- Quando abrimos um arquivo, a função tem como valor de retorno um ponteiro para o tipo FILE e todas as operações subsequentes nesse arquivo receberão esse endereço como parâmetro de entrada
- Se o arquivo não puder ser aberto, função retorna o valor NULL
- O parâmetro modo da função fopen é uma cadeia de caracteres em que se espera a ocorrência de caracteres que identificam o modo de abertura

 r    |  read    |    indica modo para leitura 
 ---  |  ---     |  ---
 w    |  write   |    indica modo para escrita 
 a    |  append  |    indica modo para escrita ao final existente
 t    |  text    |    indica modo texto
 b    |  binary  |    indica modo binário

 - Se o arquivo já existe e solicitamos sua abertura para escrita com modo w, o arquivo é destruído e um novo, inicialmente vazio, é criado
 - Quando solicitamos com o modo a, o mesmo é preservado e os novos conteúdos podem ser escritos no seu fim
 - Com ambos os modos, se o arquivo não existir, ele é criado
 - Se solicitar a abertura de um arquivo para leitura, ele já deve existir. Se não, a função falha e retorna o valor NULL
 - A função também falha se tentarmos abrir um arquivo para escrita em uma área(diretório) na qual não temos aceesso de escrita
 - Se quisermos abrir um arquivo para simultaneamente ler e escrever, acrescentamos o caractere + no modo de abertura (r+ ou w+)
 - Os modos b e t podem ser combinados com os demais 
 - Quando abrimos um arquivo, testamos o sucesso da abertura antes de qualquer outra operação
 Por exemplo: 
 ```
 FILE* fp;
 fp = fopen("entrada.txt", "rt");
 if(fp == NULL){
    printf("Erro na abertura do arquivo!\n");
    exit(1)
 }
 ```

 ### Funções para fechar arquivos
 - Após ler/escrever as informações de um arquivo, devemos fechá-lo
 - Usamos a função fclose, que espera como parâmetro o ponteiro do arquivo que deseja fechar 
 ```
 int fclose(FILE* fp);
 ```
 - O valor de retorno dessa função é 0 se o arquivo for fechado com sucesso ou a constante EOF que indica a ocorrência de um erro

 ## Arquivos em modo texto
 - Manipulação de arquivos em modo texto

 ### Funções para ler dados
 - A principal função de C para a leitura de dados em arquivos em modo texto é a fscanf
 - Os dados são capturados de um arquivo previamente aberto para leitura
 - A cada leitura, os dados correspondentes são transferidos para a memória e o cursor do arquivo avança, passando a apontar para o próximo dado do arquivo
 ```
 int fscanf (FILE* fp, char* formato, ...);
 ```
 - O primeiro parâmetro deve ser o ponteiro para o arquivo do qual os dados estão sendo lidos
 ---
 - Outra função é a fgetc
 - Ela pega um único (primeiro) caractere do arquivo
 - Dado o ponteiro do arquivo, captura o próximo caractere do arquivo (e o cursor avança para o próximo caractere)
 ```
 int fgetc (FILE* fp);
 ```
 - Apesar de o tipo do valor ser int, o valor retornado é o código do caractere lido.
 - Se o fim do arquivo for alcançado, a constante EOF(end of file) é retornada
 ---
 - Outra função muito utilizada para ler linhas de um arquivo é a função fgets
 - Ela recebe como parâmetro três valores: a cadeia de caracteres que armazenará o conteúdo lido do arquivo, o número máximo de caracteres que deve ser lido e o ponteiro do arquivo
 ```
 char* fgets (char* s, int n, FILE* fp);
 ```
 - A função lê do arquivo uma sequência de caracteres até que encontre um caractere \n ou o máximo de caracteres especificado seja alcançado
 - O valor de retorno dessa função é o ponteiro da prórpria cadeia de caracteres passada como parâmetro ou NULL no caso de ocorrer erro de leitura

 ### Funções para escrever dados
 - A função fprintf é similar ao printf que é usada para imprimir dados na saída padrão
 - A diferença é ter o parâmetro que indica o aquivo onde o dado será salvo
 - O valor de retorno dessa função é o número de bytes escritos no arquivo
 ```
 int fprintf(FILE* fp, char* formato,...);
 ```
 ---
 - A função fputc escreve im caractere no arquivo 
 - No primeiro parâmetro especificamos o código do caractere que queremos escrever/salvar
 - O valor de retorno dessa função é o próprio caractere escrito ou EOF se ocorrer um erro na escrita
 ```
 int fputc(int c, FILE* fp);
 ```