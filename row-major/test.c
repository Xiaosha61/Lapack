/* Calling DGELS using row-major order */

#include <stdio.h>
#include <lapacke.h>

#define M 3  // #rows of A and B
#define N 2  // #cols of A
#define NRHS 1  // #cols of B
#define LDA 2  // #rows of coefficients
#define LDB 1  // #cols of coefficients

int main (int argc, const char * argv[])
{
   double A[M][N] = {1,1,1,2,1,3};
   double B[M][NRHS] = {1,2,3};
   lapack_int info,m,n,lda,ldb,nrhs;
   int i,j;

   m = M;
   n = N;
   nrhs = NRHS;
   lda = LDA;
   ldb = LDB;

   info = LAPACKE_dgels(LAPACK_ROW_MAJOR,'N',m,n,nrhs,*A,lda,*B,ldb);

   for(i=0;i<n;i++)
   {
      for(j=0;j<nrhs;j++)
      {
         printf("%lf ",B[i][j]);
      }
      printf("\n");
   }
   return(info);
}
