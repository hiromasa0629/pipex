/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:27:44 by hyap              #+#    #+#             */
/*   Updated: 2022/07/30 15:16:24 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_cmd_dir(char **paths, char *cmd)
{
	int		i;
	char	*file;

	i = 0;
	while (paths[i])
	{
		file = concat_cmd(paths[i], cmd);
		if (access(concat_cmd(paths[i], cmd), F_OK) == 0)
			return (file);
		i++;
	}
	return (NULL);
}

char	**parse_argv(char *front, char **argv)
{
	int		i;
	char	**new_split;

	i = 0;
	while (argv[i])
		i++;
	new_split = (char **)malloc(sizeof(char *) * (i + 2));
	new_split[i + 1] = NULL;
	i = 0;
	new_split[i++] = front;
	while (argv[i])
	{
		new_split[i] = argv[i];
		i++;
	}
	return (new_split);
}

void	init_data(t_data *data, int ac, char **av, char **envp)
{
	(void)av;
	data->cmd_num = ac - 3;
	data->pipe_num = data->cmd_num - 1;
	data->pid = (int *)malloc(sizeof(int) * data->cmd_num);
	data->path_list = get_paths(envp);
}

void	execute(t_data *data, char *av)
{
	char **cmd;
	char *bpath;
	cmd = ft_split(av, ' ');
	bpath = get_cmd_dir(data->path_list, cmd[0]);
	cmd = parse_argv(bpath, cmd);
	if (execve(bpath, cmd, NULL) == -1)
		perror("Error:");

}

void	child_process(t_data *data, char *av)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
		perror("Child pipe");
	pid = fork();
	if (pid < 0)
		perror("Child fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(data, av);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		i;
	int		filein;
	int		fileout;

	if (ac < 5)
		return (1);
	init_data(&data, ac, av, envp);
	i = 0;

	filein = open(av[1], O_RDONLY);
	fileout = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(filein, STDIN_FILENO);
	while (i < data.pipe_num)
		child_process(&data, av[(i++) + 2]);
	dup2(fileout, STDOUT_FILENO);
	execute(&data, av[i + 2]);
	return (0);
}