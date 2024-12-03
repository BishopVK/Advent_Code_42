/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:35:01 by danjimen          #+#    #+#             */
/*   Updated: 2024/12/03 14:21:54 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/day1.h"

void	assign_order_to_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*node_to_assign;
	int		lower;

	node_to_assign = *stack;
	node_to_assign->len = 0;
	tmp = *stack;
	while (node_to_assign)
	{
		lower = 0;
		while(tmp)
		{
			if (node_to_assign->content > tmp->content)
				lower++;
			tmp = tmp->next;
		}
		node_to_assign->order = lower + 1;
		tmp = *stack;
		tmp->len++;
		node_to_assign = node_to_assign->next;
	}
}

void	print_stack_in_order(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("%i\n", tmp->content);
		tmp = tmp->next;
	}
}

void	print_stack(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("%i\n", tmp->content);
		tmp = tmp->next;
	}
}

void	ft_nodeadd_back(t_node **stack, t_node *node)
{
	t_node	*tmp;

	if (*stack == NULL)
		*stack = node;
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
}

t_node	*ft_nodenew(char *content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = ft_atoi(content);
	new_node->next = NULL;
	return (new_node);
}

void	create_stacks(t_node **stack_a, t_node **stack_b, char *line)
{
	//line[13] = '\0';
	char	**line_splited = ft_split(line, ' ');
	int		i = 0;
	t_node	*node;

	while(line_splited[i])
	{
		node = ft_nodenew(line_splited[i]);
		if (i % 2 == 0)
		{
			//printf("DB: Vamos a añadir al stack_a %s\n", line_splited[i]);
			ft_nodeadd_back(stack_a, node);
		}
		else
		{
			//printf("DB: Vamos a añadir al stack_b %s\n", line_splited[i]);
			ft_nodeadd_back(stack_b, node);
		}
		i++;
	}
}
