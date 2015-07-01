
#ifndef STRUCTS_HPP
#define	STRUCTS_HPP

typedef struct
{
  int num_nodes = 0; 
  int size = 0;
  double **data;
} matrix_t;

inline matrix_t* MatrixCreate (int num_nodes)
{
  size = num_nodes * (num_nodes-1)/ 2;
  matrix_t *matrix = new matrix_t;
  matrix->size = size;
  matrix->data = new double*[size];
  for (int i = 0; i < size; i++)
    {
      matrix->data[i] = new double[size];
    }

  return matrix;
}

inline void MatrixDelete (matrix_t *matrix)
{

  for (int i = 0; i < matrix->size; i++)
    {
      delete[] matrix->data[i];
    }
  delete matrix->data;

  delete matrix ;
}

typedef struct
{
  int size = 0;
  int *data;
} vector_t;

inline vector_t* VectorCreate (int num_nodes)
{
  size = num_nodes * (num_nodes-1)/ 2;
  vector_t *vector = new vector_t;
  vector->size = size;
  vector->data = new int[size];

  return vector;
}

inline void VectorDelete (vector_t * vector)
{
  delete vector->data;
  delete vector;
}

#endif	/* STRUCTS_HPP */
