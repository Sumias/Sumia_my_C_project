/*#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_utils.h"

void write_header(FILE *fp)
{
    fprintf(fp, "\\documentclass{exam}");
    fprintf(fp, "\n\\usepackage[utf8]{inputenc}");

}

int main()
{
    srand(time(NULL));


    FILE *fp, *fp1;
    fp = fopen("student_latex.tex", "w");
    fp1 = fopen("teacher_latex.tex", "w");

    write_header(fp);
    write_header(fp1);





    printf("\n");
    return 0;
}*/
//#include <stdio.h>
// I HACKED HUSNIYAH!
// HACKED AGAIN heheheheh
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>





//printing string during class
void get_eq_str(int a, int b, int c, char str[])
{
    char s[100];
    strcpy(str, "\\(");
    if (a == 1)
        strcat(str, "x^2 ");
    else if (a == 0)
        strcat(str, " ");
    else
    {
        sprintf(s, "%dx^2 ", a);
        strcat(str, s);
    }

    if (b == 1)
        strcat(str, "+ x");
    else if (b < 0)
    {
        sprintf(s," - %dx", abs(b));
        strcat(str, s);
    }
    else if (b > 1)
    {
        sprintf(s, "% + dx", b);
        strcat(str, s);
    }
    else if(b == 0)
    {
        strcat(str, "");
    }

    if (c > 0)
    {
        sprintf(s, " + %d", c);
        strcat(str, s);
    }
    else if (c < 0)
    {
        sprintf(s, " - %d", abs(c));
        strcat(str, s);
    }
    else if ( c == 0)
    {
        sprintf(s, "", c);
        strcat(str, s);
    }

    strcat(str, " = 0\\)");
}

int getDiscriminant(int a, int b, int c)
{
    int d = b*b - 4*a*c;
    return d;
}
void printDiscriminant(FILE *fp, int a, int b, int c, int d)
{
    int eq1 = b*b;
    int eq2 = 4*a*c;

    fprintf(fp, "\n\n\\subsection*{Discriminant}: ");
    printf("\n\n\\subsection*{Discriminant}: ");

    fprintf(fp, "\n\\[d = %d^2 - 4\\cdot %d \\cdot%d = %d - %d = %d\\]", b, a, c, eq1, eq2, d);
    printf("\nd = %d^2 - 4*%d*\\(%d) = %d", b, a, c, d);

}

