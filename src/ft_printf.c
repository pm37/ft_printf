#include "../inc/ft_printf.h"

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
			i += ft_is_conv((char *)&format[i + 1], &conv);
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

int		ft_is_conv(char *fmt, t_conv *conv)
{
	int		i;
	char	*buf;

//			ft_putendl("ft_is_conv");
	return (ft_check_flags(fmt, conv));
}

int		ft_check_flags(char *fmt, t_conv *conv)
{
	int i;

//			ft_putendl("flags");
	i = -1;
	while (fmt[++i] && (fmt[i] == ' ' || fmt[i] == '#' || fmt[i] == '+' ||  fmt[i] == '-' || fmt[i] == '0'))
	{
		
		if (fmt[i] == ' ')
			conv->flag.space = 1;
		else if (fmt[i] == '#')
			conv->flag.sharp = 1;
		else if (fmt[i] == '+')
			conv->flag.plus = 1;
		else if (fmt[i] == '-')
			conv->flag.less = 1;
		else if (fmt[i] == '0')
			conv->flag.zero = 1;
	}
	conv->length += i;
	return (ft_check_width(&fmt[i], conv));
}

int		ft_check_width(char *fmt, t_conv *conv)
{
	int i;

	i = 0;
//			ft_putendl("width");
	conv->width = ft_atoi(fmt);
	while (fmt[i] && (fmt[i] >= '0' && fmt[i] <= '9'))
		i++;
	conv->length += i;
	return (ft_check_prec(&fmt[i], conv));
}

int		ft_check_prec(char *fmt, t_conv *conv)
{
	int i;

	i = 0;
//			ft_putendl("precision");
	if (fmt[i] == '.')
	{	
		i++;
		conv->prec = ft_atoi(&fmt[i]);
		while (fmt[i] && (fmt[i] >= '0' && fmt[i] <= '9'))
			i++;
	}
	conv->length += i;
	return (ft_check_size(&fmt[i], conv));
}

int		ft_check_size(char *fmt, t_conv *conv)
{
	int i;

	i = 0;
//			ft_putendl("size");
	if (fmt[0] == 'h')
	{
		if (fmt[1] == 'h')
			conv->size.hh = 1;
		else
			conv->size.h = 1;
		i = (conv->size.h == 1) ? i + 1 : i + 2;
	}
	else if (fmt[0] == 'l')
	{
		if (fmt[1] == 'l')
			conv->size.ll = 1;
		else
			conv->size.l = 1;
		i = (conv->size.l == 1) ? i + 1 : i + 2;
	}
	conv->length += i;
	return (ft_check_conv(&fmt[i], conv));
}

int		ft_check_conv(char *fmt, t_conv *conv)
{
//			ft_putendl("conv");
	if (*fmt == 'c' || *fmt == 's' || *fmt == 'p' || *fmt == 'd' ||
	*fmt == 'i' || *fmt == 'o' || *fmt == 'u' || *fmt == 'x' || *fmt == 'X' ||
	*fmt == 'f')
	{
		conv->conv_type = *fmt;
		ft_handle_conv(conv);
	}
	else
		ft_init_conv(conv);
//	ft_putstr("renvoie length : ");
//	ft_putnbr(conv->length + 1);
//	ft_putendl("");
//	ft_putendl("");

	return (conv->length + 1);
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
			while (--conv->width && ++conv->length)
				ft_putchar(' ');
	ft_putchar(va_arg(conv->ap, int));
	if (conv->width != 0)
		if (conv->flag.less)
			while (--conv->width && ++conv->length)
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
