/* Calling DGELS using column-major order */

#include <stdio.h>
#include <lapacke.h>

#define M 5  // #rows of A and B
#define N 3  // #cols of A
#define NRHS 2  // #cols of B
#define LDA 5  // 
#define LDB 5  // 


int main (int argc, const char * argv[])
{
   double a[5*3] = {1,2,3,4,5,1,3,5,2,4,1,4,2,5,3};
   double b[5*2] = {-10,12,14,16,18,-3,14,12,16,16};
   lapack_int info,m,n,lda,ldb,nrhs;
   int i,j;

   m = M;
   n = N;
   nrhs = NRHS;
   lda = LDA;
   ldb = LDB;

   info = LAPACKE_dgels(LAPACK_COL_MAJOR,'N',m,n,nrhs,a,lda,b,ldb);

   for(i=0;i<n;i++)
   {
      for(j=0;j<nrhs;j++)
      {
         printf("%lf ",b[i+ldb*j]);
      }
      printf("\n");
   }
   return(info);
}