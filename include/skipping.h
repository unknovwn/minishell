#ifndef SKIPPING_H
# define SKIPPING_H

char	*cse_skip_protected(char *current);
int		cse_is_protect(char c);
char	*cse_skip_symbols(char *current, char c);
char	*skip_bslash(char *current);
char	*skip_space(char *current);

#endif
