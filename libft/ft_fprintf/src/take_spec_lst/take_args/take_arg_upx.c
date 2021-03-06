/*
**	The function 'take_arg_upx' puts unsigned int argument
**	to lst->arg with applying all needs flags and converting
**	to hex.
*/

#include "ft_fprintf.h"

int	take_arg_upx(t_spec_info *lst, va_list factor)
{
	if ((lst->arg = ft_prf_uitoa_base(va_arg(factor, uint32_t), UHEX)) == NULL)
		return (-1);
	if (lst->arg[0] == '0' && lst->flags.precision == 0)
		lst->arg[0] = '\0';
	lst->arg_len = ft_prf_strlen(lst->arg);
	lst->all_len = lst->arg_len;
	if (apply_precision_d(lst) == -1)
		return (-1);
	if (apply_width_s(lst) == -1)
		return (-1);
	if (lst->flags.minus == '-')
		apply_minus_s(lst);
	else if (lst->flags.zero == '0' && lst->flags.precision < 0)
		apply_zero_s(lst);
	return (0);
}
