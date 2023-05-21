/********************************************************************/
/**                                                                **/
/**  MAC0110 - Introducao a Computacao - LM - 1o. sem. 2015        **/
/**  Nome do aluno : Wesley Faveron de Almeida                     **/
/**  Numero USP : 8943581  Curso : Licenciatura em Matematica      **/
/**  Exercicio-Programa 02                                         **/
/**                                                                **/
/********************************************************************/

/*O programa a seguir resolver o seguinte problema:*/
/*Considere uma máquina automática que vende refrigerantes.*/
/*Para se fazer um pedido de compra, existe um painel com nove teclas*/
/*representando os dígitos de 1 a 9, e o cliente deve apertar uma delas.*/
/*A máquina considera que o dígito correspondente à tecla apertada é o*/
/*número de refrigerantes que o cliente quer comprar. Se a quantidade*/
/*pedida for maior do que a disponível, a máquina não pode realizar o pedido,*/
/*e emite uma mensagem. Para se efetuar o pagamento, existe uma abertura na*/
/*qual o cliente insere moedas e, em seguida, aperta uma tecla especial para*/
/*finalizar o pagamento. A máquina possui um mecanismo que calcula o número*/
/*de moedas de cada valor, bem como o valor total das moedas inseridas para*/
/*o pagamento. Se este valor for menor do que o valor a ser pago, a máquina*/
/*emite uma mensagem, não concretiza o pedido, e devolve as moedas para esse*/
/*cliente (na mesma combinação que ele inseriu). Se houver troco, a máquina*/
/*deve devolvê-lo, usando para isso o menor número possível de moedas.*/
/*Se não for possível fornecer o troco, o pedido de compra é cancelado,*/
/*a máquina emite uma mensagem e as moedas desse cliente são devolvidas na*/
/*mesma combinação que ele utilizou para o pagamento.*/

#include <stdio.h>

