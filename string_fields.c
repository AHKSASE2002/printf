#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int precision = 0;
	
	/* If precision is specified in the format string */
	if (*p == '.')
	{
		p++;
		
		/* Check for the precision value */
		if (*p == '*')
		{
			/* Precision value is passed as an argument */
			precision = va_arg(ap, int);
			
			if (precision < 0)
			{
				/* If precision is negative, ignore it */
				precision = 0;
			}
			
			p++;
		}
		else
		{
			/* Parse the precision value from the format string */
			while (_isdigit(*p))
			{
				precision = precision * 10 + (*p - '0');
				p++;
			}
		}
	}
	
	/* Update the precision in the parameters struct */
	params->precision = precision;
	
	return p;
}
