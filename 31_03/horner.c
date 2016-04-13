/*
* A ideia (bem interessante, por sinal) é 'simplificar' um polinômio em várias partes,
* resolver a mais simples delas e, no final,  combinar as soluções.
*
* Considere o polinômio, p(x) =  2x³ - 3x² + 2x + 1 como exemplo.
* Como você deve saber, avaliá-lo para x igual a 2 é o mesmo que  calcular 2*(2³) - 3*(2²) + 2*(2) + 1 = 9.
*
* Fazendo isso da maneira tradicional (aula de 22 de março), no entando, realizamos (3*n + n²)/2 multiplicações (n é grau do polinômio - ou seja, no nosso exemplo realizariamos 9 comparações). isso, é claro considerando um algoritmo de potenciação simples e que eu não errei os cálculos :P
*
* Mas, como Horner bem observou,
*
*   2x³ - 3x² + 2x + 1  = 1 + x * ( 2 + x * ( -3 + x*( 2 ) ) ).
*
*
* De agora em diante, vou chamar esta simplificação de 'forma de Honer'.
*
* Sabendo disso e com um pouco atenção é fácil perceber que
*
*   a forma de Horner de 2x³ - 3x² + 2x + 1  é igual 1 + x * ( a forma de Horner de 2x²-3x+2),  que,
*    por sua vez, é igual a  2 + x *( a forma de Horner de 2x - 3), que, finalmente,
*    é o mesmo que -3 + x * ( a forma de Horner de 2).  A forma de Horner de 2 é 2 mesmo.
*
*
* O que fizemos acima foi definir recursivamente a forma de Horner, certo?
*
* Seguindo este princípio podemos definir a seguinte a recorrência para esta forma
*
* ii) a forma de um polinômio de grau 0 é p_0 (coeficiente de grau zero).
* i) a forma de um polinômio de grau n é  p_0 + x * ( forma de p reduzindo um grau de todos os seus coefientes)
*
* Para implementar esta recorrência podemos utilizar uma variável para controlar
* qual deve ser o coeficiente de grau 0 em cada uma das chamadas recursivas ou
* definir o polinômio ao contrário, ou seja, coeficiente  p_n  na posição p[0], p_n-1  na posição p[1] etc.
*
*/
#include <stdio.h>



double horner(double p[], double x, int n)
{
    if(n == 0)  return p[n];
    else return p[n] + x * horner(p, x, n-1);
}


int main()
{
    int p[] = {2.0, -3.0, 2.0, 1.0 }; /*polinômio 2x³ - 3x² + 2x + 1*/

    printf("%d\n", horner(p, 2.0, 3)); /*avaliação passando o polinômio, x valendo 2 e o grau do polinômio que é 3 */

    return 0;
}

