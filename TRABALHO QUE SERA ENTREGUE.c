#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>

int main(void)
{
    char linha[3][3] = {"1", "2", "3"};
    char coluna[3][3] = {"A","B","C"};
    char Matriz[3][3],c[3],auxj;
    char O='O', X='X';
    int n=0,j,i,op,maquinal,maquinac,p;

    srand(time(NULL));

    do// vai permetir a pessoa continuar jogando ate que nao quiser mais
    {
       for(j=0;j<3;j++)
            for(i=0;i<3;i++)
                Matriz[i][j] = '\0';
        n=0;

        system("cls");

        printf("JOGO DA VELHA \n\n");
        printf("1-SINGLE PLAYER \n2-MULTIPLAYER\n");
        scanf(" %d",&op);

        system("cls");

        while (op != 1 && op != 2)  //looping caso o usuario digite o opcao errada
        {
            fflush(stdin);
            printf("OPCAO INVALIDA SEU BURRO \n\n");
            printf("1-SINGLE PLAYER \n2-MULTIPLAYER\n");
            scanf("%d",&op);

            system("cls");
        }


        switch(op)
        {
            case 1: // jogo da velha para 1 jogador apenas

                p=rand()%2; // condicao para ver se maquina ou o usuario some;a
                if(p == 0) // usuario comeca
                {
                    for(i=0;i<3;i++)
                        for(j=0;j<3;j++)
                            Matriz[i][j]=' ';

                    while(n<=9)
                    {
                        printf("  JOGO DA VELHA \n");

                        for(j=0;j<3;j++)
                        printf("    %s" ,coluna[j]);
                        printf("\n");

                        for(i=0;i<3;i++)
                        {
                            printf("%s",linha[i]);
                            printf("    %c \xBA %c \xBA %c\n",Matriz[i][0],Matriz[i][1],Matriz[i][2]); // foi usado caracter especial para construir o jogo da velha
                            if(i<3-1)                                                                   // \x mostra caracter hexadeciaml nesse caso Ba da o efeito entra as coluna
                            {
                                printf("    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n"); // o Í da o efeito da linha e o / xCE o efeito das interseccoes entre linha e colunas
                            }
                        }

                        printf("\nINSIRA AS COORDENADAS, ");
                        if(n%2 == 0) // diz se eh o usuario ou a maquina jogando baseado no resto do numero da jogada (vai de 0 a 8
                        {
                            printf("PLAYER \nLINHA: ");
                            auxj = j ;
                            scanf("%d",&i);
                            printf("COLUNA: ");
                            fflush(stdin);
                            scanf("%c",&c[0]);
                            fflush(stdin);
                            j=c[0];
                            if (j > 90) // conversao das letras em numero para preenchimento da matriz
                                j -= 96;
                            else
                                j -= 64;
                        }
                        else //jogada da maquina
                        {
                            auxj=j;
                            maquinal=rand()%10;
                            i= maquinal;
                            maquinac=rand()%10;
                            j=maquinac;

                        }


                        system("cls");

                        if(Matriz[i-1][j-1]==' ')// sistema de preenchimento
                        {
                            if(n%2 != 0) // numero da jogada, diz se eh o usuario ou a maquina jogando
                                Matriz[i-1][j-1]=X; // como a matriz vai de 0 a 2, e as coordenadas  disponiveis vao de 1 a 3 subtrai 1 de I e de J
                            else
                                Matriz[i-1][j-1]=O;
                            n++;
                        }


                        if((Matriz[0][0]==O && Matriz[0][1]==O && Matriz[0][2]==O)||
                           (Matriz[1][0]==O && Matriz[1][1]==O && Matriz[1][2]==O)||
                           (Matriz[2][0]==O && Matriz[2][1]==O && Matriz[2][2]==O)||
                           (Matriz[0][0]==O && Matriz[1][0]==O && Matriz[2][0]==O)||
                           (Matriz[0][1]==O && Matriz[1][1]==O && Matriz[2][1]==O)||
                           (Matriz[0][2]==O && Matriz[1][2]==O && Matriz[2][2]==O)||
                           (Matriz[0][0]==O && Matriz[1][1]==O && Matriz[2][2]==O)||
                           (Matriz[0][2]==O && Matriz[1][1]==O && Matriz[2][0]==O))
                        {
                            printf("\n\aVOCE VENCEU PARABENS!!!");
                            break;
                        }
                        if((Matriz[0][0]==X && Matriz[0][1]==X && Matriz[0][2]==X)||
                           (Matriz[1][0]==X && Matriz[1][1]==X && Matriz[1][2]==X)||
                           (Matriz[2][0]==X && Matriz[2][1]==X && Matriz[2][2]==X)||
                           (Matriz[0][0]==X && Matriz[1][0]==X && Matriz[2][0]==X)||
                           (Matriz[0][1]==X && Matriz[1][1]==X && Matriz[2][1]==X)||
                           (Matriz[0][2]==X && Matriz[1][2]==X && Matriz[2][2]==X)||
                           (Matriz[0][0]==X && Matriz[1][1]==X && Matriz[2][2]==X)||
                           (Matriz[0][2]==X && Matriz[1][1]==X && Matriz[2][0]==X))
                        {
                            printf("\n\aA MAQUINA VENCEU!!!");
                            break;
                        }

                        if(n==9)
                        {
                            printf("PARTIDA EMPATADA");
                            break;
                        }
                    }
            }
            else // maquina comecando o jogo, basicamente igual ao anterior mas com a maquina comecando
            {
                for(i=0;i<3;i++)
                    for(j=0;j<3;j++)
                        Matriz[i][j]=' ';

                while(n<=9)
                {
                    printf("  JOGO DA VELHA \n");

                    for(j=0;j<3;j++)
                        printf("    %s" ,coluna[j]);
                    printf("\n");

                    for(i=0;i<3;i++)
                    {
                        printf("%s",linha[i]);
                        printf("    %c \xBA %c \xBA %c\n",Matriz[i][0],Matriz[i][1],Matriz[i][2]); // foi usado caracter especial para construir o jogo da velha
                        if(i<3-1)                                                                   // \x mostra caracter hexadeciaml nesse caso Ba da o efeito entra as coluna
                        {
                            printf("    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n"); // o Í da o efeito da linha e o / xCE o efeito das interseccoes entre linha e colunas
                        }
                    }

                    printf("\nINSIRA AS COORDENADAS, ");
                    if(n%2 != 0) // parte que defere da primeira parte do programa. nesse ponto a vez do usurario sera quando o resto de n for diferente de 0
                    {
                        printf("PLAYER \nLINHA: ");
                        auxj = j ;
                        scanf("%d",&i);
                        printf("COLUNA: ");
                        fflush(stdin);
                        scanf("%c",&c[0]);
                        fflush(stdin);
                        j=c[0];
                        if (j > 90)
                            j -= 96;
                        else
                            j -= 64;
                    }
                    else
                    {
                        auxj=j;
                        maquinal=rand()%10;
                        i= maquinal;
                        maquinac=rand()%10;
                        j=maquinac;

                    }


                    system("cls");

                    if(Matriz[i-1][j-1]==' ')
                    {
                        if(n%2 == 0)
                            Matriz[i-1][j-1]=X;
                        else
                            Matriz[i-1][j-1]=O;
                        n++;
                    }


                    if((Matriz[0][0]==O && Matriz[0][1]==O && Matriz[0][2]==O)||
                       (Matriz[1][0]==O && Matriz[1][1]==O && Matriz[1][2]==O)||
                       (Matriz[2][0]==O && Matriz[2][1]==O && Matriz[2][2]==O)||
                       (Matriz[0][0]==O && Matriz[1][0]==O && Matriz[2][0]==O)||
                       (Matriz[0][1]==O && Matriz[1][1]==O && Matriz[2][1]==O)||
                       (Matriz[0][2]==O && Matriz[1][2]==O && Matriz[2][2]==O)||
                       (Matriz[0][0]==O && Matriz[1][1]==O && Matriz[2][2]==O)||
                       (Matriz[0][2]==O && Matriz[1][1]==O && Matriz[2][0]==O))
                    {
                        printf("\n\aVOCE VENCEU PARABENS!!!");
                        break;
                    }
                    if((Matriz[0][0]==X && Matriz[0][1]==X && Matriz[0][2]==X)||
                       (Matriz[1][0]==X && Matriz[1][1]==X && Matriz[1][2]==X)||
                       (Matriz[2][0]==X && Matriz[2][1]==X && Matriz[2][2]==X)||
                       (Matriz[0][0]==X && Matriz[1][0]==X && Matriz[2][0]==X)||
                       (Matriz[0][1]==X && Matriz[1][1]==X && Matriz[2][1]==X)||
                       (Matriz[0][2]==X && Matriz[1][2]==X && Matriz[2][2]==X)||
                       (Matriz[0][0]==X && Matriz[1][1]==X && Matriz[2][2]==X)||
                       (Matriz[0][2]==X && Matriz[1][1]==X && Matriz[2][0]==X))
                    {
                        printf("\n\aA MAQUINA VENCEU!!!");
                        break;
                    }

                    if(n==9)
                    {
                        printf("PARTIDA EMPATADA");
                        break;
                    }
                }
            }
            break;



            case 2: // jogo da velha para dois jogadores,
                for(i=0;i<3;i++)
                    for(j=0;j<3;j++)
                        Matriz[i][j]=' ';

                while(n<=9)
                    {
                        printf("  JOGO DA VELHA \n");

                        for(j=0;j<3;j++)
                            printf("    %s" ,coluna[j]);
                        printf("\n");

                        for(i=0;i<3;i++)
                        {
                            printf("%s",linha[i]);
                            printf("    %c \xBA %c \xBA %c\n",Matriz[i][0],Matriz[i][1],Matriz[i][2]); // foi usado caracter especial para construir o jogo da velha
                            if(i<3-1)                                                                   // \x mostra caracter hexadeciaml nesse caso Ba da o efeito entra as coluna
                            {
                                printf("    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n"); // o Í da o efeito da linha e o / xCE o efeito das interseccoes entre linha e colunas
                            }
                        }

                        printf("\nINSIRA AS COORDENADAS, ");
                        if(n%2 == 0) //mesma coisa que o resto do programa, entretanto, o if e o else vem antes da entrata das coordenadas
                            printf("PLAYER 1\nLINHA: ");
                        else
                            printf("PLAYER 2\nLINHA: ");

                        auxj = j ;
                        scanf("%d",&i);
                        printf("COLUNA: ");
                        fflush(stdin);
                        scanf("%c",&c[0]);
                        fflush(stdin);
                        j=c[0];
                        if (j > 90)
                            j -= 96;
                        else
                            j -= 64;


                        system("cls");

                        if(Matriz[i-1][j-1]==' ')
                        {
                            if(n%2 != 0)
                                Matriz[i-1][j-1]=X;
                            else
                                Matriz[i-1][j-1]=O;
                            n++;
                        }


                        if((Matriz[0][0]==O && Matriz[0][1]==O && Matriz[0][2]==O)||
                            (Matriz[1][0]==O && Matriz[1][1]==O && Matriz[1][2]==O)||
                            (Matriz[2][0]==O && Matriz[2][1]==O && Matriz[2][2]==O)||
                            (Matriz[0][0]==O && Matriz[1][0]==O && Matriz[2][0]==O)||
                            (Matriz[0][1]==O && Matriz[1][1]==O && Matriz[2][1]==O)||
                            (Matriz[0][2]==O && Matriz[1][2]==O && Matriz[2][2]==O)||
                            (Matriz[0][0]==O && Matriz[1][1]==O && Matriz[2][2]==O)||
                            (Matriz[0][2]==O && Matriz[1][1]==O && Matriz[2][0]==O))
                        {
                            printf("\n\aJogador 1, VOCE VENCEU!!!");
                            break;
                        }
                        if((Matriz[0][0]==X && Matriz[0][1]==X && Matriz[0][2]==X)||
                            (Matriz[1][0]==X && Matriz[1][1]==X && Matriz[1][2]==X)||
                            (Matriz[2][0]==X && Matriz[2][1]==X && Matriz[2][2]==X)||
                            (Matriz[0][0]==X && Matriz[1][0]==X && Matriz[2][0]==X)||
                            (Matriz[0][1]==X && Matriz[1][1]==X && Matriz[2][1]==X)||
                            (Matriz[0][2]==X && Matriz[1][2]==X && Matriz[2][2]==X)||
                            (Matriz[0][0]==X && Matriz[1][1]==X && Matriz[2][2]==X)||
                            (Matriz[0][2]==X && Matriz[1][1]==X && Matriz[2][0]==X))
                        {
                            printf("\n\aJogador 2, VOCE VENCEU!!!");
                            break;
                        }

                        if(n==9)
                            {
                                printf("\PARTIDA EMPATADA");
                                break;
                            }

                    }
                  break;
            }
        printf("\n\n deseja continuar? (s/n):");


    }
    while (getch()== 's');
    return 0;
}

