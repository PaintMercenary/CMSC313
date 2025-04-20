#include <stdio.h>

const int maxSize = 10;

void matrixMultiplcation(int matrix1[][maxSize], int matrix2[][maxSize], int final[][maxSize], int row1, int col1, int row2, int col2) {
    if (col1 != row2) {
        printf("Matrix multiplcation invalid\n");
        return;
    }
    
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            final[i][j] = 0;
        }
    }

    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            for (int k = 0; k < col1; ++k) {
                final[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void scalarMultiplication(int matrix[][maxSize], int row, int col, int scalar) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix[i][j] *= scalar;
        }
    }
}

void matrixTranspose(int matrix[][maxSize], int matrixB[][maxSize], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrixB[j][i] = matrix[i][j];
        }
    }
}

void matrixAdd(int matrix[][maxSize], int matrixB[][maxSize], int row1, int col1, int row2, int col2) {
    if (row1 == row2 && col1 == col2) {
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                matrix[i][j] += matrixB[i][j];
            }
        }
    }
}


void showMatrix(int matrix[][maxSize], int row, int col) {
    printf("Output\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
            if (j == col - 1) {
                printf("\n");
            }
        }
    }
}

void buildMatrix(int matrix[][maxSize], int row, int col) {
    printf("Building Matrix...\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Input %d %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int scalar = 3;
    int row1 = 0;
    int row2 = 0;
    int col1 = 0;
    int col2 = 0;

    int matrixA[maxSize][maxSize];
    int matrixB[maxSize][maxSize];
    int matrixC[maxSize][maxSize];
    int matrixCt[maxSize][maxSize];
    int matrixBxC[maxSize][maxSize];

    printf("Enter rows and column for the first matrix: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter rows and column for the second matrix: ");
    scanf("%d %d", &row2, &col2);

    buildMatrix(matrixA, row1, col1);
    buildMatrix(matrixB, row1, col2);
    buildMatrix(matrixC, row1, col2);

    scalarMultiplication(matrixB, row1, col2, scalar);
    showMatrix(matrixB, row1, col2);
    matrixTranspose(matrixC, matrixCt, row1, col2);
    showMatrix(matrixCt, col2, row1);
    matrixMultiplcation(matrixB, matrixCt, matrixBxC, row1, col2, col2, row2);
    showMatrix(matrixBxC, row1, col1);

    matrixAdd(matrixA, matrixBxC, row1, col1, row1, col1);

    showMatrix(matrixA, row1, col1);

}