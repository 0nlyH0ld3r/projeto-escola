# escola.c

## cadastrar (WIP)
```
void cadastrar(void* lista, int index, uint8_t tipo);
```

Recebe uma lista, o index e o tipo da lista (INDIVIDUO ou DISCIPLINA.

Pode receber matrícula em index para utilizar como uma função de atualizar.

Cria um invidíduo. (Professor ou Aluno).


### inicializar_lista

```
void inicializar_lista(void* lista, size_t tam, uint8_t tipo);
```

Recebe uma lista, o tamanho e o tipo da lista (INDIVIDUO ou DISCIPLINA).

Configura o membro {.estado} da estrutura de cada elemento da lista para NAO_ATIVO.

Permite o uso da lista sem que lixo afete os resultados.

### input_individuo

```
void input_individuo(individuo* lista, int index)
```

Recebe uma lista de indivíduo e o index de um elemento da lista.

Realiza inputs para cada membro da struct individuo no elemento da lista passado por index.

Planejado para ser utilizado dentro da função cadastro para receber o input de algum individuo.

Versão para indivíduos da função input_disciplina (WIP).

# relatorio.c

## lista_individuos

```
void listar_individuos(individuo* lista, size_t tam, ordenar ordenacao);
```

Recebe uma lista de individuos, o tamanho da lista e uma função de ordenação. A função pode ser omitida usando NULL.

Printa as informações dos individuos (Adicionar uma forma de diferenciar doscentes de discentes).

## listar_disciplinas

```
void listar_disciplinas(disciplina* lista, size_t tam, ordenar ordenacao);
```

O mesmo que a função acima, mas somente pra disciplinas.

## ordenar_data

```
void ordenar_data(individuo* buff_lista, size_t tam);
```

Recebe uma lista de individuos e o tamanho dessa lista.

Preferivelmente deve ser utilizada como parâmetro para lista_individuos.

Ordena a lista por ordem de data.

## compara_datas

```
static int compara_datas(data data1, data data2);
```

Recebe duas structs do tipo data.

Compara 2 datas (ano, mês e dia).

Retorna true caso dia, mês ou ano de data1 seja menor que DMA de data2.

Retorna false caso data2 seja maior.

Função local (static) somente para uso em ordenar_data.

Caso acho interessante, é possível tornar global.

# utilidades.c

## scanf_limpo_simples

```
void scanf_limpo_simples(const char* format, void* variavel);
```

Recebe uma string de formatação ("%d", "%f" ou "%s") e uma variável do respectivo tipo.

Recebe o tipo de dado formatado na variável de mesmo tipo.

Limpa o buffer após a leitura.

Retorna vazio (diferente de scanf que retorna o número de caracteres lidos).

## input_string

```
void input_string(char* string, size_t tam);
```

Recebe uma string e seu tamanho.

Lê de STDIN o input pra string.

Retira o '\n' da string (caso houver).

## compara_strins

```
int compara_strings(const char* string1, const char* string2);
```

Recebe duas strings.
Retorna **true** se forem iguais e **false** se não.

## procura_vaga

```
int procura_vaga (const void* lista, size_t tam, uint8_t tipo);
```

Recebe uma lista genérica, tamanho e seu tipo. ('p' = Pessoa', 'd' = disciplina)
Retorna o index para um espaço disponível na lista ou LISTA_CHEIA caso não houver.

## input_char_non_canon

```
int input_char_non_canon(void);
```

Retorna inteiros com o valor do ASCII lido (caracteres).

