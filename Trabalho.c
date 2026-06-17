#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifdef _WIN32  //caso seja no windows ele usa essa biblioteca <windows.h>
    #include <windows.h>
    #define PAUSA(ms) Sleep(ms)
    #define LIMPAR() system("cls")
#else  // se não ele usa essa outra <unistd.h> :)
    #include <unistd.h>
    #define PAUSA(ms) usleep((ms) * 1000)
    #define LIMPAR() system("clear")
#endif

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
                //menu de opções padrão
        printf("\n===== MENU DE CADASTRO =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto por ID\n");
        printf("4 - Atualizar produto\n");
        printf("5 - Remover produto\n");
        printf("0 - Sair\n");
        printf("=================================\n");
        printf("Escolha uma opcao: ");
            if (scanf("%d", &opcao) != 1) {   //teste para eceber valores positivos.
                printf("\nEntrada invalida!\n");
                while (getchar() != '\n');
                    opcao = -1;
                PAUSA(500);
                LIMPAR();
            continue;
        }

        LIMPAR();
        if (opcao == 1) { //Para cadastrar

            if (total >= 10) {
                LIMPAR();
                    printf("====================================\n");
                    printf("Limite maximo de registros atingido.\n"); // caso ja tenha feito os 10 cadastros.
                    printf("====================================\n");
                PAUSA(1500);

            } else {

                    int novoId;
                    int existe = 0;

                    printf("Digite o ID do produto: ");
                        if (scanf("%d", &novoId) != 1) {
                        while (getchar() != '\n');
                    LIMPAR();
                        printf("=================\n");
                        printf(" ID invalido [!]\n"); //teste para numeros inteiros
                        printf("=================\n");
                    PAUSA(500);
                    continue;

                } if (novoId <= 0) {
                    LIMPAR();
                        printf("===========================\n");
                        printf("ID deve ser maior que zero.\n"); // teste para nº > 0
                        printf("===========================\n");
                    PAUSA(500);
                    continue;
                }

                for (int i = 0; i < total; i++) {
                    if (produtos[i].id == novoId) {
                        existe = 1;
                    }
                }

                if (existe) {
                    LIMPAR();
                        printf("==========================\n");
                        printf("Erro: ID ja cadastrado [!]\n"); //caso repita o ID
                        printf("==========================\n");
                    PAUSA(500);
                    continue;
                }

                produtos[total].id = novoId;

                printf("Digite o nome do produto: ");
                    scanf(" %[^\n]", produtos[total].nome);

                printf("Digite o preco: ");
                    if (scanf("%f", &produtos[total].preco) != 1 || produtos[total].preco < 0) {
                        while (getchar() != '\n');
                        printf("==========================\n");
                        printf("Preco invalido.[!]\n"); //esses usuarios... tem que ficar ligeiro kkkkkkk
                                                        // teste para preço negativo
                        printf("==========================\n");
                    PAUSA(500);
                    LIMPAR();
                    continue;
                }

                printf("Digite a quantidade: ");
                if (scanf("%d", &produtos[total].quantidade) != 1 || produtos[total].quantidade < 0) {
                    while (getchar() != '\n');
                    LIMPAR();
                        printf("=====================\n");
                        printf("Quantidade invalida [!]\n"); //quantidade até 0 vai, porem > não passa
                        printf("=====================\n");
                    PAUSA(500);
                    continue;
                }

                total++;
                LIMPAR();
                    printf("\n");
                    printf("================================\n");
                    printf("Produto cadastrado com sucesso !\n");
                    printf("================================\n");
                PAUSA(1200);
                
            }
        } else if (opcao == 2) { //para listar

            if (total == 0) {
                LIMPAR();
                    printf("===========================\n");
                    printf("Nenhum produto cadastrado.\n");  // caso n foi realizado cadastro
                    printf("===========================\n");
                PAUSA(500);
            }else {
                LIMPAR();
            printf("\n  %-5s  %-20s  %10s  %6s\n","ID", "Nome", "Preco(R$)", "Qtd");
            printf("  %-5s  %-20s    %10s  %6s\n","-----","--------------------","----------","------");
                for (int i = 0; i < total; i++) {
                    printf("  %-5d  %-20s  %10.2f  %6d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade );            
            }
                    printf("---------------------------------------------------------------------");
                        PAUSA(3000); //tempo para visualizar os intens cadastrados
                }
    }else if (opcao == 3) { //Para Buscar

            if (total == 0) {
                LIMPAR();
                    printf("================================\n");
                    printf(" Produto nao encontrado.\n"); //caso não ache prod
                    printf("================================\n");
                PAUSA(500);
            }
            else {

                int buscaId;
                int encontrado = 0;

                printf("Digite o ID para buscar: ");
                    if (scanf("%d", &buscaId) != 1) {
                        while (getchar() != '\n'); //outro teste de valor negativo
                    printf("Entrada invalida.\n");
                    PAUSA(500);
                    LIMPAR();
                    continue;
                }

                for (int i = 0; i < total; i++) {
                    if (produtos[i].id == buscaId) {
                        printf("\n----- Produto encontrado: -----\n");
                        printf("ID: %d\n", produtos[i].id);
                        printf("Nome: %s\n", produtos[i].nome);
                        printf("Preco: %.2f\n", produtos[i].preco);
                        printf("Quantidade: %d\n", produtos[i].quantidade);
                        printf("\n--------------------------------\n");
                        PAUSA(2000); //tempo para ver o item achado
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    LIMPAR();
                        printf("===========================\n");
                        printf("Produto nao encontrado.\n"); // caso não ache o ID
                        printf("===========================\n");
                    LIMPAR();
                }                
            }
        }

        else if (opcao == 4) { // para Atualizar
            if (total == 0) {
                LIMPAR();
                    printf("=================================\n");
                    printf("Nao ha produtos para atualizar.\n");
                    printf("=================================\n");
                PAUSA(500);

            }else {
                int idAtualizar;
                int encontrado = 0;
                LIMPAR();
                printf("Digite o ID do produto a atualizar: ");
                if (scanf("%d", &idAtualizar) != 1) {
                    while (getchar() != '\n');
                        printf("Entrada invalida.\n"); //teste caso tente att com valor negativo
                        PAUSA(500);
                        LIMPAR();
                    continue;
                }

                for (int i = 0; i < total; i++) {
                    if (produtos[i].id == idAtualizar) {
                        encontrado = 1;

                        printf("Novo nome: ");
                            scanf(" %[^\n]", produtos[i].nome);

                        printf("Novo preco: ");
                            if (scanf("%f", &produtos[i].preco) != 1 || produtos[i].preco < 0) {
                                while (getchar() != '\n');  // //teste caso tente att com valor negativo
                                    printf("Preco invalido.\n");
                                    PAUSA(1000);
                                    LIMPAR();
                            break;
                        }

                        printf("Nova quantidade: ");
                            if (scanf("%d", &produtos[i].quantidade) != 1 || produtos[i].quantidade < 0) {
                                while (getchar() != '\n'); // teste caso tente att com valor negativo
                                    printf("Quantidade invalida.\n");
                                    PAUSA(1000);
                                    LIMPAR();
                            break;
                        }
                        LIMPAR();
                            printf("================================\n");
                            printf("Produto atualizado com sucesso!\n");
                            printf("================================\n");
                        PAUSA(500);
                        
                        break;
                    }
                }

                if (!encontrado) {
                    LIMPAR();
                    printf("===========================\n");
                    printf("Produto nao encontrado.\n");
                    printf("===========================\n");
                    PAUSA(500);
                    
                }
            }
        }else if (opcao == 5) { // Para REMOVER um prod

            if (total == 0) {
                LIMPAR();
                    printf("=================================\n");
                    printf("  Nao ha produto para remover.\n");
                    printf("=================================\n");
                PAUSA(1000);
                
            }else {

                int idRemover;
                int pos = -1;

                printf("\n");
                LIMPAR();
                printf("Digite o ID do produto: ");
                    if (scanf("%d", &idRemover) != 1) {
                        while (getchar() != '\n');  //vai que tenta buscar um item negativo... 
                            printf("Entrada invalida.\n");
                            PAUSA(500);
                            LIMPAR();
                    continue;
                }

                for (int i = 0; i < total; i++) {
                    if (produtos[i].id == idRemover) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("\n");
                    LIMPAR();
                    printf("=================================\n");
                    printf("    Produto nao encontrado.\n");
                    printf("=================================\n");
                    printf("\n");
                }else {
                    for (int i = pos; i < total - 1; i++) {
                        produtos[i] = produtos[i + 1];
                    }
                    total--;

                        LIMPAR();
                    printf("=================================\n");
                    printf("Produto removido com sucesso!\n");
                    printf("=================================\n");
                    printf("\n");
                        PAUSA(1200);
                        LIMPAR();
                
                }           
            }
        }

        else if (opcao == 0) {

            printf("S\t"); //Aqui foi por pura estetica :)
                PAUSA(300);
            printf("A\t");
                PAUSA(300);
            printf("I\t");
                PAUSA(300);;
            printf("N\t");
                PAUSA(300);
            printf("D\t");
                PAUSA(300);
            printf("O\t");
                PAUSA(300);
            printf(".\t");
                PAUSA(300);
            printf(".\t");
                PAUSA(300);
            printf(".\t");
            PAUSA(1000);
        }

        else {
            printf("\n");
            printf("---------------------------------------\n");
            printf(" [!] Opcao invalida. Tente novamente.\n");
            printf("---------------------------------------\n");
                PAUSA(1500);
                LIMPAR();
        }
    } while (opcao != 0);
    return 0;
}