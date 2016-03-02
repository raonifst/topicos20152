#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct _aluno {
    char nome[MAX];
    long long RGA;
    float CR;
} Aluno;

void exception(char* msg)
{
    fprintf(stderr, msg);
    exit(0);
}

#define ERROR_OPEN_FILE "Erro ao abrir arquivo"

int main()
{
    int i;
    Aluno alunos[3];
    FILE* fd = fopen("alunos.bin", "wb");

    if(fd == NULL) exception(ERROR_OPEN_FILE);

    /*preenche a estrutura*/
    sprintf(alunos[0].nome, "Camila Muniz");
    alunos[0].RGA = 202021901012;
    alunos[0].CR = 9.1;

    sprintf(alunos[1].nome, "Bruna Araujo");
    alunos[1].RGA = 202021901013;
    alunos[1].CR = 8;

    sprintf(alunos[2].nome, "Fernando Muniz");
    alunos[2].RGA = 202021901015;
    alunos[2].CR = 5;

    for(i = 0; i < 3; i++)
        fwrite(&alunos[i], sizeof(Aluno), 1, fd);

    fclose(fd);

    return 0;
}
