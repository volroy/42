/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:23:39 by rgary             #+#    #+#             */
/*   Updated: 2014/01/06 17:25:24 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "wolf3d.h"

void	error(const char *s)
{
	write(2, s, ft_strlen(s));
	exit(-1);
}
