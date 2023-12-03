#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct tp_autor {
    char nome_autor[50];
    char nacionalidade_autor[50];
};

struct tp_data {
    int dia;
    int mes;
    int ano;
};

struct tp_livro {
    char titulo_livro[50];
    int n_pagina;
    char estilo[50];
    char nome_editora[50];
    struct tp_autor autor;
    struct tp_data data;
};

int chaveExiste(struct tp_livro* lista, int tamanho, char* chave) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (strcmp(lista[i].titulo_livro, chave) == 0) {
            return 1;
        }
    }
    return 0;
}

void inserir(struct tp_livro** lista, int* tamanho) {
    struct tp_livro novolivro;
    printf("\n\n---Cadastro de Livros---\n\n");

    printf("\n\n Titulo do livro.......: ");
    fflush(stdin);
    gets(novolivro.titulo_livro);

    if (chaveExiste(*lista, *tamanho, novolivro.titulo_livro)) {
        printf("Chave j� cadastrada.Tente Novamente.\n");
        return;
    }

    printf("\n\n N�mero de Paginas.......: ");
    scanf("%d", &novolivro.n_pagina);

    printf("\n\n Estilo do livro.......: ");
    fflush(stdin);
    gets(novolivro.estilo);

    printf("\n\n Nome da Editora.......: ");
    fflush(stdin);
    gets(novolivro.nome_editora);

    printf("\n\n Nome do Autor .......: ");
    fflush(stdin);
    gets(novolivro.autor.nome_autor);

    printf("\n\n Nacionalidade do Autor .......: ");
    fflush(stdin);
    gets(novolivro.autor.nacionalidade_autor);

    printf("\n\n Dia do Cadastramento .......: ");
    scanf("%d", &novolivro.data.dia);
    while(novolivro.data.dia<1||novolivro.data.dia>31){
    	printf("Dia invalido, Digite Novamente\n");
    	scanf("%d", &novolivro.data.dia);
    	
	}

    printf("\n\n M�s do Cadastramento .......: ");
    scanf("%d", &novolivro.data.mes);
    while(novolivro.data.mes<1||novolivro.data.mes>12){
    	printf("M�s invalido,Digite Novamente\n");
    	scanf("%d",&novolivro.data.mes);
	}

    printf("\n\n Ano do Cadastramento  .......: ");
    scanf("%d", &novolivro.data.ano);
    while(novolivro.data.ano!=2023){
    	printf("Ano invalido,Digite Novamente\n");
    	scanf("%d",&novolivro.data.ano);
	}

    *lista = realloc(*lista, (*tamanho + 1) * sizeof(struct tp_livro));

    if (*lista == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    (*lista)[*tamanho] = novolivro;
    (*tamanho)++;
	system("cls");
    printf("Registro inserido com sucesso!\n");
    
    
}

void listar(struct tp_livro* lista, int tamanho) {
    printf("\n\n--- Lista de Livros ---\n\n");

    if (tamanho == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    
	int i;
    for (i = 0; i < tamanho; i++) {
        printf("Livro %d:\n", i + 1);
        printf("  T�tulo: %s\n", lista[i].titulo_livro);
        printf("  N�mero de P�ginas: %d\n", lista[i].n_pagina);
        printf("  Estilo: %s\n", lista[i].estilo);
        printf("  Nome da Editora: %s\n", lista[i].nome_editora);
        printf("  Autor: %s\n", lista[i].autor.nome_autor);
        printf("  Nacionalidade do Autor: %s\n", lista[i].autor.nacionalidade_autor);
        printf("  Data de Cadastramento: %02d/%02d/%d\n", lista[i].data.dia, lista[i].data.mes, lista[i].data.ano);
        printf("\n");
    }
}

void salvarArquivo(struct tp_livro* lista,int tamanho){
	FILE * arquivo= fopen("CadastroLivros.txt","w");
	
	if(arquivo==NULL){
		printf("Erro ao abrir o arquivo para escrita.\n");
		exit(EXIT_FAILURE);
	}
	fprintf(arquivo,"%d\n",tamanho);
	int i;
	for(i=0;i<tamanho;i++){
		fprintf(arquivo,"%s %d %s %s %s %s %d %d %d\n",
		lista[i].titulo_livro, lista[i].n_pagina, lista[i].estilo,
        lista[i].nome_editora, lista[i].autor.nome_autor,
        lista[i].autor.nacionalidade_autor,
        lista[i].data.dia, lista[i].data.mes, lista[i].data.ano
		);
	}
	fclose(arquivo);
}

void carregarArquivo(struct tp_livro** lista, int* tamanho) {
    FILE* arquivo = fopen("CadastroLivros.txt", "r");

    if (arquivo == NULL) {
        // Se o arquivo n�o existir, cria um vetor vazio
        *lista = NULL;
        *tamanho = 0;
        return;
    }

    fscanf(arquivo, "%d", tamanho);

    *lista = malloc(*tamanho * sizeof(struct tp_livro));
    if (*lista == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        exit(EXIT_FAILURE);
    }
	int i;
    for ( i = 0; i < *tamanho; i++) {
        fscanf(arquivo, "%s %d %s %s %s %s %d %d %d",
               (*lista)[i].titulo_livro, &(*lista)[i].n_pagina, (*lista)[i].estilo,
               (*lista)[i].nome_editora, (*lista)[i].autor.nome_autor,
               (*lista)[i].autor.nacionalidade_autor,
               &(*lista)[i].data.dia, &(*lista)[i].data.mes, &(*lista)[i].data.ano);
    }

    fclose(arquivo);
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    struct tp_livro* lista = NULL;
    int tamanho = 0;
    
    carregarArquivo(&lista,&tamanho);

    int menu = 1;

    while (menu == 1) {
        printf("Cadastro de Livros\n Escolha uma opcao:\n");
        printf("-> (1) Inserir um novo livro\n");
        printf("-> (2) Listar todos os livros\n");
        printf("-> (3) Consultar um livro\n");
        printf("-> (4) Remover um livro\n");
        printf("-> (5) Sair\n");

        int opcaomenu;
        scanf("%d", &opcaomenu);

        switch (opcaomenu) {
            case 1:
                printf("Fun��o inserir\n");
                inserir(&lista, &tamanho);
                
                break;
            case 2:
                printf("Fun��o listar\n");
                listar(lista, tamanho);
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                menu = 0;
                break;
            default:
                printf("Opc�o inv�lida. Tente novamente.\n");
        }
    }
	salvarArquivo(lista, tamanho);
    free(lista);

    return 0;
}

