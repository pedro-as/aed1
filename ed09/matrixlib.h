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

void fprintIntMatrix(chars fileName, int rows, int columns, int matrix[][columns])
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
        IO_println("\nERROR: invalid size");
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
        IO_println("ERROR: invalid size");
        n = 0;
    }

    // close file
    fclose(file);

    // return number
    return(n);
}

void freadIntMatrix(chars fileName, int rows, int columns, int matrix[][columns])
{
    // define local variables
    int r = 0;
    int c = 0;
    int value = 0;
    FILE *file = fopen(fileName, "rt");

    // read number of data
    IO_fscanf(file, "%d", &r);
    IO_fscanf(file, "%d", &c);

    if (rows <= 0 || rows > r ||
        columns <= 0 || columns > c)
    {
        IO_println("ERROR: invalid size");
    }
    else
    {
        // read values and store in array
        r = 0;
        while (! feof(file) && r < rows)
        {
            c = 0;
            while (! feof(file) && c < columns)
            {
                IO_fscanf(file, "%d", &value);
                matrix[r][c] = value;
                c++;
            }
            r++;
        }
    }
}
