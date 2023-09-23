
#include <bits/stdc++.h>
using namespace std;

double **genexhfacs ( int n )
{
   double **EF;
   int i, j;

   //printf("\n+++ Exhausting factors:\n");
   EF = (double **)malloc((n-1)*sizeof(double *));
   for (i=0; i<=n-2; ++i) {
     // printf("    ");
      EF[i] = (double *)malloc(n * sizeof(double));
      for (j=0; j<=n-1; ++j) {
        cin>>EF[i][j];
        // EF[i][j] = (double)(5 + rand() % 5) / (double)10;
       //  printf("%3.1lf  ", EF[i][j]);
      }
      //printf("\n");
   }
   return EF;
}

int **genpotionpos ( int n )
{
   int **PP;
   int i, j;

   //printf("\n+++ Potion positions:\n");
   PP = (int **)malloc(n*sizeof(int *));
   for (i=0; i<=n-1; ++i) {
     // printf("    ");
      PP[i] = (int *)malloc((n-1) * sizeof(int));
      for (j=0; j<=n-2; ++j) {
         cin>>PP[i][j];
         //PP[i][j] = (rand() % n <= 2) ? 1 : 0;
        // printf("%d  ", PP[i][j]);
      }
      //printf("\n");
   }
   return PP;
}

double greedy ( double **EF, int **PP, int n )
{
   int i, j, k, kmax;
   double EL, newEL, ELmax;

   EL = 1.0; i = j = 0;

   printf("    At (%d,%d) with energy level = %lf\n", 0, 0, EL);
   while ((i < n-1) || (j < n-1)) {
      if (i == n-1) {
         if (PP[i][j]) EL *= 1.25;
         ++j;
      } else if (j == n-1) {
         EL *= EF[i][j];
         ++i;
      } else {
         kmax = j; ELmax = EL * EF[i][j];
         for (k=j; k<=n-2; ++k) {
           if (PP[i][k]) EL *= 1.25;
           newEL = EL * EF[i][k+1];
           if (newEL > ELmax) {
              kmax = k+1;
              ELmax = newEL;
           }
         }
         j = kmax;
         ++i;
         EL = ELmax;
      }
      printf("    At (%d,%d) with energy level = %lf\n", i, j, EL);
   }
   return EL;
}

double DP ( double **EF, int **PP, int n )
{
   double **T, EL, EL1, EL2;
   int i, j;

   T = (double **)malloc(n * sizeof(double *));
   for (i=0; i<=n-1; ++i) {
      T[i] = (double *)malloc(n * sizeof(double));
      for (j=0; j<=n-1; ++j) {
         if (j == 0) {
            if (i == 0) T[i][0] = 1.0; else T[i][0] = T[i-1][0] * EF[i-1][0];
         } else {
            EL1 = (i == 0) ? 0 : T[i-1][j] * EF[i-1][j];
            EL2 = (PP[i][j-1]) ? T[i][j-1] * 1.25 : T[i][j-1];
            T[i][j] = (EL1 >= EL2) ? EL1 : EL2;
         }
      }
   }
   EL = T[n-1][n-1];
   for (i=0; i<=n-1; ++i) free(T[i]);
   free(T);
   return EL;
}

void DPsol ( double **EF, int **PP, int n )
{
   double **T, EL1, EL2;
   char **M, *S;
   int i, j, k;

   T = (double **)malloc(n * sizeof(double *));
   M = (char **)malloc(n * sizeof(char *));
   for (i=0; i<=n-1; ++i) {
      T[i] = (double *)malloc(n * sizeof(double));
      M[i] = (char *)malloc(n * sizeof(char));
      for (j=0; j<=n-1; ++j) {
         if (j == 0) {
            if (i == 0) {
               T[i][0] = 1.0;
               M[i][0] = 'S';
            } else {
               T[i][0] = T[i-1][0] * EF[i-1][0];
               M[i][0] = 'V';
            }
         } else {
            EL1 = (i == 0) ? 0 : T[i-1][j] * EF[i-1][j];
            EL2 = (PP[i][j-1]) ? T[i][j-1] * 1.25 : T[i][j-1];
            if (EL1 >= EL2) {
               T[i][j] = EL1;
               M[i][j] = 'V';
            } else {
               T[i][j] = EL2;
               M[i][j] = 'H';
            }
         }
      }
   }

   S = (char *)malloc(2*(n-1)*sizeof(char));
   i = j = n-1; k = 2*n-3;
   while ((i > 0) || (j > 0)) {
      if (M[i][j] == 'H') {
         --j; S[k] = 'H';
      } else {
         --i; S[k] = 'V';
      }
      --k;
   }

   i = j = 0;
   printf("    At (%d,%d) with energy level = %lf\n", 0, 0, T[0][0]);
   for (k=0; k<=2*n-3; ++k) {
      if (S[k] == 'H') ++j; else ++i;
      printf("    At (%d,%d) with energy level = %lf\n", i, j, T[i][j]);
   }

   for (i=0; i<=n-1; ++i) { free(T[i]); free(M[i]); }
   free(T); free(M); free(S);
}

int main ( int argc, char *argv[] )
{
   int n;
   double **EF;
   int **PP;
   double EL;

   cin>>n;

   EF = genexhfacs(n);
   PP = genpotionpos(n);

   printf("\n+++ Part 1: Greedy algorithm\n");
   EL = greedy(EF,PP,n);
   printf("--- Energy level during exit   = %lf\n", EL);

   printf("\n+++ Part 2: Dynamic-programming algorithm\n");
   EL = DP(EF,PP,n);
   printf("--- Energy level during exit   = %lf\n", EL);

   printf("\n+++ Part 3: Dynamic-programming algorithm with solution\n");
   DPsol(EF,PP,n);

   exit(0);
}
