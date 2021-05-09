#include <math.h>

void showOdd(int n)
{
    if (n > 0)
    {
        showOdd(n - 1);
        IO_printf("\n%d", n * 2 + 3);
    }
}

void showMultiples_5(int n)
{
    if (n > 0)
    {
        IO_printf("\n%d", n * 5);
        showMultiples_5(n - 1);
    }
}

void showSequence_a(int n)
{
    if (n > 1)
    {
        showSequence_a(n - 1);
        IO_printf("\n%d", 3 * (n - 1));
    }
    else
    {
        IO_printf("\n%d", 1);
    }
}

void showSequence_b(int n)
{
    if (n > 0)
    {
        IO_printf("\n1/%d", (int) pow(5.0, (double) n));
        showSequence_b(n - 1);
    }
    else
    {
        IO_printf("\n1");
    }
}

void showSymbols(chars string, int length)
{
    if (length > 0)
    {
        showSymbols(string, length - 1);
        IO_printf("\n%c", string[length - 1]);
    }
}

int sumOdd(int n)
{
    int sum = 0;
    if (n > 0)
    {
        sum = (n * 2 + 3) + sumOdd(n - 1);
    }
    return (sum);
}

double sumOddInv(int n)
{
    double sum = 0.0;
    if (n > 0)
    {
        sum = (1.0 / ((double) n * 2.0 + 3.0)) + sumOddInv(n - 1);
    }
    return (sum);
}

int fibonacci(int n)
{
    int x = 0;
    if (n == 1 || n == 2)
    {
        x = 1;
    }
    else
    {
        if (n > 1)
        {
            x = fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    return (x);
}

int countOddDigits(chars string, int n)
{
    int count = 0;
    char character = '\0';
    int intChar = 0;

    if (0 <= n && n < strlen(string))
    {
        character = string[n];
        intChar = (int) character - 48;
        if (('0' <= character && character <= '9') && (intChar % 2 != 0))
        {
            count = 1;
        }
        count = count + countOddDigits(string, n + 1);
    }
    return (count);
}

int countUppercase(chars string, int n)
{
    int count = 0;
    char character = '\0';

    if (0 <= n && n < strlen(string))
    {
        character = string[n];
        if ('A' <= character && character <= 'Z')
        {
            count = 1;
        }
        count = count + countUppercase(string, n + 1);
    }
    return (count);
}

double oddSummation(double x, double n)
{
    double sum = 0.0;

    if (n > 1.0)
    {
        sum = pow(x, n * 2.0 - 3.0) + oddSummation(x, n - 1.0);
    }
    else
    {
        sum = sum + 1.0;
    }
    return (sum);
}
