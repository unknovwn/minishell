#ifndef SUPER_SPLIT_H
# define SUPER_SPLIT_H

# include <stdint.h>
# include <stdlib.h>

char			**super_split(const char *s, int (*delim_comparator)(char*),
												int with_protect);

#endif
