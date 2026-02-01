#ifndef STRUCTS_TRABALHO_FINAL_H
#define STRUCTS_TRABALHO_FINAL_H

#include <stdlib.h>

typedef struct list {
	struct cliente *head; 
	int size;
}List;

typedef struct cliente {
    char cpf[15];
    char *nome;
    char *email;
    char *telefone;
    struct data nascimento; 
    int qt_produtos;
    struct cliente *next;
    struct produto *lista_produtos; 
}Cliente;

typedef struct data {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct produto {
    char *codigo;
    char *nome;
    float preco;
    int quantidade;
    struct produto *next;
}Produto;

#endif

