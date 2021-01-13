/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon_and_pipe.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:55:38 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/11 18:55:39 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		is_semicolon(char c);
int		is_pipe(char c);
int		is_redirect(char c);

char	*check_error_near(char *current);
char	*check_error_near_with_redirect_to(char *current);

#endif
