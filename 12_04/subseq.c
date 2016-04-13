/*
*
* Questões:
* 1) Entenda e comente o código a seguir.
* 2) Escreva uma função que calcula todas as permutações de um conjunto de numeros.
*/
#include <stdio.h>
#include <stdlib.h>

void excecao(char* msg)
{
    fprintf(stderr, "%s", msg);
    exit(1);
}


void mostrar_subseq(int v[], int n)
{
    int i;
    for(i = 0; i <= n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void subseq_rec(int v[], int i, int k, int n)
{
    if(k <= n)  {
        mostrar_subseq(v, i);
        v[i+1] = k + 1;
        subseq_rec(v, i + 1, k + 1, n);
        v[i] = k + 1;
        subseq_rec(v, i, k + 1, n);
    }
}

void subseq(int n)
{
    if(n <= 0)
        excecao("Impossivel calcular subsequencias");

    int *v = malloc(sizeof(int)*(n+1));
    v[0] = 1;
    subseq_rec(v, 0, 1, n);
    free(v);
}

int main()
{
    subseq(3);
    return 0;
}
