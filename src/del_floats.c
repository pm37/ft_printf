/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_floats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:37:15 by pimichau          #+#    #+#             */
/*   Updated: 2019/02/25 18:37:47 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			del_floats(t_conv *conv)
{
	ft_strdel(&FLOATS->binary);
	ft_strdel(&FLOATS->mant);
	ft_strdel(&FLOATS->exp);
	ft_strdel(&FLOATS->result);
	ft_memdel((void **)&conv->floats);
}
