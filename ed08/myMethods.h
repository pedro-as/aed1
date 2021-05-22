bool isPositive(int x)
{
    return (x > 0);
}

bool isEven(int x)
{
    return (x % 2 == 0);
}

void printIntArray (int n, int array[])
{
    // definir dado local
    int x = 0;
    
    // mostrar valores no arranjo
    for (x = 0; x < n; x++)
    {
        // mostrar valor
        IO_printf ("%d: %d\n", x, array [x]);
    }
}

void readIntArray (int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    chars text = IO_new_chars (STR_SIZE);

    // ler e guardar valores em arranjo
    for (x = 0; x < n; x++)
    {
        // ler valor
        strcpy (text, STR_EMPTY);
        y = IO_readint(IO_concat (
        IO_concat(text, IO_toString_d(x)),": "));
        
        // guardar valor
        array[x] = y;
    }
}

void fprintIntArray(chars fileName, int n, int array[])
{
    // definir dados locais
    FILE *file = fopen(fileName, "wt");
    int x = 0;

    // gravar quantidade de dados
    IO_fprintf(file, "%d\n", n);

    // gravar valores no arranjo
    for (x = 0; x < n; x++)
    {
        // gravar valor
        IO_fprintf(file, "%d\n", array[x]);
    }

    fclose(file);
}

void freadIntArray (chars fileName, int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    FILE *file = fopen(fileName, "rt");

    if (n <= 0)
    {
        IO_printf("\nERRO: arranjo de tamanho invalido");
    }
    else
    {
        while (! feof(file) && x < n)
        {
            IO_fscanf(file, "%d", &y);
            array[x] = y;
            x++;
        }
    }
}

int freadArraySize(chars fileName)
{
    int x = 0;
    int n = 0;
    FILE *file = fopen(fileName, "rt");

    IO_fscanf(file, "%d", &x);

    if (x <= 0)
    {
        n = 0;
    }
    else
    {
        while (! feof(file))
        {
            fscanf(file, "%d", &x);
            n++;
        }
    }

    return(n);
}

bool isAllEvenPositive(int n, int array[])
{
    bool result = true;
    int x = 0;
    int value = 0;

    while (x < n && result)
    {
        value = array[x];
        result = result && (isPositive(value) && isEven(value));
        x++;
    }

    return (result);
}

void fprintIntArray_evenPositive(chars fileName, int n, int array[])
{
    // definir dados locais
    FILE *file = fopen(fileName, "wt");
    int x = 0;
    int value = 0;

    // gravar quantidade de dados
    IO_fprintf(file, "%d\n", n);

    // gravar valores no arranjo
    for (x = 0; x < n; x++)
    {
        value = array[x];

        // gravar valor se obedecida as condicoes
        if (isEven(value) && isPositive(value))
        {
            IO_fprintf(file, "%d\n", value);
        }
    }

    fclose(file);
}

int getRandomInt(int start, int stop)
{
    return (start + rand() % (stop - start + 1));
}

int minIntArray(int n, int array[])
{
    int min = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return (min);
}

int maxIntArray(int n, int array[])
{
    int max = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return (max);
}

int sumIntArray(int n, int array[])
{
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum = sum + array[i];
    }

    return(sum);
}

double meanIntArray(int n, int array[])
{
    // evitar divisao por 0
    if (n > 0)
    {
        int sum = sumIntArray(n, array);
        return ((double) sum / (double) n);
    }
    else
    {
        // retornar 0 se tamanho do arranjo for invalido
        return (0.0);
    }
}

bool isOrderedIntArray_asc(int n, int array[])
{
    bool result = true;
    int x = 1;

    while (x < n && result)
    {
        result = result && (array[x] > array[x - 1]);
        x++;
    }

    return (result);
}

bool searchIntArray_pos(int value, int pos, int n, int array[])
{
    bool result = false;
    int x = pos;

    while (x < n && ! result)
    {
        result = (value == array[x]);
        x++;
    }

    return (result);
}

int indexIntArray_pos(int value, int pos, int n, int array[])
{
    bool result = false;
    int x = pos;

    while (x < n && ! result)
    {
        result = (value == array[x]);
        x++;
    }

    if (result)
    {
        return (x - 1);
    }
    else
    {
        return(-1);
    }
}

int searchIntArray_quant(int value, int pos, int n, int array[])
{
    int quant = 0;

    for (int i = pos; i < n; i++)
    {
        if (array[i] == value)
        {
            quant++;
        }
    }

    return (quant);
}
