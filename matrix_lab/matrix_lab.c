#include <stdio.h>
#define SIZE 5


void addMatrices(int m1[][SIZE], int m2[][SIZE], int result[][SIZE]){
    // In C, arrays cannot be 'returned' unless dynamically allocated.
    // I do not believe that would be necessary for this lab.
    for(int i = 0; i < SIZE; ++i){
        for(int x = 0; x < SIZE; ++x){
            result[i][x] = m1[i][x] + m2[i][x];
        }
    }

}

void multiplyMatrices(int m1[][SIZE], int m2[][SIZE], int result[][SIZE]){
    for(int i = 0; i < SIZE; ++i){
        for(int x = 0; x < SIZE; ++x){
            int sumOfProducts = 0;
            for(int y = 0; y < SIZE; ++y){
                sumOfProducts += m1[i][y] * m2[y][x];
            }
            result[i][x] = sumOfProducts;
        }
    }
}

void transposeMatrix(int m[][SIZE], int result[][SIZE]){
    for(int i = 0; i < SIZE; ++i){
        for(int x = 0; x < SIZE; ++x){
            result[x][i] = m[i][x];
        }
    }
}

void printMatrix(int m[][SIZE]){
    printf("{\n");
    for(int i = 0; i < SIZE; ++i){
        printf("   { ");
        for(int x = 0; x < SIZE; ++x){
            printf("%d ", m[i][x]);   
        }
        printf("}\n");
    }
    printf("}\n");

}


int main(){
    // All functions returns and inputs are assumed to be square matrices of size SIZExSIZE
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int addResult[SIZE][SIZE];
    int multiplyResult[SIZE][SIZE];
    int transposeResult[SIZE][SIZE];

    printf("Printed m1:\n");
    printMatrix(m1);
    printf("\n");
    printf("Sum of m1 and m2:\n");
    addMatrices(m1, m2, addResult);
    printMatrix(addResult);
    printf("\n");
    printf("Product of m1 * m2:\n");
    multiplyMatrices(m1, m2, multiplyResult);
    printMatrix(multiplyResult);
    printf("\n");
    printf("Transpose of m2:\n");
    transposeMatrix(m2, transposeResult);
    printMatrix(transposeResult);

    return 0;
}