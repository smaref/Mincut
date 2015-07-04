#include <iostream>
#include "build_components.hpp"

int main()
{
  int num_nodes = 5;
  int row_length = num_nodes*(num_nodes-1)/2; 

  int_matrix_t mycoeff = CreateCoeffMatrix(num_nodes, row_length);

  for(int i = 0; i < row_length; i++)
  {
    for(int j = 0; j < row_length; j++)
    {
      std::cout << mycoeff[i][j] << "\t";
    }
    std::cout << std::endl;
  }

  return 0;
}
