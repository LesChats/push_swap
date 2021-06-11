/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:09:38 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/11 16:22:41 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int count_op(int a, int b)
{
	const char sign_a = (a > 0);
	const char sign_b = (b > 0);
	
	if (!sign_a)
		a *= -1;
	if (!sign_b)
		b *= -1;
	if (sign_a == sign_b)
	{
		if (a > b)
			return (a);
		return (b);
	}
	else
		return (a + b);
}

int min(const int a, const int b)
{
	if (a < b)
		return (a);
	return (b);
}

int max(const int a, const int b)
{
	if (a < b)
		return (b);
	return (a);
}

int abs(const int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int maxin(const int *array, unsigned long len)
{
	unsigned long i;
	int res;

	i = 0;
	res = array[0];
	while (++i < len)
		if (res < array[i])
			res = array[i];
	return (res);
}
