
#include <iostream>
#include "obj_func.hpp"
#include <cstdlib>
#include <time.h>

int main (int argc, char const *argv[])
{
  int num_nodes = 5;
  int vector_size = num_nodes * (num_nodes - 1) / 2;

  double_matrix_t ang_mat (vector_size, std::vector<double>(vector_size)); /* This is not a function, but a matrix constructor! */
  int_vector_t edge_ind (vector_size);

  srand (time (NULL));
  for (int i = 0; i < vector_size; i++)
    {
      for (int j = i + 1; j < vector_size; ++j)
        {
          ang_mat[i][j] = rand() % 10;
          ang_mat[j][i] = ang_mat[i][j];
        }
      if (i % 2 == 0)
        {
          edge_ind[i] = 0;
        }
      else edge_ind[i] = 1;
    }

  std::cout << "Angle Matrix:" << std::endl;
  for (int i = 0; i < vector_size; ++i)
    {
      for (int j = 0; j < vector_size; ++j)
        {
          std::cout << ang_mat[i][j] << " ";
        }
      std::cout << std::endl;
    }

  std::cout << std::endl;
  std::cout << "Vector:" << std::endl;
  for (int i = 0; i < vector_size; ++i)
    std::cout << edge_ind[i] << " ";

  std::cout << std::endl;
  std::cout << "MyValue:" << std::endl;
  std::cout << MyValue (edge_ind, ang_mat);
  std::cout << std::endl;

  double_vector_t gradient = MyGrad (edge_ind, ang_mat);

  std::cout << "Gradient:" << std::endl;
  for (int i = 0; i < vector_size; i++)
    {
      std::cout << gradient[i] << std::endl;
    }
  return 0;
}

//  for (int i = 0; i < vector_size; ++i)
//  {
//    for (int j = 0; j < vector_size; ++j)
//    {
//      std::cout << ang_mat[i][j] << "mat " << std::endl;
//    }
//    std::cout << edge_ind[i] << " edge" << std::endl;
//  }
