#include <stdio.h>

#define MAX_USERS 10
#define TAM_NOME 30

int qtd_user, jaExiste = 0;
int codigo[MAX_USERS] = {0}, deposito[MAX_USERS];
char nome[MAX_USERS][TAM_NOME];

void verificarNome()
{
    for(int i=0; i<qtd_user; i++)
    {
        if(nome[qtd_user][0] == nome[i][0])
        {
            printf("\nEsse nome ja existe! %s\n", nome[qtd_user]);
            jaExiste = 1;
        }
    }
}

void verificarCodigo()
{
    for(int i=0; i<qtd_user; i++)
    {
        if(codigo[qtd_user] == codigo[i])
        {
            printf("\nEsse codigo ja existe!\n");
            jaExiste = 1;
        }
    }
}

void cadastrarUsuario()
{
    if(qtd_user <= 9)
    {
        printf("\nInsira codigo: ");
        scanf(" %d", &codigo[qtd_user]);
        verificarCodigo();

        if(!jaExiste)
        {
            printf("Insira nome: ");
            scanf(" %[^\n]s", nome[qtd_user]);
            verificarNome();

            if(!jaExiste)
            {
                printf("Insira saldo inicial: ");
                scanf("%d", &deposito[qtd_user]);
                qtd_user++;
            }
        }
        jaExiste = 0;
    }
    else
    {
        printf("\nNao e permitido cadastrar mais usuarios.\n");
    }
}

void efetuarDeposito()
{
    int verCodigo, indexCodigo=-1, valorDeposito;
    printf("Insira seu codigo para efetuar deposito: ");
    scanf("%d", &verCodigo);

    for(int i=0; i<qtd_user; i++)
    {
        if(verCodigo == codigo[i])
        {
            indexCodigo = i;
        }
    }
    if(indexCodigo != -1)
    {
        printf("Nome: %s\nSaldo: %d\n", nome[indexCodigo], deposito[indexCodigo]);
        printf("Insira o valor do deposito: ");
        scanf("%d", &valorDeposito);
        deposito[indexCodigo] = deposito[indexCodigo] + valorDeposito;
        printf("Novo saldo: %d.\n", deposito[indexCodigo]);
    }
    else
    {
        printf("Essa conta nao existe!\n");
    }
}

void efetuarSaque()
{
    int verCodigo, indexCodigo=-1, valorSacado;
    printf("Insira seu codigo para efetuar saque: ");
    scanf("%d", &verCodigo);

    for(int i=0; i<qtd_user; i++)
    {
        if(verCodigo == codigo[i])
        {
            indexCodigo = i;
        }
    }
    if(indexCodigo != -1)
    {
        printf("Nome: %s\nSaldo: %d\n", nome[indexCodigo], deposito[indexCodigo]);
        printf("Insira o valor do saque: ");
        scanf("%d", &valorSacado);
        if(valorSacado <= deposito[indexCodigo])
        {
            deposito[indexCodigo] = deposito[indexCodigo] - valorSacado;
            printf("Novo saldo: %d.\n", deposito[indexCodigo]);
        }
        else
        {
            printf("Seu saldo nao e suficiente para cobrir o saque.\n");
        }
    }
    else
    {
        printf("Essa conta nao existe!\n");
    }
}

void consultarAtivoBancario()
{
    int ativoBancario = 0;
    for(int i=0; i<qtd_user; i++)
    {
        ativoBancario += deposito[i];
    }
    printf("Ativo bancario: %d.\n", ativoBancario);
}

void menu()
{
    int op;
    do
    {
        printf("\nMENU\n");
        printf("1 - Cadastrar\n");
        printf("2 - Efetuar deposito\n");
        printf("3 - Efetuar saque\n");
        printf("4 - Consultar o ativo bancario\n");
        printf("5 - Finalizar o programa\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1: cadastrarUsuario(); break;
            case 2: efetuarDeposito(); break;
            case 3: efetuarSaque(); break;
            case 4: consultarAtivoBancario(); break;
            case 5: printf("Finalizando o programa...\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
    } while (op != 5);
}

int main()
{
    menu();
    return 0;
}
