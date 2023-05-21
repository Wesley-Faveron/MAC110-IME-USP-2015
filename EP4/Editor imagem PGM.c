/********************************************************************/
/**                                                                **/
/**  MAC0110 - Introducao a Computacao - LM - 1o. sem. 2015        **/
/**  Nome do aluno : Wesley Faveron de Almeida                     **/
/**  Numero USP : 8943581       Curso : Licenciatura em Matemática **/
/**  Exercicio-Programa 04                                         **/
/**                                                                **/
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>      /* para usar a funcao exit e a constante EXIT_FAILURE */
#include <string.h>      /* para usar as funcoes strcpy, strcat e strcmp */
#define MAXLIN     400   /* numero maximo de linhas para matrizes */
#define MAXCOL     400   /* numero maximo de colunas para matrizes */
#define MAXVIZ     9     /* numero maximo de vizinhos */
#define MAXNOMEARQ 81    /* tamanho maximo (80) para nome de arquivo */

/* Prototipos das funcoes */
void le_arquivo_pgm(char inic_nome_arq[], int a[][MAXCOL], int *lin, int *col, int *maior);
void cria_arquivo_pgm(char inic_nome_arq[], int a[][MAXCOL], int linhas, int colunas, int maior_valor);
void exibe_info_matriz(int a[][MAXCOL], int linhas, int colunas, int maior_valor);
void negativo(int a[][MAXCOL], int linhas, int colunas, int *maior);
void rebate_horizontal(int a[][MAXCOL], int linhas, int colunas);
void rebate_vertical(int a[][MAXCOL], int linhas, int colunas);
void rotacao(int a[][MAXCOL], int *lin, int *col);
void transposta(int a[][MAXCOL], int *lin, int *col);
void subimagem(int a[][MAXCOL], int *lin, int *col, int *maior, int xsup, int ysup, int xinf, int yinf);
void reduzir(int a[][MAXCOL], int *lin, int *col, int *maior);
void dobrar(int a[][MAXCOL], int *lin, int *col);
void filtro_mediana(int a[][MAXCOL], int linhas, int colunas, int *maior);
void copia_matriz(int a[][MAXCOL], int b[][MAXCOL], int linhas, int colunas);
int maior_valor_matriz(int a[][MAXCOL], int linhas, int colunas);
int determina_mediana(int a[][MAXCOL], int linhas, int colunas, int i, int j);
void ordena(int v[], int n);
void lista_operacoes();

