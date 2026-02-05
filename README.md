# Trabalho Prático — Listas Encadeadas em C

## Autores

- **GEOVANNA RODRIGUES DE BRITO**  
  Matrícula: **202017601**

- **ISAQUE SANTOS**  
  Matrícula: **211061903**

---

## Descrição

Este trabalho consiste no desenvolvimento de um sistema em **linguagem C**, executado no **terminal**, que utiliza **listas simplesmente encadeadas** para armazenar e manipular dados de forma dinâmica.

O sistema implementa as operações de **CRUD** para o gerenciamento de **clientes** e **produtos**, além de um **modo de compra**, conforme proposto na disciplina.

---

## Funcionalidades

### Clientes
- Cadastrar cliente (CPF, nome, e-mail, telefone e data de nascimento);
- Listar todos os clientes cadastrados;
- Buscar cliente pelo CPF;
- Editar dados de um cliente;
- Remover cliente.

### Produtos
- Cadastrar produto (código único, nome, preço e quantidade);
- Listar todos os produtos cadastrados;
- Buscar produto pelo código;
- Editar dados de um produto;
- Remover produto.

### Modo Compra
- Realizar compra de produtos disponíveis;
- Atualizar automaticamente a quantidade em estoque.

---

## Tecnologias Utilizadas
- Linguagem **C**
- Listas simplesmente encadeadas
- Estruturas (`struct`)
- Alocação dinâmica de memória
- Menu interativo com `switch case`

---

## Como Compilar e Executar

No terminal, execute:

```bash
gcc -Wall main_trabalho_final.c funcoes.c -o trabalho_final
./trabalho_final

