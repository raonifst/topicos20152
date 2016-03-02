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

void mostrar_Aluno(Aluno a)
{
    printf("Nome: %s\nRGA: %lld\nCR: %f", a.nome, a.RGA, a.CR);
}

int main()
{
    int n;
    Aluno aluno;
    FILE *fd = fopen("alunos.bin", "rb");

    if(fd == NULL) exception(ERROR_OPEN_FILE);

    while(printf("Informe um número (entre 1 e 3): "),scanf("%d", &n) && (n < 0 || n > 3));

    fseek(fd, n*sizeof(Aluno), SEEK_SET);
    fread(&aluno, sizeof(Aluno), 1, fd);

    mostrar_Aluno(aluno);

    fclose(fd);

    return 0;
}
