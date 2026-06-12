#include<stdio.h>
#include <string.h>
#include <windows.h>

int main() {

    
    struct Produto {
        int id;
        char nome[50];
        float preco;
        int quantidade;
    };

    struct Produto produtos[10];
    int total = 0;
    int opcao;

    do {
        Sleep(1000);
        printf("\n===== MENU DE CADASTRO =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto por ID\n");
        printf("4 - Atualizar produto\n");
        printf("5 - Remover produto\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        Sleep(500);

        if (opcao == 1) { //Para cadastrar

            if (total >= 10) {
                printf("Limite maximo de registros atingido.\n");
            } else {

                int novoId = 0;
                int existe = 0;

                printf("Digite o ID do produto: ");
                scanf("%d", &novoId);

                if (novoId <= 0) {
                    printf("ID invalido.\n");
                } else {
                    for (int i = 0; i < total; i++) {
                        if (produtos[i].id == novoId) {
                            existe = 1;
                        }
                    }

                    if (existe) {
                        printf("Erro: ID ja cadastrado.\n");
                    } else {
                        produtos[total].id = novoId;

                        printf("Digite o nome do produto: ");
                        produtos[total].id = novoId;

                        printf("Digite o preco: ");
                        scanf("%f", &produtos[total].preco);

                        if (produtos[total].preco < 0) {
                            printf("Preco invalido.\n");
                        } else {
                            printf("Digite a quantidade: ");
                            scanf("%d", &produtos[total].quantidade);

                            if (produtos[total].quantidade < 0) {
                                printf("Quantidade invalida.\n");
                            } else {
                                total++;
                                printf("Produto cadastrado com sucesso!\n");
                            }
                        }}}}

        } else if (opcao == 2) { //para listar

            if (total == 0) {
                printf("Nenhum produto cadastrado.\n");


            } else {
                printf("\n  %-5s  %-20s  %10s  %6s\n","ID", "Nome", "Preco(R$)", "Qtd");
                printf("  %-5s  %-20s    %10s  %6s\n","-----","--------------------","----------","------");
                for (int i = 0; i < total; i++) {
                    printf("  %-5d  %-20s  %10.2f  %6d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade );
                    Sleep(500);
                }
            }

       } else if (opcao == 3) { // BUSCAR


        } else if (opcao == 4) { // ATUALIZAR

        
        } else if (opcao == 5) { // REMOVER

        } else if (opcao == 0) {

            printf("S\t"); //Aqui foi por pura estetica :)
            Sleep(300);
            printf("A\t");
            Sleep(300);
            printf("I\t");
            Sleep(300);
            printf("N\t");
            Sleep(300);
            printf("D\t");
            Sleep(300);
            printf("O\t");
            Sleep(300);
            printf(".\t");
            Sleep(300);
            printf(".\t");
            Sleep(300);
            printf(".\t");
        } else {
            printf("\n");
            printf("---------------------------------------\n");
            printf(" [!] Opcao invalida. Tente novamente.\n");
            printf("---------------------------------------\n");
            Sleep(500);
        }

    } while (opcao != 0);

    return 0;
}