void print_Roots(FILE *fp, int a, int b, int discriminant, int x1)
{
    int equation1, equation2;
    equation1 = 0.5 * b/a;
    equation2 = 0.5 * sqrt(discriminant)/a;


    double realPart = -b / (2.0 * a);
    double imaginaryPart = sqrt(abs(discriminant)) / (2.0 * a);


    if(discriminant == 0)
    {
        fprintf(fp,"\n \\subsection*{\\(d = 0\\): Repeated Roots}");
        printf("\n \\subsection*{\\(d = 0\\): Repeated Roots}");

        fprintf(fp,"\n \\[x_1 = -\\frac{%d}{%d} + \\frac{\\sqrt{%d}}{%d} = %d + %d = %d\\]", b, b, discriminant, a, equation1, equation2, x1 );
        printf("\n \\[x_1 = -\\frac{%d}{%d} + \\frac{\\sqrt{%d}}{%d} = %d + %d = %d\\]", b, b, discriminant, a, equation1, equation2, x1 );

    }
    else if(discriminant > 0)
    {
        fprintf(fp,"\n \\subsection*{\\(d > 0\\): Real Roots}");
        printf("\n \\subsection*{\\(d > 0\\): Real Roots}");

        fprintf(fp,"\n \\[x_1 = -\\frac{%d}{%d} + \\frac{\\sqrt{%d}}{%d} = %d + %d = %d\\]", b, b, discriminant, a, equation1, equation2, x1 );
        printf("\n \\[x_1 = -\\frac{%d}{%d} + \\frac{\\sqrt{%d}}{%d} = %d + %d = %d\\]", b, b, discriminant, a, equation1, equation2, x1 );
    }

    else if(discriminant < 0)
    {
        fprintf(fp,"\n \\subsection*{\\(d < 0\\): Complex Roots}");
        printf("\n \\subsection*{\\(d < 0\\): Complex Roots}");

        fprintf(fp, "\n \\[x1 = -\\frac{%d}{%d} + \\frac{\\sqrt{%d}}{%d} = %.2f + %.2fi\\]",b, b, discriminant, a, realPart, imaginaryPart);
        fprintf(fp, "\n \\[x2 = -\\frac{%d}{%d} + \\frac{\\sqrt{%d}}{%d} = %.2f - %.2fi\\]",b, b, discriminant, a, realPart, imaginaryPart);

        printf("The roots are complex:\n");
        printf("x1 = %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("x2 = %.2f - %.2fi\n", realPart, imaginaryPart);
    };
}

void print_secondRoot(FILE *fp, int a, int b, int discriminant, int x2)
{
    int equation1, equation2;
    equation1 = 0.5*b/a;
    equation2 = 0.5*sqrt(discriminant)/a;


    fprintf(fp,"\n \\[x_2 = -\\frac{%d}{%d} - \\frac{\\sqrt{%d}}{%d} = %d - %d = %d\\]", b, b, discriminant, a, equation1, equation2, x2 );
    printf("\n \\[x_2 = -\\frac{%d}{%d} - \\frac{\\sqrt{%d}}{%d} = %d - %d = %d\\]", b, b, discriminant, a, equation1, equation2, x2 );
    fprintf(fp,"\n \\vspace{\\stretch{1}}");

}

void write_header(FILE *fp)
{
    fprintf(fp, "\\documentclass{exam}");
    fprintf(fp,"\n\\usepackage[utf8]{inputenc}");

    fprintf(fp,"\n\\begin{document}");

    fprintf(fp,"\n\\section*{ECE 370: Advanced Computing in ECE}");
    fprintf(fp,"\n\\subsection*{Quiz \\#1: The Quadratic Equation}");
    fprintf(fp,"\n\\today \\\\");

    fprintf(fp,"\n\\vspace{10mm}");
    fprintf(fp,"\n\\makebox[\\textwidth]{Name:\\enspace\\hrulefill}");
    fprintf(fp,"\n\\vspace{3mm}");
}



int main()
{
    srand(time(NULL));

    FILE *fp;
    FILE *fp1;

    fp = fopen("student_latex.tex", "w");
    fp1 = fopen("teacher_latex.tex", "w");

    write_header(fp);
    write_header(fp1);


    //Repeated

    int repeatedMin = -6;
    int repeatedMax = 6;
    int repeated_a;
    int repeated_b;
    int repeated_c;
    char repeated_eq[1000];
    int repeated_d, repeated_x1, repeated_x2;
    int root;

    root = repeatedMin + rand()%(repeatedMax - repeatedMin + 1);
    while (root == 0)
    {
        root = repeatedMin + rand()%(repeatedMax-repeatedMin+1); // make sure it is not 0
    }
    repeated_a = 1;
    repeated_b = 2*root;
    repeated_c = root*root;


    get_eq_str(repeated_a, repeated_b, repeated_c, repeated_eq);

    repeated_d = getDiscriminant(repeated_a, repeated_b, repeated_c);
    repeated_x1 = - repeated_b/(2*repeated_a) + sqrt(repeated_d)/(2*repeated_a);
    repeated_x2 = - repeated_b/(2*repeated_a) - sqrt(repeated_d)/(2*repeated_a);

    fprintf(fp, "\n\n\\begin{questions}");
    fprintf(fp1, "\n\n\\begin{questions}");
    printf("\n\n\\begin{questions}");

    fprintf(fp1,"\n \\question Solve for the roots: %s", repeated_eq);
    fprintf(fp,"\n \\question Solve for the roots: %s", repeated_eq);
    printf("\n \\question Solve for the roots: %s", repeated_eq);
    fprintf(fp,"\n \\vspace{\\stretch{1}}");

    printDiscriminant(fp1, repeated_a, repeated_b, repeated_c, repeated_d);
    print_Roots(fp1, repeated_a, repeated_b, repeated_d, repeated_x1);
    print_secondRoot(fp1, repeated_a, repeated_b, repeated_d, repeated_x2);


    //Real
    int realMin = -6;
    int realMax = 6;
    char real_eq[1000];
    int real_d;
    int real_x1;
    int real_x2;
    int a;
    int b;

    a = realMin + rand()% (realMax - realMin + 1);
    while(a == 0)
    {
        a = realMin + rand()% (realMax - realMin + 1);
    }
    b = realMin + rand()% (realMax - realMin + 1);
    while((b == 0) || (b == a))                          //make sure it is not 0 and b is not equal to a
    {
        b = realMin + rand()%(realMax - realMin + 1);
    }
    int real_a = 1;
    int real_b = a+b;
    int real_c= a*b;

    get_eq_str(real_a, real_b, real_c, real_eq);

    real_d = getDiscriminant(real_a, real_b, real_c);
    real_x1 = - real_b/(2*real_a) + sqrt(real_d)/(2*real_a);
    real_x2 = - real_b/(2*real_a) - sqrt(real_d)/(2*real_a);

    fprintf(fp1,"\n Solve for the roots: %s", real_eq);
    fprintf(fp,"\n \\question Solve for the roots: %s", real_eq);
    printf("\n \\question Solve for the roots: %s", real_eq);
    fprintf(fp,"\n \\vspace{\\stretch{1}}");

    printDiscriminant(fp1, real_a, real_b, real_c,real_d);
    print_Roots(fp1, real_a, real_b, real_d, real_x1);
    print_secondRoot(fp1, real_a, real_b, real_d, real_x2);



    //Complex
    int min = -6;
    int max = 6;

    char complex_eq[10000];
    int complex_d;
    int complex_x1;
    int complex_x2;

    int sigma;
    sigma = min + rand()%(max-min+1);       //in class
    min = 1;
    int w= min+rand()%(max-min+1);

    if(rand()%2 ==0)
        w = -1 * w;

    int complex_a = 1;
    int complex_b = -2 * sigma;
    int complex_c = sigma * sigma + w * w;


    get_eq_str(complex_a, complex_b, complex_c, complex_eq);

    complex_d = getDiscriminant(complex_a, complex_b, complex_c);

    fprintf(fp1,"\n  Solve for the roots: %s", complex_eq);
    fprintf(fp,"\n  Solve for the roots: %s", complex_eq);
    printf("\n  Solve for the roots: %s", complex_eq);
    fprintf(fp,"\n \\vspace{\\stretch{1}}");


    printDiscriminant(fp1, complex_a, complex_b, complex_c, complex_d);
    print_Roots(fp1, complex_a, complex_b, complex_d, complex_x1);

    printf("\n\n\\end{questions}");
    fprintf(fp, "\n\n\\end{questions}");
    fprintf(fp1, "\n\n\\end{questions}");



    fprintf(fp,"\n\n\\end{document}");
    fprintf(fp1,"\n\n\\end{document}");
    printf("\n\n\\end{document}");
    return 0;
}
