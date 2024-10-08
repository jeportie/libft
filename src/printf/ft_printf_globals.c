/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_globals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 03:49:22 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 09:13:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

const char	*g_perror[] = {
	"Success\n",
	"Error: Failed to write output\n",
	"Error: Memory allocation failed\n",
	"Error: Invalid format string\n",
};
