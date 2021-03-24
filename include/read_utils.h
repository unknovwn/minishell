#ifndef READ_UTILS_H
# define READ_UTILS_H

char	*skip_quotes(char *command, char c);
int		are_quotes_balanced(char *command);
int		has_unexpected_end(char *command, size_t command_len);
int		ends_with_backslash_newline(char *command, size_t *command_len);

#endif
