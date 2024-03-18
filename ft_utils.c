/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:13:03 by martalop          #+#    #+#             */
/*   Updated: 2024/02/14 12:35:10 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long num, int *len, char c)
{
	char	*str;
	int		i;

	if (c == 'x')
		str = "0123456789abcdef";
	else if (c == 'X')
		str = "0123456789ABCDEF";
	if (num < 16)
	{
		if ((print_char(str[num], len)) == -1)
			return (-1);
	}
	else
	{
		if ((print_hex(num / 16, len, c)) == -1)
			return (-1);
		i = num % 16;
		if ((print_char(str[i], len)) == -1)
			return (-1);
	}
	return (*len);
}

int	print_ptr(unsigned long ptr, int *len)
{
	if ((print_str("0x", len)) == -1)
		return (-1);
	if ((print_hex(ptr, len, 'x')) == -1)
		return (-1);
	return (*len);
}

int	check_format_n(int *len, char const *s, int i, va_list args)
{
	if (s[i] == 'd' || s[i] == 'i')
	{
		if ((print_num(va_arg(args, int), len)) == -1)
			return (-1);
	}
	if (s[i] == 'u')
	{
		if ((print_un_num(va_arg(args, unsigned int), len)) == -1)
			return (-1);
	}
	if (s[i] == 'x' || s[i] == 'X')
	{
		if ((print_hex(va_arg(args, unsigned int), len, s[i])) == -1)
			return (-1);
	}
	if (s[i] == 'p')
	{
		if ((print_ptr(va_arg(args, unsigned long), len)) == -1)
			return (-1);
	}
	return (*len);
}

int	check_format_c(int *len, char const *s, int i, va_list args)
{
	if (s[i] == '%')
	{
		if ((print_char(s[i], len)) == -1)
			return (-1);
	}
	if (s[i] == 'c')
	{
		if ((print_char(va_arg(args, int), len)) == -1)
			return (*len);
	}
	if (s[i] == 's')
	{
		if ((print_str(va_arg(args, char *), len)) == -1)
			return (-1);
	}
	return (*len);
}

int	check_format(int *len, char const *s, int i, va_list args)
{
	while (s[i])
	{
		if (s[i] != '%')
		{
			if ((print_char(s[i], len)) == -1)
				return (*len);
		}
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c' || s[i] == 's' || s[i] == '%')
			{
				if ((check_format_c(len, s, i, args)) == -1)
					return (-1);
			}
			if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X' \
					|| s[i] == 'p' || s[i] == 'd' || s[i] == 'i')
			{
				if ((check_format_n(len, s, i, args)) == -1)
					return (-1);
			}
		}
		if (s[i] != '\0')
			i++;
	}
	return (*len);
}
