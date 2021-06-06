/**
 * Array Library - v0.2 - 05/06/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Multipurpose library for manipulation of one dimensional arrays (vectors)
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

typedef int_Array* ref_int_Array;

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
