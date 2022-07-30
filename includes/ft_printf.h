/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:06 by hyap              #+#    #+#             */
/*   Updated: 2022/02/26 21:02:30 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define HEX "0123456789abcdef"

typedef struct s_str
{
	int		i;
}				t_str;

int		ft_printf(const char *av, ...);
int		conversion(char *str, int i, va_list ap);
int		print_c(char c);
int		print_s(char *s);
int		print_p(void *v);
int		print_d_i(int num);
int		print_u(unsigned int num);
int		print_x(int num, int isUpperCase);

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_hexlen(unsigned long long ull);
void	ft_putnbr(long long int num);
int		ft_numlen(long long int num);
int		ft_isalpha(char c);
char	ft_toupper(char c);
#endif
