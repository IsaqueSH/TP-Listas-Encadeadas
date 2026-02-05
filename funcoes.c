#include "funcoes.h"

/* ======================================== MAIN ========================================= */
/*
    Método que roda a main principal do Trabalho Final.
*/
void main_trabalho_final() {
    List *list = NULL; 
    List_Prod *list_prod = NULL; 

    list = create_list();
    list_prod = create_product_list();  

    menu_principal(list, list_prod); 

    free_lista_clientes(list);  
    free_lista_produtos(list_prod);
}

/* ================================= CRIAÇÃO DAS LISTAS ================================== */

/*
    Método que aloca o espaço na memória e retorna 
    a lista criada realacionada a clientes.
*/
List *create_list() {
    List * list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;

    return list;
}

/*
    Método que aloca o espaço na memória e retorna 
    a lista criada realacionada a produtos.
*/
List_Prod *create_product_list() {
    List_Prod * list_prod = (List_Prod *) malloc(sizeof(List_Prod));
    list_prod->head = NULL;
    list_prod->size = 0;

    return list_prod;
}

/* =================================== MENU PRINCIPAL ==================================== */
/*
    Método que mostra o menu principal do software e 
    permite ao usuário escolher uma opção.
*/
void menu_principal(List *list, List_Prod *list_prod) {
    int opcao = 0; 
    
    do { 
    system("cls");

    printf("----------------- MENU PRINCIPAL ----------------------\n");
    printf("*            (1) Gerenciamento de Clientes            *\n");
    printf("*            (2) Gerenciamento de Produtos            *\n");
    printf("*            (3) Modo Compra                          *\n");
    printf("*            (4) Sair do Programa                     *\n");
    printf("-------------------------------------------------------\n");
    printf("::Digite a opcao desejada --> ");
    scanf("%d", &opcao);	
    
        switch(opcao) {
            case 1:
                menu_cliente(list);
                break;

            case 2:
                menu_produto(list_prod);
                break;

            case 3: 
                if (list_prod->head != NULL) {
                    Cliente *cliente = buscar_cliente_cpf(list);
                    if(cliente != NULL) {
                        menu_compra(list_prod, cliente);
                    } else {
                        printf("### Cliente nao encontrado ###\n");
                        sleep(2);
                    }
                } else {
                    printf("Nao ha produtos cadastrados para realizar compras.\n");
                    sleep(1.9);
                }
                break;
            case 4:
                menu_encerra();
                break;
            default:
                printf("Opcao Invalida...\n");
                sleep(1.8);
                break;
        }

    } while(opcao != 4);
}

/*
    Método que imprime a tela de encerramento 
    do programa.
*/
void menu_encerra() {
    printf("\n\tEncerrando....\n\n");
    sleep(2);
    system("cls");
}

