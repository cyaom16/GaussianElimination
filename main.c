/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ge.h"
/*
 * 
 */


int main(void)
{
    int N = 3;
    int M = N + 1;
    
    float **A = NULL;
    float *x = NULL;
    int i, j;
    
    printf("Enter number for matrix A\n");
    A = (float **) malloc(N * sizeof(*A));
    for (i = 0; i < N; i++)
    {
        A[i] = (float *) malloc(M * sizeof(float));
        for (j = 0; j < M; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &A[i][j]);
            printf("You entered A[%d][%d] = %f\n", i, j, A[i][j]);
        }
    }
    print_matrix(A, N, M);
    
    x = (float *) malloc(N * sizeof(float));
    
    int r1 = ge_fw(A, N, M, x);
    int r2 = ge_bw(A, N, M, x);
    
    print_matrix(A, N, M);
    
    printf("\nSolutions: ");
    for (i = 0; i < N; i++)
        printf("%f\t", x[i]);
    
    free(A);
    free(x);
    
    return 0;
}





