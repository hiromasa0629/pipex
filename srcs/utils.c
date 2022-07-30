/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:21:15 by hyap              #+#    #+#             */
/*   Updated: 2022/07/29 18:51:29 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		j = i;
		while (to_find[j - i] == str[j])
			if (!to_find[++j])
				return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*concat_cmd(char *path, char *cmd)
{
	char	*s;
	int		len;
	int		i;
	int		j;

	if (!path || !cmd)
		return (NULL);
	len = ft_strlen(path) + ft_strlen(cmd) + 2;
	s = (char *)malloc(sizeof(char) * len);
	s[len] = '\0';
	i = -1;
	while (path[++i])
		s[i] = path[i];
	s[i++] = '/';
	j = 0;
	while (cmd[j])
		s[i++] = cmd[j++];
	return (s);
}
