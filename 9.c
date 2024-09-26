#include <stdio.h>
#define TAM 10

int d[TAM], di[TAM];

int main()
{
    for (int i=0; i<TAM; i++)
    {
        scanf("%d", &d[i]);
        di[i] = d[i];
        if(i >= TAM/2) di[i-TAM/2] = d[i];
    }
    for (int i=0; i<TAM; i++)
    {
        if(i<= TAM/2 - 1)
        {
            printf("%d ", di[i]);
        }
        else
        {
            printf("%d ", d[i-TAM/2]);
        }
    }
    return 0;
}
