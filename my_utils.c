#include "my_utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//function definition
void rand_array(int n, int x[], int min, int max)
{
    for(int i = 0;i<n;i++)
    {
        x[i]=min+rand()% (max-min+1);
    }
}

void rand_array_float(int n, float x[], float min, float max)
{
    for(int i = 0;i<n;i++)
    {
        float p = (float) rand() / RAND_MAX;
        x[i]=min + (max - min) * p;
    }
}

void print_array(int n, int x[], char label[])
{
    printf("\n %s", label);

    for(int i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }
}

void print_array_float(int n, float x[], char label[])
{
    printf("\n\n%s", label);

    for(int i = 0; i < n; i++)
    {
        printf(" %.2f", x[i]);
    }
    printf("\n");
}

int findDiscriminant(int a, int b, int c)
{
    return (b * b) - (4 * a * c);
}

int randomRange()
{
    int num = -6 + rand() % 13;  // Generate an initial random number between -6 and 6

    while (num == 0) {          // Keep generating until num is non-zero
        num = -6 + rand() % 13;
    }

    return num;
}
void repeatedRootQuadratic()
{
    int a, b, c;
    int root = randomRange();

    srand(time(NULL));
    a = 1;
    b = 2 * root;
    c = root * root;


    printf("repeated roots: %dx^2 + %dx + %d = 0\n", a, b, c);
}

void realRootQuadratic()
{
    int a, b;
    a = randomRange();
    b = randomRange();
    while(b == a)
    {
        b = randomRange();
    }

    int real_a = 1;
    int real_b = a + b;
    int real_c= a * b;

    printf("real roots: %dx^2 + %dx + %d = 0\n", real_a, real_b, real_c);
}

