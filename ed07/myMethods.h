#include <math.h>

int countLines(chars fileName)
{
    FILE* file = fopen(fileName, "rt");
    int count = 0;
    double x = 0.0;

    fscanf(file, "%lf", &x);

    while(! feof(file))
    {
        fscanf(file, "%lf", &x);
        count++;
    }
    fclose(file);
    return (count);
}

void writeEvenM3(chars fileName, int n)
{
    FILE *file = fopen(fileName, "wt");
    int x = 0;

    for (int i = 1; i <= n; i++)
    {
        x = 3 * 2 * i;
        fprintf(file, "%d\n", x);
    }

    fclose(file);
}

void writeOddM3(chars fileName, int n)
{
    FILE *file = fopen(fileName, "wt");
    int x = 0;

    while (n > 0)
    {
        x = 3 * (2 * n - 1);
        fprintf(file, "%d\n", x);
        n--;
    }

    fclose(file);
}

void writeExp(chars fileName, int b, int n)
{
    FILE *file = fopen(fileName, "wt");
    double y = 0.0;

    for (int x = 0; x < n; x++)
    {
        y = pow(5.0, (double) x);
        fprintf(file, "%.0lf\n", y);
    }

    fclose(file);
}

void writeNegExp(chars fileName, int b, int n)
{
    FILE *file = fopen(fileName, "wt");
    double y = 0.0;
    n = n * (-1);

    while (n < 0)
    {
        n++;
        y = pow((double) b, (double) n);
        fprintf(file, "%.12lf\n", y);
    }

    fclose(file);
}

void writeNegEvenExp(chars fileName, double b, int n)
{
    FILE *file = fopen(fileName, "wt");
    double y = 0.0;
    n = n * (-1);

    for (int i = 0; i > -2; i--)
    {
        y = pow((double) b, (double) i);
        fprintf(file, "%.12lf\n", y);
    }

    for (int i = -2; i > n; i--)
    {
        y = pow((double) b, (double) i);
        fprintf(file, "%.12lf\n", y);        
    }

    fclose(file);
}

double sumValues(chars fileName, int n)
{
    FILE *file = fopen(fileName, "rt");
    int read = 0;
    double x = 0.0;
    double sum = 0.0;

    while (! feof(file) && read < n)
    {
        fscanf(file, "%lf", &x);
        sum += x;
        read++;
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

bool isUpperCase(char x)
{
    return ('A' <= x && x <= 'Z');
}

int countUpper(chars string)
{
    // definir dados
    int count = 0;
    int length = strlen(string);
    char character = '\0';

    //testar a condicao
    for (int i = 0; i < length; i++)
    {
        character = string[i];
        if (isUpperCase(character))
        {
            count++;
        }
    }
    return (count);
}

void writeUpper(chars fileIn, chars fileOut)
{
    FILE *input = fopen(fileIn, "rt");
    FILE *output = fopen(fileOut, "wt");
    chars string = IO_new_chars(STR_SIZE);
    int count = 0;

    strcpy(string, IO_fread(input));
    IO_fprintf(output, "Cadeia => N. maiusculas\n");
    IO_fprintf(output, "-------------------------------\n");

    while (! feof(input))
    {
        count = countUpper(string);
        IO_fprintf(output, "\"%s\" => %d\n", string, count);
        strcpy(string, IO_fread(input));
    }
    fclose(output);
    fclose(input);    
}

bool isDigit(char x)
{
    return ('0' <= x && x <= '9');
}

int countDigits_LE5(chars string)
{
    int count = 0;
    int length = strlen(string);
    int digit = 0;
    char character = '\0';

    for (int i = 0; i < length; i++)
    {
        character = string[i];
        if (isDigit(character))
        {
            digit = (int) character - 48;
            
            if (digit <= 5)
            {
                count++;
            }
        }
    }
    return (count);
}

void writeDigits_LE5(chars fileIn, chars fileOut)
{
    FILE *input = fopen(fileIn, "rt");
    FILE *output = fopen(fileOut, "wt");
    chars string = IO_new_chars(STR_SIZE);
    int count = 0;

    strcpy(string, IO_fread(input));
    IO_fprintf(output, "Cadeia => N. digitos <= 5\n");
    IO_fprintf(output, "-------------------------------\n");

    while (! feof(input))
    {
        count = countDigits_LE5(string);
        IO_fprintf(output, "\"%s\" => %d\n", string, count);
        strcpy(string, IO_fread(input));
    }
    fclose(output);
    fclose(input);    
}
