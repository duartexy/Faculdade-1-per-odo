#include <stdio.h>
#define TAM 3

int main()
{
    int a, v[TAM][TAM], x[TAM * TAM]={0}, cont=0, index=0;
    scanf("%d", &a);

    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }

    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            if(v[i][j] != a)
            {
                x[index++] = v[i][j];
            }
            else cont++;
        }
    }

    for(int i=0; i<TAM*TAM - cont; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n%d apareceu %d vezes.", a, cont);
    return 0;
}
