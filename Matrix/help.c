#include "s21_matrix.h"

int s21_negative_size(int rows, int columns) {
  return rows <= 0 || columns <= 0;
}

int s21_is_null(matrix_t *A) { return A == NULL; }

int s21_equal_size(matrix_t *A, matrix_t *B) {
  return A->rows != B->rows || A->columns != B->columns;
}

void s21_determinant_m(matrix_t *determinant, matrix_t *A, int minor_row,
                       int minor_col) {
  for (int src_row = 0, det_rows = 0; src_row < A->rows; src_row++) {
    for (int src_col = 0, det_col = 0; src_col < A->columns; src_col++) {
      if (src_row != minor_row && src_col != minor_col) {
        determinant->matrix[det_rows][det_col] = A->matrix[src_row][src_col];
        det_col++;
        if (det_col == determinant->columns) {
          det_rows++;
          det_col = 0;
        }
      }
    }
  }
}

void s21_algebraic_comp(matrix_t *A, matrix_t *result) {
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; n++) {
      if ((n + m) % 2) {
        result->matrix[m][n] *= -1;
      }
    }
  }
}