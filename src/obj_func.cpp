/*
 * writing the objective function (2×∑{i=0~e-2}∑{j=i+1~e-2}w(i, j)×y(i)×y(j))
 * e = n*(n-1)/2
 * W is the angle matrix
 * y is the edge vector 
 * and gradient function (2×∑{k=0~e-1}∑{j=0~e-1, j!=k}w(i,j)×y(i)×y(j))
*/
#include "obj_func.hpp"

// The objective value
double MyValue (int_vector_t edg_ind, double_matrix_t ang_mat)
{
  double func = 0;
  int vector_size = edg_ind.size();
  for (int i = 0; i < vector_size - 1; i++)
    for (int j = i + 1; j < vector_size; j++)
      func += ang_mat[i][j] * edg_ind[i] * edg_ind[j];
  return func*2;
}

//The gradient vector
double_vector_t MyGrad (int_vector_t edg_ind, double_matrix_t ang_mat)
{

  int vector_size = edg_ind.size();
  double_vector_t grad (vector_size);
//  double grad = new double[vector_size];
  for(int k = 0; k < vector_size; k++)
  {
    grad[k] = 0;
    for (int j = 0 ; j < vector_size; j++)
      if(j!=k)
      {
        grad[k] += ang_mat[k][j] * edg_ind[j]*2; 
      }
  }
  return grad;
}
