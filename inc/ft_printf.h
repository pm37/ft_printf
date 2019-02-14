/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:52:16 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/14 18:19:15 by pimichau         ###   ########.fr       */
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
}					t_size;

typedef struct		s_conv
{
	va_list			ap;
	t_flag			flag;
	int				width;
	int				prec;
	t_size			size;
	char			conv_type;
	char			type[10];
	void			(*f[10])(struct s_conv *conv);
	int				length;
	size_t			ret;
}					t_conv;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_printf(const char *format, ...);

int					ft_check_flags(char *fmt, t_conv *conv);

void				ft_handle_s(t_conv *conv);
void				ft_handle_sp_p(t_conv *conv, char *output);
void				ft_handle_di_p(t_conv *conv, char *output);
void				ft_handle_x_p(t_conv *conv, char *output);
void				ft_handle_di(t_conv *conv);
void				ft_handle_o(t_conv *conv);
void				ft_handle_u(t_conv *conv);
void				ft_handle_x(t_conv *conv);
void				ft_handle_X(t_conv *conv);
void				ft_handle_c(t_conv *conv);
void				ft_handle_p(t_conv *conv);
void				ft_handle_f(t_conv *conv);

int					output_handler(char *fmt, t_conv *conv);

void				ft_init_fp(t_conv *conv);
void				ft_init_conv(t_conv *conv);

char				*ft_llitoa(long long nb);
char				*ft_ullitoa(unsigned long long nb);
char				*ft_llitoa_base(long long nb, int base, int lowercase);
char				*ft_ftoa(double nb, int dec);
char				*ft_get_f_dec(double nb, int dec);

int					ft_get_next_line(const int fd, char **line);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
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
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(long long n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memset(void *b, int c, size_t len);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
					size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
#endif
