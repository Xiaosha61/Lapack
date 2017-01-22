/* Calling DGELS using row-major order */

#include <stdio.h>
#include <lapacke.h>

#define M 3  // #rows of A and B
#define N 3  // #cols of A
#define NRHS 1  // #cols of B
#define LDA N  // #rows of coefficients
#define LDB NRHS  // #cols of coefficients


/* Auxiliary routine: printing a matrix */
void print_matrix_rowmajor( char* desc, lapack_int m, lapack_int n, double* mat, lapack_int ldm ) {
        lapack_int i, j;
        printf( "\n %s\n", desc );

        for( i = 0; i < m; i++ ) {
                for( j = 0; j < n; j++ ) printf( " %6.2f", mat[i*ldm+j] );
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
   double A[M][N] = {1,1,1, 
                     1,2,4, 
                     1,3,9 };

   double B[M][NRHS] = {1,
                        2,
                        3};

   lapack_int info,m,n,lda,ldb,nrhs;
 
   m = M;
   n = N;
   nrhs = NRHS;
   lda = LDA;
   ldb = LDB;

   /* Print Entry Matrix */
   print_matrix_rowmajor( "Entry Matrix A", m, n, *A, lda );
   /* Print Right Rand Side */
   print_matrix_rowmajor( "Right Hand Side B", n, nrhs, *B, ldb );
   printf( "\n" );


   /* Executable statements */
   printf( "LAPACKE_dgels (row-major, high-level) Example Program Results\n" );
   /* Solve least squares problem*/
   info = LAPACKE_dgels(LAPACK_ROW_MAJOR,'N',m,n,nrhs,*A,lda,*B,ldb);

   /* Print Solution */
   print_matrix_rowmajor( "Solution", n, nrhs, *B, ldb );
   printf( "\n" );
   exit( 0 );
} /* End of LAPACKE_dgels Example */
