#include "funcoes.h"

/*
    Método que roda a main principal do Trabalho Final.
*/
void main_trabalho_final() {
    List *list = NULL; 

    list = create_list();

    menu_principal(list);
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
void menu_principal(List *list) {
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
                menu_cliente(list);
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
                sleep(1.5);
                break;
        }

    } while(opcao != 4);
}

/*
    Método que mostra o menu cliente do Software e 
    permite ao usuário escolher uma opção.
*/
void menu_cliente(List *list) {
    int opcao = 0;
    Cliente *cliente = NULL;

    do {
    system("cls"); 

    printf("----------------- MENU CLIENTE ------------------\n");
    printf("*            (1) Cadastrar Cliente              *\n");
    printf("*            (2) Listar Cliente                 *\n");
    printf("*            (3) Buscar Cliente                 *\n");
    printf("*            (4) Editar Cliente                 *\n");
    printf("*            (5) Remover Cliente                *\n");
    printf("*            (6) Menu Principal                 *\n");
    printf("-------------------------------------------------\n");
    printf("Digite a opcao desejada --> ");
    scanf("%d", &opcao);	

     
        switch(opcao) {
            case 1:
                menu_cadastro_cliente(list);
                break;

            case 2:
                print_list(list, 1);
                break;

            case 3:
                visualizar_cliente(list, 1);
                break;

            case 4:
                cliente = buscar_cliente_cpf(list);
                if(cliente != NULL) {
                    edita_cliente(cliente, list);
                } else {
                    printf("### Cliente nao encontrado ###\n");
                    sleep(2);
                }
                break;

            case 5:
                cliente = buscar_cliente_cpf(list);
                if(cliente != NULL){
                    exclui_cliente(list, cliente);
                } else {
                    printf("### Cliente nao encontrado ###\n");
                    sleep(2);
                }
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
    printf("*            (3) Buscar Produto                 *\n");
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
    printf("\n\tAte uma proxima vez....\n\n");
    sleep(2);
    system("cls");
}

/*
    Método que permite cadastrar o número de clientes desejados.
*/
void menu_cadastro_cliente(List *list){
    int qtd = 0;
    
    printf("Digite a quantidade de clientes que deseja cadastrar --> ");
    scanf("%d", &qtd);

    for(int i = 0; i < qtd; i++) {
        printf("\n\n---------------------- Cadastro de Clientes ----------------------\n");
        getchar();
        Cliente * cliente = create_cliente();

        printf("Digite o nome do cliente: ");
        scanf(" %[^\n]", cliente->nome);
        printf("Digite o email do cliente: ");
        scanf(" %[^\n]", cliente->email);

        printf("Digite o CPF do cliente: "); 
        do{
            scanf(" %[^\n]", cliente->cpf);
        } while (verifica_unico(list, cliente->cpf));
        
        printf("Digite o dia que o cliente nasceu: "); 
        scanf("%d", &cliente->nascimento.dia); 
        printf("Digite o mes que o cliente nasceu: "); 
        scanf("%d", &cliente->nascimento.mes); 
        printf("Digite o ano que o cliente nasceu: "); 
        scanf("%d", &cliente->nascimento.ano); 
        printf("Digite o telefone do cliente: "); 
        scanf(" %[^\n]", cliente->telefone); 
        edita_informacao(cliente->nome, 0);
        edita_informacao(cliente->email, 1);
        edita_informacao(cliente->telefone, 3);
        push(list, cliente, 0);
    }

}

/*
    Método que aloca o espaço na memória e retorna o cliente criado.
*/
Cliente *create_cliente() {
    Cliente * cliente = (Cliente *) malloc(sizeof(Cliente));
    
    cliente->nome = (char *) malloc(50 * sizeof(char));
    cliente->email = (char *) malloc(50 * sizeof(char));
    cliente->telefone = (char *) malloc(20 * sizeof(char));
    cliente->qt_produtos = 0;
    cliente->carrinho = NULL;

    return cliente;
}


/*
    Método que edita o nome para os padrões desejados pelo Sistema e 
    realoca a memória para o número exatos de caracteres.
*/
void edita_informacao(char *nome, int x) {
    for(unsigned int H = 0; H < strlen(nome); H++) { 
        if(x == 0) { //nome do cliente (x = 0)
            if(H == 0 || nome[H-1] == ' ') {	
                nome[H] = toupper(nome[H]);
            } else if(H > 0) {
                nome[H] = tolower(nome[H]);
            }
        }
        if(x == 1) { //Email (x = 1)
            nome[H] = tolower(nome[H]);
        }
        if(x == 2) { // Nome do produto (x = 2)
            if(H == 0) {
                nome[H] = toupper(nome[H]);
            } else {
                nome[H] = tolower(nome[H]);
            }
        }
        nome[strlen(nome)] = '\0';
    } 

    nome = (char *) realloc(nome, strlen(nome));
}

/*
    Método que inclui um cliente na lista.
*/
void push(List * list, Cliente *cliente, int i) {
    if(list != NULL) {
        cliente->next = list->head;
        list->head = cliente;
        list->size++;
        if(i == 0) {
            printf("\tCliente, %s, cadastrado com sucesso!\n\n", cliente->nome);
            sleep(1.5);
        }
        return;
	}

    printf("### Nao foi possivel cadastrar o Cliente! ###\n");
    sleep(1.5);
}

/*
    Método que imprime todos os clientes da lista.
*/
void print_list(List *list, int i) {
    if(is_empty(&list)) { //se retornar 1
        printf("Lista vazia!\n");
        sleep(1.5);
        return;
    }
    Cliente *cliente = list->head;

    printf("\n\n-------------- Lista de Clientes --------------\n"); 
    while(cliente != NULL) {
        printf("\tNome: %s\n", cliente->nome);
        printf("\tCPF: %s\n", cliente->cpf);
        printf("\tE-mail: %s\n", cliente->email);
        printf("\tTelefone: %s\n", cliente->telefone);
        printf("\tData de nascimento: %d/%d/%d\n", cliente->nascimento.dia, cliente->nascimento.mes, cliente->nascimento.ano);
        printf("***********************************************\n");
        cliente = cliente->next;
    }
    printf("Total de Clientes: %d\n\n", list->size);

    if(i == 1) { //sem esse if, apagaria a lista de clientes
        char * liberar = (char *) malloc(sizeof(char));
        printf(":: Pressione ENTER para continuar ");
        getchar();
        scanf("%[^\n]", liberar);
        getchar();
        free(liberar);
    }
}

/*
    Método que verifica se a lista de clientes está vazia.
*/
int is_empty(List **list) {
    if((*list)->size == 0)
        return 1;
    else
        return 0;
}

/*
    Método que verifica se o cpf é único.
*/
int verifica_unico(List *list, char cpf[]){
    Cliente *cliente = list->head;

    while (cliente != NULL) {
        if (strcmp(cliente->cpf, cpf) == 0) {
            printf("Esse CPF ja esta cadastrado. Digite outro CPF: ");
            return 1;
        }
        cliente = cliente->next;
    } 
    return 0;
}

/*
    Método que apresenta os dados de um cliente que o usuário desejar buscar.
*/
void visualizar_cliente(List * list, int i) {
    Cliente *cliente = buscar_cliente_cpf(list);

    if (cliente != NULL) {
        printf("\nCliente:\n");
        printf("Nome: %s\n", cliente->nome);
        printf("CPF: %s\n", cliente->cpf);
        printf("E-mail: %s\n", cliente->email);
        printf("Telefone: %s\n", cliente->telefone);
        printf("Data de nascimento: %d/%d/%d\n", cliente->nascimento.dia, cliente->nascimento.mes, cliente->nascimento.ano);

        if(i == 1) { //sem esse if, apagaria os dados do clientes
            char * liberar = (char *) malloc(sizeof(char));
            printf("\n:: Pressione ENTER para continuar ");
            getchar();
            scanf("%[^\n]", liberar);
            getchar();
            free(liberar);
            return;
        }
    }

    printf("### Cliente nao encontrado ###\n\n");
    sleep(2);    
}

/*
    Método que permite buscar um aluno pelo CPF que o usuário digitar.
*/
Cliente *buscar_cliente_cpf(List * list) {
    char buscar[15] = {}; 
    Cliente *cliente = list->head; 

    printf(":: Digite o CPF do cliente: "); 
    scanf(" %14[^\n]", buscar); 

    while (cliente != NULL) {
        if (strcmp(cliente->cpf, buscar) == 0) {
            return cliente;
        }  
        cliente = cliente->next;
    }
    return NULL;
}

/*
    Método que permite editar o aluno.
*/
void edita_cliente(Cliente *cliente, List *list) {
    char novo_cpf[15]; 

    cliente->nome = (char *) realloc(cliente->nome, 50*sizeof(char));
    cliente->email = (char *) realloc(cliente->email, 50*sizeof(char));
    cliente->telefone = (char *) realloc(cliente->telefone, 20 * sizeof(char));
    printf("------------------------------------------------\n");
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", cliente->nome);
    printf("Digite o email do cliente: ");
    scanf(" %[^\n]", cliente->email);

    printf("Digite o CPF do cliente: "); 
    scanf(" %[^\n]", novo_cpf);
    if(strcmp(novo_cpf, cliente->cpf) != 0) {
        do{
            scanf(" %[^\n]", cliente->cpf);
        } while (verifica_unico(list, cliente->cpf));
    }
        
    printf("Digite o dia que o cliente nasceu: "); 
    scanf("%d", &cliente->nascimento.dia); 
    printf("Digite o mes que o cliente nasceu: "); 
    scanf("%d", &cliente->nascimento.mes); 
    printf("Digite o ano que o cliente nasceu: "); 
    scanf("%d", &cliente->nascimento.ano); 
    printf("Digite o telefone do cliente: "); 
    scanf(" %[^\n]", cliente->telefone); 
    edita_informacao(cliente->nome, 0);
    edita_informacao(cliente->email, 1);
    edita_informacao(cliente->telefone, 3);

    printf("**** Aluno(a), %s, editado(a) com sucesso ****\n", cliente->nome);
    sleep(2);
}

/*
    Método que exclui o cliente desejado.
*/
void exclui_cliente(List *list, Cliente *cliente) {
    Cliente *aux = list->head;
    Cliente *aux_anterior = list->head;
    int i = 0;

    while(aux != NULL) {
        if(strcmp(aux->nome, cliente->nome) == 0 && strcmp(aux->cpf, cliente->cpf) == 0) {
            if(i == 0) {  //quando existe apenas uma célula na lista
                pop_cliente(list, 1);
                break;
            } else {
                pop_index_cliente(list, aux_anterior, aux);
            }
        }
        aux_anterior = aux;
        aux = aux->next;
        i++;
    }
}

/*
    Método que exclui o ultimo cliente incluído na lista.
*/
void pop_cliente(List * list, int i) { 
    Cliente * aux = list->head;
    Produto * prod = aux->carrinho;
    char *nome = (char *) malloc(50 * sizeof(char));

    strcpy(nome, aux->nome);
    list->head = aux->next;
    free(aux->nome);
    free(aux->email);
    free(aux->telefone);
    if(prod) {
        while(prod) {
            pop_produto(aux, 0);
            prod = prod->next;
        }
    }
    free(aux);
    list->size--;

    if(i == 1) {
        printf("**** Cliente, %s, excluido(a) com sucesso! ****\n", nome);
        sleep(1.5);
    }
    free(nome);
}

/*
    Método que exclui o último produto incluído no cliente. 
*/
void pop_produto(Cliente *cliente, int i) { 
    Produto *aux = cliente->carrinho;
    char *nome = (char *) malloc(50 * sizeof(char));

    strcpy(nome, aux->nome);
    cliente->carrinho = aux->next;
    free(aux->nome);
    free(aux->codigo);
    free(aux);
    cliente->qt_produtos--;

    if(i == 1) {
        printf("**** Produto, %s, excluido com sucesso! ****\n", nome);
        sleep(1.8);
    }
    free(nome);
}

/*
    Método que apaga e libera o espaço da memória do cliente desejado.
*/
void pop_index_cliente(List * list, Cliente *cliente_anterior, Cliente *cliente_excluir) {
    Cliente *aux = cliente_excluir;
    char *nome = (char *) malloc(50 * sizeof(char));

    strcpy(nome, aux->nome);
    cliente_anterior->next = aux->next;
    free(aux->nome);
    free(aux->email);
    free(aux->telefone);
    if(aux->carrinho) {
        Produto *produto = aux->carrinho;
        while(produto) {
            pop_produto(aux, 0);
            produto = produto->next;
        }
        free(aux->carrinho);
    }
    free(aux);
    list->size--; 

    printf("**** Cliente, %s, excluido(a) com sucesso! ****\n", nome);
    sleep(1.8);
    free(nome);
}




#include "funcoes.h"

/*
    Método que roda a main principal do Trabalho Final.
*/
void main_trabalho_final() {
    List *list = NULL; 

    list = create_list();

    menu_principal(list);
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
void menu_principal(List *list) {
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
                menu_cliente(list);
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
                sleep(1.5);
                break;
        }

    } while(opcao != 4);
}

/*
    Método que mostra o menu cliente do Software e 
    permite ao usuário escolher uma opção.
*/
void menu_cliente(List *list) {
    int opcao = 0;
    Cliente *cliente = NULL;

    do {
    system("cls"); 

    printf("----------------- MENU CLIENTE ------------------\n");
    printf("*            (1) Cadastrar Cliente              *\n");
    printf("*            (2) Listar Cliente                 *\n");
    printf("*            (3) Buscar Cliente                 *\n");
    printf("*            (4) Editar Cliente                 *\n");
    printf("*            (5) Remover Cliente                *\n");
    printf("*            (6) Menu Principal                 *\n");
    printf("-------------------------------------------------\n");
    printf("Digite a opcao desejada --> ");
    scanf("%d", &opcao);	

     
        switch(opcao) {
            case 1:
                menu_cadastro_cliente(list);
                break;

            case 2:
                print_list(list, 1);
                break;

            case 3:
                visualizar_cliente(list, 1);
                break;

            case 4:
                cliente = buscar_cliente_cpf(list);
                if(cliente != NULL) {
                    edita_cliente(cliente, list);
                } else {
                    printf("### Cliente nao encontrado ###\n");
                    sleep(2);
                }
                break;

            case 5:
                cliente = buscar_cliente_cpf(list);
                if(cliente != NULL){
                    exclui_cliente(list, cliente);
                } else {
                    printf("### Cliente nao encontrado ###\n");
                    sleep(2);
                }
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
    printf("*            (3) Buscar Produto                 *\n");
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
    printf("\n\tAte uma proxima vez....\n\n");
    sleep(2);
    system("cls");
}

/*
    Método que permite cadastrar o número de clientes desejados.
*/
void menu_cadastro_cliente(List *list){
    int qtd = 0;
    
    printf("Digite a quantidade de clientes que deseja cadastrar --> ");
    scanf("%d", &qtd);

    for(int i = 0; i < qtd; i++) {
        printf("\n\n---------------------- Cadastro de Clientes ----------------------\n");
        getchar();
        Cliente * cliente = create_cliente();

        printf("Digite o nome do cliente: ");
        scanf(" %[^\n]", cliente->nome);
        printf("Digite o email do cliente: ");
        scanf(" %[^\n]", cliente->email);

        printf("Digite o CPF do cliente: "); 
        do{
            scanf(" %[^\n]", cliente->cpf);
        } while (verifica_unico(list, cliente->cpf));
        
        printf("Digite o dia que o cliente nasceu: "); 
        scanf("%d", &cliente->nascimento.dia); 
        printf("Digite o mes que o cliente nasceu: "); 
        scanf("%d", &cliente->nascimento.mes); 
        printf("Digite o ano que o cliente nasceu: "); 
        scanf("%d", &cliente->nascimento.ano); 
        printf("Digite o telefone do cliente: "); 
        scanf(" %[^\n]", cliente->telefone); 
        edita_informacao(cliente->nome, 0);
        edita_informacao(cliente->email, 1);
        edita_informacao(cliente->telefone, 3);
        push(list, cliente, 0);
    }

}

/*
    Método que aloca o espaço na memória e retorna o cliente criado.
*/
Cliente *create_cliente() {
    Cliente * cliente = (Cliente *) malloc(sizeof(Cliente));
    
    cliente->nome = (char *) malloc(50 * sizeof(char));
    cliente->email = (char *) malloc(50 * sizeof(char));
    cliente->telefone = (char *) malloc(20 * sizeof(char));
    cliente->qt_produtos = 0;
    cliente->carrinho = NULL;

    return cliente;
}


/*
    Método que edita o nome para os padrões desejados pelo Sistema e 
    realoca a memória para o número exatos de caracteres.
*/
void edita_informacao(char *nome, int x) {
    for(unsigned int H = 0; H < strlen(nome); H++) { 
        if(x == 0) { //nome do cliente (x = 0)
            if(H == 0 || nome[H-1] == ' ') {	
                nome[H] = toupper(nome[H]);
            } else if(H > 0) {
                nome[H] = tolower(nome[H]);
            }
        }
        if(x == 1) { //Email (x = 1)
            nome[H] = tolower(nome[H]);
        }
        if(x == 2) { // Nome do produto (x = 2)
            if(H == 0) {
                nome[H] = toupper(nome[H]);
            } else {
                nome[H] = tolower(nome[H]);
            }
        }
        nome[strlen(nome)] = '\0';
    } 

    nome = (char *) realloc(nome, strlen(nome));
}

/*
    Método que inclui um cliente na lista.
*/
void push(List * list, Cliente *cliente, int i) {
    if(list != NULL) {
        cliente->next = list->head;
        list->head = cliente;
        list->size++;
        if(i == 0) {
            printf("\tCliente, %s, cadastrado com sucesso!\n\n", cliente->nome);
            sleep(1.5);
        }
        return;
	}

    printf("### Nao foi possivel cadastrar o Cliente! ###\n");
    sleep(1.5);
}

/*
    Método que imprime todos os clientes da lista.
*/
void print_list(List *list, int i) {
    if(is_empty(&list)) { //se retornar 1
        printf("Lista vazia!\n");
        sleep(1.5);
        return;
    }
    Cliente *cliente = list->head;

    printf("\n\n-------------- Lista de Clientes --------------\n"); 
    while(cliente != NULL) {
        printf("\tNome: %s\n", cliente->nome);
        printf("\tCPF: %s\n", cliente->cpf);
        printf("\tE-mail: %s\n", cliente->email);
        printf("\tTelefone: %s\n", cliente->telefone);
        printf("\tData de nascimento: %d/%d/%d\n", cliente->nascimento.dia, cliente->nascimento.mes, cliente->nascimento.ano);
        printf("***********************************************\n");
        cliente = cliente->next;
    }
    printf("Total de Clientes: %d\n\n", list->size);

    if(i == 1) { //sem esse if, apagaria a lista de clientes
        char * liberar = (char *) malloc(sizeof(char));
        printf(":: Pressione ENTER para continuar ");
        getchar();
        scanf("%[^\n]", liberar);
        getchar();
        free(liberar);
    }
}

/*
    Método que verifica se a lista de clientes está vazia.
*/
int is_empty(List **list) {
    if((*list)->size == 0)
        return 1;
    else
        return 0;
}

/*
    Método que verifica se o cpf é único.
*/
int verifica_unico(List *list, char cpf[]){
    Cliente *cliente = list->head;

    while (cliente != NULL) {
        if (strcmp(cliente->cpf, cpf) == 0) {
            printf("Esse CPF ja esta cadastrado. Digite outro CPF: ");
            return 1;
        }
        cliente = cliente->next;
    } 
    return 0;
}

/*
    Método que apresenta os dados de um cliente que o usuário desejar buscar.
*/
void visualizar_cliente(List * list, int i) {
    Cliente *cliente = buscar_cliente_cpf(list);

    if (cliente != NULL) {
        printf("\nCliente:\n");
        printf("Nome: %s\n", cliente->nome);
        printf("CPF: %s\n", cliente->cpf);
        printf("E-mail: %s\n", cliente->email);
        printf("Telefone: %s\n", cliente->telefone);
        printf("Data de nascimento: %d/%d/%d\n", cliente->nascimento.dia, cliente->nascimento.mes, cliente->nascimento.ano);

        if(i == 1) { //sem esse if, apagaria os dados do clientes
            char * liberar = (char *) malloc(sizeof(char));
            printf("\n:: Pressione ENTER para continuar ");
            getchar();
            scanf("%[^\n]", liberar);
            getchar();
            free(liberar);
            return;
        }
    }

    printf("### Cliente nao encontrado ###\n\n");
    sleep(2);    
}

/*
    Método que permite buscar um aluno pelo CPF que o usuário digitar.
*/
Cliente *buscar_cliente_cpf(List * list) {
    char buscar[15] = {}; 
    Cliente *cliente = list->head; 

    printf(":: Digite o CPF do cliente: "); 
    scanf(" %14[^\n]", buscar); 

    while (cliente != NULL) {
        if (strcmp(cliente->cpf, buscar) == 0) {
            return cliente;
        }  
        cliente = cliente->next;
    }
    return NULL;
}

/*
    Método que permite editar o aluno.
*/
void edita_cliente(Cliente *cliente, List *list) {
    char novo_cpf[15]; 

    cliente->nome = (char *) realloc(cliente->nome, 50*sizeof(char));
    cliente->email = (char *) realloc(cliente->email, 50*sizeof(char));
    cliente->telefone = (char *) realloc(cliente->telefone, 20 * sizeof(char));
    printf("------------------------------------------------\n");
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", cliente->nome);
    printf("Digite o email do cliente: ");
    scanf(" %[^\n]", cliente->email);

    printf("Digite o CPF do cliente: "); 
    scanf(" %[^\n]", novo_cpf);
    if(strcmp(novo_cpf, cliente->cpf) != 0) {
        do{
            scanf(" %[^\n]", cliente->cpf);
        } while (verifica_unico(list, cliente->cpf));
    }
        
    printf("Digite o dia que o cliente nasceu: "); 
    scanf("%d", &cliente->nascimento.dia); 
    printf("Digite o mes que o cliente nasceu: "); 
    scanf("%d", &cliente->nascimento.mes); 
    printf("Digite o ano que o cliente nasceu: "); 
    scanf("%d", &cliente->nascimento.ano); 
    printf("Digite o telefone do cliente: "); 
    scanf(" %[^\n]", cliente->telefone); 
    edita_informacao(cliente->nome, 0);
    edita_informacao(cliente->email, 1);
    edita_informacao(cliente->telefone, 3);

    printf("**** Aluno(a), %s, editado(a) com sucesso ****\n", cliente->nome);
    sleep(2);
}

/*
    Método que exclui o cliente desejado.
*/
void exclui_cliente(List *list, Cliente *cliente) {
    Cliente *aux = list->head;
    Cliente *aux_anterior = list->head;
    int i = 0;

    while(aux != NULL) {
        if(strcmp(aux->nome, cliente->nome) == 0 && strcmp(aux->cpf, cliente->cpf) == 0) {
            if(i == 0) {  //quando existe apenas uma célula na lista
                pop_cliente(list, 1);
                break;
            } else {
                pop_index_cliente(list, aux_anterior, aux);
            }
        }
        aux_anterior = aux;
        aux = aux->next;
        i++;
    }
}

/*
    Método que exclui o ultimo cliente incluído na lista.
*/
void pop_cliente(List * list, int i) { 
    Cliente * aux = list->head;
    Produto * prod = aux->carrinho;
    char *nome = (char *) malloc(50 * sizeof(char));

    strcpy(nome, aux->nome);
    list->head = aux->next;
    free(aux->nome);
    free(aux->email);
    free(aux->telefone);
    if(prod) {
        while(prod) {
            pop_produto(aux, 0);
            prod = prod->next;
        }
    }
    free(aux);
    list->size--;

    if(i == 1) {
        printf("**** Cliente, %s, excluido(a) com sucesso! ****\n", nome);
        sleep(1.5);
    }
    free(nome);
}

/*
    Método que exclui o último produto incluído no cliente. 
*/
void pop_produto(Cliente *cliente, int i) { 
    Produto *aux = cliente->carrinho;
    char *nome = (char *) malloc(50 * sizeof(char));

    strcpy(nome, aux->nome);
    cliente->carrinho = aux->next;
    free(aux->nome);
    free(aux->codigo);
    free(aux);
    cliente->qt_produtos--;

    if(i == 1) {
        printf("**** Produto, %s, excluido com sucesso! ****\n", nome);
        sleep(1.8);
    }
    free(nome);
}

/*
    Método que apaga e libera o espaço da memória do cliente desejado.
*/
void pop_index_cliente(List * list, Cliente *cliente_anterior, Cliente *cliente_excluir) {
    Cliente *aux = cliente_excluir;
    char *nome = (char *) malloc(50 * sizeof(char));

    strcpy(nome, aux->nome);
    cliente_anterior->next = aux->next;
    free(aux->nome);
    free(aux->email);
    free(aux->telefone);
    if(aux->carrinho) {
        Produto *produto = aux->carrinho;
        while(produto) {
            pop_produto(aux, 0);
            produto = produto->next;
        }
        free(aux->carrinho);
    }
    free(aux);
    list->size--; 

    printf("**** Cliente, %s, excluido(a) com sucesso! ****\n", nome);
    sleep(1.8);
    free(nome);
}




