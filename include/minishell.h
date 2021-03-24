#ifndef MINISHELL_H
# define MINISHELL_H

char		*read_command(void);
int			execute(char *command);

extern int	g_exit_code;
extern int	g_sin;
extern int	g_sout;

#endif
