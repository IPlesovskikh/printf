/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_%.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:48:26 by pdonnie           #+#    #+#             */
/*   Updated: 2019/08/25 19:48:31 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"

int	ft_get_value(char *symbols, va_list argp)
{
	t_symbols	save;
	int			i;
	int			count;

	save.precision = 0;
	save.length = 0;
	save.type = 0;
	save.width = 0;
	save.sign = 1;
	i = 0;
	while (symbols[i] != '\0')
		i++;
	ft_get_type(symbols, &save, &i);
	ft_get_precisions(symbols, &save, &i);
	ft_get_width(symbols, &save, &i);
	ft_get_flags(symbols, &save, &i);
	ft_fill_array_operation();
	count = (*g_operations[(int)save.type])(&save, argp);
	return (count);
}
