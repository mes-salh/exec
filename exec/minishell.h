/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:36:25 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/05 22:50:15 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libc.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

t_env	*ft_lstnew(char *key, char *value);
int		ft_lstadd_back(t_env **lst, t_env *news);
char	**ft_split(char *s, char c);
char	**ft_split2(char *s, char c);
void	ft_free(char **ptr, int i);
char	*ft_strndup(char *src, int n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char	*s1, char *s2);
t_env	*envinit(char **env);
void	get_cwd(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	printenv(t_env	*envp);
void	split_command(char *input, char **cmd, char **arg);
char	*trim_spaces(const char *str);
int		ft_isspace(int c);
void	is_buit_in(char *temp, t_env **envp);
void	echo(char *arg);
void	export(t_env **env, char *arg);
void	ft_lstdelone(t_env *lst, void (*del)(void*));
void	unset(t_env **envp, char *arg);
void	change_dir(char *temp, t_env **envp);
void	update_env(t_env **envp, const char *key, const char *value);
void	export_notargs(t_env **envp);
char	*ft_strjoin(char *s1, char *s2);
void	export_sort_alpha(t_env **envp);
#endif