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

    void print()
    {
        cout << endl;

        for (int i = 0; i < length; i++)
        {
            cout << setw(3) << i << ":" << setw(9) << data[i] << endl;
        }
    }
};

#endif