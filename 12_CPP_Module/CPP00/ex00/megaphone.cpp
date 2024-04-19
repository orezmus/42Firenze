/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphoe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:24:39 by sum               #+#    #+#             */
/*   Updated: 2024/03/14 12:24:41 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_str(char *str)
{
	int	i = -1;
	char	c;
	
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			c = str[i] - 32;
		else
			c = str[i];
		std::cout << c;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 0;
	while (argv[++i])
		print_str(argv[i]);
	std::cout << std::endl;
	return (0);
}

