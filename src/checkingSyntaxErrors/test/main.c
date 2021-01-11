#include <stdlib.h>
#include <stdio.h>

#include "../check_syntax_errors.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	char	*status;

	status = check_syntax_errors(argv[1]);
	if (status == NULL)
		printf("|OK|\n");
	else
		printf("%s", status);
	return (0);
}
