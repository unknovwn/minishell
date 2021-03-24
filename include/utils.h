#ifndef UTILS_H
# define UTILS_H

int		is_semicolon(char *s);
int		is_pipe(char *s);
int		is_redirect(char *s);

char	*check_error_near(char *current);
char	*check_error_near_with_redirect_to(char *current);

#endif
