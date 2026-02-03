#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "structs_trabalho_final.h"

void main_trabalho_final();
List *create_list();
void menu_principal(List *list);
void menu_cliente(List *list);
void menu_produto();
void menu_encerra();
void menu_cadastro_cliente(List *list);
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
void pop_produto(Cliente *cliente, int i);
void pop_index_cliente(List * list, Cliente *cliente_anterior, Cliente *cliente_excluir);

#endif
