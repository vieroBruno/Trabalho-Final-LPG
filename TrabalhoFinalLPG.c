#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct tp_autor{
	char nome_autor[50];
	char nacionalidade_autor[50];
};
struct tp_data{
		
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

void inserir(){
	struct tp_livro livro;
	printf("\n\n---Cadastro de Livros---\n\n");
	
	printf("\n\n Titulo do livro.......: ");
	fflush(stdin);
	gets(livro.titulo_livro);
	
	printf("\n\n Número de Paginas.......: ");
	scanf("%d",&livro.n_pagina);
	
	printf("\n\n Estilo do livro.......: ");
	fflush(stdin);
	gets(livro.estilo);
	
	printf("\n\n Nome da Editora.......: ");
	fflush(stdin);
	gets(livro.nome_editora);
	
	printf("\n\n Nome do Autor .......: ");
	fflush(stdin);
	gets(livro.autor.nome_autor);
	
	printf("\n\n Nacionalidade do Autor .......: ");
	fflush(stdin);
	gets(livro.autor.nacionalidade_autor);
	
	printf("\n\n Dia do Cadastramento .......: ");
	scanf("%d",&livro.data.dia);
	
	printf("\n\n Mês do Cadastramento .......: ");
	scanf("%d",&livro.data.mes);
	
	printf("\n\n Ano do Cadastramento  .......: ");
	scanf("%d",&livro.data.ano);
	
	
}

int main() {
	setlocale(LC_ALL, "Portuguese");

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
                printf("Função inserir");
                inserir();
                break;
            case 2:
               
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                menu = 0; 
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}


