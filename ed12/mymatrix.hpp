#ifndef _MYMATRIX_HPP_
#define _MYMATRIX_HPP_

// dependencias
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

template <typename T>
class Matrix
{
  private:
    T optional;
    int rows;
    int columns;
    T** data;

  public:
    Matrix()
    {
        this->rows = 0;
        this->columns = 0;
        data = nullptr;
    }

    Matrix(int rows, int columns, T initial)
    {
        bool OK = true;
        this->optional = initial;
        this->rows = rows;
        this->columns = columns;
        data = new T* [rows];

        if (data != nullptr)
        {
            for (int x = 0; x < rows; x++)
            {
                data[x] = new T[columns];
                OK = OK && (data[x] != nullptr);
            }

            if (!OK)
            {
                data = nullptr;
            }
        }
    }

    ~Matrix()
    {
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x++)
            {
                delete(data[x]);
            }
            delete(data);
            data = nullptr;
        }
    }

    void set(int row, int column, T value)
    {
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            data[row][column] = value;
        }
    }

    T get(int row, int column)
    {
        T value = optional;
        
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            value = data[row][column];
        }
        return(value);
    }

    void print()
    {
        cout << endl;
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    void read()
    {
        cout << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << setw(2) << i << ","
                     << setw(2) << j << ": ";
                cin >> data[i][j];
            }
        }
        cout << endl;
    }

    void fprint(string fileName)
    {
        ofstream afile;

        afile.open(fileName);
        afile << rows << endl;
        afile << columns << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                afile << data[i][j] << endl;
            }
        }
        afile.close();
    }

    void fprint_alt(string fileName)
    {
        ofstream afile;

        afile.open(fileName);
        afile << rows * columns << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                afile << data[i][j] << endl;
            }
        }
        afile.close();
    }

    void fread(string fileName)
    {
        ifstream afile;
        int m = 0;
        int n = 0;

        afile.open(fileName);
        afile >> m;
        afile >> n;

        if (m <= 0 || n <= 0)
        {
            cout << "\nERROR: Invalid dimensions for matrix.\n" << endl;
        }
        else
        {
            rows = m;
            columns = n;
            data = new T* [rows];

            for (int x = 0; x < rows; x++)
            {
                data[x] = new T [columns];
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    afile >> data[i][j];
                }
            }
        }
        afile.close();
    }

    const int getRows()
    {
        return (rows);
    }

    const int getColumns()
    {
        return (columns);
    }

    Matrix& operator= (const Matrix& other)
    {
        if (other.rows == 0 || other. columns == 0)
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            this->rows = other.rows;
            this->columns = other.columns;
            this->data = new T* [rows];

            for (int x = 0; x < rows; x++)
            {
                this->data[x] = new T [columns];
            }

            for (int i = 0; i < this->rows; i++)
            {
                for (int j = 0; j < this->columns; j++)
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }

        return (*this);
    }

    int randInt(int start, int stop)
    {
        return (start + rand() % (stop - start + 1));
    }

    void genRandom(int start, int stop)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                data[i][j] = randInt(start, stop);
            }
        }
    }

    void scale(int k)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                data[i][j] = data[i][j] * k;
            }
        }
    }

    bool isIdentity()
    {
        bool result = false;
        int i = 0;
        int j = 0;

        if (rows > 0 && columns > 0)
        {
            result = true;

            while (i < rows && result)
            {
                j = 0;
                while (j < columns && result)
                {
                    if (i == j)
                        result = result && (data[i][j] == 1);
                    else
                        result = result && (data[i][j] == 0);
                    j++;
                }
                i++;
            }
        }
        return (result);
    }

    bool operator== (const Matrix& other)
    {
        bool result = true;
        int i = 0;
        int j = 0;

        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n" << endl;
            result = false;
        }
        else
        {
            while (i < rows && result)
            {
                j = 0;
                while (j < columns && result)
                {
                    result = (data[i][j] == other.data[i][j]);
                    j++;
                }
                i++;
            }
        }
        return (result);
    }

    Matrix& operator+ (const Matrix& other)
    {
        static Matrix <T> result(1, 1, 0);
        result = other;

        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n" << endl;
        }
        else
        {
            result.rows = rows;
            result.columns = other.columns;
            result.data = new T*[result.rows];
            for (int x = 0; x < result.rows; x++)
            {
                result.data[x] = new T[result.columns];
            }

            for (int i = 0; i < result.rows; i++)
            {
                for (int j = 0; j < result.columns; j++)
                {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
        }
        return (result);
    }

    void addRows(int row_a, int row_b, int k)
    {
        int x = 0;

        for (int c = 0; c < columns; c++)
        {
            x = (data[row_a][c] + data[row_b][c]) * k;
            data[row_a][c] = x;
        }
    }

    void subRows(int row_a, int row_b, int k)
    {
        int x = 0;

        for (int c = 0; c < columns; c++)
        {
            x = (data[row_a][c] - data[row_b][c]) * k;
            data[row_a][c] = x;
        }
    }

    int searchValue(int value, int dim=0)
    {
        bool found = false;
        int row = 0;
        int col = 0;

        if (dim == 0 || dim == 1)
        {
            while (row < rows && !found)
            {
                col = 0;
                while (col < columns && !found)
                {
                    found = (data[row][col] == value);
                    col++;
                }
                row++;
            }

            if (found && dim == 0)
            {
                return (row);
            }
            else if (found && dim == 1)
            {
                return (col);
            }
            else
            {
                cout << "Value not found ";
                return (-1);
            }
        }
        else
        {
            cout << "\nERROR: 'dim' parameter must be either 0 or 1\n";
            return (-2);
        }
    }

    void transpose(const Matrix& other)
    {
        for (int i = 0; i < other.rows; i++)
        {
            for (int j = 0; j < other.columns; j++)
            {
                data[j][i] = other.data[i][j];
            }
        }
    }

    bool isSequential()
    {
        bool result = true;
        int i = 0;
        int j = 0;
        int eq = 0;

        while (i < rows && result)
        {
            j = 0;
            while(j < columns && result)
            {
                eq = rows * i + j + 1;
                result = result && (data[i][j] == eq);
                j++;
            }
            i++;
        }
        return(result);
    }

    void genSequential_transp()
    {
        if (rows != columns)
        {
            cout << "\nERROR: Invalid dimensions for matrix.\n" << endl;
        }
        else
        {
            int value = 1;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    data[j][i] = value;
                    value++;
                }
            }
        }
    }
};

#endif