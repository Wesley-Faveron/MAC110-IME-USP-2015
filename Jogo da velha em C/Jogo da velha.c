#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int testaLinhaVencedor( int J[3][3], int i )
{
	if ( J[i][0] == J[i][1] && J[i][0] == J[i][2] )
    {
        return J[i][0];
    }
	return 0;
}
int testaColunaVencedor( int J[3][3], int j )
{
	if ( J[0][j] == J[1][j] && J[0][j] == J[2][j] )
    {
        return J[0][j];
	}
	return 0;
}

int testaDiagonalVencedor( int J[3][3] )
{
	if ( J[0][0] == J[1][1] && J[0][0] == J[2][2] )
    {
		return J[0][0];
	}
	if ( J[2][0] == J[1][1] && J[2][0] == J[0][2] )
	{
		return J[2][0];
	}
	return 0;
}

int testaVencedor( int J[3][3] )
{
	int i;
	if ( testaDiagonalVencedor(J) !=0 )
    {
		return testaDiagonalVencedor(J);
	}
	for ( i=0; i< 3; i++ )
	{
		if( testaLinhaVencedor( J, i )!=0 )
			return testaLinhaVencedor( J, i );
		if( testaColunaVencedor( J, i )!=0 )
			return testaColunaVencedor( J, i );
	}
	return 0;
}

int testaCasaVazia( int J[3][3], int i, int j )
{
	if ( J[i][j] == 0 )
		return 1;
	return 0;
}
void imprimeTabuleiro( int J[3][3] )
{
    char A[3][3];
    int i, j;
    for (i = 0;i < 3;i++)
		for (j = 0;j < 3;j++)
        {
            if (J[i][j] == 0)
                A[i][j] = ' ';
            else
                if (J[i][j] == 1)
                    A[i][j] = 'X';
                else
                    A[i][j] = 'O';
        }
    printf("\n %c | %c | %c \n"
           "-----------\n"
           " %c | %c | %c \n"
           "-----------\n"
           " %c | %c | %c \n\n",
           A[0][0], A[0][1], A[0][2], A[1][0], A[1][1], A[1][2], A[2][0], A[2][1], A[2][2]);
}
int obtemJogadaAleatoria( int J[3][3] )
{
    int i, j;
    srand(time(NULL));
    i = rand() % 3;
    j = rand() % 3;
    while( testaCasaVazia(J, i, j) == 0)
    {
        srand(time(NULL));
        i = rand() % 3;
        j = rand() % 3;
    }
    return i*10+j;
}
int obtemJogadaInteligenteParaO( int J[3][3] )
{
    if (J[1][1] == 0)
        return 11;
    else
        if (J[0][0] + J[0][1] + J[0][2] == 2 || J[0][0] + J[0][1] + J[0][2] == -2)
        {
            if (J[0][0] == 0)
                return 0;
            else
                if (J[0][1] == 0)
                    return 1;
                else
                    return 2;
        }
        else
            if (J[1][0] + J[1][1] + J[1][2] == 2 || J[1][0] + J[1][1] + J[1][2] == -2)
            {
                if (J[1][0] == 0)
                    return 10;
                else
                    if (J[1][1] == 0)
                        return 11;
                    else
                        return 12;
            }
            else
                if (J[2][0] + J[2][1] + J[2][2] == 2 || J[2][0] + J[2][1] + J[2][2] == -2)
                {
                    if (J[2][0] == 0)
                        return 20;
                    else
                        if (J[2][1] == 0)
                            return 21;
                        else
                            return 22;
                }
                else
                    if (J[0][0] + J[1][0] + J[2][0] == 2 || J[0][0] + J[1][0] + J[2][0] == -2)
                    {
                        if (J[0][0] == 0)
                            return 0;
                        else
                            if (J[1][0] == 0)
                                return 10;
                            else
                                return 20;
                    }
                    else
                        if (J[0][1] + J[1][1] + J[2][1] == 2 || J[0][1] + J[1][1] + J[2][1] == -2)
                        {
                            if (J[0][1] == 0)
                                return 1;
                            else
                                if (J[1][1] == 0)
                                    return 11;
                                else
                                    return 21;
                        }
                        else
                            if (J[0][2] + J[1][2] + J[2][2] == 2 || J[0][2] + J[1][2] + J[2][2] == -2)
                            {
                                if (J[0][2] == 0)
                                    return 2;
                                else
                                    if (J[1][2] == 0)
                                        return 12;
                                    else
                                        return 22;
                            }
                            else
                                if (J[0][0] + J[1][1] + J[2][2] == 2 || J[0][0] + J[1][1] + J[2][2] == -2)
                                {
                                    if (J[0][0] == 0)
                                        return 0;
                                    else
                                        if (J[1][1] == 0)
                                            return 11;
                                        else
                                            return 22;
                                }
                                else
                                    if (J[0][2] + J[1][1] + J[2][0] == 2 || J[0][2] + J[1][1] + J[2][0] == -2)
                                    {
                                        if (J[0][2] == 0)
                                            return 2;
                                        else
                                            if (J[1][1] == 0)
                                                return 11;
                                            else
                                                return 20;
                                    }
                                    else
                                        return obtemJogadaAleatoria(J);
}
int obtemJogadaTeclado( int J[3][3], int jogadas )
{
    int i, j;
    if (jogadas % 2 == 0)
    {
        printf("Jogador X: entre com linha e coluna da jogada.");
        scanf("%d %d", &i, &j );
        while( testaCasaVazia( J, i, j ) == 0 )
        {
            printf("esta posicao ja esta ocupada! escolha outra.");
            scanf("%d %d", &i, &j );
        }
    return i*10+j;
    }
    else
        return obtemJogadaInteligenteParaO(J);
}
int main()
{
	int J[3][3];
	int i,j, posicao;
	int jogadas = 0;
	for (i = 0;i < 3;i++)
    {
		for (j = 0;j < 3;j++)
			J[i][j] = 0;
	}
	while( jogadas < 9 )
    {
        /* Jogada do X */
		posicao = obtemJogadaTeclado( J, jogadas);
        i = posicao / 10;
        j = posicao % 10;
		J[i][j] = 1;
		jogadas ++;
		if( testaVencedor( J ) != 0 )
		{
			printf("Vencedor e o X!\n");
			imprimeTabuleiro(J);
			break;
		}
		if ( jogadas >= 9 )
			break;
        /* Jogada do O */
		posicao = obtemJogadaTeclado( J,jogadas);
        i = posicao / 10;
        j = posicao % 10;
        J[i][j] = -1;
		jogadas++;
		imprimeTabuleiro(J);
		if( testaVencedor( J ) != 0 )
		{
			printf("Vencedor e o O!\n");
			break;
		}
	}
	printf( "\nfim do jogo\n");
    return 0;
}
