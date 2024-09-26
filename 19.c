#include <stdio.h>

#define TAM 6
#define TAM2 3

int main()
{
    int v10[TAM], v5[TAM2]={0}, r1[TAM2], r2[TAM2];
    int qtd_pares=0, qtd_divisores=0, par, qtd_impar=0;

    for(int i=0; i<TAM; i++) {
        scanf("%d", &v10[i]);
    }

    for(int i=0; i<TAM2; i++) {
        scanf("%d", &v5[i]);
    }

    for(int m=0; m<TAM; m++) {
        par = 0;
        if(v10[m] % 2 == 0) {
            par = v10[m];
            for(int k=0; k<TAM2; k++) {
                par += v5[k];
            }
            r1[qtd_pares] = par;
            qtd_pares++;
        }
    }

    printf("r1: ");
    for(int i=0; i<qtd_pares; i++) {
        printf("%d ", r1[i]);
    }

    for(int i=0; i<TAM; i++) {
        if(v10[i] % 2 != 0) {
            for(int j=0; j<TAM2; j++) {
                if(v10[i] % v5[j] == 0) {
                    qtd_divisores++;
                }
            }
            r2[qtd_impar] = qtd_divisores;
            qtd_impar++;
        }
        qtd_divisores = 0;
    }

    printf("\nr2: ");
    for(int b=0; b<qtd_impar; b++) {
        printf("%d ", r2[b]);
    }

    return 0;
}
