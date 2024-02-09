/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:56:15 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/09 14:44:11 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

void	ft_format(char const *format, va_list vargs, int *ret)
{
	if (format[1] == 'c')
		ft_putchar(va_arg(vargs, int), ret);
	else if (format[1] == 's')
		ft_putstr(va_arg(vargs, char *), ret);
	else if (format[1] == 'p')
	{
		write(1, "0x", 2);
		*ret += 2;
		ft_putnbr_base(va_arg(vargs, uintptr_t), "0123456789abcdef", ret);
	}
	else if (format[1] == 'd')
		ft_putnbr(va_arg(vargs, int), ret);
	else if (format[1] == 'i')
		ft_putnbr(va_arg(vargs, int), ret);
	else if (format[1] == 'u')
		ft_putnbr_unsigned(va_arg(vargs, unsigned int), ret);
	else if (format[1] == 'x')
		ft_putnbr_base(va_arg(vargs, unsigned int), "0123456789abcdef", ret);
	else if (format[1] == 'X')
		ft_putnbr_base(va_arg(vargs, unsigned int), "0123456789ABCDEF", ret);
	else if (format[1] == '%')
		ft_putchar('%', ret);
}

int	ft_printf(char const *format, ...)
{
	va_list	vargs;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	va_start(vargs, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			ret++;
		}
		else
		{
			ft_format(&format[i], vargs, &ret);
			i++;
		}
		i++;
	}
	return (ret);
}

//int main(void)
//{
//	int *mem;
//
//	int aux, aux2;
//	mem = (int *)malloc(8);
//	aux = printf("og %x", -1);
//	aux2 = ft_printf("%x", -1);
//	printf("Numero BIEN: %i, nuestro Num: %i\n", aux, aux2);
//	free (mem);
//	return (0);
//}
