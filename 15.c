#include <stdio.h>
#include <string.h>

int main()
{
    int tam1, tam2;
    scanf("%d%d", &tam1, &tam2);
    if(tam1 < tam2) printf("Nao e possivel copiar");
    else
    {
        char s1[tam1+1], s2[tam2+1];
        scanf(" %[^\n]", s1);
        scanf(" %[^\n]", s2);
        strcpy(s1, s2);
        printf("%s", s1);
    }

    return 0;
}
