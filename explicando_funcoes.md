PLANO PARA CADA FUNÇÃO ATUALMENTE

# Planos atuais:

- Reformular inicializar_lista() para inicializar todo o objeto escola.
    - escola->lista_individuos  escola->lista_disciplinas (Adicionar uma forma de diferenciar doscentes de discentes).

- Retirar os parâmetros de tamanho da list para a maioria das funções.
    - Algumas funções como as de ordenação se beneficiam dos parâmetros, ainda
    a considerar o que fazer.

- Dividir a função cadastrar em duas.
    - Indivíduos e disciplinas

# escola.c

## cadastrar (WIP)

Dividir em duas funções:
- cadastrar_individuo(individuo* lista)
- cadastrar_disciplina(disciplina* lista)

Elas deverão receber:  
- uma lista (individuos ou disciplinas).

Dentro das funções chamar:

- procura_vaga(void* lista, size_t tam, uint8_t tipo) 
    - Retorna o index pra uma vaga vazia na lista

    - Escolhe vaga vazia para preencher
        - Necessita que inicializar_lista(void* lista, size_t tam, uint8_t tipo)
        seja chamada antes para inicializar a lista com vagas limpas.

- input_individuo(individuo* ptr_individuo, size_t index)
    - Recebe input para um elemento da lista de indivíduos e seu index

    - Precisa do index para gerar a matrícula.

    - lista[i], i   <- Exemplos de inputs

- input_disciplina(individuo*, index)
    - Recebe input para um elemento da lista de disciplinas e seu index

    - Precisa do index para gerar a matrícula.

    - lista[i], i   <- Exemplos de inputs


### inicializar_lista(escola* lista) # LOCAL # COMO PLANEJO DEIXAR.

Alterar funcionamento:

- Receber um objeto **escola* escola** e inicializar ambas as listas de uma vez.
Deve receber:

- Uma lista (individuos ou disciplinas). # A SER ALTERADO

- O tamanho da lista. # DEVERÁ RECEBER DOIS TAMANHOS OU ADICIONAR A INFORMAÇÃO
DENTRO DA OBJETO **escola* escola**
    - Opção extra: Simplesmente utilizar as macros. Isso, inclusive, reduz o
    tanto de parâmetros para cada função.

- O tipo da lista (INDIVIDUO ou DISCIPLINA).

Deve ser chamado dentro da mesma função em que o objeto escola. # Adicionar o tamanho das listas na struct escola, ou usar macro


### input_individuo(individuo* ptr_i) # LOCAL


Recebe o endereço de um indivíduo da lista e o seu respectivo index.

Recebe inputs do usuário para cada membro da struct do individuo.

Planejado para ser utilizado dentro da função cadastro_individuo 

Versão para indivíduos da função input_disciplina (WIP).

# relatorio.c

## lista_individuos(individuo* lista, size_t tam, ordenar_i ord, uint8_t eh_dos)


Deve receber: 

- Uma lista de individuos

- O tamanho da lista 

- Uma função de ordenação. // Pode ser omitida passando NULL.

- Se é DISCENTE ou DOSCENTE

Printa as informações dos individuos

- Chama output_individuo() para printar informaçẽos de um indivído

## listar_disciplinas(disciplina* lista, size_t tam, ordenar_d ord)

Recebe uma lista de disciplinas, o tamanho da lista e uma função de ordenação.
A função de ordenação pode ser omitida usando NULL.

- Chama output_disciplina() para printar informações de uma disciplina.

## ord_data(individuo* buff_l, size_t tam)


Recebe uma lista de individuos e o tamanho dessa lista. Preferivelmente deve ser
utilizada como parâmetro para lista_individuos para ordenar um buffer da lista.

Ordena a lista por ordem de data de nascimento.

Retorna o tamanho normal da lista, sem alterações.

Caso acho interessante, é possível tornar global.

## aniversariantes(individuo* buff_l, size_t tam)

Recebe uma lista de indivíduos e o seu tamanho. Preferivelmente deve ser
utilizada como parâmetro para lista_invididuos para ordenar um buffer da lista.

Ordena a lista dando prioridade aos aniversariantes do mês.

Retorna a contagem de estudantes que fazem aniversário do mês para printar
somente esses.

## ord_tres_disciplinas(individuo* buff_l, size_t tam)

Recebe uma lista de indivíduos e o seu tamanho. Preferivelmente deve ser
utilizada como parâmetro para lista_invididuos para ordenar um buffer da lista.

Ordena a lista dando prioridade aos estudantes com menos de três disciplinas.

Retorna a contagem de estudantes que posuem menos de três disciplinas para 
printar somente esses.


### inverter_data(data tmp) # LOCAL

Transforma a data da struct data (Dia Mês Ano) em um único inteiro (Ano Mẽs Dia)
para facilitar na ordenação por data. Função local

### output_individuo(individuo pessoa) # LOCAL

Recebe um individuo da lista de indivíduos e printa suas informações.
Desenhada pra ser chamada dentro de listar_individuos (já em uso).

### output_individuo(disciplina disciplina)
Recebe um disciplinas da lista de disciplinas e printa suas informações.
Desenhada pra ser chamada dentro de listar_disciplinas (já em uso).

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

