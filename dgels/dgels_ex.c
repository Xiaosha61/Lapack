/* Calling DGELS using row-major order */

#include <stdio.h>
#include <lapacke.h>



int main (int argc, const char * argv[])
{
   double A[3][2] = {1,1,1,2,1,3};
   double B[3][1] = {1,2,3};
   lapack_int info,m,n,lda,ldb,nrhs;
   int i,j;
/*
   m = 3;  // #rows of A
   n = 2;	// #cols of A
   nrhs = 1;
   lda = 2;  // #rows of coefficients
   ldb = 1;  // #cols of coefficients
*/
   m = 2; 
   n = 2;	
   nrhs = 1;
   lda = 3;  
   ldb = 3;  



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
