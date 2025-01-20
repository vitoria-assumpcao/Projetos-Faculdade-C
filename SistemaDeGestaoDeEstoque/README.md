# Atividade Prática Sistema de Gestão de Estoque

## Descrição
Esta aplicação em C é um sistema simplificado de gestão de estoque para farmácias. Ele inclui funcionalidades para autenticação de usuário, cadastro de produtos, busca, exibição de estoque e encerramento do programa.

## Funcionalidades

### 1. Autenticação de Usuário
- Exibe um cabeçalho informativo ao iniciar o programa.
- Solicita nome de usuário e senha.
- Valida as credenciais utilizando uma estrutura `Autenticacao`:
  ```c
  struct Autenticacao a1 = { 4258, 123456 };
  ```
- Repete a solicitação até que a autenticação seja bem-sucedida.
- Limpa a tela e avança para o controle de estoque após autenticação.

### 2. Controle de Estoque
Após autenticação, apresenta um menu com as seguintes opções:
1. Cadastro de Produto
2. Busca de Produto
3. Exibir Estoque de Produtos
4. Sair do Programa

#### 2.1 Cadastro de Produto
- Solicita informações sobre o produto (nome e outros dados relevantes).
- Armazena os produtos em um arranjo global com limite de 50 elementos.
- Controla o índice dos produtos cadastrados com uma variável global.
- Informa ao usuário que o produto foi cadastrado com sucesso.
- Permite o cadastro de mais produtos ou retorno ao menu de controle de estoque.

#### 2.2 Busca de Produto
- Solicita o nome do produto a ser consultado.
- Exibe os dados do produto encontrado.
- Informa ao usuário caso o produto não seja encontrado.
- Permite realizar novas buscas ou retornar ao menu de controle de estoque.

#### 2.3 Exibir Estoque de Produtos
- Lista todos os produtos cadastrados.
- Informa ao usuário caso o estoque esteja vazio.
- Permite retornar ao menu de controle de estoque após a exibição.

#### 2.4 Sair do Programa
- Solicita confirmação do usuário antes de encerrar.
- Usa a função `exit(1)` para finalizar o programa (necessário incluir `stdlib.h`).

## Critérios de Avaliação
1. **Autenticação do usuário**: 2,0 pontos
2. **Controle de estoque**: 1,5 pontos
3. **Cadastro de produto**: 2,0 pontos
4. **Busca de produto**: 2,0 pontos
5. **Exibição dos produtos**: 1,5 pontos
6. **Saída do programa**: 1,0 ponto

## Entrega
- A atividade deve ser entregue até **29/07/2024 às 23:55**.
- Submeter um arquivo `.zip` contendo o projeto implementado (código-fonte).
- **Não serão aceitos links para repositórios de arquivos.**

---
**Bom trabalho!**


