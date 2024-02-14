/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:53:53 by martalop          #+#    #+#             */
/*   Updated: 2024/02/14 12:34:50 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	check_format(int *len, char const *s, int i, va_list args);
int	check_format_c(int *len, char const *s, int i, va_list args);
int	check_format_n(int *len, char const *s, int i, va_list args);
int	print_ptr(unsigned long ptr, int *len);
int	print_hex(unsigned long num, int *len, char c);
int	print_num(int num, int *len);
int	print_un_num(unsigned int num, int *len);
int	print_str(char *s, int *len);
int	print_char(int c, int *len);
int	ft_printf(char const *s, ...);

#endif
