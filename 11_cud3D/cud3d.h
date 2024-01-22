/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cud3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:09:56 by sum               #+#    #+#             */
/*   Updated: 2024/01/22 15:09:57 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUD3D_H
# define CUD3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_game {
	int	x;
	int	y;
	int	info;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*fcolor;
	char	*ccolor;
	
	
}		t_game;

#endif
