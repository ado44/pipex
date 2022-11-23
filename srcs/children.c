/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:23:27 by amarna            #+#    #+#             */
/*   Updated: 2022/11/23 16:25:42 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process1(t_pipex pipex, char *av[], char *envp[])
{
	int		i;
	char	*tmp;

	if (dup2(pipex.infile, 0) == -1)
		msg_err("dup2");
	if (dup2(pipex.pipe_fd[1], 1) == -1)
		msg_err("dup2");
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	i = 0;
	pipex.my_cmd_args = ft_split(av[2], ' ');
	pipex.path_from_envp = find_path(envp);
	pipex.my_paths = ft_split(pipex.path_from_envp, ':');
	while (pipex.my_paths[++i])
	{
		tmp = ft_strjoin(pipex.my_paths[i], "/");
		pipex.cmd = ft_strjoin(tmp, pipex.my_cmd_args[0]);
		free(tmp);
		if (access(pipex.cmd, F_OK) == 0)
			execve(pipex.cmd, pipex.my_cmd_args, envp);
		free(pipex.cmd);
	}
	prompt_error("Command not found");
}

void	child_process2(t_pipex pipex, char *av[], char *envp[])
{
	int		i;
	char	*tmp;

	if (dup2(pipex.pipe_fd[0], 0) == -1)
		msg_err("dup2");
	if (dup2(pipex.outfile, 1) == -1)
		msg_err("dup2");
	close(pipex.pipe_fd[1]);
	close(pipex.pipe_fd[0]);
	i = 0;
	pipex.my_cmd_args = ft_split(av[3], ' ');
	pipex.path_from_envp = find_path(envp);
	pipex.my_paths = ft_split(pipex.path_from_envp, ':');
	while (pipex.my_paths[++i])
	{
		tmp = ft_strjoin(pipex.my_paths[i], "/");
		pipex.cmd = ft_strjoin(tmp, pipex.my_cmd_args[0]);
		free(tmp);
		if (access(pipex.cmd, F_OK) == 0)
			execve(pipex.cmd, pipex.my_cmd_args, envp);
		free(pipex.cmd);
	}
	prompt_error("Command not found");
}
