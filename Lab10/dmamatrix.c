#include <stdlib.h>
#include <stdio.h>

#define SIZE 8

typedef char String[SIZE];

double *input_matrix(int *rows, int *cols, String name) {
    printf("Input data for %s\n", name);
    printf("Number of Rows: ");
    scanf("%d", rows);
    printf("Number of Columns: ");
    scanf("%d", cols);

    int r = *rows;
    int c = *cols;
    double *matrix = (double *)malloc(r * c * sizeof(double));
    if(!matrix) {
        printf("ERROR: Out of memory");
        exit(1);
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("Enter value for [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i*c+j]);
            //printf("Value inserted: %lf\n", matrix[i*c+j]);
        }
    }

    return matrix;
}

int matrix_multiply(double *m1, int r1, int c1,
        double *m2, int r2, int c2, double *ans) {
        if(c1 == r2) {
            // multiply matrices
            for(int i = 0; i < r1; i++)
                for(int j = 0; j < c2; j++)
                    for(int k = 0; k < c1; k++)
                        ans[i*c2+j] = ans[i*c2+j] + m1[i*c1+k] * m2[k*c2 + j];
            return 1;
        } else
            return 0;
}

void output_matrix(double *matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i*cols+j]);
        }
        printf("\n");
    }
}

int main(void) {
    double *m1,*m2,*m3;
    int m1_rows,m1_columns,m2_rows,m2_columns;
    if (((m1 = input_matrix(&m1_rows,&m1_columns,"Matrix 1")) != NULL) &&
        ((m2 = input_matrix(&m2_rows,&m2_columns,"Matrix 2")) != NULL) &&
        ((m3 = malloc(m1_rows*m2_columns*sizeof(double))) != NULL)) {
        printf("Matrix 1\n");
        output_matrix(m1,m1_rows,m1_columns);
        printf("Matrix 2\n");
        output_matrix(m2,m2_rows,m2_columns);
        if (matrix_multiply(m1,m1_rows,m1_columns,m2,m2_rows,m2_columns,m3)) {
            printf("Product\n");
            output_matrix(m3,m1_rows,m2_columns);
            free(m1);
            free(m2);
            free(m3);
            return(0);
        } else {
            printf("Error in dimensions\n");
            free(m1);
            free(m2);
            free(m3);
        }
    } else {
        free(m1);
        free(m2);
        free(m3);
        printf("Error allocating memory\n");
        return(-2);
    }
}
