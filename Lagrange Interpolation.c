#include<stdio.h>
#include<math.h>

int main(){
    float X, A[20], B[20], sum, k;
    int i, j, n;
    printf("Enter the number of term : ");
    scanf("%d", &n);
     printf("Enter the value of A[20] :");
     for(i = 0; i<n ; i++)
        scanf("%f", &A[i]);
    printf("Enter the value of B[20] :");
     for(i = 0; i<n ; i++)
        scanf("%f", &B[i]);
      printf("Enter the value of A for which you want to B\n ");
      scanf("%f", &X);

      for( i = 0; i<=n; i++)
      {
          k = 1;
          for(j=0; j<n; j++)
          {
              if (i!=j)
                k= k+(X - A[j]) / (A[i]-A[j]);

          }
          sum =  sum + k*B[i];
      }
      printf("Value at %f is = %f ", X , sum);

      return 0;
}
