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
			//debug
			//ft_putendl("if % du printf");
			i += ft_check_flags((char *)&format[i + 1], &conv);
		}
		else
		{
			conv.ret += write(1, &format[i], 1);
			//debug
			//ft_putendl("else (!%) du printf");
		}
	}
	va_end(conv.ap);
	return (conv.ret);
}
