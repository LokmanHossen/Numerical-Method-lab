#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) pow(x,3)+pow(x,2)-1
#define g(x) 1/sqrt((pow(x,2))+1)

int main()
{

    int n=1,N=15;
    float x1,x2,e;
    printf("\nThis program demonstrates Fixed-Iteration method in C:\n");
    printf("\nGiven equation is f(x):x^3+x^2-1=0");
    printf("\nEquivalent equation is g(x):x=1/sqrt(x^2+1)");

    printf("\nEnter initial guess:");
    scanf("%f",&x1);

    printf("\nEnter maximum allowed error:");
    scanf("%f",&e);

    printf("\nThe given sequence of approximations are\n");
    printf("\nn\tx_n\n");
    do
    {
        x2=g(x1);
        printf("\n%d\t%f",n,x1);
        n=n+1;
        if(n>N)
        {
            printf("The given sequence is not convergent");
            exit(0);
        }
        x1=x2;
    }
        while(fabs(f(x2))>e);
        printf("\n%d\t%f\n",n,x2);
        printf("An approximate solution is %f\n",x2);
        return(0);

}

