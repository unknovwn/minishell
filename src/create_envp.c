#include "env_utils.h"
#include "libft.h"

int			count_envp_size(void)
{
	int		envp_size;
	t_list	*g_env_p;

	g_env_p = g_env;
	envp_size = 0;
	while (g_env_p)
	{
		if (((t_env_variable*)(g_env_p->content))->shell_only == 0)
			envp_size++;
		g_env_p = g_env_p->next;
	}
	return (envp_size);
}

char		*create_elem(t_env_variable *env_var)
{
	char	*result;
	size_t	result_len;

	result_len = ft_strlen(env_var->name) + 1;
	if (env_var->value)
		result_len += ft_strlen(env_var->value);
	if (!(result = (char *)malloc(sizeof(char) * (result_len + 1))))
		return (0);
	ft_strlcpy(result, env_var->name, result_len + 1);
	ft_strncat(result, "=", 1);
	if (env_var->value)
		ft_strncat(result, env_var->value, ft_strlen(env_var->value));
	return (result);
}

char		**create_envp(void)
{
	char	**envp;
	t_list	*g_env_p;
	int		i;
	int		envp_size;

	g_env_p = g_env;
	envp_size = count_envp_size();
	if (!(envp = (char**)malloc(sizeof(char*) * (envp_size + 1))))
		return (0);
	envp[0] = 0;
	i = 0;
	while (i < envp_size)
	{
		if (((t_env_variable*)(g_env_p->content))->shell_only == 0)
		{
			if (!(envp[i++] = create_elem((t_env_variable*)(g_env_p->content))))
			{
				free_string_arr(envp);
				return (0);
			}
			envp[i] = 0;
		}
		g_env_p = g_env_p->next;
	}
	return (envp);
}
