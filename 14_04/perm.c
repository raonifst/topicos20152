#include <stdio.h>
#include <stdlib.h>


void mostrar(int v[], int n)
{
    int i;
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}


void trocar(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void perm_rec(int a[], int i, int n)
{
    int j;
    if (n == 1)
        mostrar(a, i);
    else {
        for (j = n-1; j >= 0; j--) {
            trocar(&a[j], &a[n-1]);
            perm_rec(a, i, n-1);
            trocar(&a[j], &a[n-1]);
        }
    }
}

void perm(int n)
{
    int *v = malloc(sizeof(int)*n);
    int i;
    for(i = 0; i < n; i++)
        v[i] = i+1;

    //mostrar(v, n);

    perm_rec(v, n, n);

    free(v);
}

int main()
{
    perm(3);

    return 0;
}
