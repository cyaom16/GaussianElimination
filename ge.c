/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int ge_fw(float **matrix, int rows, int cols, float *x)
{
    float c, amax, xfac, tmp;
    int i, j, k, m;
    int rowx = 0;
    
    if (matrix == NULL || x == NULL) 
        return -1;
    
    for (j = 0; j < cols - 1; j++)
    {
        amax = fabsf(matrix[j][j]);
        m = j;
        // Find the row with the largest pivot
        for (i = j + 1; i < rows; i++)
        {
            xfac = fabsf(matrix[i][j]);
            if (xfac > amax)
            {
                amax = xfac;
                m = i;
            }
        }
        // Row interchange
        if (m != j)
        {
            printf("# of row interchanges: %d\n", ++rowx);
            for (k = j; k < cols; k++)
            {
                tmp = matrix[j][k];
                matrix[j][k] = matrix[m][k];
                matrix[m][k] = tmp;
            }
        }
        
        /* loop for the generation of upper triangular matrix*/
        for (i = j + 1; i < rows; i++)
        {
            c = matrix[i][j] / matrix[j][j];
            for (k = 0; k < cols; k++)
                matrix[i][k] -= c * matrix[j][k];
        }
        
    }
    x[rows - 1] = matrix[rows - 1][cols - 1] / matrix[rows - 1][cols - 2];
 
    return 0;
}

int ge_bw(float **matrix, int rows, int cols, float *x)
{
    int i, j;
    float sum;
    
    if (matrix == NULL || x == NULL) 
        return -1;
    
    for(i = rows - 2; i >= 0; i--)
    {
        sum = 0;
        for(j = i + 1; j < cols - 1; j++)
            sum += matrix[i][j] * x[j];
        x[i] = (matrix[i][cols - 1] - sum) / matrix[i][i];
    }
    return 0;
}


void print_matrix(float **a, int rows, int cols)
{
    int i, j;
    printf("\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            printf("%.3f\t", a[i][j]);
        printf("\n");
    }
}