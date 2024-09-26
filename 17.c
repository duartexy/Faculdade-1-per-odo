#include <stdio.h>
#include <string.h>

#define TAM 30

int main()
{
    char s[TAM], p1[TAM/2], p2[TAM/2];
    int length;
    float index;
    scanf("%[^\n]", s);
    length = strlen(s);
    index = length-1;
    index/=2;

    for(int i=0; i<length/2; i++)
    {
        p1[i] = s[(int)index];
        index--;
    }
    printf("%s", p1);

    index = length-1;
    for(int i=0; i<length/2; i++)
    {
        p2[i] = s[(int)index];
        index--;
    }
    printf("%s", p2);

    return 0;
}
