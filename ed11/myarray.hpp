#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_

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
class Array
{
  private:
    int length;
    T *data;

  public:
    Array(int n)
    {
        length = 0;
        data = NULL;

        if (n > 0)
        {
            length = n;
            data = new T[length];
        }
    }

    Array(const Array &source, int k)
    {
        if (source.length == 0)
        {
            cout << "\nERROR: Missing data\n" << endl;
        }
        else
        {
            length = source.length;
            data = new T[length];

            for (int i = 0; i < length; i++)
            {
                data[i] = source.data[i] * k;
            }
        }
    }

    void free()
    {
        if (data != NULL)
        {
            delete(data);
            data = NULL;
        }
    }

    void set(int position, T value)
    {
        if (0 <= position && position < length)
        {
            data[position] = value;
        }
    }

    T get(int position)
    {
        T value = 0;

        if (0 <= position && position < length)
        {
            value = data[position];
        }

        return (value);
    }

    int index(int value)
    {
        int index = -1;
        int n = 0;
        bool found = false;

        while (n < length && !found)
        {
            found = data[n] == value;
        }

        if (found)
        {
            index = n;
        }

        return (index);
    }

    void print()
    {
        cout << endl;

        for (int i = 0; i < length; i++)
        {
            cout << setw(3) << i << ":" << setw(9) << data[i] << endl;
        }
    }

    void read()
    {
        cout << endl;

        for (int i = 0; i < length; i++)
        {
            cout << setw(3) << i << ":";
            cin >> data[i];
        }
        cout << endl;
    }

    void fprint(string fileName)
    {
        ofstream afile;
        afile.open(fileName);
        afile << length << endl;

        for (int i = 0; i < length; i++)
        {
            afile << data[i] << endl;
        }

        afile.close();
    }

    void fread(string fileName)
    {
        ifstream afile;
        int n = 0;
        afile.open(fileName);
        afile >> n;

        if (n <= 0)
        {
            cout << "\nERROR: invalid length\n" << endl;
        }
        else
        {
            length = n;
            data = new T[n];

            for (int i = 0; i < length; i++)
            {
                afile >> data[i];
            }
        }
        afile.close();
    }

    int randInt(int start, int stop)
    {
        return (start + rand() % (stop - start + 1));
    }

    int getMax()
    {
        int value = 0;
        int max = this->get(0);
        
        for (int i = 1; i < length; i++)
        {
            value = this->get(i);
            if (value > max)
            {
                max = value;
            }
        }

        return (max);
    }

    int getMin()
    {
        int value = 0;
        int min = this->get(0);
        
        for (int i = 1; i < length; i++)
        {
            value = this->get(i);
            if (value < min)
            {
                min = value;
            }
        }

        return (min);
    }

    const int getLength()
    {
        return (length);
    }

    int sum()
    {
        int sum = 0;
        
        for (int i = 0; i < length; i++)
        {
            sum += this->get(i);
        }

        return (sum);
    }

    double avg()
    {
         return ((double) this->sum() / (double) length);
    }

    bool allZero()
    {
        bool result = true;
        int n = 0;
        
        while (n < length && result)
        {
            result = result && (data[n] == 0);
            n++;
        }

        return (result);
    }

    bool isSorted_desc()
    {
        bool result = true;
        int n = 1;
        
        while (n < length && result)
        {
            result = result && (data[n] < data [n - 1]);
            n++;
        }

        return (result);
    }

    bool findInRange(int value, int start, int stop)
    {
        bool result = false;
        int n = start;

        while (n < stop && !result)
        {
            result = (data[n] == value);
            n++;
        }

        return (result);
    }

    /* Metodo de ordenamento decrescente utilizando o algoritmo quicksort */
    void quickSort_desc(int low, int high)
    {
        int i = low;
        int j = high;
        int pivot = data[(i + j) / 2];
        int temp;

        while (i <= j)
        {
            while (data[i] > pivot)
            {
                i++;
            }

            while (data[j] < pivot)
            {
                j--;
            }

            if (i <= j)
            {
                temp = data[i];
                this->set(i, data[j]);
                this->set(j, temp);
                i++;
                j--;
            }
        }

        if (j > low)
        {
            quickSort_desc(low, j);
        }

        if (i < high)
        {
            quickSort_desc(i, high);
        }
    }

    bool operator!=(const Array <T> other)
    {
        bool result = false;
        int i = 0;

        if (other.length == 0 || length != other.length)
        {
            cout << "\nERROR: Missing data\n" << endl;
        }
        else
        {
            while (i < this->length && !result)
            {
                result = (data[i] != other.data[i]);
                i++;
            }
        }

        return (result);
    }

    /* Operacoes entre arranjos */

    Array& operator=(const Array <T> other)
    {
        if (other.length == 0)
        {
            cout << "\nERROR: Missing data\n" << endl;
        }
        else
        {
            this->length = other.length;
            this->data = new T[other.length];

            for (int i = 0; i < this->length; i++)
            {
                data[i] = other.data[i];
            }
        }

        return (*this);
    }    

    Array& operator-(const Array <T> other)
    {
        static Array <T> result(other);

        if (other.length == 0)
        {
            cout << "\nERROR: Missing data\n" << endl;
        }
        else
        {
            for (int i = 0; i < this->length; i++)
            {
                result.data[i] -= this->data[i];
            }
        }

        return (result);
    }
};

#endif