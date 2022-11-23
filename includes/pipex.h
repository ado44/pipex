/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarna <amarna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:23:49 by amarna            #+#    #+#             */
/*   Updated: 2022/11/23 16:25:17 by amarna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	pid_t	child1;
	pid_t	child2;
	char	*path_from_envp;
	char	**my_cmd_args;
	char	**my_paths;
	char	*cmd;
	int		pipe_fd[2];
}t_pipex;

void	my_pipex(t_pipex pipex, char *av[], char *envp[]);
void	child_process1(t_pipex pipex, char *av[], char *envp[]);
void	child_process2(t_pipex pipex, char *av[], char *envp[]);
void	msg_err(char *s);
void	prompt_error(char *s);
char	*find_path(char **envp);

#endif