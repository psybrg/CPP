#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *genamounts ( int n )
{
   int i;
   double *C;

   C = (double *)malloc(n * sizeof(double));
   for (i=0; i<n; ++i) {
      C[i] = (double)(1000 + rand() % 9000) / 100.;
      if (i % 12 == 0) printf("\n    ");
      printf("%6.2lf", C[i]);
   }
   printf("\n");
   return C;
}

double esexchange ( double *A, double *B, int n, int i, int j, double exchrate )
{
   double sol1, sol2;

   if ((i >= n) && (j >= n)) return 0;
   sol1 = sol2 = 0;
   if (i < n) sol1 = exchrate * A[i] + esexchange(A,B,n,i+1,j,exchrate+11);
   if (j < n) sol2 = exchrate * B[j] + esexchange(A,B,n,i,j+1,exchrate+11);
   return (sol1 >= sol2) ? sol1 : sol2;
}

double grexchange ( double *A, double *B, int n )
{
   double exchrate, sol, publisher;
   int i, j;

   i = j = 0; sol = 0; exchrate = 100;
   while ((i < n) || (j < n)) {
      if (i >= n) publisher = 2;
      else if (j >= n) publisher = 1;
      else if (A[i] <= B[j]) publisher = 1;
      else publisher = 2;
      if (publisher == 1) sol += exchrate * A[i++];
      else sol += exchrate * B[j++];
      exchrate += 11;
   }
   return sol;
}

/* All cheques deposited, no more exchange
   T[n][n] = 0

   All cheques from Company B deposited
   T[i][n] = T[i+1][n] + current_exchange_rate * A[i]	

   All cheques from Company A deposited
   T[n][j] = T[n][j+1] + current_exchange_rate * B[j]	

   Cheques from both companies pending to be deposited
   T[i][j] = max( T[i+1][j] + current_exchange_rate * A[i],
                  T[i][j+1] + current_exchange_rate * B[j]
                )
*/
double dpexchange ( double *A, double *B, int n )
{
   double **T, exchrate, sol1, sol2;
   int i, j;

   T = (double **)malloc((n+1) * sizeof(double *));
   for (i=0; i<=n; ++i) T[i] = (double *)malloc((n+1) * sizeof(double));
   T[n][n] = 0;
   exchrate = 100 + (2*n - 1) * 11;
   for (i=n-1; i>=0; --i) {
      T[i][n] = T[i+1][n] + A[i] * exchrate;
      exchrate -= 11;
   }
   exchrate = 100 + (2*n - 1) * 11;
   for (j=n-1; j>=0; --j) {
      T[n][j] = T[n][j+1] + B[j] * exchrate;
      exchrate -= 11;
   }
   for (i=n-1; i>=0; --i) {
      for (j=n-1; j>=0; --j) {
         exchrate = 100 + (i + j) * 11;
         sol1 = T[i+1][j] + exchrate * A[i];
         sol2 = T[i][j+1] + exchrate * B[j];
         T[i][j] = (sol1 >= sol2) ? sol1 : sol2;
      }
   }
   sol1 = T[0][0];
   for (i=0; i<=n; ++i) free(T[i]);
   free(T);
   return sol1;
}

int main ( int argc, char *argv[] )
{
   int n;
   double *A, *B;

   if (argc > 1) n = atoi(argv[1]); else scanf("%d", &n);
   printf("n = %d\n", n);
   srand((unsigned int)time(NULL));

   A = genamounts(n);
   B = genamounts(n);

   printf("\n+++ Exhaustive Search\n    Maximum exchange = %.2lf\n",
          esexchange(A,B,n,0,0,100));

   printf("\n+++ Greedy Strategy\n    Maximum exchange = %.2lf\n",
          grexchange(A,B,n));

   printf("\n+++ Dynamic Programming\n    Maximum exchange = %.2lf\n",
          dpexchange(A,B,n));

   exit(0);
}

