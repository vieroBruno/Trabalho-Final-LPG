#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */

int main() {
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


