#include "funcoes.h"

/*
    Método que roda a main principal do Trabalho Final.
*/
void main_trabalho_final() {
    List * list = NULL;
    Cliente *clientes = NULL; 

    list = create_list();

    menu_principal();
}


/*
    Método que aloca o espaço na memória e retorna a lista criada.
*/
List *create_list() {
    List * list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;

    return list;
}


/*
    Método que mostra o menu principal do Software e 
    permite ao usuário escolher uma opção.
*/
void menu_principal() {
    int opcao = 0;
    
    do { 
    system("cls");

    printf("----------------- MENU PRINCIPAL ----------------------\n");
    printf("*            (1) Gerenciamento de Clientes            *\n");
    printf("*            (2) Gerenciamento de Produtos            *\n");
    printf("*            (3) Modo Compra                          *\n");
    printf("*            (4) Sair do Programa                     *\n");
    printf("-------------------------------------------------------\n");
    printf("Digite a opcao desejada --> ");
    scanf("%d", &opcao);	

     
        switch(opcao) {
            case 1:
                menu_cliente();
                break;

            case 2:
                menu_produto();
                break;

            case 3:
                //função modo compra
                break;
            case 4:
                menu_encerra();
                break;
            default:
                printf("Opcao Invalida...\n");
                sleep(1);
                break;
        }

    } while(opcao != 4);
}

/*
    Método que mostra o menu cliente do Software e 
    permite ao usuário escolher uma opção.
*/
void menu_cliente() {
    int opcao = 0;

    do {
    system("cls"); 

    printf("----------------- MENU CLIENTE ------------------\n");
    printf("*            (1) Cadastrar Cliente              *\n");
    printf("*            (2) Listar Cliente                 *\n");
    printf("*            (3) Visualizar Cliente             *\n");
    printf("*            (4) Editar Cliente                 *\n");
    printf("*            (5) Excluir Cliente                *\n");
    printf("*            (6) Menu Principal                 *\n");
    printf("-------------------------------------------------\n");
    printf("Digite a opcao desejada --> ");
    scanf("%d", &opcao);	

     
        switch(opcao) {
            case 1:
                
                break;

            case 2:
                
                break;

            case 3:
            
                break;

            case 4:
            
                break;

            case 5:
                
                break;

            case 6:
                break;
            
            default:
                printf("Opcao Invalida...\n");
                sleep(1);
                break;
        }
    } while(opcao != 6);
}

void menu_produto() {
    int opcao = 0;
    
    do { 
    system("cls");
    
    printf("----------------- MENU PRODUTO ------------------\n");
    printf("*            (1) Cadastrar Produto              *\n");
    printf("*            (2) Listar Produto                 *\n");
    printf("*            (3) Visualizar Produto             *\n");
    printf("*            (4) Editar Produto                 *\n");
    printf("*            (5) Excluir Produto                *\n");
    printf("*            (6) Menu Principal                 *\n");
    printf("-------------------------------------------------\n");
    printf("Digite a opcao desejada --> ");
    scanf("%d", &opcao);	

        switch(opcao) {
            case 1:
                
                break;

            case 2:
                
                break;

            case 3:
            
                break;

            case 4:
            
                break;

            case 5:
                
                break;

            case 6:
                break;
            
            default:
                printf("Opcao Invalida...\n");
                sleep(1);
                break;
        }
    } while(opcao != 6);
}

void menu_encerra() {
    printf("\n\n\n\tAte uma proxima vez....\n");
    sleep(1.5);
}
