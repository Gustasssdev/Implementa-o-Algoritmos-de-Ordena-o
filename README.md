# Implementação e Comparação de Algoritmos de Ordenação

## Sobre o projeto

Este projeto foi desenvolvido como parte do **1º Trabalho Prático da disciplina Projeto e Análise de Algoritmos**, do curso de Bacharelado em Ciência da Computação da Universidade Federal do Piauí (UFPI).

O objetivo é implementar e comparar algoritmos de ordenação, analisando suas complexidades teóricas e seus tempos de execução em diferentes condições de entrada.

## Algoritmos implementados

Foram implementados quatro algoritmos de ordenação em C++:

- **Bubble Sort:** algoritmo de ordenação por comparação que realiza trocas entre elementos adjacentes.
- **Merge Sort:** algoritmo de ordenação por comparação baseado na estratégia de divisão e conquista.
- **Counting Sort:** algoritmo de ordenação por contagem que utiliza um vetor auxiliar para registrar as frequências dos valores.
- **Radix Sort:** algoritmo de ordenação que processa os dígitos dos números, utilizando uma ordenação estável em cada etapa.

As implementações foram desenvolvidas manualmente, sem utilizar funções prontas de ordenação.

## Análise experimental

Os algoritmos são avaliados por meio do tempo de execução, permitindo comparar seu desempenho e observar a influência do tamanho do vetor e do intervalo de valores utilizados.

Os resultados experimentais podem ser utilizados para verificar a relação entre a complexidade teórica e o comportamento observado na prática, destacando as vantagens e limitações de cada algoritmo.

## Tecnologias utilizadas

- **Linguagem:** C++
- **Compilador:** g++
- **Ambiente de desenvolvimento:** Linux

## Compilação e execução

Para compilar um dos programas pelo terminal, utilize:

```bash
g++ arquivo.cpp -o programa
```

Em seguida, execute:

```bash
./programa
```

Substitua `arquivo.cpp` pelo nome do arquivo-fonte desejado. Caso o programa utilize vários arquivos, compile-os em conjunto conforme a estrutura do projeto.

## Autores

- Adicione aqui os nomes dos integrantes do grupo.

**Instituição:** Universidade Federal do Piauí (UFPI)  
**Disciplina:** Projeto e Análise de Algoritmos  
**Professor:** Carlos André Batista de Carvalho