int main()
{
 int  imagem[MAXLIN][MAXCOL];      /* matriz que representa uma imagem */
 int  xsup,                        /* Coluna inicial da matriz da subimagem */
      ysup,                        /* Linha inicial da matriz da subimagem */
      xinf,                        /* Coluna final da matriz da subimagem */
      yinf,                        /* Linha final da matriz da subimagem */
      nlinhas,                     /* numero de linhas da imagem */
      ncolunas,                    /* numero de colunas da imagem */
      maior_valor;                 /* maior tonalidade de cinza da imagem */
 char inic_nome_arq[MAXNOMEARQ];   /* nome de um arquivo sem extensao .pgm */
 char codigo;                      /* codigo de uma operacao */
 printf("\nO PRGRAMA A SEGUIR EXECUTA AS SEGUINTES FUNCOES EM UMA IMAGEM COM EXTENSAO .pgm\n"
        "\nLista dos codigos e significados das possiveis operacoes:\n");
 lista_operacoes();
 printf("-------------------------------------------------------------------------------\n");
 printf("\nDigite o codigo de uma operacao : ");
 scanf(" %c", &codigo);
 while (codigo != 'f')
 {
    switch (codigo)
    {
    case 'n' :
             le_arquivo_pgm(inic_nome_arq, imagem, &nlinhas, &ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             negativo(imagem, nlinhas, ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             strcat(inic_nome_arq, "-n");
             cria_arquivo_pgm(inic_nome_arq, imagem, nlinhas, ncolunas, maior_valor);
             break;
    case 'h' :
             le_arquivo_pgm(inic_nome_arq, imagem, &nlinhas, &ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             rebate_horizontal(imagem, nlinhas, ncolunas);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             strcat(inic_nome_arq, "-h");
             cria_arquivo_pgm(inic_nome_arq, imagem, nlinhas, ncolunas, maior_valor);
             break;
    case 'v' :
             le_arquivo_pgm(inic_nome_arq, imagem, &nlinhas, &ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             rebate_vertical(imagem, nlinhas, ncolunas);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             strcat(inic_nome_arq, "-v");
             cria_arquivo_pgm(inic_nome_arq, imagem, nlinhas, ncolunas, maior_valor);
             break;
    case 'r' :
             le_arquivo_pgm(inic_nome_arq, imagem, &nlinhas, &ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             rotacao(imagem, &nlinhas, &ncolunas);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             strcat(inic_nome_arq, "-r");
             cria_arquivo_pgm(inic_nome_arq, imagem, nlinhas, ncolunas, maior_valor);
             break;
    case 't' :
             le_arquivo_pgm(inic_nome_arq, imagem, &nlinhas, &ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             transposta(imagem, &nlinhas, &ncolunas);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             strcat(inic_nome_arq, "-t");
             cria_arquivo_pgm(inic_nome_arq, imagem, nlinhas, ncolunas, maior_valor);
             break;
    case 's' :
             le_arquivo_pgm(inic_nome_arq, imagem, &nlinhas, &ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             printf("\nDigite as coordenadas do canto superior esquerdo (xsup, ysup) : ");
             scanf("%d %d", &xsup, &ysup);
             printf("\nDigite as coordenadas do canto inferior direito (xinf, yinf) : ");
             scanf("%d %d", &xinf, &yinf);
             if ((xsup <= ncolunas && ysup <= nlinhas) && (xinf > xsup && yinf > ysup))
             {
                 subimagem(imagem, &nlinhas, &ncolunas, &maior_valor, xsup, ysup, xinf, yinf);
                 exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
                 strcat(inic_nome_arq, "-s");
                 cria_arquivo_pgm(inic_nome_arq, imagem, nlinhas, ncolunas, maior_valor);
             }
             else printf("\nCoordenadas invalidas, operacao cancelada!\n\n");
             break;
    case 'd' :
             le_arquivo_pgm(inic_nome_arq, imagem, &nlinhas, &ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             if (nlinhas <= MAXLIN/2 && ncolunas <= MAXCOL)
             {
                dobrar(imagem, &nlinhas, &ncolunas);
                exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
                strcat(inic_nome_arq, "-d");
                cria_arquivo_pgm(inic_nome_arq, imagem, nlinhas, ncolunas, maior_valor);
             }
             else printf("\nFuncao nao realizada, a imagem inserida e muito grande, operacao cancelada.\n\n");
             break;
    case 'R' :
             le_arquivo_pgm(inic_nome_arq, imagem, &nlinhas, &ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             reduzir(imagem, &nlinhas, &ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             strcat(inic_nome_arq, "-R");
             cria_arquivo_pgm(inic_nome_arq, imagem, nlinhas, ncolunas, maior_valor);
             break;
    case 'm' :
             le_arquivo_pgm(inic_nome_arq, imagem, &nlinhas, &ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             filtro_mediana(imagem, nlinhas, ncolunas, &maior_valor);
             exibe_info_matriz(imagem, nlinhas, ncolunas, maior_valor);
             strcat(inic_nome_arq, "-m");
             cria_arquivo_pgm(inic_nome_arq, imagem, nlinhas, ncolunas, maior_valor);
             break;
    case 'l' :
             lista_operacoes();
             break;
    default  :
             printf("\nCodigo (    %c    )invalido.\n", codigo);
    }
    printf("-------------------------------------------------------------------------------\n");
    printf("\nDigite o codigo de uma operacao : ");
    scanf(" %c", &codigo);
 }
 return 0;
}
/* Definicoes das funcoes descritas acima */

/* Escreva um comentario para esta funcao ... */
void le_arquivo_pgm(char inic_nome_arq[], int a[][MAXCOL], int *lin, int *col, int *maior)
{
 FILE *arqentra;
 char chave[10];
 int i, j, aux, linhas, colunas, maior_valor;
 char nome_arq[MAXNOMEARQ];
 printf("\nDigite o nome do arquivo de entrada (sem extensao .pgm) : ");
 scanf("%s", inic_nome_arq);
 /* define o nome completo do arquivo */
 strcpy(nome_arq, inic_nome_arq); /* copia inic_nome_arq para nome_arq */
 strcat(nome_arq, ".pgm");        /* concatena ".pgm" no final de nome_arq */
 /* abre o arquivo para leitura */
 arqentra = fopen(nome_arq, "r");
 if (arqentra == NULL)
 {
   printf("Erro na abertura do arquivo %s\n", nome_arq);
   exit (EXIT_FAILURE);
 }
 /* le informacoes iniciais da imagem */
  aux = fscanf(arqentra, "%s", chave);
  if (aux != 1)
  {
    printf("Erro na leitura do arquivo %s \n", nome_arq);
    exit (EXIT_FAILURE);
  }
  if (strcmp(chave,"P2") != 0)
  {
    printf("Formato (%s) desconhecido\n", chave);
    exit (EXIT_FAILURE);
  }
  aux = fscanf(arqentra, "%d %d %d", &colunas, &linhas, &maior_valor);
  if (aux != 3)
  {
    printf("Formato incorreto\n");
    exit (EXIT_FAILURE);
  }
  /* le os valores dos pontos da imagem para a matriz a  */
  for (i = 0; i < linhas; i++)
    for (j = 0; j < colunas; j++)
        fscanf(arqentra, "%d", &a[i][j]);
  fclose(arqentra);   /* fecha arquivo */
  *lin = linhas;
  *col = colunas;
  *maior = maior_valor;
  printf("\nAs informacoes da imagem no arquivo %s foram obtidas com sucesso.\n", nome_arq);
}
/* Escreva um comentario para esta funcao ... */
void cria_arquivo_pgm(char inic_nome_arq[], int a[][MAXCOL], int linhas, int colunas, int maior_valor)
{
 FILE *arqsai;
 int i, j, k;
 char nome_arq[MAXNOMEARQ];
 /* define o nome completo do arquivo */
 strcpy(nome_arq, inic_nome_arq); /* copia inic_nome_arq para nome_arq */
 strcat(nome_arq, ".pgm");        /* concatena ".pgm" no final de nome_arq */
 /* abre o arquivo para escrita */
 arqsai = fopen(nome_arq, "w");
 if (arqsai == NULL)
 {
   printf("Erro na abertura do arquivo %s\n", nome_arq);
   exit (EXIT_FAILURE);
 }
 /* escreve a palavra-chave "P2", indicando formato PGM da imagem */
 fprintf(arqsai, "P2\n");
 /* escreve informacoes da matriz a */
 fprintf(arqsai, "%d %d\n%d\n", colunas, linhas, maior_valor);
 /* escreve os elementos da matriz a */
 for (i = 0; i < linhas; i++)
 {
    for (j = 0; j < colunas; )
    {
       for (k = 0; j < colunas && k < 15; j++, k++)
          fprintf(arqsai, "%4d", a[i][j]);
       fprintf(arqsai, "\n");
    }
 }
 fclose(arqsai);   /* fecha arquivo */
 printf("\nO arquivo %s foi criado com sucesso.\n\n", nome_arq);
}

void exibe_info_matriz(int a[][MAXCOL], int linhas, int colunas, int maior_valor)
{
    int i,j;
    printf("\nNumero de linhas : %d"
           "\nNumero de colunas : %d"
           "\nMaior valor : %d\n",linhas, colunas, maior_valor);
    if(linhas <= 20 && colunas <= 20)
    {
        printf("\nMatriz:\n");
        for(i = 0; i < linhas; i++)
        {
            for(j = 0; j < colunas; j++)
                printf("%4d", a[i][j]);
            printf("\n");
        }
    }
}

void negativo(int a[][MAXCOL], int linhas, int colunas, int *maior)
{
    int i, j;
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            a[i][j] = *maior - a[i][j];
    *maior = maior_valor_matriz(a, linhas, colunas);
    printf("\nFuncao NEGATIVO realizada com sucesso.\n");
}

void rebate_horizontal(int a[][MAXCOL], int linhas, int colunas)
{
    int b[MAXLIN][MAXCOL];
    int i, j;
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            b[linhas - (1+i)][j] = a [i][j];
    copia_matriz(b, a, linhas, colunas);
    printf("\nFuncao REBATE NA HORIZONTAL realizada com sucesso.\n");
}

void rebate_vertical(int a[][MAXCOL], int linhas, int colunas)
{
    int b[MAXLIN][MAXCOL];
    int i, j;
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            b[i][colunas - (1+j) ] = a [i][j];
    copia_matriz(b, a, linhas, colunas);
    printf("\nFuncao REBATE NA VERTICAL realizada com sucesso.\n");
}

void rotacao(int a[][MAXCOL], int *lin, int *col)
{
    int b[MAXLIN][MAXCOL];
    int i, j, linhas, colunas;
    linhas = *lin;
    colunas = *col;
    *lin = colunas;
    *col = linhas;
    for(i = 0; i < colunas; i++)
        for(j = 0; j < linhas; j++)
            b[i][j] = a[linhas -(1+j)][i];
    copia_matriz(b, a, colunas, linhas);
    printf("\nFuncao ROTACAO realizada com sucesso.\n");
}

void transposta(int a[][MAXCOL], int *lin, int *col)
{
   int b[MAXLIN][MAXCOL];
    int i, j, linhas, colunas;
    linhas = *lin;
    colunas = *col;
    *lin = colunas;
    *col = linhas;
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
           b[j][i] = a[i][j];
    copia_matriz(b, a, colunas, linhas);
    printf("\nFuncao TRANSPOSTA realizada com sucesso.\n");
}

void subimagem(int a[][MAXCOL], int *lin, int *col, int *maior, int xsup, int ysup, int xinf, int yinf)
{
    int b[MAXLIN][MAXCOL];
    int i, j;
    for (i = 0; xsup + i <= xinf; i++)
        for(j = 0; ysup + j <= yinf; j++)
            b[i][j] = a[xsup + i][ysup + j];
    copia_matriz(b, a, xinf - xsup + 1, yinf - ysup + 1);
    *maior = maior_valor_matriz(a, i, j);
    *lin = xinf - xsup + 1;
    *col = yinf - ysup + 1;
    printf("\nFuncao SUBIMAGEM realizada com sucesso.\n");
}

void reduzir(int a[][MAXCOL], int *lin, int *col, int *maior)
{
    int b[MAXLIN][MAXCOL];
    int i, j, k, l;
    k = l = 0;
    for (i = 0; i < *lin/2; i++)
    {
        for(j = 0; j < *col/2; j++)
        {
            b[i][j] = (a[k][l] + a[k][l+1] + a[k+1][l] + a[k+1][l+1])/4;
            l = l + 2;
        }
        k = k + 2;
        l = 0;
    }
    *lin = *lin/2;
    *col = *col/2;
    copia_matriz(b, a, *lin, *col);
    *maior = maior_valor_matriz(a, *lin, *col);
    printf("\nFuncao REDUZIR realizada com sucesso.\n");
}

void dobrar(int a[][MAXCOL], int *lin, int *col)
{
    int b[MAXLIN][MAXCOL];
    int i, j, k, l;
    k = l = 0;
    for (i = 0; i < *lin; i++)
    {
        for(j = 0; j < *col; j++)
        {
            b[k][l] = b[k][l+1] = b[k+1][l] = b[k+1][l+1] = a[i][j];
            l = l + 2;
        }
        k = k + 2;
        l = 0;
    }
    *lin = *lin * 2;
    *col = *col * 2;
    copia_matriz(b, a, *lin, *col);
    printf("\nFuncao DOBRAR realizada com sucesso.\n");
}

void filtro_mediana(int a[][MAXCOL], int linhas, int colunas, int *maior)
{
    int b[MAXLIN][MAXCOL];
    int i, j;
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            b[i][j] = determina_mediana(a, linhas, colunas, i, j);
    copia_matriz(b, a, linhas, colunas);
    *maior = maior_valor_matriz(a, linhas, colunas);
    printf("\nFuncao FILTRO DA MEDIANA realizada com sucesso.\n");
}

/* COPIA A MATRIZ a PARA A MATRIZ b */
void copia_matriz(int a[][MAXCOL], int b[][MAXCOL], int linhas, int colunas)
{
    int i,j;
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            b[i][j] = a[i][j];
}

int maior_valor_matriz(int a[][MAXCOL], int linhas, int colunas)
{
    int i, j, M;
    M = 0;
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            if(M < a[i][j])
                M = a[i][j];
    return M;
}

int determina_mediana(int a[][MAXCOL], int linhas, int colunas, int i, int j)
{
    int w[MAXVIZ];
    int k, l, n;
    n = 0;
    for(k = -1; k < 2; k++)
        for(l = -1; l < 2; l++)
            if(i+k >= 0 && i+k < linhas && j+l >= 0 && j+l < colunas)
            {
                w[n] = a[i + k][j + l];
                n++;
            }
    ordena(w, n);
    if(n%2 == 0)
        k = (n-1)/2 + 1;
    if(n%2 == 1)
        k = (n-1)/2;
    return w[k];
}

void ordena(int v[], int n)
{
 int i, j, indmin, aux;

 for (i = 0; i <= n-2; i++)
 {
    indmin = i;
    for (j = i + 1; j <= n-1; j++)
    {
       if (v[indmin] > v[j])
         indmin = j;
    }
    if (indmin != i)
    {
      aux = v[i];
      v[i] = v[indmin];
      v[indmin] = aux;
    }
 }
}

void lista_operacoes()
{
    printf("\n  n - negativo"
           "\n  h - rebater na horizontal"
           "\n  v - rebater na vertical"
           "\n  r - rotacionar"
           "\n  t - transposta"
           "\n  s - subimagem"
           "\n  d - dobrar"
           "\n  R - Reduzir"
           "\n  m - filtro da mediana"
           "\n  l - listar possiveis operacoes"
           "\n  f - finalizar\n\n");
}
