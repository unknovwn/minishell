#ifndef BUILTINS_H
# define BUILTINS_H

int	echo_command(int argc, char **argv);
int	cd_command(int argc, char **argv);
int	env_command(void);
int	exit_command(int argc, char **argv);
int	export_command(int argc, char **argv);
int	pwd_command(void);
int	unset_command(int argc, char **argv);

#endif