int main()
{
    int est,     /* Quantidade de refrigerante em estoque na maquina*/
        preco,   /* Preço do Refrigerante*/
        m100,    /* Quantidade de moedas de 1 real em caixa */
        m50,     /* Quantidade de moedas de 50 centavos em caixa */
        m10,     /* Quantidade de meodas de 10 centavos em caixa */
        m5,      /* Quantidade de moedas de 5 centavos em caixa */
        m1,      /* Quantidade de moedas de 1 centavo em caixa */
        tcaixa,  /* Total em caixa na maquina */
        n,       /* Quantidade de refrigerante que o usuario deseja */
        moeda,   /* Moedas inseridas pelo usuario */
        i100,    /* Quantidade de moedas inseridas  1 real */
        i50,     /* Quantidade de moedas inseridas de 50 centavos */
        i10,     /* Quantidade de moedas inseridas de 10 centavos */
        i5,      /* Quantidade de moedas inseridas de 5 centavos */
        i1,      /* Quantidade de moedas inseridas de 1 centavo */
        tpago,   /* Total de dinehrio inserido pelo usuario */
        troco,   /* Armazena o troco */
        t100,    /* Quantidade de moedas de 1 real no troco */
        t50,     /* Quantidade de moedas de 50 centavos no troco */
        t10,     /* Quantidade de moedas de 10 centavos no troco */
        t5,      /* Quantidade de moedas de 5 centavos no troco */
        t1;      /* Quantidade de moedas de 1 centavo no troco */

    printf(" Situacao inicial da maquina:\n\n Quantidade de refrigerantes"
           " para venda : ");
    scanf("%d", &est);
    printf("\n Preco de um refrigerante (em centavos) : ");
    scanf("%d", &preco);
    printf("\n Quantidade de moedas, de cada valor, no caixa da maquina:\n");
    printf("     1 real     : ");
    scanf("%d", &m100);
    printf("    50 centavos : ");
    scanf("%d", &m50);
    printf("    10 centavos : ");
    scanf("%d", &m10);
    printf("     5 centavos : ");
    scanf("%d", &m5);
    printf("     1 centavo  : ");
    scanf("%d", &m1);
    tcaixa = m100*100+m50*50+m10*10+m5*5+m1;
    if(tcaixa/100 > 0)
        printf("\n Valor total na maquina : %d centavos (%d reais e %d"
               " centavos).\n\n"
               "======================================================="
               "====================\n\n", tcaixa, tcaixa/100, tcaixa%100);
    else
        printf("\n Valor total na maquina : %d centavos.\n\n"
               "========================================================="
               "==================\n\n", tcaixa);
        /* Aqui comeca a interação do usuario com a maquina */
    printf(" Um pedido de compra:\n\n Quantos refrigerantes deseja"
           " comprar (1 a 9)? ");
    scanf("%d", &n);
        /* Aqui avalia se tem ou não em estoque a quantidade pedida */
    if ( n > est)
      printf( "\n ;(- Pedido de compra nao realizado: existem apenas"
             " %d refrigerantes."
              "\n\n======================================================"
              "=====================", est);

    else
    {
        /* Se tem em estoque ele entra aqui */
        if ( n*preco/100 > 0 )
            printf("\n Voce deve pagar %d centavos (%d reais e %d centavos)."
                   , n*preco, (n*preco)/100, (n*preco)%100);
        else
            printf("\n Voce deve pagar %d centavos.", n*preco);

        printf("\n\n Valores (em centavos) das moedas que voce inseriu"
               " (seguidos por um zero):\n ");
        scanf("%d", &moeda);
        /* Aqui analisa moeda por moeda de qual valor e ela */
        i100 = i50 = i10 = i5 = i1 = 0;
        while (moeda != 0)
        {
          if(moeda == 100)
            i100 ++;
          else
          {
            if(moeda == 50)
                 i50 ++;
            else
            {
                if(moeda == 10)
                    i10 ++;
                else
                {
                    if(moeda == 5)
                        i5 ++;
                    else
                        if (moeda == 1)
                        i1 ++;
                }
            }
          }
          scanf("%d", &moeda);
        }
        tpago = 100*i100+50*i50+10*i10+5*i5+i1;
        printf("\n Quantidade de moedas, de cada valor, que voce inseriu:"
               "\n%5d moeda(s) de  1 real"
               "\n%5d moeda(s) de 50 centavos"
               "\n%5d moeda(s) de 10 centavos"
               "\n%5d moeda(s) de  5 centavos"
               "\n%5d moeda(s) de  1 centavo",i100, i50, i10, i5, i1);
        if (tpago/100 > 0)
            printf("\n\n Valor total pago : %d centavos (%d reais e %d"
                   " centavos).", tpago, tpago/100, tpago%100);
        else
            printf("\n\n Valor total pago : %d centavos.", tpago);
            /* Aqui avalia tem o dinheiro pago se e o suficiente e nao */
            /* achei nescessario colocar else */
            /* Mais sei que ele ira avaliar tres vezes o total*/
            /* pago porem esteticamente */
            /* fica melhor e pra entender pelo menos ao meu ver */
        if (tpago < n*preco)
            printf("\n\n ;( - Pedido de compra cancelado: voce pagou a menos.\n"
                   "      As moedas que voce inseriu serao devolvidas."
                   "\n\n======================================================="
                   "====================\n\n");
            /* Aqui e quando nao tem que dar troco */
        if(tpago == n*preco)
        {
            m100 = m100 + i100;
            m50 = m50 + i50;
            m10 = m10 + i10;
            m5 = m5 + i5;
            m1 = m1 + i1;
            est = est - n;
            printf("\n\n Nao tem troco: pagou valor exato.\n\n"
                   " :) - Pedido de compra bem sucedido!"
                   "\n\n======================================="
                   "====================================\n\n");
        }
            /* Aqui comeca a ser avalido se vai ter como dar troco */
        if (tpago > n*preco)
        {
            troco = tpago - (n*preco);
            m100 = m100 + i100;
            m50 = m50 + i50;
            m10 = m10 + i10;
            m5 = m5 + i5;
            m1 = m1 + i1;
            printf("\n\n Existe um troco de %d centavos.\n\n", troco);
            for(t100 = 0; troco >= 100 && t100 < m100; t100++)
                troco = troco - 100;
            for(t50 = 0; troco >= 50 && t50 < m50; t50++)
                troco = troco - 50;
            for(t10 = 0; troco >= 10 && t10 < m10; t10++)
                troco = troco - 10;
            for(t5 = 0; troco >= 5 && t5 < m5; t5++)
                troco = troco - 5;
            for(t1 = 0; troco >= 1 && t1 < m1; t1++)
                troco = troco - 1;
            /* Aqui não tem como dar o troco */
            if (troco > 0)
            {
                m100 = m100 - i100;
                m50 = m50 - i50;
                m10 = m10 - i10;
                m5 = m5 - i5;
                m1 = m1 - i1;
                printf(" ;( - Pedido de compra cancelado: a maquina"
                       " nao pode fornecer o troco.\n"
                       "      As moedas que voce inseriu serao devolvidas."
                       "\n\n==============================================="
                       "============================\n\n");
            }
            /* Aqui e quando se tem como dar o troco e ele vai emitir */
            else
            {
                m100 = m100 - t100;
                m50 = m50 - t50;
                m10 = m10 - t10;
                m5 = m5 - t5;
                m1 = m1 - t1;
                est = est - n;
                printf(" A maquina fornece o troco da seguinte forma:\n");
                /* Aqui tambem sei que ele  ira avaliar duas vezes cada moeda */
                /* Pois nao vejo muito problea em avaliar duas vezes ao inves */
                /* de uma vez so e colocar um monter de else e basicamente */
                /* dar no mesmo pois tem o caso de ser zero */
                if (t100 == 1)
                    printf("%6d moeda  de  1 real\n", t100);
                if (t100 > 1)
                    printf("%6d moedas de  1 real\n", t100);
                if (t50 == 1)
                    printf("%6d moeda  de 50 centavos\n", t50);
                if (t50 > 1)
                    printf("%6d moedas de 50 centavos\n", t50);
                if (t10 == 1)
                    printf("%6d moeda  de 10 centavos\n", t10);
                if (t10 > 1)
                    printf("%6d moedas de 10 centavos\n", t10);
                if (t5 == 1)
                    printf("%6d moeda  de  5 centavos\n", t5);
                if (t5 > 1)
                    printf("%6d moedas de  5 centavos\n", t5);
                if (t1 == 1)
                    printf("%6d moeda  de  1 centavo\n", t1);
                if (t1 > 1)
                    printf("%6d moedas de  1 centavo\n", t1);

                printf("\n :) - Pedido de compra bem sucedido!\n\n"
                       "=================================================="
                       "=========================\n\n");
            }
         }
         /* Aqui ja atualizou a maquina se foi preciso e vai imprimir o que tem nela */
        printf(" Situacao final da maquina:\n\n "
               "Quantidade de moedas, de cada valor, no caixa da maquina:\n"
               "     1 real     : %2d moeda(s)\n"
               "    50 centavos : %2d moeda(s)\n"
               "    10 centavos : %2d moeda(s)\n"
               "     5 centavos : %2d moeda(s)\n"
               "     1 centavo  : %2d moeda(s)\n",m100, m50, m10, m5, m1);
        tcaixa = m100*100+m50*50+m10*10+m5*5+m1;
        if(tcaixa/100 > 0)
            printf("\n Valor total na maquina : %d centavos (%d reais e"
                   " %d centavos).\n\n", tcaixa, tcaixa/100, tcaixa%100);
        else
            printf("\n Valor total na maquina : %d centavos.\n\n", tcaixa);

        printf(" Restam %d refrigerantes para venda.", est);
    }
    return 0;
}
