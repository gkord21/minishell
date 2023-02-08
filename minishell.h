/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:27:06 by iwhana21          #+#    #+#             */
/*   Updated: 2022/06/04 04:40:25 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>
# include <curses.h>
# include <termios.h> 
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <term.h>
# include <string.h>
# include <errno.h>
# define MAX_LINE       15
# define NEW_COMMAND    0
# define DIRECT_LINE    1
# define MORE           2
# define DOUBLE_MORE    3 
# define LESS           4
# define SEMICOLON      5
# define DOUBLE_LESS    6
# define WRONG_COMMAND  -1
# define WRONG_FILE     -2    
# define PERMISSION_DENIED -3
# define SYN_ERROR_TOK_NEW "minishell: syntax error \
near unexpected token `newline'\n"

pid_t				g_global_pid;
typedef struct s_env
{
	char			**env;
	char			**keys;
	char			**values;
	char			**env_lvl;
	int				exit_num;
	int				fd[2];
}					t_env;

typedef struct s_term_sistem
{
	int							stat_1;
	int							key;
	int							len;
	char						*str;
	char						*term_name;
	int							history_slider;
	char						*history_line;
	struct termios				termios_p_in;
	struct termios				termios_und;
}								t_term_sistem;

typedef struct s_command_and_flag
{
	char						*command_and_flags;
	char						*command;
	int							num_proc;
	int							pape;
	char						*flags;
	char						**array_flags;
	int							f_error;
	int							status_flag;
	struct s_command_and_flag	*next;
}								t_command_and_flag;

typedef struct s_minishell
{
	char						*file_history;
	int							single_q;
	int							double_q;
	int							flag;
	t_command_and_flag			*head;
	t_term_sistem				*term;
	struct winsize				*win;
	char						*env_varianles;
	char						*name_varianled;
	char						*tmp;
	char						**path;
	t_env						*env;
	int							lvl;
	int							ret;
	int							pipe;
}								t_minishell;

typedef struct s_list_pid
{
	pid_t						*pid;
	int							size;
	struct s_list_pid			*next;
}								t_list_pid;

/*
**	array_utils
*/
void				free_array_of_strings(char **array);
char				**new_array_rm(char	**array, int index);
char				**new_array_add(char **array, char *str);

/*
**	check_builtins
*/
void				ft_double_less_print(t_command_and_flag *all, int fd);
void				check_builtins2(t_command_and_flag *all, int *pipe_1, \
							int fd1, t_env *env);
void				check_builtins(t_command_and_flag *all, \
							int *pipe_1, int fd1, t_env *env);

/*
**	check_stat_utils
*/
int					check_stat_file_utils(t_command_and_flag *command, \
							int *i_stat, struct stat stat_command);
int					check_stat_file(t_command_and_flag *command);
int					find_slash_dot(char *line);
int					check_stat_command_with_path(t_command_and_flag *command);
int					check_stat_command_utils_2(struct stat stat_command);

/*
**	check_stat_utils2
*/
int					check_stat_file_with_path_utils(t_command_and_flag \
							*command, struct stat stat_command);
int					check_stat_file_with_path(t_command_and_flag *command);
int					create_file(char *path_and_command);

/*
**	check_stat
*/
int					check_stat_command_utils(t_minishell *data, \
							t_command_and_flag *command, \
							char **path_and_command);
int					check_stat_command(t_minishell *data, \
							t_command_and_flag *command);
int					stat_command_utils(t_command_and_flag *command, \
							int *i_stat, t_minishell *data);
int					check_stat_builtins(t_command_and_flag *command);
int					*stat_command(t_minishell *data);

/*
**	core_fork
*/
pid_t				core_fork(t_command_and_flag	*all, int	*pipe_1, \
							int	*pipe_2, t_env	*env);

/*
**	create_command_env
*/
int					create_command_with_env_variables_utils_3(char **command, \
							t_minishell *data, int *i, int *j);
int					create_command_with_env_variables_utils_2(char *command, \
							int *i, int *j);
int					create_command_with_env_variables_utils(char *command, \
							t_minishell *data, int *i);
char				*create_command_with_env_variables(char *command, \
							t_minishell *data);

/*
**	create_commands
*/
int					create_char_command(char **command);
char				*create_command(char *command, int i, int j, int key);

/*
**	env_utils
*/
int					create_env_lvl(t_env *env, int lvl);
t_env				*env_keys_values(t_env *env1, int lvl, int i);
char				**ft_strdup_array_of_strings(char **env);
t_env				*allocate_env(char **env, int lvl);

