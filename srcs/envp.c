/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:19:00 by hyap              #+#    #+#             */
/*   Updated: 2022/07/28 17:41:21 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		path = ft_strstr(envp[i++], "PATH=");
		if (path)
		{
			while (*path != '=')
				path++;
			path++;
			return (path);
		}
	}
	return (NULL);
}

char	**get_paths(char **envp)
{
	char	*path;
	char	**paths;

	path = find_path(envp);
	paths = ft_split(path, ':');
	return (paths);
}