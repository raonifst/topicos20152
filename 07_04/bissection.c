/*
* Este código ilustra como o algoritmo de busca binária estudado neste semestre pode ser utilizado para
* calcular uma aproximação da raiz quadrada de um número real positivo.
*
* Leia atentamente (estude) o texto em: http://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html
*
* Questões:
* 1) Entenda e comente o código a seguir.
* 2) Escreva uma função que calcula uma aproximação para raiz cúbica de um número
* 3) Prove que a funcao
                f(x) = x*x - n
    tem uma raiz no intervalo [1, n-1].
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void excecao(char* msg)
{
    fprintf(stderr, "%s", msg);
    exit(1);
}

float f(float x, float k)
{
    return x*x - k;
}

int sig(float x)
{
    return x > 0? 1: -1;
}

float bisect(float ini, float fim, float eps, float k)
{
    float m = (fim+ini)/2;

    if(fabs(f(m, k)) < eps)  //caso base
        return m;

    if (sig(f(fim, k)) == sig(f(m, k)))
        fim=m;
    else
        ini=m;

    return bisect(ini, fim, eps, k);
}

float raiz(float n)
{
    if(n < 0)
        excecao("Nao existe raiz real para este numero.");

    /*Prove que a funcao
                f(x) = x*x - n
    tem uma raiz no intervalo [1, n-1] */
    return bisect(1.0, n-1, 0.001, n);
}


int main()
{
    float n = 0.5;
    printf("A raiz de %.2lf eh %.2lf", n, raiz(n));
    return 0;
}
