#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

void Entrada();

struct Autenticacao
{
    int usuario;
    int senha;
};

struct Autenticacao a1 = { 4258,123456 };

void cabecalho();
void cadastraProd();

struct produto
{
    char nome[50];
    char descricao[50];
    char categoria[50];
    float preco;
    int qntd;
};

struct produto estoque[50];
int produtosCadastrados = 0;

void BuscaProd();
void EstoqueProd();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n;
    char resposta[30];
    struct Autenticacao vet;

    do
    {
        Entrada();
        printf("Informe o seu usuário: \n");
        scanf("%d", &vet.usuario);
        printf("Informe a sua senha: \n");
        scanf("%d", &vet.senha);
        system("cls");

    }
    while (vet.usuario!=a1.usuario && vet.senha!=a1.senha);

    cabecalho();

    return 0;
}

void Entrada()
{


    printf("******************************************* \n");
    printf("SISTEMA DE GESTÃO DE ESTOQUE - FARMÁCIA XWY \n");
    printf("******************************************* \n");
    printf("------------AUTENTICAÇÃO DE USUÁRIO-------- \n");

}

void cabecalho()
{
    char sair[5];
    int n;
    printf("******************************************* \n");
    printf("SISTEMA DE GESTÃO DE ESTOQUE - FARMÁCIA XWY \n");
    printf("******************************************* \n");
    printf("--------------CONTROLE DE ESTOQUE---------- \n");
    printf("1- Cadastro de produto; \n");
    printf("2- Busca de produto; \n");
    printf("3- Exibir estoque de produtos; \n");
    printf("4- Sair do programa. \n");

    scanf("%d", &n);
    getchar();

    switch (n)
    {

    case 1:
        system("cls");
        cadastraProd();
        system("cls");
        cabecalho();
        break;
    case 2:
        system("cls");
        BuscaProd();

        cabecalho();
        break;
    case 3:
        system("cls");
        EstoqueProd();
        cabecalho();
        break;
    case 4:
        printf("Deseja realmente sair? [sim/não] \n");
        fgets(sair, 5, stdin);
        sair[strcspn(sair, "\n")] = '\0';
        if (strcmp(sair,"sim")==0)
        {
            exit(1);
        }
        else
        {
            cabecalho();
        }
        break;
    default:
        printf("Opção inválida. Tente novamente.\n");
        cabecalho();
        break;
    }
}

void cadastraProd()
{
    printf("******************************************* \n");
    printf("SISTEMA DE GESTÃO DE ESTOQUE - FARMÁCIA XWY \n");
    printf("******************************************* \n");
    printf("--------------CADASTRO DE PRODUTO---------- \n");
    int cadastro=1;
    while(cadastro)
    {
        printf("Informe o nome do produto: ");
        fgets(estoque[produtosCadastrados].nome, 50, stdin);

        printf("Informe a descrição do produto: ");
        fgets(estoque[produtosCadastrados].descricao, 50, stdin);

        printf("Informe a categoria: ");
        fgets(estoque[produtosCadastrados].categoria, 50, stdin);

        printf("Informe a quantidade: ");
        scanf("%d", &estoque[produtosCadastrados].qntd);

        printf("Informe o preço do produto: ");
        scanf("%f", &estoque[produtosCadastrados].preco);

        printf("Produto cadastrado com sucesso! \n");
        produtosCadastrados++;
        getchar();

        printf("Deseja cadastrar mais algum? [1] - SIM, [0] - NÃO \n");
        scanf("%d", &cadastro);
        getchar();
    }

}
void BuscaProd()
{
    printf("******************************************* \n");
    printf("SISTEMA DE GESTÃO DE ESTOQUE - FARMÁCIA XWY \n");
    printf("******************************************* \n");
    printf("--------------BUSCA DE PRODUTO---------- \n");

    char BUSCA[50];
    int i;
    int encontrou=0;
    int procurar=1;


    while (procurar)
    {
        printf("Digite o nome do produto para buscar no estoque: ");
        fgets(BUSCA, 50, stdin);

        for (int i=0; i < produtosCadastrados; i++)
        {
            if (strcmp (BUSCA, estoque[i].nome)==0)
            {
                encontrou = 1;
                procurar=0;
                break;
            }
        }

        if (encontrou)
        {
            printf("Nome: %s", estoque[i].nome);
            printf("Descrição do produto: %s", estoque[i].descricao);
            printf("Categoria do produto: %s", estoque[i].categoria);
            printf("Quantidade do produto: %d \n", estoque[i].qntd);
            printf("Preço do produto: %.2f \n", estoque[i].preco);
            printf("\n");
        }
        else
        {
            printf("O produto não foi encontrado, deseja continuar buscando? [1] - SIM, [0] - NÃO \n");
            scanf("%d", &procurar);
            getchar();

        }
    }
}

void EstoqueProd()
{
    int exibe=0;

    while(exibe==0)
    {
        if(produtosCadastrados>0)
        {
            for (int i=0; i < produtosCadastrados; i++)
            {

                printf(" Nome: %s ", estoque[i].nome);
                printf("Descrição do produto: %s ", estoque[i].descricao);
                printf("Categoria do produto: %s ", estoque[i].categoria);
                printf("Quantidade do produto: %d \n", estoque[i].qntd);
                printf(" Preço do produto: %.2f \n", estoque[i].preco);
                printf("\n");
            }
            exibe=1;
        }
        else
        {
            printf("Nenhum produto cadastrado. \nDeseja voltar ao menu de controle de estoque? [1] - SIM, [0] - NÃO \n");
            scanf("%d", &exibe);
        }
    }
}
