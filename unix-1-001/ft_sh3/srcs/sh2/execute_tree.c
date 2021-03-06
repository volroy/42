/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 11:43:42 by rgary             #+#    #+#             */
/*   Updated: 2014/02/07 17:15:34 by rgary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh2.h"

void	delete_char_tab_tab(char**);

void	free_cmd(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	if (cmd != NULL)
		free(cmd);
}

void	execute_command(t_token *tok, char ***env, char **path)
{
	int		j;
	t_token	*save;
	char	**cmd;

	save = tok;
	j = -1;
	while (j++, save)
		save = save->next;
	cmd = (char**)malloc(sizeof(char*) * (j + 1));
	j = -1;
	save = tok;
	while (j++, tok)
	{
		cmd[j] = ft_strdup(tok->val);
		tok = tok->next;
	}
	cmd[j] = NULL;
	j = ft_check_builtins(env, cmd);
	if (!j)
		ft_not_builtins(path, cmd, env);
	free_tok_list(save);
	delete_char_tab_tab(cmd);
}

void	exec_laredir(t_ast *ast, char **env, char **path)
{
	(void)ast;
	(void)env;
	(void)path;
	ft_error("Double left redirection unsupported");
}

t_tree	*build_f_tab(void)
{
	static t_tree	*f = NULL;

	if (f != NULL)
		return (f);
	f = (t_tree*)malloc(sizeof(t_tree) * 5);
	f[0] = exec_lredir;
	f[1] = exec_rredir;
	f[2] = exec_lredir;
	f[3] = exec_raredir;
	f[4] = exec_pipe;
	return (f);
}

void	execute_tree(t_ast *ast, char ***env, char **path)
{
	t_ast	*save;
	t_tree	*f;
	int		i;
	int		tab[6] = {LREDIR, RREDIR, LAREDIR, RAREDIR, PIPE, -1};

	f = NULL;
	if (pipe(ast->fd) == -1)
	{
		ft_error("Pipe Error");
		return ;
	}
	f = build_f_tab();
	while (ast->leftcmd != NULL)
		ast = ast->leftcmd;
	save = ast;
	i = -1;
	while (i++, tab[i] != -1)
	{
		if ((int)save->type == tab[i])
			(f[i])(save, env, path);
	}
	free_tree(ast);
}
