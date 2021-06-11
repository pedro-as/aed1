/**
 * Struct Library - v0.1 - 05/06/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Multipurpose library for manipulation of composite data types (structs)
 */

// dependencias
#include "io.h"

// definicoes globais

typedef
    struct s_int_Array
    {
        int length;
        ints data;
        int ix;
    }
    int_Array;

typedef int_Array *ref_int_Array;

typedef
    struct s_int_Matrix
    {
        int lines;
        int columns;
        ints *data;
        int ix, iy;
    }
    int_Matrix;

typedef int_Matrix *ref_int_Matrix;

// metodos

ref_int_Array new_int_Array(int n)
{
    ref_int_Array tmpArray = (ref_int_Array) malloc(sizeof(int_Array));

    if (tmpArray == NULL)
    {
        IO_printf("\nERRO: Falta espaco\n");
    }
    else
    {
        tmpArray->length = 0;
        tmpArray->data = NULL;
        tmpArray->ix = -1;

        if (n > 0)
        {
            tmpArray->length = n;
            tmpArray->data = (ints) malloc(n * sizeof(int));
            tmpArray->ix = 0;
        }
    }
    return (tmpArray);
}

void free_int_Array(ref_int_Array tmpArray)
{
    if (tmpArray != NULL)
    {
        free(tmpArray->data);
        free(tmpArray);
    }
}

void printIntArray(int_Array array)
{
    for (array.ix = 0; array.ix < array.length; array.ix++)
    {
        IO_printf("%2d: %d\n", array.ix, array.data[array.ix]);
    }
}

void printIntArray_ref(ref_int_Array array)
{
    for (array->ix = 0; array->ix < array->length; array->ix++)
    {
        IO_printf("%2d: %d\n", array->ix, array->data[array->ix]);
    }
}

int_Array IO_readintArray()
{
    chars text = IO_new_chars(STR_SIZE);
    static int_Array array;

    do
    {
        array.length = IO_readint("\nlength = ");
    }
    while (array.length <= 0);

    array.data = IO_new_ints(array.length);

    if (array.data == NULL)
    {
        array.length = 0;
    }
    else
    {
        for (array.ix = 0; array.ix < array.length; array.ix++)
        {
            strcpy(text, STR_EMPTY);
            array.data[array.ix] 
            = IO_readint(IO_concat(
                         IO_concat(text, IO_toString_d(array.ix)), ": "));
        }
    }
    return (array);
}

void fprintIntArray(chars fileName, int_Array array)
{
    FILE *file = fopen(fileName, "wt");

    // gravar quantidade de dados
    IO_fprintf(file, "%d\n", array.length);

    for (array.ix = 0; array.ix < array.length; array.ix++)
    {
        IO_fprintf(file, "%d\n", array.data[array.ix]);
    }

    fclose(file);
}

ref_int_Array freadintArray(chars fileName)
{
    ref_int_Array array = NULL;
    int length = 0;
    FILE *file = fopen(fileName, "rt");

    fscanf(file, "%d", &length);

    if (length <= 0)
    {
        IO_printf("\nERRO: tamanho invalido");
    }
    else
    {
        array = new_int_Array(length);

        if (array->data == NULL)
        {
            array->length = 0;
            array->data = 0;
            array->ix = 0;
        }
        else
        {
            array->ix = 0;

            while (!feof(file) && array->ix < array->length)
            {
                fscanf(file, "%d", &array->data[array->ix]);
                array->ix++;
            }
            array->ix = 0;
        }
    }
    return (array);
}

int getRandomInt(int start, int stop)
{
    return (start + rand() % (stop - start + 1));
}

bool searchIntArray(int value, ref_int_Array array)
{
    bool result = false;
    array->ix = 0;

    while (array->ix < array->length && !result)
    {
        result = array->data[array->ix] == value;
        array->ix++;
    }
    return (result);
}

int freadArraySize(chars fileName)
{
    int n = 0;
    FILE *file = fopen(fileName, "rt");

    fscanf(file, "%d", &n);
    return (n);
}

bool isEqual_array(ref_int_Array array1, ref_int_Array array2)
{
    bool result = true;
    array1->ix = 0;

    while (array1->ix < array1->length && result)
    {
        result = result && (array1->data[array1->ix] == 
                            array2->data[array1->ix]);
        
        array1->ix++;
    }
    array1->ix = 0;
    return (result);
}

int sumIntArrays(ref_int_Array array1, ref_int_Array array2, int k)
{
    int sum = 0;

    for (array1->ix = 0; array1->ix < array1->length; array1->ix++)
    {
        sum += array1->data[array1->ix] + array2->data[array1->ix] * k;
    }

    return (sum);
}

bool isAscOrdered(ref_int_Array array)
{
    bool result = true;
    array->ix = 1;
    
    while (array->ix < array->length && result)
    {
        result = result && (array->data[array->ix] > array->data[array->ix - 1]);
        array->ix++;
    }

    array->ix = 0;
    return (result);
}

ref_int_Matrix new_int_Matrix(int lines, int columns)
{
    ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc(sizeof(int_Matrix));

    if (tmpMatrix != NULL)
    {
        tmpMatrix->lines = 0;
        tmpMatrix->columns = 0;
        tmpMatrix->data = NULL;

        if (lines > 0 && columns > 0)
        {
            tmpMatrix->lines = lines;
            tmpMatrix->columns = columns;
            tmpMatrix->data = (ints*) malloc(lines * sizeof(ints));

            for (tmpMatrix->ix = 0;
                 tmpMatrix->ix < tmpMatrix->lines;
                 tmpMatrix->ix++)
            {
                tmpMatrix->data[tmpMatrix->ix] = (ints) malloc(columns * sizeof(int));
            }
        }

        tmpMatrix->ix = 0;
        tmpMatrix->iy = 0;
    }
    return (tmpMatrix);
}

