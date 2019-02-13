#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			i;
	t_conv		conv;

	i = -1;
	va_start(conv.ap, format);
	ft_init_conv(&conv);
	ft_init_fp(&conv);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			//ft_putendl("format = %");
			i += ft_check_flags((char *)&format[i + 1], &conv);
			//conv.length = 0;
		}
		else
		{
			ft_putchar(format[i]);
			conv.length++;
		}
	}
	va_end(conv.ap);
	return (conv.length);
}
