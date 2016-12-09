/*
 * UNIPÊ - Centro Universiátio de João Pessoa
 * Curso: Ciência da Computação - 2° Período - Turma B / 2016
 * Disciplina: Introdução a Linguagem de Programação - 3° Estágio - Projeto Final.
 * Professor: Renato Leite
 * Grupo C.
 * Jogo da Forca.
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
/* Bibliotecas Personalizadas */
#include "funcoes.h"
#include "interface.h"

int main() {
    char entrar;
    unsigned short int repetir = 1;
    abre_arquivo_bin();
    while (repetir){
        system("cls || clear");
        tela();
        entrar = validar_escolha();
        switch(entrar) {
            case '1':
            system("cls || clear");
            unsigned short int contar_p = contar_palavras();
            if (contar_p > 0){
                adicionar_nome();
                jogo();
            } else {
                printf("Nao ha palavras cadastradas no jogo!\n");
                printf("\nSelecione a opcao [3], cadastre suas palavras e divirta-se!\n");
            }
            printf("\nPressione qualquer tecla para continuar...");
            getch();
            break;
            case '2':
            system("cls || clear");
            printf("Ranking do Jogo");
            mostrar_ranking();
            break;
            case '3':
            system("cls || clear");
            adicionar_palavra();
            break;
            case '4':
            system("cls || clear");
            creditos();
            break;
            case '5':
            system("cls || clear");
            printf("O jogo foi finalizado.");
            printf("\n\nPressione qualquer tecla para finalizar...\n");
            getch();
            sair();
            break;
            default:
            system("cls || clear");
            printf("Opcao Invalida!");
            printf("\n\nPressione qualquer tecla para continuar...");
            getch();
        }
    }
    return 0;
}
