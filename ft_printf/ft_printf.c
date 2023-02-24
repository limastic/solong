/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:45:23 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/14 04:56:47 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formats_p_u(char c, va_list arg)
{
	ssize_t	print_len;
	int		check_write;

	print_len = 0;
	check_write = 0;
	if (c == 'u')
		print_len += ft_put_u(va_arg(arg, unsigned int), check_write);
	if (c == 'p')
	{
		check_write = write(1, "0x", 2);
		if (check_write < 0)
			return (-1);
		print_len += ft_putptr(va_arg(arg, uintptr_t), "0123456789abcdef",
				check_write);
		if (print_len < 0)
			return (-1);
		print_len += check_write;
	}
	if (print_len < 0)
		return (-1);
	return (print_len);
}

int	formats(char c, va_list arg)
{
	ssize_t	print_len;
	int		check_write;

	print_len = 0;
	check_write = 0;
	if (c == 'c')
		print_len += ft_putchar(va_arg(arg, int));
	if (c == 's')
		print_len += ft_print_str(va_arg(arg, char *));
	if (c == 'i' || c == 'd')
		print_len += ft_putnbr(va_arg(arg, int), check_write);
	if (c == 'x')
		print_len += ft_puthex(va_arg(arg, int), "0123456789abcdef",
				check_write);
	if (c == 'X')
		print_len += ft_puthex(va_arg(arg, int), "0123456789ABCDEF",
				check_write);
	if (c == '%')
		print_len += ft_putchar('%');
	if (c == 'p' || c == 'u')
		print_len += formats_p_u(c, arg);
	if (print_len < 0)
		return (-1);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	ssize_t	print_len;
	int		temp;
	int		i;

	va_start(arg, str);
	print_len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (-1);
			temp = formats(str[++i], arg);
		}
		else
			temp = write(1, &str[i], 1);
		i ++;
		if (temp < 0)
			return (-1);
		print_len += temp;
	}
	va_end(arg);
	return (print_len);
}

//#include <stdio.h>

//int	main(void)
//{
//	int		test;
//	int		test2;
//	char	*ptr = NULL;

//	test = ft_printf("%x, %X, %p\n", 123456789, -123456789, ptr);
//	test2 = printf("%x, %X, %p\n", 123456789, -123456789, ptr);
//	ft_printf("%i\n", test);
//	printf("%i\n", test2);
//	return (0);
//}
