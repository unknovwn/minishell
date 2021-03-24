#ifndef CHECK_SYNTAX_ERRORS_H
# define CHECK_SYNTAX_ERRORS_H

/*
** ==========================================================================
**                                ERROS
** ==========================================================================
*/

# define ERROR_UNCLOSED_QUOTES "syntax error unclosed quotes\n"

# define ERROR_NEAR_SEMICOLON "syntax error near unexpected token `;'"
# define ERROR_NEAR_PIPE "syntax error near unexpected token `|'"
# define ERROR_NEAR_NEWLINE "syntax error near unexpected token `newline'"
# define ERROR_NEAR_TWO_REDIRECT_TO "syntax error near unexpected token `>>'"
# define ERROR_NEAR_REDIRECT_TO "syntax error near unexpected token `>'"
# define ERROR_NEAR_REDIRECT_FROM "syntax error near unexpected token `<'"

/*
** ==========================================================================
** ==========================================================================
*/

char		*check_syntax_errors(char *command);

#endif
