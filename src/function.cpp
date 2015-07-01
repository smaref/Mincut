#include "function.hpp"

double MyValue (vector_t *edg_ind, matrix_t *ang_mat)
{
  double func = 0;
  int vector_size = edg_ind->size;
  for (int i = 0; i < vector_size - 1; i++)
    for (int j = i + 1; j < vector_size; j++)
      func += ang_mat->data[i][j] * edg_ind->data[i] * edg_ind->data[j];
  return func*2;
}

double* MyGrad (vector_t *edg_ind, matrix_t *ang_mat)
{

  int vector_size = edg_ind->size;
  double *grad = new double[vector_size];
  for(int k = 0; k < vector_size; k++)
  {
    grad[k] = 0;
    for (int j = 0 ; j < vector_size; j++)
      if(j!=k)
      {
        grad[k] += ang_mat->data[k][j] * edg_ind->data[j]*2; 
      }
  }
  return grad;
}
