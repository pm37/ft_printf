/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:52:16 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/07 14:21:11 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H__
# define __FT_PRINTF_H__

# include <stdarg.h>
# include "libft/libft.h"
# include "ft_printf.h"

typedef struct s_flag
{
	int	zero;
	int	space;
	int	sharp;
	int	plus;
	int	less;
}				t_flag;

typedef struct	s_size
{
	int	h;
	int	hh;
	int	l;
	int	ll;
}				t_size;

typedef struct	s_conv
{
	va_list	ap;
	t_flag	flag;
	int		width;
	int		prec;
	t_size	size;
	char	conv_type;
	char	*str_val;
	char	type[10];
	void	(*f[10])(struct s_conv *conv);
	int		length;
}				t_conv;

int		ft_printf(const char *format, ...);
int		ft_is_conv(char *fmt, t_conv *conv);
int		ft_check_flags(char *fmt, t_conv *conv);
int		ft_check_width(char *fmt, t_conv *conv);
int		ft_check_prec(char *fmt, t_conv *conv);
int		ft_check_size(char *fmt, t_conv *conv);
int		ft_check_conv(char *fmt, t_conv *conv);
void	ft_handle_conv(t_conv *conv);
void	ft_handle_s(t_conv *conv);
void	ft_handle_sp_p(t_conv *conv);
void	ft_handle_di_p(t_conv *conv);
void	ft_init_fp(t_conv *conv);
void	ft_init_conv(t_conv *conv);
char	*ft_llitoa(long long nb);
char	*ft_ullitoa(unsigned long long nb);
char	*ft_llitoa_base(long long nb, int base, int lowercase);
char	*ft_ftoa(double nb, int dec);
char	*ft_get_f_dec(double nb, int dec);
#endif