/*
**	find_functions
*/
int					**make_pipe(int size);
void				fd_init(t_env	*env, int flag);
void				free_find_function(int	**pipe, int	*pid);
void				find_function(int size, t_env *env, t_command_and_flag \
							*head, t_command_and_flag *reverse_head);

/*
**	find_path
*/
int					find_path_from_new_env_utils(t_minishell *data);
int					find_path_from_new_env(t_minishell *data);

/*
**	free_structs
*/
void				free_tmp(t_command_and_flag	*tmp);
void				free_env(t_minishell *data, t_env *env);
void				free_path(t_minishell *data);
int					free_commands(t_command_and_flag *command);

/*
**	ft_cd
*/
void				ft_cd_change_pwd(char **env, char *buf);
int					ft_cd(t_command_and_flag *all, char **env);

/*
**	ft_echo
*/
void				ft_echo(t_command_and_flag *all, int fd);

/*
**	ft_env
*/
void				ft_env(t_command_and_flag *all, char **env, int fd);

/*
**	ft_exit
*/
int					check_exit_num(char	*str);
int					exit_error(t_command_and_flag *reverse_head, t_env *env);
int					ft_exit(t_command_and_flag	*tmp, t_env *env);

/*
**	ft_export_utils
*/
int					ft_check_env(t_env *struct_env, char *str, \
							int end_of_key, int value);
int					ft_check_env_lvl(t_env *struct_env, char *str, \
							int end_of_key,	int value);
void				ft_value_name(char *str, int *end_of_key, int *value);

/*
**	ft_export
*/
void				ft_export_no_arguments(char **env, char **env_lvl, int fd);
void				ft_export_loop(char *str, t_env *struct_env);
int					ft_export(t_command_and_flag *all, int fd, \
							t_env *struct_env);

/*
**	ft_pwd
*/
void				ft_pwd(char **env, int fd);

/*
**	ft_unset
*/
int					ft_check_name(char *name);
void				ft_unset_env_lvl(t_env *struct_env, char *str, int len);
void				ft_unset_loop(char	*str, t_env	*struct_env);
int					ft_unset(t_command_and_flag	*all, t_env	*struct_env);

/*
**	functions_launch
*/
int					builtin_launch(t_env *struct_env, int size, \
							t_command_and_flag *tmp);
void				ft_minishell_name(int *lvl, t_env *struct_env);
int					functions_launch(t_command_and_flag	**head,	\
							t_env *struct_env, int *lvl, t_minishell *all);

/*
**	handler
*/
int					handler_the_shooter2(t_minishell *data);
int					handler_the_signals(t_minishell *data, \
							char **command, int *i);
/*
**	history
*/
int					ft_strlen_history(t_minishell *data);
int					definition_history_line2(t_minishell *data, int *i);
int					definition_history_line(t_minishell *data, int *i);
char				*reader_history_line(t_minishell *data, \
							int history_slider);
int					crete_or_cheak_file_history(t_minishell *data, int lvl);

/*
**	list_utils
*/
t_command_and_flag	*ft_lstnew(char *command, int pape);
void				ft_lstadd_back(t_command_and_flag **lst, \
							t_command_and_flag *new);
int					create_list_command(char *command, \
							t_minishell *data, int pipe);
void				ft_list_clear(t_command_and_flag *command);
t_command_and_flag	*ft_create_elem(t_command_and_flag *data);

/*
**	number_of_pipes
*/
char				*term_from_double_less(t_minishell *data);
t_command_and_flag	*ft_double_less(char	*split, t_minishell *all_com);
void				number_of_pipes(int	*size, t_command_and_flag	**head1, \
							t_command_and_flag	**new_head, t_minishell *all);

/*
**	parser_commands_utils
*/
int					skip_slash(char *command, int *i);
int					shift_command(char *command, t_minishell *data);
int					skip_space(t_command_and_flag *one_command, \
							int *i, int *j, int *len);
int					fill_command(t_command_and_flag *one_command, \
							int *i, int *j, t_minishell *data);
int					fill_flags(t_command_and_flag *one_command, \
							int len, int *i);

/*
**	parser_commands_utils2
*/
int					delete_single_quotes(t_minishell *data, \
							t_command_and_flag *command, int i);
int					delete_double_quotes(t_minishell *data, \
							t_command_and_flag *command, int i);
int					delete_quotes(t_minishell *data, \
							t_command_and_flag *command);

/*
**	parser_commands
*/
int					parser_commands2(t_minishell *data);
int					parser_commands(char *command, t_minishell *data);
int					start_parser(t_minishell *data, t_env *struct_env, \
							char *command);

/*
**	parser_commands2
*/
int					parser_pipe(char *command, int *i, int *j, \
							t_minishell *data);
