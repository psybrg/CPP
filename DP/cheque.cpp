#include <bits/stdc++.h>
using namespace std;
double esexchange( double *A, double *B, int n, int i, int j, double exchrate )
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
double dpexchange ( double *A, double *B, int n )
{
   double T[n+1][n+1], exchrate, sol1, sol2;
   int i, j;

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
   return sol1;
}

int main ()
{
   int n,i;
   double A[100],B[100];
   cin>>n;
   for(i=0;i<n;i++)
    cin>>A[i];
   for(i=0;i<n;i++)
    cin>>B[i];

   printf("\n+++ Exhaustive Search\n    Maximum exchange = %.2lf\n",esexchange(A,B,n,0,0,100));

   printf("\n+++ Greedy Strategy\n    Maximum exchange = %.2lf\n",grexchange(A,B,n));

   printf("\n+++ Dynamic Programming\n    Maximum exchange = %.2lf\n",dpexchange(A,B,n));

   exit(0);
}