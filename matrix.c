#include "matrix.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>


Matrix* create_matrix(int row, int col){
	Matrix *matr  = (Matrix*)calloc(1, sizeof(Matrix));
	matr -> row = row;
	matr -> col = col;
	matr -> mat = (double**)calloc(row, sizeof(double*));
	if(matr -> mat == NULL)
		return NULL;
	for(int i = 0; i < row; i++){
		(matr -> mat)[i] = (double*)calloc(col, sizeof(double));
		if((matr -> mat)[i] == NULL)
			return NULL;
	}
	return matr;
};


void set_elem(Matrix* matrix, int row, int col, double val){
	(matrix -> mat)[row][col] = val;
};

Matrix* create_matrix_from_file(FILE* file){
	int n, m, count;	
	fscanf (file, "%d", &n);
	fscanf (file, "%d", &m);
	fscanf (file, "%d", &count);		
	Matrix* matr = create_matrix(n, m);
	if(matr == NULL)
		return NULL;
	for (int i = 0; i <count*3; i++){
		int strk, stlb;
		double znach;
		fscanf (file, "%d", &strk);
		fscanf (file, "%d", &stlb);
		fscanf (file, "%lf", &znach);
		set_elem(matr, strk, stlb, znach);
	}
	return matr;
};

void free_matrix(Matrix* matrix){
	free(matrix);
};
double get_elem(Matrix* matrix, int row, int col){
	return (matrix -> mat)[row][col];
};
int get_rows(Matrix* matrix){
	return matrix -> row;	
};
int get_cols(Matrix* matrix){
	return matrix -> col;
};



void show_mat(Matrix *matr){
	for (int i = 0; i < get_rows(matr); i++){
		for (int j = 0; j < get_cols(matr); j++){
			printf ("%g   ", get_elem(matr, i, j));					
		}
		printf("\n");		
	}
}

Matrix* trans_mat(Matrix* matr){
	int n = get_rows(matr);
	int m = get_cols(matr);
	Matrix* matrt = create_matrix(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		set_elem(matrt, i , j, get_elem(matr, j, i));	
	}
	return matrt;
}


