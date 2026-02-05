#ifndef STRUCTS_TRABALHO_FINAL_H
#define STRUCTS_TRABALHO_FINAL_H

#include <stdlib.h>

/* ===================== DATA ===================== */

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

/* ===================== PRODUTO ===================== */

typedef struct produto {
    char *codigo;
    char *nome;
    float preco;
    int quantidade;
    struct produto *next;
} Produto;

/* ===================== CLIENTE ===================== */

typedef struct cliente {
    char cpf[15];
    char *nome;
    char *email;
    char *telefone;
    Data nascimento;
    int qt_produtos;
    struct cliente *next;
    Produto *carrinho;
} Cliente;

/* ===================== LISTA DE CLIENTES ===================== */

typedef struct list {
    Cliente *head;
    int size;
} List;

/* ===================== LISTA DE PRODUTOS ===================== */

typedef struct list_prod {
    Produto *head;
    int size;
} List_Prod;

#endif
