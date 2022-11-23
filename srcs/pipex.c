/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:49:38 by armand            #+#    #+#             */
/*   Updated: 2022/11/23 15:51:44 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

void	msg_err(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	prompt_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

void	my_pipex(t_pipex pipex, char *av[], char *envp[])
{
	int	status;

	if (pipe(pipex.pipe_fd) == -1)
		msg_err("pipe");
	pipex.child1 = fork();
	if (pipex.child1 == -1)
		msg_err("fork");
	else if (pipex.child1 == 0)
		child_process1(pipex, av, envp);
	pipex.child2 = fork();
	if (pipex.child2 == -1)
		msg_err("fork");
	else if (pipex.child2 == 0)
		child_process2(pipex, av, envp);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	waitpid(pipex.child1, &status, 0);
	waitpid(pipex.child2, &status, 0);
}

int	main(int ac, char *av[], char *envp[])
{
	t_pipex	pipex;

	if (ac != 5)
		prompt_error("Wrong numbers of arguments");
	pipex.infile = open(av[1], O_RDONLY);
	pipex.outfile = open(av[ac -1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.infile < 0)
		prompt_error("Error: infile");
	if (pipex.outfile < 0)
		prompt_error("Error: outfile");
	my_pipex(pipex, av, envp);
	return (0);
}
