/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:45:45 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/30 15:16:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static t_buffer	ft_init(t_buffer buf_info, size_t size)
{
	buf_info.index = 0;
	buf_info.nb_printed = 0;
	buf_info.error = NOERR;
	buf_info.buf_fd = -1;
	buf_info.max_size = size;
	return (buf_info);
}

static t_buffer	ft_loop_format(const char *format, size_t size, char *str, ...)
{
	va_list		args;
	t_buffer	buf_info;

	ft_init(buf_info, size);
	va_start(args, str);
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_process_format_specifier(&format, args, &buf_info) == -1)
			{
				va_end(args);
				if (size > 0)
					str[size - 1] = '\0';
				buf_info.error = 1;
				return (buf_info);
			}
		}
		else
			ft_buffer_add(&buf_info, *format);
		format++;
	}
	va_end(args);
	return (buf_info);
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list		args;
	t_buffer	buf_info;
	char		buffer[BUFFER_SIZE];
	size_t		to_copy;

	if (!str || !format)
		return (-1);
	va_start(args, format);
	buf_info = ft_loop_format(format, size, str, args);
	va_end(args);
	buf_info.buffer = buffer;
	if (buf_info.index > 0)
	{
		if ((int)(buf_info.index) < (int)(size - 1))
			to_copy = buf_info.index;
		else
			to_copy = size - 1;
		ft_memcpy(str, buf_info.buffer, to_copy);
		if (size > 0)
			str[to_copy] = '\0';
	}
	if (buf_info.error == ERNOWRITE)
		return (buf_info.nb_printed + buf_info.index);
	return (buf_info.nb_printed);
}
