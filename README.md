# Descrição do Projeto

Esse repositório tem por finalidade a realização da Trabalho 4 da disciplina de Estrutura de Dados da FGV EMAp. O objetivo deste trabalho é implementar um Sistema de Autocomplete de Jogos utilizando os conhecimentos obtidos através das aulas e do material fornecido pelo professor. Foi requisitado que implementássemos a estrutura de dados Trie como estrtura principal do sistema. 

# Instruções de Compilação

Para compilar, deve-se utilizar o seguinte comando:

```bash
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```

# Instruções de Execução

Após a compilação, pode-se executar o comando:

```bash
./app k prefixo
```
No qual `k`é o número de jogos a ser retornado e `prefixo` é o prefixo do título do jogo que está sendo buscado.

# Organização dos Arquivos

O projeto está organizado nos seguntes arquivos:

Arquivos fornecidos pelo professor:
- `GamesDatabase.hpp`
- `GamesDatabase.cpp`
- `Game.hpp`
- `Game.cpp`
- `check_database.cpp`

Arquivos criados pelos alunos para realização do projeto:

- `Trie.hpp` : Onde é realizado a definição das classses.
- `Trie.cpp` : Onde as classes são implementadas.
- `main.cpp` : Driver Code do projeto.

# Exemplos de Uso

Caso se queira retornar os 3 primeiros jogos que começam com o prefixo "Th", então o comando a ser executado após a compilação é:

```bash
./app 3 Th
```
Há dois pontos a serem observados:

A busca é "case-insensitive", ou seja, a busca acima é equivalente a buscar das seguintes formas:

```bash
./app 3 th
```
```bash
./app 3 tH
```

O segundo ponto é que se quiser buscar um prefixo que possui um espaço no meio, o prefixo deve ser passado entre aspas:

```bash
./app 5 "The W"
```


