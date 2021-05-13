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

bool isRelational(char symbol)
{
    return (symbol == '>' || symbol == '<' || symbol == '=');
}
