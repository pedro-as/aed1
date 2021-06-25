#include <string.h>
#include <math.h>

int totalFactors(int n)
{
    int total = 0;

    for (int i = n; i > 0; i--)
    {
        if (n % i == 0)
        {
            total++;
        }
    }
    return total;
}

int sumFactors(int n)
{
    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int getGcd_rec(int a, int b)
{
    int mod = a % b;

    if (mod == 0)
    {
        return b;
    }

    return getGcd_rec(b, mod);
}

int getGcd(int a, int b)
{
    int c = 0;
    while (a % b != 0)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return b;
}

int getLcm(int a, int b)
{
    return (a * b) / getGcd(a, b);
}

void getPrefix(char *string, int n, char *dest)
{
    
    if (n > strlen(string))
    {
        n = strlen(string);
    }
    
    for (int i = 0; i < n; i++)
    {
        strncat(dest, &string[i], 1);
    }
}

void getSuffix(char *string, int n, char *dest)
{
    int len = strlen(string);

    if (n > len)
    {
        strncat(dest, "\0", 1);
    }

    for (int i = n; i < len; i++)
    {
        strncat(dest, &string[i], 1);
    }
}

char getLastchar(char *string)
{
    int i = strlen(string) - 1;

    return string[i];
}

void getButlast(char *string, char *dest)
{
    int n = strlen(string) - 1;
    
    for (int i = 0; i < n; i++)
    {
        strncat(dest, &string[i], 1);
    }
}

int toDec(int s, int array[])
{
    int dec = 0;
    int e = s - 1;

    for (int i = 0; i < s; i++)
    {
        dec += array[i] * (int) pow(2, e);
        e--;
    }

    return dec;
}

void invertArray(int s, int array1[], int array2[])
{
    int i = s - 1;
    int x = 0;

    for (int j = 0; j < s; j++)
    {
        x = array1[i];
        array2[j] = x;
        i--;
    }
}