int					parser_quotes(t_minishell *data, \
							t_command_and_flag *one_command, int *i);
int					parser_redirection_out(char *command, int *i, int *j, \
							t_minishell *data);
int					parser_redirection_in(char *command, int *i, int *j, \
							t_minishell *data);

/*
**	parser_flags_utils
*/
int					delete_quotes_in_flags_utils(t_minishell *data, \
							t_command_and_flag *command, int i, int j);
int					delete_quotes_in_flags_utils2(t_minishell *data, \
							t_command_and_flag *command, int i, int j);
int					delete_quotes_in_flags(t_minishell *data);
int					skip_space_flags(t_command_and_flag *one_command, \
							int *j, int *i);
int					parser_flags_quotes(t_command_and_flag *one_command, \
							t_minishell *data, int *i);

/*
**	parser_flags
*/
int					parser_flags_utils4(t_command_and_flag *one_command, \
							t_minishell *data, int k);
int					parser_flags_utils3(t_command_and_flag *one_command, \
							int *i, int *j, int *k);
int					parser_flags_utils2(t_command_and_flag *one_command, \
							t_minishell *data);
int					parser_flags_utils(int *i, int *j, int *k, int *z);
int					parser_flags(t_minishell *data, \
							t_command_and_flag *one_command);

/*
**	pipe_utils
*/
void				redirect_pipe(int *pipe, int where);
void				redirect_fd(int fd, int where);
void				close_pipe(int	*pipe);

/*
**	press_arrows
*/
int					press_up(t_minishell *data, char**command, \
							int *i, char **tmp);
int					press_down(t_minishell *data, char **command, \
							int *i, char **tmp);
int					arrow_handler(t_minishell *data, \
							char **command, int *i, char **tmp);
/*
**	press
*/
int					press_backspase(int *i, char **command);
int					press_control_c(char **command);

/*
**	print_errors
*/
void				export_errors(t_command_and_flag *all, t_env *env);
void				redirect_errors(t_command_and_flag *reverse_head);
int					builtins_errors(t_command_and_flag *reverse_head, \
							int fd1, t_env *env);
void				bin_errors(t_command_and_flag *reverse_head, \
							int fd1, t_env *env);
void				print_errors(pid_t	*pid, t_command_and_flag *reverse_head, \
							int size, t_env *env);

/*
**	read_terminal
*/
int					save_old_term(t_minishell *data);
int					save_system_term(t_minishell *data);
int					create_new_term(t_minishell *data);
int					handler_press(t_minishell *data, char **command, \
							int *i, char **tmp);
char				*read_terminal(t_minishell *data);

/*
**	redirect
*/
void				redirect(t_command_and_flag	*all, int *fd1, int *fd2);
t_command_and_flag	*redirect2(t_command_and_flag *all);

/*
**	replacement_utils
*/
int					replacement_utils(t_minishell *data, char **env_varianles);
int					replacement_utils_2(t_minishell *data, \
							char **env_varianles);
int					replacement_utils_3(char **env_varianles);
int					replacement_utils_4(char *command, int *i, int j);
int					replacement_utils_5(char *command, \
							char *new_command, int j, char *env_varianles);

/*
**	replacement
*/
char				*replacement_2(char *command, int *i, int j, \
							t_minishell *data);
char				*replacement(char *command, int *i, int j, \
							t_minishell *data);

/*
**	signals
*/
void				signal_manager(int sig);
void				create_signal_controller(void);

/*
**	split_flags
*/
int					split_flags_variables(int *i, int *j, int *l, int *k);
int					split_flags_utils(t_command_and_flag *one_command, \
							int *l, int *i, int *k);
int					split_flags_utils2(t_command_and_flag *one_command, \
							t_minishell *data, int *i, int *j);
int					split_flags_utils3(int *j, int *l);
int					split_flags(t_command_and_flag *one_command, \
							t_minishell *data);

/*
**	start_minishell
*/
int					write_line_break(t_minishell *data);
char				**find_path(void);
int					create_loop(t_minishell *data, char *command, \
							t_env *struct_env);
int					set_data(t_minishell *data, char **argv, \
							t_env **struct_env, char **env);
int					start(int argc, char **argv, char **env);

/*
**	utils
*/
void				ft_list_push_front(t_command_and_flag	**begin_list, \
							t_command_and_flag	*data);
void				ft_list_push_second(t_command_and_flag	**begin_list, \
							t_command_and_flag	*data);
char				*my_getenv(char *name_env, t_minishell *data);
int					ft_strcmp(const char *s1, const char *s2);

#endif
