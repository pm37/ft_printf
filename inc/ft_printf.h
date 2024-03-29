/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:52:16 by pimichau          #+#    #+#             */
/*   Updated: 2019/03/01 15:50:01 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE	1024
# define OPEN_MAXI	1024

# define OPTIONS	"cspdiouxXfbkK"
# define ULL		unsigned long long

# define BLACK		"{black}"
# define RED		"{red}"
# define GREEN		"{green}"
# define YELLOW		"{yellow}"
# define BLUE		"{blue}"
# define PURPLE		"{purple}"
# define CYAN		"{cyan}"
# define GREY		"{grey}"
# define BOLD		"{bold}"
# define UNDERLINED	"{ul}"
# define NC			"{nc}"

# define FLAG		conv->flag
# define SIZE		conv->size
# define WIDTH		conv->width
# define PREC		conv->prec
# define TYPE		conv->conv_type
# define FLOATS		conv->floats
# define RET		conv->ret
# define ARG		conv->ap
# define STYLE		conv->style
# define OFFSET		conv->offset

# define RESULT		conv->floats->result
# define LEN		conv->floats->len
# define RESULT		conv->floats->result
# define IS_NEG		conv->floats->is_neg
# define P_DIFF		conv->floats->p_diff
# define SIGN		conv->floats->sign
# define EDGE		conv->floats->edge
# define B_SIZE		conv->floats->b_size
# define INDEX		conv->floats->max_index
# define F_LEN		conv->floats->f_len

typedef struct		s_flag
{
	int				zero;
	int				space;
	int				sharp;
	int				plus;
	int				less;
}					t_flag;

typedef struct		s_size
{
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				lf;
}					t_size;

typedef union		u_ftype
{
	float			f_num;
	double			d_num;
	long double		ld_num;
	long			l_num;
	int				i_num;
	short			s_num;
	char			character;
}					t_ftype;

typedef struct		s_float
{
	int				e_len;
	int				m_len;
	int				f_len;
	int				is_neg;
	int				bias;
	int				v_exp;
	int				len;
	int				p_diff;
	int				sign;
	int				edge;
	int				b_size;
	int				max_index;
	t_ftype			f_value;
	char			*binary;
	char			*mant;
	char			*exp;
	char			*result;
	char			*min;
}					t_float;

typedef struct		s_conv
{
	va_list			ap;
	t_flag			flag;
	int				width;
	int				prec;
	t_size			size;
	int				(*f[13])(struct s_conv *conv);
	int				offset;
	size_t			ret;
	char			*style;
	char			conv_type;
	char			type[13];
	t_float			*floats;
}					t_conv;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_printf(const char *format, ...);

int					check_flags(char *fmt, t_conv *conv);

int					print_c(t_conv *conv);
void				print_sp(t_conv *conv, char *output);
void				print_di(t_conv *conv, char *output);
void				print_o(t_conv *conv, char *output);
void				print_u(t_conv *conv, char *output);
void				print_x(t_conv *conv, char *output);
void				print_float(t_conv *conv);
void				print_space_before(t_conv *conv, int max, char *output);
void				print_space_after(t_conv *conv, int max);
void				print_zeros(t_conv *conv, int digits);
void				print_extra_x(t_conv *conv, int prec, int len);
void				print_extra_o(t_conv *conv, int len,
					int *prec, int is_width);

int					handle_di(t_conv *conv);
int					handle_o(t_conv *conv);
int					handle_u(t_conv *conv);
int					handle_xx(t_conv *conv);

int					handle_s(t_conv *conv);
int					handle_p(t_conv *conv);
int					handle_f(t_conv *conv);

int					handle_b(t_conv *conv);
int					timestamp_to_date(t_conv *conv);
int					date_to_timestamp(t_conv *conv);

int					output_handler(char *fmt, t_conv *conv);

void				init_fp(t_conv *conv);
void				init_conv(t_conv *conv);
int					init_floats(t_conv *conv);
char				*init_str(int size, char c);
void				del_floats(t_conv *conv);

int					color_check(t_conv *conv, const char *format, int *i);

char				*ft_llitoa(long long nb);
char				*ft_ullitoa(unsigned long long nb);
char				*ft_llitoa_base(long long nb, int base);
char				*ft_ullitoa_base(unsigned long long nb, int base);
char				*ft_get_f_dec(double nb, int dec);

int					ft_count_occurence(char *str, char c);
char				*get_bits(void *octet, int size);
char				*get_bits2(long value);
int					ft_binatoi(char *str);
void				str_addition(char **result, char *add);
void				str_mult_by_two(char **str, t_conv *conv);
void				str_div_by_two(char **str, t_conv *conv);
int					format_float(t_conv *conv, char *number);
char				*set_min(t_conv *conv, int exp);
int					get_float_len(char *str);
void				*ft_realloc(void *ptr, size_t size);

int					ft_str_notchr_index(char *str, char a, char b);
int					ft_strr_notchr_index(char *str, char a, char b);
int					ft_strchr_index(const char *str, char c);
char				*ft_str_notchr(char *str, char c);
int					ft_islower(int c);
void				ft_strtoupper(char *str);
int					ft_toupper(int c);
int					ft_max(int n1, int n2);
int					ft_tolower(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_sqrt(int nb);
long long			ft_recursive_power(long long nb, int power);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1, const char *restrict s2,
					size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(long long n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
					size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
#endif
