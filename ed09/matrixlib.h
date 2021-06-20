/**
 * Matrix Library - v0.1 - 29/05/2021
 * Author: Pedro H. Amorim Sa - 742626
 * Multipurpose library for manipulation of two dimensional arrays (matrices)
 */

// include IO_lib if not included in main program
// #include "io.h"

void printIntMatrix(int rows, int columns, int matrix[][columns])
{
    // iterate over matrix to show values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // print value
            IO_printf("%3d\t", matrix[i][j]);
        }
        IO_printf("\n");
    }
}

void readIntMatrix(int rows, int columns, int matrix[][columns])
{
    // define local variables
    int value = 0;
    chars text = IO_new_chars(STR_SIZE);

    // iterate over matrix to read and store values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // read value
            strcpy(text, STR_EMPTY);
            value = IO_readint(IO_concat(
                            IO_concat(IO_concat(text, IO_toString_d(i)), ","),
                            IO_concat(IO_concat(text, IO_toString_d(j)), ": ")));

            // store value
            matrix[i][j] = value;
        }
    }
}

void fprintIntMatrix(chars fileName, int rows, int columns,
                     int matrix[][columns])
{
    // define local variables
    FILE *file = fopen(fileName, "wt");

    // write matrix dimensions to file
    IO_fprintf(file, "%d\n", rows);
    IO_fprintf(file, "%d\n", columns);

    // iterate over matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // write value to file
            IO_fprintf(file, "%d\n", matrix[i][j]);
        }
    }
    // close file
    fclose(file);
}

int freadMatrixRows(chars fileName)
{
    // define local variables
    int n = 0;
    FILE *file = fopen(fileName, "rt");

    // read number of data
    IO_fscanf(file, "%d", &n);

    if (n <= 0)
    {
        n = 0;
    }

    // close file
    fclose(file);

    // return number
    return(n);
}

int freadMatrixColumns(chars fileName)
{
    // define local variables
    int n = 0;
    FILE *file = fopen(fileName, "rt");

    // read number of data
    IO_fscanf(file, "%d", &n);
    IO_fscanf(file, "%d", &n);

    if (n <= 0)
    {
        IO_println("ERROR: invalid dimensions");
        n = 0;
    }

    // close file
    fclose(file);

    // return number
    return(n);
}

void freadIntMatrix(chars fileName, int rows, int columns,
                    int matrix[][columns])
{
    // define local variables
    int i = 0;
    int j = 0;
    int value = 0;
    FILE *file = fopen(fileName, "rt");

    // read number of data
    IO_fscanf(file, "%d", &i);
    IO_fscanf(file, "%d", &j);

    if (rows <= 0 || rows > i ||
        columns <= 0 || columns > j)
    {
        IO_println("ERROR: invalid dimensions");
    }
    else
    {
        // read values and store in array
        i = 0;
        while (! feof(file) && i < rows)
        {
            j = 0;
            while (! feof(file) && j < columns)
            {
                IO_fscanf(file, "%d", &value);
                matrix[i][j] = value;
                j++;
            }
            i++;
        }
    }
}

void printFloatMatrix(int rows, int columns, double matrix[][columns])
{
    // iterate over matrix to show values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // print value
            IO_printf("%3lf\t", matrix[i][j]);
        }
        IO_printf("\n");
    }
}

void readFloatMatrix(int rows, int columns, double matrix[][columns])
{
    double value = 0;
    chars text = IO_new_chars(STR_SIZE);

    if (rows <= 0 || columns <= 0)
    {
        IO_printf("\nERROR: invalid dimensions");
    }
    else
    {
        // iterate over matrix to read and store values
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                // enforce positive values
                while (value <= 0.0)
                {
                    strcpy(text, STR_EMPTY);
                    value = IO_readdouble(IO_concat(
                                IO_concat(IO_concat(text, IO_toString_d(i)), ","),
                                IO_concat(IO_concat(text, IO_toString_d(j)), ": ")));
                }

                // guardar valor e reinicia-lo
                matrix[i][j] = value;
                value = 0.0;
            }
        }
    }
}

void fprintFloatMatrix(chars fileName, int rows, int columns,
                       double matrix[][columns])
{
    // define local variables
    FILE *file = fopen(fileName, "wt");

    // write matrix dimensions to file
    IO_fprintf(file, "%d\n", rows);
    IO_fprintf(file, "%d\n", columns);

    // iterate over matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // write value to file
            IO_fprintf(file, "%lf\n", matrix[i][j]);
        }
    }
    // close file
    fclose(file);
}

void freadFloatMatrix(chars fileName, int rows, int columns,
                      double matrix[][columns])
{
    // define local variables
    int i = 0;
    int j = 0;
    double value = 0.0;
    FILE *file = fopen(fileName, "rt");

    // read number of data
    IO_fscanf(file, "%d", &i);
    IO_fscanf(file, "%d", &j);

    if (rows <= 0 || rows > i ||
        columns <= 0 || columns > j)
    {
        IO_println("ERROR: invalid dimensions");
    }
    else
    {
        // read values and store in array
        i = 0;
        while (! feof(file) && i < rows)
        {
            j = 0;
            while (! feof(file) && j < columns)
            {
                IO_fscanf(file, "%lf", &value);
                matrix[i][j] = value;
                j++;
            }
            i++;
        }
    }
}

