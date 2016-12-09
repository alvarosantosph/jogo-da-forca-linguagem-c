#ifndef FUNCOES_H
    #define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

FILE *arqrank;

/* Protótipos das funções */
char validar_escolha();
void adicionar_palavra();
void gravar_palavra(char *vetor_palavra);
void gravar_dica(char *vetor_dica);
int valida_palavra(char *verifica);
int contar_palavras();
void adicionar_nome();
void abre_arquivo_bin();
void gravar_ranking();
void mostrar_ranking();
void dados();

#endif
