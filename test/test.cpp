#include <iostream>
#include "function.hpp"
#include <cstdlib>
#include <time.h>

int main (int argc, char const *argv[])
{
  int vector_size = 4;
  vector_t *edge_ind = VectorCreate (vector_size);
  matrix_t *ang_mat = MatrixCreate (vector_size);

  srand (time(NULL));
  for (int i = 0; i < vector_size; i++)
  {
    for (int j = i+1; j < vector_size; ++j)
    {
      if (i == j)
        ang_mat->data[i][j] = 0;
      else
      {
        ang_mat->data[i][j] = rand()%10;
        ang_mat->data[j][i] = ang_mat->data[i][j];
      }
    }
    if (i % 2 == 0)
    {
      edge_ind->data[i] = 0;
    }
    else edge_ind->data[i] = 1;
  }

  std::cout << "Angle Matrix:" << std::endl;
  for (int i = 0; i < vector_size; ++i)
  {
    for (int j = 0; j < vector_size; ++j)
    {
      std::cout << ang_mat->data[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
  std::cout << "Vector:" << std::endl;
  for (int i = 0; i < vector_size; ++i)
    std::cout << edge_ind->data[i] << " " ;

  std::cout << std::endl;
  std::cout << "MyValue:" << std::endl;
  std:: cout << MyValue (edge_ind, ang_mat);
  std::cout << std::endl;
  
  double *grad = MyGrad (edge_ind, ang_mat);

  std::cout << "Gradient:" << std::endl;
  for (int i = 0; i < vector_size; i++)
  {
    std::cout << grad[i] << std::endl;
  }
  MatrixDelete (ang_mat);
  VectorDelete (edge_ind);
  return 0;
}

//  for (int i = 0; i < vector_size; ++i)
//  {
//    for (int j = 0; j < vector_size; ++j)
//    {
//      std::cout << ang_mat->data[i][j] << "mat " << std::endl;
//    }
//    std::cout << edge_ind->data[i] << " edge" << std::endl;
//  }
