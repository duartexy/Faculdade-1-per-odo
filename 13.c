#include <stdio.h>

#define TAM 3

int main()
{
    char nome[TAM][10];
    int media[TAM], maior_media=-1, media_alunos_nao_aprovados[TAM];
    int qtd_alunos_nao_aprovados=0, nota_restante[TAM]= {0}, nome_restante[TAM];

    for(int i=0; i<TAM; i++)
    {
        scanf(" %s", nome[i]);
        scanf(" %d", &media[i]);
    }


    for(int i=0; i<TAM; i++)
    {
        //aluno com maior media
        if(media[i] > maior_media) maior_media = media[i];

        if(media[i] < 7)
        {
            media_alunos_nao_aprovados[qtd_alunos_nao_aprovados] = media[i];
            nota_restante[qtd_alunos_nao_aprovados] = 7 - media[i];
            nome_restante[qtd_alunos_nao_aprovados] = nome[i];
            qtd_alunos_nao_aprovados++;
        }
    }


    printf("\nMaior media: %d.\n", maior_media);
    for(int i=1; i<=qtd_alunos_nao_aprovados+1; i++)
    {
        if(nota_restante[i-1] != 0)
        {
            printf("Aluno %s precisa tirar %d para passar na media final.\n", nome_restante[i-1], nota_restante[i-1]);
        }
        else
        {
            printf("Nenhum aluno reprovou.");
        }
    }

    return 0;
}
