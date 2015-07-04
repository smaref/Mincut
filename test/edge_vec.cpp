#include <iostream>
#include "build_components.hpp"

int main()
{
int num_nodes =7;
int vec_size = num_nodes * (num_nodes-1) /2;

int_vector_t edge_vec = init_edge_vec (num_nodes, vec_size);

for(int i = 0; i < num_nodes-1 ;i++)
  std::cout<<edge_vec[i]<<std::endl;
    std::cout<<" "<<std::endl;

for(int i = num_nodes-1; i < vec_size ;i++)
  std::cout<<edge_vec[i]<<std::endl;

return 0;
}
