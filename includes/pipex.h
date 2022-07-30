/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:28:21 by hyap              #+#    #+#             */
/*   Updated: 2022/07/30 14:55:53 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "./ft_printf.h"
# include "./get_next_line.h"

typedef struct s_data {
	int		*pid;
	char	**path_list;
	int		cmd_num;
	int		pipe_num;
}				t_data;


char	*ft_strstr(char *str, char *to_find);
char	**ft_split(char *s, char c);
char	**get_paths(char **envp);
char	*concat_cmd(char *path, char *cmd);

#endif