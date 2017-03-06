#include "matrix.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
 
int main (int argc, char *argv[]) {
 
   
    FILE *f = fopen(argv[1], "r");
    if (f == NULL){
        printf ("cant open file\n");
        return 1;
    }
   
   
    Matrix *matrix = create_matrix_from_file(f);
    if(matrix == NULL)
        return -1; 
   
    Matrix *tmatrix = trans_mat(matrix);
    if(tmatrix == NULL)
        return -1;
    show_mat(tmatrix);
 
   
    free_matrix(matrix);
    free_matrix(tmatrix);  
    return 0;
}