void printMainDiagonal_f(int rows, int columns, double matrix[][columns])
{
    if (rows <= 0 || columns <= 0)
    {
        IO_println("ERROR: invalid dimensions");
    }
    else if (rows != columns)
    {
        IO_println("ERROR: not a square matrix");
    }
    else
    {
        // iterate over matrix to show values
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (i == j)
                {
                    IO_printf("%3.3lf\t", matrix[i][j]);
                    
                }
                else
                {
                    IO_printf("%3s\t", "*****");
                }
            }
            IO_printf("\n");
        }
    }
}

void printAntidiagonal_f(int rows, int columns, double matrix[][columns])
{
    if (rows <= 0 || columns <= 0)
    {
        IO_println("ERROR: invalid dimensions");
    }
    else if (rows != columns)
    {
        IO_println("ERROR: not a square matrix");
    }
    else
    {
        int n = rows - 1;

        // iterate over matrix to show values
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (i + j == n)
                {
                    IO_printf("%3.3lf\t", matrix[i][j]);
                    
                }
                else
                {
                    IO_printf("%3s\t", "*****");
                }
            }
            IO_printf("\n");
        }
    }
}

void printLowerTriangular_f(int rows, int columns, double matrix[][columns])
{
    if (rows <= 0 || columns <= 0)
    {
        IO_println("ERROR: invalid dimensions");
    }
    else if (rows != columns)
    {
        IO_println("ERROR: not a square matrix");
    }
    else
    {
        // iterate over matrix to show values
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (i > j)
                {
                    IO_printf("%3.3lf\t", matrix[i][j]);
                    
                }
                else
                {
                    IO_printf("%3s\t", "*****");
                }
            }
            IO_printf("\n");
        }
    }
}

void printUpperTriangular_f(int rows, int columns, double matrix[][columns])
{
    if (rows <= 0 || columns <= 0)
    {
        IO_println("ERROR: invalid dimensions");
    }
    else if (rows != columns)
    {
        IO_println("ERROR: not a square matrix");
    }
    else
    {
        // iterate over matrix to show values
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (i < j)
                {
                    IO_printf("%3.3lf\t", matrix[i][j]);
                    
                }
                else
                {
                    IO_printf("%3s\t", "*****");
                }
            }
            IO_printf("\n");
        }
    }
}

void printSecLowerTriangular_f(int rows, int columns, double matrix[][columns])
{
    if (rows <= 0 || columns <= 0)
    {
        IO_println("ERROR: invalid dimensions");
    }
    else if (rows != columns)
    {
        IO_println("ERROR: not a square matrix");
    }
    else
    {
        int n = rows - 1;
        // iterate over matrix to show values
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (i + j > n)
                {
                    IO_printf("%3.3lf\t", matrix[i][j]);
                    
                }
                else
                {
                    IO_printf("%3s\t", "*****");
                }
            }
            IO_printf("\n");
        }
    }
}

void printSecUpperTriangular_f(int rows, int columns, double matrix[][columns])
{
    if (rows <= 0 || columns <= 0)
    {
        IO_println("ERROR: invalid dimensions");
    }
    else if (rows != columns)
    {
        IO_println("ERROR: not a square matrix");
    }
    else
    {
        int n = rows - 1;
        // iterate over matrix to show values
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (i + j < n)
                {
                    IO_printf("%3.3lf\t", matrix[i][j]);
                    
                }
                else
                {
                    IO_printf("%3s\t", "*****");
                }
            }
            IO_printf("\n");
        }
    }
}

bool allZeroLowerTriangular_f(int rows, int columns, double matrix[][columns])
{
    bool result = true;
    int i = 0;
    int j = 0;

    if (rows <= 0 || columns <= 0)
    {
        IO_println("ERROR: invalid dimensions");
        result = false;
    }
    else if (rows != columns)
    {
        IO_println("ERROR: not a square matrix");
        result = false;
    }
    else
    {
        // iterate over matrix to check for zeros
        while (i < rows && result)
        {
            j = 0;
            while (j < columns && result)
            {
                if (i > j)
                {
                    result = result && (matrix[i][j] == 0);
                }

                j++;
            }

            i++;
        }
    }

    return (result);
}

bool allZeroUpperTriangular_f(int rows, int columns, double matrix[][columns])
{
    bool result = true;
    int i = 0;
    int j = 0;

    if (rows <= 0 || columns <= 0)
    {
        IO_println("ERROR: invalid dimensions");
        result = false;
    }
    else if (rows != columns)
    {
        IO_println("ERROR: not a square matrix");
        result = false;
    }
    else
    {
        // iterate over matrix to check for zeros
        while (i < rows && result)
        {
            j = 0;
            while (j < columns && result)
            {
                if (i < j)
                {
                    result = result && (matrix[i][j] == 0);
                }

                j++;
            }

            i++;
        }
    }

    return (result);
}

void genDescMatrix(int rows, int columns, int matrix[][columns])
{
    // define local variables
    int value = rows * columns;

    // iterate over matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // store value
            matrix[i][j] = value;

            value--;
        }
    }
}

void genDescMatrix_transp(int rows, int columns, int matrix[][rows])
{
    // define local variables
    int value = rows * columns;

    // iterate over matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // store value
            matrix[j][i] = value;

            value--;
        }
    }
}

void transposeIntMatrix (int rows, int columns,
                         int source[][columns], int dest[][rows])
{
    // iterate over matrices
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // transpose values
            dest[j][i] = source[i][j];
        }
    }
}
