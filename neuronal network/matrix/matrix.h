#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int row;
    int column;
    double** value;
} Matrix;

Matrix* create_matrix(int row, int column);
void fill_matrix(Matrix *matrix, double values[]);
void print_matrix(Matrix *matrix);

#endif