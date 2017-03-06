#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

typedef struct Matrix {
	int row;
	int col;
	double** mat;
	
} Matrix;

Matrix* create_matrix(int row, int col);
void set_elem(Matrix* matrix, int row, int col, double val);
Matrix* create_matrix_from_file(FILE* file);
void free_matrix(Matrix* matrix);
double get_elem(Matrix* matrix, int row, int col);
int get_rows(Matrix* matrix);
int get_cols(Matrix* matrix);
void show_mat(Matrix *matr)
Matrix* trans_mat(Matrix* matr)


