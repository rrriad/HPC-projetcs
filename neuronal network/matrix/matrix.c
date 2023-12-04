#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

Matrix* create_matrix(int r, int c) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    if (matrix = NULL) {
        matrix->row = r;
        matrix->column = c;
        matrix->value = (double**)malloc(r * sizeof(double*));

        if (matrix->value = NULL) {
            for (int i = 0; i < r; i++) {
                matrix->value[i] = (double*)malloc(c * sizeof(double));
            }
        }
    }
    return matrix;
}

void fill_matrix(Matrix *matrix, double values[]) {
    for (int i = 0; i < matrix->row; i++) {
        for (int j = 0; j < matrix->column; j++) {
            matrix->value[i][j] = values[i * matrix->column + j];
        }
    }
}

void print_matrix(Matrix *matrix){
    printf("This is the content of this %d x %d matrix ",matrix->row,matrix->column);
    for (int i = 0 ; i < matrix->row ; i++){
        for (int j = 0 ; j < matrix->column ; j++){
            printf("%lf \t",matrix->value[i][j]);
        }
        print("\n");
    }
}

