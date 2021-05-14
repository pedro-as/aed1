#include <math.h>

bool isPositive(int n)
{
    return (n > 0);
}

bool isEven(int n)
{
    return (n % 2 == 0);
}

bool isLogical(char symbol)
{
    return (symbol == '&' || symbol == '|' || symbol == '!');
}

bool isArithmetic(char symbol)
{
    return ((symbol == '+') || (symbol == '-') || (symbol == '*') ||
            (symbol == '/') || (symbol == '%'));
}

bool isDelimiter(char symbol)
{
    return ((symbol == ' ') || (symbol == '.') || (symbol == ',') ||
            (symbol == ';') || (symbol == ':') || (symbol == '_'));
}

bool isRelational(char symbol)
{
    return (symbol == '>' || symbol == '<' || symbol == '=');
}

bool isUpper(char symbol)
{
    return ('A' <= symbol && symbol <= 'Z');
}

bool isLower(char symbol)
{
    return ('a' <= symbol && symbol <= 'z');
}

bool isDigit(char symbol)
{
    return ('0' <= symbol && symbol <= '9');
}

double smallest(double x, double y, double z)
{
    if (x < y && x < z)
    {
        return (x);
    }
    else if (y < x && y < z)
    {
        return (y);
    }
    else if (z < x && z < y)
    {
        return (z);
    }
    else
    {
        return (0);
    }
}

bool belongsTo(int x, int a, int b)
{
    return (a < x && x < b);
}

bool belongsTo_f(double x, double a, double b)
{
    return (a < x && x < b);
}

double invCubeSum(int x, int a, int b)
{
    if (x == 0)
    {
        return (0.0);
    }
    else if (belongsTo(x, a, b))
    {
        return (1. / (pow((double) x, 3.0)));
    }
    else
    {
        return (0.0);
    }
}

bool isIncreasing(double x, double y, double z)
{
    return (x < y && y < z);
}

bool isDecreasing(double x, double y, double z)
{
    return (x > y && y > z);
}

bool isIncreasing_c(char x, char y, char z)
{
    return (((int) x < (int) y) && ((int) y < (int) z));
}

bool isDecreasing_c(char x, char y, char z)
{
    return (((int) x > (int) y) && ((int) y > (int) z));
}
