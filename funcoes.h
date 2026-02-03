#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "structs_trabalho_final.h"

void main_trabalho_final();
List *create_list();
List_Prod *create_product_list();
void menu_principal(List *list, List_Prod *plist);
void menu_cliente(List *list);
void menu_produto(List_Prod *plist);
<<<<<<< HEAD
void menu_compra(List_Prod *plist, Cliente *cliente);
void dados_cliente(Cliente *cliente);
=======
void menu_compra(List *list, List_Prod *plist);
>>>>>>> e32ecf0 (feat: adiciona parâmetros, declarações de CRUD de produtos e funções auxiliares em funcoes.h)
void menu_encerra();
void menu_cadastro_cliente(List *list);

/* Cliente */
Cliente *create_cliente();
void edita_informacao(char *nome, int x);
void push(List * list, Cliente *cliente, int i);
void print_list(List *, int);
int is_empty(List **list);
int verifica_unico(List *list, char cpf[]);
Cliente *buscar_cliente_cpf(List * list);
void visualizar_cliente(List * list, int i);
void edita_cliente(Cliente *cliente, List *list);
void exclui_cliente(List *list, Cliente *cliente);
void pop_cliente(List * list, int i);
void pop_index_cliente(List * list, Cliente *cliente_anterior, Cliente *cliente_excluir);

/* Produtos */
Produto *create_produto();
<<<<<<< HEAD
void push_produto(List_Prod *plist, Produto *p, int i);
void menu_cadastro_produto(List_Prod *plist);
void print_produtos(List_Prod *plist, int i);
int verifica_unico_produto(List_Prod *plist, char *codigo); 
Produto *buscar_produto_codigo(List_Prod *plist);
void visualizar_produto(List_Prod *plist, int i);
void edita_produto(Produto *prod, List_Prod *plist);
void exclui_produto(List_Prod *plist, Produto *produto);
void pop_produto(List_Prod *plist, int i);
void pop_index_produto(List_Prod *plist, Produto *produto_anterior, Produto *produto_excluir);
int is_empty_plist(List_Prod **plist);

/* Carrinho */
void adicionar_produto_ao_carrinho(List_Prod *plist, Cliente *cliente);
void listar_carrinho_cliente(Cliente *cliente);
int is_empty_produto(Cliente *cliente);
void exclui_produto_carrinho(Cliente *cliente, Produto *produto, int qt);
Produto *busca_produto_carrinho(Cliente *cliente);
void print_p(Produto *produto);
void pop_index_produto_carrinho(Cliente *cliente, Produto *produto_anterior, Produto *produto_excluir);
void pop_produto_carrinho(Cliente *cliente, int i);
Produto *busca_produto_carrinho_versao2(Cliente *cliente, char *codigo);

void free_lista_clientes(List *list);
void free_lista_produtos(List_Prod *list_prod);

=======
void push_produto(List_Prod *plist, Produto *produto, int i);
void menu_cadastro_produto(List_Prod *plist);
void print_produtos(List_Prod *plist, int i);
int verifica_unico_produto(List_Prod *plist, char codigo[]);
Produto *buscar_produto_codigo(List_Prod *plist);
void visualizar_produto(List_Prod *plist, int i);
void edita_produto(Produto *produto, List_Prod *plist);
void exclui_produto(List_Prod *plist, Produto *produto);
void pop_produto_catalog(List_Prod *plist, int i);
void pop_index_produto(List_Prod *plist, Produto *produto_anterior, Produto *produto_excluir);

/* Carrinho / Compra */
void adicionar_produto_ao_carrinho(List *list, List_Prod *plist);
void listar_carrinho_cliente(Cliente *cliente);
void remover_produto_do_carrinho(List *list, List_Prod *plist);
>>>>>>> e32ecf0 (feat: adiciona parâmetros, declarações de CRUD de produtos e funções auxiliares em funcoes.h)

#endif
