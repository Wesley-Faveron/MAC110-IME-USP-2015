/********************************************************************/
/**                                                                **/
/**  MAC0110 - Introducao a Computacao - LM - 1o. sem. 2015        **/
/**  Nome do aluno : Wesley Faveron de Almeida                     **/
/**  Numero USP : 8943581       Curso : Licenciatura em Matemática **/
/**  Exercicio-Programa 01                                         **/
/**                                                                **/
/********************************************************************/
/* O programa a seguir tem como objetivo resolver o problema do seguinte*/
/* enunciado*/
/* Para realizar medidas de volume, uma química dispõe em seu laboratório*/
/* somente de pipetas de 1 ml, 5 ml, 10 ml, 25 ml e 50 ml.*/
/* Escreva um programa na linguagem C, que tenha como entrada uma sequência de*/
/* inteiros positivos, seguida por um zero.*/
/* Cada inteiro positivo da sequência de entrada representa um volume em*/
/* mililitros. Para cada um dos inteiros positivos da sequência, seu programa*/
/* deve determinar o número mínimo de pipetagens necessárias*/
/* e uma forma de obter o volume correspondente realizando um número mínimo*/
/* de pipetagens, somente adicionando-se volumes.*/
/* Neste exercício-programa trabalhe apenas com números inteiros.*/
/* As mensagens e o formato de saída do seu programa deverão ser idênticos aos*/
/* do exemplo abaixo.*/
/* O seu programa só poderá utilizar os recursos da linguagem C que foram*/
/* vistos em aula.*/

#include <stdio.h>

int main()
{
    int n,            /*numero inserido pelo usuario*/
        pipeta50,     /*Quantidade de pipetas de 50 ml usadas*/
        pipeta25,     /*Quantidade de pipetas de 25 ml usadas*/
        pipeta10,     /*Quantidade de pipetas de 10 ml usadas*/
        pipeta5,      /*Quantidade de pipetas de 5 ml usadas*/
        pipeta1,      /*Quantidade de pipetas de 1 ml usadas*/
        resto,        /*Armazena o resto das divisões sucessivas*/
        soma_pipetas; /*Armazena a quantidade minima e total de*/
                      /*pipetas usadas*/
    printf ("Digite um inteiro positivo representando um volume em mililitros: ");
    scanf ("%d", &n);
    while (n !=0)
    {
        pipeta50 = pipeta25 = pipeta10 = pipeta5 = pipeta1 = 0;

        pipeta50 = n/50;
        resto = n%50;
        pipeta25 = resto/25;
        resto = resto%25;
        pipeta10 = resto/10;
        resto = resto%10;
        pipeta5 = resto/5;
        resto = resto%5;
        pipeta1 = resto;
        soma_pipetas = pipeta50 + pipeta25 + pipeta10 + pipeta5 + pipeta1;

        if (soma_pipetas != 1) printf ("\n O volume de %d ml pode ser obtido com um minimo de %d pipetagens,\ndistribuidas da seguinte forma:\n", n, soma_pipetas);
        else
            printf ("\n O volume de %d ml pode ser obtido com\n", n);
        if (pipeta50 > 1)
            printf ("%4d pipetagens de 50 ml\n", pipeta50);
        else
            if (pipeta50 == 1)
                printf ("%4d pipetagem  de 50 ml\n", pipeta50);
        if (pipeta25 > 1)
            printf ("%4d pipetagens de 25 ml\n", pipeta25);
        else
            if (pipeta25 == 1)
                printf ("%4d pipetagem  de 25 ml\n", pipeta25);
        if (pipeta10 > 1)
            printf ("%4d pipetagens de 10 ml\n", pipeta10);
        else
            if (pipeta10 == 1)
                printf ("%4d pipetagem  de 10 ml\n", pipeta10);
        if (pipeta5 > 1)
            printf ("%4d pipetagens de  5 ml\n", pipeta5);
        else
            if (pipeta5 == 1)
                printf ("%4d pipetagem  de  5 ml\n", pipeta5);
        if (pipeta1 > 1)
            printf ("%4d pipetagens de  1 ml\n", pipeta1);
        else
            if (pipeta1 == 1)
                printf ("%4d pipetagem  de  1 ml\n", pipeta1);

        printf ("\n\nDigite um inteiro positivo representando um volume em mililitros,\nou um zero para finalizar: ");
        scanf ("%d", &n);
    }
    printf ("\n\n            FIM DE JOGO \n\n");
    printf ("         TENHA UM BOM DIA ;) \n\n");
    return 0;
}
