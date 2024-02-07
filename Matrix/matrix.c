#include "matrix.h"

int create_matrix(int rows, int columns, matrix_t *result) {
  memset(result, 0, sizeof(matrix_t));
  if (negative_size(rows, columns) || is_null(result)) {
    return INCORRECT;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0;
      }
    }
  }
  return OK;
}

void remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

int eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS, rows = A->rows, cols = A->columns;
  if (is_null(A) || is_null(B) || equal_size(A, B)) {
    res = FAILURE;
  }
  if (res == SUCCESS) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
          res = FAILURE;
          break;
        }
      }
      if (res == FAILURE) {
        break;
      }
    }
  }
  return res;
}

int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  memset(result, 0, sizeof(matrix_t));
  int res = OK, rows = A->rows, cols = A->columns;
  if (is_null(A) || is_null(B) || is_null(result)) {
    return INCORRECT;
  }
  res = create_matrix(rows, cols, result);
  if (equal_size(A, B) && res == 0) {
    res = ERROR;
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return res;
}

int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  memset(result, 0, sizeof(matrix_t));
  int rows = A->rows, cols = A->columns;
  if (negative_size(A->rows, A->columns) ||
      negative_size(B->rows, B->columns)) {
    return INCORRECT;
  }
  if (equal_size(A, B) || is_null(A) || is_null(B)) {
    return ERROR;
  }
  create_matrix(rows, cols, result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}

int mult_number(matrix_t *A, double number, matrix_t *result) {
  memset(result, 0, sizeof(matrix_t));
  int rows = A->rows, cols = A->columns;
  if (is_null(A) || is_null(result) ||
      negative_size(A->rows, A->columns)) {
    return INCORRECT;
  }
  if (isinf(number) || isnan(number)) {
    return ERROR;
  }
  create_matrix(rows, cols, result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result->matrix[i][j] = number * A->matrix[i][j];
    }
  }
  return OK;
}

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  memset(result, 0, sizeof(matrix_t));
  int res = OK;
  if (is_null(A) || is_null(B) || is_null(result)) {
    return INCORRECT;
  }
  res = create_matrix(A->rows, B->columns, result);
  if (A->columns != B->rows && res == 0) {
    res = ERROR;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int l = 0; l < A->columns; l++) {
        result->matrix[i][j] += A->matrix[i][l] * B->matrix[l][j];
      }
    }
  }
  return res;
}

int transpose(matrix_t *A, matrix_t *result) {
  memset(result, 0, sizeof(matrix_t));
  int res = OK, rows = A->rows, cols = A->columns;
  if (is_null(A) || is_null(result)) {
    return INCORRECT;
  }
  res = create_matrix(cols, rows, result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return res;
}

int calc_complements(matrix_t *A, matrix_t *result) {
  memset(result, 0, sizeof(matrix_t));
  int res = OK, rows = A->rows, cols = A->columns;
  if (is_null(A) || is_null(result)) {
    return INCORRECT;
  } else if (rows != cols) {
    return ERROR;
  }
  res = create_matrix(rows, cols, result);
  matrix_t determinant;
  if (res == 0) {
    if (rows > 1) {
      res = create_matrix(rows - 1, cols - 1, &determinant);
    } else {
      result->matrix[0][0] = 1.;
    }
  }
  for (int minor_row = 0; minor_row < rows && rows > 1; minor_row++) {
    for (int minor_col = 0; minor_col < cols; minor_col++) {
      determinant_m(&determinant, A, minor_row, minor_col);
      determinant(&determinant, &result->matrix[minor_row][minor_col]);
    }
  }
  if (rows > 1) {
    remove_matrix(&determinant);
    algebraic_comp(A, result);
  }
  return res;
}

int determinant(matrix_t *A, double *result) {
  memset(result, 0, sizeof(double));
  int res = OK;
  if (is_null(A) || result == NULL) {
    return INCORRECT;
  } else if (A->rows != A->columns) {
    return ERROR;
  }
  matrix_t tmp;
  res = create_matrix(A->rows, A->columns, &tmp);
  for (int i = 0; i < tmp.rows; i++) {
    for (int j = 0; j < tmp.columns; j++) {
      tmp.matrix[i][j] = A->matrix[i][j];
    }
  }
  int not_zero = 0, all_zero = 1, sign = 1;
  double *temp = NULL;
  *result = 1.;

  for (int rows = 0; rows < tmp.rows - 1 && *result; rows++) {
    for (not_zero = rows; not_zero < tmp.rows; not_zero++) {
      if (tmp.matrix[not_zero][rows]) {
        temp = tmp.matrix[not_zero];
        all_zero = 0;
        break;
      }
    }
    if (tmp.matrix[rows][rows] == 0. && temp) {
      tmp.matrix[not_zero] = tmp.matrix[rows];
      tmp.matrix[rows] = temp;
      sign = -sign;
    }
    if (all_zero) {
      *result = 0.;
    } else {
      for (int m = rows + 1; m < tmp.rows; m++) {
        double temp = tmp.matrix[m][rows] / tmp.matrix[rows][rows];
        for (int n = rows; n < tmp.columns; n++) {
          tmp.matrix[m][n] -= tmp.matrix[rows][n] * temp;
        }
      }
    }
  }
  for (int k = 0; k < A->rows; k++) {
    *result *= tmp.matrix[k][k];
  }
  *result *= sign;
  remove_matrix(&tmp);
  return res;
}

int inverse_matrix(matrix_t *A, matrix_t *result) {
  memset(result, 0, sizeof(matrix_t));
  int res = OK, rows = A->rows, cols = A->columns;
  if (is_null(A) || is_null(result)) {
    return INCORRECT;
  } else if (rows != cols) {
    return ERROR;
  }
  res = create_matrix(A->rows, A->columns, result);
  double det = 0.;
  determinant(A, &det);
  if (det) {
    matrix_t complements, transpose;

    calc_complements(A, &complements);
    transpose(&complements, &transpose);

    mult_number(&transpose, 1 / det, result);

    remove_matrix(&complements);
    remove_matrix(&transpose);
  } else {
    res = ERROR;
  }
  return res;
}

int main(void) {
  matrix_t A;
  create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t B;
  create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  int result = eq_matrix(&A, &B);
  printf("%d -> actual\n%d -> needed\n", result, 1);
  remove_matrix(&A);
  remove_matrix(&B);
}