/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_length_and_other.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:56:32 by vsarapin          #+#    #+#             */
/*   Updated: 2018/01/12 09:56:45 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_strlen_double_array(char **array)
{
	int i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i); /*HERE IS A LEAK*/
}

size_t			max_len_of_word_in_array(char **array)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(array[0]);
	while (array[i])
	{
		if (len < ft_strlen(array[i]))
			len = ft_strlen(array[i]);
		i++;
	}
	if (!(len % 8))
		len++;
	while (len % 8)
		len++;
	free_double_array(array);
	return (len);
}

unsigned long	size_of_screen(void)
{
	struct ttysize	ws;
	unsigned long	line_length;

	line_length = 80;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != -1 && ws.ts_cols != 0)
		line_length = ws.ts_cols;
	return (line_length);
}

int				sum_of_files(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	free_double_array(array);
	return (count);
}

char			*joinmode_helper(char *stat_string, char *splited_saved_string_all)
{
	char	*tmp;

	if (stat_string)
	{
		tmp = ft_strdup(stat_string);
		free(stat_string);
		stat_string = ft_strjoinmode(tmp, splited_saved_string_all);
		free(tmp);
		return (stat_string);
	}
	else
		stat_string = ft_strdup(splited_saved_string_all);
	return (stat_string);
}
