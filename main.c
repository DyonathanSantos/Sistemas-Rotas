#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RESET   "\033[0m"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define CYAN    "\033[36m"

#define BOLD    "\033[1m"


// variaveis globais
char enderecos[20][100];
int qtdEnderecos = 0;


// Pausa antes do menu novamente
void pausarSistema()
{
    printf("\n");
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();
}


// Function for create routes and save in array enderecos

void createEnderecos()
{
    if (qtdEnderecos < 20){

        printf ("\nDigite o endereço: ");

        getchar();
// pega o que é digitado pelo teclado, tudo diferente do scanf(%s) que vai até o 1 espaço. Coloca na posiçaõ correta do array e determina um tamanho
        fgets(enderecos[qtdEnderecos], 100, stdin);

        enderecos[qtdEnderecos][strcspn(enderecos[qtdEnderecos], "\n")] = '\0'; // troca o enter por /0.

        qtdEnderecos++;

        printf(GREEN "\n✓ Endereco cadastrado com sucesso!\n" RESET);

    }else{
        printf("\nLimite maximo de enderecos atingido!\n");
    }
    
}

void listarEnderecos()
{
    int i;

    if(qtdEnderecos == 0){
        printf(RED "\n✗ Nenhum endereco cadastrado!\n" RESET);
        return;
    }

    printf(BLUE BOLD);
    printf("\n=====================================\n");
    printf("         ENDERECOS CADASTRADOS\n");
    printf("=====================================\n");
    printf(RESET);

    for(i = 0; i < qtdEnderecos; i++){
        printf(CYAN "\n[%02d]" RESET " %s\n", i + 1, enderecos[i]);
    }

    printf("\n=====================================\n");
}

void atualizarEndereco()
{
    int i;
    int posicao;

    if(qtdEnderecos == 0){
        printf(RED "\n✗ Nenhum endereco cadastrado!\n" RESET);
        return;
    }

    printf(BLUE BOLD);
    printf("\n=====================================\n");
    printf("         ENDERECOS CADASTRADOS\n");
    printf("=====================================\n");
    printf(RESET);

    for(i = 0; i < qtdEnderecos; i++){
        printf(CYAN "[%02d]" RESET " %s\n", i + 1, enderecos[i]);
    }

    printf("\n(0- volta)\n");
    printf("\nQual endereco deseja atualizar? ");
    scanf("%d", &posicao);

    if(posicao < 0 || posicao > qtdEnderecos){
        printf(RED "\n✗ Endereco invalido!\n" RESET);
        return;
    }

    else if (posicao == 0){
        printf("Retornando...");
        return;
    }

    getchar();

    printf("Digite o novo endereco: ");
    fgets(enderecos[posicao - 1], 100, stdin);

    enderecos[posicao - 1][strcspn(enderecos[posicao - 1], "\n")] = '\0';

    printf(GREEN "\n✓ Endereco atualizado com sucesso!\n" RESET);
}

void deletarEndereco()
{
    int i;
    int posicao;

    if(qtdEnderecos == 0){
        printf(RED "\n✗ Nenhum endereco cadastrado!\n" RESET);
        return;
    }

    printf(BLUE BOLD);
    printf("\n=====================================\n");
    printf("         ENDERECOS CADASTRADOS\n");
    printf("=====================================\n");
    printf(RESET);     

    for(i = 0; i < qtdEnderecos; i++){
        printf(CYAN "\n[%02d]" RESET " %s\n", i + 1, enderecos[i]);
    }

    printf("\n0 - volta\n");
    printf("\nQual endereco deseja remover? ");
    scanf("%d", &posicao);

    if(posicao < 0 || posicao > qtdEnderecos){
        printf(RED "\n✗ Endereco invalido!\n" RESET);
        return;
    }

    else if (posicao == 0){
        printf("Retornando...");
        return;
    }

    for(i = posicao - 1; i < qtdEnderecos - 1; i++){
        strcpy(enderecos[i], enderecos[i + 1]);  // strcpy copia a str na outra e o loop faz todas ir para esquerda para substituir o espaço vazio
    }

    qtdEnderecos--;

    printf(GREEN "\n✓ Endereco removido com sucesso!\n" RESET);
}

void listarRotas()
{
    int i;
    int rota = 1;

    if(qtdEnderecos == 0){
        printf(RED "\n✗ Nenhum endereco cadastrado!\n" RESET);
        return;
    }

    printf("\n===== ROTAS =====\n");

    for(i = 0; i < qtdEnderecos; i++){

        if(i % 4 == 0){
           printf(PURPLE BOLD);
           printf("\n=====================================\n");
           printf("             ROTA %d\n", rota);
           printf("=====================================\n\n");
           printf(RESET);

           rota++;
        }

        printf("[%02d] - %s\n", i + 1, enderecos[i]);
    }
}

int main()

{
    int menuChoice, createChoice, upChoice, delChoice, listChoice;

    do{
        printf("\n");
        system("clear");
        printf(CYAN BOLD);
        printf("=====================================\n");
        printf("         SISTEMA DE ROTAS\n");
        printf("=====================================\n");
        printf(RESET);
        printf(GREEN);
        printf(" Enderecos cadastrados: %02d/20\n", qtdEnderecos);
        printf(RESET);
        printf("=====================================\n");
        printf(YELLOW "[1]" RESET " Adicionar Endereco\n");
        printf(YELLOW "[2]" RESET " Listar Enderecos\n");
        printf(YELLOW "[3]" RESET " Atualizar Endereco\n");
        printf(YELLOW "[4]" RESET " Remover Endereco\n");
        printf(YELLOW "[5]" RESET " Listar Rotas\n");
        printf(RED    "[0]" RESET " Sair\n");
        printf("=====================================\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &menuChoice);

        switch(menuChoice){

            case 0:
                printf("Encerrando...");
                break;

            case 1:
                
                createEnderecos();
                pausarSistema();
                break;

            case 2:
            
                listarEnderecos();
                pausarSistema();
                break;

            case 3:

                atualizarEndereco();
                pausarSistema();
                break;

            case 4:
                deletarEndereco();
                pausarSistema();
                break;

            case 5:
                listarRotas();
                pausarSistema();
                break;
        }
    }
    while(menuChoice !=0);
        
    return 0;
}
