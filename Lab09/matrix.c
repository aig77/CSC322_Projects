#include <stdlib.h>
#include <stdio.h>

#define SIZE 3

typedef int Matrix[SIZE][SIZE];

void init(Matrix m1, Matrix m2) {
    printf("Please input data for matrices A and B\n");
    printf("Fill in data for A\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            int val;
            printf("Enter value for position [%d][%d]: ", i, j);
            scanf("%d", &val);
            //m1[i][j] = val;
            *(*(m1+i)+j) = val;
        }
    }
    printf("Fill in data for B\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            int val;
            printf("Enter value for position [%d][%d]: ", i, j);
            scanf("%d", &val);
            //m2[i][j] = val;
            *(*(m2+i)+j) = val;
        }
    }
}

void multiply(Matrix m1, Matrix m2, Matrix ans) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            //ans[i][j] = 0;
            *(*(ans+i)+j) = 0;
            for(int k = 0; k < SIZE; k++) {
                //ans[i][j] = ans[i][j] + m1[i][k] * m2[k][j];
                *(*(ans+i)+j) = *(*(ans+i)+j) + *(*(m1+i)+k) * *(*(m2+k)+j);
            }
        }
    }
}

void printMatrix(Matrix m1) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            //printf("%d ", m1[i][j]);
            printf("%d ", *(*(m1+i)+j));
        }
        printf("\n");
    }
}

int main(void) {

    Matrix m1;
    Matrix m2;
    Matrix ans;

    init(m1, m2);
    printf("Values of A\n");
    printMatrix(m1);
    printf("Values of B\n");
    printMatrix(m2);

    printf("Multiplying A and B\n");
    multiply(m1,m2,ans);

    printf("AB is: \n");
    printMatrix(ans);

    return 0;
}
