# SuperSplit

PROTOTYPE:

char **super_split(const char *s, int (*delim_comparator)(char*));

DESCRIPTION:

- This is a split that supports shielding (" ", ' ' and backslash).
Func int delim_comporator(char*) must to return a lengh of separator.

RETURN VALUES:

- Pointer to array of strings (char**). End of array is NULL-pointer.
- NULL, if error.
