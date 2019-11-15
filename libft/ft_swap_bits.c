/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:07:31 by hmiyake           #+#    #+#             */
/*   Updated: 2018/05/05 16:11:03 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_swap_bits(unsigned char octet)
{
	return ((octet >> 4 & 0x0F) | (0xF0 & octet << 4));
}