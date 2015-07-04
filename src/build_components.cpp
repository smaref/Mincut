/*
 * Building the coefficient matrix A of size n*(n-1)/2 x (n*(n-1)/2), n is number of vertices, 
 * as in the linear constraint Ay = 0
 * y is the vector indicating the edges between vertices of size 1 x n*(n-1)/2.
 */
#include <iostream>
#include "build_components.hpp"

int_matrix_t CreateCoeffMatrix (int num_nodes, int row_length)
{
  //creating a matrix with size n*(n-1)/2 x n*(n-1)/2
  int_matrix_t coeff (row_length, int_vector_t(row_length));

  //creating the matrix coefficient(A) 
  for (int sec = 1; sec < num_nodes - 1; sec++)
    {
      int begin = (sec * num_nodes) - sec * (sec + 1) / 2;
      for (int row = (sec * num_nodes) - sec * (sec + 1) / 2; row < (sec + 1) * num_nodes - (sec + 1)*(sec + 2) / 2; row++)
        {
          coeff[row][row] = -1;
          coeff[row][sec - 1] = 1;
          coeff[row][sec + row - begin] = -1;
        }
    }

  return coeff;
}

int_vector_t init_edge_vec (int num_nodes, int vec_size)
{
  int ind = num_nodes-1;
  int_vector_t edge_vec(vec_size);

  for (int edge_indx = 0; edge_indx < (num_nodes - 1) / 2; edge_indx++)
    edge_vec[edge_indx] = 1;

  for (int i = 0; i < num_nodes - 2; i++)
    for (int j = i + 1; j < num_nodes - 1; j++)
      {
        edge_vec[ind] = edge_vec[i] - edge_vec[j];
        ind++;
      }
  return edge_vec;
}