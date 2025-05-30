typedef char String[80];

typedef struct endereco Endereco;

typedef struct telefone Telefone;

typedef struct aniversario Aniversario;

typedef struct pessoa Pessoa;

// Limpa o buffer
void limpar_buffer();

Pessoa *criar_agenda(int size);

// Imprime os dados de uma certa pessoa na agenda
void imprimir_dados(Pessoa pessoa);

void imprimir_agenda_parcialmente(Pessoa *agenda, int qtd_pessoas);

void imprimir_agenda_completa(Pessoa *agenda, int qtd_pessoas);

// Busca na agenda por um nome que o usuário define
void buscar_nome(char *nome, Pessoa *agenda);

// Busca na agenda de acordo com o mẽs de nascimento
void buscar_mes(int mes, Pessoa *agenda);

// Busca na agenda de acordo com o dia e o mês de nascimento
void buscar_dia_mes(int dia, int mes, Pessoa *agenda);

// Insere uma pessoa nova na agenda
void inserir_pessoa(Pessoa *agenda, int *qtd_pessoas);

void remover_pessoa(Pessoa *agenda, int *qtd_pessoas, char *nome);
