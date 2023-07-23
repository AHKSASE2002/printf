#include "main.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list ap, params_t *params)
{
    char pad_char = ' ';
    unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

    if (params->minus_flag)
        sum += _putchar(ch);
    while (pad++ < params->width)
        sum += _putchar(pad_char);
    if (!params->minus_flag)
        sum += _putchar(ch);
    return (sum);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list ap, params_t *params)
{
    long l;

    if (params->l_modifier)
        l = va_arg(ap, long);
    else if (params->h_modifier)
        l = (short int)va_arg(ap, int);
    else
        l = (int)va_arg(ap, int);
    
    char *str = convert(l, 10, 0, params);

    // Apply precision
    int i = _strlen(str);
    if (params->precision != UINT_MAX)
    {
        while (i++ < params->precision)
            sum += _putchar('0');
    }

    return (print_number(str, params));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list ap, params_t *params)
{
    char *str = va_arg(ap, char *);
    char pad_char = ' ';
    unsigned int pad = 0, sum = 0, i = 0, j;

    // Rest of the code...

    // Apply precision
    if (params->precision < pad)
        j = pad = params->precision;
    
    // Rest of the code...
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, params_t *params)
{
    (void)ap;
    (void)params;
    return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list ap, params_t *params)
{
    char *str = va_arg(ap, char *);
    char *hex;
    int sum = 0;

    if ((int)(!str))
        return (_puts(NULL_STRING));
    for (; *str; str++)
    {
        if ((*str > 0 && *str < 32) || *str >= 127)
        {
            sum += _putchar('\\');
            sum += _putchar('x');
            hex = convert(*str, 16, 0, params);
            if (!hex[1])
                sum += _putchar('0');
            sum += _puts(hex);
        }
        else
        {
            sum += _putchar(*str);
        }
    }
    return (sum);
}

/**
 * print_rev - prints string in reverse
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
    int len, sum = 0;
    char *str = va_arg(ap, char *);
    (void)params;

    if (str)
    {
        for (len = 0; *str; str++)
            len++;
        str--;
        for (; len > 0; len--, str--)
            sum += _putchar(*str);
    }
    return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
    int i, index;
    int count = 0;
    char arr[] =
        "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
    char *a = va_arg(ap, char *);
    (void)params;

    i = 0;
    index = 0;
    while (a[i])
    {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
        {
            index = a[i] - 65;
            count += _putchar(arr[index]);
        }
        else
            count += _putchar(a[i]);
        i++;
    }
    return (count);
}

