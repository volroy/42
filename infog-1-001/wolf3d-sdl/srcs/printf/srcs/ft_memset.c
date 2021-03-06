/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:56:47 by rgary             #+#    #+#             */
/*   Updated: 2013/12/12 12:18:14 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	char			*tmp;
	unsigned char	ch;

	i = 0;
	tmp = (char*)b;
	ch = (unsigned char)c;
	while (len > 0)
	{
		tmp[i] = ch;
		i++;
		len--;
	}
	return (b);
}
