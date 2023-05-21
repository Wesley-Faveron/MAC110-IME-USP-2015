/********************************************************************/
/**                                                                **/
/**  MAC0110 - Introducao a Computacao - LM - 1o. sem. 2015        **/
/**  Nome do aluno : Wesley Faveron de Almeida                     **/
/**  Numero USP : 8943581       Curso : Licenciatura em Matemática **/
/**  Exercicio-Programa 03                                         **/
/**                                                                **/
/********************************************************************/

/* O programa a seguir satisfaz o seguinte enunciado: */
/*Escreva um programa em C que realiza uma sequencia de tarefas.*/
/*Uma tarefa pode ser calcular um valor aproximado para pi, em termos da area da funcaao*/
/*f(x) = √(1.0 − x) no intervalo [0.0, 1.0]. A area em quest˜ao devera*/
/*ser calculada utilizando-se um dos tres metodos (Retangulos trapezios e Monte Carlo).*/
/*Uma outra tarefa possıvel e imprimir um grafico da func˜ao f(x) = √(1.0 − x)*/
/*no intervalo [0.0, 1.0].*/

#include <stdio.h>
/* As definocoes sugeridas no enunciado do EP*/
#define EPS 1e-7
#define A 1277
#define B 1
#define L 131072
/*Os prototipos das fucoes usdas durante a execucao do programa*/
double modulo (double x);
double raiz_quadrada (double x);
double f (double x);
double metodo_retangulos (double a, double b, int k);
double metodo_trapezios (double a, double b, int k);
void gera_num_aleatorio (int *u);
void gera_ponto (double a, double b, double M, int *u, double *px, double *py);
double metodo_monte_carlo (double a, double b, double m, int n, int *u);
int converte (double fx, double M, int fe);
void imprime_grafico (double a, double b, double M, int k, int fe);

