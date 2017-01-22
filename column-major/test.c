/* Calling DGELS using column-major order */

#include <stdio.h>
#include <lapacke.h>
#include "aux.h"  

#define M 5  // #rows of A and B
#define N 3  // #cols of A
#define NRHS 2  // #cols of B
#define LDA M  //  ??
#define LDB M  //  ??


/* Auxiliary routine: printing a matrix */
void print_matrix_colmajor( char* desc, lapack_int m, lapack_int n, double* mat, lapack_int ldm ) {
        lapack_int i, j;
        printf( "\n %s\n", desc );

        for( i = 0; i < m; i++ ) {
                for( j = 0; j < n; j++ ) printf( " %6.2f", mat[i+j*ldm] );
                printf( "\n" );
        }
}

/* Auxiliary routine: printing a vector of integers */
void print_vector( char* desc, lapack_int n, lapack_int* vec ) {
        lapack_int j;
        printf( "\n %s\n", desc );
        for( j = 0; j < n; j++ ) printf( " %6i", vec[j] );
        printf( "\n" );
}

int main (int argc, const char * argv[])
{
   /* Locals */
   double A[5][3] = {{1,2,3},{4,5,1},{3,5,2},{4,1,4},{2,5,3}};
   double b[5][2] = {{-10,12},{14,16},{18,-3},{14,12},{16,16}};
   lapack_int info,m,n,lda,ldb,nrhs;

   /* Initialization */
   m = M;
   n = N;
   nrhs = NRHS;
   lda = LDA;
   ldb = LDB;

   /* Print Entry Matrix */
   print_matrix_colmajor( "Entry Matrix A", m, n, *A, lda );
   /* Print Right Rand Side */
   print_matrix_colmajor( "Right Hand Side b", n, nrhs, *b, ldb );
   printf( "\n" );

   /* Executable statements */
   printf( "LAPACKE_dgels (col-major, high-level) Example Program Results\n" );
   /* Solve least squares problem*/
   info = LAPACKE_dgels(LAPACK_COL_MAJOR,'N',m,n,nrhs,*A,lda,*b,ldb);

   /* Print Solution */
   print_matrix_colmajor( "Solution", n, nrhs, *b, ldb );
   printf( "\n" );
   exit( info );
} /* End of LAPACKE_dgels Example */