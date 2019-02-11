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

void	ft_handle_conv(t_conv *conv)
{
	int i;

//			ft_putendl("handle");
	i = 0;
	while (conv->conv_type != conv->type[i])
		i++;
	conv->f[i](conv);
}

void	ft_handle_c(t_conv *conv)
{
	
//			ft_putendl("handle c :");
	
	if (conv->width != 0)
		if (!conv->flag.less)
			while (--conv->width)
				ft_putchar(' ');
	ft_putchar(va_arg(conv->ap, int));
	if (conv->width != 0)
		if (conv->flag.less)
			while (--conv->width)
				ft_putchar(' ');
//	ft_putendl("");
//	ft_putendl("");
}

void	ft_handle_s(t_conv *conv)
{
//			ft_putendl("handle s :");
	conv->str_val = ft_strdup(va_arg(conv->ap, char *));
	ft_handle_sp_p(conv);
//	ft_putendl("");
//	ft_putendl("");
}

void	ft_handle_di(t_conv *conv)
{
// 	ft_putendl("test");
	if (conv->size.hh)
		conv->str_val = ft_strdup(ft_llitoa((char)va_arg(conv->ap, long long)));
	else if (conv->size.h)
		conv->str_val = ft_strdup(ft_llitoa((short)va_arg(conv->ap, long long)));
	else if (conv->size.ll)
		conv->str_val = ft_strdup(ft_llitoa(va_arg(conv->ap, long long)));
	else if (conv->size.l)
		conv->str_val = ft_strdup(ft_llitoa((long)va_arg(conv->ap, long long)));
	else
		conv->str_val = ft_strdup(ft_llitoa(va_arg(conv->ap, int)));
	ft_handle_di_p(conv);
}

void	ft_handle_u(t_conv *conv)
{
	if (conv->size.hh)
		conv->str_val = ft_strdup(ft_llitoa((unsigned char)va_arg(conv->ap, unsigned long long)));
	else if (conv->size.h)
		conv->str_val = ft_strdup(ft_llitoa((unsigned short)va_arg(conv->ap, unsigned long long)));
	else if (conv->size.ll)
		conv->str_val = ft_strdup(ft_ullitoa(va_arg(conv->ap, unsigned long long)));
	else if (conv->size.l)
		conv->str_val = ft_strdup(ft_llitoa((unsigned long)va_arg(conv->ap, unsigned long long)));
	else
		conv->str_val = ft_strdup(ft_llitoa(va_arg(conv->ap, unsigned int)));
	ft_handle_di_p(conv);
}

void	ft_handle_o(t_conv *conv)
{
	if (conv->size.hh)
		conv->str_val = ft_strdup(ft_llitoa_base((char)va_arg(conv->ap, long long), 8, 0));
	else if (conv->size.h)
		conv->str_val = ft_strdup(ft_llitoa_base((short)va_arg(conv->ap, long long), 8, 0));
	else if (conv->size.ll)
		conv->str_val = ft_strdup(ft_llitoa_base(va_arg(conv->ap, long long), 8, 0));
	else if (conv->size.l)
		conv->str_val = ft_strdup(ft_llitoa_base((long)va_arg(conv->ap, long long), 8, 0));
	else
		conv->str_val = ft_strdup(ft_llitoa_base(va_arg(conv->ap, int), 8, 0));
	ft_handle_di_p(conv);
}
void	ft_handle_x(t_conv *conv)
{
	if (conv->size.hh)
		conv->str_val = ft_strdup(ft_llitoa_base((char)va_arg(conv->ap, long long), 16, 1));
	else if (conv->size.h)
		conv->str_val = ft_strdup(ft_llitoa_base((short)va_arg(conv->ap, long long), 16, 1));
	else if (conv->size.ll)
		conv->str_val = ft_strdup(ft_llitoa_base(va_arg(conv->ap, long long), 16, 1));
	else if (conv->size.l)
		conv->str_val = ft_strdup(ft_llitoa_base((long)va_arg(conv->ap, long long), 16, 1));
	else
		conv->str_val = ft_strdup(ft_llitoa_base(va_arg(conv->ap, int), 16, 1));
	ft_handle_di_p(conv);
}

void	ft_handle_X(t_conv *conv)
{
	if (conv->size.hh)
		conv->str_val = ft_strdup(ft_llitoa_base((char)va_arg(conv->ap, long long), 16, 0));
	else if (conv->size.h)
		conv->str_val = ft_strdup(ft_llitoa_base((short)va_arg(conv->ap, long long), 16, 0));
	else if (conv->size.ll)
		conv->str_val = ft_strdup(ft_llitoa_base(va_arg(conv->ap, long long), 16, 0));
	else if (conv->size.l)
		conv->str_val = ft_strdup(ft_llitoa_base((long)va_arg(conv->ap, long long), 16, 0));
	else
		conv->str_val = ft_strdup(ft_llitoa_base(va_arg(conv->ap, int), 16, 0));
	ft_handle_di_p(conv);
}

void	ft_handle_p(t_conv *conv)
{
	conv->str_val = ft_strjoin("0x7fff", ft_llitoa_base(va_arg(conv->ap, int), 16, 1));
	ft_handle_sp_p(conv);
}

void	ft_handle_f(t_conv *conv)
{
	if (conv->prec == -1)
	   conv->prec = 6;	
	conv->str_val = ft_strdup(ft_ftoa(va_arg(conv->ap, double), conv->prec));
	ft_handle_di_p(conv);
}

void	ft_init_conv(t_conv *conv)
{
	conv->length = 0;
	conv->prec = -1;
	conv->width = -1;
}

void	ft_init_fp(t_conv *conv)
{
	
//	ft_putendl("init");
	conv->f[0] = ft_handle_c;
	conv->type[0] = 'c';
	conv->f[1] = ft_handle_s;
	conv->type[1] = 's';
	conv->f[2] = ft_handle_p;
	conv->type[2] = 'p';
	conv->f[3] = ft_handle_di;
	conv->type[3] = 'd';
	conv->f[4] = ft_handle_di;
	conv->type[4] = 'i';
	conv->f[5] = ft_handle_o;
	conv->type[5] = 'o';
	conv->f[6] = ft_handle_u;
	conv->type[6] = 'u';
	conv->f[7] = ft_handle_x;
	conv->type[7] = 'x';
	conv->f[8] = ft_handle_X;
	conv->type[8] = 'X';
	conv->f[9] = ft_handle_f;
	conv->type[9] = 'f';
}
