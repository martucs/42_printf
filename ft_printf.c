/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:19:55 by martalop          #+#    #+#             */
/*   Updated: 2024/02/14 12:33:39 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, int *len)
{
	if (write(1, &c, 1) == -1)
		*len = -1;
	else
		*len = *len + 1;
	return (*len);
}

int	print_str(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
	{
		if ((write(1, "(null)", 6)) == -1)
			return (-1);
		else
			*len = *len + 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			if ((print_char(s[i], len)) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}

int	print_un_num(unsigned int num, int *len)
{
	if (num >= 10)
	{
		if (print_un_num((num / 10), len) == -1)
			return (-1);
	}
	if ((print_char('0' + num % 10, len)) == -1)
		return (-1);
	return (*len);
}

int	print_num(int num, int *len)
{
	if (num == -2147483648)
	{
		if ((print_char('-', len)) == -1)
			return (-1);
		if ((print_char('2', len)) == -1)
			return (-1);
		num = 147483648;
	}
	if (num < 0)
	{
		if ((print_char('-', len)) == -1)
			return (-1);
		num = num * -1;
	}
	if (num >= 10)
	{
		if (print_num((num / 10), len) == -1)
			return (-1);
	}
	if ((print_char('0' + num % 10, len)) == -1)
		return (-1);
	return (*len);
}

int	ft_printf(char const *s, ...)
{
	int		len;
	int		i;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	if ((check_format(&len, s, i, args)) == -1)
		return (-1);
	va_end(args);
	return (len);
}

/*int	main(void)
{
	//char	prueba_char;
	//int	prueba_num;
	char	*prueba_str;
	char const	*str;

	//prueba_char = 'a';
	//prueba_num = 29;
	prueba_str = "holi";
	str = "%%This is %p test %s";
	printf("_%d\n", ft_printf(str, &prueba_str, (char *) NULL));
	printf("\n");
	printf("_%d\n", printf(str, &prueba_str, (char *) NULL));
}*/
