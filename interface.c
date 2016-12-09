#include "interface.h"

#define TAM_V 100

/* Estrutura para armazenamento no arquivo binárop */
typedef struct{
    char nome[25];
    unsigned short int pontos;
}ranking;
ranking rank;

/* Função: Tela inicial do jogo*/
void tela() {
    printf("___________   \n|         |   \n|        _|_\n|         O   JOGO DA FORCA\n|        /|\\    \n|        / \\ \n| \n| \n| \n");
	printf("\n[1] Jogar\n");
	printf("[2] Ver Rankig\n");
	printf("[3] Cadastrar Palavras\n");
    printf("[4] Creditos\n");
	printf("[5] Sair\n\n");
}
/* Função: Jogo*/
int jogo() {
    /* Variáveis do jogo*/
    unsigned short int c, contador, n, nchar, e1, e2, e3, e4, e5, certo, animacao, animacao2, conta_tentativa;
    char tentativa, confirmar, continuar;
    do{
        system("cls || clear");
        confirmar = 'n';
        while(confirmar != 'S') {
            certo = 0;
            nchar=0;
            n = 0;
            c=0;
            contador = 0;
            e1 = ' ';
            e2 = ' ';
            e3 = ' ';
            e4 = ' ';
            e5 = ' ';
            unsigned short int i = 0, i2 = 0, numPalavras = 0, numPalavras2 = 0;
            char *palavras[TAM_V];
            char line[TAM_V];
            memset(line, 0, sizeof(line));
            unsigned short int palavra;
            char *palavras2[TAM_V];
            char line2[TAM_V];
            memset(line2, 0, sizeof(line2));
            /* Abrindo arquivo de texto */
            FILE *arquivo2 = NULL;
            arquivo2 = fopen("palavras.txt", "a+");
            if (!arquivo2){
                printf("Impossivel abrir arquivo [0]\n");
                getch();
                exit(1);
            }
            FILE *arquivo3 = NULL;
            arquivo3 = fopen("dicas.txt", "a+");
            if (!arquivo3){
                printf("Impossivel abrir arquivo [1]\n");
                getch();
                exit(1);
            }
            while(fgets(line, sizeof(line), arquivo2) != NULL) {
                /* Adiciona cada palavra no vetor */
                palavras[i] = strdup(line);
                i++;
                numPalavras++;
                if (ferror(arquivo2)) {
                    printf("Erro [6]");
                    clearerr(arquivo2);
                    getch();
                    break;
                }
            }
            while(fgets(line2, sizeof(line2), arquivo3) != NULL) {
                /* Adiciona cada palavra no vetor */
                palavras2[i2] = strdup(line2);
                i2++;
                numPalavras2++;
                if (ferror(arquivo3)) {
                    printf("Erro [5]");
                    clearerr(arquivo3);
                    getch();
                    break;
                }
            }
            /* Gerando índice aleatório para a palavra */
            srand(time(NULL));
            palavra = rand() % numPalavras;
            unsigned short int numletras;
            unsigned short int numletras2;
            numletras = strlen(palavras[palavra]);
            numletras2 = strlen(palavras2[palavra]);
            char *palavra_selecionada = NULL;
            char *dica_selecionada = NULL;
            char resposta[numletras];
            /* Alocação Dinâmica da palavra de acordo com a quantidade de caracteres */
            palavra_selecionada = (char*) malloc(numletras*sizeof(char)+1);
            if (!palavra_selecionada){
                printf("Erro ao alocar [0]");
                getch();
                return 1;
            }
            /* Alocação Dinâmica da dica de acordo com a quantidade de caracteres */
            dica_selecionada = (char*) malloc(numletras2*sizeof(char)+1);
            if (!dica_selecionada){
                printf("Erro ao alocar [1]");
                getch();
                return 1;
            }
            /* Copia a palavra de um vetor para outro*/
            strcpy(palavra_selecionada, palavras[palavra]);
            strcpy(dica_selecionada, palavras2[palavra]);
                        for(c = 0; c < numletras+1 ; c++) {
                                if (palavra_selecionada[c] == '\n'){
                                    resposta[c] = ' ';
                                } else {
                                    resposta[c] = '_';
                                }
                        }
                while(contador < 6) {
                    n=0;
                    certo=0;
                    switch(contador) {
                        case 0: printf("___________   \n|         |   \n|        _|_\n|          \n|         \n|         \n| \n| \n| \n\n");
                        break;
                        case 1: printf("___________   \n|         |   \n|        _|_\n|         O    \n|         \n|       \n| \n| \n| \n\n");
                        break;
                        case 2: printf("___________   \n|         |   \n|        _|_\n|         O    \n|         |    \n|         \n| \n| \n| \n\n");
                        break;
                        case 3: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|    \n|         \n| \n| \n| \n\n");
                        break;
                        case 4: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|         \n| \n| \n| \n\n");
                        break;
                        case 5: printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        /  \n| \n| \n| \n\n");
                        break;
                    }
                    for(c=0; c < 20; c++) {
                        if(palavra_selecionada[c] == '\0') {
                            nchar = c;
                            break;
                        }
                        else {
                            if(palavra_selecionada[c] == ' ') {
                                resposta[c]= ' ';
                                printf("%c", resposta[c]);
                            }
                            else {
                                if(palavra_selecionada[c] == tentativa) {
                                    resposta[c] = palavra_selecionada[c];
                                }
                            }
                        }
                        printf("%c ", resposta[c]);
                    }
                    printf("\n\n%c %c %c %c %c\n", e1, e2, e3, e4, e5);
                    switch(contador) {
                        case 0: puts("\n\nVoce pode errar 5 vezes.");
                        conta_tentativa = 0;
                        break;
                        case 1: puts("\n\nVoce pode errar 4 vezes.");
                        conta_tentativa = 1;
                        break;
                        case 2: puts("\n\nVoce pode errar 3 vezes.");
                        conta_tentativa = 2;
                        break;
                        case 3: puts("\n\nVoce pode errar 2 vezes.");
                        conta_tentativa = 3;
                        break;
                        case 4: puts("\n\nVoce pode errar apenas mais uma vez.");
                        conta_tentativa = 4;
                        break;
                        case 5: puts("\n\nSe errar agora morre!");
                        conta_tentativa = 5;
                    }
                    for(c = 0; c <= nchar; c++) {
                        if(tentativa != ' ') {
                            if(resposta[c]!= '_') {
                                certo++;
                                if(certo == nchar) {
                                    contador = 7;
                                    break;
                                }
                            }
                        }
                    }
                    if(certo!=nchar) {
                        printf("\nDica: %s\n", dica_selecionada);
                        unsigned short int verifica_tentativa;
                        char valida_entrada[20];
                        unsigned short int contador_entrada;
                        do {
                            printf("Digite uma letra: ");
                            setbuf(stdin,NULL);
                            scanf("%s", valida_entrada);
                            contador_entrada = strlen(valida_entrada);
                            tentativa = valida_entrada[0];
                            tentativa = tolower(tentativa);
                            verifica_tentativa = isalpha(tentativa);
                            if (verifica_tentativa == 0) {
                                printf("\n\nDigite apenas letras!\n\n");
                                printf("Pressione qualquer tecla para continuar ...\n\n");
                                getch();
                            }
                            if (contador_entrada > 1) {
                                printf("\n\nDigite apenas uma letra!\n\n");
                                printf("Pressione qualquer tecla para continuar ...\n\n");
                                getch();
                            }
                        } while (verifica_tentativa == 0 || contador_entrada > 1);
                    }
                    for(c = 0; c < nchar; c++) {
                        if(tentativa != palavra_selecionada[c]) {
                            n++;
                            if(n==nchar) {
                                contador++;
                                if(contador==1) {
                                    e1 = tentativa;
                                }
                                if(contador==2) {
                                    e2 = tentativa;
                                }
                                if(contador==3) {
                                    e3 = tentativa;
                                }
                                if(contador==4) {
                                    e4 = tentativa;
                                }
                                if(contador==5) {
                                    e5 = tentativa;
                                }
                            }
                        }
                    }
                    system("cls || clear");
                }
            if(contador==6) {
                printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        / \\ \n| \n| \n| \n\n");
                for(c = 0; c < nchar; c++) {
                    if(resposta[c] == palavra_selecionada[c]) {
                        printf("%c ", resposta[c]);
                    }
                    else {
                        printf("%c ", palavra_selecionada[c]);
                    }
                }
                printf("\n\n%c %c %c %c %c %c\n", e1, e2, e3, e4, e5, tentativa);
                printf("\n\n...Voce foi enforcado...\n");
                printf("\n\n");
            }
            if(contador==7) {
                for(animacao=0;animacao<7;animacao++) {
                    for(animacao2=0;animacao2<5;animacao2++) {
                        system("cls || clear");
                        printf("Parabens!! Voce Venceu!!\n");
                        printf("___________ \n|         | \n|        _|_\n|\n|\n|         O \n|        /|\\ \n|        / \\\n|\n\n");
                    }
                    for(animacao2=0;animacao2<5;animacao2++) {
                        system("cls || clear");
                        printf("Parabens!! Voce Venceu!!\n");
                        printf("___________ \n|         | \n|        _|_\n|\n|\n|\n|        _O_\n|         | \n|        / \\\n\n");
                    }
                    for(animacao2=0;animacao2<5;animacao2++) {
                        system("cls || clear");
                        printf("Parabens!! Voce Venceu!!\n");
                        printf("___________ \n|         | \n|        _|_\n|\n|\n|        \\O/\n|         | \n|        / \\\n|\n\n");
                    }
                }
                system("cls || clear");
                printf("Parabens!! Voce Venceu!!\n");
                printf("___________ \n|         | \n|        _|_\n|\n|\n|\n|        \\O/\n|         | \n|        / \\\n\n");
                tentativa='_';
            }
            confirmar = 'S';
            /* Pontuação do ranking baseada nas tentativas */
            if(conta_tentativa == 0) {
                rank.pontos = 100;
            }
            if(conta_tentativa == 1) {
                rank.pontos = 50;
            }
            if(conta_tentativa == 2) {
                rank.pontos = 30;
            }
            if(conta_tentativa == 3) {
                rank.pontos = 20;
            }
            if(conta_tentativa == 4) {
                rank.pontos = 10;
            }
            if(conta_tentativa == 5) {
                rank.pontos = 0;
            }
            printf("Pontuacao: %d\n\n", rank.pontos);
            gravar_ranking();
            char valida_entrada2[20];
            unsigned short int contador_entrada2;
            do {
                do {
                    printf("Deseja jogar novamente (S/N)? ");
                    setbuf(stdin,NULL);
                    scanf("%s", valida_entrada2);
                    contador_entrada2 = strlen(valida_entrada2);
                    continuar = valida_entrada2[0];
                    continuar = toupper(continuar);
                    if (contador_entrada2 > 1) {
                        printf("\nDigite apenas um caractere.\n");
                    }
                    if (continuar != 'N' || continuar != 'S') {
                        printf("\nDigite [S] para jogar novamente ou [N] para sair.\n\n");
                    }
                } while (contador_entrada2 > 1);
                if (continuar == 'N') {
                    break;
                }
            } while (continuar != 'S');
    /* Liberando a memória e atribuindo valores nulos aos vetores */
    free(palavra_selecionada);
    palavra_selecionada = NULL;
    free(dica_selecionada);
    dica_selecionada = NULL;
    /* Fechar arquivo de texto */
    fclose(arquivo2);
    arquivo2 = NULL;
    fclose(arquivo3);
    arquivo3 = NULL;
        }
    }while(continuar=='S');
    system("cls || clear");
    return 0;
    fclose(arqrank);
    arqrank = NULL;
}
/* Função: Créditos */
void creditos() {
    printf("Creditos\n\n");
    printf("Alvaro Philipe Andrade dos Santos (Programacao)\n");
    printf("Arthur Jose da Silva Dias (Design)\n");
    printf("Khayo Luiz de Souza (Programacao)\n");
    printf("Lucas Pereira Costa (Design)\n");
    printf("Marcelo Henrique Dantas Rodrigues (Programacao e Testes)\n");
    printf("Sidnei Farias de Lima Filho (Design e Testes)\n");
    printf("\n\nPressione qualquer tecla para continuar...");
    getch();
}
/* Função: Sair do Jogo */
int sair() {
    exit(0);
}
