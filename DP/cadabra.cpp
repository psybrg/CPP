#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *gencosts ( int n )
{
   int i;
   double *C;

   C = (double *)malloc(n * sizeof(double));
   for (i=0; i<n; ++i) {
      C[i] = (double)(1 + rand() % 999) / 100.;
      if (i % 15 == 0) printf("\n    ");
      printf("%5.2lf", C[i]);
   }
   printf("\n");
   return C;
}

double esprofit ( double *C, int n, int i, int j, double depfactor )
{
   double sol1, sol2;

   if ((i >= n/2) && (j >= n/2)) return 0;
   sol1 = sol2 = 0;
   if (i < n/2) sol1 = depfactor * C[n/2-i-1] + esprofit(C,n,i+1,j,0.9*depfactor);
   if (j < n/2) sol2 = depfactor * C[n/2 + j] + esprofit(C,n,i,j+1,0.9*depfactor);
   return (sol1 >= sol2) ? sol1 : sol2;
}

double grprofit ( double *C, int n )
{
   double depfactor, profit, side;
   int i, j;

   i = j = 0; profit = 0; depfactor = 1.0;
   while ((i < n/2) || (j < n/2)) {
      if (i >= n/2) side = 2;
      else if (j >= n/2) side = 1;
      else if (C[n/2 - i - 1] >= C[n/2 + j]) side = 1;
      else side = 2;
      if (side == 1) { profit += depfactor * C[n/2 - i - 1]; ++i; }
      else { profit += depfactor * C[n/2 + j]; ++j; }
      depfactor *= 0.9;
   }
   return profit;
}

/* All items sold, no more profit
   T[n/2][n/2] = 0

   Right side exhausted
   T[i][n/2] = T[i+1][n/2] + current_depreciation_factor * C[n/2-i-1]

   Left side exhausted
   T[n/2][j] = T[n/2][j+1] + current_depreciation_factor * C[n/2+j]

   Both sides have items to be sold
   T[i][j] = max( T[i+1][j] + current_depreciation_factor * C[n/2-i-1],
                  T[i][j+1] + current_depreciation_factor * C[n/2+j]
                )
*/
double dpprofit ( double *C, int n )
{
   double **T, depfactor, sol1, sol2;
   int i, j, k;

   T = (double **)malloc((n/2 + 1) * sizeof(double *));
   for (i=0; i<=n/2; ++i) T[i] = (double *)malloc((n/2 + 1) * sizeof(double));
   T[n/2][n/2] = 0;
   depfactor = 1.0; for (i=0; i<n-1; ++i) depfactor *= 0.9;
   for (i=n/2-1; i>=0; --i) {
      T[i][n/2] = T[i+1][n/2] + C[n/2-i-1] * depfactor;
      depfactor /= 0.9;
   }
   depfactor = 1.0; for (i=0; i<n-1; ++i) depfactor *= 0.9;
   for (j=n/2-1; j>=0; --j) {
      T[n/2][j] = T[n/2][j+1] + C[n/2+j] * depfactor;
      depfactor /= 0.9;
   }
   for (i=n/2-1; i>=0; --i) {
      depfactor = 1.0; for (k=0; k<i+n/2-1; ++k) depfactor *= 0.9;
      for (j=n/2-1; j>=0; --j) {
         sol1 = T[i+1][j] + C[n/2-i-1] * depfactor;
         sol2 = T[i][j+1] + C[n/2 + j] * depfactor;
         T[i][j] = (sol1 >= sol2) ? sol1 : sol2;
         depfactor /= 0.9;
      }
   }
   sol1 = T[0][0];
   for (i=0; i<=n/2; ++i) free(T[i]);
   free(T);
   return sol1;
}

int main ( int argc, char *argv[] )
{
   int n;
   double *C;

   if (argc > 1) n = atoi(argv[1]); else scanf("%d", &n);
   printf("n = %d\n", n);
   srand((unsigned int)time(NULL));

   C = gencosts(n);

   printf("\n+++ Exhaustive Search\n     Maximum profit = %lf\n",
          esprofit(C,n,0,0,1.0));

   printf("\n+++ Greedy Strategy\n     Maximum profit = %lf\n",
          grprofit(C,n));

   printf("\n+++ Dynamic Programming\n     Maximum profit = %lf\n",
          dpprofit(C,n));

   exit(0);
}