void free_int_Matrix(ref_int_Matrix tmpMatrix)
{
    if (tmpMatrix != NULL)
    {
        for (tmpMatrix->ix = 0;
            tmpMatrix->ix < tmpMatrix->lines;
            tmpMatrix->ix++)
        {
            free(tmpMatrix->data[tmpMatrix->ix]);
        }

        free(tmpMatrix->data);
        free(tmpMatrix);
    }
}

ref_int_Matrix freadintMatrix (chars fileName)
{
    ref_int_Matrix matrix = NULL;
    int lines = 0;
    int columns = 0;
    FILE *file = fopen (fileName, "rt");

    fscanf(file, "%d", &lines);
    fscanf(file, "%d", &columns);

    if (lines <= 0 || columns <= 0)
    {
        IO_printf("\nERRO: tamanho invalido\n");
    }
    else
    {
        matrix = new_int_Matrix (lines, columns);

        if (matrix->data == NULL)
        {
            matrix->lines = 0;
            matrix->columns = 0;
            matrix->ix = 0;
            matrix->iy = 0;
        }
        else
        {
            matrix->ix = 0;

            while (!feof(file) && matrix->ix < matrix->lines)
            {
                matrix->iy = 0;

                while (!feof(file) && matrix->iy < matrix->columns)
                {
                    fscanf(file, "%d", &(matrix->data [matrix->ix][matrix->iy]));
                    matrix->iy++;
                }

                matrix->ix++;
            }

            matrix->ix = 0;
            matrix->iy = 0;
        }
    }

    return (matrix);
}

ref_int_Matrix transposeIntMatrix (ref_int_Matrix src)
{
    ref_int_Matrix dest = NULL;

    if (src == NULL || src->data == NULL)
    {
        IO_printf("\nERRO: faltam dados\n");
    }
    else
    {
        if (src->lines <= 0 || src->columns <= 0)
        {
            IO_printf("\nERRO: tamanho invalido\n");
        }
        else
        {
            dest = new_int_Matrix(src->columns, src->lines);

            if (dest == NULL || dest->data == NULL)
            {
                IO_printf("\nERRO: falta espaco\n");
            }
            else
            {
                for (dest->ix = 0; dest->ix < dest->lines; dest->ix++)
                {
                    for (dest->iy = 0; dest->iy < dest->columns; dest->iy++)
                    {
                        dest->data[dest->iy][dest->ix] =
                        src->data[dest->ix][dest->iy];
                    }
                }
            }
        }
    }
    
    return (dest);
}

void printIntMatrix(ref_int_Matrix matrix)
{
    for (matrix->ix = 0; matrix->ix < matrix->lines; matrix->ix++)
    {
        for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy++)
        {
            IO_printf("%3d\t", matrix->data[matrix->ix][matrix->iy]);
        }

        IO_printf("\n");
    }
}

bool isAllZero_matrix(ref_int_Matrix matrix)
{
    bool result = true;
    matrix->ix = 0;

    while (matrix->ix < matrix->lines && result)
    {
        matrix->iy = 0;
        while (matrix->iy < matrix->columns && result)
        {
            result = result && (matrix->data[matrix->ix][matrix->iy] == 0);
            matrix->iy++;
        }
        matrix->ix++;
    }

    return (result);
}

bool isEqual_matrix(ref_int_Matrix matrix1, ref_int_Matrix matrix2)
{
    bool result = true;

    if ((matrix1->lines != matrix2->lines) ||
        (matrix1->columns != matrix2->columns))
    {
        return (false);
    }
    else
    {
        matrix1->ix = 0;
        
        while (matrix1->ix < matrix1->lines && result)
        {
            matrix1->iy = 0;
            while (matrix1->iy < matrix1->columns && result)
            {
                result = result && (matrix1->data[matrix1->ix][matrix1->iy] ==
                                    matrix2->data[matrix1->ix][matrix1->iy]);
                
                matrix1->iy++;
            }
            matrix1->ix++;
        }
        matrix1->ix = 0;
    }

    return (result);
}

ref_int_Matrix addIntMatrix(ref_int_Matrix matrix1, ref_int_Matrix matrix2, int k)
{
    ref_int_Matrix matrix3 = NULL;

    if ((matrix1->lines != matrix2->lines) ||
        (matrix1->columns != matrix2->columns))
    {
        return (matrix3);
    }
    else
    {
        matrix3 = new_int_Matrix(matrix1->lines, matrix1->columns);

        for (matrix3->ix = 0; matrix3->ix < matrix3->lines; matrix3->ix++)
        {
            for (matrix3->iy = 0; matrix3->iy < matrix3->columns; matrix3->iy++)
            {
                matrix3->data[matrix3->ix][matrix3->iy] =
                    matrix1->data[matrix3->ix][matrix3->iy] +
                    matrix2->data[matrix3->ix][matrix3->iy] * k;
            }
        }

        return (matrix3);
    }
}

ref_int_Matrix multIntMatrix(ref_int_Matrix matrix1, ref_int_Matrix matrix2)
{
    ref_int_Matrix matrix3 = NULL;
    int sum = 0;

    if ((matrix1->lines == matrix2->lines) &&
        (matrix1->columns == matrix2->columns))
    {
        matrix3 = new_int_Matrix(matrix1->lines, matrix1->columns);

        for (int i = 0; i < matrix3->lines; i++)
        {
            for (int j = 0; j < matrix3->columns; j++)
            {
                sum = 0;
                for (int h = 0; h < matrix1->columns; h++)
                {
                    sum += (matrix1->data[i][h] *
                           matrix2->data[h][j]);
                }
                matrix3->data[i][j] = sum;
            }
        }
    }

    return (matrix3);
}
