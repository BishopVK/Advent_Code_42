/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:55:12 by danjimen          #+#    #+#             */
/*   Updated: 2024/12/03 14:19:48 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/day1.h"

int	main(void)
{
	int		fd = open("input.txt", O_RDONLY);
	char	*line = get_next_line(fd, false);
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;

	while (line)
	{
		create_stacks(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(fd, false);
	}
	close (fd);
	assign_order_to_stack(&stack_a);
	assign_order_to_stack(&stack_b);
	printf(">>> STACK A <<<\n");
	print_stack(&stack_a);
	printf(">>> STACK B <<<\n");
	print_stack(&stack_b);
	return (0);
}
