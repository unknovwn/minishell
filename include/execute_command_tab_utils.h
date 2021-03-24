#ifndef EXECUTE_COMMAND_TAB_UTILS_H
# define EXECUTE_COMMAND_TAB_UTILS_H

int	is_in_redirected(int fd);
int	is_out_redirected(int fd);
int	count_argc(char **argv);
int	execute_builtin(char **argv);

#endif