/* ================================= MENU DE CLIENTES ================================== */
/*
    Método que mostra o menu de clientes e 
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
    printf(":: Digite a opcao desejada --> ");
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

/* ================================= MENU DE PRODUTOS ================================== */
/*
    Método que mostra o menu de produtos e 
    permite ao usuário escolher uma opção.
*/
void menu_produto(List_Prod *plist) {
    int opcao = 0;
    Produto *prod = NULL;
    
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
        printf(":: Digite a opcao desejada --> ");
        scanf("%d", &opcao);	

        switch(opcao) {
            case 1:
                menu_cadastro_produto(plist);
                break;

            case 2:
                print_produtos(plist, 1);
                break;

            case 3:
                visualizar_produto(plist, 1);
                break;

            case 4:
                prod = buscar_produto_codigo(plist);
                if (prod != NULL) {
                    edita_produto(prod, plist);
                } else {
                    printf("### Produto nao encontrado ###\n");
                    sleep(2);
                }
                break;

            case 5:
                prod = buscar_produto_codigo(plist);
                if (prod) {
                    exclui_produto(plist, prod);
                } else {
                    printf("### Produto nao encontrado ###\n");
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

/* ===================================== MENU COMPRA =======================================*/

/*
    Método que imprime na tela o menu compra e 
    chama as ações dentro do nome do cliente.
*/
void menu_compra(List_Prod *plist, Cliente *cliente) {
    int opcao, i = 0;
    Produto *produto;

    do {
        system("cls");
        printf("----------------------- Modo Compra ----------------------\n");
        dados_cliente(cliente);
        printf("*          (1) Incluir produtos no carrinho              *\n");
        printf("*          (2) Listar os produtos do carrinho            *\n");
        printf("*          (3) Retirar produtos do carrinho              *\n");
        printf("*          (4) Voltar ao menu principal                  *\n");
        printf("----------------------------------------------------------\n");
        printf("\n:: Digite a opcao desejada --> ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionar_produto_ao_carrinho(plist, cliente);
                break;
            
            case 2:
                listar_carrinho_cliente(cliente);
                break;

            case 3:
                produto = busca_produto_carrinho(cliente);
                int qt_itens = 0;
                if(produto != NULL) {
                    print_p(produto); 
                    printf("Quantos itens desse produto voce deseja excluir? ");
                    scanf("%d", &qt_itens);
                    if (produto->quantidade >= qt_itens && qt_itens > 0) {
                        exclui_produto_carrinho(cliente, produto, qt_itens);
                    } else {
                        printf("### Quantidade invalida ###\n\n");
                        sleep(1.8);
                    }
                } else {
                    printf("### Codigo nao encontrado ###\n");
                    sleep(1.8);
                }
                break;

            case 4:
                break;

            default:
                printf("Opcao ivalida!\n");
                sleep(1.8);
                break;
        }
        i++;
    } while(opcao != 4);
}

/*
    Método que imprime os dados de um cliente.
*/
void dados_cliente(Cliente *cliente) {
    printf("          Cliente: %s\n", cliente->nome);
    printf("          CPF: %s\n", cliente->cpf);
    printf("          Quantidade de produtos: %d\n", cliente->qt_produtos);
    printf("----------------------------------------------------------\n");
}

/* ======================================= CLIENTES ======================================= */
/*
    Método que permite cadastrar o número de 
    clientes desejados.
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
    Método que aloca o espaço na memória e 
    retorna o cliente criado.
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
    Método que edita o nome para os padrões desejados pelo 
    sistema e realoca a memória para o número exatos de caracteres.
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
            sleep(1.8);
        }
        return;
	}

    printf("### Nao foi possivel cadastrar o Cliente! ###\n");
    sleep(1.8);
}

/*
    Método que imprime todos os clientes da lista.
*/
void print_list(List *list, int i) {
    if(is_empty(&list)) { 
        printf("Lista vazia!\n");
        sleep(1.8);
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

    if(i == 1) { 
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
    Método que verifica se a lista de produtos está vazia.
*/
int is_empty_plist(List_Prod **plist) {
    if((*plist)->size == 0)
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
    Método que apresenta os dados de um cliente 
    que o usuário desejar buscar.
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

        if(i == 1) {
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
    Método que permite buscar um cliente 
    pelo CPF que o usuário digitar.
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
    Método que permite editar o cliente.
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

    printf("**** Cliente, %s, editado(a) com sucesso ****\n", cliente->nome);
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
        if(strcmp(aux->cpf, cliente->cpf) == 0) {
            if(i == 0) {  
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
            pop_produto_carrinho(aux, 0);
            prod = prod->next;
        }
    }
    free(aux);
    list->size--;

    if(i == 1) {
        printf("**** Cliente, %s, excluido(a) com sucesso! ****\n", nome);
        sleep(1.8);
    }
    free(nome);
}

/*
    Método que apaga e libera o espaço da 
    memória do cliente desejado.
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
            pop_produto_carrinho(aux, 0);
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

/* ====================================== PRODUTOS ======================================= */
/*
    Método que aloca o espaço na memória 
    e retorna o produto criado.
*/
Produto *create_produto() {
    Produto *p = (Produto *) malloc(sizeof(Produto));
    p->codigo = (char *) malloc(20);
    p->nome = (char *) malloc(50);
    p->next = NULL;
    return p;
}

/*
    Método que verifica se o código do produto é único.
*/
int verifica_unico_produto(List_Prod *plist, char *codigo) {
    Produto *p = plist->head;
    while (p) {
        if (strcmp(p->codigo, codigo) == 0) return 1;
        p = p->next;
    }
    return 0;
}

/*
    Método que inclui um produto na lista.
*/
void push_produto(List_Prod *plist, Produto *p, int i) {
    if(plist != NULL) {
        p->next = plist->head;
        plist->head = p;
        plist->size++;
        if(i == 0) {
            printf("\tProduto, %s, cadastrado com sucesso!\n\n", p->nome);
            sleep(1.8);
        }
        return;
	}

    printf("### Nao foi possivel cadastrar o produto! ###\n");
    sleep(1.8);
}

/*
    Método que permite cadastrar um produto.
*/
void menu_cadastro_produto(List_Prod *plist) {
    Produto *prod = create_produto();

    printf("Codigo: ");
    do {
        scanf(" %[^\n]", prod->codigo);
    } while (verifica_unico_produto(plist, prod->codigo));
    edita_informacao(prod->codigo, 3);

    printf("Nome: "); 
    scanf(" %[^\n]", prod->nome);
    edita_informacao(prod->nome, 2);

    printf("Preco: "); 
    scanf("%f", &prod->preco);
    printf("Quantidade: "); 
    scanf("%d", &prod->quantidade);

    push_produto(plist, prod, 0);
}

/*
    Método que imprime todos os produtos da lista.
*/
void print_produtos(List_Prod *plist, int i) {
    if(is_empty_plist(&plist)) { 
        printf("Lista vazia!\n");
        sleep(1.8);
        return;
    }
    Produto *prod = plist->head;

    printf("\n\n-------------- Lista de Produto(s) --------------\n"); 
    while(prod != NULL) {
        printf("           Codigo: %s\n", prod->codigo);
        printf("           Nome: %s\n", prod->nome);
        printf("           Preco: %.2f\n", prod->preco);
        printf("           Quantidade: %d\n", prod->quantidade);
        printf("--------------------------------------------------\n");
        prod = prod->next;
    }
    printf("Total de Produto(s): %d\n\n", plist->size);

    if(i == 1) { 
        char * liberar = (char *) malloc(sizeof(char));
        printf(":: Pressione ENTER para continuar ");
        getchar();
        scanf("%[^\n]", liberar);
        getchar();
        free(liberar);
    }
}

/*
    Método que permite buscar um produto 
    pelo código que o usuário digitar.
*/
Produto *buscar_produto_codigo(List_Prod *plist) {
    char busca[20] = {};
    Produto *prod = plist->head;
    
    printf("Codigo: ");
    scanf(" %[^\n]", busca);

    while (prod) {
        if (strcmp(prod->codigo, busca) == 0) 
            return prod;
        prod = prod->next;
    }
    return NULL;
}

/*
    Método que apresenta os dados de um produto.
*/
void visualizar_produto(List_Prod *plist, int i) {
    Produto *prod = buscar_produto_codigo(plist);

    if (prod != NULL) {
         printf("\n\tCodigo: %s\n", prod->codigo);
        printf("\tNome: %s\n", prod->nome);
        printf("\tPreco: %.2f\n", prod->preco);
        printf("\tQuantidade: %d\n", prod->quantidade);

        if(i == 1) {
            char * liberar = (char *) malloc(sizeof(char));
            printf("\n:: Pressione ENTER para continuar ");
            getchar();
            scanf("%[^\n]", liberar);
            getchar();
            free(liberar);
            return;
        }
    }

    printf("### Produto nao encontrado ###\n\n");
    sleep(2);    
}

/*
    Método que permite editar o produto.
*/
void edita_produto(Produto *prod, List_Prod *plist) {
    char novo_codigo[20]; 

    prod->codigo = (char *) realloc(prod->codigo, 20*sizeof(char));
    prod->nome = (char *) realloc(prod->nome, 50*sizeof(char));
    
    printf("-------------------------------------------------\n"); 
    do {
        printf("Digite o codigo: ");
        scanf(" %[^\n]", prod->codigo);
    } while (verifica_unico_produto(plist, prod->codigo) && strcmp(novo_codigo, prod->codigo) != 0);

    printf("Digite o nome: ");
    scanf(" %[^\n]", prod->nome);
        
    printf("Digite o preco: "); 
    scanf("%f", &prod->preco); 
    printf("Digite a quantidade: "); 
    scanf("%d", &prod->quantidade); 
    
    edita_informacao(prod->nome, 2);
    edita_informacao(prod->codigo, 3);

    printf("**** Editado com sucesso. ****\n");
    sleep(1.8);
}

/*
    Método que exclui o produto desejado.
*/
void exclui_produto(List_Prod *plist, Produto *produto) {
    Produto *aux = plist->head;
    Produto *aux_anterior = plist->head;
    int i = 0;

    while(aux != NULL) {
        if(strcmp(aux->codigo, produto->codigo) == 0) {
            if(i == 0) {
                pop_produto(plist, 1);
                break;
            } else {
                pop_index_produto(plist, aux_anterior, aux);
            }
        }
        i++;
        aux_anterior = aux;
        aux = aux->next;
    }
}

/*
    Método que exclui o último produto incluído no cliente. 
*/
void pop_produto(List_Prod *plist, int i) {
    Produto *prod_lixo = plist->head;
    char *nome = (char *) malloc(50 * sizeof(char));

    strcpy(nome, prod_lixo->nome);
    plist->head = prod_lixo->next;
    free(prod_lixo->nome);
    free(prod_lixo->codigo);
    free(prod_lixo);
    plist->size--;

    if(i == 1) {
        printf("**** Produto, %s, excluido com sucesso! ****\n", nome);
        sleep(1.8);
    }
    free(nome);
}

/*
    Método que exclui o produto.
*/
void pop_index_produto(List_Prod *plist, Produto *produto_anterior, Produto *produto_excluir) {
    Produto *prod_lixo = produto_excluir;
    char * nome = (char *) malloc(50 * sizeof(char));

    strcpy(nome, prod_lixo->nome);
    produto_anterior->next = prod_lixo->next;
    free(prod_lixo->nome);
    free(prod_lixo->codigo);
    free(prod_lixo);
    plist->size--; 

    printf("**** Produto, %s, excluido com sucesso! ****\n", nome);
    sleep(1.8);
    free(nome);
}

/* ======================================= CARRINHO ========================================== */
/*
    Método que adiciona produto ao carrinho do cliente.
*/
void adicionar_produto_ao_carrinho(List_Prod *plist, Cliente *cliente) {
    print_produtos(plist, 0);
    printf("::: Qual produto voce deseja incluir no carrinho ?\n");
    Produto *prod = buscar_produto_codigo(plist);
    if (prod == NULL) {
        printf("### Codigo nao encontrado ###\n");
        sleep(1.8);
        return;
    }
    int qt = 0;
    printf("Digite a quantidade: ");
    scanf("%d", &qt);
    if (qt > prod->quantidade || qt <= 0) {
        printf("\n### Quantidade invalida ###\n");
        sleep(1.8);
        return;
    }
    Produto *p_carrinho = busca_produto_carrinho_versao2(cliente, prod->codigo);

    if(p_carrinho == NULL) {
        Produto *novo = create_produto();
        strcpy(novo->codigo, prod->codigo);
        strcpy(novo->nome, prod->nome);
        novo->preco = prod->preco;
        novo->quantidade = qt;

        novo->next = cliente->carrinho;
        cliente->carrinho = novo;
        cliente->qt_produtos++;

        printf("\nProduto cadastrado!\n");
        sleep(1.9);
        
    } else {
        int soma = p_carrinho->quantidade + qt;

        if (soma <= prod->quantidade) {
            p_carrinho->quantidade += qt;
        } else {
            printf("\n### Quantidade indisponivel no estoque ###\n");
            sleep(1.8);
            return;
        }    
    }
}

/*
    Método que busca um produto no carrinho. 
*/
Produto *busca_produto_carrinho_versao2(Cliente *cliente, char *codigo) {
    Produto *p = cliente->carrinho;

    while (p != NULL) {
        if (strcmp(p->codigo, codigo) == 0) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}


/*
    Método que lista todos os produtos 
    do carrinho do cliente.
*/
void listar_carrinho_cliente(Cliente *cliente) {
    if(is_empty_produto(cliente)) {
        printf("Carrinho vazio!\n");
        sleep(1.8);
        return;
    }
    int qt_total_prod = 0;
    float valor_total = 0, valor = 0;
    Produto *produto = cliente->carrinho;
    
    printf("\n--------------------------- Produto(s) no Carrinho -------------------------\n");
    while(produto != NULL) {
        printf("\tCodigo: %s | ", produto->codigo);
        printf("Nome: %s | ", produto->nome);
        printf("Preco: %.2f | ", produto->preco);
        printf("Quantidade: %d\n", produto->quantidade);
        printf("---------------------------------------------------------------------------\n");
        qt_total_prod += produto->quantidade;
        valor = produto->preco * produto->quantidade;
        valor_total += valor;
        produto = produto->next;
    }
    printf("Quantidade total de itens: %d\n", qt_total_prod);
    printf("Valor total da compra: %.2f\n\n", valor_total);

    char *release = (char *) malloc(sizeof(char));
    printf(":: Pressione ENTER para continuar ");
    getchar();
    scanf("%[^\n]", release);
    getchar();
    free(release);
}

/*
    Método que verifica se o carrinho de 
    um cliente está vazio.
*/
int is_empty_produto(Cliente *cliente) {
    if(cliente->carrinho == 0)
        return 1;
    else
        return 0;
}  

/*
    Método que permite buscar um produto pelo 
    código no carrinho do cliente.
*/
Produto *busca_produto_carrinho(Cliente *cliente) {
    char *buscar;
    Produto *prod = cliente->carrinho;

    buscar = (char *) malloc(50 * sizeof(char));

    printf("Digite o codigo do produto --> ");
    scanf(" %[^\n]", buscar);

    while (prod != NULL) {
        if (strcmp(prod->codigo, buscar) == 0) {
            free(buscar);
            return prod;
        }  
        prod = prod->next;
    }
    free(buscar);
    return NULL;
}

/*
    Método que imprime todos os dados de 
    um produto do carrinho de um cliente.
*/
void print_p(Produto *produto) {
    printf("------------------------------ Dados do Produto ------------------------------\n");
    printf("\t\tCodigo: %s | ", produto->codigo);
    printf("Nome: %s | ", produto->nome);
    printf("Preco: %.2f | ", produto->preco);
    printf("Quantidade: %d\n", produto->quantidade);
    printf("------------------------------------------------------------------------------\n");
}


/*
    Método que remove produto do carrinho.
*/
void exclui_produto_carrinho(Cliente *cliente, Produto *produto, int qt) {
    Produto *aux = cliente->carrinho;
    Produto *aux_anterior = cliente->carrinho;
    int i = 0; 

    if (qt == produto->quantidade) {
        while(aux != NULL) {
            if(strcmp(aux->codigo, produto->codigo) == 0) {
                if(i == 0) {
                    pop_produto_carrinho(cliente, 1);
                    break;
                } else {
                    pop_index_produto_carrinho(cliente, aux_anterior, aux);
                }
            }
            aux_anterior = aux;
            aux = aux->next;
            i++;
        }
    } else { 
        produto->quantidade -= qt; 
    }   
}

/*
    Método que exclui o último produto 
    incluído no cliente. 
*/
void pop_produto_carrinho(Cliente *cliente, int i) { 
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
    Método que exclui o produto recebido 
    relacionado ao carrinho de um cliente.
*/
void pop_index_produto_carrinho(Cliente *cliente, Produto *produto_anterior, Produto *produto_excluir) {
    Produto *aux_prod = produto_excluir;
    char * nome = (char *) malloc(50 * sizeof(char));

    strcpy(nome, aux_prod->nome);
    produto_anterior->next = aux_prod->next;
    free(aux_prod->nome);
    free(aux_prod->codigo);
    free(aux_prod);
    cliente->carrinho--; 

    printf("**** Produto, %s, excluido com sucesso! ****\n", nome);
    sleep(1.8);
    free(nome);
}

/* ================================= Funções para Desalocar ================================= */

/*
    Método para desalocar espaço de mémoria de list.
*/
void free_lista_clientes(List *list) {
    if (list == NULL) 
        return;

    Cliente *cliente_atual = list->head;
    Cliente *cliente_prox = NULL;

    while (cliente_atual != NULL) {
        cliente_prox = cliente_atual->next;

        // libera campos dinâmicos do cliente
        free(cliente_atual->nome);
        free(cliente_atual->email);
        free(cliente_atual->telefone);

        // libera o carrinho do cliente
        Produto *p_atual = cliente_atual->carrinho;
        Produto *p_prox = NULL;

        while (p_atual != NULL) {
            p_prox = p_atual->next;
            free(p_atual->codigo);
            free(p_atual->nome);
            free(p_atual);
            p_atual = p_prox;
        }

        // libera o próprio cliente
        free(cliente_atual);

        cliente_atual = cliente_prox;
    }

    // libera a estrutura da lista
    free(list);
}

/*
    Método para desalocar espaço de mémoria de list_prod.
*/
void free_lista_produtos(List_Prod *list_prod) {
    if (list_prod == NULL) 
        return;

    Produto *prod_atual = list_prod->head;
    Produto *prox_prod = NULL;

    while (prod_atual != NULL) {
        prox_prod = prod_atual->next;

        free(prod_atual->codigo);
        free(prod_atual->nome);
        free(prod_atual);

        prod_atual = prox_prod;
    }

    free(list_prod);
}













