#include<stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>


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
        
        printf("\n===== MENU DE CADASTRO =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto por ID\n");
        printf("4 - Atualizar produto\n");
        printf("5 - Remover produto\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        Sleep(500);
        system("cls");

        if (opcao == 1) { //Para cadastrar
            if (total >= 10) {

                system("cls");
                    printf("====================================\n");
                    printf("Limite maximo de registros atingido.\n");
                    printf("====================================\n");
                Sleep(1500);

            } else {
                int novoId, existe = 0;

                printf("Digite o ID do produto: ");
                scanf("%d", &novoId);

                if (novoId <= 0) {
                    system("cls");
                        printf("=================\n");
                        printf(" ID invalido [!]\n");
                        printf("=================\n");
                    Sleep(500);
                } else {
                    for (int i = 0; i < total; i++) {
                        if (produtos[i].id == novoId) {
                            existe = 1;
                        }
                    }

                    if (existe) {
                        system("cls");
                            printf("==========================\n");
                            printf("Erro: ID ja cadastrado [!]\n");
                            printf("==========================\n");
                        Sleep(500);

                    } else {
                        produtos[total].id = novoId;

                        printf("Digite o nome do produto: ");
                            scanf(" %[^\n]", produtos[total].nome);

                        printf("Digite o preco: ");
                            scanf("%f", &produtos[total].preco);

                        if (produtos[total].preco < 0) {
                            printf("Preco invalido.\n");
                        } else {
                            printf("Digite a quantidade: ");
                                scanf("%d", &produtos[total].quantidade);

                            if (produtos[total].quantidade < 0) {
                                system("cls");
                                    printf("=====================\n");
                                    printf("Quantidade invalida [!]\n");
                                    printf("=====================\n");
                                Sleep(500);
                            } else {
                                total++;
                                    printf("\n");
                                    printf("================================\n");
                                    printf("Produto cadastrado com sucesso !\n");
                                    printf("================================\n");
                                Sleep(1000);
                                system("cls");

                     }
                 }
            }
         }
    }

} else if (opcao == 2) { //para listar

    if (total == 0) {
        system("cls");
            printf("===========================\n");
            printf("Nenhum produto cadastrado.\n");
            printf("===========================\n");
        Sleep(500);
    } else {
        system("cls");
            printf("\n  %-5s  %-20s  %10s  %6s\n","ID", "Nome", "Preco(R$)", "Qtd");
            printf("  %-5s  %-20s    %10s  %6s\n","-----","--------------------","----------","------");
         for (int i = 0; i < total; i++) {
            printf("  %-5d  %-20s  %10.2f  %6d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade );            
        }
    printf("---------------------------------------------------------------------");
        Sleep(2500);
    }

} else if (opcao == 3) { //Para Buscar
            if (total == 0) {

                 system("cls");
                    printf("================================\n");
                    printf(" Produto nao encontrado.\n");
                    printf("================================\n");
                Sleep(500);
            } else {

                int buscaId;
                int encontrado = 0;

                printf("Digite o ID para buscar: ");
                scanf("%d", &buscaId);

                    for (int i = 0; i < total; i++) {
                        if (produtos[i].id == buscaId) {
                            system("cls");
                            printf("\n----- Produto encontrado: -----\n");
                            printf("Nome: %s  \n ", produtos[i].nome);
                            printf("Preco: %.2f \n ", produtos[i].preco);
                            printf("Quantidade: %d \n ", produtos[i].quantidade);
                            printf("\n--------------------------------\n");
                            Sleep(1500);
                         encontrado = 1;
                            }
                    }
                if (!encontrado) {
                    system("cls");
                        printf("===========================\n");
                        printf("Produto nao encontrado.\n");
                        printf("===========================\n");
                    Sleep(500);
                }
            }

} else if (opcao == 4) { // para Atualizar
            if (total == 0) {
                system("cls");
                    printf("=================================\n");
                    printf("Nao ha produtos para atualizar.\n");
                    printf("=================================\n");
                Sleep(500);
            } else {
                int atualizaId; 
                int encontrado = 0;
                system("cls");
                printf("Digite o ID do produto a atualizar: ");
                    scanf("%d", &atualizaId);

                for (int i = 0; i < total; i++) {
                    if (produtos[i].id == atualizaId) {

                        printf("Novo nome: ");
                            scanf(" %[^\n]", produtos[i].nome);

                        printf("Novo preco: ");
                            scanf("%f", &produtos[i].preco);

                        printf("Nova quantidade: ");
                            scanf("%d", &produtos[i].quantidade);

                        system("cls");
                            printf("================================\n");
                            printf("Produto atualizado com sucesso!\n");
                            printf("================================\n");
                        Sleep(500);
                            encontrado = 1;
                    }
                }

                if (!encontrado) {
                    system("cls");
                        printf("===========================\n");
                        printf("  Produto nao encontrado.\n");
                        printf("===========================\n");
                    Sleep(500);
                }
            }
        
        } else if (opcao == 5) { // Para REMOVER um prod
 if (total == 0) {
                 system("cls");
                    printf("=================================\n");
                    printf("  Nao ha produto para remover.\n");
                    printf("=================================\n");

            } else {
                int removeId;
                int pos = -1;

                    printf("\n");
                    system("cls");
                    printf("Digite o ID do produto para remover: ");
                        scanf("%d", &removeId);
                    printf("\n");

                for (int i = 0; i < total; i++) {
                    if (produtos[i].id == removeId) {
                        pos = i;
                    }
                }

                if (pos == -1) {
                    printf("\n");
                    system("cls");
                    printf("=================================\n");
                    printf("    Produto nao encontrado.\n");
                    printf("=================================\n");
                    printf("\n");

                } else {
                    for (int i = pos; i < total - 1; i++) {
                        produtos[i] = produtos[i + 1];
                    }
                    total--;
                    
                    system("cls");
                    printf("=================================\n");
                    printf("Produto removido com sucesso!\n");
                    printf("=================================\n");
                    printf("\n");
                }
            }

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