#include "funcoes.h"

#define TAM_P 100
#define MAX_P 20

/* Estrutura para armazenamento no arquivo binário */
typedef struct{
    char nome[25];
    unsigned short int pontos;
}ranking;
ranking rank;

/* Função: Validar Escolha */
char validar_escolha() {
    unsigned short int j, pw = 0;
    char opcao[50], c = NULL;
    memset(opcao, 0, sizeof(opcao));
    do {
        printf("Digite uma opcao: ");
        scanf("%50s", opcao);
        fflush(stdin);
        j = strlen(opcao);
        if (j > 1) {
            printf("\nDigite apenas 1 caractere [numero].\n\n");
            printf("Pressione qualquer tecla para continuar ...\n\n");
            getch();
        }
    } while (j > 1);
    if (j == 1) {
    if (isdigit(opcao[0]) != 0) {
        pw = 1;
        }
    } else {
        pw = 2;
    }
    if (pw == 1) {
        c = opcao[0];
    }
    if (pw == 2) {
        c = 0;
    }
    return c;
}
/* Função: Tratamento da palavra antes de ser inserida no arquivo de texto */
void adicionar_palavra(){
    char continuar_op = 'S';
    unsigned short int contar_pp = contar_palavras();
    char valida_entrada3[300];
    unsigned short int contador_entrada3;
    while (continuar_op == 'S' && contar_pp <= TAM_P){
        if (contar_pp >= TAM_P){
        printf("\nO numero maximo de palavras cadastradas foi atingido [max 100]!\n");
        break;
        } else {
            char palavra_adicionada[MAX_P];
            char dica[MAX_P];
            memset(palavra_adicionada, 0, sizeof(palavra_adicionada));
            memset(dica, 0, sizeof(dica));
            unsigned short int tamanho, tamanho2, verifica, verifica2;
            /* Laço para verificar palavra */
            do {
                printf("Numero de Palavras Cadastradas: %d\n", contar_pp);
                printf("\nAdicionar palavra no jogo [Max 20 Letras]: ");
                /* Limpar buffer do teclado */
                setbuf(stdin,NULL);
                scanf("%s", palavra_adicionada);
                tamanho = strlen(palavra_adicionada);
                verifica = valida_palavra(palavra_adicionada);
                if (tamanho > MAX_P){
                    printf("\nDigite no maximo 20 caracteres!\n\n");
                    printf("Pressione qualquer tecla para continuar ...\n\n");
                    getch();
                    system("cls || clear");
                }
                if (verifica == 1){
                    printf("\nDigite apenas letras!\n\n");
                    printf("Pressione qualquer tecla para continuar ...\n\n");
                    getch();
                    system("cls || clear");
                }
                if (tamanho == 0) {
                    printf("\nVoce deve digitar pelo menos uma palavra.\n\n");
                }
            }  while(tamanho > MAX_P || tamanho == 0 || verifica == 1);
            /* Laço para verificar dica */
            do {
                printf("\nAdicionar dica [Max 20 Letras]: ");
                /* Limpar buffer do teclado */
                setbuf(stdin,NULL);
                scanf("%s", dica);
                tamanho2 = strlen(dica);
                verifica2 = valida_palavra(dica);
                if (tamanho2 > MAX_P){
                    printf("\nDigite no maximo 20 caracteres!\n\n");
                    printf("Pressione qualquer tecla para continuar ...\n\n");
                    getch();
                }
                if (verifica2 == 1){
                    printf("\nDigite apenas letras!\n\n");
                    printf("Pressione qualquer tecla para continuar ...\n\n");
                    getch();
                }
                if (tamanho2 == 0) {
                    printf("\nVoce deve digitar pelo menos uma dica.\n\n");
                }

            } while(tamanho2 > MAX_P || tamanho2 == 0 || verifica2 == 1);
            gravar_palavra(palavra_adicionada);
            gravar_dica(dica);
            system("cls || clear");
            printf("Palavra Adicionada com Sucesso!\n\n");

            do {
                do {
                    printf("Deseja adicionar outra palavra (S/N)? ");
                    setbuf(stdin,NULL);
                    scanf("%s", valida_entrada3);
                    contador_entrada3 = strlen(valida_entrada3);
                    continuar_op = valida_entrada3[0];
                    continuar_op = toupper(continuar_op);
                    if (contador_entrada3 > 1) {
                        printf("\nDigite apenas um caractere.\n");
                    }
                    if (continuar_op != 'N' || continuar_op != 'S') {
                        printf("\nDigite [S] para adicionar outra palavra ou [N] para sair.\n\n");
                    }
                } while (contador_entrada3 > 1);
                if (continuar_op == 'N') {
                    break;
                }
            } while (continuar_op != 'S');
            system("cls || clear");
        }
        contar_pp++;
        if (contar_pp >= TAM_P){
        printf("\nO numero maximo de palavras cadastradas foi atingido [max 100]!\n");
        break;
        }
    }
    printf("Pressione qualquer tecla para continuar...");
    getch();
}
/* Função: Gravar a palavra no arquivo de texto: palavras.txt */
void gravar_palavra(char *vetor_palavra){
    FILE *arquivo = NULL;
    arquivo = fopen("palavras.txt", "a+");
    if (!arquivo){
        printf("Impossivel abrir arquivo [2]\n");
        getch();
        exit(1);
    }
    fprintf(arquivo, "%s\n", vetor_palavra);
    if (ferror(arquivo)) {
        printf("Erro [4]");
        clearerr(arquivo);
        getch();
    }
    fflush(arquivo);
    fclose(arquivo);
    arquivo = NULL;
}
/* Função: Gravar a dica no arquivo de texto: dicas.txt */
void gravar_dica(char *vetor_dica){
    FILE *arquivo_dica = NULL;
    arquivo_dica = fopen("dicas.txt", "a+");
    if (!arquivo_dica){
        printf("Impossivel abrir arquivo [3]\n");
        getch();
        exit(1);
    }
    fprintf(arquivo_dica, "%s\n", vetor_dica);
    if (ferror(arquivo_dica)) {
        printf("Erro [3]");
        clearerr(arquivo_dica);
        getch();
    }
    fflush(arquivo_dica);
    fclose(arquivo_dica);
    arquivo_dica = NULL;
}
/* Função: Verificar se a palavra e dica contém números ou símbolos */
int valida_palavra(char *verifica){
    unsigned short int contador, verdadeiro = 0, falso = 0;
    for(contador = 0 ; contador < strlen(verifica); contador++){
        if((verifica[contador] >= 'a' && verifica[contador] <= 'z') || (verifica[contador] >= 'A' && verifica[contador] <= 'Z')){
            falso++;
        } else {
            verdadeiro++;
        }
    }
    if (verdadeiro > 0){
        return 1;
    } else {
        return 0;
    }
}
/* Função: Contar quantas palavras tem no arquivo palavras.txt*/
int contar_palavras() {
    char c;
    unsigned short int count = 0, flag = 0;
    FILE *verificar_arquivo = NULL;
    verificar_arquivo = fopen("palavras.txt", "r");
    if (!verificar_arquivo){
        printf("Impossivel abrir arquivo [4]\n");
        getch();
        exit(1);
    }
    while(!feof(verificar_arquivo)) {
        c = getc(verificar_arquivo);
        if ( c == ' ' || c == '\n' ) {
            if (flag == 0) {
            count++;
            flag = 1;
            }
        } else {
            if ( flag == 1 )
            flag = 0;
        }

        if (ferror(verificar_arquivo)) {
            printf("Erro [2]");
            clearerr(verificar_arquivo);
            getch();
            break;
        }
    }
    fclose(verificar_arquivo);
    verificar_arquivo = NULL;
    return count;
}
/* Funcão: Adicionar nome */
void adicionar_nome() {
    unsigned short int tamanho_nome;
    unsigned short int verifica_nome;
    do {
        printf("\nDigite seu nome [Max 20 Letras]: ");
        /* Limpar buffer do teclado */
        setbuf(stdin,NULL);
        scanf("%s", rank.nome);
        tamanho_nome = strlen(rank.nome);
        verifica_nome = valida_palavra(rank.nome);
        if (tamanho_nome > 20){
        printf("\nDigite no maximo 20 caracteres!\n\n");
        printf("Pressione qualquer tecla para continuar ...\n\n");
        getch();
        system("cls || clear");
        }
        if (verifica_nome == 1){
        printf("\nDigite apenas letras!\n\n");
        printf("Pressione qualquer tecla para continuar ...\n\n");
        getch();
        system("cls || clear");
        }
    } while (tamanho_nome > 20 || tamanho_nome == 0 || verifica_nome == 1);
}
/* Função: Abrir arquivo binário */
void abre_arquivo_bin(){
	arqrank=fopen("ranking.txt","a+b");
    if (!arqrank){
        printf("Impossivel abrir arquivo [5]\n");
        getch();
        exit(1);
    }
}
/* Função: Gravar ranking */
void gravar_ranking() {
    fseek(arqrank, 0, SEEK_END);
	fwrite(&rank, sizeof(ranking), 1, arqrank);
    if (ferror(arqrank)) {
        printf("Erro [1]");
        clearerr(arqrank);
        getch();
    }
}
/* Função: Mostrar Ranking */
void mostrar_ranking(){
    printf("\n ____________________________");
	printf("\n|NOME           |PONTUACAO  |");
	printf("\n|_______________|___________|");
    rewind(arqrank);
    fread(&rank ,sizeof(ranking), 1, arqrank);
    while (!feof(arqrank)) {
        dados();
        fread(&rank ,sizeof(ranking), 1, arqrank);
        if (ferror(arqrank)) {
            printf("Erro [0]");
            clearerr(arqrank);
            getch();
            break;
        }
    }
    printf("\n|_______________|___________|");
    printf("\n\nPressione qualquer tecla para continuar...");
    getch();
}
/* Função: Imprimir nome do jogador e pontuação */
void dados(){
    printf("\n|%-15s|%-11d|", rank.nome,rank.pontos);
}
