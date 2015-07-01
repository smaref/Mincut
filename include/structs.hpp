
#ifndef STRUCTS_HPP
#define	STRUCTS_HPP

typedef struct
{
  int size;
  double **data;
} matrix_t;

inline matrix_t* MatrixCreate (int size)
{
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
  int size;
  int *data;
} vector_t;

inline vector_t* VectorCreate (int size)
{
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