int main()
{
    int n,          /* Numero de retangulos, trapezios ou pontos (Monte carlo e */
                    /* Grafico), depende da tarefa */
        fe,         /* Fator de escala no grafico */
        semente,    /* Numero inicial (semente) para gerar numeros aleatorios */
        repeticoes, /* Numero de repeticoes do metodo de Monte Carlo para */
                    /* achar a aproximacao de PI */
        i;          /* contador auxiliar para contar o numero de repeticoes */
                    /* do metodo de Monte Carlo */
    double  a,      /* valor inicial do intervalo da funcao */
            b,      /* valor final do intervalo da funcao */
            M,      /* Assintota da funcao */
            pseudo_pi; /* Variavel auxiliar pro calculo do PI no metodo */
                       /* de Monte Carlo */
    char    tarefa; /* Caractere correspondente a tarefa executada */
    a = 0.0;
    b = 1.0;
    M = 1.0;
    printf("\n   O PROGRAMA A SEGUIR REALIZA 4 DIFERENTES TAREFAS DESCRITAS"
           "\n                    NA TABELA ABAIXO:\n"
           "\n-----------------------------------------------------------------"
           "\n|              O QUE FAZ              | CARACTERE CORESPONDENTE |");
    printf("\n|---------------------------------------------------------------|"
           "\n| Calcula um valor aproximado para PI |             r           |"
           "\n| usando o metodo dos retangulos.     |                         |"
           "\n|---------------------------------------------------------------|");
    printf("\n| Calcula um valor aproximado para PI |             t           |"
           "\n| usando o metodo dos trapezios.      |                         |"
           "\n|---------------------------------------------------------------|"
           "\n| Calcula um valor aproximado para PI |             m           |");
    printf("\n| usando o metodo de Monte Carlo.     |                         |"
           "\n|---------------------------------------------------------------|"
           "\n| Gera um esboco do grafico da funcao |             g           |"
           "\n| raiz quadrada de (1 - x*x).         |                         |");
    printf("\n|---------------------------------------------------------------|"
           "\n| Para finalizar a execucao do progra-|             -           |"
           "\n| ma digite esse caractere            |                         |"
           "\n-----------------------------------------------------------------");
    printf("\n\nDigite o codigo de uma tarefa ('r', 't', 'm', 'g') : ");
    scanf("%c", &tarefa);
    while (tarefa != '-')
    {
        switch (tarefa)
        {
            case 'r' : /* tarefa do metodo dos retangulos */
                        printf("\nDigite o numero de retangulos : ");
                        scanf("%d", &n);
                        printf("\n--------------------------------------------"
                               "------------------------------------\n"
                               "Tarefa : Valor aproximado de pi pelo metodo"
                               " dos retangulos"
                                "\n\nNumero de retangulos = %d"
                                "\nDeltax = %f"
                                "\nPI = %.10f", n, (b - a)/n,
                               4 * metodo_retangulos(a, b, n));
                        break;
            case 't' : /* tarefa do metodo dos trapezios */
                        printf("\nDigite o numero de trapezios : ");
                        scanf("%d", &n);
                        printf("\n-------------------------------------------"
                               "-------------------------------------\n"
                               "Tarefa : Valor aproximado de pi pelo metodo"
                               " dos trapezios"
                                "\n\nNumero de trapezios = %d"
                                "\nDeltax = %f"
                                "\nPI = %.10f", n, (b - a)/n,
                               4 * metodo_trapezios (a, b, n));
                        break;
            case 'm' : /* tarefa do metodo de Monte Carlo */
                        printf("\nDigite uma semente para o gerador de nos."
                               " aleatorios : ");
                        scanf("%d", &semente);
                        printf("Digite o numero de repeticoes do calculo da"
                               " area : ");
                        scanf("%d", &repeticoes);
                        printf("Digite o numero de pontos a serem gerados : ");
                        scanf("%d", &n);
                        printf("\n------------------------------------------"
                               "--------------------------------------\n"
                               "Tarefa : Valor aproximado de pi pelo "
                               "Monte Carlo\n\nSemente = %d"
                               "\nNumero de repeticoes = %d"
                               "\nNumero de pontos = %d", semente,
                                repeticoes, n);
                        pseudo_pi = 0.0;
                        for(i = 1; i <= repeticoes; i++)
                            pseudo_pi = pseudo_pi +
                            4 * metodo_monte_carlo(a, b, M, n, &semente);
                        printf("\nPI = %.10f", pseudo_pi/repeticoes);
                        break;
            case 'g' : /* tarefa de gerar o grafico da funcao */
                        printf("\nDigite o numero de pontos para o grafico : ");
                        scanf("%d", &n);
                        printf("Digite um fator de escala (int. entre 20 e 60) : ");
                        scanf("%d", &fe);
                        printf("\n------------------------------------------"
                               "--------------------------------------\n"
                               "Tarefa : Grafico da funcao raiz quadrada de"
                               " (1-x*x) no intervalo [%.1f, %.1f]"
                               "\n\nNumero de pontos = %d"
                               "\nFator de escala = %d\n\n\n", a, b, n, fe);
                        imprime_grafico(a, b, M, n, fe);
                        break;
            default : /* Caso o usuario insira um caractere invalido */
                        printf("\nTarefa invalido (%c).\n", tarefa);
        }
        printf("\n\n====================================================="
               "==========================="
               "\n\nDigite o codigo de uma tarefa ('r', 't', 'm', 'g', '-') : ");
        scanf(" %c", &tarefa);
    }
    printf("\n\n====================================================="
               "===========================");
    /* Mensagem final so pra deixa mais divertido o programa */
    printf ("\n\n          FIM DAS TAREFAS \n\n");
    printf ("         TENHA UM BOM DIA ;) \n\n");
    return 0;
}
/* Esta func˜ao recebe um numero real x, e devolve o modulo de x */
/* Ao longo do programa nao precisei usar essa funcao porem */
/* estou deixando ela aqui pois o enunciado diz bem claro */
/* "Implemente em seu programa, obrigatoriamente, todas as func˜oes */
/* cujos prototipos est˜ao descritos a seguir ( No caso, no pdf do enunciado). */
/* N˜ao altere o prototipo de nenhuma delas" */
double modulo (double x)
{
    if (x < 0)
        return -1 * x;
    else
        return x;
}
/* Esta func˜ao recebe um numero real positivo x, e devolve uma */
/* aproxima¸c˜ao da raiz quadrada de x,com precis˜ao EPS. */
/* EPS ja foi definido no comeco dro programa */
double raiz_quadrada (double x)
{
    double r0, r1, y;
    r0 = x;
    r1 = (x + 1.0)/2;
    y = r1 - r0;

    while ((y >= EPS) || (y <= -EPS))
    {
        r0 = r1;
        r1 = (r0 + x/r0)/2;
        y = r1 - r0;
    }
    return r1;
}
/* A funcao que o programa se baseia para fazer todas as aproximacoes e graficos */
/* Nesse caso e a funca raiz quadrada de 1-x^2 */
/* Essa funcao recebe um x real e devolve a a raiz quadrada de 1 - x^2 */
double f (double x)
{
    if (1 > x*x)
        return raiz_quadrada(1 - x*x);
    else
        return 0.0;
}
/* Esta func˜ao recebe um inteiro positivo k, e dois n´umeros reais a e b, */
/* com a < b. Devolve um valor aproximado para a ´area da fun¸c˜ao f(x), no */
/* intervalo [a, b], calculada pelo metodo dos retangulos, utilizando k retangulos */
double metodo_retangulos (double a, double b, int k)
{
    int i;
    double area, deltax;
    deltax = (b - a)/k;
    area = 0.0;
    for(i = 1; i <= k; i++)
        area = area + deltax * f(a + i*deltax);
    return area;
}
/* Esta func˜ao recebe um inteiro positivo k, e dois numeros reais a e b, */
/* com a < b. Devolve um valor aproximado para a area da func˜ao f(x), no */
/* intervalo [a, b], calculada pelo metododos trapezios, utilizando k trapezios */
double metodo_trapezios (double a, double b, int k)
{
    int i;
    double area, deltax;
    deltax = (b - a)/k;
    area = 0.0;
    for(i = 1; i <= k; i++)
        area = area + (deltax/2) * ( f(a + (i-1)*deltax) + f(a + i*deltax) );
    return area;
}
/* Esta func˜ao recebe um inteiro *u (uma semente ou um numero da sequencia */
/* pseudo-aleatoria gerada a partir de uma semente). Armazena em *u o valor */
/* do proximo inteiro gerado pelo metodo das congruencias lineares a partir de *u */
void gera_num_aleatorio (int *u)
{
    *u = (A * *u + B) % L ;
}
/* Esta func˜ao recebe dois numeros reais em a e b, com a < b, um numero */
/* real positivo em M e um inteiro *u (uma semente ou um numero da sequencia */
/* pseudo-aleatoria gerada a partir de uma semente). A partir de *u, a func˜ao */
/* gera as coordenadas reais x e y de um ponto no retangulo [a, b] × [0, M], que */
/* serao armazenadas em *px e *py, respectivamente */
void gera_ponto (double a, double b, double M, int *u, double *px, double *py)
{
    gera_num_aleatorio(u);
    *px = a + (double)(*u) * (b - a)/(L - 1);
    gera_num_aleatorio(u);
    *py = (double)(*u) * M/(L - 1);
}
/* Esta funcao recebe um inteiro positivo em n, dois numeros reais em a e b, */
/* com a < b, um numero real positivo em M tal que f(x) ≤ M, para todo x ∈ [a, b], */
/* e o endere¸co de uma vari´avel inteira em u (e o endereco da variavel que */
/* armazena uma semente ou cada numero da sequencia pseudo-aleatoria gerada a */
/* partir de uma semente). Essa func˜ao calcula e devolve um valor aproximado */
/* para a area da funcao f(x), no intervalo [a, b], utilizando o metodo de */
/* Monte Carlo, gerando n pontos no retangulo [a, b] × [0, M].*/
double metodo_monte_carlo (double a, double b, double M, int n, int *u)
{
    int p, i;
    double px, py;
    for (p = 0, i = 1 ; i <= n ; i++)
    {
    gera_ponto(a, b, M, u, &px, &py);
    if ( px >= a && px <= b && py <= f(px) )
        p++;
    }
    return ((double)p/n) * (b - a) * M;
}
/* Esta func˜ao recebe dois numeros reais fx e M, com 0 ≤ fx ≤ M, e um inteiro fe. */
/* Devolve o inteiro entre 0 e fe, correspondente a fx. */
int converte (double fx, double M, int fe)
{
    return (int)((fx * fe)/M + 0.5);
}
/* Esta funcao recebe dois inteiros positivos k e fe, dois numeros reais a e b, */
/* com a < b, e um numero real M tal que 0 ≤ f(x) ≤ M, para todo x ∈ [a, b]. */
/* Imprime um grafico da func˜ao f(x), no intervalo [a, b], calculando o valor */
/* dessa func˜ao em k pontos equidistantes desse intervalo, utilizando o fator de escala fe. */
void imprime_grafico (double a, double b, double M, int k, int fe)
{
    int i, cont_esp, convercao;
    double px, deltax, fx;
    printf("                 %.0f", a);
    for (i = 1; i < fe ; i++)
        printf(" ");
    printf("%.0f\n x (linhas)     ", M);
    for (i = 1; i <= fe ; i++)
        printf(" ");
    printf("        f(x) (colunas)\n              --|");
    for (i = 0; i <= fe ; i++)
        printf("-");
    printf("|-->");
    deltax = (double)(b-a)/(k-1);
    px = a;
    for (i = 0; i < k ; i++)
    {
        px = a + i*deltax;
        printf("\n  %f      |", px);
        fx = f(px);
        convercao = converte(fx, M, fe);
        for(cont_esp = 0; cont_esp < convercao; cont_esp++)
            printf(" ");
        printf("*");
        while (cont_esp < fe)
        {
            printf(" ");
            cont_esp++;
        }
        printf("|      %.10f", f(px));
    }
        printf("\n                |");
        for(cont_esp = 0; cont_esp <= fe; cont_esp++)
            printf(" ");
        printf("|");
}
